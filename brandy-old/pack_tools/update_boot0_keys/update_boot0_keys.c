#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include "types.h"
#include "boot0_v2.h"
#include "check.h"

#define MAX_PATH	(260)

#define ROTPK_LENGTH	(32)
#define SSK_LENGTH	(16)

void sunxi_dump(char *buf, int count)
{
	int i,j;

	for(j=0;j<count;j+=16)
	{
		for(i=0;i<16;i++)
		{
			printf("%02x ", buf[j+i] & 0xff);
		}
		printf("\n");
	}
	printf("\n");
}

int IsFullName(const char *FilePath)
{
	if (isalpha(FilePath[0]) && ':' == FilePath[1])
		return 1;
	else
		return 0;
}

void GetFullPath(char *dName, const char *sName)
{
	char Buffer[MAX_PATH];

	if (IsFullName(sName)) {
		strcpy(dName, sName);
		return ;
	}

	/* Get the current working directory: */
	if (getcwd(Buffer, MAX_PATH ) == NULL)
	{
		perror( "getcwd error" );
		return ;
	}

	sprintf(dName, "%s/%s", Buffer, sName);
}

static int usage(char *app)
{
	printf("\n");
	printf("add rotpk and ssk to boot0 header\n");
	printf("Usage: %s --boot0 <boot0.bin> --rotpk <rotpk.bin> --ssk <ssk.bin> \n", app);
	return 1;
}


int main(int argc, char *argv[])
{
	char boot0[MAX_PATH] = {0};
	char rotpk[MAX_PATH] = {0};
	char ssk[MAX_PATH] = {0};

	FILE *boot0_file = NULL;
	FILE *rotpk_file = NULL;
	FILE *ssk_file = NULL;

	char *boot0_buf = NULL;
	char *rotpk_buf = NULL;
	char *ssk_buf = NULL;

	int boot0_length = 0;
	int rotpk_length = 0;
	int ssk_length = 0;

	boot0_file_head_t *boot0_head = NULL;

	char *app = argv[0];

	int ret = -1;

	if (argc != 7)
		return usage(app);

	argc --;
	argv ++;

	// parse the rotpk and ssk path.
	while (argc > 0) {
		if (argc < 2)
			return usage(app);

		char *arg = argv[0];
		char *val = argv[1];

		argc -= 2;
		argv += 2;

		if (!strcmp(arg, "--boot0"))
			GetFullPath(boot0, val);
		else if (!strcmp(arg, "--rotpk"))
			GetFullPath(rotpk, val);
		else if (!strcmp(arg, "--ssk"))
			GetFullPath(ssk, val);
		else
			return usage(app);
	}

	printf("boot0 path: %s\n", boot0);
	printf("rotpk path: %s\n", rotpk);
	printf("ssk path: %s\n", ssk);

	// get rotpk data
	rotpk_file = fopen(rotpk, "rb");
	if (rotpk_file == NULL) {
		printf("%s: unable to open rotpk file %s\n",app, rotpk);
		goto error;
	}

	fseek(rotpk_file, 0, SEEK_END);
	rotpk_length = ftell(rotpk_file);
	fseek(rotpk_file, 0, SEEK_SET);
	if (rotpk_length != ROTPK_LENGTH) {
		printf("The length of rotpk file: %s should be %d bit\n", rotpk, ROTPK_LENGTH);
		goto error;
	}

	rotpk_buf = (char *)malloc(rotpk_length);
	if (!rotpk_buf) {
		printf("malloc rotpk_buf error!\n");
		goto error;
	}

	fread(rotpk_buf, rotpk_length, 1, rotpk_file);

	// get ssk data
	ssk_file = fopen(ssk, "rb");
	if (ssk_file == NULL) {
		printf("%s: unable to open ssk file: %s\n",app, ssk);
		goto error;
	}

	fseek(ssk_file, 0, SEEK_END);
	ssk_length = ftell(ssk_file);
	fseek(ssk_file, 0, SEEK_SET);
	if (ssk_length != SSK_LENGTH) {
		printf("The length of ssk file: %s should be %d bit\n", ssk, ROTPK_LENGTH);
		goto error;
	}

	ssk_buf = (char *)malloc(ssk_length);
	if (!ssk_buf) {
		printf("malloc ssk_buf error!\n");
		goto error;
	}

	fread(ssk_buf, ssk_length, 1, ssk_file);

	// get boot0 data
	boot0_file = fopen(boot0, "rb+");
	if (boot0_file == NULL) {
		printf("%s: unable to open boot0 file: %s\n",app, boot0);
		goto error;
	}

	fseek(boot0_file, 0, SEEK_END);
	boot0_length = ftell(boot0_file);
	fseek(boot0_file, 0, SEEK_SET);
	if (!boot0_length) {
		printf("The length of ssk file: %s should not be 0 bit\n", ssk);
		goto error;
	}

	boot0_buf = (char *)malloc(boot0_length);
	if (!boot0_buf) {
		printf("malloc boot0_buff error!\n");
		goto error;
	}

	fread(boot0_buf, boot0_length, 1, boot0_file);
	rewind(boot0_file);

	sunxi_dump(boot0_buf, sizeof(boot0_file_head_t));

	boot0_head = (boot0_file_head_t *)boot0_buf;

	// verify boot0 check sum
	ret = check_file((unsigned int *)boot0_buf, boot0_head->boot_head.length, BOOT0_MAGIC);
	if (ret != CHECK_IS_CORRECT) {
		printf("Verify boot0 check_sum failed!\n");
		goto error;
	}

	// copy rotpk and ssk to boot0_head
	memcpy(boot0_head->prvt_head.ROTPK, rotpk_buf, ROTPK_LENGTH);
	memcpy(boot0_head->prvt_head.SSK, ssk_buf, SSK_LENGTH);

	// generate the check_sum
	gen_check_sum((void *)boot0_buf);

	// verify check sum
	ret = check_file((unsigned int *)boot0_buf, boot0_head->boot_head.length, BOOT0_MAGIC);
	if (ret != CHECK_IS_CORRECT) {
		printf("Verify boot0 check_sum failed!\n");
		goto error;
	}

	sunxi_dump(boot0_buf, sizeof(boot0_file_head_t));
	fwrite(boot0_buf, boot0_length, 1, boot0_file);

error:
	if (boot0_buf)
		free(boot0_buf);
	if (boot0_file)
		fclose(boot0_file);

	if (rotpk_buf)
		free(rotpk_buf);
	if (rotpk_file)
		fclose(rotpk_file);

	if (ssk_buf)
		free(ssk_buf);
	if (ssk_file)
		fclose(ssk_file);

	return ret;
}
