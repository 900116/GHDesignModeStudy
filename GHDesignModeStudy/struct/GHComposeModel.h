//
//  GHComposeModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
【组合模式】
 
主要解决：
       它在我们树型结构的问题中，模糊了简单元素和复杂元素的概念，
        客户程序可以像处理简单元素一样来处理复杂元素，从而使得客户程序与复杂元素的内部结构解耦。

优点：
       1、高层模块调用简单。
       2、节点自由增加。

缺点：
       在使用组合模式时，其叶子和树枝的声明都是实现类，而不是接口，违反了依赖倒置原则。

使用场景：
       部分、整体场景，如树形菜单，文件、文件夹的管理。

注意事项：
       定义时为具体类。
*/

@interface GHEmployee : NSObject

//
@property (nonatomic,strong) NSString *name;
//
@property (nonatomic,strong) NSMutableArray<GHEmployee *> *subordinates;

- (void)manage: (GHEmployee *)employee;
- (void)removeManage: (GHEmployee *)employee;

@end

static inline void ghCompose_test () {
    GHEmployee *ceo = [GHEmployee new]; //ceo 管理两个leader  leader管理两个staff
    ceo.name = @"CEO";
    
    GHEmployee *leader = [GHEmployee new];
    leader.name = @"leader";
    
    GHEmployee *leader2 = [GHEmployee new];
    leader2.name = @"leader2";
    
    [ceo manage:leader];
    [ceo manage:leader2];
    
    GHEmployee *staff = [GHEmployee new];
    staff.name = @"staff";
    
    GHEmployee *staff2 = [GHEmployee new];
    staff2.name = @"staff2";
    
    [leader manage:staff];
    [leader manage:staff2];
}

NS_ASSUME_NONNULL_END
