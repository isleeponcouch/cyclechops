//
//  WFBIKEStateData.h
//  WFConnector
//
//  Created by Garrett Franks on 5/14/19.
//  Copyright © 2019 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, WFBIKEBrakeLocation_e)
{
    WF_BIKE_BRAKE_LOCATION_FRONT_ON_LEFT  = 0,
    WF_BIKE_BRAKE_LOCATION_FRONT_ON_RIGHT = 1,
    WF_BIKE_BRAKE_LOCATION_UNKNOWN        = 0xFF,
};

typedef NS_ENUM(NSInteger, WFBIKEShifterType_e)
{
    WF_BIKE_SHIFTER_TYPE_SHIMANO_DI2          = 0,
    WF_BIKE_SHIFTER_TYPE_SHIMANO_DI2_SYNCHRO  = 1,
    WF_BIKE_SHIFTER_TYPE_SRAM_ETAP            = 2,
    WF_BIKE_SHIFTER_TYPE_SRAM_MECHANICAL      = 3,
    WF_BIKE_SHIFTER_TYPE_CAMPAGNOLO           = 4,
    WF_BIKE_SHIFTER_TYPE_INVALID              = 0xFF,
};

typedef NS_ENUM(NSInteger, WFBIKEShifterVariant_e)
{
	WF_BIKE_SHIFTER_VARIANT_LEFT_CONNECTED			= 0x00,
	WF_BIKE_SHIFTER_VARIANT_RIGHT_CONNECTED			= 0x01,
	WF_BIKE_SHIFTER_VARIANT_DISCONNECTED			= 0xFF,
};


@class WFBIKEChainringData;
@class WFBIKECassetteData;
@interface WFBIKEStateData : NSObject

/// the current shifter type
@property (nonatomic, assign) WFBIKEShifterType_e currentShifterType;

/// the current chainring setting
@property (nonatomic, strong, nullable) WFBIKEChainringData *currentChainringSetting;

/// the current cassette setting
@property (nonatomic, strong, nullable) WFBIKECassetteData *currentCassetteSetting;

/// the current brake location
@property (nonatomic, assign) WFBIKEBrakeLocation_e currentBrakeLocation;

+ (nonnull instancetype)bikeStateWithData:(nonnull NSData *)data;
+ (WFBIKEShifterType_e)shifterTypeForSegment:(NSInteger)segment;
+ (WFBIKEBrakeLocation_e)brakeLocationForSegment:(NSInteger)segment;

@end

// Chainring State Data
@interface WFBIKEChainringData: WFBIKEStateData

/// the inner chainring setting
@property (nonatomic, assign) u_int8_t innerChainring;

/// the middle chainring setting
@property (nonatomic, assign) u_int8_t middleChainring;

/// the outer chainring setting
@property (nonatomic, assign) u_int8_t outerChainring;

+ (nonnull instancetype)defaultBIKEChainringStateData;

- (nonnull instancetype)initBIKEChainringStateWithInnerChainring:(int)innerChainring
                                                 middleChainring:(int)middleChainring
                                                  outerChainring:(int)outerChainring;

@end


// Cassette State Data
@interface WFBIKECassetteData: WFBIKEStateData

/// the first sprocket setting
@property (nonatomic, assign) u_int8_t sprocket1;

/// the second sprocket setting
@property (nonatomic, assign) u_int8_t sprocket2;

/// the third sprocket setting
@property (nonatomic, assign) u_int8_t sprocket3;

/// the fourth sprocket setting
@property (nonatomic, assign) u_int8_t sprocket4;

/// the fifth sprocket setting
@property (nonatomic, assign) u_int8_t sprocket5;

/// the sixth sprocket setting
@property (nonatomic, assign) u_int8_t sprocket6;

/// the seventh sprocket setting
@property (nonatomic, assign) u_int8_t sprocket7;

/// the eighth sprocket setting
@property (nonatomic, assign) u_int8_t sprocket8;

/// the ninth sprocket setting
@property (nonatomic, assign) u_int8_t sprocket9;

/// the tenth sprocket setting
@property (nonatomic, assign) u_int8_t sprocket10;

/// the eleventh sprocket setting
@property (nonatomic, assign) u_int8_t sprocket11;

/// the twelfth sprocket setting
@property (nonatomic, assign) u_int8_t sprocket12;

/// the thirteenth sprocket setting
@property (nonatomic, assign) u_int8_t sprocket13;

+ (nonnull instancetype)defaultBIKECassetteStateData;

- (nonnull instancetype)initBIKECassetteStateWithSprocket1:(int)sprocket1
                                                  sprocket2:(int)sprocket2
                                                  sprocket3:(int)sprocket3
                                                  sprocket4:(int)sprocket4
                                                  sprocket5:(int)sprocket5
                                                  sprocket6:(int)sprocket6
                                                  sprocket7:(int)sprocket7
                                                  sprocket8:(int)sprocket8
                                                  sprocket9:(int)sprocket9
                                                 sprocket10:(int)sprocket10
                                                 sprocket11:(int)sprocket11
                                                 sprocket12:(int)sprocket12
                                                 sprocket13:(int)sprocket13;

@end

@interface WFBIKESystemHealthCheckData: WFBIKEStateData

@property (nonatomic, assign) WFBIKEShifterVariant_e shifterPortOneStatus;
@property (nonatomic, assign) WFBIKEShifterVariant_e shifterPortTwoStatus;
@property (nonatomic, assign) WFBIKEShifterVariant_e shifterPortThreeStatus;

@property (nonatomic, assign, readonly) BOOL shiftersDisconnected;


- (nonnull instancetype)initHealthCheckDataWithPortOneStatus:(WFBIKEShifterVariant_e)portOneStatus
											   portTwoStatus:(WFBIKEShifterVariant_e)portTwoStatus
											 portThreeStatus:(WFBIKEShifterVariant_e)portThreeStatus;
@end
