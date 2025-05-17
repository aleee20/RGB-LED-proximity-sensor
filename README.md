# RGB-LED-proximity-sensor
A car parking sensor, implemented using the WOWKI platform. The sensor warns the driver by changing an RGB LED from green to red and by transmitting an audio signal, when there are other objects in the car's perimeter. The sensor sends the exact distance to an I2C LCD display.


I used a proximity sensor HC-SR04, connected to digital pins 8 and 12, a buzzer connected to pin 7, an RGB LED connected to pins 9, 10, 11 and an LCD-I2C display connected to A4 and A5.

I initialized the pins.

It display the text "Distance" on the first line of the screen.

The proximity sensor sends an ultrasonic signal.

Using the formula: distance = proximity * 0.034 / 2,we calculate the distance. The value 0.034 represents the speed of sound in air. The division by 2 is done because
the distance is round trip.

The distance is displayed on the second line on the display.

If the distance falls below the threshold of 150, the LED changes color from green to yellow, and if it falls below the threshold of 70, from yellow to red and the buzzer emits a sound.
