//
//  GHNullObjModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHNullObjModel.h"

@implementation GHAccount

@end

@implementation GHNullAccount

- (NSString *)name {
    return @"没有该用户";
}

@end


@implementation GHAccountManager

- (id<GHIAccount>)getAccountWithName: (NSString *)name {
    NSArray *existName = @[@"A",@"B",@"C",@"D"];
    if ([existName containsObject:name]) {
        GHAccount *account = [GHAccount new];
        account.name = name;
        return account;
    }
    return [GHNullAccount new];
}

@end

