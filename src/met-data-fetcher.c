#include "met-data-fetcher.h"
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float lon = 0;
float lat = 0;

int met_data_fetcher() {

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
