//
//  WFHardwareConnector.h
//  WFHardwareConnector
//
//  Created by Michael Moore on 2/9/10.
//  Copyright 2010 Wahoo Fitness. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WFConnector/hardware_connector_types.h>
#import <WFConnector/_WFHardwareConnector.h>


#define WF_API_VERSION @"4.0.2.1"

@class WFSensorConnection;
@class WFConnectionParams;
@class WFConnectorSettings;
@class WFFisicaInfo;


#pragma mark -
#pragma mark WFHardwareConnector Interface Declaration

/**
 * The WFHardwareConnector represents the bridge between the fisica
 * sensor receiver (dongle or case) and the iPhone application.
 *
 * The connector, along with the WFHardwareConnectorDelegate protocol, provide
 * an interface to the fisica device.  The connector is used to configure
 * the device and obtain the latest data from the sensors.  The delegate
 * protocol updates the delegate of status changes to the sensors and data
 * availability.
 */
@interface WFHardwareConnector : _WFHardwareConnector
{
}


#pragma mark -
#pragma mark WFHardwareConnector Property Declarations

/**
 * Gets the current Wahoo Fitness API version string.
 */
@property (weak, nonatomic, readonly) NSString* apiVersion;

/**
 * Gets a boolean value indicating whether the ANT Bridge is currently active.
 *
 * This value is <c>TRUE</c> when the Ant Bridge is available, configured and
 * currently serving as the Serial Transport Layer for ANT Connections.  In all
 * other cases, this value is <c>FALSE</c>.
 *
 * @see WFHardwareConnector::enableAntBridge:
 * @see WFHardwareConnector::isAntBridgeEnabled
 */
@property (nonatomic, readonly) BOOL isAntBridgeActive;

/**
 * Gets a boolean value indicating whether the ANT Bridge is currently enabled.
 *
 * @note This value does not indicate the presence or current state of the ANT
 * Bridge.  For example, the value can be <c>TRUE</c>, even when the ANT Bridge is not
 * present.  The value indicates whether the ANT Bridge will be configured and
 * used if and when it becomes available.
 *
 * @see WFHardwareConnector::enableAntBridge:
 * @see WFHardwareConnector::isAntBridgeActive
 */
@property (nonatomic, readonly) BOOL isAntBridgeEnabled;

/**
 * Gets a boolean value indicating whether the fisica device is connected.
 *
 * This property specifies the status of the dongle or case accessory.  When
 * the device is physically connected to the iPhone and communication has been
 * established, the value will be <code>true</code>.  To determine the status
 * of remote sensors (heartrate, FootPod, etc.), see the
 * WFHardwareConnector::isSensorConnected: method.
 *
 * @note This property applies to the fisica hardware only.  To determine the
 * status of BTLE hardware, use the WFHardwareConnector::isBTLEEnabled property.
 *
 * @see WFHardwareConnector::isCommunicationHWReady
 */
@property (nonatomic, readonly) BOOL isFisicaConnected;

/**
 * Gets a boolean value indicating whether the BTLE hardware is enabled and ready
 * for a connection.
 *
 * @note This propety applies to the BTLE hardware only.  To determine the status
 * of the fisica hardware, use the WFHardwareConnector::isFisicaConnected property.
 *
 * @see WFHardwareConnector::isCommunicationHWReady
 */
@property (nonatomic, readonly) BOOL isBTLEEnabled;

/**
 * Gets a boolean value indicating whether any communication hardware is available.
 *
 * This property will return <c>TRUE</c> if either the fisica hardware is connected,
 * or the BTLE hardware is enabled, or both.  If no hardware is available and enabled,
 * this property returns <c>FALSE</c>.
 *
 * @see WFHardwareConnector::isFisicaConnected <br />WFHardwareConnector::isBTLEEnabled
 */
@property (nonatomic, readonly) BOOL isCommunicationHWReady;

/**
 * Gets a boolean value indicating whether the device has hardware support for BTLE.
 */
@property (nonatomic, readonly) BOOL hasBTLESupport;

/**
 * Gets a WFFisicaInfo instance describing the properties and capabilities of
 * the currently connected fisica hardware.
 */
@property (weak, nonatomic, readonly) WFFisicaInfo* fisicaInfo;

/**
 * Gets or sets the sample rate in seconds.
 *
 * The value of this property will determine how often data updates are sent
 * to the delegate.  The WFHardwareConnectorDelegate::hardwareConnectorHasData
 * method will be invoked at the sample rate.
 */
