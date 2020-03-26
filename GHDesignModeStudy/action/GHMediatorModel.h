//
//  GHMediatorModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/*
【中介者模式】
 
主要解决：
        对象与对象之间存在大量的关联关系，这样势必会导致系统的结构变得很复杂，同时若一个对象发生改变，我们也需要跟踪与之相关联的对象，同时做出相应的处理。

优点：
        1、降低了类的复杂度，将一对多转化成了一对一。
        2、各个类之间的解耦。
        3、符合迪米特原则。

缺点：
        中介者会庞大，变得复杂难以维护。

使用场景：
        1、系统中对象之间存在比较复杂的引用关系，导致它们之间的依赖关系结构混乱而且难以复用该对象。
        2、想通过一个中间类来封装多个类中的行为，而又不想生成太多的子类。

注意事项：
        不应当在职责混乱的时候使用。
*/

@protocol GHIChatUser <NSObject>

- (void)say:(NSString *)something;
- (void)receiveMsg:(NSString *)something;
- (NSString *)userName;

@end

@protocol GHIChatRoom <NSObject>

- (void)sendMsg:(NSString *)msg usr:(id<GHIChatUser>)user;
- (void)joinRoom:(id<GHIChatUser>)user;

@end

@interface GHUser : NSObject <GHIChatUser>

//
@property (nonatomic,weak) id<GHIChatRoom> chatRoom;
//
@property (nonatomic,copy) NSString *userName;

@end

@interface GHChatRoom : NSObject <GHIChatRoom>

@end

/*
 与外观模式的区别
 
 外观模式;是一种结构化模型，中介者是行为型模式

 外观模式是对子系统提供统一的接口，中介者是用一个中介对象封装一系列同事对象的交互行为。

 外观模式所有的请求处理都委托给子系统完成，而中介者模式则由中心协调同事类和中心本身共同完成业务。
 */

static inline void ghMediator_test() {
    GHChatRoom *room = [GHChatRoom new];
    GHUser *zs = [GHUser new]; //张三 李四 王五相互发消息，避免了直接的接触
    zs.userName = @"张三";
    zs.chatRoom = room;
    
    GHUser *ls = [GHUser new];
    ls.userName = @"李四";
    ls.chatRoom = room;
    
    GHUser *ww = [GHUser new];
    ww.userName = @"王五";
    ww.chatRoom = room;
    
    [zs say:@"大家好，我叫张三"];
    [ls say:@"各位，我就是传说中的四哥"];
    [ww say:@"Hello,EveryOne"];
}


NS_ASSUME_NONNULL_END
