//
//  GHCommandModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHCommandModel.h"


@implementation GHNetWorkComponent

- (void)loadComphonet {
    NSLog(@"加载网络组件");
}

- (void)destoryComphoent {
    NSLog(@"销毁网络组件");
}

@end

@implementation GHDBComponent

- (void)loadComphonet {
    NSLog(@"加载数据库组件");
}

- (void)destoryComphoent {
    NSLog(@"销毁数据库组件");
}

@end

@implementation GHNotificationComponent

- (void)loadComphonet {
    NSLog(@"加载通知库组件");
}

- (void)destoryComphoent {
    NSLog(@"销毁通知组件");
}

@end

@interface GHDBComphonetManager ()

//
@property (nonatomic,strong) NSMutableArray<id<GHComponent>> * components;

@end

@implementation GHDBComphonetManager

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.components = [NSMutableArray new];
    }
    return self;
}

- (void)addComponent:(id<GHComponent>)component {
    [self.components addObject:component];
}

- (void)blkAll:(void(^)(id<GHComponent>))executeBlk {
    [self.components enumerateObjectsUsingBlock:^(id<GHComponent>  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        executeBlk(obj);
    }];
}

- (void)loadAllComponent {
    [self blkAll:^(id<GHComponent> component) {
        [component loadComphonet];
    }];
}

- (void)destoryAllComponent {
    [self blkAll:^(id<GHComponent> component) {
        [component destoryComphoent];
    }];
}

@end
