#include <dirent.h>
#include <errno.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int show_hidden_files = 0;
void get_target_directory(char *cwd, char *target_path) {
	int target_path_length = 0;

	while (target_path[target_path_length] != '\0')
		target_path_length++;

	if (target_path_length == 0)
		return;

	if (target_path[0] == '/') {
		strcpy(cwd, target_path);
		return;
	}

	if (!(target_path_length == 1 && target_path[0] == '.')) {
		strcat(cwd, "/");
		strcat(cwd, target_path);
	}
}

int is_folder_navigation_thingy(char *file) {
	int length = strlen(file);
	if (length == 1 && file[0] == '.')
		return 1;
	if (length == 2 && file[0] == '.' && file[1] == '.')
		return 1;

	return 0;
}

void show_structure(char *cwd, char *leading, int depth, int max_depth) {
	if (depth > max_depth)
		return;

	char *next_leading = (char *)malloc(max_depth * 5 + 1);
	char *next_leading_without_bar = (char *)malloc(max_depth * 5 + 1);

	// if (depth != 0) {
	strcpy(next_leading, leading);
	strcpy(next_leading_without_bar, leading);

	strcat(next_leading, "| ");
	strcat(next_leading_without_bar, "  ");
	// }

	DIR *dir = opendir(cwd);

	if (dir) {
		/* Directory exists. */

		struct stat file_stat;

		struct dirent *next_entry;
		struct dirent *entry;

		while ((entry = readdir(dir)) != NULL) {
			if (!is_folder_navigation_thingy(entry->d_name))
				break;
		}

		if (entry == NULL) {
			free(next_leading);
			free(next_leading_without_bar);
			return;
		}

		char full_path[PATH_MAX];
		while ((next_entry = readdir(dir)) != NULL) {
			// Ignore "." and ".." entries
			if (is_folder_navigation_thingy(next_entry->d_name))
				continue;
			if (!show_hidden_files && next_entry->d_name[0] == '.')
				continue;

			snprintf(full_path, sizeof(full_path), "%s/%s", cwd, entry->d_name);

			printf("%s", leading);
			printf("├");

			printf("─ %s", entry->d_name);
			if (stat(full_path, &file_stat) == 0 &&
				S_ISDIR(file_stat.st_mode)) {
				printf("/\n");
				show_structure(full_path, next_leading, depth + 1, max_depth);
			} else {
				printf("\n");
			}

			entry = next_entry;
		}

		snprintf(full_path, sizeof(full_path), "%s/%s", cwd, entry->d_name);

		printf("%s", leading);
		printf("└");

		if (stat(full_path, &file_stat) == 0 && S_ISDIR(file_stat.st_mode)) {
			printf("─ %s/\n", entry->d_name);
			show_structure(full_path, next_leading_without_bar, depth + 1,
						   max_depth);
		} else {
			printf("─ %s\n", entry->d_name);
		}

		closedir(dir);
	} else if (ENOENT == errno) {
		/* Directory does not exist. */
		printf("Mate, the directory you gave me does not exist.\n");
		exit(EXIT_FAILURE);
	} else {
		printf("Something went wrong. \nidk\n");
		/* opendir() failed for some other reason. */
	}

	free(next_leading);
	free(next_leading_without_bar);
}

/// first parameter is the path where we show the structure
int main(int argc, char *argv[]) {
	char cwd[PATH_MAX];

	char *x = getcwd(cwd, sizeof(cwd));
	for (int index = 1; index < argc; index++) {
		if (argv[index][0] != '-') {
			get_target_directory(cwd, argv[index]);
		}

		if (!strcmp(argv[index], "-a")) {
			show_hidden_files = 1;
		}
	}

	printf("Showing file structure for %s\n\n", cwd);

	show_structure(cwd, "", 0, 10);

	/// current working directory

	return 0;
}
