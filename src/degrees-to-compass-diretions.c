#include "degrees-to-compass-diretions.h"
#include <math.h>

char *degrees_to_compass_directions(double wind_direction) {
  int index;
  char *compass_sectors[17] = {"N",  "NNE", "NE", "ENE", "E",  "ESE",
                               "SE", "SSE", "S",  "SSW", "SW", "WSW",
                               "W",  "WNW", "NW", "NNW", "N"};

  index = (int)wind_direction % 360;
  index = round(index / 22.5)+1;

  return compass_sectors[index];
}
