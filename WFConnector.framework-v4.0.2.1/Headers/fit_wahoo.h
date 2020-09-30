//
//  wf_fit_custom.h
//  FitSDK
//
//  Created by Antony Gardiner on 11/05/16.
//  Copyright © 2016 Wahoo Fitness. All rights reserved.
//

#ifndef fit_custom_h
#define fit_custom_h

#include <stdio.h>

// Custom Wahoo specific messages
#define FIT_MESG_NUM_WAHOO_PAUSED_RECORD                                        ((FIT_MESG_NUM)0xFF00)
#define FIT_MESG_NUM_WAHOO_MESG_ID                                              ((FIT_MESG_NUM)0xFF01)
#define FIT_MESG_NUM_WAHOO_SEGMENT_LEADERBOARD_ENTRY                            ((FIT_MESG_NUM)0xFF02)

// This is used in the exmaple.h file to include Wahoo custom messages in the file file.
#define FIT_WAHOO_CUSTOM_MESG_ENUMS     FIT_MESG_WAHOO_PAUSED_RECORD,\
                                        FIT_MESG_WAHOO_ID,\
                                        FIT_MESG_WAHOO_SEGMENT_LEADERBOARD_ENTRY


#endif /* wf_fit_custom_h */
