//
//  WFWahooGymConnectConnection.h
//  WFConnector
//
//  Created by Chris Uroda on 2015-02-20.
//  Copyright (c) 2015 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WFConnector/WFSensorConnection.h>
#import <WFConnector/WFWahooGymConnectFitnessEquipmentData.h>
#import <WFConnector/WFWahooGymConnectEventsDelegate.h>
#import <WFConnector/WFWahooGymConnectControlEventsDelegate.h>
#import <WFConnector/WFWahooGymConnectUserData.h>
#import <WFConnector/WFWahooGymConnectUploadItem.h>

/**
 * Represents a connection to a Wahoo Gym Connect Service (implemented by a BLE device)
 */
@interface WFWahooGymConnectConnection : WFSensorConnection
{
	/** \cond InterfaceDocs */
    
    id<WFWahooGymConnectEventsDelegate> __weak _wahooGymConnectDelegate;
    id<WFWahooGymConnectControlEventsDelegate> __weak _wahooGymConnectControlDelegate;
    
	/** \endcond */
}



@property (nonatomic, weak) id<WFWahooGymConnectEventsDelegate> wahooGymConnectDelegate;
@property (nonatomic, weak) id<WFWahooGymConnectControlEventsDelegate> wahooGymConnectControlDelegate;


/**
 * Get the Fitness Equipment Type value that the sensor has reported.
 *
 * @return A WFWahooGymConnectFitnessEquipmentType_t value
 */
- (WFWahooGymConnectFitnessEquipmentType_t)getFitnessEquipmentType;


/**
 * Get the Fitness Equipment State information that the sensor has reported.
 *
 * @return A WFWahooGymConnectFitnessEquipmentStateInformation instance with the state information for the fitness equipment.
 */
- (WFWahooGymConnectFitnessEquipmentStateInformation*)getFitnessEquipmentState;


/**
 * Get the Fitness Equipment Workout Program Name that the sensor has reported.
 *
 * @return An NSString instance with the workout program name reported by the fitness equipment.
 */
- (NSString*)getFitnessEquipmentWorkoutProgramName;


/**
 * Returns the latest data available from the sensor.
 *
 * @see WFSensorConnection::getData
 *
 * @return A WFWahooGymConnectFitnessEquipmentData instance containing data if available,
 * otherwise <c>nil</c>.
 */
- (WFWahooGymConnectFitnessEquipmentData*)getFitnessEquipmentData;


/**
 * Send a Heart Rate measurment value to the Fitness Equipment.
 *
 * @param heartRateMeasurement The heart rate measurment value.
 *                             The units of the measurement are beats per minute (BPM).
 */
- (void)sendSensorMeasurementHeartRate:(uint16_t)heartRateMeasurement;


/**
 * Send a Cadence Measurment value to the Fitness Equipment.
 *
 * @param cadenceMeasurement The cadence measurment value.
 *                           The units of the measurement are units per minute - the units depend on the type of the
 *                           fitness equipment. For example, revolutions per minute (RPM) for a Bike, strides per minute
 *                           for a treadmill or cross trainer.
 */
- (void)sendSensorMeasurementCadence:(uint16_t)cadenceMeasurement;


/**
 * Fetch the workout summary data from the peripheral
 *
 * Will callback wahooGymConnectDelegate wahooGymConnect:didFetchFitnessEquipmentSummaryData:withError:
 */
- (void)fetchWorkoutSummaryData;


/**
 * Initiate fetching of supported upload item types from the Fitness Equipment.
 *
 * Will callback wahooGymConnectDelegate wahooGymConnect:didFetchSupportedUploadItemTypes:forVendor:withVendorSpecificInfoValues:withError:
 *
 */
- (void)beginSupportedUploadItemTypesFetching;


/**
 * Cancel fetching of supported upload item types from the Fitness Equipment.
 */
- (void)cancelSupportedUploadItemTypesFetching;


