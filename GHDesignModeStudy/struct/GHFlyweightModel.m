//
//  GHFlyweightModel.m
//  GHDesignModeStudy
//
//  Created by GuangHui Zhao on 2020/3/24.
//  Copyright © 2020 GuangHui Zhao. All rights reserved.
//

#import "GHFlyweightModel.h"

@implementation GHOnlyPerson

@end

@interface GHOnlyPersonFlyweightFactory ()

//
@property (nonatomic,strong) NSMutableDictionary<NSString*,GHOnlyPerson*> *persons;

@end

@implementation GHOnlyPersonFlyweightFactory

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.persons = [NSMutableDictionary new];
    }
    return self;
}

- (GHOnlyPerson *)personWithName: (NSString *)userName {
    GHOnlyPerson *person = self.persons[userName];
    if (!person) {
        person = [GHOnlyPerson new];
        person.userName = userName;
        self.persons[userName] = person;
    }
    return person;
}

- (void)showPersons {
    NSArray *persons = [self.persons allValues];
    persons = [persons sortedArrayUsingComparator:^NSComparisonResult(GHOnlyPerson *obj1, GHOnlyPerson *obj2) {
        return obj1.vote < obj2.vote;
    }];
    NSLog(@"--------------");
    for (GHOnlyPerson *person in persons) {
        NSLog(@"name:%@ vote:%d",person.userName,person.vote);
    }
    NSLog(@"--------------");
}

@end
