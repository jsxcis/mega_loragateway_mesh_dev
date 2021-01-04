#include <EEPROM.h>
#include <RHRouter.h>
#include <RHMesh.h>
#include <RH_RF95.h>

uint8_t nodeId = 99;


#define RFM95_CS 10
#define RFM95_RST 9
#define RFM95_INT 2

#define XCIS_RH_MESH_MAX_MESSAGE_LEN 32

// Singleton instance of the radio driver
//RH_RF95 rf95;
RH_RF95 rf95(RFM95_CS, RFM95_INT);

// Class to manage message delivery and receipt, using the driver declared above
RHMesh *manager;

// message buffer
char buf[RH_MESH_MAX_MESSAGE_LEN];
   
bool gotESPMessage = false;
bool gotScanMessage = false;
char inData[20]; // Allocate some space for the string
char inChar; // Where to store the character read
int index = 0; // Index into array; where to store the character

String inbound;
String buffer;
String outgoing;              // outgoing message
String command = "";               // command from ESP

byte msgCount = 0;            // count of outgoing messages
byte localAddress = 0xFF;     // address of this device
long lastSendTime = 0;        // last send time
String sensorData = "";

#define LORA_SEND 22
#define LORA_RECV 23


void setup() 
{
    pinMode(RFM95_RST, OUTPUT);
    digitalWrite(RFM95_RST, HIGH);
  
    Serial.begin(115200);     // communication with the host computer
    pinMode(LORA_SEND, OUTPUT);
    pinMode(LORA_RECV, OUTPUT);
    while (!Serial)   { ; }
    // Start the software serial for communication with the ESP8266
    Serial3.begin(115200);  
    while (!Serial3)   { ; }
    Serial.println("");

    manager = new RHMesh(rf95, nodeId);

    if (!manager->init()) {
      Serial.println(F("init failed"));
    } else {
    Serial.println("done");
    }
    rf95.setTxPower(23, false);
    rf95.setFrequency(915.0);
    rf95.setCADTimeout(500);

    Serial.println("RH LoRa Gateway init succeeded.");
    Serial.println("Ready");
    Serial.println(""); 
    flashStartUp();
}
void loop() 
{ 
  if (Serial3.available())
  {
    Serial.println("Serial port available");
    // listen for communication from the ESP8266
    char scanStarter = '0';
    char peeked = Serial3.peek();
    if (scanStarter == peeked)
    {
       Serial.println("Found Start of Scan message from ESP");
       gotScanMessage = true;
    }
    while(Serial3.available() > 0) // Don't read unless there you know there is data
    {  
      if(index < 18) // Reads 18 bytes message ID:REQUEST:DXX:EOM
      {
          inChar = Serial3.read(); // Read a character
          inData[index] = inChar; // Store it
          index++; // Increment where to write next
          inData[index] = '\0'; // Null terminate the string
      }
    } 
    if (index >=18)
    { 
      //Serial.print(String(inData));
      String req;
      req = inData;
      processCommand(req);
      for(int i=0;i<19;i++)
      {
        inData[i]=0;
      }
      index = 0;
      gotScanMessage = false;
    }
  }

     sensorData = receiveFromMesh();
    if (sensorData != "")
    {
        Serial.println("Got valid command - sending data");
        Serial.println(sensorData);
        writeData(sensorData);
    } 
    sensorData = "";
}
