//
//  GHFactoryModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*
 【工厂模式】
 
 主要解决：
        主要解决接口选择的问题。
 
 优点：
        1、一个调用者想创建一个对象，只要知道其名称就可以了。
        2、扩展性高，如果想增加一个产品，只要扩展一个工厂类就可以。
        3、屏蔽产品的具体实现，调用者只关心产品的接口。
 
 缺点：
        每次增加一个产品时，都需要增加一个具体类和对象实现工厂，使得系统中类的个数成倍增加，在一定程度上增加了系统的复杂度，
        同时也增加了系统具体类的依赖。这并不是什么好事。

 使用场景：
        同一行为的不同实现，比如不同的加密算法，不同的网络协议等等。

 注意事项：
        作为一种创建类模式，在任何需要生成复杂对象的地方，都可以使用工厂方法模式。
        有一点需要注意的地方就是复杂对象适合使用工厂模式，而简单对象，特别是只需要通过 new 就可以完成创建的对象，无需使用工厂模式。
        如果使用工厂模式，就需要引入一个工厂类，会增加系统的复杂度。
 */


@protocol GHIDrink <NSObject>

- (void)drink;

@end


@interface GHCola : NSObject <GHIDrink>

@end

@interface GHJuice : NSObject <GHIDrink>

@end

@interface GHBeer : NSObject <GHIDrink>

@end

@interface GHVEM : NSObject

- (id<GHIDrink>)buyDrink:(CGFloat)money;

@end


static inline void ghFactory_test() {
    //现在想要买一瓶可乐喝
    //创建一个自动售货机，往里面投入一个五块钱的硬币
    GHVEM *vem = [GHVEM new];
    id<GHIDrink> drink = [vem buyDrink:5.0];
    
    //出来一瓶可乐，喝掉，我只需要知道五块钱对应可乐就可以
    //并且我的诉求 只是喝一瓶饮料，所以我不需要知道饮料更具体的细节
    [drink drink];
    
    drink = [vem buyDrink:10.0];
    [drink drink];
    
    drink = [vem buyDrink:3.0];
    [drink drink];
};


NS_ASSUME_NONNULL_END
