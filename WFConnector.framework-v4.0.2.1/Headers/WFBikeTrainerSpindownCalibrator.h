//
//  WFBikeTrainerSpindownCalibrator.h
//  WFConnector
//
//  Created by Mark Snaterse on 01/08/15.
//  Copyright (c) 2015 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WFConnector/WFBikePowerConnection.h>
#import <WFConnector/WFBikeTrainerSpindownCalibratorResult.h>

@protocol WFBikeTrainerSpindownCalibratorDelegate;


typedef NS_ENUM(NSInteger, WFBikeTrainerSpindownCalibratorState_t)
{
    WF_BIKE_TRAINER_SPINDOWN_CALIBRATOR_STATE_IDLE,
    WF_BIKE_TRAINER_SPINDOWN_CALIBRATOR_STATE_WARMING_UP,
    WF_BIKE_TRAINER_SPINDOWN_CALIBRATOR_STATE_WAITING_FOR_TARGET_SPEED,
    WF_BIKE_TRAINER_SPINDOWN_CALIBRATOR_STATE_SPINDOWN_IN_PROGRESS,
    WF_BIKE_TRAINER_SPINDOWN_CALIBRATOR_STATE_UPLOADING,
    WF_BIKE_TRAINER_SPINDOWN_CALIBRATOR_STATE_COMPLETED,
    WF_BIKE_TRAINER_SPINDOWN_CALIBRATOR_STATE_FAILED,
};


typedef NS_ENUM(NSInteger, WFBikeTrainerSpindownCalibratorWorkingStatus_t)
{
    WF_BIKE_TRAINER_SPINDOWN_CALIBRATOR_WORKING_STATUS_NOT_AVAILABLE,
    WF_BIKE_TRAINER_SPINDOWN_CALIBRATOR_WORKING_STATUS_WAITING_FOR_DEVICE,
    WF_BIKE_TRAINER_SPINDOWN_CALIBRATOR_WORKING_STATUS_DEVICE_INTERRUPTION,
    WF_BIKE_TRAINER_SPINDOWN_CALIBRATOR_WORKING_STATUS_IN_PROGRESS,
    WF_BIKE_TRAINER_SPINDOWN_CALIBRATOR_WORKING_STATUS_PROCESSING,
};



/**
 * Error domain for WFBikeTrainerSpindownCalibrator errors
 */
extern NSString* const WFBikeTrainerSpindownCalibratorErrorDomain;

typedef NS_ENUM(NSUInteger, WBikeTrainerSpindownCalibratorError)
{
    WFBikeTrainerCalibratorErrorNone = 0,                       /**< No error has occured. */
    WFBikeTrainerCalibratorErrorUnknown,                        /**< An unknown error occured. */
    WFBikeTrainerCalibratorErrorOperationNotPermitted,          /**< The operation is not permitted in the current calibrator state. */
    WFBikeTrainerCalibratorErrorInvalidParameter,               /**< A supplied parameter is invalid. */
    WFBikeTrainerCalibratorErrorDeviceTimeout,                  /**< The device for calibration (sensor connection) has timed out. */
    WFBikeTrainerCalibratorDeviceError,                         /**< The device responded with an unexpected error. */
    WFBikeTrainerCalibratorDeviceErrorOpcodeNotSupported,       /**< The device does not support a required command. */
    WFBikeTrainerCalibratorErrorDataSourceError,                /**< Required data could not be obtained. */
    WFBikeTrainerCalibratorErrorCalibrationTimeout,             /**< The calibration has timed out. */
    WFBikeTrainerCalibratorErrorUserError,                      /**< The user did display unexpected behavior. */
    WFBikeTrainerCalibratorErrorUnableToResolveCalibration,     /**< No calibration profile could be resolved for the data */
};




@interface WFBikeTrainerSpindownCalibrator : NSObject

/**
 * The Bike Power Connection which is being used to perform the calibration.
 */
@property (nonatomic, readonly) WFBikePowerConnection *bikePowerConnection;



/**
 * The current state of this calibrator instance
 */
@property (nonatomic, readonly) WFBikeTrainerSpindownCalibratorState_t state;


/**
 * The current working status of this calibrator instance. This is only valid when the current state is WF_WAHOO_MOTION_ANALYSIS_CALIBRATOR_STATE_WORKING.
 */
@property (nonatomic, readonly) WFBikeTrainerSpindownCalibratorWorkingStatus_t workingStatus;



/**
 * The result of the calibration. This is only valid when the current state is WF_BIKE_TRAINER_SPINDOWN_CALIBRATOR_STATE_COMPLETED.
 */
@property (nonatomic, readonly) WFBikeTrainerSpindownCalibratorResult *calibrationResult;


/**
 * The delegate which will receive event/progress update callbacks
 */
@property (nonatomic, assign) id <WFBikeTrainerSpindownCalibratorDelegate> delegate;


/**
 * The speed required to trigger a spindown, in meters per second. Instruct the user to slowly increase their speed untill they reach this threshold.*
 */
@property (nonatomic, readonly) double spindownThresholdSpeed;


/**
 * The designated initialiser
 */
- (instancetype)initWithBikePowerConnection:(WFBikePowerConnection *)bikePowerConnection;


 /**
 * Initiates the trainer for a system drag spindown test.
 * 
 * A system drag spindown test is used to calibrate the trainer and determine power loss due to friction.
 * When this function is called successfully, the trainer is set to Resistance Mode at 0.0% brake.
 * A spindown requires the rider to pedal to speeds above 22 mph and let the bike coast down to less
 * than 13 mph.
 * @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>.
 */
- (BOOL)startSystemDragSpindown;


/**
 * Initiates the trainer for a brake strength spindown test
 *
 * A brake strength spindown test is used to calibrate the brake strength.
 * A brake strength spindown consists of three phases: a warmup, followed by two spindown tests
 * During the warmup the rider is required to pedal at a comfortable speed. Each spindown test 
 * requires the rider to pedal to speeds above 22 mph and let the bike coast down to less than
 * 13 mph.
 * @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>.
 */
- (BOOL)startBrakeStrengthSpindown;


/**
 * Resets the brake strength value to the default value
 */
- (BOOL)resetBrakeStrengthSpindownToDefault;


/**
 * Abort the spindown process
 * @return <c>false</c> if an error occurred
 */
- (void)abortSpindown;


@end
