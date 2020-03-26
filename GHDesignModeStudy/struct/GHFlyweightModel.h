//
//  GHFlyweightModel.h
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
【享元模式】
 
主要解决：
       在有大量对象时，有可能会造成内存溢出，我们把其中共同的部分抽象出来，如果有相同的业务请求，直接返回在内存中已有的对象，避免重新创建。

优点：
       大大减少对象的创建，降低系统的内存，使效率提高。

缺点：
       提高了系统的复杂度，需要分离出外部状态和内部状态，而且外部状态具有固有化的性质，不应该随着内部状态的变化而变化，否则会造成系统的混乱。

使用场景：
       1、系统有大量相似对象。
       2、需要缓冲池的场景。

注意事项：
       1、注意划分外部状态和内部状态，否则可能会引起线程安全问题。
       2、这些类必须有一个工厂对象加以控制。
*/

@interface GHOnlyPerson : NSObject

//
@property (nonatomic,strong) NSString *userName;
//
@property (nonatomic,assign) int vote;

@end

@interface GHOnlyPersonFlyweightFactory : NSObject

- (GHOnlyPerson *)personWithName: (NSString *)userName;
- (void)showPersons;

@end

static inline void ghFlyWeight_test() {
    //只创建了四个对象，模拟一个投票系统
    GHOnlyPersonFlyweightFactory *factory = [GHOnlyPersonFlyweightFactory new];
    NSArray *votes = @[@"张三",@"李四",@"王五",@"张三",@"赵六",@"王五",@"王五",@"王五",@"赵六"];
    for (NSString *userName in votes) {
        GHOnlyPerson *person = [factory personWithName:userName];
        person.vote ++;
    }
    [factory showPersons];
}


NS_ASSUME_NONNULL_END
