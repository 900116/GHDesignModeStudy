//
//  GHBusinessDelegateModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
业务代表模式
业务代表模式（Business Delegate Pattern）用于对表示层和业务层解耦。它基本上是用来减少通信或对表示层代码中的业务层代码的远程查询功能。在业务层中我们有以下实体。

客户端（Client） - 表示层代码可以是 JSP、servlet 或 UI java 代码。
业务代表（Business Delegate） - 一个为客户端实体提供的入口类，它提供了对业务服务方法的访问。
查询服务（LookUp Service） - 查找服务对象负责获取相关的业务实现，并提供业务对象对业务代表对象的访问。
业务服务（Business Service） - 业务服务接口。实现了该业务服务的实体类，提供了实际的业务实现逻辑。
*/

@protocol GHBusinessService <NSObject>

- (void)doProcessing;

@end

@interface GHBusinessServiceA : NSObject <GHBusinessService>

@end

@interface GHBusinessServiceB : NSObject <GHBusinessService>

@end

@interface GHBusinessLookUp : NSObject

- (id<GHBusinessService>)serviceByType:(NSString *)type;

@end

@interface GHBusinessDelegate : NSObject

//
@property (nonatomic,copy) NSString *serviceType;

- (void)doTask;

@end

@interface GHClient : NSObject

//
@property (nonatomic,strong) GHBusinessDelegate *service;

- (void)doTask;

@end

static inline void ghBusinessDelegate_test() {
    GHBusinessDelegate *delegate = [GHBusinessDelegate new];
    delegate.serviceType = @"A";
    
    GHClient *client = [GHClient new];
    client.service = delegate;
    [client doTask];
    
    delegate.serviceType =  @"B"; //client只跟代理绑定，代理灵活变化
    [client doTask];
}

NS_ASSUME_NONNULL_END
