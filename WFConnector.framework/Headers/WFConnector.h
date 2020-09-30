//
//  WFConnector.h
//  WFConnector
//
//  Created by Michael Moore on 9/1/11.
//  Copyright 2011 Wahoo Fitness. All rights reserved.
//

//#import <WFConnector/common_types.h>
#import <WFConnector/types.h>

#import <WFConnector/hardware_connector_types.h>
#import <WFConnector/WFDisplayElementBitmap+WFUIKit.h>
#import <WFConnector/WFDisplayPageView.h>
#import <WFConnector/wf_ant_types.h>
#import <WFConnector/wf_btle_types.h>
#import <WFConnector/WFANTWeightScaleData.h>
#import <WFConnector/WFBikeCadenceConnection.h>
#import <WFConnector/WFBikeCadenceData.h>
#import <WFConnector/WFBikeCadenceRawData.h>
#import <WFConnector/WFBikePowerConnection.h>
#import <WFConnector/WFBikePowerCrankTorqueData.h>
#import <WFConnector/WFBikePowerCTFData.h>
#import <WFConnector/WFBikePowerData.h>
#import <WFConnector/WFBikePowerPowerOnlyData.h>
#import <WFConnector/WFBikePowerRawData.h>
#import <WFConnector/WFBikePowerWheelTorqueData.h>
#import <WFConnector/WFBikeSpeedCadenceConnection.h>
#import <WFConnector/WFBikeSpeedCadenceData.h>
#import <WFConnector/WFBikeSpeedCadenceDelegate.h>
#import <WFConnector/WFBikeSpeedCadenceRawData.h>
#import <WFConnector/WFBikeSpeedConnection.h>
#import <WFConnector/WFBikeSpeedData.h>
#import <WFConnector/WFBikeSpeedRawData.h>
#import <WFConnector/WFBloodPressureConnection.h>
#import <WFConnector/WFBloodPressureData.h>
#import <WFConnector/WFBTLEBikePowerData.h>
#import <WFConnector/WFBTLEBikeSpeedCadenceData.h>
#import <WFConnector/WFBTLECommonData.h>
#import <WFConnector/WFBTLEFootpodData.h>
#import <WFConnector/WFBTLEGlucoseConnection.h>
#import <WFConnector/WFBTLEGlucoseData.h>
#import <WFConnector/WFBTLEHeartrateData.h>
#import <WFConnector/WFBTLEWeightScaleData.h>
#import <WFConnector/WFBTLEWeightScaleUser.h>
#import <WFConnector/WFCalorieData.h>
#import <WFConnector/WFCalorimeterConnection.h>
#import <WFConnector/WFCommonData.h>
#import <WFConnector/WFConnectionParams.h>
#import <WFConnector/WFConnectorSettings.h>
#import <WFConnector/WFDeviceParams.h>
#import <WFConnector/WFDisplayConnection.h>
#import <WFConnector/WFDisplayConnectionDelegate.h>
#import <WFConnector/WFWahooRawSensorConnection.h>
#import <WFConnector/WFWahooGymConnectConnection.h>
#import <WFConnector/WFFisicaInfo.h>
#import <WFConnector/WFFitnessEquipmentConnection.h>
#import <WFConnector/WFHeadwindConfigData.h>
#import <WFConnector/WFWahooAdvancedFitnessEquipmentControlConnection.h>
#import <WFConnector/WFWahooAdvancedFitnessEquipmentControlDelegate.h>
#import <WFConnector/WFWahooHeadwindConnection.h>
#import <WFConnector/WFWahooHeadwindControlDelegate.h>
#import <WFConnector/wf_wahoo_headwind_types.h>
#import <WFConnector/WFWahooBIKEConnection.h>
#import <WFConnector/WFWahooBIKEControlDelegate.h>
#import <WFConnector/WFFitnessEquipmentData.h>
#import <WFConnector/WFFitnessEquipmentRawData.h>
#import <WFConnector/WFFootpodConnection.h>
#import <WFConnector/WFFootpodData.h>
#import <WFConnector/WFFootpodRawData.h>
#import <WFConnector/WFGeoCacheConnection.h>
#import <WFConnector/WFGeoCacheData.h>
#import <WFConnector/WFGeoCacheProgramData.h>
#import <WFConnector/WFGlucoseConnection.h>
#import <WFConnector/WFGlucoseData.h>
#import <WFConnector/WFHardwareConnector.h>
#import <WFConnector/WFHardwareConnectorDelegate.h>
#import <WFConnector/WFHealthThermometerConnection.h>
#import <WFConnector/WFHealthThermometerData.h>
#import <WFConnector/WFHeartrateConnection.h>
#import <WFConnector/WFHeartrateData.h>
#import <WFConnector/WFHeartrateRawData.h>
#import <WFConnector/WFMultiSportConnection.h>
#import <WFConnector/WFOdometerHistory.h>
#import <WFConnector/WFProximityConnection.h>
#import <WFConnector/WFProximityData.h>
#import <WFConnector/WFSensorConnection.h>
#import <WFConnector/WFSensorConnectionDelegate.h>
#import <WFConnector/WFSensorData.h>
#import <WFConnector/WFWahooCSCData.h>
#import <WFConnector/WFWeightScaleConnection.h>
#import <WFConnector/WFWeightScaleData.h>
#import <WFConnector/WFANTWeightScaleData.h>

#import <WFConnector/WFDiscoveryManager.h>
#import <WFConnector/WFDeviceInformation.h>



#import <WFConnector/WFDisplayTypes.h>
#import <WFConnector/WFDisplayConfiguration.h>
#import <WFConnector/WFDisplayPage.h>
#import <WFConnector/WFDisplayElement.h>
#import <WFConnector/WFDisplayElementRect.h>
#import <WFConnector/WFDisplayElementString.h>
#import <WFConnector/WFDisplayElementBitmap.h>
#import <WFConnector/WFDisplayElementGroup.h>
#import <WFConnector/WFDisplaySound.h>
#import <WFConnector/WFDisplayMemoryCalculator.h>


#import <WFConnector/WFWahooMotionAnalysisCalibrator.h>
#import <WFConnector/WFWahooMotionAnalysisCalibratorRunning.h>
#import <WFConnector/WFWahooMotionAnalysisCalibratorXCounting.h>
#import <WFConnector/WFWahooMotionAnalysisCalibratorElliptical.h>
#import <WFConnector/WFWahooMotionAnalysisCalibratorDelegate.h>
#import <WFConnector/WFWahooMotionAnalysisCalibrationProfile.h>
#import <WFConnector/WFWahooMotionAnalysisCalibrationProfileRunning.h>
#import <WFConnector/WFWahooMotionAnalysisCalibrationProfileXCounting.h>
#import <WFConnector/WFWahooMotionAnalysisCalibrationProfileElliptical.h>

#import <WFConnector/WFBikeTrainerSpindownCalibrator.h>

#import <WFConnector/wf_wahoo_advanced_fitness_equipment_control_types.h>



