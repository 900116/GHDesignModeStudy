//
//  GHStrategyModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*
【策略模式】
 
主要解决：
        在有多种算法相似的情况下，使用 if...else 所带来的复杂和难以维护。

优点：
        1、算法可以自由切换。
        2、避免使用多重条件判断。
        3、扩展性良好。

缺点：
        1、策略类会增多。
        2、所有策略类都需要对外暴露。

使用场景：
        1、如果在一个系统里面有许多类，它们之间的区别仅在于它们的行为，那么使用策略模式可以动态地让一个对象在许多行为中选择一种行为。
        2、一个系统需要动态地在几种算法中选择一种。
        3、如果一个对象有很多的行为，如果不用恰当的模式，这些行为就只好使用多重的条件选择语句来实现。

 注意事项：
        如果一个系统的策略多于四个，就需要考虑使用混合模式，解决策略类膨胀的问题。
*/

@protocol GHIStatisticsStratety <NSObject>

- (CGFloat)refFerenceValue: (NSArray<NSNumber *>*)numbers;

@end

//平均值
@interface GHAvgStatisticsStratety : NSObject <GHIStatisticsStratety>

@end

//中位数
@interface GHMidStatisticsStratety : NSObject <GHIStatisticsStratety>

@end

@interface GHStatisticsContext : NSObject

//
@property (nonatomic,strong) id <GHIStatisticsStratety> stratety;

+ (instancetype)context:(NSArray<NSNumber *> *)nums;
- (CGFloat)caculaterRefValue;

@end

static inline void ghStrategy_test () {
    //计算比较复杂，减少了if判断
    GHStatisticsContext *context = [GHStatisticsContext context:@[@22,@15,@33,@11,@44,@20]];
    context.stratety = [GHAvgStatisticsStratety new];
    NSLog(@"value:%lf",[context caculaterRefValue]);
    
    context.stratety = [GHMidStatisticsStratety new];
    NSLog(@"value:%lf",[context caculaterRefValue]);
    
}

NS_ASSUME_NONNULL_END
