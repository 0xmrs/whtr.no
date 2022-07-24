#include "met-data-fetcher.h"
#include "url.h"
#include <curl/curl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float lon = 0;
float lat = 0;

int met_data_fetcher() {

	url_formatter();

	CURL *curl = curl_easy_init();

	if (!curl) {
		fprintf(stderr, "curl init failed\n");
		exit(1);
	}

	// Set URL and User-Agent
	curl_easy_setopt(curl, CURLOPT_URL, URL);
	curl_easy_setopt(curl, CURLOPT_USERAGENT, "whtr.no/1.0");

	// Send stdout to file
	int fd = dup(STDOUT_FILENO);
	if (!freopen(TMPFILE, "w", stdout))
		fprintf(stderr, "Error: %d", errno);

	// Fetch the data
	CURLcode result = curl_easy_perform(curl);
	if (result != CURLE_OK)
		fprintf(stderr, "%s\n", curl_easy_strerror(result));

	curl_easy_cleanup(curl);

	// Restore stdout.
	fflush(stdout);
	close(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);

	return 0;
}
