//
//  GHMementoModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/*
【备忘录模式】
 
主要解决：
        所谓备忘录模式就是在不破坏封装的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态，这样可以在以后将对象恢复到原先保存的状态。

优点：
        1、给用户提供了一种可以恢复状态的机制，可以使用户能够比较方便地回到某个历史的状态。
        2、实现了信息的封装，使得用户不需要关心状态的保存细节。

缺点：
        消耗资源。如果类的成员变量过多，势必会占用比较大的资源，而且每一次保存都会消耗一定的内存。

使用场景：
        1、需要保存/恢复数据的相关状态场景。 2、提供一个可回滚的操作。

注意事项：
        1、为了符合迪米特原则，还要增加一个管理备忘录的类。
        2、为了节约内存，可使用原型模式+备忘录模式。
*/

@interface GHChessMemento : NSObject
//
@property (nonatomic,assign) NSInteger x;
@property (nonatomic,assign) NSInteger y;

@end

@interface GHChess : NSObject

//
@property (nonatomic,assign) NSInteger x;
@property (nonatomic,assign) NSInteger y;

- (GHChessMemento *)step:(NSInteger)x y:(NSInteger)y;
- (void)restore: (GHChessMemento *)memento;
- (void)show;

@end

@interface GHChessMementoCaretaker : NSObject

- (void)addMemento: (GHChessMemento *)memento;
- (GHChessMemento *)memento:(NSUInteger)idx;

@end

static inline void ghMemento_test() {
    GHChess *chess = [GHChess new];
    GHChessMementoCaretaker *taker = [GHChessMementoCaretaker new];
    void (^play)(NSInteger,NSInteger) = ^ (NSInteger x,NSInteger y) {
         GHChessMemento *memento = [chess step:x y:y];
        [taker addMemento:memento];
    };
    play(100,50);
    play(30,70);
    play(20,34);
    play(77,22);
    
    [chess show];
    //悔棋到第二步
    [chess restore: [taker memento:1]];
    [chess show];
}


NS_ASSUME_NONNULL_END
