//
//  wf_fit_wahoo_segment_leaderboard_entry.h
//  FitSDK
//
//  Created by Antony Gardiner on 15/07/16.
//  Copyright © 2016 Wahoo Fitness. All rights reserved.
//

#ifndef fit_wahoo_segment_leaderboard_entry_h
#define fit_wahoo_segment_leaderboard_entry_h

// segment_leaderboard_entry message

#define FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_SIZE                                 16
#define FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_DEF_SIZE                             23
#define FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_NAME_COUNT                           1
#define FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_UUID_COUNT                           33

typedef struct
{
	FIT_UINT32                   group_primary_key; // Primary user ID of this leader
	FIT_UINT32                   activity_id; // ID of the activity associated with this leader time
	FIT_UINT32                   segment_time; // 1000 * s + 0, Segment Time (includes pauses)
	FIT_MESSAGE_INDEX            message_index; //
	FIT_STRING                   name[FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_NAME_COUNT]; // Friendly name assigned to leader
	FIT_SEGMENT_LEADERBOARD_TYPE type; // Leader classification
	FIT_STRING                   uuid[FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_UUID_COUNT];
} FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG;

typedef enum
{
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_FIELD_NUM_GROUP_PRIMARY_KEY = 2,
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_FIELD_NUM_ACTIVITY_ID       = 3,
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_FIELD_NUM_SEGMENT_TIME      = 4,
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_FIELD_NUM_MESSAGE_INDEX     = 254,
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_FIELD_NUM_NAME              = 0,
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_FIELD_NUM_TYPE              = 1,
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_FIELD_NUM_UUID              = 6,
} FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_FIELD_NUM;

typedef enum
{
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_GROUP_PRIMARY_KEY,
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_ACTIVITY_ID,
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_SEGMENT_TIME,
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_MESSAGE_INDEX,
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_NAME,
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_TYPE,
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_UUID,
	FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_FIELDS
} FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_FIELD;

typedef struct
{
	FIT_UINT8    reserved_1;
	FIT_UINT8    arch;
	FIT_MESG_NUM global_mesg_num;
	FIT_UINT8    num_fields;
	FIT_UINT8    fields[FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_WAHOO_SEGMENT_LEADERBOARD_ENTRY_MESG_DEF;


#endif /* fit_wahoo_segment_leaderboard_entry_h */
