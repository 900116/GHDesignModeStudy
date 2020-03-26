//
//  GHMVCModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
 MVC 模式
 MVC 模式代表 Model-View-Controller（模型-视图-控制器） 模式。这种模式用于应用程序的分层开发。

 Model（模型） - 模型代表一个存取数据的对象或 JAVA POJO。它也可以带有逻辑，在数据变化时更新控制器。
 View（视图） - 视图代表模型包含的数据的可视化。
 Controller（控制器） - 控制器作用于模型和视图上。它控制数据流向模型对象，并在数据变化时更新视图。它使视图与模型分离开。
 */

@protocol GHStudentViewModel <NSObject>

@property (nonatomic,copy) NSString *name;

@end

@interface GHStudentModel : NSObject <GHStudentViewModel>

//
@property (nonatomic,copy) NSString *name;

@end

@interface GHStudentView : NSObject

- (void)updateViewWithModel:(id<GHStudentViewModel>)model;

@end

@interface GHStudentController : NSObject

//
@property (nonatomic,strong) GHStudentModel *model;
//
@property (nonatomic,strong) GHStudentView *studentView;

- (void)setUserName: (NSString *)userName;
- (NSString *)userName;
- (void)updateView;

@end

static inline void ghMVC_test () {
    GHStudentController *controller = [GHStudentController new];
    GHStudentModel *model = [GHStudentModel new];
    GHStudentView *view = [GHStudentView new];
    controller.model = model;
    controller.studentView = view;
    
    [controller setUserName:@"3"];
    [controller updateView];
}

NS_ASSUME_NONNULL_END
