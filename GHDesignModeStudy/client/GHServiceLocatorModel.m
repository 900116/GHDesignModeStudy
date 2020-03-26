//
//  GHServiceLocatorModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHServiceLocatorModel.h"

@implementation GHISLServiceA

- (NSString *)name {
    return @"A";
}

- (void)execute {
    NSLog(@"ServiceA execute");
}

@end

@implementation GHISLServiceB

- (NSString *)name {
    return @"B";
}

- (void)execute {
    NSLog(@"ServiceB execute");
}

@end

@implementation GHInitialContext

- (id)lookup:(NSString *)name {
    if ([name isEqualToString:@"A"]) {
        NSLog(@"new serviceA");
        return [GHISLServiceA new];
    }
    if ([name isEqualToString:@"B"]) {
        NSLog(@"new serviceB");
        return [GHISLServiceB new];
    }
    return nil;
}

@end

@interface GHSLCache ()

//
@property (nonatomic,strong) NSMutableDictionary<NSString*,id<GHISLService>> *services;

@end

@implementation GHSLCache

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.services = [NSMutableDictionary new];
    }
    return self;
}

- (id<GHISLService>)getService:(NSString *)serviceName {
    return self.services[serviceName];
}

- (void)addService:(id<GHISLService>)service {
    self.services[service.name] = service;
}

@end

@implementation GHServiceLocator

+ (id<GHISLService>)getService:(NSString *)serviceName {
    static GHSLCache *cache = nil;
    if (!cache) {
        cache = [GHSLCache new];
    }
    id<GHISLService> service = [cache getService:serviceName];
    if (service) {
        return service;
    }
    GHInitialContext *context = [GHInitialContext new];
    service = [context lookup:serviceName];
    [cache addService:service];
    return service;
}

@end
