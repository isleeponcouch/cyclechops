//
//  WFFitnessEquipmentData.h
//  WFConnector
//
//  Created by Michael Moore on 12/21/10.
//  Copyright 2010 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WFConnector/WFSensorData.h>


/**
 * Represents the most commonly used data available from the ANT+ Fitness Equipment sensor.
 *
 * ANT+ sensors send data in multiple packets.  The WFFitnessEquipmentData combines the
 * most commonly used of this data into a single entity.  The data represents
 * the latest of each data type sent from the sensor.
 */

@interface WFFitnessEquipmentData : WFSensorData
{
	/** \cond InterfaceDocs */
	
	// general FE data.
	WFFitnessEquipmentType_t equipmentType;
	WFFitnessEquipmentState_t equipmentState;
	float accumTime;
	ULONG accumDistance;
	float instSpeed;
	UCHAR heartrate;
    ULONG heartrateAccumBeatCount;
    NSTimeInterval heartrateTimestamp;
	UCHAR lapNumber;
    float lastLapAccumTime;
   BOOL cadenceSupported;
   BOOL wheelRevolutionSupported;
	
	// equipment specific: treadmill.
	UCHAR treadmillCadence;
	float treadmillAccumNegVertDist;
	float treadmillAccumPosVertDist;
	
	// equipment specific: elliptical.
	float  ellipticalAccumPosVertDist;
	ULONG  ellipticalAccumStrides;
	UCHAR  ellipticalCadence;
	USHORT ellipticalInstPower;
	
	// equipment specific: bike.
	UCHAR  bikeCadence;
    NSTimeInterval bikeCadenceTimestamp;
    ULONG bikeAccumCrankRevolutions;
	USHORT bikeInstPower;
    float bikeAccumTorque;
    NSTimeInterval bikeTimestamp;
	
	// equipment specific: rower.
	ULONG  rowerAccumStrokes;
	UCHAR  rowerCadence;
	USHORT rowerInstPower;
   
   // equipment specific: climber.
   ULONG climberAccumStrides;
   UCHAR climberCadence;
   USHORT climberInstPower;
   
   // equipment specific: skier.
   ULONG skierAccumStrides;
   UCHAR skierCadence;
   USHORT skierInstPower;
   
   // equipment specific: trainer.
   ULONG trainerEventCount;
   UCHAR trainerInstCadence;
   USHORT trainerAccumPower;
   USHORT trainerInstPower;
   USHORT trainerTargetPower;
   
   // equipment specific: trainer torque.
   ULONG trainerTorqueEventCount;
   UCHAR trainerTorqueWheelTicks;
   USHORT trainerTorqueWheelPeriod;
   float trainerTorqueAccumTorque;
   USHORT trainerTorqueWheelRPM;
   NSTimeInterval wheelTimestamp;
   
   // calibration
   BOOL calibrationZeroOffsetSuccess;
   BOOL calibrationSpindownSuccess;
   UCHAR calibrationTemperature;
   USHORT calibrationZeroOffset;
   USHORT calibrationSpindownTimeMs;
   UCHAR calibrationSpeedCondition;
   UCHAR calibrationTemperatureCondition;
   UCHAR calibrationCurrentTemperature;
   USHORT calibrationTargetSpeed;
   USHORT calibrationTargetSpindownTimeMs;

	UCHAR debugRawElapsedTime;
    UCHAR debugNewElapsedTime;
    UCHAR debugRawElapsedDistance;
    USHORT debugRawSpeed;

	/** \endcond */
}


// general FE data.


/**
 * The type of the connected Fitness Equipment device.
 */
@property (nonatomic, assign) WFFitnessEquipmentType_t equipmentType;
/**
 * The current state of the connected Fitness Equipment device.
 */
@property (nonatomic, assign) WFFitnessEquipmentState_t equipmentState;
/**
 * The accumulated time since the workout was started, in seconds.
 */
