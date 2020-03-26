//
//  GHAdapterModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHAdapterModel.h"

@implementation GH35MMLoudSpeaker

- (void)play35MMData:(NSString *)to35mmData {
    NSLog(@"播放 %@",to35mmData);
}

@end

@interface GHUsbLoudSpeaker ()

@end

@implementation GHUsbLoudSpeaker

- (void)playUsbData:(NSString *)useData {
    NSString *to35mmData = [useData stringByReplacingOccurrencesOfString:@"usb" withString:@"35MM"];
    [self play35MMData:to35mmData];
}

@end


@implementation GHComputer : NSObject

- (void)play:(NSString *)usbData {
    [self.usbDataplayer playUsbData:usbData];
}

@end