@property (nonatomic, assign) NSTimeInterval sampleRate;

/** Gets the persistent settings for the Wahoo API. */
@property (weak, nonatomic, readonly) WFConnectorSettings* settings;


#pragma mark -
#pragma mark WFHardwareConnector Method Declarations

/**
 * Returns the number of unallocated communication channels.
 *
 * @return The number of unallocated channels.
 */
- (UCHAR)availableChannelCount;

/**
 * Returns the current state of the WFHardwareConnector.
 *
 * @return The current state.
 * <br /><br />
 * The return value is a bit-field representing the current state.  Values are:
 * <br /><br />
 * <table>
 * <tr><td><b>Value</b></td><td><b>Description</b></td></tr>
 * <tr><td>::WF_HWCONN_STATE_NOT_CONNECTED</td><td>The fisica device is not
 * physically connected.</td></tr>
 * <tr><td>::WF_HWCONN_STATE_CONNECTED</td><td>The fisica device is physically
 * connected.</td></tr>
 * <tr><td>::WF_HWCONN_STATE_ACTIVE</td><td>The fisica device is in normal
 * operation mode.</td></tr>
 * <tr><td>::WF_HWCONN_STATE_RESET</td><td>The fisica device is performing a
 * reset operation.</td></tr>
 * </table>
 * <br /><br />
 * With the exception of ::WF_HWCONN_STATE_NOT_CONNECTED, these values are
 * masked together to define the current state.  For example, the normal
 * operational state is defined by:
 * <br /><br />
 * <code>UCHAR ucNormalState = ::WF_HWCONN_STATE_CONNECTED | ::WF_HWCONN_STATE_ACTIVE;</code>
 */
- (WFHardwareConnectorState_t) currentState;

/**
 * @deprecated This API is deprecated and should not be used. It is strongly encouged that all
 * developers move to using the WFDiscoveryManager API as this will be removed in the very
 * near future
 * @see WFDiscoveryManager
 *
 * Initiates device discovery on the specified network.
 *
 * @note Device discovery must be requested on a specific network.  However, it
 * is possible to have simultaneous discovery on multiple networks by invoking
 * this method sequentially with different network types.
 *
 * @note Device discovery for the SUUNTO network is not supported at this time.
 *
 * To discover devices on a network, the following conditions must be met:
 * <ol>
 * <li>There are no existing connections on the network.</li>
 * <li>There is no device discovery currently in progress on the network.</li>
 * <li>The network must be supported (i.e. fisica key present for ANT, or BT 4.0
 * hardware must be present for BTLE).</li>
 * </ol>
 * 
 * The standard discovery proceedure is as follows:
 * <ol>
 * <li>Implement the
 * WFHardwareConnectorDelegate::hardwareConnector:didDiscoverDevices:searchCompleted:
 * method</li>
 * 
 * <li>Invoke the WFHardwareConnector::discoverDevicesOfType:onNetwork:searchTimeout:
 * method with the desired parameters.</li>
 * 
 * <li>The WFHardwareConnectorDelegate::hardwareConnector:didDiscoverDevices:searchCompleted:
 * method will be invoked as soon as a matching device is discovered, for each
 * matching device discovered.  The <c>connectionParams</c> parameter will contain a
 * single <c>WFConnectionParams</c> instance, and the <c>bCompleted</c> parameter
 * will be <c>FALSE</c></li>.
 * 
 * <li>When the search timeout period has ellapsed, the
 * WFHardwareConnectorDelegate::hardwareConnector:didDiscoverDevices:searchCompleted:
 * method will be invoked with the <c>bCompleted</c> parameter set to <c>TRUE</c>.
 * The <c>connectionParams</c> parameter will contain a WFConnectionParams instance for
 * each matching device which was discovered.</li>
 * </ol>
 *
 * If a real-time update is desired, the
 * WFHardwareConnectorDelegate::hardwareConnector:didDiscoverDevices:searchCompleted:
 * may be processed for each device, as it is discovered.  If real-time updates are
 * not desired, wait to process
 * WFHardwareConnectorDelegate::hardwareConnector:didDiscoverDevices:searchCompleted:
 * until the <c>bCompleted</c> parameter is <c>TRUE</c>.  In this case, the
 * <c>connectionParams</c> parameter will contain all matching sensors discovered
 * during the discovery process. 
 *
 * @param eSensorType The ::WFSensorType_t to discover.  If this value is
 * ::WF_SENSORTYPE_NONE, a wildcard discovery is performed.
 *
 * @param eNetworkType The network on which to perform the discovery.  <b>THIS IS
 * A SINGLE NETWORK TYPE</b>, masking is not supported on this argument.
 * 
 * @param timeout The timeout for the discovery process, in seconds.  If this
 * value is <c>0</c> the discovery will continue indefinitely.  The device discovery
 * continues until the <c>timeout</c> period has elapsed, or the
 * WFHardwareConnector::cancelDiscoveryOnNetwork: method is invoked.
 *
 * @return <c>TRUE</c> if the discovery was successfully initiated, otherwise <c>FALSE</c>.
 * If a discovery is currently in progress on the specified network, or if any
 * connections exist on the network, or if the specified sensor type is not supported
 * on the specified network type, the return will be <c>FALSE</c>.
 */
