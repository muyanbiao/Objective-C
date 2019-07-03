//
//  BNRLogger.h
//  Callbacks
//
//  Created by Max on 2019/7/3.
//  Copyright © 2019 Max. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BNRLogger : NSObject

@property(nonatomic) NSDate *lastTime;
- (NSString *)lastTimeString;
- (void)updateLastTime:(NSTimer *)t;

@end

NS_ASSUME_NONNULL_END
