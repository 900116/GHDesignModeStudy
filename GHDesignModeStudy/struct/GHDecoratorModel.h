//
//  GHDecoratorModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
【装饰者模式】
 
主要解决：
       一般的，我们为了扩展一个类经常使用继承方式实现，由于继承为类引入静态特征，并且随着扩展功能的增多，子类会很膨胀。

优点：
       装饰类和被装饰类可以独立发展，不会相互耦合，装饰模式是继承的一个替代模式，装饰模式可以动态扩展一个实现类的功能。

缺点：
       多层装饰比较复杂。

使用场景：
       1、扩展一个类的功能。
       2、动态增加功能，动态撤销。

注意事项：
       可代替继承。
*/

@interface GHNetWorkManager : NSObject

- (void)sendRequest: (NSDictionary *)params;

@end

@interface GHNetWorkLoggerManager : GHNetWorkManager

- (instancetype)initWithNetWorkManager:(GHNetWorkManager *)netWorkManager;

@end

@interface GHNetWorkLoadingManager : GHNetWorkManager

- (instancetype)initWithNetWorkManager:(GHNetWorkManager *)netWorkManager;

@end

static inline void ghDecorate_test() {
    //在扩展上，不需要改动原来类的代码baseManager，降低风险，而且可以灵活的组合成各种版本对象，灵活更改
    GHNetWorkManager *baseManager = [GHNetWorkManager new];
    
    //此处是多态，在接口使用上baseManager和loggerManager 没有区别
    GHNetWorkManager *loggerManager = [[GHNetWorkLoggerManager alloc]initWithNetWorkManager:baseManager];
    
    //带loading的
    GHNetWorkManager *loading = [[GHNetWorkLoadingManager alloc]initWithNetWorkManager:baseManager];
    
    //既有loading又有logger的
    GHNetWorkManager *loaddingLogger = [[GHNetWorkLoadingManager alloc]initWithNetWorkManager:loggerManager];
    
    NSDictionary *params = @{@"userName":@"zhangsan"};
    
    //不带参数打印
    [baseManager sendRequest:params];

    NSLog(@"-------");
    
    //带参数打印
    [loggerManager sendRequest:params];

    NSLog(@"-------");
    
    //只带loading的
    [loading sendRequest:params];

    NSLog(@"-------");

    //又有loading 又有logger
    [loaddingLogger sendRequest:params];

    NSLog(@"-------");
}

NS_ASSUME_NONNULL_END
