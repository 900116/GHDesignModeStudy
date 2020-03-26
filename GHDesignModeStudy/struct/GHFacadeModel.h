//
//  GHFacadeModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
【外观模式】
 
主要解决：
       降低访问复杂系统的内部子系统时的复杂度，简化客户端与之的接口。

优点：
       1、减少系统相互依赖。
       2、提高灵活性。
       3、提高了安全性。

缺点：
       不符合开闭原则，如果要改东西很麻烦，继承重写都不合适。

使用场景：
       1、为复杂的模块或子系统提供外界访问的模块。
       2、子系统相对独立。
       3、预防低水平人员带来的风险。

注意事项：
       在层次化结构中，可以使用外观模式定义系统中每一层的入口。
*/

@interface GHLoginModule : NSObject

- (void)login:(NSString *)userName password:(NSString *)passowrd;
- (void)logOut;

@end

@interface GHOrderModle : NSObject

- (void)buy:(NSString *)goodsId;

@end


@interface GHApplicationManager : NSObject

- (void)login:(NSString *)userName password:(NSString *)passowrd;
- (void)logOut;

- (void)buy:(NSString *)goodsId;

@end

static inline void ghFacade_test() {
    GHApplicationManager *manager = [GHApplicationManager new];
    //隐藏内部的实现，降低外部的复杂性,隐藏了使用GHLoginModule和GHOrderModle这一事实
    [manager login:@"123" password:@"123"];

    [manager buy:@"1"];
    
    [manager logOut];
}

NS_ASSUME_NONNULL_END
