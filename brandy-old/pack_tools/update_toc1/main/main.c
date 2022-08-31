/*  update.cpp : Defines the entry point for the console application. */
/*  */

#include "common.h"

__asm__(".symver memcpy ,memcpy@GLIBC_2.2.5");
void *script_file_decode(char *script_name);
int update_for_toc1(char *toc1_name);

void Usage(void)
{
	printf("\n");
	printf("Usage:\n");
	printf("update_toc1 script file path para file path\n\n");
}

int main(int argc, char *argv[])
{
	char   source_toc1_name[MAX_PATH];
	char   script_file_name[MAX_PATH];
	char   *script_buf = NULL;
	int    ret = -1;

	GetFullPath(source_toc1_name,  argv[1]);
	GetFullPath(script_file_name,   argv[2]);

	printf("\n");
	printf("toc1 file Path=%s\n", source_toc1_name);
	printf("script file Path=%s\n", script_file_name);
	printf("\n");

	script_buf = (char *)script_file_decode(script_file_name);
	if (!script_buf) {
		printf("update toc1 error: unable to get script data\n");

		goto _err_out;
	}
	script_parser_init(script_buf);

	if (update_for_toc1(source_toc1_name)) {
		printf("script update toc1 fail\n");

		goto _err_out;
	}

	printf("script update toc1 ok\n");

	ret = 0;
_err_out:
	if (script_buf)
		free(script_buf);

	return ret;
}


int update_for_toc1(char *toc1_name)
{
	FILE *toc1_file = NULL;
	char *toc1_buf = NULL;
	int   length = 0;
	int   i;
	int   ret = -1;
	int   value[8];
	script_gpio_set_t   gpio_set[32];
	sbrom_toc1_head_info_t *toc1_head;

	toc1_file = fopen(toc1_name, "rb+");
	if (toc1_file == NULL) {
		printf("update:unable to open toc1 file\n");
		goto _err_toc1_out;
	}
	fseek(toc1_file, 0, SEEK_END);
	length = ftell(toc1_file);
	fseek(toc1_file, 0, SEEK_SET);
	if (!length)
		goto _err_toc1_out;

	toc1_buf = (char *)malloc(length);
	if (!toc1_buf)
		goto _err_toc1_out;

	fread(toc1_buf, length, 1, toc1_file);
	rewind(toc1_file);

	toc1_head = (sbrom_toc1_head_info_t *)toc1_buf;

	if (script_parser_fetch("board_id", "board_id_enable", value)) {
		printf("cant get board_id_enable\n");
		ret = 0;
		goto _err_toc1_out;
	}

	if (value == 0) {
		printf("board_id_enable is zero\n");
		ret = 0;
		goto _err_toc1_out;
	}

	if (!script_parser_mainkey_get_gpio_cfg("board_id", gpio_set, 32)) {
		for (i = 0; i < 32; i++) {
			if (!gpio_set[i].port)
				break;

			toc1_head->board_id_simple_gpio[i].port      = gpio_set[i].port;
			toc1_head->board_id_simple_gpio[i].port_num  = gpio_set[i].port_num;
			printf("board_id gpio%d: P%c%d\n", i, gpio_set[i].port+'A'-1, gpio_set[i].port_num);
		}
	}

	gen_check_sum_toc1((void *)toc1_buf);
	fwrite(toc1_buf, length, 1, toc1_file);

	ret = 0;

_err_toc1_out:
	if (toc1_buf)
		free(toc1_buf);

	if (toc1_file)
		fclose(toc1_file);

	return ret;
}


void *script_file_decode(char *script_file_name)
{
	FILE  *script_file;
	void  *script_buf = NULL;
	int    script_length;

	script_file = fopen(script_file_name, "rb");
	if (!script_file) {
		printf("update error:unable to open script file\n");
		return NULL;
	}

	fseek(script_file, 0, SEEK_END);
	script_length = ftell(script_file);
	if (!script_length) {
		fclose(script_file);
		printf("the length of script is zero\n");

		return NULL;
	}
	script_buf = (char *)malloc(script_length);
	if (!script_buf) {
		fclose(script_file);
		printf("unable malloc memory for script\n");

		return NULL;
	}
	fseek(script_file, 0, SEEK_SET);
	fread(script_buf, script_length, 1, script_file);
	fclose(script_file);

	return script_buf;
}

