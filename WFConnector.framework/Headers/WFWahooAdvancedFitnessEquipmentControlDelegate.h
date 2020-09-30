//
//  WFWahooAdvancedFitnessEquipmentControlDelegate
//  WFConnector
//
//  Created by Mark Snaterse on 24/07/17.
//  Copyright © 2017 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WFWahooControlPointDelegateInfo.h"
#import "wf_wahoo_advanced_fitness_equipment_control_types.h"

/**
 * Provides the interface for Advanced Trainer Control callback methods used by the WFBikePowerConnection.
 */
@protocol WFWahooAdvancedFitnessEquipmentControlDelegate <NSObject>


/**
 * Invoked when a response to the Did Set Hub Height command is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param hubHeightM The new hub height in meters.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didSetHubHeight:(double)hubHeightM withInfo:(WFWahooControlPointDelegateInfo *)info;


/**
 * Invoked when a response to the Did Get Hub Height command is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param hubHeightM The currently configured hub height in meters.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didGetHubHeight:(double)hubHeightM withInfo:(WFWahooControlPointDelegateInfo *)info;


/**
 * Invoked when a Hub Height change event is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param hubHeightM The new hub height in meters.
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didSendHubHeightChangeEvent:(double)hubHeightM;


/**
 * Invoked when a response to the Set Wheel Base command is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param wheelBaseM The new wheel base in meters.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didSetWheelBase:(double)wheelBaseM withInfo:(WFWahooControlPointDelegateInfo *)info;


/**
 * Invoked when a response to the Get Wheel Base command is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param wheelBaseM The currently configured wheel base in meters.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didGetWheelBase:(double)wheelBaseM withInfo:(WFWahooControlPointDelegateInfo *)info;


/**
 * Invoked when a Wheel Base change event is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param wheelBaseM The new wheel base in meters.
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didSendWheelBaseChangeEvent:(double)wheelBaseM;


/**
 * Invoked when a response to the Set Target Tilt command is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param targetTiltPct The new target tilt in percent.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didSetTargetTilt:(double)targetTiltPct withInfo:(WFWahooControlPointDelegateInfo *)info;


/**
 * Invoked when a response to the Get Target Tilt command is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param targetTiltPct The current target tilt (percent) in effect.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didGetTargetTilt:(double)targetTiltPct withInfo:(WFWahooControlPointDelegateInfo *)info;


/**
 * Invoked when a Target Tilt change event is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param targetTiltPct The new target tilt in percent.
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didSendTargetTiltChangeEvent:(double)targetTiltPct;


/**
 * Invoked when a response to the Get Current Tilt command is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param targetTiltPct The current tilt (percent).
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didGetCurrentTilt:(double)currentTiltPct withInfo:(WFWahooControlPointDelegateInfo *)info;


/**
 * Invoked when a Current Tilt change event is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param currentTiltPct The new current tilt in percent.
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didSendCurrentTiltChangeEvent:(double)currentTiltPct;


/**
 * Invoked when a response to the Get Tilt Mode command is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param tiltMode The current tilt mode in effect.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didGetTiltMode:(WFWahooAdvancedFitnessEquipmentControlTiltMode_t)tiltMode withInfo:(WFWahooControlPointDelegateInfo *)info;


/**
 * Invoked when a Tilt Mode change event is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param tiltMode The new tilt mode.
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didSendTiltModeChangeEvent:(WFWahooAdvancedFitnessEquipmentControlTiltMode_t)tiltMode;


/**
 * Invoked when a response to the Get Tilt Limits command is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param minTilt The minimum tilt value (percent) for the current configuration (this depends on wheel base and hub height)
 * @param maxTilt The maximum tilt value (percent) for the current configuration (this depends on wheel base and hub height)
 * @param info Structure containing info regarding the control point command (eg status)
 *
 * Note: receiving this delegate callback may take as long as 10 seconds from sending the getTiltLimits command
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didGetTiltLimits:(double)minTiltPct to:(double)maxTiltPct withInfo:(WFWahooControlPointDelegateInfo *)info;


/**
 * Invoked when a Tilt Limits change event is received.
 *
 * @param sender The WFBikePowerConnection instance.
 * @param minTiltPct The minimum tilt value (percent) for the current configuration (this depends on wheel base and hub height)
 * @param maxTiltPct The maximum tilt value (percent) for the current configuration (this depends on wheel base and hub height)
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didSendTiltLimitsChangedEvent:(double)minTiltPct to:(double)maxTiltPct;

/**
 Invoked when a set zero tilt offset change event response is received.

 @param sender the WFBikePowerConnection instance
 @param offset the new tilt offset from 0% on the top tube angle
 @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didSetZeroTiltOffset:(double)offset withInfo:(WFWahooControlPointDelegateInfo *)info;

/**
 Invoked when a get zero tilt offset command response is received.

 @param sender the WFBikePowerConnectionn instance
 @param offset the new tilt offset that was set from 0% on the top tube angle
 @param info Structure containing info regarding the control point command (eg status)
 */
- (void)wahooAdvancedFitnessEquipmentControl:(id)sender didGetZeroTiltOffset:(double)offset withInfo:(WFWahooControlPointDelegateInfo *)info;

@end

