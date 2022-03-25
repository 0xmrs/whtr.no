#include <stdio.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "degrees-to-compass-diretions.h"
#include "met-data-fetcher.h"

int nowcast_formatter(void) {
  FILE *fp;
  char buffer[5530];

  struct json_object *json_obj, *properties_obj, *timeseries_obj, *time_obj,
      *data_obj, *instant_obj, *instant_details_obj,*details_obj, *air_temperature_obj,
      *precipitation_amount_obj, *wind_from_direction_obj,
      *wind_speed_obj, *wind_speed_gust_obj, *next_1_hours_obj, *summary_obj, *symbol_code_obj;

  struct json_object *timeseries;

  size_t object;

  fp = fopen(TMPFILE, "r");
  if (!fp) {
    perror("Error");
    return -1;
  }
  fread(buffer, 5530, 1, fp);
  fclose(fp);
  fp = NULL;

  json_obj = json_tokener_parse(buffer);

  object = json_object_object_get_ex(json_obj, "properties", &properties_obj);
  if (object==false) {
    fprintf(stderr, "properties not found\n");
    return -1;
  }
  object = json_object_object_get_ex(properties_obj, "timeseries", &timeseries_obj);
  if (object==false) {
    fprintf(stderr, "timeseries not found\n");
    return -1;
  }
  timeseries = json_object_array_get_idx(timeseries_obj, 0);

  object = json_object_object_get_ex(timeseries, "time", &time_obj);
  if (object==false) {
    fprintf(stderr, "time not found\n");
    return -1;
  }
  object = json_object_object_get_ex(timeseries, "data", &data_obj);
  if (object==false) {
    fprintf(stderr, "data not found\n");
    return -1;
  }
  object = json_object_object_get_ex(data_obj, "instant", &instant_obj);
  if (object==false) {
    fprintf(stderr, "instant not found\n");
    return -1;
  }
  object = json_object_object_get_ex(instant_obj, "details", &instant_details_obj);
  if (object==false) {
    fprintf(stderr, "instant:details not found\n");
    return -1;
  }

  object = json_object_object_get_ex(instant_details_obj, "air_temperature", &air_temperature_obj);
  if (object==false) {
    fprintf(stderr, "air_temperature not found\n");
    return -1;
  }
  object = json_object_object_get_ex(instant_details_obj, "wind_from_direction", &wind_from_direction_obj);
  if (object==false) {
    fprintf(stderr, "wind_from_direction not found\n");
    return -1;
  }
  object = json_object_object_get_ex(instant_details_obj, "wind_speed", &wind_speed_obj);
  if (object==false) {
    fprintf(stderr, "wind_speed not found\n");
    return -1;
  }
  object = json_object_object_get_ex(instant_details_obj, "wind_speed_of_gust", &wind_speed_gust_obj);
  if (object==false) {
    fprintf(stderr, "wind_from_direction not found\n");
    return -1;
  }
  object = json_object_object_get_ex(data_obj, "next_1_hours", &next_1_hours_obj);
  if (object==false) {
    fprintf(stderr, "next_1_hours not found\n");
    return -1;
  }
  object = json_object_object_get_ex(next_1_hours_obj, "summary", &summary_obj);
  if (object==false) {
    fprintf(stderr, "summary not found\n");
    return -1;
  }
  object = json_object_object_get_ex(summary_obj, "symbol_code", &symbol_code_obj);
  if (object==false) {
    fprintf(stderr, "symbol_code not found\n");
    return -1;
  }
  object = json_object_object_get_ex(next_1_hours_obj, "details", &details_obj);
  if (object==false) {
    fprintf(stderr, "details not found\n");
    return -1;
  }
  object = json_object_object_get_ex(details_obj, "precipitation_amount", &precipitation_amount_obj);
  if (object==false) {
    fprintf(stderr, "precipitation_amount not found\n");
    return -1;
  }

  printf("Updated: %s\n\n\t%s\n\t%s ⁰C\n\t%s %.1f(%.1f) m/s\n\t%.1f "
         "mm\n",
         json_object_get_string(time_obj),
         json_object_get_string(symbol_code_obj),
         json_object_get_string(air_temperature_obj),
         degrees_to_compass_directions(json_object_get_double(wind_from_direction_obj)),
         json_object_get_double(wind_speed_obj),
         json_object_get_double(wind_speed_gust_obj),
         json_object_get_double(precipitation_amount_obj));

  return 0;
}
