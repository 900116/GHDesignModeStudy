//
//  GHTemplateModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
【模板模式】
 
主要解决：
        一些方法通用，却在每一个子类都重新写了这一方法。

优点：
        1、封装不变部分，扩展可变部分。
        2、提取公共代码，便于维护。
        3、行为由父类控制，子类实现。

缺点：
        每一个不同的实现都需要一个子类来实现，导致类的个数增加，使得系统更加庞大。
 
使用场景：
        1、有多个子类共有的方法，且逻辑相同。
        2、重要的、复杂的方法，可以考虑作为模板方法。

 注意事项：
        为防止恶意操作，一般模板方法都加上 final 关键词。
*/

@interface GHQuestion : NSObject

//
@property (nonatomic,assign) NSInteger score;

@end

@protocol GHIExamPaper <NSObject>

//单选
- (NSArray<GHQuestion *> *)selectQuestion;

//多选
- (NSArray<GHQuestion *> *)multiSelectQuestion;

//填空
- (NSArray<GHQuestion *> *)fillQuestion;

//简答题
- (NSArray<GHQuestion *> *)answerQuestion;

@end

//物理
@interface GHPhysicsExamPaper : NSObject <GHIExamPaper>

@end


//数学
@interface GHMathExamPaper : NSObject <GHIExamPaper>

@end

@interface GHExamScoreCaculater : NSObject

- (NSInteger)paperTotal: (id<GHIExamPaper>)paper;

@end

static inline void ghTemplate_test() {
    GHExamScoreCaculater *calculator = [GHExamScoreCaculater new];
    id <GHIExamPaper> paper = [GHMathExamPaper new];
    NSLog(@"totalScore:%ld",[calculator paperTotal:paper]);
    
    paper = [GHPhysicsExamPaper new];
    NSLog(@"totalScore:%ld",[calculator paperTotal:paper]);
    
}

NS_ASSUME_NONNULL_END
