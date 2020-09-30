//
//  wf_wahoo_headwind_types_stub.h
//  WFConnector
//
//  Created by Patrick Bush on 5/22/18.
//  Copyright © 2018 Wahoo Fitness. All rights reserved.
//

#ifndef wf_wahoo_headwind_types_h
#define wf_wahoo_headwind_types_h

typedef NS_ENUM(NSInteger, WFHeadwindOperatingMode_e)
{
    WF_HEADWIND_OPERATING_MODE_ERROR           = 0,
    WF_HEADWIND_OPERATING_MODE_POWERED_OFF,
    WF_HEADWIND_OPERATING_MODE_HEARTRATE,
    WF_HEADWIND_OPERATING_MODE_SPEED,
    WF_HEADWIND_OPERATING_MODE_DIRECT,
	WF_HEADWIND_OPERATING_MODE_STANDBY
};

#endif /* wf_wahoo_headwind_types_h */
