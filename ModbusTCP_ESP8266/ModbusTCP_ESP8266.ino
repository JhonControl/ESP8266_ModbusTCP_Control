/**
*    Pruebas Esclavo Modbus TCP/IP  -  Modbus TCP/IP SLAVE  
*    
*    More information about projects PDAControl   
*    PDAControl English     http://pdacontrolen.com   
*    
*    Mas informacion sobre proyectos PDAControl
*    PDAControl Espanol     http://pdacontroles.com
*    
*    Channel  Youtube       https://www.youtube.com/c/JhonValenciaPDAcontrol/videos   
*
*/

#include <ESP8266WiFi.h>
#include <ModbusTCPSlave.h>
#include <Ticker.h>
#include <Servo.h> 

//WIFI Settings
//byte ip[]      = { 192, 168, 1, 126};
//byte gateway[] = { 192, 168, 1, 1 };
//byte subnet[]  = { 255, 255, 255, 0 };

Servo myservo; 
Ticker Stop;
ModbusTCPSlave Mb;

const int ledPin =  4;  
const int inputPin =  12;  
const int servoPin =  14;  
const int analogInPin = A0; 


void monitoring() {

///Digital Inputs
//Mb.MBHoldingRegister[0]=digitalRead(inputPin);

////Analog Output PWM
//myservo.write(Mb.MBHoldingRegister[1]);
 
///Digital Outputs 
digitalWrite(ledPin,Mb.MBHoldingRegister[2] );

///Random  int Value
Mb.MBHoldingRegister[3] = random(0,10); 

////Analog Input
Mb.MBHoldingRegister[4] = analogRead(analogInPin);
   
//Debug
 /*
    for (int i=0; i <= 10; i++){ 
      Serial.print(i);  
      Serial.print("- -");  
    Serial.println(Mb.MBHoldingRegister[i]); 

   } 
*/

  }

void setup()
{
 pinMode(ledPin, OUTPUT);
 myservo.attach(servoPin);
 Serial.begin(115200); 
 Mb.begin("**********", "************");   //  Mb.begin("SSID", "PASSWORD", ip, gateway, subnet);
 delay(100);

}

void loop()
{
  
  Mb.Run();
 ////Ticker Function
 Stop.attach_ms(35,monitoring);
  
}

