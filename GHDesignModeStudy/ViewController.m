//
//  ViewController.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "ViewController.h"
#import "GHAbstractFactoryModel.h"
#import "GHSingletonModel.h"
#import "GHBuilderModel.h"
#import "GHProtoModel.h"
#import "GHAdapterModel.h"
#import "GHBridgeModel.h"
#import "GHFilterModel.h"
#import "GHDecoratorModel.h"
#import "GHFacadeModel.h"
#import "GHFlyweightModel.h"
#import "GHProxyModel.h"
#import "GHResponChainModel.h"
#import "GHCommandModel.h"
#import "GHInterpreterModel.h"
#import "GHIteratorModel.h"
#import "GHMediatorModel.h"
#import "GHMementoModel.h"
#import "GHObserverModel.h"
#import "GHStateModel.h"
#import "GHNullObjModel.h"
#import "GHStrategyModel.h"
#import "GHTemplateModel.h"
#import "GHVisitorModel.h"
#import "GHMVCModel.h"
#import "GHBusinessDelegateModel.h"
#import "GHComposeEntityModel.h"
#import "GHDataAccessObjModel.h"
#import "GHFrontControllerModel.h"
#import "GHInterceptingFilterModel.h"
#import "GHServiceLocatorModel.h"
#import "GHTransferObjModel.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    //构造对象模式
    //ghFactory_test();  //工厂模式
    //ghAbstractFactory_test(); //抽象工厂模式
    //ghSigleton_test(); //单例模式
    //ghBuilder_test();  //建造者模式
    //ghProto_test();  //原型模式
    
    //结构型模式
    //ghAdapter_test(); //适配器模式
    //ghBrige_test(); //桥接模式
    //ghFilter_test(); //过滤器模式
    //ghDecorate_test(); //装饰者模式
    //ghFacade_test(); //外观模式
    //ghFlyWeight_test(); //享元模式
    //ghProxy_test(); //代理模式
    
    //行为型模式
    //ghResonsChain_test(); //责任链模式
    //ghCommand_test(); //命令模式
    //ghInterpreter_test(); //解释器模式
    //ghIterator_test(); //迭代器模式
    //ghMediator_test(); //中介者模式
    //ghMemento_test(); //备忘录模式
    //ghObserver_test();//观察者模式
    //ghState_test(); //状态模式
    //ghNullObj_test(); //空对象模式
    //ghStrategy_test(); //策略模式
    //ghTemplate_test(); //模板模式
    //ghVisitor_test();//访问者模式
    
    //业务型模式
    //ghMVC_test(); mvc模式
    //ghBusinessDelegate_test(); //业务代理
    //ghComposeEntity_test(); //组合实体
    //ghDataAccess_test(); //数据访问对象模式
    //ghFrontController_test(); //前段控制器模式
    //ghInterceptingFilter_test(); //拦截过滤器模式
    //ghServiceLocation_test(); //服务定位模式
    //ghTransferObj_test(); //传输对象模式
}


@end
