//
//  WFWahooGymConnectControlEventsDelegate.h
//  WFConnector
//
//  Created by Chris Uroda 2016-06-23
//  Copyright (c) 2016 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WFConnector/WFWahooGymConnectFitnessEquipmentControlData.h>


@protocol WFWahooGymConnectControlEventsDelegate <NSObject>

@optional


/**
 * Invoked when the Supported Fitness Equipment Control Features have been fetched.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param supportedControlFeatures A Set of the supported control features.  Elements of this set are WFWahooGymConnectFitnessEquipmentControlFeature string constants.
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchFitnessEquipmentControlSupportedFeatures:(NSSet *)supportedControlFeatures withError:(NSError *)error;


/**
 * Invoked when the Fitness Equipment Control Reset has been requested.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didRequestFitnessEquipmentControlResetWithError:(NSError *)error;


/**
 * Invoked when the Fitness Equipment Control Workout Start has been requested.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didRequestFitnessEquipmentControlWorkoutStartWithError:(NSError *)error;


/**
 * Invoked when the Fitness Equipment Control Workout Pause has been requested.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didRequestFitnessEquipmentControlWorkoutPauseWithError:(NSError *)error;


/**
 * Invoked when the Fitness Equipment Control Workout Resume has been requested.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didRequestFitnessEquipmentControlWorkoutResumeWithError:(NSError *)error;


/**
 * Invoked when the Fitness Equipment Control Workout Finish has been requested.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didRequestFitnessEquipmentControlWorkoutFinishWithError:(NSError *)error;



// +--------------------------------------------------------------------------------------------+
//                  Speed
// +--------------------------------------------------------------------------------------------+

/**
 * Invoked when the Fitness Equipment Control Speed Setting change has been requested.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didRequestFitnessEquipmentControlSpeedSettingChangeWithError:(NSError *)error;


/**
 * Invoked when current Fitness Equipment Control Speed setting has been fetched.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param speedSettingKph The current speed setting in kilometres per hour
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchFitnessEquipmentControlCurrentSpeedSetting:(double)speedSettingKph withError:(NSError *)error;


/**
 * Invoked when Fitness Equipment Control Speed setting limits have been fetched.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param min The minimum supported speed setting in kilometres per hour
 * @param max The maximum supported speed setting in kilometres per hour
 * @param increment The minimum supported speed setting increment in kilometres per hour
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchFitnessEquipmentControlSpeedSettingLimitsMin:(double)min max:(double)max increment:(double)increment error:(NSError *)error;


/**
 * Invoked when a Speed Setting Adjusted event is received from the Fitness Equipment
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param speedSettingKph The new speed setting (as set via the fitness equipment console/interface) in kilometres per hour
 */
- (void)wahooGymConnect:(id)sender didReceiveFitnessEquipmentControlSpeedSettingAdjustedEventWithSettingValue:(double)speedSettingKph;



// +--------------------------------------------------------------------------------------------+
//                  Incline (Grade)
// +--------------------------------------------------------------------------------------------+

/**
 * Invoked when the Fitness Equipment Control Incline Setting change has been requested.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didRequestFitnessEquipmentControlInclineSettingChangeWithError:(NSError *)error;


/**
 * Invoked when current Fitness Equipment Control Incline setting has been fetched.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param inclineSettingPercent The current incline setting in Per cent grade
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchFitnessEquipmentControlCurrentInclineSetting:(double)inclineSettingPercent withError:(NSError *)error;


/**
 * Invoked when Fitness Equipment Control Incline setting limits have been fetched.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param min The minimum supported incline setting in Per cent grade
 * @param max The maximum supported incline setting in Per cent grade
 * @param increment The minimum supported incline setting increment in Per cent grade
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchFitnessEquipmentControlInclineSettingLimitsMin:(double)min max:(double)max increment:(double)increment error:(NSError *)error;


/**
 * Invoked when an Incline Setting Adjusted event is received from the Fitness Equipment
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param inclineSettingPercent The new incline setting (as set via the fitness equipment console/interface) in Per cent grade
 */
- (void)wahooGymConnect:(id)sender didReceiveFitnessEquipmentControlInclineSettingAdjustedEventWithSettingValue:(double)inclineSettingPercent;




// +--------------------------------------------------------------------------------------------+
//                  Resistance Level
// +--------------------------------------------------------------------------------------------+

/**
 * Invoked when the Fitness Equipment Control Resistance Level Setting change has been requested.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didRequestFitnessEquipmentControlResistanceLevelSettingChangeWithError:(NSError *)error;


/**
 * Invoked when current Fitness Equipment Control Resistance Level setting has been fetched.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param resistanceLevelSetting The current resistance level setting
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchFitnessEquipmentControlCurrentResistanceLevelSetting:(double)resistanceLevelSetting withError:(NSError *)error;


/**
 * Invoked when Fitness Equipment Control Resistance Level setting limits have been fetched.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param min The minimum supported resistance level setting
 * @param max The maximum supported resistance level setting
 * @param increment The minimum supported resistance level setting increment
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchFitnessEquipmentControlResistanceLevelSettingLimitsMin:(double)min max:(double)max increment:(double)increment error:(NSError *)error;


/**
 * Invoked when a Resistance Level Setting Adjusted event is received from the Fitness Equipment
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param resistanceLevelSetting The new resistance level setting (as set via the fitness equipment console/interface)
 */
