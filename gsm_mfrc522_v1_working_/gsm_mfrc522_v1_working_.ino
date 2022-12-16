

/*
 * 
 * Projects sourced gotten from included Arduino examples and combined into
 *  one project
 * 
 * 
 * 10/5/2017
 * 
 */
 
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

SoftwareSerial SIM900A(2,3);
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x3F, 16, 2);


void SendMessage1()
{//jahnavi
  Serial.println ("Sending Message please wait....");
  SIM900A.println("AT+CMGF=1");    //Text Mode initialisation 
  delay(1000);
  Serial.println ("Set SMS Number");
  SIM900A.println("AT+CMGS=\"+917013115025\"\r"); // Receiver's Mobile Number
  delay(1000);
  Serial.println ("Set SMS Content");
  SIM900A.println("Congratulations jahnavi , Your are present to office on time ");// Messsage content
  delay(100);
  Serial.println ("Done");
  SIM900A.println((char)26);//   delay(1000);
  Serial.println ("Message sent succesfully");
}

void SendMessage2()
{ //SPANDHANA
  Serial.println ("Sending Message please wait....");
  SIM900A.println("AT+CMGF=1");    //Text Mode initialisation 
  delay(1000);
  Serial.println ("Set SMS Number");
  SIM900A.println("AT+CMGS=\"+919550188599\"\r"); // Receiver's Mobile Number
  delay(1000);
  Serial.println ("Set SMS Content");
  SIM900A.println("Congratulations Spandhana,Your are present to office on time ");// Messsage content
  delay(100);
  Serial.println ("Done");
  SIM900A.println((char)26);//   delay(1000);
  Serial.println ("Message sent succesfully");
}

void SendMessage3()
{ //ramya
  Serial.println ("Sending Message please wait....");
  SIM900A.println("AT+CMGF=1");    //Text Mode initialisation 
  delay(1000);
  Serial.println ("Set SMS Number");
  SIM900A.println("AT+CMGS=\"+918977882001\"\r"); // Receiver's Mobile Number
  delay(1000);
  Serial.println ("Set SMS Content");
  SIM900A.println("Congratulations Ramya ,Your are present to office on time ");// Messsage content
  delay(100);
  Serial.println ("Done");
  SIM900A.println((char)26);//   delay(1000);
  Serial.println ("Message sent succesfully");
}

void SendMessage4()
{ //ganesh
  Serial.println ("Sending Message please wait....");
  SIM900A.println("AT+CMGF=1");    //Text Mode initialisation 
  delay(1000);
  Serial.println ("Set SMS Number");
  SIM900A.println("AT+CMGS=\"+918297261285\"\r"); // Receiver's Mobile Number
  delay(1000);
  Serial.println ("Set SMS Content");
  SIM900A.println("Congratulations Ganesh ,Your are present to office on time ");// Messsage content
  delay(100);
  Serial.println ("Done");
  SIM900A.println((char)26);//   delay(1000);
  Serial.println ("Message sent succesfully");
}

void setup() 
 {
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
SIM900A.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin();
  // Print a message to the LCD.
 // lcd.print("hello, world!");

}
void loop() 
{
 // lcd.setCursor(0,1);
 // lcd.print(millis()/1000);
   // Turn off the display:
  //lcd.noDisplay();
  //delay(500);
  // Turn on the display:
  lcd.display();
  delay(500);
  
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  lcd.setCursor(0,0);
  Serial.print("UID tag :");
  lcd.print("UID:");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     lcd.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  lcd.print("Message : ");
  content.toUpperCase();
 // if (content.substring(1) == "BD 31 15 2B") //change here the UID of the card/cards that you want to give access
  if (content.substring(1) == "C2 E3 59 1B") //jahnavi
  {
    lcd.setCursor(0,1);
    Serial.println("Authorized access");
    Serial.println();
    lcd.print("Auth access     ");
    lcd.println();
    SendMessage1();
    delay(3000);
  }
 else if (content.substring(1) == "E0 8F EB 1B") //spandhana
  {
    lcd.setCursor(0,1);
    Serial.println("Authorized access");
    Serial.println();
    lcd.print("Auth access     ");
    lcd.println();
    SendMessage2();
    delay(3000);
  }
  else if (content.substring(1) == "13 9A CE 9A")
  {//ramya
    lcd.setCursor(0,1);
    Serial.println("Authorized access");
    Serial.println();
    lcd.print("Auth access     ");
    lcd.println();
    SendMessage3();
    delay(3000);
  }
  else if (content.substring(1) == "10 12 16 1C") //ganesh
  {
    lcd.setCursor(0,1);
    Serial.println("Authorized access");
    Serial.println();
    lcd.print("Auth access     ");
    lcd.println();
    SendMessage4();
    delay(3000);
  }
  
 else   {
    lcd.setCursor(0,1);
    Serial.println(" Access denied");
    lcd.print(" Access denied  ");
    delay(3000);
  }
} 
