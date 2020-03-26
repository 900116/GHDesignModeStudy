//
//  GHComposeModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHComposeModel.h"

@implementation GHEmployee

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.subordinates = [NSMutableArray new];
    }
    return self;
}

- (void)manage:(GHEmployee *)employee {
    [self.subordinates addObject:employee];
}

- (void)removeManage:(GHEmployee *)employee {
    [self.subordinates removeObject:employee];
}

@end