- (void)wahooGymConnect:(id)sender didReceiveFitnessEquipmentControlResistanceLevelSettingAdjustedEventWithSettingValue:(double)resistanceLevelSetting;




// +--------------------------------------------------------------------------------------------+
//                  Target Power
// +--------------------------------------------------------------------------------------------+

/**
 * Invoked when the Fitness Equipment Control Target Power Setting change has been requested.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didRequestFitnessEquipmentControlTargetPowerSettingChangeWithError:(NSError *)error;


/**
 * Invoked when current Fitness Equipment Control Target Power setting has been fetched.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param resistanceLevelSetting The current target power setting in Watts
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchFitnessEquipmentControlCurrentTargetPowerSetting:(double)targetPowerSettingWatts withError:(NSError *)error;


/**
 * Invoked when Fitness Equipment Control Target Power setting limits have been fetched.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param min The minimum supported target power setting in Watts
 * @param max The maximum supported target power setting in Watts
 * @param increment The minimum supported target power setting increment in Watts
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchFitnessEquipmentControlTargetPowerSettingLimitsMin:(double)min max:(double)max increment:(double)increment error:(NSError *)error;


/**
 * Invoked when a Target Power Setting Adjusted event is received from the Fitness Equipment
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param targetPowerSettingWatts The new target power setting (as set via the fitness equipment console/interface) in Watts
 */
- (void)wahooGymConnect:(id)sender didReceiveFitnessEquipmentControlTargetPowerSettingAdjustedEventWithSettingValue:(double)targetPowerSettingWatts;




// +--------------------------------------------------------------------------------------------+
//                  Target Heart Rate
// +--------------------------------------------------------------------------------------------+

/**
 * Invoked when the Fitness Equipment Control Target Heart Rate Setting change has been requested.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didRequestFitnessEquipmentControlTargetHeartRateSettingChangeWithError:(NSError *)error;


/**
 * Invoked when current Fitness Equipment Control Target Power setting has been fetched.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param targetHeartRateSettingBPM The current target heart rate setting in beats per minute
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchFitnessEquipmentControlCurrentTargetHeartRateSetting:(uint8_t)targetHeartRateSettingBPM withError:(NSError *)error;


/**
 * Invoked when Fitness Equipment Control Target Heart Rate setting limits have been fetched.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param min The minimum supported target heart rate setting in beats per minute
 * @param max The maximum supported target heart rate setting in beats per minute
 * @param increment The minimum supported target heart rate setting increment in beats per minute
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchFitnessEquipmentControlTargetHeartRateSettingLimitsMin:(double)min max:(double)max increment:(double)increment error:(NSError *)error;


/**
 * Invoked when a Target Heart Rate Setting Adjusted event is received from the Fitness Equipment
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param targetHeartRateSettingBPM The new target heart rate setting (as set via the fitness equipment console/interface) in beats per minute
 */
- (void)wahooGymConnect:(id)sender didReceiveFitnessEquipmentControlTargetHeartRateSettingAdjustedEventWithSettingValue:(uint8_t)targetHeartRateSettingBPM;




// +--------------------------------------------------------------------------------------------+
//                  Indoor Bike Simulation
// +--------------------------------------------------------------------------------------------+

/**
 * Invoked when the Fitness Equipment Control Indoor Bike Simulation Constants change have been requested.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didRequestFitnessEquipmentControlIndoorBikeSimulationConstantsChangeWithError:(NSError *)error;


/**
 * Invoked when current Fitness Equipment Control Indoor Bike Simulation Constants have been fetched.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param indoorBikeSimulationConstants The current Indoor Bike Simulation Constants
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchFitnessEquipmentControlCurrentIndoorBikeSimulationConstants:(WFWahooGymConnectFitnessEquipmentControlIndoorBikeSimulationConstants *)indoorBikeSimulationConstants withError:(NSError *)error;


/**
 * Invoked when a Indoor Bike Simulation Constants Adjusted event is received from the Fitness Equipment
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param indoorBikeSimulationConstants The new Indoor Bike Simulation Constants (as set via the fitness equipment console/interface)
 */
- (void)wahooGymConnect:(id)sender didReceiveFitnessEquipmentControlIndoorBikeSimulationConstantsAdjustedEventWithSettingValue:(WFWahooGymConnectFitnessEquipmentControlIndoorBikeSimulationConstants *)indoorBikeSimulationConstants;


/**
 * Invoked when the Fitness Equipment Control Indoor Bike Simulation Settings change has been requested.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didRequestFitnessEquipmentControlIndoorBikeSimulationSettingsChangeWithError:(NSError *)error;


/**
 * Invoked when current Fitness Equipment Control Indoor Bike Simulation Settings have been fetched.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param indoorBikeSimulationSettings The current Indoor Bike Simulation Settings
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchFitnessEquipmentControlCurrentIndoorBikeSimulationSettings:(WFWahooGymConnectFitnessEquipmentControlIndoorBikeSimulationSettings *)indoorBikeSimulationSettings withError:(NSError *)error;


/**
 * Invoked when a Indoor Bike Simulation Settings Adjusted event is received from the Fitness Equipment
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param indoorBikeSimulationSettings The new Indoor Bike Simulation Settings (as set via the fitness equipment console/interface)
 */
- (void)wahooGymConnect:(id)sender didReceiveFitnessEquipmentControlIndoorBikeSimulationSettingAdjustedEventWithSettingValue:(WFWahooGymConnectFitnessEquipmentControlIndoorBikeSimulationSettings *)indoorBikeSimulationSettings;




@end