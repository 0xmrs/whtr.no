#include <stdlib.h>
#include <limits.h>
#include "reformat-timestamp.h"

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
