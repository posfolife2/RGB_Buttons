# RGB_Buttons
Atmega2560/w5100/mcp23018/tlc5947


Arduino 64 Channel MQTT RGB Button Controller

MQTT Messasge Structure

------>		House/SuperIO/Box1/0/Color

<------		House/SuperIO/Box1/0/Button

------>		House/SuperIO/Box1/1/Color

<------		House/SuperIO/Box1/1/Button

------>		House/SuperIO/Box1/2/Color

<------		House/SuperIO/Box1/2/Button

and so on up to /63/

Wiring

TLC5947/V+ needs to match your LED voltage

MEGA PIN      |       CHIP/PIN
--------------------------------
24            |  TLC5947/Data IN
--------------------------------
25            |  TLC5947/Clock
--------------------------------
26            |  TLC5947/Latch
--------------------------------
GND           |  TLC5947/GND

MCP23017 (Centipede Shield) wiring is available from google.. (Macetech Centipede)

Color payload is formatted like R,G,B where R,G,and B = 0 to 4095

Button payload outputs on and off with a short delay to catch most debounce
