/*

  Author: Martin R.
  Description: Program to fetch data from the MET api.

*/

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int met_data_fetcher();
float lat;
float lon;

int main(int argc, char *argv[]) {

  char ch;
  while ((ch = getopt(argc, argv, "a:b:")) != EOF) {
    switch (ch) {
    case 'a':
      lat = atof(optarg);
      break;
    case 'b':
      lat = atof(optarg);
      break;
    default:
      fprintf(stderr, "Not a valid option: %s\n", optarg);
    }
  }
  argc -= optind;
  argv -= optind;

  met_data_fetcher();

  return 0;
}

int met_data_fetcher() {

  lat = 59.220535;
  lon = 10.934701;
  char URL[100];

  sprintf(URL,
          "https://api.met.no/weatherapi/nowcast/2.0/complete?lat=%f&lon=%f",
          lat, lon);

  CURL *curl = curl_easy_init();

  if (!curl) {
    fprintf(stderr, "init failed\n");
    exit(1);
  }

  // Set URL and User-Agent
  curl_easy_setopt(curl, CURLOPT_URL, URL);
  curl_easy_setopt(curl, CURLOPT_USERAGENT, "Dark Ninja Dragon/1.0");

  // Make stdout go to data.json (storing the response).
  freopen("data.json", "w", stdout);

  // Fetch the data
  CURLcode result = curl_easy_perform(curl);
  if (result != CURLE_OK) {
    fprintf(stderr, "Problem fetching data: %s", curl_easy_strerror(result));
  }

  curl_easy_cleanup(curl);

  return 0;
}
