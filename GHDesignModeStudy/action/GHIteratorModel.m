//
//  GHIteratorModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//


#import "GHIteratorModel.h"


@interface GHArray ()

//
@property (nonatomic,strong) NSArray *arr;
- (NSUInteger)count;

@end

@interface GHArrayIterator ()

//
@property (nonatomic,assign) NSUInteger idx;
@property (nonatomic,weak) GHArray *array;

@end

@implementation GHArrayIterator

- (BOOL)hasNext {
    if (self.idx < self.array.count) {
        return YES;
    }
    return NO;
}

- (id)next {
    id res = self.array[self.idx];
    self.idx ++;
    return res;
}


@end

@implementation GHArray

- (NSUInteger)count {
    return self.arr.count;
}

+ (instancetype)ghArrayWithArray:(NSArray *)array {
    GHArray *res = [GHArray new];
    res.arr = array;
    return res;
}

- (id<GHIIterator>)iterator {
    GHArrayIterator *res = [GHArrayIterator new];
    res.array = self;
    return res;
}


- (id)objectAtIndexedSubscript:(NSUInteger)idx{
    return self.arr[idx];
}

@end
