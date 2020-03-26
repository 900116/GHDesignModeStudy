//
//  GHDataAccessObjModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
数据访问对象模式
数据访问对象模式（Data Access Object Pattern）或 DAO 模式用于把低级的数据访问 API 或操作从高级的业务服务中分离出来。以下是数据访问对象模式的参与者。

数据访问对象接口（Data Access Object Interface） - 该接口定义了在一个模型对象上要执行的标准操作。
数据访问对象实体类（Data Access Object concrete class） - 该类实现了上述的接口。该类负责从数据源获取数据，数据源可以是数据库，也可以是 xml，或者是其他的存储机制。
模型对象/数值对象（Model Object/Value Object） - 该对象是简单的 POJO，包含了 get/set 方法来存储通过使用 DAO 类检索到的数据。
*/

@interface GHDataAccessStudent : NSObject

//
@property (nonatomic,copy) NSString *name;
@property (nonatomic,assign) int identifier;

@end

@protocol GHDataAccessStudentDAO <NSObject>

- (NSArray<GHDataAccessStudent *>*)getStudents;
- (GHDataAccessStudent *)getStudent:(int)identifier;
- (void)updateStudent:(GHDataAccessStudent*)student;
- (void)deleteStudent:(GHDataAccessStudent*)student;

@end

@interface GHDataAccessStudentDAOImp : NSObject <GHDataAccessStudentDAO>

@end

static inline void ghDataAccess_test() {
    id <GHDataAccessStudentDAO> dao = [GHDataAccessStudentDAOImp new];
    
    NSLog(@"----------------");
    [[dao getStudents] enumerateObjectsUsingBlock:^(GHDataAccessStudent * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        NSLog(@"name:%@",obj.name);
    }];
    
    GHDataAccessStudent *stu = [dao getStudent:0];
    NSLog(@"originalName:%@",stu.name);
    stu.name = @"Michael";
    [dao updateStudent:stu];
    
    stu = [dao getStudent:0];
    NSLog(@"newName:%@",stu.name);
}

NS_ASSUME_NONNULL_END
