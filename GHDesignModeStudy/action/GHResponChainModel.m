//
//  GHResponChainModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHResponChainModel.h"

@interface GHAbstractLogger()

- (GHLoggerLevel)level;

@end

@implementation GHAbstractLogger

- (void)logger:(NSString *)msg level:(GHLoggerLevel)level {
    if (self.level <= level) {
        [self logger:msg];
    }
    [self.nextLogger logger:msg level:level];
}

- (void)logger:(NSString *)msg {}

- (GHLoggerLevel)level {
    return GHLoggerLevelInfo;
}

@end

@implementation GHConsleLogger

- (GHLoggerLevel)level {
    return GHLoggerLevelInfo;
}

- (void)logger:(NSString *)msg {
    NSLog(@"[控制台]%@",msg);
}

@end

@implementation GHErrorLogger

- (GHLoggerLevel)level {
    return GHLoggerLevelError;
}

- (void)logger:(NSString *)msg {
    NSLog(@"[错误日志]%@",msg);
}

@end


@implementation GHFileLogger

- (GHLoggerLevel)level {
    return GHLoggerLevelDebug;
}

- (void)logger:(NSString *)msg {
    NSLog(@"[文件日志]%@",msg);
}

@end
