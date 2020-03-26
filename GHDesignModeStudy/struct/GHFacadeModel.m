//
//  GHFacadeModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHFacadeModel.h"

@interface GHLoginModule ()

//
@property (nonatomic,assign) BOOL isLogin;

@end

@implementation GHLoginModule

- (void)login:(NSString *)userName password:(NSString *)passowrd {
    NSLog(@"登录");
    self.isLogin = YES;
}

- (void)logOut {
    NSLog(@"登出");
    self.isLogin = NO;
}

@end

@implementation GHOrderModle

- (void)buy:(NSString *)goodsId {
    NSLog(@"买");
}

@end

@interface GHApplicationManager ()

//
@property (nonatomic,strong) GHLoginModule *loginModule;
//
@property (nonatomic,strong) GHOrderModle *orderModule;

@end

@implementation GHApplicationManager

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.loginModule = [GHLoginModule new];
        self.orderModule = [GHOrderModle new];
    }
    return self;
}

- (void)login:(NSString *)userName password:(NSString *)passowrd {
    [self.loginModule login:userName password:passowrd];
}

- (void)logOut {
    [self.loginModule logOut];
}

- (void)buy:(NSString *)goodsId {
    if (!self.loginModule.isLogin) {
        NSLog(@"需要登录");
        return;
    }
    [self.orderModule buy:goodsId];
}

@end
