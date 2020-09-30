//
//  WFDisplayElementGroup.h
//  WFConnector
//
//  Created by Murray Hughes on 17/12/12.
//  Copyright (c) 2012 Wahoo Fitness. All rights reserved.
//

#import "WFDisplayElement.h"

@interface WFDisplayElementGroup : WFDisplayElement
{
    NSMutableArray* _mutableElements;
    NSString* _groupId;
}


// Array of dictionaries representing elements.
@property (weak, nonatomic, readonly) NSArray* elements;
@property (nonatomic, strong) NSString* groupId;

- (void) addElement:(WFDisplayElement*) element;
- (void) removeElement:(WFDisplayElement*) element;
- (void) removeAllElements;


@end
