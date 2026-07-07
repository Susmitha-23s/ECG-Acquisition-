#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <SD.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
const int ecgPin = A0;
const int chipSelect = 10;
int ecgValue = 0;
int threshold = 550; // adjust based on your signal
int beatCount = 0;
unsigned long lastBeatTime = 0;
unsigned long currentTime = 0;
float bpm = 0;
void setup() {
Serial.begin(9600);
// OLED setup
if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
Serial.println("OLED not found");
while (1);
}
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(WHITE);
// SD card setup
if (!SD.begin(chipSelect)) {
Serial.println("SD Card failed!");
} else {
Serial.println("SD Card ready");
}
Serial.println("ECG System Started");
}
void loop() {
ecgValue = analogRead(ecgPin);
// Serial Monitor output
Serial.println(ecgValue);
// Serial Plotter (just ECG waveform)
Serial.print(ecgValue);
Serial.print("\t");
Serial.println(threshold);
// Peak detection (simple R-peak detection)
if (ecgValue > threshold) {
currentTime = millis();
if (currentTime - lastBeatTime > 300) { // debounce
beatCount++;
if (lastBeatTime > 0) {
bpm = 60000.0 / (currentTime - lastBeatTime);
}
lastBeatTime = currentTime;
}
}
// Save to SD card
File dataFile = SD.open("ecg.txt", FILE_WRITE);
if (dataFile) {
dataFile.print(ecgValue);
dataFile.print(",");
dataFile.println(bpm);
dataFile.close();
}
// OLED Display
display.clearDisplay();
display.setCursor(0, 0);
display.print("ECG Value: ");
display.println(ecgValue);
display.setCursor(0, 20);
display.print("BPM: ");
display.println(bpm);
display.setCursor(0, 40);
if (bpm > 60 && bpm < 100) {
display.print("Status: NORMAL");
Serial.println("NORMAL");
} else {
display.print("Status: ABNORMAL");
Serial.println("ABNORMAL");
}
display.display();
delay(10);
}