@property (nonatomic, assign) float accumTime;
/**
 * <c>TRUE</c> if the sensor provides cadence data, otherwise <c>FALSE</c>.
 */
@property (nonatomic, assign) BOOL cadenceSupported;

/**
 * Returns <c>TRUE</c> if the connected sensor supports Wheel Revolutions (Speed/Distance)
 */
@property (nonatomic, assign, getter = isWheelRevolutionSupported) BOOL wheelRevolutionSupported;
/**
 * The accumulated distance, in meters, since the workout was started.
 */
@property (nonatomic, assign) ULONG accumDistance;
/**
 * The instantaneous speed, in meters per second.
 */
@property (nonatomic, assign) float instSpeed;
/**
 * The instantaneous heart rate, in BPM.
 */
@property (nonatomic, assign) UCHAR heartrate;
/**
 * The calcualted accumulated heart rate, in BPM. (estamated based on instant HR)
 */
@property (nonatomic, assign) ULONG heartrateAccumBeatCount;

/**
 * Timestamp of the last received bike cadence data
 */
@property (nonatomic, assign) NSTimeInterval heartrateTimestamp;

/**
 * The current lap number.
 */
@property (nonatomic, assign) UCHAR lapNumber;
/**
 * The total accumulated time at the last lap event
 */
@property (nonatomic, assign) float lastLapAccumTime;


// equipment specific: treadmill.

/**
 * The instantaneous cadence, in strides per minute.
 */
@property (nonatomic, assign) UCHAR treadmillCadence;
/**
 * The total negative vertial distance traveled, in meters.
 */
@property (nonatomic, assign) float treadmillAccumNegVertDist;
/**
 * The total positive vertical distance traveled, in meters.
 */
@property (nonatomic, assign) float treadmillAccumPosVertDist;

// equipment specific: elliptical.

/**
 * The total positive vertical distance traveled, in meters.
 */
@property (nonatomic, assign) float  ellipticalAccumPosVertDist;
/**
 * The total number of strides taken.
 */
@property (nonatomic, assign) ULONG  ellipticalAccumStrides;
/**
 * The instantaneous cadence, in strides per minute.
 */
@property (nonatomic, assign) UCHAR  ellipticalCadence;
/**
 * The instantaneous power, in watts.
 */
@property (nonatomic, assign) USHORT ellipticalInstPower;

// equipment specific: bike.

/**
 * The instantaneous cadence, in RPMs.
 */
@property (nonatomic, assign) UCHAR  bikeCadence;

/**
 * Timestamp of the last received bike cadence data
 */
@property (nonatomic, assign) NSTimeInterval bikeCadenceTimestamp;



/**
 * The accumulated crank revolutions since the sensor was connected or reset.
 */
@property (nonatomic, assign) ULONG bikeAccumCrankRevolutions;
/**
 * The instantaneous power, in watts.
 */
@property (nonatomic, assign) USHORT bikeInstPower;
/**
 * The estimated accumative torque (esimated based on inst power
*/
@property (nonatomic, assign) float bikeAccumTorque;
/**
 * Timestamp of the last received bike specific data
 */
@property (nonatomic, assign) NSTimeInterval bikeTimestamp;



// equipment specific: rower.

/**
 * The total stroke count.
 */
@property (nonatomic, assign) ULONG  rowerAccumStrokes;
/**
 * The instantaneous cadence, in strokes per minute.
 */
@property (nonatomic, assign) UCHAR  rowerCadence;
/**
 * The instantaneous power, in watts.
 */
@property (nonatomic, assign) USHORT rowerInstPower;



// equipment specific: climber.

/**
 * The total stride count.
 */
@property (nonatomic, assign) ULONG  climberAccumStrides;
/**
 * The instantaneous cadence, in strides per minute.
 */
@property (nonatomic, assign) UCHAR  climberCadence;
/**
 * The instantaneous power, in watts.
 */
