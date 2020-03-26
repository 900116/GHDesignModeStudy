//
//  GHSingletonModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHSingletonModel.h"

@implementation GHSingletonModel

+ (instancetype)getInstance {
    static dispatch_once_t onceToken;
    static GHSingletonModel *model = nil;
    dispatch_once(&onceToken, ^{
        model = [self new];
    });
    return model;
}

@end
