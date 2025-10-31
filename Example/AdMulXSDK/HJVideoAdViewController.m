//
//  HJVideoAdViewController.m
//  AdMulXDemo
//
//  Created by 枫 on 2025/10/22.
//

#import "HJVideoAdViewController.h"
#import <AdMulXSDK/HJVideoAd.h>

@interface HJVideoAdViewController ()<HJVideoAdDelegate>

@property (nonatomic, strong) HJVideoAd *hjVideoAd;


@end

@implementation HJVideoAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
   
    [self loadVideoAd];
    
}

// 视频贴片广告
- (void) loadVideoAd {
    
    self.hjVideoAd = [[HJVideoAd alloc] initWithSlotId:self.slotId controller:self adSize:CGSizeMake([UIScreen mainScreen].bounds.size.width, 0)];
    self.hjVideoAd.delegate = self;
    [self.hjVideoAd loadAdData];
}

#pragma mark - HJVideoAdDelegate
/**
 * video|广告数据加载成功 开始渲染
 */
- (void)hjad_videoAdViewDidLoad:(HJVideoAd *)videoAd {
    
    [self.hjVideoAd showAdFromView:self.view];
    
}
/**
 * video|广告数据加载失败
 */
- (void)hjad_videoAdsManager:(HJVideoAd *)videoAd didFailWithError:(NSError *_Nullable)error {
    
}
/**
 * video|广告被点击 video
 */
- (void)hjad_videoAdDidClick:(HJVideoAd *)videoAd {
 }
/**
 * video|广告被关闭
 */
- (void)hjad_videoAdViewClosed:(HJVideoAd *)videoAd {
    
}
@end
