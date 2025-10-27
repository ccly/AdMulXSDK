//
//  HJAppDelegate.m
//  AdMulXSDK
//
//  Created by ccly on 10/21/2025.
//  Copyright (c) 2025 ccly. All rights reserved.
//

#import "HJAppDelegate.h"
#import "RootViewController.h"
#import <AdMulXSDK/AdMulXSDK.h>

@implementation HJAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    
    
    HJAdConfig *config = [[HJAdConfig alloc] init];
    config.appId = @"89385817";
         
    [HJAdManager startWithAsyncConfig:config completionHandler:^(BOOL success, NSError * _Nullable error) {
        
        if(success){
            
            dispatch_async(dispatch_get_main_queue(), ^{
                //初始化开屏广告
                
            });
            
        }
        
    }];
    
    UIWindow *keyWindow = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    [keyWindow makeKeyAndVisible];
    self.window = keyWindow;
    self.window.rootViewController = [self rootViewController];
    
    return YES;
}

- (UIViewController *)rootViewController {
    RootViewController *mainViewController = [[RootViewController alloc] init];
    UINavigationController *navigationVC = [[UINavigationController alloc] initWithRootViewController:mainViewController];
    return navigationVC;
}



- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
