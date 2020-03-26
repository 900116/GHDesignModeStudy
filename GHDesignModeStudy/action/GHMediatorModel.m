//
//  GHMediatorModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHMediatorModel.h"

@implementation GHUser

- (void)say:(NSString *)something {
    [self.chatRoom sendMsg:something usr:self];
}

- (void)receiveMsg:(NSString *)something {
    NSLog(@"[%@]收到消息: [%@]",self.userName,something);
}

- (void)setChatRoom:(id<GHIChatRoom>)chatRoom {
    _chatRoom = chatRoom;
    [chatRoom joinRoom:self];
}

@end

@interface GHChatRoom ()

//
@property (nonatomic,strong) NSMutableArray<id<GHIChatUser>> *users;

@end

@implementation GHChatRoom

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.users = [NSMutableArray new];
    }
    return self;
}

- (void)joinRoom:(id<GHIChatUser>)user {
    [self.users addObject:user];
}

- (void)sendMsg:(NSString *)msg usr:(id<GHIChatUser>)user {
    NSLog(@"%@说:%@",user.userName,msg);
    [self.users enumerateObjectsUsingBlock:^(id<GHIChatUser>  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if (![obj.userName isEqualToString:user.userName]) {
            [obj receiveMsg:msg];
        }
    }];
}

@end
