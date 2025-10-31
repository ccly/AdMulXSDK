//
//  HJHalfScreenAdViewController.m
//  AdMulXDemo
//
//  Created by 枫 on 2025/10/16.
//

#import "HJHalfScreenAdViewController.h"

#import <AdMulXSDK/HJHalfScreenAd.h>

@interface HJHalfScreenAdViewController ()<HJHalfScreenAdDelegate>

@property (nonatomic, strong) HJHalfScreenAd *hjHalfScreenAd;

@end

@implementation HJHalfScreenAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self loadHJHalfScreenAd];
    
}

- (void) loadHJHalfScreenAd {
    
    self.hjHalfScreenAd = [[HJHalfScreenAd alloc] initWithAdSlotId:self.slotId];
    self.hjHalfScreenAd.delegate = self;
    [self.hjHalfScreenAd loadAdData];
}

#pragma mark - HJHalfScreenAdDelegate
/**
 * 插屏|已加载广告数据 展示广告
 */
- (void)hjad_halfScreenAdDidLoad:(HJHalfScreenAd *)halfScreenAd {
    
}

/**
 * 插屏|已加载完毕广告素材,准备展示，在此处展示广告
 */
- (void)hjad_halfScreenAdVideoDidLoad:(HJHalfScreenAd *)halfScreenAd {
    [self.hjHalfScreenAd showAdFromRootViewController:self];
}
/**
 * 插屏|广告加载、渲染失败
 */
- (void)hjad_halfScreenAdRenderFail:(HJHalfScreenAd *)halfScreenAd error:(NSError *)error {
    
}
/**
 * 插屏|广告被点击
 */
- (void)hjad_halfScreenAdDidClick:(HJHalfScreenAd *)halfScreenAd {
    
}
/**
 * 插屏|广告被点击跳过
 */
- (void)hjad_halfScreenAdDidClickSkip:(HJHalfScreenAd *)halfScreenAd {
    
}
/**
 * 插屏|广告已经关闭
 */
- (void)hjad_halfScreenAdDidClose:(HJHalfScreenAd *)halfScreenAd {
    [self.navigationController popViewControllerAnimated:YES];
}

@end
