# CombinedSensors

Run and upload through the Arduino IDE.

Combines AtlasScientific sample code in order to read pH, dissolved oxygen, and temperature at the same time, off the same arduino.

Once code is uploaded the user will be prompted to select which sensors they will be using, after this selection values for chosen sensors will be shown every second on the Arduino serial monitor

# Set Up
Connect sensors to breadboard and arduino as normal (see AtlasScientific website for wiring diagrams)

Connect pH to serial port 3, DO to serial port 2, and temperature to serial port 1 (code will not work if this isn't done)