/**
 * Upload user data to the Fitness Equipment.
 *
 * Will callback wahooGymConnectDelegate wahooGymConnect:userData:uploadDidCompleteWithError:
 *
 * @param userData An instance of WFWahooGymConnectUserData containing the user data to upload.
 */
- (void)beginUserDataUpload:(WFWahooGymConnectUserData *)userData;


/**
 * Cancel upload of user data.
 */
- (void)cancelUserDataUpload;


/**
 * Upload an "upload item" (e.g. a workout program) for use with the fitness equipment.
 *
 * Will callback: 
 * wahooGymConnectDelegate wahooGymConnect:didProgressUploadOfItemWithProgressPercentage:
 * wahooGymConnectDelegate wahooGymConnect:didProgressUploadItemProcessingWithProgressPercentage:
 * wahooGymConnectDelegate wahooGymConnect:didCompleteUploadOfItem:withError:
 *
 * @param uploadItem An instance of WFWahooGymConnectUploadItem containing information about the data to upload.
 */
- (void)beginUploadOfItem:(WFWahooGymConnectUploadItem *)uploadItem;


/**
 * Cancel upload of "upload item"
 */
- (void)cancelUploadOfItem;


/**
 * Beging fetching of "upload item issues" reported by the device for the last successful upload of "upload item"
 *
 * Will callback:
 * wahooGymConnectDelegate wahooGymConnect:didProgressFetchingUploadItemIssuesWithNumIssuesFetched:
 * wahooGymConnectDelegate wahooGymConnect:didCompleteFetchingUploadItemIssues:withError:
 */
- (void)beginUploadItemIssuesFetching;


/**
 * Cancel fetching of "upload item issues"
 */
- (void)cancelUploadItemIssuesFetching;






/**
 * Beging fetching of "Supported Control Features" reported by the device
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didFetchFitnessEquipmentControlSupportedFeatures:withError:
 */
- (void)feControlFetchSupportedControlFeatures;


/**
 * Request the device to reset fitness equipment control settings
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didRequestFitnessEquipmentControlResetWithError:
 */
- (void)feControlRequestControlReset;


/**
 * Request the fitness equipment to start the workout
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didRequestFitnessEquipmentControlWorkoutStartWithError:
 */
- (void)feControlRequestWorkoutStart;


/**
 * Request the fitness equipment to pause the workout
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didRequestFitnessEquipmentControlWorkoutPauseWithError:
 */
- (void)feControlRequestWorkoutPause;

/**
 * Request the fitness equipment to resume the workout
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didRequestFitnessEquipmentControlWorkoutResumeWithError:
 */
- (void)feControlRequestWorkoutResume;

/**
 * Request the fitness equipment to finish the workout
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didRequestFitnessEquipmentControlWorkoutFinishWithError:
 */
- (void)feControlRequestWorkoutFinish;


/**
 * Request the fitness equipment to change the speed setting
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didRequestFitnessEquipmentControlSpeedSettingChangeWithError:
 *
 * @param speedKph The requested speed in kilometres per hour
 */
- (void)feControlRequestSpeedSettingChange:(double)speedKph;

/**
 * Fetch the current speed setting from the fitness equipment
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didFetchFitnessEquipmentControlCurrentSpeedSetting:withError:
 */
- (void)feControlFetchCurrentSpeedSetting;

/**
 * Fetch the speed setting limits from the fitness equipment
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didFetchFitnessEquipmentControlSpeedSettingLimitsMin:max:increment:error
 */
- (void)feControlFetchSupportedSpeedSettingLimits;


/**
 * Request the fitness equipment to change the incline (grade) setting
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didRequestFitnessEquipmentControlInclineSettingChangeWithError:
 *
 * @param inclinePercent The requested incline in per cent
 */
- (void)feControlRequestInclineSettingChange:(double)inclinePercent;

/**
 * Fetch the current incline setting from the fitness equipment
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didFetchFitnessEquipmentControlCurrentInclineSetting:withError:
 */
- (void)feControlFetchCurrentInclineSetting;

/**
 * Fetch the inline setting limits from the fitness equipment
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didFetchFitnessEquipmentControlInclineSettingLimitsMin:max:increment:error
 */
