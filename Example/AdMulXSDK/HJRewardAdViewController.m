//
//  HJRewardAdViewController.m
//  AdMulXDemo
//
//  Created by 枫 on 2025/10/16.
//

#import "HJRewardAdViewController.h"
#import <AdMulXSDK/HJRewardAd.h>

@interface HJRewardAdViewController ()<HJRewardAdDelegate>

@property (nonatomic, strong) HJRewardAd *hjRewardAd;
@property (weak, nonatomic) IBOutlet UIButton *showAdBtn;

@end

@implementation HJRewardAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
}
- (IBAction)loadAd:(UIButton *)sender {
    
    [self loadHJRewardAd];
    
}

- (IBAction)showAd:(UIButton *)sender {
    
    self.showAdBtn.userInteractionEnabled = NO;
    [self.showAdBtn setBackgroundColor:[UIColor lightGrayColor]];
        
    [self.hjRewardAd showAdFromRootViewController:self];
    
}

- (void) loadHJRewardAd{
    
    self.hjRewardAd = [[HJRewardAd alloc] initWithSlotId:@"202509290391" rewardAdExtra:@"12eoioir3r32r3r"];
    self.hjRewardAd.delegate = self;
    [self.hjRewardAd loadAdData];
}


#pragma mark - HJRewardAdDelegate
/**
 * 激励|已加载广告数据
 */
- (void)hjad_rewardAdDidLoad:(HJRewardAd *)rewardAd {
    
}
/**
 * 激励|视频广告从请求到缓存到展示发生任何失败均调用此方法
 */
- (void)hjad_rewardAd:(HJRewardAd *)rewardAd didFailWithError:(NSError *_Nullable)error {
    
}
/**
 * 激励|视频等资源成功时调用此方法，收到此回调后广告才能开始展示，否则资源是未下载完成的
 */
- (void)hjad_rewardAdVideoDidLoad:(HJRewardAd *)rewardAd {
    
    self.showAdBtn.userInteractionEnabled = YES;
    [self.showAdBtn setBackgroundColor:[UIColor darkGrayColor]];
}
/**
 * 激励|视频广告已经关闭
 */
- (void)hjad_rewardAdDidClose:(HJRewardAd *)rewardAd {
    
}
/**
 * 激励|视频广告被点击
 */
- (void)hjad_rewardAdDidClick:(HJRewardAd *)rewardAd {
    
}
/**
 * 激励|广告被点击跳过
 */
- (void)hjad_rewardAdDidClickSkip:(HJRewardAd *)rewardAd {
    
}
/**
 * 激励|用户获得奖励时回调
 */
- (void)hjad_rewardAd:(HJRewardAd *)rewardAd hasReward:(BOOL)hasReward {
    
}


@end
