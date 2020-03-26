//
//  GHSingletonModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
  【单例模式】
 
主要解决：
       一个全局使用的类频繁地创建与销毁。

优点：
       1、在内存里只有一个实例，减少了内存的开销，尤其是频繁的创建和销毁实例（比如管理学院首页页面缓存）。
       2、避免对资源的多重占用（比如写文件操作）。

缺点：
       没有接口，不能继承，与单一职责原则冲突，一个类应该只关心内部逻辑，而不关心外面怎么样来实例化。

使用场景：
       1、要求生产唯一序列号。
       2、创建的一个对象需要消耗的资源过多，比如 I/O 与数据库的连接等。

注意事项：
       getInstance() 方法中需要使用同步锁 synchronized (Singleton.class)
       防止多线程同时进入造成 instance 被多次实例化。
*/

@interface GHSingletonModel : NSObject

//禁止初始化方法
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)alloc NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

+ (instancetype)getInstance;

@end

static inline void ghSigleton_test() {
    //只能通过单例方法获得对象，单例方法获得的对象始终是同一个
    GHSingletonModel *model = [GHSingletonModel getInstance];
    NSLog(@"%@",model);
    
    model = [GHSingletonModel getInstance];
    NSLog(@"%@",model);
};


NS_ASSUME_NONNULL_END
