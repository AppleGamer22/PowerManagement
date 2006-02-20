/*
 * Copyright (c) 2005 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef __AppleSmartBatteryManager__
#define __AppleSmartBatteryManager__

#include <IOKit/IOService.h>
#include <IOKit/smbus/IOSMBusController.h>
#include "AppleSmartBattery.h"

void BattLog(char *fmt, ...);

class AppleSmartBattery;

class AppleSmartBatteryManager : public IOService {
    
    OSDeclareDefaultStructors(AppleSmartBatteryManager)
    
public:
    bool start(IOService *provider);
    
    IOReturn performTransaction(IOSMBusTransaction * transaction,
				    IOSMBusTransactionCompletion completion = 0,
				    OSObject * target = 0,
				    void * reference = 0);

    IOReturn setPowerState(unsigned long which, IOService *whom);

    IOReturn message(UInt32 type, IOService *provider, void * argument);

private:
    IOCommandGate               * fGate;
    IOSMBusController           * fProvider;
    AppleSmartBattery           * fBattery;
};

#endif
