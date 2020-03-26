//
//  GHCommandModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
【责任链模式】
 
主要解决：
       在软件系统中，行为请求者与行为实现者通常是一种紧耦合的关系，但某些场合，
       比如需要对行为进行记录、撤销或重做、事务等处理时，这种无法抵御变化的紧耦合的设计就不太合适。

优点：
       1、降低了系统耦合度。
       2、新的命令可以很容易添加到系统中去。

缺点：
       使用命令模式可能会导致某些系统有过多的具体命令类。

使用场景：
       认为是命令的地方都可以使用命令模式，比如：
            1、GUI 中每一个按钮都是一条命令。
            2、模拟 CMD。

注意事项：
       系统需要支持命令的撤销(Undo)操作和恢复(Redo)操作，也可以考虑使用命令模式，见命令模式的扩展。
*/

//定义一种组件行为
@protocol GHComponent <NSObject>

- (void)loadComphonet;
- (void)destoryComphoent;

@end

@interface GHNetWorkComponent : NSObject <GHComponent>

@end

@interface GHDBComponent : NSObject <GHComponent>

@end

@interface GHNotificationComponent : NSObject <GHComponent>

@end


@interface GHDBComphonetManager : NSObject

- (void)addComponent:(id<GHComponent>)component;
- (void)loadAllComponent;
- (void)destoryAllComponent;

@end

static inline void ghCommand_test() {
    GHDBComphonetManager *manager = [GHDBComphonetManager new];
    
    id<GHComponent> netWorkComponent = [GHNetWorkComponent new];
    id<GHComponent> dbComponent = [GHDBComponent new];
    id<GHComponent> notifComponent = [GHNotificationComponent new];
    
    [manager addComponent:netWorkComponent];
    [manager addComponent:dbComponent];
    [manager addComponent:notifComponent];
    
    [manager loadAllComponent];
    [manager destoryAllComponent];
}

NS_ASSUME_NONNULL_END
