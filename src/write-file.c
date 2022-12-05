#include <stdlib.h>
#include <stdio.h>
#include "write-file.h"

char *read_file(char *file_name) {
	char *buffer = NULL;
	FILE *fp = fopen(file_name, "r");
	if (fp != NULL) {
		if (fseek(fp, 0L, SEEK_END) == 0) {
			long bufsize = ftell(fp);
			if (bufsize == -1)
				return NULL;

			if ((buffer = malloc(sizeof(char) * bufsize + 1)) == NULL)
				return NULL;

			if (fseek(fp, 0L, SEEK_SET != 0))
					return NULL;

			size_t len = fread(buffer, sizeof(char), bufsize, fp);
			if (ferror(fp) != 0)
				return NULL;
			else 
				buffer[len++] = '\0';
		}
	}
	return buffer;
}
