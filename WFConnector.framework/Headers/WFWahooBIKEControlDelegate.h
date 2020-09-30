//
//  WFWahooBIKEControlDelegate.h
//  WFConnector
//
//  Created by Garrett Franks on 5/14/19.
//  Copyright © 2019 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WFWahooControlPointDelegateInfo.h"
#import "WFBIKEStateData.h"

@protocol WFWahooBIKEControlDelegate <NSObject>


/**
 Invoked when a response to the did set shifter type command is received
 
 @param sender the WFWahooBIKEConnection instance
 @param shifterType the new shifterType in % (1 - 5)
 @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooBIKEControl:(nonnull id)sender didSetShifterType:(WFBIKEShifterType_e)shifterType withInfo:(nullable WFWahooControlPointDelegateInfo *)info;

/**
 Invoked when a response to the did set chainring setting command is received
 
 @param sender the WFWahooBIKEConnection instance
 @param chainRingSetting the new chainringSetting in % (1 - 3)
 @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooBIKEControl:(nonnull id)sender didSetChainringSetting:(nullable WFBIKEChainringData*)chainringSetting withInfo:(nullable WFWahooControlPointDelegateInfo *)info;

/**
 Invoked when a response to the did set cassette setting command is received
 
 @param sender the WFWahooBIKEConnection instance
 @param cassetteSetting the new cassetteSetting in % (1 - 13)
 @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooBIKEControl:(nonnull id)sender didSetCassetteSetting:(nullable WFBIKECassetteData*)cassetteSetting withInfo:(nullable WFWahooControlPointDelegateInfo *)info;

/**
 Invoked when a response to the did set brake location command is received
 
 @param sender the WFWahooBIKEConnection instance
 @param brakeLocation the new brake location in % (0 or 1)
 @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooBIKEControl:(nonnull id)sender didSetBrakeLocation:(WFBIKEBrakeLocation_e)brakeLocation withInfo:(nullable WFWahooControlPointDelegateInfo *)info;


/**
 Inboked when a response to the get shifter type command is received
 
 @param sender the WFWahooBIKEConnection instance
 @param value the new shifter type value in % (1 - 5)
 @param info Structure containing info regarding the control point command
 */
- (void)wahooBIKEControl:(nonnull id)sender didGetShifterType:(WFBIKEShifterType_e)value withInfo:(nullable WFWahooControlPointDelegateInfo *)info;

/**
 Inboked when a response to the get chainring setting command is received
 
 @param sender the WFWahooBIKEConnection instance
 @param value the new chainring setting value in % (1 - 3)
 @param info Structure containing info regarding the control point command
 */
- (void)wahooBIKEControl:(nonnull id)sender didGetChainringSetting:(nullable WFBIKEChainringData*)value withInfo:(nullable WFWahooControlPointDelegateInfo *)info;

/**
 Inboked when a response to the get cassette setting command is received
 
 @param sender the WFWahooBIKEConnection instance
 @param value the new cassette setting value in % (1 - 13)
 @param info Structure containing info regarding the control point command
 */
- (void)wahooBIKEControl:(nonnull id)sender didGetCassetteSetting:(nullable WFBIKECassetteData*)value withInfo:(nullable WFWahooControlPointDelegateInfo *)info;

/**
 Inboked when a response to the get brake location command is received
 
 @param sender the WFWahooBIKEConnection instance
 @param value the new brake location value in % (0 or 1)
 @param info Structure containing info regarding the control point command
 */
- (void)wahooBIKEControl:(nonnull id)sender didGetBrakeLocation:(WFBIKEBrakeLocation_e)value withInfo:(nullable WFWahooControlPointDelegateInfo *)info;

/**
 Invoked when a state change event is received
 
 @param sender the WFWahooBIKEConnection instance
 @param data the object with the new shifter/chainring/cassette/brake/state info
 */
- (void)wahooBIKEControl:(nonnull id)sender didSendStateChangeEvent:(nullable WFBIKEStateData *)data;

/**
 Invoked when a response to the get system health check command is received
 @param sender the WFWahooBIKEConnection instance
 @param data the updated system health check object
 @param info Structure containing info regarding the control point command
 */
- (void)wahooBIKEControl:(nonnull id)sender didGetHealthCheckData:(nullable WFBIKESystemHealthCheckData *)data withInfo:(nullable WFWahooControlPointDelegateInfo *)info;

/**
 Invoked when a system health check state change is received
 @param sender the WFWahooBIKEConnection
 @param data the object with the new system health check data in it
 */
- (void)wahooBIKEControl:(nonnull id)sender didSendHealthCheckStateChangeEvent:(nullable WFBIKESystemHealthCheckData *)data;
@end
