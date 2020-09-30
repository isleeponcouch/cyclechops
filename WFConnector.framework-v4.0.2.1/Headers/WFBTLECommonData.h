//
//  WFBTLECommonData.h
//  WFConnector
//
//  Created by Michael Moore on 12/22/11.
//  Copyright (c) 2011 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WFConnector/WFSensorData.h>
#import <WFConnector/wf_btle_types.h>


/**
 * Represents the metadata for the sensor, available from most BTLE sensors.
 */
@interface WFBTLECommonData : NSObject
{
	/** \cond InterfaceDocs */
	
    // Generic Access Service values.
    NSString* deviceName;
    USHORT appearance;
    
    // Device Information Service values.
    NSString* manufacturerName;
    NSString* modelNumber;
    NSString* serialNumber;
    NSString* hardwareRevision;
    NSString* firmwareRevision;
    NSString* softwareRevision;
    uint64_t systemId;
    
    // Battery Service values.
    UCHAR batteryLevel;
    WFBTLEBattPowerState_t batteryPowerState;
    
	/** \endcond */
}


/** Gets the device name. */
@property (nonatomic, copy) NSString* deviceName;
/** Gets a value indicating the device apperance. */
@property (nonatomic, assign) USHORT appearance;

/** Gets the device manufacturer name. */
@property (nonatomic, copy) NSString* manufacturerName;
/** Gets the device model number. */
@property (nonatomic, copy) NSString* modelNumber;
/** Gets the device serial number. */
@property (nonatomic, copy) NSString* serialNumber;
/** Gets the device hardware revision. */
@property (nonatomic, copy) NSString* hardwareRevision;
/** Gets the device firmware revision. */
@property (nonatomic, copy) NSString* firmwareRevision;
/** Gets the device software revision. */
@property (nonatomic, copy) NSString* softwareRevision;
/** Gets the device system ID. */
@property (nonatomic, assign) uint64_t systemId;

/** Gets the battery level (<c>WF_BTLE_BATT_LEVEL_INVALID</c> if not supported). */
@property (nonatomic, assign) UCHAR batteryLevel;
/** Gets the battery power state. */
@property (nonatomic, assign) WFBTLEBattPowerState_t batteryPowerState;

@end
