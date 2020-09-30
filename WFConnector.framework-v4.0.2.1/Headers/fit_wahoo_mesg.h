//
//  wf_fit_wahoo_mesg.h
//  FitSDK
//
//  Created by Antony Gardiner on 15/07/16.
//  Copyright © 2016 Wahoo Fitness. All rights reserved.
//

#ifndef fit_wahoo_mesg_h
#define fit_wahoo_mesg_h

#include "fit_sdk/fit.h"
#include "fit_sdk/fit_product.h"

// Custom WAHOO ID message

#define FIT_WAHOO_ID_MESG_SIZE                                                    26
#define FIT_WAHOO_ID_MESG_DEF_SIZE                                                14
#define FIT_WAHOO_ID_MESG_DEIVCE_ID_SIZE                                          20

typedef struct
{
	FIT_STRING device_id[FIT_WAHOO_ID_MESG_DEIVCE_ID_SIZE]; // ID of the device
	FIT_SINT32 workout_id;
	FIT_UINT16 std_workout_type;

} FIT_WAHOO_ID_MESG;

typedef enum
{
	FIT_WAHOO_ID_FIELD_NUM_DEVICE_ID        = 0,
	FIT_WAHOO_ID_FIELD_NUM_WORKOUT_ID       = 1,
	FIT_WAHOO_ID_FIELD_NUM_STD_WORKOUT_TYPE = 2,

} FIT_WAHOO_ID_FIELD_NUM;

typedef enum
{
	FIT_WAHOO_ID_MESG_DEVICE_ID,
	FIT_WAHOO_ID_MESG_WORKOUT_ID,
	FIT_WAHOO_ID_MESG_STD_WORKOUT_TYPE,
	FIT_WAHOO_ID_MESG_FIELDS

} FIT_WAHOO_ID_MESG_FIELD;

typedef struct
{
	FIT_UINT8    reserved_1;
	FIT_UINT8    arch;
	FIT_MESG_NUM global_mesg_num;
	FIT_UINT8    num_fields;
	FIT_UINT8    fields[FIT_WAHOO_ID_MESG_FIELDS * FIT_FIELD_DEF_SIZE];

} FIT_WAHOO_ID_MESG_DEF;

#endif /* fit_wahoo_mesg_h */
