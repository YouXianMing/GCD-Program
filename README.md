# GCD-Program

* [swift版本GCD](https://github.com/YouXianMing/Swift-GCD)


```
//
//  ViewController.m
//  GCD
//
//  Created by YouXianMing on 15/10/19.
//  Copyright © 2015年 ZiPeiYi. All rights reserved.
//

#import "ViewController.h"
#import "GCD.h"

@interface ViewController ()

@property (nonatomic, strong) GCDTimer *timer;

@end

@implementation ViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [GCDQueue executeInGlobalQueue:^{
        
        // download task, etc
        
        [GCDQueue executeInMainQueue:^{
            
            // update UI
        }];
    }];
    
    
    
    
    // init group
    GCDGroup *group = [GCDGroup new];
    
    // add to group
    [[GCDQueue globalQueue] execute:^{
        // task one
    } inGroup:group];
    
    // add to group
    [[GCDQueue globalQueue] execute:^{
        // task two
    } inGroup:group];
    
    // notify in mainQueue
    [[GCDQueue mainQueue] notify:^{
        // task three
    } inGroup:group];
    
    
    
    
    // init timer
    self.timer = [[GCDTimer alloc] initInQueue:[GCDQueue mainQueue]];
    
    // timer event
    [self.timer event:^{
        // task
    } timeInterval:NSEC_PER_SEC * 3];
    
    // start timer
    [self.timer start];
    
    
    
    
    // init semaphore
    GCDSemaphore *semaphore = [GCDSemaphore new];
    
    // wait
    [GCDQueue executeInGlobalQueue:^{
        
        [semaphore wait];
        // todo sth else
    }];
    
    // signal
    [GCDQueue executeInGlobalQueue:^{
        
        // do sth
        [semaphore signal];
    }];
}

@end
```
