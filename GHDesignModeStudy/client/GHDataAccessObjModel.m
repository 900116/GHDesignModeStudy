//
//  GHDataAccessObjModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHDataAccessObjModel.h"

@implementation GHDataAccessStudent
@end


@interface GHDataAccessStudentDAOImp ()

//
@property (nonatomic,strong) NSMutableArray<GHDataAccessStudent *> *students;

@end


@implementation GHDataAccessStudentDAOImp

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.students = [NSMutableArray new];
        GHDataAccessStudent *stu = [GHDataAccessStudent new];
        stu.identifier = 0;
        stu.name = @"John";
        
        [self.students addObject:stu];
        
        stu = [GHDataAccessStudent new];
        stu.identifier = 1;
        stu.name = @"Robert";
        [self.students addObject:stu];
    }
    return self;
}

- (NSArray<GHDataAccessStudent *> *)getStudents {
    return self.students;
}

- (GHDataAccessStudent *)getStudent:(int)identifier {
    return self.students[identifier];
}

- (void)deleteStudent:(GHDataAccessStudent *)student {
    return [self.students removeObjectAtIndex:student.identifier];
}

- (void)updateStudent:(GHDataAccessStudent *)student {
    self.students[student.identifier].name = student.name;
}

@end
