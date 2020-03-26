//
//  GHBusinessDelegateModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHBusinessDelegateModel.h"

@implementation GHBusinessServiceA

- (void)doProcessing {
    NSLog(@"服务A");
}

@end

@implementation GHBusinessServiceB

- (void)doProcessing {
    NSLog(@"服务B");
}

@end

@implementation GHBusinessLookUp

- (id<GHBusinessService>)serviceByType:(NSString *)type {
    if ([type isEqualToString:@"A"]) {
        return [GHBusinessServiceA new];
    }
    if ([type isEqualToString:@"B"]) {
        return [GHBusinessServiceB new];
    }
    return nil;
}

@end

@interface GHBusinessDelegate ()

//
@property (nonatomic,strong) GHBusinessLookUp *lookup;

@end

@implementation GHBusinessDelegate

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.lookup = [GHBusinessLookUp new];
    }
    return self;
}

- (void)doTask {
    id <GHBusinessService> service = [self.lookup serviceByType:self.serviceType];
    [service doProcessing];
}

@end

@implementation GHClient

- (void)doTask {
    [self.service doTask];
}

@end
