//
//  WFWahooMotionAnalysisRunningCalibrator.h
//  WFConnector
//
//  Created by Chris Uroda on 06/11/2014.
//  Copyright (c) 2014 Wahoo Fitness. All rights reserved.
//

#import "WFWahooMotionAnalysisCalibrator.h"
#import "WFWahooMotionAnalysisCalibrationProfileRunning.h"

@class WFCalibrationPhase;




typedef NS_ENUM(NSInteger,WFMotionAnalysisRunningCalibratorActivity_t)
{
    WF_MOTION_ANALYSIS_RUNNING_CALIBRATOR_ACTIVITY_RUNNING = 0,
    WF_MOTION_ANALYSIS_RUNNING_CALIBRATOR_ACTIVITY_WALKING = 1
};



typedef NS_ENUM(NSInteger,WFMotionAnalysisRunningCalibrationGender_t)
{
    WF_MOTION_ANALYSIS_RUNNING_CALIBRATOR_GENDER_UNKNOWN    = 0,
    WF_MOTION_ANALYSIS_RUNNING_CALIBRATOR_GENDER_MALE       = 1,
    WF_MOTION_ANALYSIS_RUNNING_CALIBRATOR_GENDER_FEMALE     = 2
};



@interface WFWahooMotionAnalysisCalibratorRunning : WFWahooMotionAnalysisCalibrator

/**
 * The <b>Regular</b> calibration process requires the user
 * to walk or run at a single speed for two minutes (single phase).
 *
 * The <b>Extended</b> calibration requires the user to run at three
 * different speeds for two minutes each (three phases). For the best
 * result the speeds should be as distinct as possible. The resulting
 * speed estimate can be more accurate than the result from the 
 * the regular calibration process.
 *
 * The extended calibration is only supported for running calibration,
 * not for walking calibration
 */
@property (assign, nonatomic) bool extendedCalibrationEnabled;


/**
 * If the users gender is known it will be used to improve the calibration
 */
@property (assign, nonatomic) WFMotionAnalysisRunningCalibrationGender_t gender;



/**
 * If the users stature (height) is known it will be used to improve the calibration
 * Units are in centimeters
 */
@property (assign, nonatomic) double stature;



/**
 * Setter for average speed during current calibration phase.
 * If speed is required to continue the calibration process
 * the delegate method wahooMotionAnalysisCalibrator:doesRequireSpeedToContinue:
 * is called. Respond to the delegate call using this setter to continue.
 */
@property (assign, nonatomic) NSNumber *averageSpeedForCurrentPhase;



/**
 * The number of calibration phases.  
 */
@property (assign, nonatomic, readonly) int numberOfPhases;


/**
 * The current calibration phase
 */
@property (assign, nonatomic, readonly) int currentPhase;


/**
 * The time remaining in the current calibration phase
 */
@property (assign, nonatomic, readonly) NSTimeInterval remainingTimeInPhase;



/**
 * The designated initialiser 
 *
 * @param activity Running or walking
 *
 */
- (instancetype)initForActivity:(WFMotionAnalysisRunningCalibratorActivity_t)activity withSensorConnection:(WFSensorConnection *)sensorConnection;


/**
 * Upload default calibration profile for users gender and stature
 * @param activity The activity to upload the default calibration for (walking or running).
 * @param gender   Use WF_MOTION_ANALYSIS_RUNNING_CALIBRATOR_GENDER_UNKNOWN if not known.
 * @param stature  Users stature (height) in centimeter. Use nil if unkown.
 * @return <c>false</c> if an error occurred
 */
- (bool)uploadDefaultCalibrationProfileForActivity:(WFMotionAnalysisRunningCalibratorActivity_t)activity
                                            gender:(WFMotionAnalysisRunningCalibrationGender_t)gender
                                        andStature:(NSNumber *)stature;


/**
 * Resets the current calibration phase and puts the calibration process in a paused state.
 * Call continueCalibration: to continue the calibration process.
 */
- (void)resetCurrentPhase;


@end




/**
 * Extended calibrator delegate protocol for Running
 */

@protocol WFWahooMotionAnalysisCalibratorRunningDelegate <WFWahooMotionAnalysisCalibratorDelegate>

/**
 * Invoked when speed is required to continue the calibration process.
 * Use the property averageSpeedForCurrentPhase to (asynchronously) return the requested speed.
 */
- (void) wahooMotionAnalysisCalibrator:(WFWahooMotionAnalysisCalibrator *)calibrator doesRequireSpeedToContinue:(bool)reserved;

@end

