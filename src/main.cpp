#define POLLING_INTERVAL 30    // poll every 30 seconds

#include <Arduino.h>
#include "types.h"
#include "platform.h"
#include "serial.h"


double north;
orientation_t sun_position;
coordinate_t location;
Platform* platform;

// TODO: implement GPS
// TODO: implement compass
// TODO: implement azimuth calculation

void setup() {
  sun_position = request_position();
  location = request_location();
  north = request_north();

  Stepper hStepper(STEPPER_RESOLUTION, 8, 9, 10, 11);
  Stepper vStepper(STEPPER_RESOLUTION, 8, 9, 10, 11);

  platform = new Platform(north, &hStepper, &vStepper);
}

void loop() {
  sun_position = request_position();
  platform->set_orientation(sun_position);
  delay(POLLING_INTERVAL * 1000);
}
