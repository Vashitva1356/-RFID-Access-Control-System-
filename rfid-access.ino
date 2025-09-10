#include <SPI.h>
#include <MFRC522.h>
#include<Servo.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
// Define LED and Buzzer pins
#define BLUE_LED 3
#define GREEN_LED 4
#define BUZZER 5
Servo myServo;
void setup() 
{
  Serial.begin(9600);   // Start serial communication
  SPI.begin();          // Start SPI
  mfrc522.PCD_Init();   // Init MFRC522
  Serial.println("Approximate your card to the reader...");
  // Set pin modes
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  myServo.attach(6);
  // Turn everything off initially
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BUZZER, LOW);
  myServo.write(0);
}
void loop() 
{
  // Look for a card
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  // Show UID
  Serial.print("UID tag :");
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
    if (mfrc522.uid.uidByte[i] < 0x10){
      content += "0";
    content += String(mfrc522.uid.uidByte[i], HEX);
    content += " ";
  }
  }
  content.trim();  // Remove trailing space
  content.toUpperCase();

  Serial.println(content);
  Serial.print("Message : ");

  if (content == "F6 E7 C2 01") // Replace with your own UID
  {
    Serial.println("Authorized access");
    digitalWrite(BLUE_LED, HIGH);  // Turn on Blue LED
    myServo.write(180);
    delay(2000);                  // 30 seconds delay
    digitalWrite(BLUE_LED, LOW);   // Turn off Blue LED
    myServo.write(0); 
  }
  else
  {
    Serial.println("Access denied");
    digitalWrite(GREEN_LED, HIGH);  // Turn on Green LED
    digitalWrite(BUZZER, HIGH);     // Turn on Buzzer
     myServo.write(0);
    delay(2000);                   // 30 seconds delay
    digitalWrite(GREEN_LED, LOW);   // Turn off Green LED
    digitalWrite(BUZZER, LOW);      // Turn off Buzzer
     myServo.write(0);
  }
}