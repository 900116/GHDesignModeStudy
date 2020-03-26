//
//  GHBuilderModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*
  【建造者模式】
 
主要解决：
        主要解决在软件系统中，有时候面临着"一个复杂对象"的创建工作，其通常由各个部分的子对象用一定的算法构成；
        由于需求的变化，这个复杂对象的各个部分经常面临着剧烈的变化，但是将它们组合在一起的算法却相对稳定。

优点：
        1、建造者独立，易扩展。
        2、便于控制细节风险。

缺点：
        1、产品必须有共同点，范围有限制。
        2、如内部变化复杂，会有很多的建造类。

使用场景：
        1、需要生成的对象具有复杂的内部结构。
        2、需要生成的对象内部属性本身相互依赖。

注意事项：
       与工厂模式的区别是：建造者模式更加关注与零件装配的顺序。
*/


@protocol GHIEatGoods <NSObject>

- (NSString *)name;
- (CGFloat)price;

@end

@interface GHBurger : NSObject <GHIEatGoods>

@end

@interface GHMealCola : NSObject <GHIEatGoods>

@end

@interface GHChicken : NSObject <GHIEatGoods>

@end

@interface GHMeal : NSObject

- (void)addItem: (id<GHIEatGoods>)item;
- (CGFloat)getCost;
- (void)listItems;

@end

@interface GHMealBuilder : NSObject

- (GHMeal *)mealA;
- (GHMeal *)mealB;

@end


static inline void ghBuilder_test() {
    //套餐构建起
    GHMealBuilder *builder = [GHMealBuilder new];
    //构建一个套餐A
    NSLog(@"-------套餐A-------");
    [[builder mealA] listItems];
    NSLog(@"-------套餐B-------");
    //构建一个套餐B
    [[builder mealB] listItems];
    
    //把套餐价格的计算，与套餐的组装进行了解耦，计算在meal里面，而套餐的组装在builder里面
};


NS_ASSUME_NONNULL_END
