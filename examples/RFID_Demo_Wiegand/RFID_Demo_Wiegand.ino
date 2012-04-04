#include <SeeedRFIDLib.h>
#include <SoftwareSerial.h> 
// SoftwareSerial must be included because the library depends on it
// If you use the Library in Wiegand Mode, then the compiler
// will optimize the SoftwareSerial away

// Configure the Library in Wiegand Mode
SeeedRFIDLib RFID(WIEGAND_26BIT); 
RFIDTag tag;

void setup() 
{
  Serial.begin(57600);
}
void loop()
{
    if(RFID.isIdAvailable()) {
        tag = RFID.readId();
        // In Wiegand Mode, we only get the card code
        Serial.print("CC = ");
        Serial.println(tag.id); 
    }
}


