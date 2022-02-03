/*

  Author: Martin R.
  Description: Program to fetch data from the MET api and format it.

*/

#include "met-data-fetcher.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int verbose_flag;

int main(int argc, char *argv[]) {

  // Get the command line arguments.
  static struct option long_options[] = {
      {"verbose", no_argument, &verbose_flag, 1},
      {"brief", no_argument, &verbose_flag, 0},
      {"lat", required_argument, 0, 'y'},
      {"lon", required_argument, 0, 'x'},
      {0, 0, 0, 0}};

  // Option index.
  int option_index = 0;

  int c;
  while ((c = getopt_long(argc, argv, "lat:lon:", long_options,
                          &option_index)) != EOF) {
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
    default:
      abort();
    }
  }

  met_data_fetcher();

  return 0;
}
