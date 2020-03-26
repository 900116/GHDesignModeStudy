//
//  GHDecoratorModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHDecoratorModel.h"

@implementation GHNetWorkManager

- (void)sendRequest: (NSDictionary *)params {
    NSLog(@"发送请求");
}

@end

@interface GHNetWorkLoggerManager ()
//
@property (nonatomic,strong) GHNetWorkManager *innerManager;

@end


@implementation GHNetWorkLoggerManager

- (instancetype)initWithNetWorkManager:(GHNetWorkManager *)netWorkManager {
    self = [super init];
    if (self) {
        self.innerManager = netWorkManager;
    }
    return self;
}

- (void)sendRequest:(NSDictionary *)params {
    NSLog(@"打印参数：%@",params);
    [self.innerManager sendRequest:params];
}

@end

@interface GHNetWorkLoadingManager ()
//
@property (nonatomic,strong) GHNetWorkManager *innerManager;

@end


@implementation GHNetWorkLoadingManager

- (instancetype)initWithNetWorkManager:(GHNetWorkManager *)netWorkManager {
    self = [super init];
    if (self) {
        self.innerManager = netWorkManager;
    }
    return self;
}

- (void)sendRequest:(NSDictionary *)params {
    NSLog(@"loading start");
    [self.innerManager sendRequest:params];
    NSLog(@"loading end");
}


@end
