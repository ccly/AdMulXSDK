//
//  HJExpressAdViewController.m
//  AdMulXDemo
//
//  Created by 枫 on 2025/10/16.
//

#import "HJExpressAdViewController.h"
#import <AdMulXSDK/HJExpressAd.h>
#import "HJHUD.h"
@interface HJExpressAdViewController ()<HJExpressAdDelegate>

@property (nonatomic, strong) HJExpressAd *hjExpressAd;

@end

@implementation HJExpressAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [HJHUD showHUDLoading];
    [self loadHJExpressAd];
}

- (void) loadHJExpressAd {
    
    self.hjExpressAd = [[HJExpressAd alloc] initWithSlotId:self.slotId controller:self adSize:CGSizeMake([UIScreen mainScreen].bounds.size.width-20, 100)];
    self.hjExpressAd.delegate = self;
    [self.hjExpressAd loadAdData];
}


/**
 * express|广告数据加载成功 开始渲染
 */
- (void)hjad_expressAdViewDidLoad:(HJExpressAd *)expressAd {
    [HJHUD dismissHUD];
    
    CGRect frame = self.hjExpressAd.expressAdView.frame;
    CGFloat height = frame.size.height;
    CGFloat width = frame.size.width;
    frame.origin = CGPointMake((self.view.frame.size.width - width) / 2, (self.view.frame.size.height - height)/2);
    self.hjExpressAd.expressAdView.frame = frame;
    
    [self.hjExpressAd showAdFromView:self.view];
}
/**
 * express|广告数据加载失败
 */
- (void)hjad_expressAd:(HJExpressAd *)expressAd didFailWithError:(NSError *_Nullable)error {
    [HJHUD dismissHUD];
    [HJHUD showStatu:error.domain];
    [self.navigationController popViewControllerAnimated:YES];
}
/**
 * express|广告被点击
 */
- (void)hjad_expressAdDidClick:(HJExpressAd *)expressAd {
    
}
/**
 * express|广告被关闭
 */
- (void)hjad_expressAdViewClosed:(HJExpressAd *)expressAd {
    [self.navigationController popViewControllerAnimated:YES];
}


@end
