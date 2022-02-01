/*

  Author: Martin R.
  Description: Program to fetch data from the MET api.

*/

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

/* TO-DO:
 * - Make the function take arguments which specify the lat & lon values.
 *
 */

int met_data_fetcher(void) {
  CURL *curl = curl_easy_init();

  if (!curl) {
    fprintf(stderr, "init failed\n");
    exit(1);
  }

  // Set URL and User-Agent
  curl_easy_setopt(curl, CURLOPT_URL,
                   "https://api.met.no/weatherapi/locationforecast/2.0/"
                   "compact?lat=59.220535&lon=10.934701");
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
