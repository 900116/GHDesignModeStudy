//
//  GHFrontControllerModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
前端控制器模式
前端控制器模式（Front Controller Pattern）是用来提供一个集中的请求处理机制，所有的请求都将由一个单一的处理程序处理。该处理程序可以做认证/授权/记录日志，或者跟踪请求，然后把请求传给相应的处理程序。以下是这种设计模式的实体。

前端控制器（Front Controller） - 处理应用程序所有类型请求的单个处理程序，应用程序可以是基于 web 的应用程序，也可以是基于桌面的应用程序。
调度器（Dispatcher） - 前端控制器可能使用一个调度器对象来调度请求到相应的具体处理程序。
视图（View） - 视图是为请求而创建的对象。
*/

@interface GHFCView : NSObject

- (void)show;

@end

@interface GHFCStudentView : GHFCView

@end

@interface GHFCTeacherView : GHFCView

@end

@interface GHDispatcher : NSObject

- (void)dispatch:(NSString *)userType;

@end

@interface GHFrontController : NSObject

- (void)login: (NSString *)userType;

@end

static inline void ghFrontController_test() {
    GHFrontController *controller = [GHFrontController new];
    [controller login:@"STU"];
    [controller login:@"TEA"];
}

NS_ASSUME_NONNULL_END