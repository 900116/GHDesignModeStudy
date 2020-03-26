//
//  GHInterpreterModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
【解释器模式】
 
主要解决：
        对于一些固定文法构建一个解释句子的解释器。

优点：
        1、可扩展性比较好，灵活。
        2、增加了新的解释表达式的方式。
        3、易于实现简单文法。

缺点：
        1、可利用场景比较少。
        2、对于复杂的文法比较难维护。
        3、解释器模式会引起类膨胀。
        4、解释器模式采用递归调用方法。

使用场景：
        1、可以将一个需要解释执行的语言中的句子表示为一个抽象语法树。
        2、一些重复出现的问题可以用一种简单的语言来进行表达。
        3、一个简单语法需要解释的场景。

注意事项：
        可利用场景比较少，JAVA 中如果碰到可以用 expression4J 代替。
*/


@protocol GHExpression <NSObject>

- (NSInteger)interpreter:(NSDictionary<NSString *,NSNumber *>*)vars;

@end


@interface GHCalculator : NSObject

- (NSInteger)calculator: (NSString *)exp vars:(NSDictionary<NSString*,NSNumber*>*)vars;

@end

@interface GHVarExpression : NSObject <GHExpression>

+ (instancetype)expression: (NSString *)key;

@end

@interface GHSymbolExpression : NSObject <GHExpression>

+ (instancetype)expression: (id<GHExpression>)left right:(id<GHExpression>)right;

@end

@interface GHAddExpression : GHSymbolExpression

@end

@interface GHSubExpression : GHSymbolExpression

@end

static inline void ghInterpreter_test() {
    NSMutableDictionary <NSString *,NSNumber *> *vars = [NSMutableDictionary new];
    vars[@"a"] = @3;
    vars[@"b"] = @10;
    vars[@"c"] = @7;
    
    NSString *exp = @"a+b-c";
    
    GHCalculator *cal = [GHCalculator new];
    NSInteger res = [cal calculator:exp vars:vars];
    NSLog(@"res = %ld",res);
}

NS_ASSUME_NONNULL_END
