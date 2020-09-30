//
//  BikeManager.swift
//  CycleChops2
//
//  Created by Toby Gundry on 29/9/20.
//  Copyright © 2020 Toby Gundry. All rights reserved.
//

import Foundation

class BikeManager : UIResponder, ObservableObject, WFBikeTrainerDelegate {
    let connector: WFHardwareConnector = WFHardwareConnector.shared()
    var discoveryManager: WFDiscoveryManager = WFDiscoveryManager()
    
    var powerConnection: WFSensorConnection?
    var bikeConnection: WFWahooBIKEConnection?
    
    @Published var wheelRevolutions : Double = 0.0
    @Published var formattedCadence : String = "--"
    @Published var isCoasting: Bool = false
    @Published var formattedDistance : String = "--"
    @Published var formattedSpeed: String = "--"
    
    override init() {
        super.init()
        connector.delegate = self
        connector.enableBTLE(true)
        connector.setSampleTimerDataCheck(false)
        discoveryManager.delegate = self
    }
    
    public func discoverAndConnect() {
        discoveryManager.discoverSensorTypes(nil, on: WF_NETWORKTYPE_BTLE)
    }
}

extension BikeManager : WFDiscoveryManagerDelegate {
    func discoveryManager(_ discoveryManager: WFDiscoveryManager!, didDiscoverDevice deviceInformation: WFDeviceInformation!) {
        let bikeConnParams : WFConnectionParams = deviceInformation.connectionParams(for: WF_SENSORTYPE_WAHOO_KICKR_BIKE)
        let powerConnParams : WFConnectionParams = deviceInformation.connectionParams(for: WF_SENSORTYPE_BIKE_POWER)
        
        // TODO: although for now only KICKR bike is supported, it may be safer to traverse the collection of
        // supported sensors and only connect if the device is in that list.
        // for _ in deviceInformation.supportedSensorTypes { }
        
        powerConnection = connector.requestSensorConnection(powerConnParams)
        powerConnection?.delegate = self
        
        bikeConnection = connector.requestSensorConnection(bikeConnParams) as? WFWahooBIKEConnection
        bikeConnection?.delegate = self
        
        discoveryManager.stopDiscovery()
    }
    
    func discoveryManager(_ discoveryManager: WFDiscoveryManager!, didLooseDevice deviceInformation: WFDeviceInformation!) {
        discoveryManager.discoverSensorTypes(nil, on: WF_NETWORKTYPE_BTLE)
    }
}

extension BikeManager : WFSensorConnectionDelegate {
    func connection(_ connectionInfo: WFSensorConnection!, stateChanged connState: WFSensorConnectionStatus_t) {
        // TODO: manage reconnection of sensors within the hardware connector
    }
    
    func connectionDidTimeout(_ connectionInfo: WFSensorConnection!) {
        // TODO: Manage reconnection/discovery
    }
}

extension BikeManager : WFHardwareConnectorDelegate {
    func hardwareConnectorHasData() {
        guard powerConnection != nil && powerConnection!.isConnected && powerConnection!.hasData() else {
            return
        }
        
        if let powerData = powerConnection!.getData() as? WFBikePowerData {
            wheelRevolutions = powerData.wheelRevolutions
            formattedCadence = powerData.formattedCadence(true)
            formattedDistance = powerData.formattedDistance(true)
            formattedSpeed = powerData.formattedSpeed(true)
            isCoasting = powerData.isCoasting()
            print("instant power: ", powerData.instantPower)
            print("instant cadence: ", powerData.instantCadence)
            print("instant wheel RPM: ", powerData.instantWheelRPM)
            print("wheel revolutions: ", powerData.wheelRevolutions)
        }
    }

    func hardwareConnector(_ hwConnector: WFHardwareConnector!, connectedSensor connectionInfo: WFSensorConnection!) {
        hwConnector.resetSampleTimer()
    }
    
    func hardwareConnector(_ hwConnector: WFHardwareConnector!, stateChanged currentState: WFHardwareConnectorState_t) {
        // TODO: update UI
    }
}
