#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "utils.h"

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

unsigned timezone = 0;

struct timestamp *reformat_timestamp(char *timestamp, unsigned timezone) {
	struct timestamp *time = (struct timestamp *)malloc(sizeof(struct timestamp));
	char buffer[4];

	for (int i = 0, j = 0; i < 4; i++, j++) buffer[j] = timestamp[i];
	time->year = atoi(buffer);
	buffer[2] = '\0';

	for (int i = 5, j = 0; i < 7; i++, j++) buffer[j] = timestamp[i];
	time->month = atoi(buffer);

	for (int i = 8, j = 0; i < 10; i++, j++) buffer[j] = timestamp[i];
	time->day = atoi(buffer);

	for (int i = 11, j = 0; i < 13; i++, j++) buffer[j] = timestamp[i];
	time->hour = atoi(buffer);
	if (timezone < INT_MAX) time->hour += timezone;

	for (int i = 14, j = 0; i < 16; i++, j++) buffer[j] = timestamp[i];
	time->minute = atoi(buffer);

	return time;
}
