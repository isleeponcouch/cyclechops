//
//  WFWahooGymConnectFitnessEquipmentControlData.h
//  WFConnector
//
//  Created by Chris Uroda on 2016-06-23.
//  Copyright (c) 2016 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * Fitness Equipment Control Feature Constants
 */

extern NSString * const WFWahooGymConnectFitnessEquipmentControlFeatureWorkoutControl;
extern NSString * const WFWahooGymConnectFitnessEquipmentControlFeatureSpeedControl;
extern NSString * const WFWahooGymConnectFitnessEquipmentControlFeatureInclineControl;
extern NSString * const WFWahooGymConnectFitnessEquipmentControlFeatureResistanceLevelControl;
extern NSString * const WFWahooGymConnectFitnessEquipmentControlFeatureTargetPowerControl;
extern NSString * const WFWahooGymConnectFitnessEquipmentControlFeatureTargetHeartRateControl;
extern NSString * const WFWahooGymConnectFitnessEquipmentControlFeatureIndoorBikeSimulationControl;



/**
 * A Value Object Class for Bike Simulation Constants
 */
@interface WFWahooGymConnectFitnessEquipmentControlIndoorBikeSimulationConstants : NSObject
{
    /** \cond InterfaceDocs */
    
    double _wheelCircumference;
    double _totalWeight;
    
	/** \endcond */
}

/**
 * Wheel Circumference. Units are Millimetres
 */
@property (nonatomic, assign) double wheelCircumference;


/**
 * Total Weight (Rider Weight + Bike Weight). Units are Kilograms
 */
@property (nonatomic, assign) double totalWeight;

@end



/**
 * A Value Object Class for Bike Simulation Settings
 */
@interface WFWahooGymConnectFitnessEquipmentControlIndoorBikeSimulationSettings : NSObject
{
    /** \cond InterfaceDocs */
    
    double _windSpeed;
    double _incline;
    double _crr;
    double _cw;
    
    /** \endcond */
}

/**
 * Wind speed component in the direction of travel. Units are metres per second.
 * Positive values indicate a head wind, negative values indicate a tail wind.
 */
@property (nonatomic, assign) double windSpeed;


/**
 * Incline (Grade) setting. Units are % Grade.
 * 0% grade is flat, 100% grade is 45 degrees "uphill", -100% grade is 45 degrees "downhill".
 */
@property (nonatomic, assign) double incline;


/**
 * Coefficient of Rolling Resistance.  Unitless
 */
@property (nonatomic, assign) double crr;


/**
 * Coefficient of Wind Resistance.  Units are Kilograms per Metre (Kg/m)
 */
@property (nonatomic, assign) double cw;


@end

