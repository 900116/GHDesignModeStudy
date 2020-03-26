//
//  GHVisitorModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHVisitorModel.h"

@implementation GHVisitorEmployee

- (void)accept:(id<GHIVisitor>)visitor {
    if ([self isKindOfClass:[GHEmployeeBased class]]) {
        [visitor visitorBased:(GHEmployeeBased *)self];
    } else if([self isKindOfClass:[GHEmployeeManager class]]) {
        [visitor visitorManager:(GHEmployeeManager *)self];
    }
}

@end

@implementation GHEmployeeBased
@end

@implementation GHEmployeeManager

@end


@implementation GHAccountVisitor

- (void)visitorManager:(GHEmployeeManager *)manager {
    NSLog(@"会计统计经理的薪水和期权 salary:%ld rightValue:%ld",manager.salary,manager.rightValue);
}

- (void)visitorBased:(GHEmployeeBased *)base {
    NSLog(@"会计统计普通员工的薪水 salary:%ld",base.salary);
}

@end


@implementation GHHRVisitor

- (void)visitorManager:(GHEmployeeManager *)manager {
    NSLog(@"hr关心经理的管理年限和绩效 managerYear:%d score:%ld",manager.managerYear,manager.score);
}

- (void)visitorBased:(GHEmployeeBased *)base {
    NSLog(@"hr关心普通员工的工作年限和绩效 year:%d score:%ld",base.year,base.score);
}

@end

@interface GHVisiterManager ()

//
@property (nonatomic,strong) NSMutableArray<id<GHIVisitorPerson>> *persons;

@end

@implementation GHVisiterManager

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.persons = [NSMutableArray new];
    }
    return self;
}

- (void)addPerson:(id<GHIVisitorPerson>)person {
    [self.persons addObject:person];
}

- (void)accept:(id<GHIVisitor>)visitor {
    for (id <GHIVisitorPerson> person in self.persons) {
        [person accept:visitor];
    }
}

@end
