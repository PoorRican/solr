# SOLR

### Description

This is a 2-axis solar panel platform. At the moment, the system does not calculate the Sun's Sea Elevation Angle
nor azimuth, but rather receives it via serial.

All location and telemetry data (North, global coordinates, time, orientation of sun) will be received via serial.

In future versions, telemetry sensors will be built in (magnetometer for North offset, GPS for coordinates, and RTC).
Also, azimuth calculations will be implemented (possibly using NOAA calculator).

As a simpler alternative, a SoC with a built-in linux environment can be used to run a Python program
that calculates the Suns Azimuth for a given time.