//
//  WFBikeTrainerDelegate.h
//  WFConnector
//
//  Created by Michael Moore on 8/18/12.
//  Copyright (c) 2012 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WFConnector/_WFBikeTrainerDelegate.h>


/**
 * Provides the interface for callback methods used by the WFBikePowerConnection.
 *
 * This delegate handles callbacks for commands according to the Wahoo-specific
 * Bike Trainer Profile.  For commands used by CSC Profile devices please see
 * the WFBikePowerDelegate.
 */
@protocol WFBikeTrainerDelegate <_WFBikeTrainerDelegate>

@optional

/**
 * Invoked when a response to the Set Trainer Mode command is received.
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param eMode The WFBikeTrainerMode_t specified in the command.
 * @param params An NSDictionary instance containing changed parameters associated
 *               with the current mode.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didSetTrainerMode:(WFBikeTrainerMode_t)eMode params:(NSDictionary*)params info:(WFBikeTrainerDelegateInfo_t)info;
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didSetTrainerMode:(WFBikeTrainerMode_t)eMode status:(UCHAR)ucStatus __deprecated_msg("Use cpmConnection:didSetTrainerMode:params:info:");


/**
 * Invoked when a response to the Set Trainer Grade command is received.
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param grade The new trainer grade.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didSetTrainerGrade:(float)grade info:(WFBikeTrainerDelegateInfo_t)info;
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didSetTrainerGrade:(UCHAR)ucStatus __deprecated_msg("Use cpmConnection:didSetTrainerGrade:info:");


/**
 * Invoked when a response to the Set Trainer Rolling Resistance command is received.
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param rollingResistance The new rolling resistance.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didSetTrainerRollingResistance:(float)rollingResistance info:(WFBikeTrainerDelegateInfo_t)info;
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didSetTrainerRollingResistance:(UCHAR)ucStatus __deprecated_msg("Use cpmConnection:didSetTrainerRollingResistance:info:");



/**
 * Invoked when a response to the Set Trainer Wind Resistance command is received.
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param windResistance The new wind resistance.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didSetTrainerWindResistance:(float)windResistance info:(WFBikeTrainerDelegateInfo_t)info;
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didSetTrainerWindResistance:(UCHAR)ucStatus __deprecated_msg("Use cpmConnection:didSetTrainerWindResistance:info:");


/**
 * Invoked when a response to the Set Trainer Wind Speed command is received.
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param windSpeed The new wind speed.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didSetTrainerWindSpeed:(float)windSpeed info:(WFBikeTrainerDelegateInfo_t)info;
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didSetTrainerWindSpeed:(UCHAR)ucStatus __deprecated_msg("Use cpmConnection:didSetTrainerWindSpeed:info:");


/**
 * Invoked when a response to the Set Trainer Wheel Circumference command is received.
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param wheelCircumference The new wheel circumference.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didSetTrainerWheelCircumference:(USHORT)wheelCircumference info:(WFBikeTrainerDelegateInfo_t)info;
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didSetTrainerWheelCircumference:(UCHAR)ucStatus __deprecated_msg("Use cpmConnection:didSetTrainerWindSpeed:info:");


/**
 * Invoked when a response to the Read Trainer Mode command is received.
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param ucStatus The status of the command (0 is Success).
 * @param eMode If the command was successful, the current WFBikeTrainerMode_t.
 * @param params An NSDictionary instance containing any parameters associated
 * with the current mode.
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveTrainerReadModeResponse:(WFBikeTrainerMode_t)eMode params:(NSDictionary*)params info:(WFBikeTrainerDelegateInfo_t)info;
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveTrainerReadModeResponse:(UCHAR)ucStatus mode:(WFBikeTrainerMode_t)eMode params:(NSDictionary*)params __deprecated_msg("Use cpmConnection:didReceiveTrainerReadModeResponse:params:info:");
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveTrainerReadModeResponse:(UCHAR)ucStatus mode:(WFBikeTrainerMode_t)eMode __attribute__((unavailable("Use cpmConnection:didReceiveTrainerReadModeResponse:mode:params")));


/**
 * Invoked when a response to the Set Trainer Feature Enabled State is received.
 *
 * @param eFeature The feature for which the state was set
 * @param bEnabled <c>TRUE</c> if the specified feature is enabled, <c>FALSE</c> if the specified feature is disabled.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveTrainerSetFeatureEnabledStateResponse:(WFBikeTrainerFeature_t)eFeature enabled:(BOOL)bEnabled info:(WFBikeTrainerDelegateInfo_t)info;


/**
 * Invoked when a response to the Read Trainer Feature Enabled State command is received.
 *
 * @param eFeature The feature for which the state was requested
 * @param bEnabled <c>TRUE</c> if the specified feature is enabled, <c>FALSE</c> if the specified feature is disabled.
 * @param info Structure containing info regarding the control point command (eg status)
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveTrainerReadFeatureEnabledStateResponse:(WFBikeTrainerFeature_t)eFeature enabled:(BOOL)bEnabled info:(WFBikeTrainerDelegateInfo_t)info;

/**
 * Invoked when a response to Set Paired Ant Device Id is received
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param eChannelType The channel type for the paired ANT device
 * @param info Structure containing info regarding the control point command
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveTrainerSetPairedAntDeviceIdResponse:(WFBikeTrainerPairedAntChannelType_t)eChannelType info:(WFBikeTrainerDelegateInfo_t)info;


/**
 * Invoked when a response to Read Paired Ant Device Id is received
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param eChannelType The channel type for the paired ANT device
 * @param usDeviceId The device id for the paired ANT device
* @param info Structure containing info regarding the control point command
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveTrainerReadPairedAntDeviceIdResponse:(WFBikeTrainerPairedAntChannelType_t)eChannelType deviceId:(USHORT)usDeviceId info:(WFBikeTrainerDelegateInfo_t)info;


/**
 * Invoked when a response to Request Paired Ant Device State is received
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param eState The channel state for the paired ANT device
 * @param eChannelType The channel type for the paired ANT device
 * @param usDeviceId The device id for the paired ANT device
* @param info Structure containing info regarding the control point command
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveTrainerReadPairedAntDeviceState:(WFBikeTrainerPairedAntDeviceState_t)eState channelType:(WFBikeTrainerPairedAntChannelType_t)eChannelType deviceId:(USHORT)usDeviceId info:(WFBikeTrainerDelegateInfo_t)info;


/**
 * Invoked when a response to the Trainer Get Calibration Capabilities command is received
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param supportedCalibrations The calibration capabilities supported by the device. See wf_bike_trainer_types.h for calibration capability definitions.
 * @param requiredCalibrations The calibrations that are currently required for proper functioning of the device. See wf_bike_trainer_types.h for calibration capability definitions.
 * @param Structure containing info regarding the control point command (eg status)
 */
