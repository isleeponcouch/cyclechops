//
//  WFWahooHeadwindControlDelegate.h
//  WFConnector
//
//  Created by Patrick Bush on 5/18/18.
//  Copyright © 2018 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WFWahooControlPointDelegateInfo.h"
#import "wf_wahoo_headwind_types.h"
#import "WFHeadwindConfigData.h"
#import "WFHeadwindStateData.h"

@protocol WFWahooHeadwindControlDelegate <NSObject>


/**
 Invoked when a response to the did set speed setting command is received

 @param sender the WFWahooHeadwindConnection instance
 @param speed the new speed in % (0 - 100)
 @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooHeadwindControl:(id)sender didSetSpeed:(int)speed withInfo:(WFWahooControlPointDelegateInfo *)info;


/**
 Invoked when a response to the did set operating mode setting command is received

 @param sender the WFWahooHeadwindConnection instance
 @param mode the new operating mode (HeadwindOperatingMode_e)
 @param info Structure containing info regarding the control point command
 */
- (void)wahooHeadwindControl:(id)sender didSetOperatingMode:(WFHeadwindOperatingMode_e)mode withInfo:(WFWahooControlPointDelegateInfo *)info;

/**
 Inboked when a response to the get speed setting command is received

 @param sender the WFWahooHeadwindConnection instance
 @param value the new speed value in % (0 - 100)
 @param info Structure containing info regarding the control point command
 */
- (void)wahooHeadwindControl:(id)sender didGetSpeedSetting:(int)value withInfo:(WFWahooControlPointDelegateInfo *)info;

/**
 Invoked when a response to the get operating mode command is received

 @param sender the WFWahooHeadwindConnection instance
 @param mode the new operating mode (HeadwindOperatingMode_e)
 @param info Structure containing info regarding the control point command
 */
- (void)wahooHeadwindControl:(id)sender didGetOperatingMode:(WFHeadwindOperatingMode_e)mode withInfo:(WFWahooControlPointDelegateInfo *)info;

/**
 Invoked when a state change event is received
 
 @param sender the WFWahooHeadwindConnection instance
 @param data the object with the new speed/state info
 */
- (void)wahooHeadwindControl:(id)sender didSendStateChangeEvent:(WFHeadwindStateData *)data;

/**
 Invoked when a response to the get config settings event is receievd

 @param sender the WFWahooHeadwindConnection instance
 @param settings the new sensor settings
 @param info Struct containing info regarding the control point command
 */
- (void)wahooHeadwindControl:(id)sender didGetConfigSettings:(WFHeadwindConfigData *)settings withInfo:(WFWahooControlPointDelegateInfo *)info;

/**
 Invoked when a reponse to the set config settings is received

 @param sender the WFWahooHeadwindConnection instance
 @param settings the new sensor settings
 @param info Struct containing info regarding the control point command
 */
- (void)wahooHeadwindControl:(id)sender didSetConfigSettings:(WFHeadwindConfigData *)settings withInfo:(WFWahooControlPointDelegateInfo *)info;

/**
 Invoked when a reponse to the reset command is received
 
 @param sender the WFWahooHeadwindConnection instance
 @param reset whether the command was successful
 */
- (void)wahooHeadwindControl:(id)sender didReset:(BOOL)reset;


@end
