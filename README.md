# whtr.no

whtr.no is a text based text-to-speech friendly weather program that utilizes the
MET (The Norwegian Meteorological Institute) API.

At the current time i have only implemented the *nowcast* API product, which provides
immediate weather data (updates every five minutes).

I plan on at least implementing the *locationforecast* API product too. Locationforecast
provides a weather forecast for a nine day period.

## nowcast

Nowcast can be used by specifying the `--now` command line option. You can specify
your desired location with the `--lat` and `--lon` command line options (for latitude
and longitude respectively).

#### Example

```sh
whtr.no --lat 59.911491 --lon 10.757933 --now
```

**NOTE**: *nowcast is only supported in the Nordic area.*
