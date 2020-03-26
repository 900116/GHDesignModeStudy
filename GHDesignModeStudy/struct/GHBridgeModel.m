//
//  GHBirdgeModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHBridgeModel.h"

@implementation GHDrawStyle1

- (void)drawCircle:(CGFloat)x y:(CGFloat)y radius:(CGFloat)radius {
    NSLog(@"风格1");
}

@end

@implementation GHDrawStyle2

- (void)drawCircle:(CGFloat)x y:(CGFloat)y radius:(CGFloat)radius {
    NSLog(@"风格2");
}

@end


@implementation GHShape

- (void)draw {
    //override me
}

@end


@implementation GHCircle

- (void)draw {
    [self.drawer drawCircle:self.x y:self.y radius:self.radius];
}

@end

