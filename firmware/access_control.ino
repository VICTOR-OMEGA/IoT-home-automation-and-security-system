#include <SPI.h> 
#include <MFRC522.h> 
#include <nRF24L01.h> 
#include <RF24.h> 
#include <Servo.h> 
#include <LiquidCrystal_I2C.h> 
#include <Keypad.h> 
#include <EEPROM.h>
 
#define SS_PIN 
#define SERVO_PIN

String masterTagID = "B7E7FC19"; 
String scanTagID = ""; 
Servo myservo; 

RF24 radio(CE_PIN, CSN_PIN); 
CE, CSN MFRC522 mfrc522(SS_PIN, RST_PIN); 
LiquidCrystal_I2C lcd(0x27, 16, 2); 
char new_pass[4], user_input_pass[4], eeprom_pass[4]; 
int i = 0; 
char key_def, key_pass; 
const byte address[6] = "00011"; 
const byte row_count = 4; 
const byte column_count = 4; 
char keys4x4[row_count][column_count] = { }
byte row_pins[row_count] = { }; 
byte column_pins[column_count] = { }; 
Keypad myKeypad = Keypad(makeKeymap(keys4x4), row_pins, column_pins, row_count, column_count); 
