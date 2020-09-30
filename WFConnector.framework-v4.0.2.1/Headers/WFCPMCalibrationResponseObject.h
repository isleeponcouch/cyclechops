//
//  WFCPMCalibrationResponseObject.h
//  WFConnector
//
//  Created by Murray Hughes on 19/03/2015.
//  Copyright (c) 2015 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WFConnector/_WFBikePowerDelegate.h>

@interface WFCPMCalibrationResponseObject : NSObject
{
    BOOL bResponseSuccess;
    UCHAR ucResponseStatus;
    UCHAR ucResponseErrorParam;
    UCHAR ucResponseWahooErrorParam;
    
    USHORT ucManufactureID;
    NSData* manufactureData;
    SSHORT ssOffsetCompensation;
    USHORT usOffset;
    SCHAR scTemperature;
}

@property (nonatomic, assign) BOOL bResponseSuccess;

@property (nonatomic, assign) UCHAR ucResponseStatus;
@property (nonatomic, assign) UCHAR ucResponseErrorParam;
@property (nonatomic, assign) UCHAR ucResponseWahooErrorParam;

@property (nonatomic, assign) USHORT usOffset;
@property (nonatomic, assign) USHORT ucManufactureID;
@property (nonatomic, strong) NSData* manufactureData;
@property (nonatomic, assign) SCHAR scTemperature;
@property (nonatomic, assign) SSHORT ssOffsetCompensation;

@end
