//
//  WFWahooGymConnectFitnessEquipmentData.h
//  WFConnector
//
//  Created by Chris Uroda on 2015-02-20.
//  Copyright (c) 2015 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WFConnector/WFSensorData.h>
#import <WFConnector/wf_btle_types.h>

@class WFBTLECommonData;


/**
 * Fitness Equipment State Enumeration
 */
typedef NS_ENUM(NSInteger, WFWahooGymConnectFitnessEquipmentState_t) {
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_STATE_UNKNOWN                = 0,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_STATE_IDLE                   = 1,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_STATE_PAUSED                 = 2,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_STATE_IN_USE                 = 10,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_STATE_IN_USE_WARMING_UP      = 11,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_STATE_IN_USE_LOW_INTENSITY   = 12,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_STATE_IN_USE_HIGH_INTENSITY  = 13,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_STATE_IN_USE_RECOVERY        = 14,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_STATE_FINISHED               = 128,
};



/**
 * Fitness Equipment Type Enumeration
 */
typedef NS_ENUM(NSInteger, WFWahooGymConnectFitnessEquipmentType_t) {
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_TYPE_UNKNOWN                 = 0,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_TYPE_TREADMILL               = 1,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_TYPE_BIKE                    = 2,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_TYPE_STEPPER                 = 3,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_TYPE_STEP_MILL               = 4,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_TYPE_CROSS_TRAINER           = 5,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_TYPE_TOTAL_BODY_TRAINER      = 6,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_TYPE_TREADCLIMBER            = 7,
    WF_WAHOO_GYM_CONNECT_FITNESS_EQUIPMENT_TYPE_ROWER                   = 8,
};



/**
 * Represents the Fitness Equipment state information for the Wahoo Fitness Gym Connect device.
 */
@interface WFWahooGymConnectFitnessEquipmentStateInformation : NSObject

{
    /** \cond InterfaceDocs */
    
    // ivars for public properties
    WFWahooGymConnectFitnessEquipmentState_t _state;
    NSString* _customInUseStateName;

    // ivars for private properties
    
    /** \endcond */
}


/**
 * The last known state of the fitness equipment
 */
@property (nonatomic, assign) WFWahooGymConnectFitnessEquipmentState_t state;

/**
 * The fitness equipment can optionally provide a custom "In Use" state name.
 */
@property (nonatomic, strong) NSString* customInUseStateName;

@end



/**
 * Represents the workout data available from the Wahoo Fitness Gym Connect device.
 */
@interface WFWahooGymConnectFitnessEquipmentData : WFSensorData
{
	/** \cond InterfaceDocs */
	
    // ivars for public properties
    WFBTLECommonData* _btleCommonData;
    NSNumber* _elapsedWorkoutTime;
    NSNumber* _remainingWorkoutTime;
    NSNumber* _currentHeartRate;
    NSNumber* _currentLevel;
    NSNumber* _currentResistance;
    NSNumber* _currentSpeed;
    NSNumber* _currentCadence;
    NSNumber* _cumulativeMovements;
    NSNumber* _cumulativeHorizontalDistance;
    NSNumber* _cumulativeVerticalDistance;
    NSNumber* _cumulativeVerticalDistanceNegative;
    NSNumber* _cumulativeEnergy;
    NSNumber* _currentEnergyRate;
    NSNumber* _currentMETs;
    NSNumber* _currentPower;
    NSNumber* _currentTorque;
    NSNumber* _currentGear;
    NSNumber* _currentGrade;
    NSNumber* _currentAngle;
    NSNumber* _currentFloorRate;
    NSNumber* _cumulativeFloors;
    NSNumber* _cumulativeLaps;
    NSNumber* _currentMovementLength;

    // ivars for private properties
    
    
	/** \endcond */
}


/** Gets the metadata for the BTLE device. */
@property (nonatomic, strong) WFBTLECommonData* btleCommonData;

/** The timestamp when this data was last updated */
@property (nonatomic, readonly) NSTimeInterval lastDataTime;

@property (nonatomic, strong) NSNumber* elapsedWorkoutTime;                 /**< Units are seconds */
@property (nonatomic, strong) NSNumber* remainingWorkoutTime;               /**< Units are seconds */
@property (nonatomic, strong) NSNumber* currentHeartRate;                   /**< Units are BPM */
@property (nonatomic, strong) NSNumber* currentLevel;                       /**<  */
@property (nonatomic, strong) NSNumber* currentResistance;                  /**<  */
@property (nonatomic, strong) NSNumber* currentSpeed;                       /**< Units are km/h */
@property (nonatomic, strong) NSNumber* currentCadence;                     /**< Units are RPM or Steps per minute etc. */
@property (nonatomic, strong) NSNumber* cumulativeMovements;                /**< Units are steps/strokes etc. depending on the fitness equipment being used */
@property (nonatomic, strong) NSNumber* cumulativeHorizontalDistance;       /**< Units are kilometres */
@property (nonatomic, strong) NSNumber* cumulativeVerticalDistance;         /**< Units are metres */
@property (nonatomic, strong) NSNumber* cumulativeVerticalDistanceNegative; /**< Units are metres */
@property (nonatomic, strong) NSNumber* cumulativeEnergy;                   /**< Units are Kilogram calories */
@property (nonatomic, strong) NSNumber* currentEnergyRate;                  /**< Units are Kilogram calories / hour */
@property (nonatomic, strong) NSNumber* currentMETs;                        /**< Units are METs */
@property (nonatomic, strong) NSNumber* currentPower;                       /**< Units are Watts */
@property (nonatomic, strong) NSNumber* currentTorque;                      /**< Units are newton.metres */
@property (nonatomic, strong) NSNumber* currentGear;                        /**< The current gear number */
@property (nonatomic, strong) NSNumber* currentGrade;                       /**< Units are % Grade. 0% is flat, 100% is 45 degrees uphill, -100% is 45 degrees downhill */
@property (nonatomic, strong) NSNumber* currentAngle;                       /**< Units are Degrees, 0 is flat, 90 is straight up, -90 is straight down */
@property (nonatomic, strong) NSNumber* currentFloorRate;                   /**< Units are Floors per minute */
@property (nonatomic, strong) NSNumber* cumulativeFloors;                   /**< Units are Floors */
@property (nonatomic, strong) NSNumber* cumulativeLaps;                     /**< Units are Laps */
@property (nonatomic, strong) NSNumber* currentMovementLength;              /**< Units are meters */





@end

