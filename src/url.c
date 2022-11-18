#include "url.h"
#include "met-data-fetcher.h"
#include <stdio.h>

int type_now = 0;
int type_forecast = 1;

char URL[100];

void url_formatter(void) {
	const char *URLs[2] = {
		"https://api.met.no/weatherapi/locationforecast/2.0/complete?lat=%f&lon=%f",
		"https://api.met.no/weatherapi/nowcast/2.0/complete?lat=%f&lon=%f"
	};

	if (type_now)
		sprintf(URL, URLs[1], lat, lon);
	else
		sprintf(URL, URLs[0], lat, lon);
}
