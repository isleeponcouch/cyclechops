//
//  WFWahooHeadwindConnection.h
//  WFConnector
//
//  Created by Patrick Bush on 5/17/18.
//  Copyright © 2018 Wahoo Fitness. All rights reserved.
//

#import "WFSensorConnection.h"
#import "WFWahooHeadwindControlDelegate.h"


@interface WFWahooHeadwindConnection : WFSensorConnection


/**
 Specifies the WFWahooHeadwindControlDelegate instance which will handle callback
 methods for this WFWahooHeadwindConnection.
 */
@property (nonatomic, weak) id<WFWahooHeadwindControlDelegate>headwindConnectionDelegate;

/**
 *************************************************************************************************+
 *                                                                                               *
 * Wahoo Headwind Control                                                                        *
 *                                                                                               *
 * Responses to the Wahoo Headwind commands and change events                                    *
 * are delivered to the WFWahooHeadwindControlDelegate.                                          *
 *************************************************************************************************+
 */


/**
 Sends request to set the speed value

 @param newSpeed fan speed value in % (0 - 100)
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)setSpeedSetting:(int)newSpeed;

/**
 Sends request to set the new operating mode

 @param newMode the new operating mode
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)setOperatingMode:(WFHeadwindOperatingMode_e)newMode;

/**
 Sends request to get the current speed setting

 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)getSpeedSetting;

/**
 Sends request to get the current operating mode

 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)getOperatingMode;

/**
 Sends request to set the new config settings
 
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)setNewConfig:(WFHeadwindConfigData *)config;

/**
 Sends request to get the current config settings
 
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)getConfigSetting;

/**
 Sends request to reset NVM
 
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */

- (BOOL)resetNVM;

@end
