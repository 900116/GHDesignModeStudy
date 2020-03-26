//
//  GHFactoryModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHFactoryModel.h"

@implementation GHCola

- (void)drink {
    NSLog(@"喝可乐");
}

@end

@implementation GHJuice

- (void)drink {
    NSLog(@"喝果汁");
}

@end

@implementation GHBeer

- (void)drink {
    NSLog(@"喝啤酒");
}

@end

@implementation GHVEM

- (id<GHIDrink>)buyDrink:(CGFloat)money{
    if (money == 3) {
        return [GHJuice new];
    }
    if (money == 5) {
        return [GHCola new];
    }
    if (money == 10) {
        return [GHBeer new];
    }
    return nil;
}

@end
