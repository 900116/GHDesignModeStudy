//
//  GHProxyModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHProxyModel.h"


//真整的网络请求类
@implementation GHTrueRequestManager

- (NSString *)sendRequest:(NSDictionary *)params {
    return @"真实数据";
}

@end

//代理
@interface GHRequestManagerProxy ()

//
@property (nonatomic,strong) GHTrueRequestManager *trueManager;

@end

//代理
@implementation GHRequestManagerProxy

- (GHTrueRequestManager *)trueManager {
    if (!_trueManager) {
        _trueManager = [GHTrueRequestManager new];
    }
    return _trueManager;
}

- (NSString *)sendRequest:(NSDictionary *)params {
    if (params.count == 0) {
        return nil;
    }
#if DEBUG
    return @"mock数据";
#endif
    NSString *result = [self.trueManager sendRequest:params];
    return result;
}

@end
