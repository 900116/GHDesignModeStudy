//
//  GHBuilderModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHBuilderModel.h"

@implementation GHBurger

- (NSString *)name {
    return @"汉堡包";
}

- (CGFloat)price {
    return 15.0;
}

@end

@implementation GHMealCola

- (NSString *)name {
    return @"可乐";
}

- (CGFloat)price {
    return 7.0;
}

@end

@implementation GHChicken

- (NSString *)name {
    return @"炸鸡";
}

- (CGFloat)price {
    return 22.0;
}

@end


@interface GHMeal ()

//
@property (nonatomic,strong) NSMutableArray<id<GHIEatGoods>> *items;

@end

@implementation GHMeal

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.items = [NSMutableArray new];
    }
    return self;
}

- (CGFloat)getCost {
    CGFloat res = 0.0;
    for (id <GHIEatGoods> good in self.items) {
        res += good.price;
    }
    return res;
}

- (void)addItem:(id<GHIEatGoods>)item {
    [self.items addObject:item];
}

- (void)listItems {
    NSLog(@"");
    for (id <GHIEatGoods> good in self.items) {
        NSLog(@"|%@|￥%.1lf|",good.name,good.price);
    }
    NSLog(@"");
    NSLog(@"< 总价: ￥%.1lf >",[self getCost]);
    NSLog(@"");
}

@end


@implementation GHMealBuilder

- (GHMeal *)mealA {
    //套餐A添加一瓶可乐，一个汉堡包
    GHMeal *meal = [GHMeal new];
    [meal addItem:[GHMealCola new]];
    [meal addItem:[GHBurger new]];
    return meal;
}

- (GHMeal *)mealB {
    //套餐A添加一瓶可乐，一个汉堡包，一个炸鸡
    GHMeal *meal = [GHMeal new];
    [meal addItem:[GHMealCola new]];
    [meal addItem:[GHBurger new]];
    [meal addItem:[GHChicken new]];
    return meal;
}

@end
