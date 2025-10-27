//
//  RootViewController.m
//  AdMulXDemo
//
//  Created by 枫 on 2025/10/16.
//

#import "RootViewController.h"

#import "HJExpressAdViewController.h"
#import "HJBannerAdViewController.h"
#import "HJRewardAdViewController.h"
#import "HJDrawAdViewController.h"
#import "HJFullScreenAdViewController.h"
#import "HJHalfScreenAdViewController.h"
#import "HJVideoAdViewController.h"
#import <AdMulXSDK/AdMulXSDK.h>

@interface RootViewController ()<HJSplashAdDelegate>

@property (nonatomic, strong)  HJSplashAd *hjSplashAd;


@end

@implementation RootViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

// 开屏广告
- (IBAction)splashAdvEvent:(UIButton *)sender {
    
        
    self.hjSplashAd = [[HJSplashAd alloc] initWithSlotId:@"202509294325"];
    self.hjSplashAd.delegate = self;
    [self.hjSplashAd loadAdData];
    
    
//    [self.rewardedVideoAd showAdFromRootViewController:self.navigationController];
    
}

// 信息流
- (IBAction)infoAdvEvent:(UIButton *)sender {
    [self.navigationController pushViewController:[HJExpressAdViewController new] animated:YES];
}

// banner广告
- (IBAction)bannerAdvEvent:(UIButton *)sender {
    [self.navigationController pushViewController:[HJBannerAdViewController new] animated:YES];
}

// 激励视频
- (IBAction)rewardAdvEvent:(UIButton *)sender {
    [self.navigationController pushViewController:[HJRewardAdViewController new] animated:YES];
}

// draw
- (IBAction)drawAdvEvent:(UIButton *)sender {
    [self.navigationController pushViewController:[HJDrawAdViewController new] animated:YES];
}

// 新插全屏广告
- (IBAction)fullscreenAdvEvent:(UIButton *)sender {
    [self.navigationController pushViewController:[HJFullScreenAdViewController new] animated:YES];
}

// 新插半屏广告
- (IBAction)halfscreenAdvEvent:(UIButton *)sender {
    [self.navigationController pushViewController:[HJHalfScreenAdViewController new] animated:YES];
}

- (IBAction)videoAdvEvent:(UIButton *)sender {
    [self.navigationController pushViewController:[HJVideoAdViewController new] animated:YES];
}


/**
 * 开屏|已加载广告数据
 */
- (void)hjad_splashAdDidLoad:(HJSplashAd *)splashAd {
    
    
}
/**
 * 开屏|已加载完毕广告素材,准备展示，在此处展示广告
 */
- (void)hjad_splashAdContentDidLoad:(HJSplashAd *)splashAd {
   
    [splashAd showSplashViewInRootViewController:self.navigationController];
    
}
/**
 * 开屏|广告已经可见
 */
- (void)hjad_splashAdDidVisible:(HJSplashAd *)splashAd {
    
}
/**
 * 开屏|视频广告开始播放（仅适用于视频广告）
 */
- (void)hjad_splashAdVideoDidBeginPlay:(HJSplashAd *)splashAd {
    
}
/**
 * 开屏|广告数据加载失败
 */
- (void)hjad_splashAd:(HJSplashAd *)splashAd didFailWithError:(nonnull NSError *)error {
    
}
/**
 * 开屏|点击跳过按钮调用此方法
 */
- (void)hjad_splashAd:(HJSplashAd *)splashAd didSkip:(NSTimeInterval)playDuration {
    
}
/**
 * 开屏|广告被点击
 */
- (void)hjad_splashAdDidClick:(HJSplashAd *)splashAd {
    
}
/**
 * 开屏|广告关闭
 */
- (void)hjad_splashAdDidAutoDismiss:(HJSplashAd *)splashAd {
    
}

@end
