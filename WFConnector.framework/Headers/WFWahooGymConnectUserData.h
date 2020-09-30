//
//  WFWahooGymConnectUserData.h
//  WFConnector
//
//  Created by Chris Uroda on 2015-09-28.
//  Copyright (c) 2015 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * User Data Gender Enumeration
 */
typedef NS_ENUM(NSInteger, WFWahooGymConnectUserDataGender_t) {
    WF_WAHOO_GYM_CONNECT_USER_DATA_GENDER_NONE                          = 0,
    WF_WAHOO_GYM_CONNECT_USER_DATA_GENDER_MALE                          = 1,
    WF_WAHOO_GYM_CONNECT_USER_DATA_GENDER_FEMALE                        = 2,
};


/**
 * Represents the user information which can be uploaded to the Wahoo Fitness Gym Connect device.
 */
@interface WFWahooGymConnectUserData : NSObject
{
	/** \cond InterfaceDocs */
	
    // ivars for public properties
    NSNumber* _userWeight;
    NSNumber* _userAge;
    WFWahooGymConnectUserDataGender_t _userGender;
    NSString* _userName;
    
    // ivars for private properties
    
	/** \endcond */
}


@property (nonatomic, strong) NSNumber* userWeight;                             /**< Units are kilograms */
@property (nonatomic, strong) NSNumber* userAge;                                /**< Units are years */
@property (nonatomic, assign) WFWahooGymConnectUserDataGender_t userGender;     /**< */
@property (nonatomic, strong) NSString* userName;                               /**< */


@end

