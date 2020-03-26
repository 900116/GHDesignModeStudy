//
//  GHTransferObjModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
传输对象模式
传输对象模式（Transfer Object Pattern）用于从客户端向服务器一次性传递带有多个属性的数据。传输对象也被称为数值对象。传输对象是一个具有 getter/setter 方法的简单的 POJO 类，它是可序列化的，所以它可以通过网络传输。它没有任何的行为。服务器端的业务类通常从数据库读取数据，然后填充 POJO，并把它发送到客户端或按值传递它。对于客户端，传输对象是只读的。客户端可以创建自己的传输对象，并把它传递给服务器，以便一次性更新数据库中的数值。以下是这种设计模式的实体。

业务对象（Business Object） - 为传输对象填充数据的业务服务。
传输对象（Transfer Object） - 简单的 POJO，只有设置/获取属性的方法。
客户端（Client） - 客户端可以发送请求或者发送传输对象到业务对象。
*/


@interface GHTStudent : NSObject

//
@property (nonatomic,copy) NSString *name;
@property (nonatomic,assign) int identifier;

@end

@interface GHTStudentDAO: NSObject

- (NSArray<GHTStudent *>*)getStudents;
- (GHTStudent *)getStudent:(int)identifier;
- (void)updateStudent:(GHTStudent*)student;
- (void)deleteStudent:(GHTStudent*)student;

@end

static inline void ghTransferObj_test() {
    GHTStudentDAO *dao = [GHTStudentDAO new];
    
    NSLog(@"----------------");
    [[dao getStudents] enumerateObjectsUsingBlock:^(GHTStudent * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        NSLog(@"name:%@",obj.name);
    }];
    
    GHTStudent *stu = [dao getStudent:0];
    NSLog(@"originalName:%@",stu.name);
    stu.name = @"Michael";
    [dao updateStudent:stu];
    
    stu = [dao getStudent:0];
    NSLog(@"newName:%@",stu.name);
}

NS_ASSUME_NONNULL_END
