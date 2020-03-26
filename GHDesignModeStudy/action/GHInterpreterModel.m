//
//  GHInterpreterModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHInterpreterModel.h"

@implementation GHCalculator

- (NSInteger)calculator: (NSString *)exp vars:(NSDictionary<NSString*,NSNumber*>*)vars{
    NSMutableArray <id<GHExpression>> *stack = [NSMutableArray new];
    id<GHExpression> left = nil;
    id<GHExpression> right = nil;
    for (int i = 0; i < exp.length; ++i) {
        char x = [exp characterAtIndex:i];
        if (x == '+') {
            left = stack[0];
            [stack removeObjectAtIndex:0];
            right = [GHVarExpression expression:[NSString stringWithFormat:@"%c",[exp characterAtIndex:++i]]];
            [stack insertObject:[GHAddExpression expression:left right:right] atIndex:0];
        }
        else if (x == '-') {
            left = stack[0];
            [stack removeObjectAtIndex:0];
            right = [GHVarExpression expression:[NSString stringWithFormat:@"%c",[exp characterAtIndex:++i]]];
            [stack insertObject:[GHSubExpression expression:left right:right] atIndex:0];
        } else {
            [stack insertObject:[GHVarExpression expression:[NSString stringWithFormat:@"%c",x]] atIndex:0];
        }
    }
    id <GHExpression> expression = stack[0];
    [stack removeObjectAtIndex:0];
    return [expression interpreter:vars];
}

@end

@interface GHVarExpression ()

//
@property (nonatomic,copy) NSString *key;

@end

@implementation GHVarExpression

+ (instancetype)expression: (NSString *)key {
    GHVarExpression *exp = [self new];
    exp.key = key;
    return exp;
}

- (NSInteger)interpreter:(NSDictionary<NSString *,NSNumber *> *)vars {
    return [vars[self.key] intValue];
}

@end

@interface GHSymbolExpression ()

//
@property (nonatomic,strong) id<GHExpression> left;
@property (nonatomic,strong) id<GHExpression> right;

@end

@implementation GHSymbolExpression

+ (instancetype)expression: (id<GHExpression>)left right:(id<GHExpression>)right {
    GHSymbolExpression *exp = [self new];
    exp.left = left;
    exp.right = right;
    return exp;
}

- (NSInteger)interpreter:(NSDictionary<NSString *,NSNumber *> *)vars {
    return 0;
}

@end

@implementation GHAddExpression

- (NSInteger)interpreter:(NSDictionary<NSString *,NSNumber *> *)vars {
    return [self.left interpreter:vars] + [self.right interpreter:vars];
}

@end

@implementation GHSubExpression

- (NSInteger)interpreter:(NSDictionary<NSString *,NSNumber *> *)vars {
    return [self.left interpreter:vars] - [self.right interpreter:vars];
}

@end