- (BOOL)discoverDevicesOfType:(WFSensorType_t)eSensorType onNetwork:(WFNetworkType_t)eNetworkType searchTimeout:(NSTimeInterval)timeout DEPRECATED_MSG_ATTRIBUTE("Please see WFDiscoveryManager class");

/**
 * @deprecated This API is deprecated and should not be used. It is strongly encouged that all
 * developers move to using the WFDiscoveryManager API as this will be removed in the very
 * near future
 *
 * Cancels device discovery on the specified network.
 *
 *
 * @see WFDiscoveryManager
 *
 * @see WFHardwareConnector::discoverDevicesOfType:onNetwork:searchTimeout:
 *
 * @param eNetworkType The network on which to cancel discovery.
 *
 * @return An <c>NSSet</c> containing zero or more WFConnectionParams instances
 * representing all devices discovered up to the point the discovery was cancelled.
 */
- (NSSet*)cancelDiscoveryOnNetwork:(WFNetworkType_t)eNetworkType DEPRECATED_MSG_ATTRIBUTE("Please see WFDiscoveryManager class");
/**
 * Enables or disables the ANT Brige.
 *
 * The ANT Brige allows the WFHardwareConnector to connect to ANT devices
 * via the ANT radio on an ANT Brige enabled Wahoo Fitness BTLE device, such
 * as the RFLKT+.  This method will enable the ANT Bridge if it is availabe, or
 * when it becomes available.  If the bridge is immediately available when enabled,
 * it will be activated and used for ANT connections.  If the bridge is not
 * available when enabled, it will be configured and activated once it becomes
 * available.
 *
 * To avoid requiring the application to explicitly enable the ANT Bridge for
 * each session, the WFConnectorSettings::isAntBrigeAutoEnabled property may
 * be used.
 *
 * @note This method has no effect until an ANT Bridge enabled Wahoo Fitness
 * BTLE device is connected.
 *
 * @see WFHardwareConnectorDelegate::hardwareConnector:antBridgeStateChanged:onDevice:
 *
 * @param bEnable <c>TRUE</c> to enable the bridge, otherwise <c>FALSE</c>
 *
 * @return <c>TRUE</c> if the ANT Bridge is ready, otherwise <c>FALSE</c>.  The
 * ANT Bridged enabled state is set, regardless of the return value.  The return
 * serves primarily to indicate whether an active state change was required.
 */
- (BOOL)enableAntBridge:(BOOL)bEnable;

/**
 * Enables BTLE support (when available).
 *
 * @param bEnable <c>TRUE</c> to enable BTLE support, <c>FALSE</c> to disable.
 *
 * @note As of version 2.1.3, BTLE support is disabled by default.  This may
 * change in a future release.
 *
 * @return <c>TRUE</c> if the request was successful, otherwise <c>FALSE</c>.
 * When <c>bEnable</c> is <c>FALSE</c>, the return is <c>TRUE</c> only if BTLE
 * support is enabled at the time of the request.  When <c>bEnable</c> is
 * <c>TRUE</c>, the return is <c>TRUE</c> only if the device is capable of BTLE,
 * and BTLE is not enabled at the time of the request.
 */
- (BOOL)enableBTLE:(BOOL)bEnable;

