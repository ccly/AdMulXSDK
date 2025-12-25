//
//  HJDrawAdViewController.m
//  AdMulXDemo
//
//  Created by 枫 on 2025/10/16.
//

#import "HJDrawAdViewController.h"
#import <AdMulXSDK/HJDrawAd.h>
#import "HJHUD.h"

@interface HJDrawAdViewController ()<HJDrawAdDelegate>

@property (nonatomic, strong) HJDrawAd *hjDrawAd;

@end

@implementation HJDrawAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [HJHUD showHUDLoading];

    [self loadHJDrawAd];
    
}

-(void) loadHJDrawAd {
    self.hjDrawAd = [[HJDrawAd alloc] initWithSlotId:self.slotId controller:self adSize:[UIScreen mainScreen].bounds.size];
    self.hjDrawAd.delegate = self;
    [self.hjDrawAd loadAdData];
}

/**
 * draw|广告数据加载成功 开始渲染
 */
- (void)hjad_drawAdViewDidLoad:(HJDrawAd *)drawAd {
    [HJHUD dismissHUD];
    [self.hjDrawAd showAdFromView:self.view];
}
/**
 * draw|广告数据加载失败
 */
- (void)hjad_drawAd:(HJDrawAd *)drawAd didFailWithError:(NSError *_Nullable)error {
    [HJHUD dismissHUD];
    [HJHUD showStatu:error.domain];
    [self.navigationController popViewControllerAnimated:YES];
}
/**
 * draw|广告被点击
 */
- (void)hjad_drawAdDidClick:(HJDrawAd *)drawAd {
    
}
/**
 * draw|广告被关闭
 */
- (void)hjad_drawAdViewClosed:(HJDrawAd *)drawAd {
    [self.navigationController popViewControllerAnimated:YES];
}


@end
