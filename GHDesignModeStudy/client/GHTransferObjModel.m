//
//  GHTransferObjModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHTransferObjModel.h"

@implementation GHTStudent
@end


@interface GHTStudentDAO ()

//
@property (nonatomic,strong) NSMutableArray<GHTStudent *> *students;

@end


@implementation GHTStudentDAO

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.students = [NSMutableArray new];
        GHTStudent *stu = [GHTStudent new];
        stu.identifier = 0;
        stu.name = @"John";
        
        [self.students addObject:stu];
        
        stu = [GHTStudent new];
        stu.identifier = 1;
        stu.name = @"Robert";
        [self.students addObject:stu];
    }
    return self;
}

- (NSArray<GHTStudent *> *)getStudents {
    return self.students;
}

- (GHTStudent *)getStudent:(int)identifier {
    return self.students[identifier];
}

- (void)deleteStudent:(GHTStudent *)student {
    return [self.students removeObjectAtIndex:student.identifier];
}

- (void)updateStudent:(GHTStudent *)student {
    self.students[student.identifier].name = student.name;
}

@end
