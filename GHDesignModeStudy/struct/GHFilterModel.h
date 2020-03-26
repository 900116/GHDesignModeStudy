//
//  GHFilterModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
 【过滤器模式】
 
  将一组对象进行过滤，并且统一接口
 */

@interface GHPerson : NSObject

//
@property (nonatomic,strong) NSString *name;
//
@property (nonatomic,assign) BOOL gender;
//
@property (nonatomic,assign) BOOL married;

@end

@protocol GHPersonFilter <NSObject>

- (NSArray <GHPerson *> *)filter:(NSArray <GHPerson *> *)persons;

@end

@interface GHMalePersonFilter : NSObject <GHPersonFilter>

@end

@interface GHFemalePersonFilter : NSObject <GHPersonFilter>

@end

@interface GHSinglePersonFilter : NSObject <GHPersonFilter>

@end

@interface GHMarriedPersonFilter : NSObject <GHPersonFilter>

@end

@interface GHAndFilter : NSObject <GHPersonFilter>

+ (instancetype)and:(id<GHPersonFilter>)f1 f2:(id<GHPersonFilter>)f2;

@end

@interface GHOrFilter : NSObject <GHPersonFilter>

+ (instancetype)or:(id<GHPersonFilter>)f1 f2:(id<GHPersonFilter>)f2;

@end

static inline void ghFilter_testAddPerson(NSMutableArray <GHPerson *> *persons,NSString *name,BOOL gender,BOOL married) {
    GHPerson *person = [GHPerson new];
    person.name = name;
    person.gender = gender;
    person.married = married;
    [persons addObject:person];
}

static inline void ghFilter_testPrint(NSArray <GHPerson *> *persons,NSString *type) {
    NSLog(@"---------%@---------",type);
    for (GHPerson *person in persons) {
        NSLog(@"%@",person.name);
    }
}


static inline void ghFilter_test() {
    NSMutableArray <GHPerson *> *persons = [NSMutableArray new];
    ghFilter_testAddPerson(persons, @"S小明", YES, NO);
    ghFilter_testAddPerson(persons, @"M小军", YES, YES);
    ghFilter_testAddPerson(persons, @"M小亮", YES, YES);
    ghFilter_testAddPerson(persons, @"S小李", YES, NO);
    
    ghFilter_testAddPerson(persons, @"S小丽", NO, NO);
    ghFilter_testAddPerson(persons, @"M小雅", NO, YES);
    ghFilter_testAddPerson(persons, @"M小花", NO, YES);
    ghFilter_testAddPerson(persons, @"S小爱", NO, NO);
    
    id<GHPersonFilter> males = [GHMalePersonFilter new]; //男性
    id<GHPersonFilter> feMales = [GHFemalePersonFilter new]; //女性
    id<GHPersonFilter> singles = [GHSinglePersonFilter new]; //单身
    id<GHPersonFilter> marrieds = [GHMarriedPersonFilter new]; //已婚
    id<GHPersonFilter> singleAndMale = [GHAndFilter and:singles f2:males]; //单身并且男性
    id<GHPersonFilter> marriedOrFemales = [GHOrFilter or:marrieds f2:feMales]; //已婚或者女性
    
    ghFilter_testPrint([males filter:persons],@"男性");
    ghFilter_testPrint([feMales filter:persons],@"女性");
    ghFilter_testPrint([singles filter:persons],@"单身");
    ghFilter_testPrint([marrieds filter:persons],@"已婚");
    ghFilter_testPrint([singleAndMale filter:persons],@"单身并且男性");
    ghFilter_testPrint([marriedOrFemales filter:persons],@"已婚或者女性");
    
    
}

NS_ASSUME_NONNULL_END
