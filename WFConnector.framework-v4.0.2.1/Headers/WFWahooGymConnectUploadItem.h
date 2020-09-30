//
//  WFWahooGymConnectUploadItem.h
//  WFConnector
//
//  Created by Chris Uroda on 2016-04-18.
//  Copyright (c) 2016 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * Upload Item type enumeration for non-vender specific item types
 */
typedef NS_ENUM(NSInteger, WFWahooGymConnectUploadItemType_e)
{
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_TYPE_NULL               = 0,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_TYPE_TEXT_MESSAGE       = 2,
};

typedef NS_ENUM(NSInteger, WFWahooGymConnectUploadItemVendorId_e)
{
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_VENDOR_ID_NULL                 = 0,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_VENDOR_ID_WAHOO_FITNESS        = 0x0001,
    
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_VENDOR_ID_STAR_TRAC            = 0x0101,
    WF_WAHOO_GYM_CONNECT_UPLOAD_ITEM_VENDOR_ID_STAIRMASTER          = 0x0102,
};



/**
 * Represents the an item which can be uploaded to the Wahoo Fitness Gym Connect device.
 */
@interface WFWahooGymConnectUploadItem : NSObject
{
	/** \cond InterfaceDocs */
	
    // ivars for public properties
    uint16_t _itemType;

    NSData* _itemData;
    
    // ivars for private properties
    NSUInteger _numIssuesThatAreFatal;
    NSUInteger _numIssuesThatAreWarnings;
	/** \endcond */
}



@property (nonatomic, assign) uint16_t itemType;
@property (nonatomic, strong) NSData* itemData;

/**
 * These properties are set once the Upload has been sucessfully completed.
 * The receiver will use warning issues and or fatal issues to report any faults or problems
 * that it detects with the uploaded data
 */
@property (nonatomic, readonly) NSUInteger numIssuesThatAreFatal;
@property (nonatomic, readonly) NSUInteger numIssuesThatAreWarnings;



@end