/**
 * Enables BTLE support (when available), with the specified mode.
 *
 * @param bEnable <c>TRUE</c> to enable BTLE support, <c>FALSE</c> to disable.
 * @param bBondingMode <c>TRUE</c> to put the BTLE controller in bonding mode,
 * otherwise <c>FALSE</c>
 *
 * @note As of version 2.1.3, BTLE support is disabled by default.  This may
 * change in a future release.
 *
 *  As of iOS 5.1, there is a bug in CoreBluetooth affecting devices which
 * require bonding.  In normal operation, the Wahoo API will run CoreBluetooth
 * on an alternate dispatch queue.  This is the default state, and allows for
 * efficient simultaneous connections with multiple BTLE devices.  However, when
 * a device requires bonding, CoreBluetooth prompts the user with an alert
 * dispatched on the alternate queue, rather than the main run loop,
 * causing the UI to freeze.  To work around this issue, the WF API allows the
 * developer to put the BTLE controller into "bonding" mode.  In this mode,
 * the bonding prompt is dispatched on the main run loop, so that the
 * UI performs as expected.
 *
 * @note <b>BONDING MODE SHOULD ONLY BE USED WHEN IT IS NECESSARY TO BOND A DEVICE
 * WHICH HAS NOT YET BEEN BONDED.</b>  Using this mode for normal operation may lead
 * to unstable behavior.
 *
 * The mode may be switched between normal and bonding via this method.  If BTLE
 * is enabled when this method is invoked, and a different mode is specified, the
 * BTLE controller will be reset and then enabled in the specified mode.  The
 * application will receive the WFHardwareConnectorDelegate::hardwareConnector:stateChanged:
 * message twice when switching modes.  The first will be for the reset, the
 * ::WF_HWCONN_STATE_BT40_ENABLED flag will be cleared.  The second is when the
 * specified mode is enabled, the ::WF_HWCONN_STATE_BT40_ENABLED flag will be
 * set.
 *
 * @see WFHardwareConnector::enableBTLE:
 *
 * @return <c>TRUE</c> if the request was successful, otherwise <c>FALSE</c>.
 * When <c>bEnable</c> is <c>FALSE</c>, the return is <c>TRUE</c> only if BTLE
 * support is enabled at the time of the request.  When <c>bEnable</c> is
 * <c>TRUE</c>, the return is <c>TRUE</c> if the device is capable of BTLE,
 * and BTLE is not enabled at the time of the request.  If BTLE is enabled at
 * the time of the request, the return is <c>TRUE</c> if the specified mode is
 * different than the current mode, otherwise it is <c>FALSE</c>
 */
- (BOOL)enableBTLE:(BOOL)bEnable inBondingMode:(BOOL)bBondingMode;

/**
 * Returns an array of WFSensorConnection instances for all connected sensors
 * of the specified type.
 *
 * @param sensorType The type of sensor for which to get connections.  If this
 * parameter is <c>WF_SENSORTYPE_NONE</c>, all connections for any type are returned.
 *
 * @return An NSArray containing the matching WFSensorConnection instances.
 */
- (NSArray*)getSensorConnections:(WFSensorType_t)sensorType;

/**
 * Initializes a sensor connection request based on the specified parameters.
 *
 * This method will initiate a connection request based on the specified
 * parameters, and return a WFSensorConnection instance which may be used to
 * manage the connection.  The connection process is asynchronous.  Unless
 * a sensor specified in the parameters is already connected, it is likely
 * that the sensor will not have connected when this method returns.
 *
 * The WFSensorConnection may be used to monitor the connection status.  There
 * are two ways to be notified when the sensor connection is established.  The
 * WFHardwareConnectorDelegate::hardwareConnector:connectedSensor: is invoked
 * whenever any sensor connection is established.  When using this method, the
 * connectionInfo parameter must be checked to determine which sensor has
 * connected (if multiple connections were requested).  The other option is
 * to set the WFSensorConnection::delegate property on the instance returned.
 * The delegate will be alerted to any change in the connection status.
 *
 * The WFSensorConnection class is an abstract base class for sensor connection
 * management.  The actual object type returned will be determined by the
 * WFConnectionParams::sensorType value.  It is recommended that the instance
 * returned be cast as the specific type, and then cached as an instance
 * member used for managing the connection.  The WFSensorConnection is used
 * to retrieve data from the sensor, as well as to disconnect, or monitor the
 * state of the connection.
 *
 * A best-practices outline for connecting to a heart rate monitor follows:
 *
 * <ol>
 * <li>Create a WFConnectionParams instance and set the
 * WFConnectionParams::sensorType property to <c>WF_SENSORTYPE_HEARTRATE</c></li>
 *
 * <li>Create a WFDeviceParams instance and set its values to a previously
 * paired heart rate monitor (see the WFSensorConnection documentation for
 * information about initial pairing).</li>
 *
 * <li>Assign the WFDeviceParams instance to the WFConnectionParams::device1
 * property.</li>
 *
 * <li>Repeat the last two steps for any other previously paired heart rate
 * monitors (up to four).  Just use the device2, device3, or device4 property
 * instead of device1 specified in the last step.</li>
 *
 * <li>Invoke the WFHardwareConnector::requestSensorConnection: method.</li>
 *
 * <li>Cast the return value as a WFHeartrateConnection and cache as an
 * instance member.</li>
 *
 * <li>Set the WFSensorConnection::delegate property.</li>
 *
 * <li>Once the connection has been established, use the
 * WFHeartrateConnection::getHeartrateData method to retrieve a WFHeartrateData
 * instance.  This instance will contain the latest heart rate data.</li>
 *
 * <li>When the heart rate monitor is no longer needed, use the
 * WFSensorConnection::disconnect method to end the connection.</li>
 *
 * <li>After the connection is ended, the
 * WFSensorConnectionDelegate::connection:stateChanged: method will be invoked.
 * Check that the WFSensorConnection::isConnected is <c>FALSE</c>.  Release
 * the previously cached WFSensorConnection instance.</li>
 * </ol>
 *
 * @param params A WFConnectionParams instance which specifies the connection
 * parameters.
 *
 * @return If a device matching the connection parameters is already connected,
 * the existing WFSensorConnection instance is returned, and no new connection
 * is initialized.  If an error occurs (such as no unallocated communication
 * channels available), the return is <c>nil</c>.  Otherwise, the value returned
 * is a WFSensorConnection instance which may be used to manage the connection.
 */
