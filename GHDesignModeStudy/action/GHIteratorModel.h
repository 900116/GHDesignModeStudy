//
//  GHIteratorModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
【迭代器模式】
 
主要解决：
        不同的方式来遍历整个整合对象。

优点：
        1、它支持以不同的方式遍历一个聚合对象。
        2、迭代器简化了聚合类。
        3、在同一个聚合上可以有多个遍历。
        4、在迭代器模式中，增加新的聚合类和迭代器类都很方便，无须修改原有代码。

缺点：
        由于迭代器模式将存储数据和遍历数据的职责分离，增加新的聚合类需要对应增加新的迭代器类，类的个数成对增加，这在一定程度上增加了系统的复杂性。

使用场景：
        1、访问一个聚合对象的内容而无须暴露它的内部表示。
        2、需要为聚合对象提供多种遍历方式。
        3、为遍历不同的聚合结构提供一个统一的接口。

注意事项：
        迭代器模式就是分离了集合对象的遍历行为，抽象出一个迭代器类来负责，这样既可以做到不暴露集合的内部结构，又可让外部代码透明地访问集合内部的数据。
*/

@protocol GHIIterator <NSObject>

- (BOOL)hasNext;
- (id)next;

@end

@protocol GHIContainer <NSObject>

- (id<GHIIterator>)iterator;

@end


@interface GHArrayIterator : NSObject <GHIIterator>

@end

@interface GHArray : NSObject <GHIContainer>

+ (instancetype)ghArrayWithArray:(NSArray *)array;
- (id)objectAtIndexedSubscript:(NSUInteger)idx;

@end

static inline void ghIterator_test () {
    id<GHIContainer> arr = [GHArray ghArrayWithArray:@[@"1",@"2",@"3"]];
    
    //只要实现了迭代器，就可以用这种方式进行迭代，统一了迭代的接口，将容器抽象
    for (id<GHIIterator> iter = arr.iterator; iter.hasNext;) {
        NSLog(@"%@",iter.next);
    }
}


NS_ASSUME_NONNULL_END
