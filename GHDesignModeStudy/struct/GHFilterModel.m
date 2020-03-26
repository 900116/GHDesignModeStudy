//
//  GHFilterModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHFilterModel.h"

@interface NSArray (GHFilter)
@end

@implementation NSArray (GHFilter)

- (NSArray *)filterWithBlk: (BOOL(^)(id)) blk{
    NSMutableArray *res = [NSMutableArray new];
    [self enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if (blk(obj)) {
            [res addObject:obj];
        }
    }];
    return [res copy];
}

@end

@implementation GHPerson
@end

@implementation GHMalePersonFilter

- (NSArray <GHPerson *> *)filter:(NSArray <GHPerson *> *)persons {
    return [persons filterWithBlk:^BOOL(GHPerson *person) {
        return person.gender == YES;
    }];
}

@end

@implementation GHFemalePersonFilter

- (NSArray <GHPerson *> *)filter:(NSArray <GHPerson *> *)persons {
    return [persons filterWithBlk:^BOOL(GHPerson *person) {
        return person.gender == NO;
    }];
}

@end

@implementation GHSinglePersonFilter

- (NSArray <GHPerson *> *)filter:(NSArray <GHPerson *> *)persons  {
    return [persons filterWithBlk:^BOOL(GHPerson *person) {
        return person.married == NO;
    }];
}

@end

@implementation GHMarriedPersonFilter

- (NSArray <GHPerson *> *)filter:(NSArray <GHPerson *> *)persons  {
    return [persons filterWithBlk:^BOOL(GHPerson *person) {
        return person.married == YES;
    }];
}

@end

@interface GHAndFilter ()

//
@property (nonatomic,strong) id <GHPersonFilter> f1;
@property (nonatomic,strong) id <GHPersonFilter> f2;

@end


@implementation GHAndFilter


+ (instancetype)and:(id<GHPersonFilter>)f1 f2:(id<GHPersonFilter>)f2 {
    GHAndFilter *res = [GHAndFilter new];
    res.f1 = f1;
    res.f2 = f2;
    return res;
}

- (NSArray <GHPerson *> *)filter:(NSArray <GHPerson *> *)persons  {
    NSMutableArray *res = [NSMutableArray new];
    NSArray *filter1 = [self.f1 filter:persons];
    NSArray *filter2 = [self.f2 filter:persons];
    for (GHPerson *person in filter1) {
        if ([filter2 containsObject:person]) {
            [res addObject:person];
        }
    }
    return [res copy];
}

@end

@interface GHOrFilter ()

//
@property (nonatomic,strong) id <GHPersonFilter> f1;
@property (nonatomic,strong) id <GHPersonFilter> f2;

@end

@implementation GHOrFilter

+ (instancetype)or:(id<GHPersonFilter>)f1 f2:(id<GHPersonFilter>)f2 {
    GHOrFilter *res = [GHOrFilter new];
    res.f1 = f1;
    res.f2 = f2;
    return res;
}

- (NSArray <GHPerson *> *)filter:(NSArray <GHPerson *> *)persons  {
    NSMutableArray *res = [NSMutableArray new];
    NSArray *filter1 = [self.f1 filter:persons];
    NSArray *filter2 = [self.f2 filter:persons];
    [res addObjectsFromArray:filter1];
    for (GHPerson *person in filter2) {
        if (![filter1 containsObject:person]) {
            [res addObject:person];
        }
    }
    return [res copy];
}

@end
