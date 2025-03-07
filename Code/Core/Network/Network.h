// Network
//------------------------------------------------------------------------------
#pragma once

// Includes
//------------------------------------------------------------------------------
#include "Core/Strings/AStackString.h"

// Forward Declarations
//------------------------------------------------------------------------------
class AString;

// Network
//------------------------------------------------------------------------------
class Network
{
public:
    static void GetHostName( AString & hostName );
    static void GetDomainName( AString & domainName );
    static void GetIPv4Addresses( Array<AString> & outAddresses );
    static uint32_t GetHostIPFromName( const AString & hostName, uint32_t timeoutMS = 1000 );

private:
    static uint32_t NameResolutionThreadFunc( void * userData );

    struct NameResolutionData
    {
        AStackString<>  hostName;
        bool            safeToFree;
    };
};

//------------------------------------------------------------------------------
