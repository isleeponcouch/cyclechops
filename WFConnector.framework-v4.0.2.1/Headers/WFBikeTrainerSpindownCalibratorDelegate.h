//
//  WFBikeTrainerSpindownCalibratorDelegate.h
//  WFConnector
//
//  Created by Mark Snaterse on 01/08/15.
//  Copyright (c) 2015 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WFBikeTrainerSpindownCalibrator.h"
#import "WFBikeTrainerSpindownCalibratorResult.h"

@protocol WFBikeTrainerSpindownCalibratorDelegate <NSObject>

@optional

- (void)bikeTrainerSpindownCalibrator:(WFBikeTrainerSpindownCalibrator *)calibrator didChangeState:(WFBikeTrainerSpindownCalibratorState_t)state;

- (void)bikeTrainerSpindownCalibrator:(WFBikeTrainerSpindownCalibrator *)calibrator didChangeWorkingStatus:(WFBikeTrainerSpindownCalibratorWorkingStatus_t)workingStatus;

- (void)bikeTrainerSpindownCalibrator:(WFBikeTrainerSpindownCalibrator *)calibrator didBeginSpindownCalibrationWithError:(NSError *)error;

- (void)bikeTrainerSpindownCalibrator:(WFBikeTrainerSpindownCalibrator *)calibrator didFailSpindownCalibrationWithError:(NSError *)error;

- (void)bikeTrainerSpindownCalibrator:(WFBikeTrainerSpindownCalibrator *)calibrator didFinishSpindownCalibrationWithResult:(WFBikeTrainerSpindownCalibratorResult *)result error:(NSError *)error;

@end
