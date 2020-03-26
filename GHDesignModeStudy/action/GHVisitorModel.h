//
//  GHVisitorModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
【访问者模式】
 
主要解决：
        稳定的数据结构和易变的操作耦合问题。

优点：
        1、符合单一职责原则。
        2、优秀的扩展性。
        3、灵活性。

缺点：
        1、具体元素对访问者公布细节，违反了迪米特原则。
        2、具体元素变更比较困难。
        3、违反了依赖倒置原则，依赖了具体类，没有依赖抽象。
 
使用场景：
        1、对象结构中对象对应的类很少改变，但经常需要在此对象结构上定义新的操作。
        2、需要对一个对象结构中的对象进行很多不同的并且不相关的操作，而需要避免让这些操作"污染"这些对象的类，也不希望在增加新操作时修改这些类。

 注意事项：
        访问者可以对功能进行统一，可以做报表、UI、拦截器与过滤器。
*/
@protocol GHIVisitor;

@protocol GHIVisitorPerson <NSObject>

- (void)accept:(id<GHIVisitor>)visitor; //接受采访

@end

@interface GHVisitorEmployee : NSObject <GHIVisitorPerson>

//薪水
@property (nonatomic,assign) NSInteger salary;

//
@property (nonatomic,assign) NSInteger score; //绩效

//
@property (nonatomic,assign) int year; //工作年限

@end

@interface GHEmployeeBased : GHVisitorEmployee

@end


@interface GHEmployeeManager : GHVisitorEmployee

//
@property (nonatomic,assign) NSInteger rightValue; //期权

@property (nonatomic,assign) int managerYear; //管理年限

@end

//抽象访问者
@protocol GHIVisitor <NSObject>

- (void)visitorBased: (GHEmployeeBased *)base;
- (void)visitorManager: (GHEmployeeManager *)manager;

@end

@interface GHAccountVisitor : NSObject <GHIVisitor> //会计

@end

@interface GHHRVisitor : NSObject <GHIVisitor> //hr

@end

@interface GHVisiterManager : NSObject <GHIVisitorPerson>

- (void)addPerson:(id<GHIVisitorPerson>)person;

@end

static inline void ghVisitor_test() {
    GHVisiterManager *manager = [GHVisiterManager new];

    //经理
    GHEmployeeManager *eManager1 = [[GHEmployeeManager alloc]init];
    eManager1.managerYear = 3;
    eManager1.score = 4;
    eManager1.year = 6;
    eManager1.rightValue = 3000;
    eManager1.salary = 30000;
    
    //普通员工
    GHEmployeeBased *base1 = [[GHEmployeeBased alloc]init];
    base1.year = 3;
    base1.score = 3;
    base1.salary = 10000;
    
    [manager addPerson:eManager1];
    [manager addPerson:base1];
    
    id <GHIVisitor> hrVistor = [GHHRVisitor new];
    [manager accept:hrVistor];
    
    id <GHIVisitor> accountVisitor = [GHAccountVisitor new];
    [manager accept:accountVisitor];
}

NS_ASSUME_NONNULL_END
