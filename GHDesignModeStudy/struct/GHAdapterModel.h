//
//  GHAdapterModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
【适配器模式】
 
主要解决：
       常常要将一些"现存的对象"放到新的环境中，而新环境要求的接口是现对象不能满足的。

优点：
       1、可以让任何两个没有关联的类一起运行。
       2、提高了类的复用。
       3、增加了类的透明度。 4、灵活性好。

缺点：
       1、过多地使用适配器，会让系统非常零乱，不易整体进行把握。
          比如，明明看到调用的是 A 接口，其实内部被适配成了B接口的实现，
          一个系统如果太多出现这种情况，无异于一场灾难。
          因此如果不是很有必要，可以不使用适配器，而是直接对系统进行重构。
        2.由于 JAVA 至多继承一个类，所以至多只能适配一个适配者类，而且目标类必须是抽象类。

使用场景：
       有动机地修改一个正常运行的系统的接口，这时应该考虑使用适配器模式。

注意事项：
       适配器不是在详细设计时添加的，而是解决正在服役的项目的问题。
*/

@protocol GHUsbPlayer <NSObject>

- (void)playUsbData:(NSString *)useData;

@end

@interface GH35MMLoudSpeaker : NSObject

@end

@interface GHUsbLoudSpeaker : GH35MMLoudSpeaker <GHUsbPlayer>

@end


@interface GHComputer : NSObject

@property (nonatomic,strong) id <GHUsbPlayer> usbDataplayer;

- (void)play:(NSString *)usbData;

@end

static inline void ghAdapter_test() {
    //GH35MMLoudSpeaker 只能播放3.5mm数据
    //computer只能传输usb数据
    //所有这两个已有的类没法协作
    //GHUsbLoudSpeaker 实现了播放usb数据接口，内部将usb数据变成了3.5mm数据，使得这两个类可以协作
    
    GHComputer *computer = [GHComputer new];
    computer.usbDataplayer = [GHUsbLoudSpeaker new];
    [computer play:@"usb数据"];
}

NS_ASSUME_NONNULL_END