@property (nonatomic, assign) USHORT climberInstPower;


// equipment specific: skier.

/**
 * The total stride count.
 */
@property (nonatomic, assign) ULONG  skierAccumStrides;
/**
 * The instantaneous cadence, in strides per minute.
 */
@property (nonatomic, assign) UCHAR  skierCadence;
/**
 * The instantaneous power, in watts.
 */
@property (nonatomic, assign) USHORT skierInstPower;


// equipment specific: trainer.

/**
 * The total stride count.
 */
@property (nonatomic, assign) ULONG  trainerEventCount;
/**
 * The instantaneous cadence, in strides per minute.
 */
@property (nonatomic, assign) UCHAR  trainerInstCadence;
/**
 * The accumulated power, in watts.
 */
@property (nonatomic, assign) USHORT trainerAccumPower;
/**
 * The instantaneous power, in watts.
 */
@property (nonatomic, assign) USHORT trainerInstPower;

/**
 * The target power.
 */
@property (nonatomic, assign) USHORT trainerTargetPower;

// equipment specific: trainer torque.

/**
 * The update event count.
 */
@property (nonatomic, assign) ULONG  trainerTorqueEventCount;
/**
 * The wheel ticks.
 */
@property (nonatomic, assign) UCHAR  trainerTorqueWheelTicks;
/**
 * The wheel period.
 */
@property (nonatomic, assign) USHORT trainerTorqueWheelPeriod;
/**
 * The accumulated torque.
 */
@property (nonatomic, assign) float trainerTorqueAccumTorque;
/**
 * The Trainer Wheel Rpm
 */
@property (nonatomic, assign) USHORT trainerTorqueWheelRPM;
/**
 * The real-time timestamp for speed data from the sensor (as an offset
 * from the Cocoa reference date).
 *
 * Time values from the sensors are implemented as an offset in seconds
 * between the time when the sensor is turned on and the time when a
 * data sample is taken.  This value is typically a 16-bit unsigned
 * integer in units of 1/1024 second.  The rollover is then 64 seconds.
 *
 * A base real-time value is stored when the first sample from the
 * sensor is received.  The timestamp of each subsequent sample is the
 * base time value offset by the time value offset from the sensor.
 * If the time between samples is greater than the rollover time, the
 * base time value is set to the time the first sample after the delay
 * is received.
 */
@property (nonatomic, assign) NSTimeInterval wheelTimestamp;
// calibration

/**
 * The calibration zero offset status.
 */
@property (nonatomic, assign) BOOL  calibrationZeroOffsetSuccess;
/**
 * The calibration spindown status.
 */
@property (nonatomic, assign) BOOL  calibrationSpindownSuccess;
/**
 * The temperature.
 */
@property (nonatomic, assign) UCHAR calibrationTemperature;
/**
 * The zero offset.
 */
@property (nonatomic, assign) USHORT calibrationZeroOffset;
/**
 * The spindown time in ms.
 */
@property (nonatomic, assign) USHORT calibrationSpindownTimeMs;
/**
 * The target speed in 0.001 m/s.
 */
@property (nonatomic, assign) USHORT calibrationTargetSpeed;
/**
 * The target spindown time in ms.
 */
@property (nonatomic, assign) USHORT calibrationTargetSpindownTimeMs;
/**
 * The speed condition.
 */
@property (nonatomic, assign) UCHAR calibrationSpeedCondition;
/**
 * The temperature condition.
 */
@property (nonatomic, assign) UCHAR calibrationTemperatureCondition;
/**
 * The current temperature.
 */
@property (nonatomic, assign) UCHAR calibrationCurrentTemperature;


// Debug
@property (nonatomic, assign) UCHAR debugRawElapsedTime;
@property (nonatomic, assign) UCHAR debugNewElapsedTime;
@property (nonatomic, assign) UCHAR debugRawElapsedDistance;
@property (nonatomic, assign) USHORT debugRawSpeed;

@end
