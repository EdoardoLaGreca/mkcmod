#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int put_guard = 1, use_standard_guard = 0;
char *name = NULL;

/* parse argument list and initialize global variables, return 0 if an error
   occurred during the argument parsing, 1 otherwise
*/
int parse_args(int argc, char **argv) {
	int i = 0;

	/* for each argument */
	for (i = 1; i < argc; i++) {

		if (argv[i][0] == '-') {
			int j;

			/* for each character */
			for (j = 0; j < (int) strlen(argv[i]); j++) {
				char opt = argv[i][j];

				/* option */
				switch (opt) {
				case 'g':
					put_guard = 0;
					break;
				case 'd':
					use_standard_guard = 1;
					break;
				default:
					fprintf(stderr, "ERROR: unknown option '%c'.\n", opt);
					return 0;
					break;
				}
			}

		} else {
			name = argv[i];

			/* name is the last argument */
			break;
		}

	}

	return 1;
}

/* return 1 if file exists, 0 otherwise */
int file_exists(char *path) {
	FILE *fp = fopen(path, "r");
	if (fp == NULL) {
		return 0;
	}

	return 1;
}


int main(int argc, char **argv) {
	char *header_name, *source_name;
	FILE *hp, *sp;

	/* check arguments */
	if (!parse_args(argc, argv)) {
		exit(EXIT_FAILURE);
	}

	if (name == NULL) {
		fprintf(stderr, "ERROR: no name supplied.\n");
		exit(EXIT_FAILURE);
	}

	/* create header file name */
	header_name = calloc(strlen(name) + 3, sizeof(char));
	strcpy(header_name, name);
	strcat(header_name, ".h");

	/* create source file name */
	source_name = calloc(strlen(name) + 3, sizeof(char));
	strcpy(source_name, name);
	strcat(source_name, ".c");

	/* check if files already exist */
	if (file_exists(header_name) || file_exists(source_name)) {
		fprintf(stderr, "ERROR: file already exists.\n");
		exit(EXIT_FAILURE);
	}

	/* create files */
	hp = fopen(header_name, "w");
	sp = fopen(source_name, "w");
	if (hp == NULL || sp == NULL) {
		fprintf(stderr, "ERROR: cannot create files.\n");
		exit(EXIT_FAILURE);
	}

	/* put guards if needed */
	if (put_guard) {
		if (use_standard_guard) {
			fprintf(hp, "#ifndef __%s_H__\n", name);
			fprintf(hp, "#define __%s_H__\n", name);
		} else {
			fprintf(hp, "#pragma once\n");
		}
	}

	return 0;
}
