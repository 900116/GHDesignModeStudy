//
//  GHObserverModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHObserverModel.h"

@interface GHSubject ()
//
@property (nonatomic,strong) NSMutableArray<id<GHIObserver>> *observers;

@end

@implementation GHSubject

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.observers = [NSMutableArray new];
    }
    return self;
}

- (void)registerObserver:(id<GHIObserver>)observer {
    [self.observers addObject:observer];
    observer.subject = self;
}

- (void)setState:(int)state {
    _state = state;
    [self.observers enumerateObjectsUsingBlock:^(id<GHIObserver>  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        [obj stateChange];
    }];
}

@end

@implementation GHObserver

- (void)stateChange {
    NSLog(@"[%@]subject.state = %d",self,self.subject.state);
}

@end
