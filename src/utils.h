char *read_file(char *buffer);

extern unsigned timezone;
struct timestamp *reformat_timestamp(char *timestamp, unsigned timezone);
struct timestamp {
	unsigned hour;
	unsigned minute;
	unsigned day;
	unsigned month;
	unsigned year;
};
