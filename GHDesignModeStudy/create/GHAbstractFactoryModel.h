//
//  GHAbstractFactoryModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GHFactoryModel.h"

NS_ASSUME_NONNULL_BEGIN


@protocol GHIVEM <NSObject>

- (id<GHIDrink>)buyDrink:(CGFloat)money;

@end


/*
【抽象工厂模式】
 
 主要解决：
        主要解决接口选择的问题。
 
 优点：
        当一个产品族中的多个对象被设计成一起工作时，它能保证客户端始终只使用同一个产品族中的对象。
 
 缺点：
        产品族扩展非常困难，要增加一个系列的某一产品，既要在抽象的 Creator 里加代码，又要在具体的里面加代码。

 使用场景：
        1、QQ 换皮肤，一整套一起换。
        2、生成不同操作系统的程序。

 注意事项：
        产品族难扩展，产品等级易扩展。
 */

@interface GHPepsiCola : NSObject <GHIDrink>

@end

@interface GHPepsiJuice : NSObject <GHIDrink>

@end

@interface GHPepsiBeer : NSObject <GHIDrink>

@end

@interface GHPepsiVEM : NSObject <GHIVEM>

@end

@interface GHCocaCola : NSObject <GHIDrink>

@end

@interface GHCocaJuice : NSObject <GHIDrink>

@end

@interface GHCocaBeer : NSObject <GHIDrink>

@end

@interface GHCocaVEM : NSObject <GHIVEM>

@end

@interface GHAbstractVEM : NSObject

- (id<GHIVEM>)vemForBrand:(NSString *)brand;

@end

static inline void ghAbstractFactory_test() {
    //一台抽象的自动售货机
    GHAbstractVEM *absVem = [GHAbstractVEM new];
    
    //我想买一瓶可口可乐公司出的，所以我需要创建一个可口可乐自动售货机
    id <GHIVEM> trueVem = [absVem vemForBrand:@"Coca"];
    //放进去五块钱，买一瓶可乐喝掉
    id <GHIDrink> drink = [trueVem buyDrink:5];
    [drink drink];
    
    //如果想买百事可乐公司出的，就创建百事可乐售货机
    trueVem = [absVem vemForBrand:@"Pepsi"];
    drink = [trueVem buyDrink:3];
    [drink drink];
    
    //虽然工厂模式，本身可以实现这个需求，但是单纯的工厂模式把品牌耦合进去，工厂方法将变得臃肿，维护性也变差
};


NS_ASSUME_NONNULL_END
