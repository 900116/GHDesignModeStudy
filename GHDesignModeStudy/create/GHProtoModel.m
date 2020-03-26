//
//  GHProtoModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHProtoModel.h"

@implementation GHBigResourceData

- (id<GHICloneable>)clone {
    GHBigResourceData *data = [self.class alloc];
    data.loadData = self.loadData;
    data.sid = self.sid;
    return data;
}

- (NSString *)type {
    return nil;
}

@end

@implementation GHBigResourceDataA

- (instancetype)init
{
    self = [super init];
    if (self) {
        sleep(3);
        self.loadData = @"someDataA";
    }
    return self;
}

- (NSString *)type {
    return @"A";
}


@end

@implementation GHBigResourceDataB

- (instancetype)init
{
    self = [super init];
    if (self) {
        sleep(2);
        self.loadData = @"someDataB";
    }
    return self;
}


- (NSString *)type {
    return @"B";
}

@end

@interface GHBigResourceDataCache ()

//
@property (nonatomic,strong) NSMutableDictionary<NSString *,GHBigResourceData *> *resourceCache;

@end

@implementation GHBigResourceDataCache

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.resourceCache = [NSMutableDictionary new];
    }
    return self;
}

- (void)loadCache {
    GHBigResourceData *data = [GHBigResourceDataA new];
    data.sid = @"1";
    self.resourceCache[data.sid] = data;
    
    GHBigResourceData *data2 = [GHBigResourceDataB new];
    data2.sid = @"2";
    self.resourceCache[data2.sid] = data2;
}

- (GHBigResourceData *)getObj:(NSString *)key {
    GHBigResourceData *obj = self.resourceCache[key];
    return [obj clone];
}

@end
