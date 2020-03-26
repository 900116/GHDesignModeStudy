//
//  GHTemplateModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHTemplateModel.h"
@implementation GHQuestion
@end

//物理
@implementation GHPhysicsExamPaper

- (NSArray<GHQuestion *> *)selectQuestion {
    NSMutableArray *res = [NSMutableArray new];
    for (int i = 0; i < 8; i++) {
        GHQuestion *q = [GHQuestion new];
        q.score = 6;
        [res addObject:q];
    }
    return res;
}

- (NSArray<GHQuestion *> *)multiSelectQuestion {
    NSMutableArray *res = [NSMutableArray new];
    for (int i = 0; i < 4; i++) {
        GHQuestion *q = [GHQuestion new];
        q.score = 8;
        [res addObject:q];
    }
    return res;
}

- (NSArray<GHQuestion *> *)fillQuestion {
    NSMutableArray *res = [NSMutableArray new];
    for (int i = 0; i < 10; i++) {
        GHQuestion *q = [GHQuestion new];
        q.score = 2;
        [res addObject:q];
    }
    return res;
}

- (NSArray<GHQuestion *> *)answerQuestion {
    NSMutableArray *res = [NSMutableArray new];
    for (int i = 0; i < 4; i++) {
        GHQuestion *q = [GHQuestion new];
        q.score = 8;
        [res addObject:q];
    }
    return res;
}

@end


//数学
@implementation GHMathExamPaper

- (NSArray<GHQuestion *> *)selectQuestion {
    NSMutableArray *res = [NSMutableArray new];
    for (int i = 0; i < 12; i++) {
        GHQuestion *q = [GHQuestion new];
        q.score = 6;
        [res addObject:q];
    }
    return res;
}

- (NSArray<GHQuestion *> *)multiSelectQuestion {
    NSMutableArray *res = [NSMutableArray new];
    for (int i = 0; i < 6; i++) {
        GHQuestion *q = [GHQuestion new];
        q.score = 6;
        [res addObject:q];
    }
    return res;
}

- (NSArray<GHQuestion *> *)fillQuestion {
    NSMutableArray *res = [NSMutableArray new];
    for (int i = 0; i < 10; i++) {
        GHQuestion *q = [GHQuestion new];
        q.score = 3;
        [res addObject:q];
    }
    return res;
}

- (NSArray<GHQuestion *> *)answerQuestion {
    NSMutableArray *res = [NSMutableArray new];
    for (int i = 0; i < 4; i++) {
        GHQuestion *q = [GHQuestion new];
        q.score = 12;
        [res addObject:q];
    }
    return res;
}

@end


@implementation GHExamScoreCaculater : NSObject

- (NSInteger)paperTotal: (id<GHIExamPaper>)paper {
    __block NSInteger res = 0;
    //单选
    [[paper selectQuestion] enumerateObjectsUsingBlock:^(GHQuestion * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        res += obj.score;
    }];
    
    //多选
    [[paper multiSelectQuestion] enumerateObjectsUsingBlock:^(GHQuestion * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        res += obj.score;
    }];
    
    //填空
    [[paper fillQuestion] enumerateObjectsUsingBlock:^(GHQuestion * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        res += obj.score;
    }];
    
    //问答
    [[paper answerQuestion] enumerateObjectsUsingBlock:^(GHQuestion * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        res += obj.score;
    }];    
 
    return res;
}

@end
