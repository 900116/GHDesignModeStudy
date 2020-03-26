//
//  GHFrontControllerModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHFrontControllerModel.h"

@implementation GHFCView

- (void)show {};

@end

@implementation GHFCStudentView

- (void)show {
    NSLog(@"展示学生视图");
}

@end

@implementation GHFCTeacherView


- (void)show {
    NSLog(@"展示老师视图");
}

@end

@interface GHDispatcher ()
//
@property (nonatomic,strong) GHFCStudentView *stuView;
@property (nonatomic,strong) GHFCTeacherView *teaView;

@end

@implementation GHDispatcher

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.stuView = [GHFCStudentView new];
        self.teaView = [GHFCTeacherView new];
    }
    return self;
}

- (void)dispatch:(NSString *)userType {
    if ([userType isEqualToString:@"STU"]) {
        [self.stuView show];
    }
    if ([userType isEqualToString:@"TEA"]) {
        [self.teaView show];
    }
}

@end

@interface GHFrontController ()

//
@property (nonatomic,strong) GHDispatcher *disPatcher;

@end

@implementation GHFrontController

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.disPatcher = [GHDispatcher new];
    }
    return self;
}

- (void)login: (NSString *)userType {
    //登录成功
    [self.disPatcher dispatch:userType];
}

@end
