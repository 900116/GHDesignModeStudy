//
//  GHMVCModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHMVCModel.h"

@implementation GHStudentModel

- (void)setName:(NSString *)name {
    _name = name;
    NSLog(@"设置名称:%@",name);
}

@end

@implementation GHStudentView

- (void)updateViewWithModel:(id<GHStudentViewModel>)model {
    NSLog(@"刷新视图");
}

@end

@implementation GHStudentController

- (void)setUserName:(NSString *)userName {
    self.model.name = userName;
}

- (NSString *)userName {
    return self.model.name;
}

- (void)updateView {
    [self.studentView updateViewWithModel:self.model];
}

@end
