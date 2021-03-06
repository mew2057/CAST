/*================================================================================

    csmnet/src/CPP/endpoint_utility.cc

  © Copyright IBM Corporation 2015-2019. All Rights Reserved

    This program is licensed under the terms of the Eclipse Public License
    v1.0 as published by the Eclipse Foundation and available at
    http://www.eclipse.org/legal/epl-v10.html

    U.S. Government Users Restricted Rights:  Use, duplication or disclosure
    restricted by GSA ADP Schedule Contract with IBM Corp.

================================================================================*/

#include <cstdio>
#include <exception>
#include <iostream>
#include <algorithm>

#include <sys/types.h>   // stat()

#include <unistd.h>      // close()
#include <sys/socket.h>  // socket calls
#include <sys/un.h>      // struct sockaddr_un
#include <fcntl.h>       // setting non-blocking socket

#include <errno.h>

#include <logging.h>
#include "csm_network_config.h"
#include "csm_network_exception.h"
#include "csm_network_msg_cpp.h"
#include "address.h"
#include "endpoint_ptp.h"
#include "endpoint_utility.h"

csm::network::EndpointUtility_plain::EndpointUtility_plain( const csm::network::Address_sptr aLocalAddr,
                                                            const csm::network::EndpointOptions_sptr aOptions )
: csm::network::EndpointPTP_base( aLocalAddr, aOptions )
{
  csm::network::EndpointOptionsUtility_sptr ptpOptions =
      std::dynamic_pointer_cast<csm::network::EndpointOptionsPTP<csm::network::AddressUtility>>( _Options );

  if( IsServerEndpoint() )
  {
    PrepareServerSocket<csm::network::AddressUtility>();
    SetRemoteAddr( _LocalAddr );
  }
  else
    if( ! ptpOptions->_ServerAddr.IsEmpty() )
    {
      int rc = Connect( std::make_shared<csm::network::AddressUtility>( ptpOptions->_ServerAddr ) );
      if( rc )
        throw csm::network::ExceptionEndpointDown("Socket creation - connect");
    }

  LOG( csmnet, debug ) << "EndpointUtility_plain created.";
}

  /* Connects to a server and returns the address
   */
int
csm::network::EndpointUtility_plain::Connect( const Address_sptr aSrvAddr )
{
  int rc = ConnectPrep<csm::network::AddressUtility>( aSrvAddr );
  if( rc == 0 )
    _Connected = true;

  if( _Connected )
    rc = ConnectPost();

  return rc;
}

csm::network::Endpoint*
csm::network::EndpointUtility_plain::Accept( )
{
  return GenericPTPAccept<csm::network::AddressUtility, csm::network::EndpointUtility_plain>();
}

// message based send
ssize_t
csm::network::EndpointUtility_plain::SendTo( const csm::network::Message &aMsg,
                                             const Address_sptr aRemoteAddr )
{
  const csm::network::AddressUtility *addr = dynamic_cast<const csm::network::AddressUtility*>( aRemoteAddr.get() );
  if( addr == nullptr )
    throw csm::network::ExceptionEndpointDown("Wrong or Null remote address.", ENOTCONN );
  if( *addr != *(csm::network::AddressUtility*)_RemoteAddr.get() )
    LOG( csmnet, warning ) << "EndpointUtility_plain::SendTo(): Request to send to different address than connected. Given address IGNORED!";

  return Send( aMsg );
}












csm::network::EndpointUtility_sec::EndpointUtility_sec( const Address_sptr aLocalAddr,
                         const EndpointOptions_sptr aOptions )
: csm::network::EndpointPTP_sec_base( aLocalAddr, aOptions )
{
  csm::network::EndpointOptionsUtility_sptr ptpOptions =
      std::dynamic_pointer_cast<csm::network::EndpointOptionsPTP<csm::network::AddressUtility>>( _Options );

  if( IsServerEndpoint() )
  {
    PrepareServerSocket<csm::network::AddressUtility>();
    SetRemoteAddr( _LocalAddr );
  }
  else
    if( ! ptpOptions->_ServerAddr.IsEmpty() )
    {
      int rc = Connect( std::make_shared<csm::network::AddressUtility>( ptpOptions->_ServerAddr ) );
      if( rc )
        throw csm::network::ExceptionEndpointDown("Socket creation - connect");
    }
}

  /* Connects to a server and returns the address
   */
int
csm::network::EndpointUtility_sec::Connect( const csm::network::Address_sptr aSrvAddr )
{
  int rc = ConnectPrep<csm::network::AddressUtility>( aSrvAddr );

  // stop any ssl setup if not connected
  if( rc != 0 )
    return rc;

  return EndpointPTP_sec_base::Connect( aSrvAddr );
}

csm::network::Endpoint*
csm::network::EndpointUtility_sec::Accept( )
{
  return GenericAcceptSSL<csm::network::AddressUtility, csm::network::EndpointUtility_sec>();
}

ssize_t csm::network::EndpointUtility_sec::SendTo( const csm::network::Message &aMsg,
                                                   const csm::network::Address_sptr aRemoteAddr )
{
  const csm::network::AddressUtility *addr = dynamic_cast<const csm::network::AddressUtility*>( aRemoteAddr.get() );
  if( addr == nullptr )
    throw csm::network::ExceptionEndpointDown("Wrong or Null remote address.", ENOTCONN );
  if( *addr != *(csm::network::AddressUtility*)_RemoteAddr.get() )
    LOG( csmnet, warning ) << "EndpointUtility_sec::SendTo(): Request to send to different address than connected. Given address IGNORED!";

  return csm::network::EndpointPTP_sec_base::Send( aMsg );
}

