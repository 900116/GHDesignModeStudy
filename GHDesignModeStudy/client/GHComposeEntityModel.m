//
//  GHComposeEntityModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHComposeEntityModel.h"

@implementation GHObjectA

@end

@implementation GHObjectB

@end

@interface GHTupleObject ()

//
@property (nonatomic,strong) GHObjectA *a;
@property (nonatomic,strong) GHObjectB *b;

@end

@implementation GHTupleObject

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.a = [GHObjectA new];
        self.b = [GHObjectB new];
    }
    return self;
}

- (void)setData:(NSString *)data1 data2:(NSString *)data2 {
    self.a.data = data1;
    self.b.data = data2;
}

- (NSArray<NSString *> *)getData {
    return @[self.a.data,self.b.data];
}

@end

@interface GHCompositeEntity ()

//
@property (nonatomic,strong) GHTupleObject *obj;

@end

@implementation GHCompositeEntity

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.obj = [GHTupleObject new];
    }
    return self;
}

- (void)setData:(NSString *)data1 data2:(NSString *)data2 {
    [self.obj setData:data1 data2:data2];
}

- (NSArray<NSString *> *)getData {
    return [self.obj getData];
}

@end

@interface GHComposeClient ()

//
@property (nonatomic,strong) GHCompositeEntity *obj;

@end

@implementation GHComposeClient

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.obj = [GHCompositeEntity new];
    }
    return self;
}

- (void)setData:(NSString *)data1 data2:(NSString *)data2 {
    [self.obj setData:data1 data2:data2];
}

- (void)printData {
    NSLog(@"-------------------");
    [[self.obj getData] enumerateObjectsUsingBlock:^(NSString * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        NSLog(@"data:%@",obj);
    }];
}

@end

