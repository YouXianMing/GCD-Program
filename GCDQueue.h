//
//  GCDQueue.h
//  GCD
//
//  http://home.cnblogs.com/u/YouXianMing/
//  https://github.com/YouXianMing
//
//  Created by XianMingYou on 15/3/15.
//  Copyright (c) 2015年 XianMingYou. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GCDGroup;

@interface GCDQueue : NSObject

@property (strong, readonly, nonatomic) dispatch_queue_t dispatchQueue;

+ (GCDQueue *)mainQueue;
+ (GCDQueue *)globalQueue;
+ (GCDQueue *)highPriorityGlobalQueue;
+ (GCDQueue *)lowPriorityGlobalQueue;
+ (GCDQueue *)backgroundPriorityGlobalQueue;

#pragma 便利的构造方法
+ (void)executeInMainQueue:(dispatch_block_t)block;
+ (void)executeInGlobalQueue:(dispatch_block_t)block;
+ (void)executeInHighPriorityGlobalQueue:(dispatch_block_t)block;
+ (void)executeInLowPriorityGlobalQueue:(dispatch_block_t)block;
+ (void)executeInBackgroundPriorityGlobalQueue:(dispatch_block_t)block;
+ (void)executeInMainQueue:(dispatch_block_t)block afterDelaySecs:(NSTimeInterval)sec;
+ (void)executeInGlobalQueue:(dispatch_block_t)block afterDelaySecs:(NSTimeInterval)sec;
+ (void)executeInHighPriorityGlobalQueue:(dispatch_block_t)block afterDelaySecs:(NSTimeInterval)sec;
+ (void)executeInLowPriorityGlobalQueue:(dispatch_block_t)block afterDelaySecs:(NSTimeInterval)sec;
+ (void)executeInBackgroundPriorityGlobalQueue:(dispatch_block_t)block afterDelaySecs:(NSTimeInterval)sec;

#pragma 初始化以及释放
- (instancetype)init;
- (instancetype)initSerial;
- (instancetype)initSerialWithLabel:(const char *label);
- (instancetype)initConcurrent;
- (instancetype)initConcurrentWithLabel:(const char *label);

#pragma 用法
- (void)execute:(dispatch_block_t)block;
- (void)execute:(dispatch_block_t)block afterDelay:(int64_t)delta;
- (void)waitExecute:(dispatch_block_t)block;
- (void)barrierExecute:(dispatch_block_t)block;
- (void)waitBarrierExecute:(dispatch_block_t)block;
- (void)suspend;
- (void)resume;

#pragma 与GCDGroup相关
- (void)execute:(dispatch_block_t)block inGroup:(GCDGroup *)group;
- (void)notify:(dispatch_block_t)block inGroup:(GCDGroup *)group;

@end
