//
//  GHBirdgeModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*
【桥接模式】
 
主要解决：
       在有多种可能会变化的情况下，用继承会造成类爆炸问题，扩展起来不灵活。

优点：
       1、抽象和实现的分离。
       2、优秀的扩展能力。
       3、实现细节对客户透明。

缺点：
       桥接模式的引入会增加系统的理解与设计难度，由于聚合关联关系建立在抽象层，
       要求开发者针对抽象进行设计与编程。

使用场景：
       1、如果一个系统需要在构件的抽象化角色和具体化角色之间增加更多的灵活性，
        避免在两个层次之间建立静态的继承联系，通过桥接模式可以使它们在抽象层建立一个关联关系。
       2、对于那些不希望使用继承或因为多层次继承导致系统类的个数急剧增加的系统，桥接模式尤为适用。
       3、一个类存在两个独立变化的维度，且这两个维度都需要进行扩展。

注意事项：
       对于两个独立变化的维度，使用桥接模式再适合不过了。
*/

@protocol GHDraw <NSObject>

- (void)drawCircle: (CGFloat)x y:(CGFloat)y radius:(CGFloat)radius;

@end

@interface GHDrawStyle1 : NSObject <GHDraw>

@end

@interface GHDrawStyle2 : NSObject <GHDraw>

@end

@interface GHShape : NSObject

@property (nonatomic, strong) id <GHDraw> drawer;
- (void)draw;

@end

@interface GHCircle : GHShape

@property (nonatomic,assign) CGFloat x;
@property (nonatomic,assign) CGFloat y;
@property (nonatomic,assign) CGFloat radius;

@end

static inline void ghBrige_test() {
    //创建一个圆形
    GHCircle *circleStyle1 = [GHCircle new];
    circleStyle1.x = 0;
    circleStyle1.y = 0;
    circleStyle1.radius = 0;
    
    GHShape *shape = circleStyle1;
    shape.drawer = [GHDrawStyle1 new];
    [shape draw];
    //将形状的实体与绘制方法进行解耦
    //这样就可以进行灵活的组合
    
    //与适配器模式有何区别？
    //适配器模式，往往是一种事后设计，已经有了两个不相关的类，接口不统一想要进行协作
    //而桥接模式，往往是一种事前设计，项目创建之初就定义好了接口，在接口上进行扩展
    
    GHCircle *circleStyle2 = [GHCircle new];
    circleStyle2.x = 0;
    circleStyle2.y = 0;
    circleStyle2.radius = 0;
    
    shape = circleStyle2;
    shape.drawer = [GHDrawStyle2 new];
    [shape draw];
}

NS_ASSUME_NONNULL_END
