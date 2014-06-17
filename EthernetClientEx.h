
//Requires your sketch to include Ethernet.h
#include <Arduino.h>
#include <utility/w5100.h>

template<typename Tag, typename Tag::type M>
  struct AccessMember{ 
    friend typename Tag::type get( Tag ){ return M; }
};

struct EthernetClient_Socket{ 
  typedef uint8_t EthernetClient::*type;
  friend type get( EthernetClient_Socket );
};

template struct AccessMember< EthernetClient_Socket, &EthernetClient::_sock >;

IPAddress RemoteIP( EthernetClient &c ){
  byte remoteIP[ 4 ];
  W5100.readSnDIPR( c.*get( EthernetClient_Socket() ), remoteIP );
  return ( remoteIP );
}

struct EthernetClientEx : EthernetClient{

	operator bool(){ return *( ( EthernetClient* ) this ) == true; }
	
	EthernetClientEx( uint8_t sock ) : EthernetClient( sock ) {}
	IPAddress RemoteIP() { return ::RemoteIP( *this ); }
	
	
};

//EOF