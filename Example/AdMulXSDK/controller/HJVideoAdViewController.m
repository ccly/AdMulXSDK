//
//  HJVideoAdViewController.m
//  AdMulXDemo
//
//  Created by 枫 on 2025/10/22.
//

#import "HJVideoAdViewController.h"
#import <AdMulXSDK/HJVideoAd.h>
#import "HJHUD.h"

@interface HJVideoAdViewController ()<HJVideoAdDelegate>

@property (nonatomic, strong) HJVideoAd *hjVideoAd;

@property (weak, nonatomic) IBOutlet UIView *videoView;

@end

@implementation HJVideoAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [HJHUD showHUDLoading];
    [self loadVideoAd];
    
}

// 视频贴片广告
- (void) loadVideoAd {
    
    self.hjVideoAd = [[HJVideoAd alloc] initWithSlotId:self.slotId controller:self adSize:CGSizeMake(self.videoView.frame.size.width, self.videoView.frame.size.height)];
    self.hjVideoAd.delegate = self;
    [self.hjVideoAd loadAdData];
}

#pragma mark - HJVideoAdDelegate
/**
 * video|广告数据加载成功 开始渲染
 */
- (void)hjad_videoAdViewDidLoad:(HJVideoAd *)videoAd {
    [HJHUD dismissHUD];
    [self.hjVideoAd showAdFromView:self.videoView];
    
}
/**
 * video|广告数据加载失败
 */
- (void)hjad_videoAd:(HJVideoAd *)videoAd didFailWithError:(NSError *_Nullable)error {
    [HJHUD dismissHUD];
    [HJHUD showStatu:error.domain];
    [self.navigationController popViewControllerAnimated:YES];
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
    [self.navigationController popViewControllerAnimated:YES];
}
@end
