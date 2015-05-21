# GCD-Program
![image.gif](http://images0.cnblogs.com/blog2015/607542/201505/191755367606422.gif)

http://home.cnblogs.com/u/YouXianMing/



> Normal use

```
    [GCDQueue executeInGlobalQueue:^{
        
        // download task, etc
        
        [GCDQueue executeInMainQueue:^{
            
            // update UI
        }];
    }];
```

> Use group

```
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
```

> Timer

```
#import "ViewController.h"
#import "GCD.h"

@interface ViewController ()

@property (nonatomic, strong) GCDTimer *timer;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // init timer
    self.timer = [[GCDTimer alloc] initInQueue:[GCDQueue mainQueue]];
    
    // timer event
    [self.timer event:^{
        // task
    } timeInterval:NSEC_PER_SEC * 3];
    
    // start timer
    [self.timer start];
}

@end
```



> Use semaphore

```
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
```
