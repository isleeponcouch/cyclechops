//
//  WFHeadwindStateData.h
//  WFConnector
//
//  Created by Patrick Bush on 6/27/18.
//  Copyright © 2018 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "wf_wahoo_headwind_types.h"

@interface WFHeadwindStateData : NSObject

/// the current speed
@property (nonatomic, assign) u_int8_t currentSpeed;

/// the current operating mode
@property (nonatomic, assign) WFHeadwindOperatingMode_e currentMode;

+ (instancetype)headwindStateWithData:(NSData *)data;

@end

