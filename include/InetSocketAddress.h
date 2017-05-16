#ifndef LIBNET_DISTRIBUTION_INETSOCKETADDRESS_H
#define LIBNET_DISTRIBUTION_INETSOCKETADDRESS_H
#include "InetAddress.h"

namespace net
{

class InetSocketAddress
{
public:
  //Creates a socket address from an IP address and a port number
  InetSocketAddress(const InetAddress& addr, int port);

  //Creates a socket address where the IP address is the wildcard address and the port number a specified value
  InetSocketAddress(int port);

  //Creates a socket address from a hostname and a port number
  InetSocketAddress(const char* hostname, int port);

  //Gets the InetAddress
  InetAddress get_address() const;

  //Gets the port number
  int get_port() const;

private:
  InetSocketAddress() {}


  union {
    struct sockaddr_in sockaddr_;
    struct sockaddr_in6 sockaddr6_;
  };



};

}



#endif //LIBNET_DISTRIBUTION_INETSOCKETADDRESS_H