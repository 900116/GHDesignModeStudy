//
//  GHAbstractFactoryModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHAbstractFactoryModel.h"

@implementation GHPepsiCola

- (void)drink {
    NSLog(@"喝百事可乐");
}

@end

@implementation GHPepsiJuice

- (void)drink {
    NSLog(@"喝百事果汁");
}

@end

@implementation GHPepsiBeer

- (void)drink {
    NSLog(@"喝百事啤酒");
}


@end

@implementation GHPepsiVEM

- (id<GHIDrink>)buyDrink:(CGFloat)money {
    if (money == 3) {
        return [GHPepsiJuice new];
    }
    if (money == 5) {
        return [GHPepsiCola new];
    }
    if (money == 10) {
        return [GHPepsiBeer new];
    }
    return nil;
}

@end

@implementation GHCocaCola

- (void)drink {
    NSLog(@"喝可口可乐");
}

@end

@implementation GHCocaJuice

- (void)drink {
    NSLog(@"喝可口果汁");
}


@end

@implementation GHCocaBeer

- (void)drink {
    NSLog(@"喝可口啤酒");
}


@end

@implementation GHCocaVEM

- (id<GHIDrink>)buyDrink:(CGFloat)money {
    if (money == 3) {
        return [GHCocaJuice new];
    }
    if (money == 5) {
        return [GHCocaCola new];
    }
    if (money == 10) {
        return [GHCocaBeer new];
    }
    return nil;
}

@end

@implementation GHAbstractVEM

- (id<GHIVEM>)vemForBrand:(NSString *)brand {
    if ([brand isEqualToString:@"Coca"]) {
        return [GHCocaVEM new];
    }
    if ([brand isEqualToString:@"Pepsi"]) {
        return [GHPepsiVEM new];
    }
    return nil;
}

@end