- (void)cpmConnection:(WFBikePowerConnection *)cpmConn didReceiveTrainerCalibrationCapabalities:(NSSet *)supportedCalibrations required:(NSSet *)requiredCalibrations info:(WFBikeTrainerDelegateInfo_t)info;


/**
 * Invoked when a response to the Trainer Init Spindown command is received.
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param ucStatus The command status code (0 for Success).
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveTrainerInitSpindownResponseWithInfo:(WFBikeTrainerDelegateInfo_t)info __deprecated_msg("Use WFBikeTrainerSpindownCalibratorDelegate class to receive spindown progress callbacks");
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveTrainerInitSpindownResponse:(UCHAR)ucStatus __deprecated_msg("Use WFBikeTrainerSpindownCalibratorDelegate class to receive spindown progress callbacks");


/**
 * Invoked when a Trainer Spindown Result is received.
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param spindownTime The spindown time value.
 * @param spindownTemperature The spindown temperature value.
 * @param spindownOffset The zero offset calibration
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveTrainerSpindownResult:(float)spindownTime temperature:(float)spindownTemperature offset:(USHORT)spindownOffset __deprecated_msg("Use WFBikeTrainerSpindownCalibratorDelegate class to receive spindown progress callbacks");


/**
 * Invoked when a response to the Trainer Assign Device Info command is received.
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param ucStatus The command status code (0 for Success).
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveAntIdResponse:(UCHAR)ucStatus;



/**
 * Invoked when a response to the Trainer Read Device Info command is received.
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param ucStatus The command status code (0 for Success).
 * @param ulSerial The serial number of the device.
 * @param usAntId The ANT ID of the device
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveReadDeviceInfoResponse:(UCHAR)ucStatus serialNumber:(ULONG)ulSerial antId:(USHORT)usAntId;


/**
 * Invoked when a response to the Trainer Request ANT Connection command is received.
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param ucStatus The command status code (0 for Success).
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveTrainerRequestAntConnectionResponse:(UCHAR)ucStatus __attribute__((unavailable("Use cpmConnection:didReceiveSetPairendAntDeviceIdResponse:channelType:info:")));


/**
 * Invoked when a Kurt InRide Trainer Spindown Result is received.
 *
 * @param cpmConn The WFBikePowerConnection instance.
 * @param ulSpindownPeriod The spindown period, in microseconds.
 */
- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveKurtSpindownResult:(ULONG)ulSpindownPeriod;


- (void)cpmConnection:(WFBikePowerConnection*)cpmConn didReceiveKurtSetProFlywheelEnabled:(BOOL) proFlywheelEnabled spindownEnabled:(BOOL) spindownEnabled response:(BOOL)bSuccess;


@end
