//
//  WFWahooMotionAnalysisXCountingCalibrator.h
//  WFConnector
//
//  Created by Mark Snaterse on 2014-11-12.
//  Copyright (c) 2014 Wahoo Fitness. All rights reserved.
//

#import "WFWahooMotionAnalysisCalibrator.h"
#import "WFWahooMotionAnalysisCalibrationProfileXCounting.h"



@class WFWahooMotionAnalysisCalibrationProfileXCounting;


@interface WFWahooMotionAnalysisCalibratorXCounting : WFWahooMotionAnalysisCalibrator



/**
 * The number of repetitions performed by the user during the calibration process.
 * If this value is required to continue the calibration process
 * the delegate method wahooMotionAnalysisCalibrator:doesRequireNumberOfRepetitionsToContinue:
 * is called. Respond to the delegate call using this setter to continue.
 */
@property (retain, nonatomic) NSNumber *numberOfRepetitionsPerformed;



//
/**
 * Begin the calibration process for a new exercise
 * @return <c>false</c> if an error occurred
 */
- (bool)beginCalibrationForNewExercise;



//
/**
 * Begin the calibration process for an existing exercise
 * @param current calibration profile for exercise
 * @return <c>false</c> if an error occurred
 */
- (bool)beginCalibrationForExistingExercise:(WFWahooMotionAnalysisCalibrationProfileXCounting *)currentCalibrationProfile;

@end




/**
 * Extended calibrator delegate protocol for XCounting
 */
@protocol WFWahooMotionAnalysisCalibratorXCountingDelegate <WFWahooMotionAnalysisCalibratorDelegate>

/**
 * Invoked when the number of repetitions performed by the user is required to continue the calibration process.
 * Use the property numberOfRepetitionsPerformed to (asynchronously) return the requested number of repetitions.
 */
- (void)wahooMotionAnalysisCalibrator:(WFWahooMotionAnalysisCalibrator *)calibrator doesRequireNumberOfRepetitionsToContinue:(bool)reserved;


@end