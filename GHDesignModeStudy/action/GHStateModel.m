//
//  GHStateModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHStateModel.h"

@implementation GHWalkState

- (void)run:(id<GHIAnimationPerson>)person {
    person.state = self;
    [person runWalkAnimation];
}

@end

@implementation GHSleepState

- (void)run:(id<GHIAnimationPerson>)person {
    person.state = self;
    [person runSleepAnimation];
}

@end

@implementation GHAnimationPerson

- (void)runSleepAnimation {
    NSLog(@"播放睡觉动画");
}

- (void)runWalkAnimation {
    NSLog(@"播放走路动画");
}

@end
