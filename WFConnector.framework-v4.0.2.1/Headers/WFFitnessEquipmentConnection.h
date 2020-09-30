//
//  WFFitnessEquipmentConnection.h
//  WFConnector
//
//  Created by Michael Moore on 12/21/10.
//  Copyright 2010 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WFConnector/WFSensorConnection.h>


@class WFFitnessEquipmentData;
@class WFFitnessEquipmentRawData;


/**
 * Represents a connection to an ANT+ Fitness Equipment sensor.
 */
@interface WFFitnessEquipmentConnection : WFSensorConnection
{
}

/**
 * Returns the latest data available from the sensor.
 *
 * @see WFSensorConnection::getData
 *
 * @return A WFFitnessEquipmentData instance containing data if available,
 * otherwise <c>nil</c>.
 */
- (WFFitnessEquipmentData*)getFitnessEquipmentData;

/**
 * Returns the latest raw (unformatted) data available from the sensor.
 *
 * @see WFSensorConnection::getRawData
 *
 * @return A WFFitnessEquipmentRawData instance containing data if available,
 * otherwise <c>nil</c>.
 */
- (WFFitnessEquipmentRawData*)getFitnessEquipmentRawData;


- (BOOL)trainerSetBasicResistance:(float)fpScale;
- (BOOL)trainerSetTargetPower:(float)fpWatts;
- (BOOL)trainerSetWindResistance:(float)fpWindResistanceCoefficient windSpeed:(float)fpWindSpeed dragFactor:(float)fpDragFactor;
- (BOOL)trainerSetTrackResistance:(float)fpGrade rollingResistance:(float)fpCrr;
- (BOOL)trainerReadFECapabilities;
- (BOOL)trainerSetUserConfiguration:(float)fpUserWeight wheelDiameter:(USHORT)usWheelDiameterMm bicycleWeight:(float)fpBicycleWeight gearRatio:(float)fpGearRatio;
- (BOOL)trainerInitSpindown;
- (BOOL)trainerRequestCurrentState;

/**
 * Returns Notification Names for Calibrating Fitness Equipment sensor.
 */
+ (NSString *)notificationCenterNameForDidReceiveTrainerInitSpindownResponse;
+ (NSString *)notificationCenterNameForDidReceiveTrainerSpindownResultResponse;

@end
