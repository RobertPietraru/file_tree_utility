#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void get_target_directory(char *cwd, char *target_path) {
	int target_path_length = 0;

	while (target_path[target_path_length] != '\0')
		target_path_length++;
	if (!(target_path_length == 1 && target_path[0] == '.')) {
		strcat(cwd, "/");
		strcat(cwd, target_path);
	}
}

char *get_extension(char *filename) {

	int last_dot = -1;
	int index = 0;
	while (filename[index] != '\0') {
		if (filename[index] == '.')
			last_dot = index;
		index++;
	}
	if (last_dot == -1)
		return "";

	char *ext;
	strcpy(ext, filename);
	ext += last_dot;

	return ext;
}

int is_folder_navigation_thingy(char *file) {
	int length = strlen(file);
	if (length == 1 && file[0] == '.')
		return 1;
	if (length == 2 && file[0] == '.' && file[1] == '.')
		return 1;

	return 0;
}

void show_structure(char *cwd, int depth) {
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

		if (entry == NULL)
			return;

		char full_path[PATH_MAX];
		while ((next_entry = readdir(dir)) != NULL) {
			// Ignore "." and ".." entries
			if (is_folder_navigation_thingy(next_entry->d_name))
				continue;

			snprintf(full_path, sizeof(full_path), "%s/%s", cwd, entry->d_name);

			for (int i = 0; i < depth; i++)
				printf("   ");
			printf("├");

			if (stat(full_path, &file_stat) == 0 &&
				S_ISDIR(file_stat.st_mode)) {
				printf("─ %s/\n", entry->d_name);
				show_structure(full_path, depth + 1);
			} else {
				printf("─ %s\n", entry->d_name);
			}

			entry = next_entry;
		}

		snprintf(full_path, sizeof(full_path), "%s/%s", cwd, entry->d_name);

		for (int i = 0; i < depth; i++)
			printf("   ");
		printf("└");

		if (stat(full_path, &file_stat) == 0 && S_ISDIR(file_stat.st_mode)) {
			printf("─ %s/\n", entry->d_name);
			show_structure(full_path, depth + 1);
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
}

/// first parameter is the path where we show the structure
int main(int argc, char *argv[]) {
	char cwd[PATH_MAX];

	char *x = getcwd(cwd, sizeof(cwd));

	if (argc > 1)
		get_target_directory(cwd, argv[1]);
	printf("Showing file structure for %s\n\n", cwd);
	show_structure(cwd, 0);

	/// current working directory

	return 0;
}
