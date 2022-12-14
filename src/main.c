/*

  Author: Martin R.-S.
  Description: Program to fetch data from the MET api and format it.

*/

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "met-data-fetcher.h"
#include "url.h"
#include "nowcast-formatter.h"
#include "locationforecast-formatter.h"
#include "reformat-timestamp.h"

void sig_handler(int signum) {
	if (remove(TMPFILE))
		fprintf(stderr, "Unable to remove temporary file.\n");
}

int main(int argc, char **argv) {

	signal(SIGINT, sig_handler);

	/* Get the command line arguments. */
	static struct option long_options[] = {
		{"lat",      required_argument, 0, 'y'},
		{"lon",      required_argument, 0, 'x'},
		{"timezone", required_argument, 0, 't'},
		{"now",      0,                 0, 'n'},
		{0,          0,                 0,  0 }
	};

	int c, option_index = 0;
	while ((c = getopt_long(argc, argv, "lat:lon:timezone:now", 
				long_options, &option_index)) != EOF) {
		switch (c) {
			case 0:
				if (long_options[option_index].flag != 0)
					break;
				printf("option %s\n", long_options[option_index].name);
				break;
			case 'y':
				lat = atof(optarg);
				break;
			case 'x':
				lon = atof(optarg);
				break;
			case 't':
				timezone = atoi(optarg);
				break;
			case 'n':
				type_now = 1;
				break;
			default:
				exit(1);
		}
	}

	met_data_fetcher();
	if (type_now)
		nowcast_formatter();
	else
		locationforecast_formatter();

	raise(SIGINT);

	return 0;
}
