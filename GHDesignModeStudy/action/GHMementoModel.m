//
//  GHMementoModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHMementoModel.h"

@implementation GHChessMemento

@end

@implementation GHChess

- (GHChessMemento *)step:(NSInteger)x y:(NSInteger)y {
    self.x = x;
    self.y = y;
    GHChessMemento *res = [GHChessMemento new];
    res.x = x;
    res.y = y;
    return res;
}

- (void)restore:(GHChessMemento *)memento {
    self.x = memento.x;
    self.y = memento.y;
}

- (void)show {
    NSLog(@"x:%ld y:%ld",self.x,self.y);
}

@end

@interface GHChessMementoCaretaker()

//
@property (nonatomic,strong) NSMutableArray <GHChessMemento *> *mementoList;

@end

@implementation GHChessMementoCaretaker

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.mementoList = [NSMutableArray new];
    }
    return self;
}

- (void)addMemento: (GHChessMemento *)memento {
    [self.mementoList addObject:memento];
}

- (GHChessMemento *)memento:(NSUInteger)idx {
    return self.mementoList[idx];
}

@end
