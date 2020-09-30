//
//  wf_wahoo_advanced_fitness_equipment_control_types_stub.h
//  WFConnector
//
//  Created by Mark Snaterse on 25/01/2018.
//  Copyright © 2018 Wahoo Fitness. All rights reserved.
//

#ifndef wf_wahoo_advanced_fitness_equipment_control_types_stub_h
#define wf_wahoo_advanced_fitness_equipment_control_types_stub_h

/**
 * Wahoo Advanced Fitness Equipment Control Point
 *
 * Describes the tilt mode the advanced fitness equipment is currently using
 */
typedef enum
{
    WF_WAHOO_ADVANCED_FITNES_EQUIPMENT_CONTROL_TILT_MODE_UNLOCKED           = 0,
    WF_WAHOO_ADVANCED_FITNES_EQUIPMENT_CONTROL_TILT_MODE_LOCKED             = 1,
    WF_WAHOO_ADVANCED_FITNES_EQUIPMENT_CONTROL_TILT_MODE_TILT_UNAVAILABLE   = 255,
} WFWahooAdvancedFitnessEquipmentControlTiltMode_t;

#endif /* wf_wahoo_advanced_fitness_equipment_control_types_stub_h */
