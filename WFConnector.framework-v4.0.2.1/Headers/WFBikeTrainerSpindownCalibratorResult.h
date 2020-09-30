//
//  WFBikeTrainerSpindownCalibratorResult.h
//  WFConnector
//
//  Created by Mark Snaterse on 10/08/15.
//  Copyright © 2015 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface WFBikeTrainerSpindownCalibratorResult : NSObject

@property (nonatomic, assign) double spindownTime;
@property (nonatomic, assign) double spindownTemperature;
@property (nonatomic, assign) double spindownOffset;

@end


