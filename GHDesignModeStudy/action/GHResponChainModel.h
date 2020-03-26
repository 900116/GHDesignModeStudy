//
//  GHResponChainModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/*
【责任链模式】
 
主要解决：
       职责链上的处理者负责处理请求，客户只需要将请求发送到职责链上即可，无须关心请求的处理细节和请求的传递，所以职责链将请求的发送者和请求的处理者解耦了。

优点：
       1、降低耦合度。它将请求的发送者和接收者解耦。
       2、简化了对象。使得对象不需要知道链的结构。
       3、增强给对象指派职责的灵活性。通过改变链内的成员或者调动它们的次序，允许动态地新增或者删除责任。
       4、增加新的请求处理类很方便。

缺点：
       1、不能保证请求一定被接收。
       2、系统性能将受到一定影响，而且在进行代码调试时不太方便，可能会造成循环调用。
       3、可能不容易观察运行时的特征，有碍于除错。

使用场景：
       1、有多个对象可以处理同一个请求，具体哪个对象处理该请求由运行时刻自动确定。
       2、在不明确指定接收者的情况下，向多个对象中的一个提交一个请求。
       3、可动态指定一组对象处理请求。

注意事项：
       在 JAVA WEB 中遇到很多应用。
*/

typedef NS_ENUM(NSUInteger,GHLoggerLevel) {
    GHLoggerLevelInfo,
    GHLoggerLevelDebug,
    GHLoggerLevelError
};

@interface GHAbstractLogger : NSObject

@property (nonatomic,strong) GHAbstractLogger *nextLogger;
- (void)logger:(NSString *)msg level:(GHLoggerLevel)level;
@end

@interface GHConsleLogger : GHAbstractLogger

@end

@interface GHErrorLogger : GHAbstractLogger

@end


@interface GHFileLogger : GHAbstractLogger

@end

//需求
//错误日志，只记录错误相关的
//文件日志，要记录debug相关日志和错误日志
//控制台日志，要记录所有的日志
static inline void ghResonsChain_test() {
    //构造责任链，这一步可以封装起来，进行隐藏
    GHAbstractLogger *errorLogger = [GHErrorLogger new];
    GHAbstractLogger *consoleLogger = [GHConsleLogger new];
    GHAbstractLogger *fileLogger = [GHFileLogger new];
    
    errorLogger.nextLogger = fileLogger;
    fileLogger.nextLogger = consoleLogger;
    
    
    //外面只需要知道有logger对象以及logger:level方法即可，
    GHAbstractLogger *logger = errorLogger;
    [logger logger:@"info" level:GHLoggerLevelInfo];
    [logger logger:@"debug" level:GHLoggerLevelDebug];
    [logger logger:@"error" level:GHLoggerLevelError];
}

NS_ASSUME_NONNULL_END
