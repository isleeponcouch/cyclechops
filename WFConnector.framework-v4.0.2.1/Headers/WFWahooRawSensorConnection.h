//
//  WFWahooRawSensorConnection.h
//  WFConnector
//
//  Created by Chris Uroda on 2014-12-18.
//  Copyright (c) 2014 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WFConnector/WFSensorConnection.h>
#import <WFConnector/WFWahooRawSensorTypes.h>
#import <WFConnector/WFWahooRawSensorControlEventsDelegate.h>
#import <WFConnector/WFWahooRawSensorMeasurementEventsDelegate.h>


/**
 * Represents a connection to a Wahoo Raw Sensor Service (implemented by a BLE device)
 */
@interface WFWahooRawSensorConnection : WFSensorConnection
{
	/** \cond InterfaceDocs */
    
    id<WFWahooRawSensorControlEventsDelegate> __weak controlEventsDelegate;
    id<WFWahooRawSensorMeasurementEventsDelegate> __weak measurementEventsDelegate;
	/** \endcond */
}


@property (nonatomic, weak) id<WFWahooRawSensorControlEventsDelegate> controlEventsDelegate;

@property (nonatomic, weak) id<WFWahooRawSensorMeasurementEventsDelegate> measurementEventsDelegate;



- (BOOL)activateMeasurements:(NSArray*)measurementTypes;

- (BOOL)deactivateMeasurements:(NSArray*)measurementTypes;

@end