- (WFSensorConnection*)requestSensorConnection:(WFConnectionParams*)params;

/**
 * Initializes a sensor connection request, with limited search range specified.
 *
 * @note Proximity is not supported on older fisica keys with the AP1 ANT chip.
 * Invoking this method with the older key present is equivilent to invoking
 * the WFHardwareConnector::requestSensorConnection: overload.
 *
 * @param params A WFConnectionParams instance which specifies the connection
 * parameters.
 *
 * @param proximity A WFProximityRange_t value which limits the proximity of the
 * search.  There are ten range levels available, with <c>WF_PROXIMITY_RANGE_1</c>
 * being the closest.  When <c>WF_PROXIMITY_RANGE_1</c> is specified, the device
 * must be very close to the fisica key for a connection to be established.  The
 * search distance increases with each range level.
 *
 * @see WFHardwareConnector::requestSensorConnection:
 *
 * @return If a device matching the connection parameters is already connected,
 * the existing WFSensorConnection instance is returned, and no new connection
 * is initialized.  If an error occurs (such as no unallocated communication
 * channels available), the return is <c>nil</c>.  Otherwise, the value returned
 * is a WFSensorConnection instance which may be used to manage the connection.
 */
- (WFSensorConnection*)requestSensorConnection:(WFConnectionParams*)params withProximity:(WFProximityRange_t)proximity;

/**
 * Initializes a sensor connection request, with limited search range specified.
 *
 * @note Proximity is not supported on older fisica keys with the AP1 ANT chip.
 * Invoking this method with the older key present is equivilent to invoking
 * the WFHardwareConnector::requestSensorConnection: overload.  The only difference
 * is that this overload has error handling.
 *
 * @param params A WFConnectionParams instance which specifies the connection
 * parameters.
 *
 * @param proximity A WFProximityRange_t value which limits the proximity of the
 * search.  There are ten range levels available, with <c>WF_PROXIMITY_RANGE_1</c>
 * being the closest.  When <c>WF_PROXIMITY_RANGE_1</c> is specified, the device
 * must be very close to the fisica key for a connection to be established.  The
 * search distance increases with each range level.
 *
 * @param ppError If an error occurs, upon returns contains an <c>NSError</c>
 * object that describes the problem.  Pass in <c>nil</c> if error handling is
 * not desired.
 * 
 * @see WFHardwareConnector::requestSensorConnection:
 *
 * @return If a device matching the connection parameters is already connected,
 * the existing WFSensorConnection instance is returned, and no new connection
 * is initialized.  If an error occurs (such as no unallocated communication
 * channels available), the return is <c>nil</c>.  Otherwise, the value returned
 * is a WFSensorConnection instance which may be used to manage the connection.
 */
- (WFSensorConnection*)requestSensorConnection:(WFConnectionParams*)params withProximity:(WFProximityRange_t)proximity error:(NSError**)ppError;

