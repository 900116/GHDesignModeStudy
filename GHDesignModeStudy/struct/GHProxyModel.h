//
//  GHProxyModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
【代理模式】
 
主要解决：
       在直接访问对象时带来的问题，比如说：要访问的对象在远程的机器上。在面向对象系统中，
       有些对象由于某些原因（比如对象创建开销很大，或者某些操作需要安全控制，或者需要进程外的访问），
       直接访问会给使用者或者系统结构带来很多麻烦，我们可以在访问此对象时加上一个对此对象的访问层。

优点：
       1、职责清晰。
       2、高扩展性。
       3、智能化。

缺点：
       1、由于在客户端和真实主题之间增加了代理对象，因此有些类型的代理模式可能会造成请求的处理速度变慢。
       2、实现代理模式需要额外的工作，有些代理模式的实现非常复杂。

使用场景：
       1、远程代理。
       2、虚拟代理。
       3、Copy-on-Write 代理。
       4、保护（Protect or Access）代理。
       5、Cache代理。 6、防火墙（Firewall）代理。
       7、同步化（Synchronization）代理。
       8、智能引用（Smart Reference）代理。

注意事项：
       1、和适配器模式的区别：适配器模式主要改变所考虑对象的接口，而代理模式不能改变所代理类的接口。
       2、和装饰器模式的区别：装饰器模式为了增强功能，而代理模式是为了加以控制。
*/

@protocol GHIRequestManager <NSObject>

- (NSString *)sendRequest:(NSDictionary *)params;

@end

//真整的网络请求类
@interface GHTrueRequestManager : NSObject <GHIRequestManager>

@end

//代理
@interface GHRequestManagerProxy : NSObject <GHIRequestManager>

@end

static inline void ghProxy_test() {
    id<GHIRequestManager> requestManager = [GHRequestManagerProxy new];
    //可以在代理类，里面进行权限等判断，也可以mock数据，不影响真实类的实现
    
    //与装饰者模式的区别？
    //装饰器模式关注于在一个对象上动态的添加方法，然而代理模式关注于控制对对象的访问。
    //换句话 说，用代理模式，代理类（proxy class）可以对它的客户隐藏一个对象的具体信息。
    //因此，当使用代理模式的时候，我们常常在一个代理类中创建一个对象的实例。
    //并且，当我们使用装饰器模 式的时候，我们通常的做法是将原始对象作为一个参数传给装饰者的构造器。
    //使用代理模式，代理和真实对象之间的的关系通常在编译时就已经确定了，而装饰者能够在运行时递归地被构造。
    //【最后一句是重点，代理模式往往是单层的，而装饰者可能是多层的】
    NSString *result = [requestManager sendRequest:@{@"userName":@"zhangsan"}];
    NSLog(@"%@",result);
}

NS_ASSUME_NONNULL_END
