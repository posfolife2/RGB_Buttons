#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Centipede.h>
#include "Adafruit_TLC5947.h"

// Set the MAC address
byte mac[] = { 0x90, 0xA0, 0xDA, 0x0F, 0x5E, 0x69 };

// Set fallback IP address if DHCP fails
//IPAddress ip(192.168.001.243);

// Set the broker server IP
IPAddress server(192, 168, 5, 150);

// How many boards do you have chained?
#define NUM_TLC5974 8

#define data    22
#define clock   23
#define latch   24
#define oe  -1  // set to -1 to not use the enable pin (its optional)

Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5974, clock, data, latch);

Centipede CS;

int AAR;
int AAG;
int AAB;
int ABR;
int ABG;
int ABB;
int ACR;
int ACG;
int ACB;
int ADR;
int ADG;
int ADB;
int AER;
int AEG;
int AEB;
int AFR;
int AFG;
int AFB;
int AGR;
int AGG;
int AGB;
int AHR;
int AHG;
int AHB;
int AIR;
int AIG;
int AIB;
int AJR;
int AJG;
int AJB;
int AKR;
int AKG;
int AKB;
int ALR;
int ALG;
int ALB;
int AMR;
int AMG;
int AMB;
int ANR;
int ANG;
int ANB;
int AOR;
int AOG;
int AOB;
int APR;
int APG;
int APB;
int AQR;
int AQG;
int AQB;
int ARR;
int ARG;
int ARB;
int ASR;
int ASG;
int ASB;
int ATR;
int ATG;
int ATB;
int AUR;
int AUG;
int AUB;
int AVX; // AVR is NOT Valid option
int AVG;
int AVB;
int AWR;
int AWG;
int AWB;
int AXR;
int AXG;
int AXB;
int AYR;
int AYG;
int AYB;
int AZR;
int AZG;
int AZB;
int BAR;
int BAG;
int BAB;
int BBR;
int BBG;
int BBB;
int BCR;
int BCG;
int BCB;
int BDR;
int BDG;
int BDB;
int BER;
int BEG;
int BEB;
int BFR;
int BFG;
int BFB;
int BGR;
int BGG;
int BGB;
int BHR;
int BHG;
int BHB;
int BIR;
int BIG;
int BIB;
int BJR;
int BJG;
int BJB;
int BKR;
int BKG;
int BKB;
int BLR;
int BLG;
int BLB;
int BMR;
int BMG;
int BMB;
int BNR;
int BNG;
int BNB;
int BOR;
int BOG;
int BOB;
int BPR;
int BPG;
int BPB;
int BQR;
int BQG;
int BQB;
int BRR;
int BRG;
int BRB;
int BSR;
int BSG;
int BSB;
int BTR;
int BTG;
int BTB;
int BUR;
int BUG;
int BUB;
int BVR;
int BVG;
int BVB;
int BWR;
int BWG;
int BWB;
int BXR;
int BXG;
int BXB;
int BYR;
int BYG;
int BYB;
int BZR;
int BZG;
int BZB;
int CAR;
int CAG;
int CAB;
int CBR;
int CBG;
int CBB;
int CCR;
int CCG;
int CCB;
int CDR;
int CDG;
int CDB;
int CER;
int CEG;
int CEB;
int CFR;
int CFG;
int CFB;
int CGR;
int CGG;
int CGB;
int CHR;
int CHG;
int CHB;
int CIR;
int CIG;
int CIB;
int CJR;
int CJG;
int CJB;
int CKR;
int CKG;
int CKB;
int CLR;
int CLG;
int CLB;

String PRETOPIC = "House/SuperIO/Box1/";
String POSTTOPIC = "/Button";

