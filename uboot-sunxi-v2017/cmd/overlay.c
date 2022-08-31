#include <common.h>
#include <command.h>
#include <environment.h>
#include <malloc.h>

static int ends_with(const char *str, const char *suffix)
{
    size_t suffix_len = strlen(suffix);
    const char *p = str;

    if (strlen(str) > suffix_len) {
        p = str + strlen(str) - suffix_len;
        if (!strncmp(p, suffix, suffix_len))
            return 1;
    }

    return 0;
}

static int overlay_search(ENTRY *entry)
{
	char *new = NULL;
	char *next = NULL;
	const char *current = env_get("overlays");
	const char *suffix = "/enable";
	int current_size=0, new_size=0, next_size=0;

	if (current != NULL) 
		current_size = strlen(current);
	else
		current_size = 0;

	if (ends_with(entry->key, suffix)) {		
		next_size = strlen(entry->key) - strlen(suffix) + 1;
		next = (char *) malloc(next_size);
		memset (next, 0, next_size);
		strncpy(next, entry->key, next_size-1);

		/* already in overlays */
		if (strstr(current, next) != NULL)
			return 0;
		
		new_size = current_size + strlen(entry->key) - strlen(suffix) + 1;
		new = (char *) malloc(new_size);
		memset (new, 0, new_size);
		
		if (current != NULL) {
			sprintf(new, "%s %s", current, next);
		} else {
			sprintf(new, "%s", next);
		}
		env_set("overlays", new);
		free(new);
	}
	return 0;
}

static int do_overlay(cmd_tbl_t *cmdtp, int flag, int argc,
			char * const argv[])
{

	if (argc < 2)
		return CMD_RET_USAGE;

	if (!strcmp(argv[1], "search")) {
		hwalk_r(&env_htab, overlay_search);
		const char *current = env_get("overlays");
		if (NULL != current)
			printf("overlays=%s\n", env_get("overlays"));
		else
			printf("overlays is empty\n");
		return 0;
	}
	
	return CMD_RET_USAGE;
}


U_BOOT_CMD(
	overlay,	CONFIG_SYS_MAXARGS,	1,	do_overlay,
	"overlay helper command",
	"search\n"
	"    - search actived overlay and update the 'overlays' environment\n"

);

