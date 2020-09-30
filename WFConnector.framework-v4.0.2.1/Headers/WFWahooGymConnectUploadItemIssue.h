//
//  WFWahooGymConnectUploadItemIssue.h
//  WFConnector
//
//  Created by Chris Uroda on 2016-04-19.
//  Copyright (c) 2016 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * Upload Item type enumeration
 */
typedef NS_ENUM(NSInteger, WFWahooGymConnectUploadItemIssueLevel_e)
{
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_LEVEL_WARNING    = 0,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_LEVEL_FATAL      = 1
};


typedef NS_ENUM(NSInteger, WFWahooGymConnectUploadItemIssueSimplifiedType_e)
{
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_SIMPLIFIED_TYPE_NULL                                 = 0,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_SIMPLIFIED_TYPE_UNEXPECTED_NOT_PERMITTED             = 1,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_SIMPLIFIED_TYPE_MISSING_ITEM                         = 11,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_SIMPLIFIED_TYPE_UNRECOGNIZED_PARAMETER_OR_SYNTAX     = 21,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_SIMPLIFIED_TYPE_INVALID_VALUE                        = 31,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_SIMPLIFIED_TYPE_INVALID_LENGTH_OR_COUNT              = 51
};


typedef NS_ENUM(NSInteger, WFWahooGymConnectUploadItemIssueType_e)
{
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_NULL                                    = 0,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_UNEXPECTED_OR_NOT_PERMITTED             = 1,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_ITEM_NOT_PERMITTED                      = 2,
    
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_MISSING_ITEM                            = 11,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_UNTERMINATED_ITEM_OR_ARRAY              = 12,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_REQUIRED_ITEM_MISSING                   = 13,
    
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_UNRECOGNIZED_PARAMETER_OR_SYNTAX        = 21,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_UNRECOGNIZED_PARAMETER                  = 22,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_UNRECOGNIZED_SYNTAX                     = 23,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_UNRECOGNIZED_UNABLE_TO_PARSE_VALUE      = 24,
    
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_INVALID_VALUE                           = 31,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_INVALID_VALUE_MUST_NOT_BE_ZERO          = 32,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_INVALID_VALUE_MUST_NOT_BE_NULL          = 33,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_INVALID_VALUE_MUST_BE_INTEGER           = 34,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_INVALID_VALUE_MUST_BE_POSITIVE_INTEGER  = 35,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_INVALID_VALUE_MUST_BE_NUMBER            = 36,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_INVALID_VALUE_MUST_BE_POSITIVE_NUMBER   = 37,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_INVALID_VALUE_MUST_BE_ASCII_STRING      = 38,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_INVALID_VALUE_MUST_BE_UTF8_STRING       = 39,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_INVALID_VALUE_OUT_OF_RANGE              = 40,
    
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_INVALID_LENGTH_OR_COUNT                 = 51,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_INVALID_LENGTH_OR_COUNT_FOR_ARRAY       = 52,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_ISSUE_TYPE_INVALID_LENGTH_OR_COUNT_FOR_STRING      = 53,
};


/**
 * Represents an upload item issue which has been fetched from the Wahoo Fitness Gym Connect device.
 */
@interface WFWahooGymConnectUploadItemIssue : NSObject
{
	/** \cond InterfaceDocs */
	
    // ivars for public properties
    NSUInteger _issueLocationDataIndex;
    NSUInteger _issueLocationDataLenth;
    WFWahooGymConnectUploadItemIssueSimplifiedType_e _simplifiedIssueType;
    WFWahooGymConnectUploadItemIssueType_e _issueType;
    WFWahooGymConnectUploadItemIssueLevel_e _issueLevel;
    NSNumber* _additionalInfoMinimumValue;
    NSNumber* _additionalInfoMaximumValue;
    NSNumber* _additionalInfoMinimumLength;
    NSNumber* _additionalInfoMaximumLength;
    
    // ivars for private properties

    /** \endcond */
}



@property (nonatomic, assign) NSUInteger issueLocationDataIndex;
@property (nonatomic, assign) NSUInteger issueLocationDataLenth;

@property (nonatomic, assign) WFWahooGymConnectUploadItemIssueSimplifiedType_e simplifiedIssueType;
@property (nonatomic, assign) WFWahooGymConnectUploadItemIssueType_e issueType;

@property (nonatomic, assign) WFWahooGymConnectUploadItemIssueLevel_e issueLevel;

@property (nonatomic, strong) NSNumber* additionalInfoMinimumValue;
@property (nonatomic, strong) NSNumber* additionalInfoMaximumValue;

@property (nonatomic, strong) NSNumber* additionalInfoMinimumLength;
@property (nonatomic, strong) NSNumber* additionalInfoMaximumLength;


@end

