/*

  Author: Martin R.
  Description: Program to fetch data from the MET api and format it.

*/

#include "met-data-fetcher.h"
#include "url.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  // Get the command line arguments.
  static struct option long_options[] = {{"lat", required_argument, 0, 'y'},
                                         {"lon", required_argument, 0, 'x'},
                                         {"now", 0, 0, 'n'},
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
    case 'n':
      typeNow = 1;
      break;
    default:
      abort();
    }
  }

  met_data_fetcher();

  return 0;
}
