
#include <Ethernet.h>
#include <SPI.h>
#include <EthernetClientEx.h>

void setup() {


  //If you prefer to use the original EthernetClient class, you can
  //pass the instance to RemoteIP.
  
  EthernetClient c;
  Serial.print( RemoteIP( c ) );
  
  
  //If you use EthernetClientEx, it has RemoteIP() built in.
  EthernetClientEx d;
  Serial.print( d.RemoteIP() );
 
}

void loop() {

  
}
