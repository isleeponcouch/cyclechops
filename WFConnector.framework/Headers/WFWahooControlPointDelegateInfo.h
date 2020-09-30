//
//  WFWahooControlPointDelegateInfo.h
//  WFConnector
//
//  Created by Mark Snaterse on 14/01/2018.
//  Copyright © 2018 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "hardware_connector_types.h"

/**
 *
 * Structure containing information regarding the control point command
 * error = the error
 * responseOrigin Indicates if the response is to an ANT or BlE command, or an echoed BLE response to an ANT command
 */

@interface WFWahooControlPointDelegateInfo : NSObject

@property (nonatomic, strong) NSError *error;
@property (nonatomic, assign) wf_cp_response_origin_t responseOrigin;

+ (instancetype)infoWithError:(NSError *)error andResponseOrigin:(wf_cp_response_origin_t) responseOrigin;

@end
