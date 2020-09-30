//
//  WFWahooGymConnectFitnessEquipmentSummaryData.h
//  WFConnector
//
//  Created by Chris Uroda on 2016-05-24.
//  Copyright (c) 2016 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WFConnector/WFSensorData.h>
#import <WFConnector/wf_btle_types.h>

@class WFBTLECommonData;


/**
 * Represents the workout summary data available from the Wahoo Fitness Gym Connect device.
 */
@interface WFWahooGymConnectFitnessEquipmentSummaryData : WFSensorData
{
	/** \cond InterfaceDocs */
	
    // ivars for public properties
    WFBTLECommonData* _btleCommonData;
    NSNumber* _totalWorkoutTime;
    NSNumber* _totalDistance;
    NSNumber* _averageSpeed;
    NSNumber* _totalMovements;
    NSNumber* _averageCadence;
    NSNumber* _totalFloors;
    NSNumber* _averageFloorRate;
    NSNumber* _totalVerticalDistance;
    NSNumber* _totalVerticalDistanceNegative;
    NSNumber* _averagePower;
    NSNumber* _averageHeartRate;
    NSNumber* _maximumHeartRate;
    NSNumber* _totalEnergy;
    NSNumber* _averageEnergyRate;
    NSNumber* _averageMETs;
    NSNumber* _totalLaps;
    
    // ivars for private properties
    
	/** \endcond */
}


/** Gets the metadata for the BTLE device. */
@property (nonatomic, strong) WFBTLECommonData* btleCommonData;

/** The timestamp when this data was last updated */
@property (nonatomic, readonly) NSTimeInterval lastDataTime;

@property (nonatomic, strong) NSNumber* totalWorkoutTime;                   /**< Units are seconds */
@property (nonatomic, strong) NSNumber* totalDistance;                      /**< Units are kilometres */
@property (nonatomic, strong) NSNumber* averageSpeed;                       /**< Units are km/h */
@property (nonatomic, strong) NSNumber* totalMovements;                     /**< Units are steps/strokes etc. depending on the fitness equipment being used */
@property (nonatomic, strong) NSNumber* averageCadence;                     /**< Units are RPM or Steps per minute etc. */
@property (nonatomic, strong) NSNumber* totalFloors;                        /**< Units are Floors */
@property (nonatomic, strong) NSNumber* averageFloorRate;                   /**< Units are Floors per minute */
@property (nonatomic, strong) NSNumber* totalVerticalDistance;              /**< Units are metres */
@property (nonatomic, strong) NSNumber* totalVerticalDistanceNegative;      /**< Units are metres */
@property (nonatomic, strong) NSNumber* averagePower;                       /**< Units are Watts */
@property (nonatomic, strong) NSNumber* averageHeartRate;                   /**< Units are BPM */
@property (nonatomic, strong) NSNumber* maximumHeartRate;                   /**< Units are BPM */
@property (nonatomic, strong) NSNumber* totalEnergy;                        /**< Units are Kilogram calories */
@property (nonatomic, strong) NSNumber* averageEnergyRate;                  /**< Units are Kilogram calories / hour */
@property (nonatomic, strong) NSNumber* averageMETs;                        /**< Units are METs */
@property (nonatomic, strong) NSNumber* totalLaps;                          /**< Units are Laps */


@end

