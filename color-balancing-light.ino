// Hello! This code was written by Timothy Reese, and was last updated on April 09, 2015.
// Happy color balancing!
// If you have flicker in your dotstars when turning the knobs, it means you didn't use a 
// debounce capacitor. Can't skip that step!

#include <Adafruit_DotStar.h>

#include <SPI.h> 

#define NUMPIXELS_A 10 // Number of LEDs in strip a
#define NUMPIXELS_B 10 // Number of LEDs in strip b

#define DATAPIN_A    3   // The data and clock pins for strip a
#define CLOCKPIN_A   4

#define DATAPIN_B    5   // The data and clock pins for strip b
#define CLOCKPIN_B   6

Adafruit_DotStar strip_a = Adafruit_DotStar(NUMPIXELS_A, DATAPIN_A, CLOCKPIN_A);
Adafruit_DotStar strip_b = Adafruit_DotStar(NUMPIXELS_B, DATAPIN_B, CLOCKPIN_B);

int sensorPin_A = A0;   // The analog reading pin for strip a
int sensorValue_A = 0;   // The value between 0 and 1023 coming off the pot for a
int outputValue_A = 0;   // The value between 0 and 255 mapped from sensorValue_A

int sensorPin_B = A1;   // The analog reading pin for strip b
int sensorValue_B = 0;   // The value between 0 and 1023 coming off the pot for b
int outputValue_B = 0;   // The value between 0 and 255 mapped from sensorValue_B

void setup() {
  // put your setup code here, to run once:
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  strip_a.begin(); // Initialize pins for output
  strip_a.show();  // Turn all LEDs off ASAP
  
  strip_b.begin(); // Initialize pins for output
  strip_b.show();  // Turn all LEDs off ASAP
  
  pinMode(13, OUTPUT); // On/Off Button LED

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(13, HIGH); // On/Off Status LED is on to show light is powered

strip_a.setPixelColor(0, 255, 255, 255);
strip_a.setPixelColor(1, 255, 255, 255);
strip_a.setPixelColor(2, 255, 255, 255);
strip_a.setPixelColor(3, 255, 255, 255);
strip_a.setPixelColor(4, 255, 255, 255);
strip_a.setPixelColor(5, 255, 255, 255);
strip_a.setPixelColor(6, 255, 255, 255);
strip_a.setPixelColor(7, 255, 255, 255);
strip_a.setPixelColor(8, 255, 255, 255);
strip_a.setPixelColor(9, 255, 255, 255);

strip_b.setPixelColor(0, 255, 255, 255);
strip_b.setPixelColor(1, 255, 255, 255);
strip_b.setPixelColor(2, 255, 255, 255);
strip_b.setPixelColor(3, 255, 255, 255);
strip_b.setPixelColor(4, 255, 255, 255);
strip_b.setPixelColor(5, 255, 255, 255);
strip_b.setPixelColor(6, 255, 255, 255);
strip_b.setPixelColor(7, 255, 255, 255);
strip_b.setPixelColor(8, 255, 255, 255);
strip_b.setPixelColor(9, 255, 255, 255);

sensorValue_A = analogRead(sensorPin_A); 
outputValue_A = map(sensorValue_A, 0, 1023, 0, 255);
strip_a.setBrightness(outputValue_A);

sensorValue_B = analogRead(sensorPin_B); 
outputValue_B = map(sensorValue_B, 0, 1023, 0, 255);
strip_b.setBrightness(outputValue_B);

strip_a.show();
strip_b.show();

delay(1);
}
