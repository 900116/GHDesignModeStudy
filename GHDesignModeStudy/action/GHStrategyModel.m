//
//  GHStrategyModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHStrategyModel.h"


//平均值
@implementation GHAvgStatisticsStratety

- (CGFloat)refFerenceValue:(NSArray<NSNumber *> *)numbers {
    __block CGFloat total;
    CGFloat length = numbers.count;
    [numbers enumerateObjectsUsingBlock:^(NSNumber * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        total += [obj intValue];
    }];
    return total / length;
}

@end

//中位数
@implementation GHMidStatisticsStratety
- (CGFloat)refFerenceValue:(NSArray<NSNumber *> *)numbers {
    NSArray *array = [numbers sortedArrayUsingComparator:^NSComparisonResult(id  _Nonnull obj1, id  _Nonnull obj2) {
        return [obj1 intValue] > [obj2 intValue];
    }];
    NSUInteger idx = numbers.count % 2 != 0 ? (numbers.count/2): (numbers.count/2) - 1;
    return [array[idx] floatValue];
}

@end

@interface GHStatisticsContext ()
//
@property (nonatomic,strong) NSArray<NSNumber *> *nums;
@end

@implementation GHStatisticsContext
+ (instancetype)context:(NSArray<NSNumber *> *)nums {
    GHStatisticsContext *context = [GHStatisticsContext new];
    context.nums = nums;
    return context;
}

- (CGFloat)caculaterRefValue {
    return [self.stratety refFerenceValue:self.nums];
}
@end
