//
//  GHNullObjModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
【空对象模式】
 
 减少空的判断，提供默认行为
*/

//用户
@protocol GHIAccount <NSObject>

- (NSString *)name;

@end

@interface GHAccount : NSObject <GHIAccount>
//
@property (nonatomic,copy) NSString *name;
@end

@interface GHNullAccount : NSObject <GHIAccount>

@end

@interface GHAccountManager : NSObject

- (id<GHIAccount>)getAccountWithName: (NSString *)name;

@end

static inline void ghNullObj_test() {
    GHAccountManager *manager = [GHAccountManager new];
    id<GHIAccount> account1 = [manager getAccountWithName:@"A"];
    NSLog(@"userName:%@",account1.name);
    
    id<GHIAccount> account2 = [manager getAccountWithName:@"X"];
    NSLog(@"userName:%@",account2.name);
}

NS_ASSUME_NONNULL_END
