//
//  HJFullScreenAdViewController.m
//  AdMulXDemo
//
//  Created by 枫 on 2025/10/16.
//

#import "HJFullScreenAdViewController.h"
#import <AdMulXSDK/HJFullScreenAd.h>

@interface HJFullScreenAdViewController ()<HJFullScreenAdDelegate>

@property (nonatomic, strong) HJFullScreenAd *hjFullScreenAd;

@end

@implementation HJFullScreenAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self loadHJFullScreenAd];
}

- (void) loadHJFullScreenAd {
    
    self.hjFullScreenAd = [[HJFullScreenAd alloc] initWithAdSlotId:@"202509295733"];
    self.hjFullScreenAd.delegate = self;
    [self.hjFullScreenAd loadAdData];
    
}

/**
 * 插屏|已加载广告数据
 */
- (void)hjad_fullScreenAdDidLoad:(HJFullScreenAd *)fullScreenAd {
    
}
/**
 * 插屏|已加载完毕广告素材,准备展示，在此处展示广告
 */
- (void)hjad_fullScreenAdVideoDidLoad:(HJFullScreenAd *)fullScreenAd {
    [self.hjFullScreenAd showAdFromRootViewController:self];
}
/**
 * 插屏|广告加载、渲染失败
 */
- (void)hjad_fullScreenAdRenderFail:(HJFullScreenAd *)fullScreenAd error:(NSError *)error {
    
}
/**
 * 插屏|广告被点击
 */
- (void)hjad_fullScreenAdDidClick:(HJFullScreenAd *)fullScreenAd {
    
}
/**
 * 插屏|广告被点击跳过
 */
- (void)hjad_fullScreenAdDidClickSkip:(HJFullScreenAd *)fullScreenAd {
    
}
/**
 * 插屏|广告已经关闭
 */
- (void)hjad_fullScreenAdDidClose:(HJFullScreenAd *)fullScreenAd {
    [self.navigationController popViewControllerAnimated:YES];
}

@end
