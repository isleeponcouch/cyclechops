//
//  WFWahooMotionAnalyisCalibratorElliptical.h
//  WFConnector
//
//  Created by Mark Snaterse on 04/03/15.
//  Copyright (c) 2015 Wahoo Fitness. All rights reserved.
//

#import "WFWahooMotionAnalysisCalibrator.h"

@interface WFWahooMotionAnalysisCalibratorElliptical : WFWahooMotionAnalysisCalibrator



/**
 * Begin calibration. If the calibration succeeds the new calibration profile will
 * be uploaded to the device.
 *
 * @param distance  distance in meters
 * @param stepcount number of steps used to cover distance
 *
 * @see WFWahooMotionAnalysisCalibratorDelegate for status callbacks
 *
 */
- (bool) beginCalibrationWithStepcount:(int)stepcount andDistance:(float)distance;

@end