void callback(char* topic, byte* payload, unsigned int length) {
  // check for messages on subscribed topics
  payload[length] = '\0';
  Serial.print("Topic: ");
  Serial.println(String(topic));



  // check topic to identify type of content
  if (String(topic) == "House/SuperIO/Box1/0/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AAR = value.substring(0, value.indexOf(',')).toInt();
    AAG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AAB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AAR);
    Serial.print("GREEN: ");
    Serial.println(AAG);
    Serial.print("BLUE: ");
    Serial.println(AAB);

    tlc.setLED(0,AAR,AAG,AAB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }

  if (String(topic) == "House/SuperIO/Box1/1/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    ABR = value.substring(0, value.indexOf(',')).toInt();
    ABG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    ABB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(ABR);
    Serial.print("GREEN: ");
    Serial.println(ABG);
    Serial.print("BLUE: ");
    Serial.println(ABB);

    tlc.setLED(1,ABR,ABG,ABB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/2/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    ACR = value.substring(0, value.indexOf(',')).toInt();
    ACG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    ACB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(ACR);
    Serial.print("GREEN: ");
    Serial.println(ACG);
    Serial.print("BLUE: ");
    Serial.println(ACB);

    tlc.setLED(2,ACR,ACG,ACB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/3/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    ADR = value.substring(0, value.indexOf(',')).toInt();
    ADG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    ADB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(ADR);
    Serial.print("GREEN: ");
    Serial.println(ADG);
    Serial.print("BLUE: ");
    Serial.println(ADB);

    tlc.setLED(3,ADR,ADG,ADB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/4/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AER = value.substring(0, value.indexOf(',')).toInt();
    AEG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AEB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AER);
    Serial.print("GREEN: ");
    Serial.println(AEG);
    Serial.print("BLUE: ");
    Serial.println(AEB);

    tlc.setLED(4,AER,AEG,AEB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }

  if (String(topic) == "House/SuperIO/Box1/5/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AFR = value.substring(0, value.indexOf(',')).toInt();
    AFG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AFB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AFR);
    Serial.print("GREEN: ");
    Serial.println(AFG);
    Serial.print("BLUE: ");
    Serial.println(AFB);

    tlc.setLED(5,AFR,AFG,AFB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/6/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AGR = value.substring(0, value.indexOf(',')).toInt();
    AGG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AGB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AGR);
    Serial.print("GREEN: ");
    Serial.println(AGG);
    Serial.print("BLUE: ");
    Serial.println(AGB);

    tlc.setLED(6,AGR,AGG,AGB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/7/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AHR = value.substring(0, value.indexOf(',')).toInt();
    AHG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AHB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AHR);
    Serial.print("GREEN: ");
    Serial.println(AHG);
    Serial.print("BLUE: ");
    Serial.println(AHB);

    tlc.setLED(7,AHR,AHG,AHB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/8/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AAR = value.substring(0, value.indexOf(',')).toInt();
    AAG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AAB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AIR);
    Serial.print("GREEN: ");
    Serial.println(AIG);
    Serial.print("BLUE: ");
    Serial.println(AIB);

    tlc.setLED(8,AIR,AIG,AIB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }

  if (String(topic) == "House/SuperIO/Box1/9/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AJR = value.substring(0, value.indexOf(',')).toInt();
    AJG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AJB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AJR);
    Serial.print("GREEN: ");
    Serial.println(AJG);
    Serial.print("BLUE: ");
    Serial.println(AJB);

    tlc.setLED(9,AJR,AJG,AJB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/10/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AKR = value.substring(0, value.indexOf(',')).toInt();
    AKG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AKB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AKR);
    Serial.print("GREEN: ");
    Serial.println(AKG);
    Serial.print("BLUE: ");
    Serial.println(AKB);

    tlc.setLED(10,AKR,AKG,AKB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/11/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    ALR = value.substring(0, value.indexOf(',')).toInt();
    ALG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    ALB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(ALR);
    Serial.print("GREEN: ");
    Serial.println(ALG);
    Serial.print("BLUE: ");
    Serial.println(ALB);

    tlc.setLED(11,ALR,ALG,ALB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/12/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AMR = value.substring(0, value.indexOf(',')).toInt();
    AMG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AMB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AMR);
    Serial.print("GREEN: ");
    Serial.println(AMG);
    Serial.print("BLUE: ");
    Serial.println(AMB);

    tlc.setLED(12,AMR,AMG,AMB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }

  if (String(topic) == "House/SuperIO/Box1/13/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    ANR = value.substring(0, value.indexOf(',')).toInt();
    ANG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    ANB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(ANR);
    Serial.print("GREEN: ");
    Serial.println(ANG);
    Serial.print("BLUE: ");
    Serial.println(ANB);

    tlc.setLED(13,ANR,ANG,ANB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/14/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AOR = value.substring(0, value.indexOf(',')).toInt();
    AOG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AOB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AOR);
    Serial.print("GREEN: ");
    Serial.println(AOG);
    Serial.print("BLUE: ");
    Serial.println(AOB);

    tlc.setLED(14,AOR,AOG,AOB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/15/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    APR = value.substring(0, value.indexOf(',')).toInt();
    APG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    APB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(APR);
    Serial.print("GREEN: ");
    Serial.println(APG);
    Serial.print("BLUE: ");
    Serial.println(APB);

    tlc.setLED(15,APR,APG,APB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/16/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AQR = value.substring(0, value.indexOf(',')).toInt();
    AQG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AQB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AQR);
    Serial.print("GREEN: ");
    Serial.println(AQG);
    Serial.print("BLUE: ");
    Serial.println(AQB);

    tlc.setLED(16,AQR,AQG,AQB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/17/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    ARR = value.substring(0, value.indexOf(',')).toInt();
    ARG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    ARB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(ARR);
    Serial.print("GREEN: ");
    Serial.println(ARG);
    Serial.print("BLUE: ");
    Serial.println(ARB);

    tlc.setLED(17,ARR,ARG,ARB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/18/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    ASR = value.substring(0, value.indexOf(',')).toInt();
    ASG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    ASB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(ASR);
    Serial.print("GREEN: ");
    Serial.println(ASG);
    Serial.print("BLUE: ");
    Serial.println(ASB);

    tlc.setLED(18,ASR,ASG,ASB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/19/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    ATR = value.substring(0, value.indexOf(',')).toInt();
    ATG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    ATB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(ATR);
    Serial.print("GREEN: ");
    Serial.println(ATG);
    Serial.print("BLUE: ");
    Serial.println(ATB);

    tlc.setLED(19,ATR,ATG,ATB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/20/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AUR = value.substring(0, value.indexOf(',')).toInt();
    AUG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AUB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AUR);
    Serial.print("GREEN: ");
    Serial.println(AUG);
    Serial.print("BLUE: ");
    Serial.println(AUB);

    tlc.setLED(20,AUR,AUG,AUB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/21/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AVX = value.substring(0, value.indexOf(',')).toInt();
    AVG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AVB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AVX);
    Serial.print("GREEN: ");
    Serial.println(AVG);
    Serial.print("BLUE: ");
    Serial.println(AVB);

    tlc.setLED(21,AVX,AVG,AVB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/22/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AWR = value.substring(0, value.indexOf(',')).toInt();
    AWG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AWB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AWR);
    Serial.print("GREEN: ");
    Serial.println(AWG);
    Serial.print("BLUE: ");
    Serial.println(AWB);

    tlc.setLED(22,AWR,AWG,AWB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/23/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AXR = value.substring(0, value.indexOf(',')).toInt();
    AXG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AXB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AXR);
    Serial.print("GREEN: ");
    Serial.println(AXG);
    Serial.print("BLUE: ");
    Serial.println(AXB);

    tlc.setLED(23,AXR,AXG,AXB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/24/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AYR = value.substring(0, value.indexOf(',')).toInt();
    AYG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AYB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AYR);
    Serial.print("GREEN: ");
    Serial.println(AYG);
    Serial.print("BLUE: ");
    Serial.println(AYB);

    tlc.setLED(24,AYR,AYG,AYB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/25/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    AZR = value.substring(0, value.indexOf(',')).toInt();
    AZG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    AZB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(AZR);
    Serial.print("GREEN: ");
    Serial.println(AZG);
    Serial.print("BLUE: ");
    Serial.println(AZB);

    tlc.setLED(25,AZR,AZG,AZB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/26/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BAR = value.substring(0, value.indexOf(',')).toInt();
    BAG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BAB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BAR);
    Serial.print("GREEN: ");
    Serial.println(BAG);
    Serial.print("BLUE: ");
    Serial.println(BAB);

    tlc.setLED(26,BAR,BAG,BAB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }

  if (String(topic) == "House/SuperIO/Box1/27/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BBR = value.substring(0, value.indexOf(',')).toInt();
    BBG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BBB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BBR);
    Serial.print("GREEN: ");
    Serial.println(BBG);
    Serial.print("BLUE: ");
    Serial.println(BBB);

    tlc.setLED(27,BBR,BBG,BBB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/28/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BCR = value.substring(0, value.indexOf(',')).toInt();
    BCG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BCB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BCR);
    Serial.print("GREEN: ");
    Serial.println(BCG);
    Serial.print("BLUE: ");
    Serial.println(BCB);

    tlc.setLED(28,BCR,BCG,BCB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/29/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BDR = value.substring(0, value.indexOf(',')).toInt();
    BDG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BDB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BDR);
    Serial.print("GREEN: ");
    Serial.println(BDG);
    Serial.print("BLUE: ");
    Serial.println(BDB);

    tlc.setLED(29,BDR,BDG,BDB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/30/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BER = value.substring(0, value.indexOf(',')).toInt();
    BEG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BEB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BER);
    Serial.print("GREEN: ");
    Serial.println(BEG);
    Serial.print("BLUE: ");
    Serial.println(BEB);

    tlc.setLED(30,BER,BEG,BEB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }

  if (String(topic) == "House/SuperIO/Box1/31/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BFR = value.substring(0, value.indexOf(',')).toInt();
    BFG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BFB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BFR);
    Serial.print("GREEN: ");
    Serial.println(BFG);
    Serial.print("BLUE: ");
    Serial.println(BFB);

    tlc.setLED(31,BFR,BFG,BFB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/32/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BGR = value.substring(0, value.indexOf(',')).toInt();
    BGG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BGB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BGR);
    Serial.print("GREEN: ");
    Serial.println(BGG);
    Serial.print("BLUE: ");
    Serial.println(BGB);

    tlc.setLED(32,BGR,BGG,BGB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/33/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BHR = value.substring(0, value.indexOf(',')).toInt();
    BHG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BHB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BHR);
    Serial.print("GREEN: ");
    Serial.println(BHG);
    Serial.print("BLUE: ");
    Serial.println(BHB);

    tlc.setLED(33,BHR,BHG,BHB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/34/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BIR = value.substring(0, value.indexOf(',')).toInt();
    BIG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BIB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BIR);
    Serial.print("GREEN: ");
    Serial.println(BIG);
    Serial.print("BLUE: ");
    Serial.println(BIB);

    tlc.setLED(34,BIR,BIG,BIB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }

  if (String(topic) == "House/SuperIO/Box1/35/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BJR = value.substring(0, value.indexOf(',')).toInt();
    BJG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BJB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BJR);
    Serial.print("GREEN: ");
    Serial.println(BJG);
    Serial.print("BLUE: ");
    Serial.println(BJB);

    tlc.setLED(35,BJR,BJG,BJB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/36/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BKR = value.substring(0, value.indexOf(',')).toInt();
    BKG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BKB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BKR);
    Serial.print("GREEN: ");
    Serial.println(BKG);
    Serial.print("BLUE: ");
    Serial.println(BKB);

    tlc.setLED(36,BKR,BKG,BKB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/37/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BLR = value.substring(0, value.indexOf(',')).toInt();
    BLG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BLB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BLR);
    Serial.print("GREEN: ");
    Serial.println(BLG);
    Serial.print("BLUE: ");
    Serial.println(BLB);

    tlc.setLED(37,BLR,BLG,BLB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/38/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BMR = value.substring(0, value.indexOf(',')).toInt();
    BMG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BMB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BMR);
    Serial.print("GREEN: ");
    Serial.println(BMG);
    Serial.print("BLUE: ");
    Serial.println(BMB);

    tlc.setLED(38,BMR,BMG,BMB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }

  if (String(topic) == "House/SuperIO/Box1/39/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BNR = value.substring(0, value.indexOf(',')).toInt();
    BNG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BNB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BNR);
    Serial.print("GREEN: ");
    Serial.println(BNG);
    Serial.print("BLUE: ");
    Serial.println(BNB);

    tlc.setLED(39,BNR,BNG,BNB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/40/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BOR = value.substring(0, value.indexOf(',')).toInt();
    BOG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BOB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BOR);
    Serial.print("GREEN: ");
    Serial.println(BOG);
    Serial.print("BLUE: ");
    Serial.println(BOB);

    tlc.setLED(40,BOR,BOG,BOB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/41/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BPR = value.substring(0, value.indexOf(',')).toInt();
    BPG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BPB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BPR);
    Serial.print("GREEN: ");
    Serial.println(BPG);
    Serial.print("BLUE: ");
    Serial.println(BPB);

    tlc.setLED(41,BPR,BPG,BPB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/42/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BQR = value.substring(0, value.indexOf(',')).toInt();
    BQG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BQB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BQR);
    Serial.print("GREEN: ");
    Serial.println(BQG);
    Serial.print("BLUE: ");
    Serial.println(BQB);

    tlc.setLED(42,BQR,BQG,BQB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/43/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BRR = value.substring(0, value.indexOf(',')).toInt();
    BRG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BRB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BRR);
    Serial.print("GREEN: ");
    Serial.println(BRG);
    Serial.print("BLUE: ");
    Serial.println(BRB);

    tlc.setLED(43,BRR,BRG,BRB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/44/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BSR = value.substring(0, value.indexOf(',')).toInt();
    BSG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BSB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BSR);
    Serial.print("GREEN: ");
    Serial.println(BSG);
    Serial.print("BLUE: ");
    Serial.println(BSB);

    tlc.setLED(44,BSR,BSG,BSB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/45/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BTR = value.substring(0, value.indexOf(',')).toInt();
    BTG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BTB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BTR);
    Serial.print("GREEN: ");
    Serial.println(BTG);
    Serial.print("BLUE: ");
    Serial.println(BTB);

    tlc.setLED(45,BTR,BTG,BTB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/46/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BUR = value.substring(0, value.indexOf(',')).toInt();
    BUG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BUB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BUR);
    Serial.print("GREEN: ");
    Serial.println(BUG);
    Serial.print("BLUE: ");
    Serial.println(BUB);

    tlc.setLED(46,BUR,BUG,BUB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/47/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BVR = value.substring(0, value.indexOf(',')).toInt();
    BVG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BVB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BVR);
    Serial.print("GREEN: ");
    Serial.println(BVG);
    Serial.print("BLUE: ");
    Serial.println(BVB);

    tlc.setLED(47,BVR,BVG,BVB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/48/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BWR = value.substring(0, value.indexOf(',')).toInt();
    BWG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BWB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BWR);
    Serial.print("GREEN: ");
    Serial.println(BWG);
    Serial.print("BLUE: ");
    Serial.println(BWB);

    tlc.setLED(48,BWR,BWG,BWB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/49/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BXR = value.substring(0, value.indexOf(',')).toInt();
    BXG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BXB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BXR);
    Serial.print("GREEN: ");
    Serial.println(BXG);
    Serial.print("BLUE: ");
    Serial.println(BXB);

    tlc.setLED(49,BXR,BXG,BXB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/50/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BYR = value.substring(0, value.indexOf(',')).toInt();
    BYG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BYB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BYR);
    Serial.print("GREEN: ");
    Serial.println(BYG);
    Serial.print("BLUE: ");
    Serial.println(BYB);

    tlc.setLED(50,BYR,BYG,BYB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/51/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    BZR = value.substring(0, value.indexOf(',')).toInt();
    BZG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    BZB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(BZR);
    Serial.print("GREEN: ");
    Serial.println(BZG);
    Serial.print("BLUE: ");
    Serial.println(BZB);

    tlc.setLED(51,BZR,BZG,BZB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/52/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    CAR = value.substring(0, value.indexOf(',')).toInt();
    CAG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    CAB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(CAR);
    Serial.print("GREEN: ");
    Serial.println(CAG);
    Serial.print("BLUE: ");
    Serial.println(CAB);

    tlc.setLED(52,CAR,CAG,CAB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }

  if (String(topic) == "House/SuperIO/Box1/53/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    CBR = value.substring(0, value.indexOf(',')).toInt();
    CBG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    CBB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(CBR);
    Serial.print("GREEN: ");
    Serial.println(CBG);
    Serial.print("BLUE: ");
    Serial.println(CBB);

    tlc.setLED(53,CBR,CBG,CBB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/54/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    CCR = value.substring(0, value.indexOf(',')).toInt();
    CCG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    CCB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(CCR);
    Serial.print("GREEN: ");
    Serial.println(CCG);
    Serial.print("BLUE: ");
    Serial.println(CCB);

    tlc.setLED(54,CCR,CCG,CCB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/55/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    CDR = value.substring(0, value.indexOf(',')).toInt();
    CDG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    CDB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(CDR);
    Serial.print("GREEN: ");
    Serial.println(CDG);
    Serial.print("BLUE: ");
    Serial.println(CDB);

    tlc.setLED(55,CDR,CDG,CDB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/56/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    CER = value.substring(0, value.indexOf(',')).toInt();
    CEG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    CEB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(CER);
    Serial.print("GREEN: ");
    Serial.println(CEG);
    Serial.print("BLUE: ");
    Serial.println(CEB);

    tlc.setLED(56,CER,CEG,CEB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }

  if (String(topic) == "House/SuperIO/Box1/57/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    CFR = value.substring(0, value.indexOf(',')).toInt();
    CFG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    CFB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(CFR);
    Serial.print("GREEN: ");
    Serial.println(CFG);
    Serial.print("BLUE: ");
    Serial.println(CFB);

    tlc.setLED(57,CFR,CFG,CFB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/58/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    CGR = value.substring(0, value.indexOf(',')).toInt();
    CGG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    CGB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(CGR);
    Serial.print("GREEN: ");
    Serial.println(CGG);
    Serial.print("BLUE: ");
    Serial.println(CGB);

    tlc.setLED(58,CGR,CGG,CGB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/59/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    CHR = value.substring(0, value.indexOf(',')).toInt();
    CHG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    CHB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(CHR);
    Serial.print("GREEN: ");
    Serial.println(CHG);
    Serial.print("BLUE: ");
    Serial.println(CHB);

    tlc.setLED(59,CHR,CHG,CHB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/60/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    CIR = value.substring(0, value.indexOf(',')).toInt();
    CIG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    CIB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(CIR);
    Serial.print("GREEN: ");
    Serial.println(CIG);
    Serial.print("BLUE: ");
    Serial.println(CIB);

    tlc.setLED(60,CIR,CIG,CIB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }

  if (String(topic) == "House/SuperIO/Box1/61/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    CJR = value.substring(0, value.indexOf(',')).toInt();
    CJG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    CJB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(CJR);
    Serial.print("GREEN: ");
    Serial.println(CJG);
    Serial.print("BLUE: ");
    Serial.println(CJB);

    tlc.setLED(61,CJR,CJG,CJB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/62/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    CKR = value.substring(0, value.indexOf(',')).toInt();
    CKG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    CKB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(CKR);
    Serial.print("GREEN: ");
    Serial.println(CKG);
    Serial.print("BLUE: ");
    Serial.println(CKB);

    tlc.setLED(62,CKR,CKG,CKB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
  if (String(topic) == "House/SuperIO/Box1/63/Color") {
    // convert payload to String
    String value = String((char*)payload);
    Serial.println (value);
    // split string at every "," and store in proper variable
    // convert final result to integer
    CLR = value.substring(0, value.indexOf(',')).toInt();
    CLG = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    CLB = value.substring(value.lastIndexOf(',') + 1).toInt();

    // print obtained values for debugging
    Serial.print("RED: ");
    Serial.println(CLR);
    Serial.print("GREEN: ");
    Serial.println(CLG);
    Serial.print("BLUE: ");
    Serial.println(CLB);

    tlc.setLED(63,CLR,CLG,CLB);
    tlc.write();

    while (Serial.available())
      Serial.read();

  }
}

EthernetClient ethClient;
PubSubClient client(server, 1883, callback, ethClient);

void setup()
{
  // Open serial communications
  Serial.begin(9600);

  Serial.println("MCP27017 Driver Loading");
  Wire.begin();
  CS.initialize();
  CS.portPullup(0, 0b1111111111111111);
  CS.portPullup(1, 0b1111111111111111);
  CS.portPullup(2, 0b1111111111111111);
  CS.portPullup(3, 0b1111111111111111);
  Serial.println("MCP23017 Driver OK");

  Serial.println("TLC5974 Driver Loading");
  tlc.begin();
  if (oe >= 0) {
    pinMode(oe, OUTPUT);
    digitalWrite(oe, LOW);
  }
  tlc.write();
  Serial.println("TLC5974 Driver OK");

  Serial.println("Checking DHCP:");
  Ethernet.begin(mac);

  Serial.print("My address:");
  Serial.println(Ethernet.localIP());

  if (client.connect("Buttons")) {
    client.publish("House/SuperIO/Box1/Status", "OK");
    Serial.println("Pub OK");
    client.subscribe("House/SuperIO/Box1/#");
    Serial.println("Sub OK");
  }
}

void loop(){
  client.loop();
  for (int RPIN = 0; RPIN <= 63; RPIN++) {
    if (CS.digitalRead (RPIN) == LOW) {
    Serial.println(String("Button ") + RPIN + (" pressed!"));
    String outtopic = PRETOPIC + RPIN + POSTTOPIC;
    const char * msg = outtopic.c_str();
    client.publish(msg, "ON");
    delay(500);
    client.publish(msg, "OFF");

    
    }
  }
}  
