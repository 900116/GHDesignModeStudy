//
//  GHInterceptingFilterModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHInterceptingFilterModel.h"

@implementation GHAuthenFilter

- (void)execute:(NSString *)request {
    NSLog(@"校验相关");
}

@end

@implementation GHDebugFilter

- (void)execute:(NSString *)request {
    NSLog(@"Debug info 记录");
}

@end


@implementation GHTarget

- (void)execute:(NSString *)request {
    NSLog(@"真正的请求");
}

@end

@interface GHFilterChain ()

//
@property (nonatomic,strong) NSMutableArray<id<GHIFFilter>> *filters;

@end

@implementation GHFilterChain
- (instancetype)init
{
    self = [super init];
    if (self) {
        self.filters = [NSMutableArray new];
    }
    return self;
}

- (void)addFilter:(id<GHIFFilter>)filter {
    [self.filters addObject:filter];
}

- (void)execute: (NSString *)request {
    [self.filters enumerateObjectsUsingBlock:^(id<GHIFFilter>  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        [obj execute:request];
    }];
    [self.target execute:request];
}

@end

@implementation GHFilerManager

- (instancetype)initWithTarget:(GHTarget *)target
{
    self = [super init];
    if (self) {
        self.chain = [GHFilterChain new];
        self.chain.target = target;
    }
    return self;
}

- (void)filterRequest: (NSString *)request {
    [self.chain execute:request];
}

- (void)addFilter:(id<GHIFFilter>)filter {
    [self.chain addFilter:filter];
}

@end

@implementation GHIFClient

- (void)sendRequest:(NSString *)request {
    [self.manager filterRequest:request];
}

@end