/**
 * Resets all sensor connections and sets the fisica device to IDLE mode.
 *
 * @note This method should be used with care, as it will reset all
 * active sensor connections.  To disconnect individual sensors, use the
 * WFSensorConnection::disconnect method instead.
 *
 * @see WFHardwareConnector::requestSensorConnection:
 * @see WFHardwareConnector::getSensorConnections:
 *
 * @return <c>TRUE</c> if all sensors were disconnected and the fisica device
 * set to IDLE mode, otherwise <c>FALSE</c>.
 */
- (BOOL)resetConnections;

/**
 * Resets the sample timer, based on the current sample rate.
 */
- (void)resetSampleTimer;

/**
 * Specifies whether the WFHardwareConnector should invoke the
 * WFHardwareConnectorDelegate::hardwareConnectorHasData method only when new
 * data is available.
 *
 * By default, the WFHardwareConnectorDelegate::hardwareConnectorHasData
 * method is invoked at the sample rate whether or not new data is present.
 * If the checkData value is <c>TRUE</c>, the delegate method will only be
 * invoked if there is new data present on at least one sensor.
 *
 * @param checkData <c>TRUE</c> if the
 * WFHardwareConnectorDelegate::hardwareConnectorHasData method should only
 * be invoked when new data is present.  Otherwise <c>FALSE</c>.
 */
- (void)setSampleTimerDataCheck:(BOOL)checkData;

// START Build-specific method declarations.
//
// Mac OSX-only methods.

#if !defined(WF_API_BUILD) || defined(MAC_OSX_BUILD)
/*  These methods are only applicable for the Mac OSX build. */

/**
 * Opens a connection to the USB ANT Stick.
 *
 * This method initiates a connection to the first USB device detected on the
 * system.  To select a specific device use WFHardwareConnector::openUSBSession:deviceNumber
 * instead.
 *
 * @note This method is only applicable for the Mac OSX build.
 *
 * @param ulBaudRate The baud rate for the connection.
 *
 * @return <c>TRUE</c> if the USB session was successfully started, otherwise <c>FALSE</c>.
 */
- (BOOL)openUSBSession:(ULONG)ulBaudRate;

/**
 * Opens a connection to the USB ANT Stick.
 *
 * @note This method is only applicable for the Mac OSX build.
 *
 * @param ulBaudRate The baud rate for the connection.
 * @param ucUSBDeviceNumber The zero-indexed USB device number.
 *
 * @return <c>TRUE</c> if the USB session was successfully started, otherwise <c>FALSE</c>.
 */
- (BOOL)openUSBSession:(ULONG)ulBaudRate deviceNumber:(UCHAR)ucUSBDeviceNumber;

- (void)closeSession;

#endif

// iOS-only methods.

#if !defined(WF_API_BUILD) || !defined(MAC_OSX_BUILD)
/* These methods are only applicable for the iOS build. */

/**
 * Prepares the WFHardwareConnector for background mode.
 *
 * @note This method has no effect when the device is running iOS 5.0 or greater.
 *
 * This method should be invoked when the application receives
 * notification that the app is entering background mode.  When the
 * application returns from background mode, the
 * WFHardwareConnector::returnFromBackground method should be invoked.
 */
- (void)prepareForBackground;

/**
 * Restores normal operation upon returning from background mode.
 *
 * @note This method has no effect when the device is running iOS 5.0 or greater.
 *
 * The WFHardwareConnector::prepareForBackground method should be invoked
 * when the application receives notification that the app is entering
 * background mode.  When the application returns from background mode, this
 * method should be invoked to restore normal operation.
 */
- (void)returnFromBackground;

#endif
// END Build-specific method declarations.

#pragma mark -
#pragma mark WFHardwareConnector Data Access Methods

/**
 * Resets all accumulated and calculated data for all sensor types.
 *
 * This method can be invoked at the beginning of a workout to put the sensors
 * in a known state.
 *
 * @return <c>TRUE</c> if the reset was successful, otherwise <c>FALSE</c>.
 */
- (BOOL)resetAllSensorData;


/**
 * Provides a URL which can be used to navigate the user of the app to the
 * official Wahoo Fitness Utility App, "Wahoo Utility".
 */
- (NSURL*)getWahooFinessUtilityAppUrl;


#pragma mark -
#pragma mark WFHardwareConnector Class Method Declarations

/**
 * Returns the singleton WFHardwareConnector instance.
 *
 * As of API version 2.0, the WFHardwareConnector is enforced as a singleton.
 * This method may be used to obtain a reference to that instance.  If the
 * instance does not yet exist when this method is invoked, it will be created.
 *
 * @return The WFHardwareConnector singleton instance.
 */
+ (WFHardwareConnector*)sharedConnector;

@end
