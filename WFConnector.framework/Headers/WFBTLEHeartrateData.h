//
//  WFBTLEHeartrateData.h
//  WFConnector
//
//  Created by Michael Moore on 5/2/12.
//  Copyright (c) 2012 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WFHeartrateData.h"

@class WFBTLECommonData;


typedef enum
{
	WFBTLEHeartrateData_SensorContactStatus__NotSupported 						= 0,
	WFBTLEHeartrateData_SensorContactStatus__NotSupportedInCurrentConnection 	= 1,
	WFBTLEHeartrateData_SensorContactStatus__ContactNotDetected 				= 2,
	WFBTLEHeartrateData_SensorContactStatus__ContactDetected 					= 3
} WFBTLEHeartrateData_SensorContactStatus;


/**
 * Represents the data available from the BTLE Heart Rate sensor.
 *
 * BTLE sensors send data in multiple packets.  The WFBTLEHeartrateData
 * combines the most commonly used of this data into a single entity.  The data
 * represents the latest of each data type sent from the sensor.
 */
@interface WFBTLEHeartrateData : WFHeartrateData
{
    WFBTLECommonData* btleCommonData;
    NSArray* rrIntervals;
    WFBTLEHeartrateData_SensorContactStatus sensorContactStatus;
}


/**
 * Common sensor data for BTLE sensors, provides information about the sensor.
 *
 * @note This property is only available for BTLE sensors.  All other sensors
 * will have a <c>nil</c> value.
 */
@property (nonatomic, strong) WFBTLECommonData* btleCommonData;
/**
 * Gets an array of R-R intervals reported by the sensor since the last time
 * data was read.
 *
 * When R-R intervals are not available, this property will be <c>nil</c>.
 *
 * When available, this property will contain one or more <b>NSNumber</b> instances,
 * each representing an R-R interval in seconds.  The array is in ascending order
 * (the oldest value is first).  Each <b>NSNumber</b> instance contains an
 * <b>NSTimeInterval</b> value.
 *
 * @note The R-R values represent those reported by the sensor since the last
 * time that WFHeartrateConnection::getHeartrateData was invoked.  The API will
 * cache the R-R intervals received between calls to
 * WFHeartrateConnection::getHeartrateData, and will empty the cache when that
 * method is called.
 */
@property (nonatomic, strong) NSArray* rrIntervals;

// NEED_DOCS:
@property (nonatomic, assign) WFBTLEHeartrateData_SensorContactStatus sensorContactStatus;

@end
