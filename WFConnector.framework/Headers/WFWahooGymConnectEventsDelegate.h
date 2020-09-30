//
//  WFWahooGymConnectEventsDelegate.h
//  WFConnector
//
//  Created by Chris Uroda 2015-06-15
//  Copyright (c) 2015 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WFConnector/WFWahooGymConnectFitnessEquipmentData.h>
#import <WFConnector/WFWahooGymConnectFitnessEquipmentSummaryData.h>
#import <WFConnector/WFWahooGymConnectUserData.h>
#import <WFConnector/WFWahooGymConnectUploadItem.h>
#import <WFConnector/WFWahooGymConnectUploadItemIssue.h>


@protocol WFWahooGymConnectEventsDelegate <NSObject>

@optional

/**
 * Invoked when a Fitness Equipment state change has been detected.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param stateInfo An instance of WFWahooGymConnectFitnessEquipmentStateInformation containing the new state information.
 */
- (void)wahooGymConnect:(id)sender fitnessEquipmentDidChangeState:(WFWahooGymConnectFitnessEquipmentStateInformation*)stateInfo;


/**
 * Invoked when a Fitness Equipment workout program name change has been detected.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param workoutProgramName The new workout program name.
 */
- (void)wahooGymConnect:(id)sender fitnessEquipmentDidChangeWorkoutProgramName:(NSString*)workoutProgramName;




/**
 * Invoked when a user data upload process completed
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param userData An instance of WFWahooGymConnectUserData containing the user information that was uploaded to the fitness equipment.
 * @param error If an error occurs, an error object containing the error information will be provided.  The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender userData:(WFWahooGymConnectUserData*)userData uploadDidCompleteWithError:(NSError*)error;


/**
 * Invoked once recently uploaded user data has come into effect on the fitness equipment.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param error If an error occurs, an error object containing the error information will be provided.  The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender userDataDidBecomeInEffectWithError:(NSError*)error;


/**
 * Invoked when the device has responded to a request for the Supported Upload Item Types
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param supportedUploadItemTypes An array of NSNumbers, each representing an unsigned integer Upload Item Id.
 * @param vendorID The Identifier for the vendor (some Upload Item Types are Vendor/Manufacturer specific).
 * @param vendorSpecificInfoValues An array of NSNumbers, each representing an unsigned integer vendor specific information value (in the order as sent by the peripheral)
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchSupportedUploadItemTypes:(NSArray*)supportedUploadItemTypes forVendor:(WFWahooGymConnectUploadItemVendorId_e)vendorID withVendorSpecificInfoValues:(NSArray*)vendorSpecificInfoValues withError:(NSError*)error;

/**
 * Invoked when the device has Supported Upload Item Types fetch has progressed
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param packetCount The number of packets that have been fetched.
 * @param expectedTotalPacketCount If the expected total packet count is not known, this value will be zero.  Be careful to avoid divide by zero problems.
 */
- (void)wahooGymConnect:(id)sender didProgressSupportedUploadItemTypesFetchingWithPacketCount:(NSUInteger)packetCount ofExpectedTotalPacketCount:(NSUInteger)expectedTotalPacketCount;


/**
 * Invoked when the upload process of an "upload item" has been completed
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param uploadItem The item which was uploaded (or failied to upload).
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain. 
 */
- (void)wahooGymConnect:(id)sender didCompleteUploadOfItem:(WFWahooGymConnectUploadItem *)uploadItem withError:(NSError*)error;


/**
 * Invoked when the upload process of an "upload item" is progressing.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param progressPercentage The progress percentage.  0.0 = 0%, 1.0 = 100%
 */
- (void)wahooGymConnect:(id)sender didProgressUploadOfItemWithProgressPercentage:(double)progressPercentage;

/**
 * Invoked when the remote device's progress of processing the "upload item" has progressed.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param progressPercentage The progress percentage.  0.0 = 0%, 1.0 = 100%.  A negative value means that the device is process but is unable to report a progress percentage (indeterminate)
 */
- (void)wahooGymConnect:(id)sender didProgressUploadItemProcessingWithProgressPercentage:(double)progressPercentage;



/**
 * Invoked when the fetching of "upload item issues" has been completed
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param uploadItemIssues The fetched issues - the members of this array are instances of the WFWahooGymConnectUploadItemIssue class
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didCompleteFetchingUploadItemIssues:(NSArray *)uploadItemIssues withError:(NSError*)error;


/**
 * Invoked when the fetching of "upload item issues" is progressing.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param numIssuesFetched The number of issues that have been fetched so far
 */
- (void)wahooGymConnect:(id)sender didProgressFetchingUploadItemIssuesWithNumIssuesFetched:(NSUInteger)numIssuesFetched;


/**
 * Invoked when the Fitness Equipment Workout Summary has been fetched.
 *
 * @param sender The WFWahooGymConnectConnection instance.
 * @param fitnessEquipmentSummaryData The summary data
 * @param error If an error occurs, an error object containing the error information will be provided. The error is limited to WFDeviceControlPointErrorDomain.
 */
- (void)wahooGymConnect:(id)sender didFetchFitnessEquipmentSummaryData:(WFWahooGymConnectFitnessEquipmentSummaryData*)fitnessEquipmentSummaryData withError:(NSError*)error;



@end