//
//  WFWahooBIKEConnection.h
//  WFConnector
//
//  Created by Garrett Franks on 5/14/19.
//  Copyright © 2019 Wahoo Fitness. All rights reserved.
//

#import "WFSensorConnection.h"
#import "WFWahooBIKEControlDelegate.h"


@interface WFWahooBIKEConnection : WFSensorConnection


/**
 Specifies the WFWahooBIKEControlDelegate instance which will handle callback
 methods for this WFWahooBIKEConnection.
 */
@property (nonatomic, weak, nullable) id<WFWahooBIKEControlDelegate>bikeConnectionDelegate;

/**
 *************************************************************************************************+
 *                                                                                               *
 * Wahoo BIKE Control                                                                        *
 *                                                                                               *
 * Responses to the Wahoo BIKE commands and change events                                    *
 * are delivered to the WFWahooBIKEControlDelegate.                                          *
 *************************************************************************************************+
 */


/**
 Sends request to set the shifter type value
 
 @param newShifterType the new shifterType in % (1 - 5)
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)setShifterType:(WFBIKEShifterType_e)newShifterType withBrakeLocation:(WFBIKEBrakeLocation_e)brakeLocation;

/**
 Sends request to set the shifter type and chainring setting value
 
 @param newShifterType the new shifterType in % (1 - 5)
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)setShifterType:(WFBIKEShifterType_e)newShifterType withChainringSetting:(nonnull WFBIKEChainringData*)newChainringSetting withBrakeLocation:(WFBIKEBrakeLocation_e)brakeLocation;

/**
 Sends request to get the current shifter type
 
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)getShifterType;

/**
 Sends request to set the chainring settings value
 
 @param newChainringSetting the new chainringSetting in % (1 - 3)
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)setChainringSetting:(nonnull WFBIKEChainringData*)newChainringSetting withShifterType:(WFBIKEShifterType_e)shifterType withBrakeLocation:(WFBIKEBrakeLocation_e)brakeLocation;

/**
 Sends request to get the current chainring setting
 
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)getChainringSetting;

/**
 Sends request to set the speed value
 
 @param newCassetteSetting the new cassetteSetting in % (1 - 13)
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)setCassetteSetting:(nonnull WFBIKECassetteData*)newCassetteSetting withBrakeLocation:(WFBIKEBrakeLocation_e)brakeLocation;

/**
 Sends request to get the current cassette setting
 
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)getCassetteSetting;

/**
 Sends request to set the brake location
 
 @param newBrakeLocation the new brake location in % (0 or 1)
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)setBrakeLocation:(WFBIKEBrakeLocation_e)newBrakeLocation;

/**
 Sends request to get the current brake location
 
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)getBrakeLocation;

/**
 Sends request to get the current system health check data
 
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>
 */
- (BOOL)getSystemHealthCheckData;
@end