- (void)feControlFetchSupportedInclineSettingLimits;


/**
 * Request the fitness equipment to change the resistance level setting
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didRequestFitnessEquipmentControlResistanceLevelSettingChangeWithError:
 *
 * @param resistanceLevel The requested resistance level value
 */
- (void)feControlRequestResistanceLevelSettingChange:(double)resistanceLevel;

/**
 * Fetch the current resistance level setting from the fitness equipment
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didFetchFitnessEquipmentControlCurrentResistanceLevelSetting:withError:
 */
- (void)feControlFetchCurrentResistanceLevelSetting;

/**
 * Fetch the resistance level setting limits from the fitness equipment
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didFetchFitnessEquipmentControlResistanceLevelSettingLimitsMin:max:increment:error
 */
- (void)feControlFetchSupportedResistanceLevelSettingLimits;


/**
 * Request the fitness equipment to change the target power setting
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didRequestFitnessEquipmentControlTargetPowerSettingChangeWithError:
 *
 * @param targetPowerWatts The requested target power in Watts
 */
- (void)feControlRequestTargetPowerSettingChange:(double)targetPowerWatts;

/**
 * Fetch the current target power setting from the fitness equipment
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didFetchFitnessEquipmentControlCurrentTargetPowerSetting:withError:
 */
- (void)feControlFetchCurrentTargetPowerSetting;

/**
 * Fetch the target power setting limits from the fitness equipment
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didFetchFitnessEquipmentControlTargetPowerSettingLimitsMin:max:increment:error
 */
- (void)feControlFetchSupportedTargetPowerSettingLimits;


/**
 * Request the fitness equipment to change the target heart rate setting
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didRequestFitnessEquipmentControlTargetHeartRateSettingChangeWithError:
 *
 * @param targetHeartRate The requested target heart rate in Beats per minute
 */
- (void)feControlRequestTargetHeartRateSettingChange:(uint8_t)targetHeartRate;

/**
 * Fetch the current target heart rate setting from the fitness equipment
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didFetchFitnessEquipmentControlCurrentTargetHeartRateSetting:withError:
 */
- (void)feControlFetchCurrentTargetHeartRateSetting;

/**
 * Fetch the target heart rate setting limits from the fitness equipment
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didFetchFitnessEquipmentControlTargetHeartRateSettingLimitsMin:max:increment:error
 */
- (void)feControlFetchSupportedTargetHeartRateSettingLimits;


/**
 * Request the fitness equipment to change the indoor bike simulation constants
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didRequestFitnessEquipmentControlIndoorBikeSimulationConstantsChangeWithError:
 *
 * @param indoorBikeSimulationConstants The requested indoor bike simulation constants
 */
- (void)feControlRequestIndoorBikeSimulationConstantsChange:(WFWahooGymConnectFitnessEquipmentControlIndoorBikeSimulationConstants *)indoorBikeSimulationConstants;

/**
 * Fetch the current indoor bike simulation constants from the fitness equipment
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didFetchFitnessEquipmentControlCurrentIndoorBikeSimulationConstants:withError:
 */
- (void)feControlFetchCurrentIndoorBikeSimulationConstants;


/**
 * Request the fitness equipment to change the indoor bike simulation settings
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didRequestFitnessEquipmentControlIndoorBikeSimulationSettingsChangeWithError:
 *
 * @param indoorBikeSimulationSettings The requested indoor bike simulation settings
 */
- (void)feControlRequestIndoorBikeSimulationSettingsChange:(WFWahooGymConnectFitnessEquipmentControlIndoorBikeSimulationSettings *)indoorBikeSimulationSettings;

/**
 * Fetch the current indoor bike simulation settings from the fitness equipment
 *
 * Will callback:
 * wahooGymConnectControlDelegate wahooGymConnect:didFetchFitnessEquipmentControlCurrentIndoorBikeSimulationSettings:withError:
 */
- (void)feControlFetchCurrentIndoorBikeSimulationSettings;



@end


