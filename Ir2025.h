#include "IRremote.h"

struct Ir2025 {
  IRrecv irrecv = NULL;
  decode_results results; 
  Ir2025(int irPin) {
    irrecv = IRrecv(irPin); 
    irrecv.enableIRIn();
  }

  int getIrValue() {
    //irrecv = new IRrecv(receiver);
    int irVal = -1;
    if (irrecv.decode(&results)) // have we received an IR signal?
    {
      irVal = translateIR();
      irrecv.resume(); // receive the next value
    }  
    return irVal;
  }


//TODO this is specifically for the CR2025, this should not be :)

/*-----( Declare User-written Functions )-----
// takes action based on IR code received
// describing Car MP3 IR codes 
*/
  int translateIR() {
    switch(results.value)  {
    case 0xFFE01F:  
      return 10;
      
    case 0xFFA857:  
      return 11;
      
    case 0xFF906F:  
      return 12; 
      
    case 0xFF6897:  
      return 0; 
      
    case 0xFF9867:  
      return 13;
      
    case 0xFFB04F:  
      return 14;
      
    case 0xFF30CF:  
      return 1; 
      
    case 0xFF18E7:  
      return 2; 
      
    case 0xFF7A85:  
      return 3; 
      
    case 0xFF10EF:  
      return 4; 
      
    case 0xFF38C7:  
      return 5; 
      
    case 0xFF5AA5:  
      return 6; 
      
    case 0xFF42BD:  
      return 7; 
      
    case 0xFF4AB5:  
      return 8; 
      
    case 0xFF52AD:  
      return 9; 
      
    default: 
      //Serial.println(" other button   ");
      return -1;
    }
  }
};
