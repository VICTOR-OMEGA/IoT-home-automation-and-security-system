#include <SPI.h> 
#include <nRF24L01.h> 
#include <RF24.h> 
#include <LiquidCrystal_I2C.h> 
#include <DHT.h> 
#include <WiFi.h> #include <AsyncTCP.h> 
 #else 
#include <ESP8266WiFi.h> 
#include <ESPAsyncTCP.h> #endif 
#include <ESPAsyncWebServer.h> 

#define DHT_SENSOR_PIN
#define MOTION_SENSOR_PIN
#define RELAY_PIN
#define flame_sensor 
#define buzzer 
#define LED 
#define potPin 

unsigned long now = millis(); 
unsigned long lastTrigger = 0; 
boolean startTimer = false;
unsigned long now2 = millis(); 
unsigned long lastTrigger2 = 0; 
boolean startTimer2 = false; 

// rain Sensor pins 
int pos = 0;
int sensorValue = 0;

// Replace with your network credentials 
const char* ssid = "'"; 
const char* password = "octoberr"; 
const char* http_username = "OMEGA"; 
const char* http_password = "Telecom1"; 
const char* PARAM_INPUT_1 = "state"; 
const char text[] = "1"; 
const int output = 32;

// set the LCD number of columns and rows 
int lcdColumns = 16; 
int lcdRows = 2; 

//create an RF24 object 
RF24 radio(4, 5); // CE, CSN 

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows); 
DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE); 

//Create AsyncWebServer object on port 80

