//
//  WFHeadwindConfigData.h
//  WFConnector
//
//  Created by Antony Gardiner on 20/06/18.
//  Copyright © 2018 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WFHeadwindConfigData : NSObject

/// threshold between hrz 1,2
@property (nonatomic, assign) u_int8_t hrThresholdOne;

/// threshold between hrz 2,3
@property (nonatomic, assign) u_int8_t hrThresholdTwo;

/// threshold between hrz 3,4
@property (nonatomic, assign) u_int8_t hrThresholdThree;

/// threshold between hrz 4, 5
@property (nonatomic, assign) u_int8_t hrThresholdFour;

/// Minimum speed to set fan. Defines the lower limit for all values less thandefaultHeadwindConfig Min
@property (nonatomic, assign) u_int16_t speedSensorMin;

/// Maximum speed to set fan. Defines the upper limit for all values greater than Max
@property (nonatomic, assign) u_int16_t speedSensorMax;

+ (instancetype)headwindConfigWithData:(NSData *)data;


/**
 Creates a default headwind config.
 hrThresholdOne = 115
 hrThresholdTwo = 133
 hrThresholdThree = 152
 hrThresholdFour = 170
 speedSensorMin = 2235
 speedSensorMax = 11176

 @return an instance init with defaults.
 */
+ (instancetype)headwindConfigDefault;

- (instancetype)initWithData:(NSData *)data;

- (instancetype)initWithThresholdOne:(u_int8_t)thresholdOne
						thresholdTwo:(u_int8_t)thresholdTwo
					  thresholdThree:(u_int8_t)thresholdThree
					   thresholdFour:(u_int8_t)thresholdFour
					  speedSensorMin:(u_int16_t)speedSensorMin
					  speedSensorMax:(u_int16_t)speedSensorMax;


- (NSData *)dataConfig;

@end





