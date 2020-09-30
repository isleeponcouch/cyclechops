//
//  WFWahooAdvancedFitnessEquipmentControlConnection.h
//  WFConnector
//
//  Created by Mark Snaterse on 07/12/17.
//  Copyright © 2017 Wahoo Fitness. All rights reserved.
//

#import "WFSensorConnection.h"
#import "WFWahooAdvancedFitnessEquipmentControlDelegate.h"


/**
 * Represents a connection to a Advanced Fitness Equipment Control sensor.
 */
@interface WFWahooAdvancedFitnessEquipmentControlConnection : WFSensorConnection


/**
 * Specifies the WFWahooAdvancedFitnessEquipmentControlDelegate instance which will handle callback
 * methods for this WFWahooAdvancedFitnessEquipmentControlConnection.
 */
@property (nonatomic, weak) id<WFWahooAdvancedFitnessEquipmentControlDelegate> advancedFitnessEquipmentControlDelegate;



/**
 *************************************************************************************************+
 *                                                                                               *
 * Advanced Fitness Equipment Control                                                            *
 *                                                                                               *
 * Responses to the Advanced Fitness Equipment commands and change events                        *
 * are delivered to the WFWahooAdvancedFitnessEquipmentControlDelegate.                          *
 *************************************************************************************************+
 */


/**
 * Determines if the trainer supports Advanced Fitness Equipment Control.
 *
 * If the trainer does not support Advanced Fitness Equipment Control all other commands will return FALSE.
 *
 * @return <c>TRUE</c> if the trainer supports Advanced Fitness Equipment Control, otherwise <c>FALSE</c>.
 */
- (BOOL)trainerSupportsAdvancedFitnessEquipmentControl;


/**
 * Sends request to set the hub height.
 *
 * For trainers supporting variable hub height configuring hub height is required
 * to guarantee accurate tilt angles.
 *
 * @param hubHeightM Height of the hub in meters
 *
 * @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>.
 */
- (BOOL)setHubHeight:(double)hubHeightM;


/**
 * Sends request to set the wheel base.
 *
 * For trainers supporting variable wheel base configuring wheel base is required
 * to guarantee accurate tilt angles.
 *
 * @param wheelBaseM Wheel base in meters
 *
 * @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>.
 */
- (BOOL)setWheelBase:(double)wheelBaseM;


/**
 * Sends request to set the target tilt.
 *
 * Setting target tilt is only accepted when the tilt mode is UNLOCKED
 *
 * @param targetTiltPct Target tilt in percent
 *
 * @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>.
 */
- (BOOL)setTargetTilt:(double)targetTiltPct;


/**
 * Sends request to get currently configured hub height.
 *
 * @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>.
 */
- (BOOL)getHubHeight;

/**
 * Sends request to get currently configured wheel base.
 *
 * @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>.
 */
- (BOOL)getWheelBase;


/**
 * Sends request to get current tilt mode.
 *
 * @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>.
 */
- (BOOL)getTiltMode;


/**
 * Sends request to get current target tilt.
 *
 * @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>.
 */
- (BOOL)getTargetTilt;


/**
 * Sends request to get current tilt.
 *
 * @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>.
 */
- (BOOL)getCurrentTilt;


/**
 * Sends request to get tilt limits for current configuration
 *
 * @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>.
 *
 * Note: the response to the getTiltLimits command may take as long as 10 seconds
 */
- (BOOL)getTiltLimits;

/**
 Sends request to get the zero tilt offset for current configuration
 
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>.

 */
- (BOOL)getZeroTiltOffset;

/**
 Sends request to set the zero tilt offset

 @param offset the new tilt offset to set
 @return <c>TRUE</c> if the command was sent successfully, otherwise <c>FALSE</c>.
 */
- (BOOL)setZeroTiltOffset:(double)offset;


@end
