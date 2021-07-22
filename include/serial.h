//
// Created by Josue Figueroa on 7/19/21.
//

#include "Arduino.h"
#include "types.h"

/**
 * Communication protocols via serial
 */

#ifndef SOLR_SERIAL_H
#define SOLR_SERIAL_H

/**
 * Requests position of the sun via Serial
 *
 * @return current SEA and azimuth of sun
 */
orientation_t request_position();

/**
 * Requests local coordinates over serial
 *
 * @return coordinates of platform
 */
coordinate_t request_location();

/**
 * Requests the current direction of north in relation to platform orientation
 * as an offset.
 *
 * @return offset from north
 */
double request_north();

#endif //SOLR_SERIAL_H
