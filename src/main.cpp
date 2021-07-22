#define POLLING_INTERVAL 30    // poll every 30 seconds

#include <Arduino.h>
#include "types.h"
#include "platform.h"
#include "serial.h"


orientation_t sun_position;
coordinate_t location;
Platform platform;

// TODO: implement GPS
// TODO: implement compass
// TODO: implement azimuth calculation

void setup() {
  sun_position = request_position();
  location = request_location();
  double north = request_north();
  platform = Platform(north);
}

void loop() {
  sun_position = request_location();
  platform.set_orientation(sun_position);
  delay(POLLING_INTERVAL * 1000);
}
