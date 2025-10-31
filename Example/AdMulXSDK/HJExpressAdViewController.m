//
//  HJExpressAdViewController.m
//  AdMulXDemo
//
//  Created by 枫 on 2025/10/16.
//

#import "HJExpressAdViewController.h"
#import <AdMulXSDK/HJExpressAd.h>
@interface HJExpressAdViewController ()<HJExpressAdDelegate>

@property (nonatomic, strong) HJExpressAd *hjExpressAd;

@end

@implementation HJExpressAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self loadHJExpressAd];
}

- (void) loadHJExpressAd {
    
    self.hjExpressAd = [[HJExpressAd alloc] initWithSlotId:self.slotId controller:self adSize:CGSizeMake([UIScreen mainScreen].bounds.size.width, 100)];
    self.hjExpressAd.delegate = self;
    [self.hjExpressAd loadAdData];
    
}

/**
 * 信息流|广告数据加载成功
 */
- (void)hjad_expressAdsManagerSuccessToLoad:(HJExpressAd *)expressAd expressAds:(NSArray<HJExpressAdModel *> *_Nullable)dataArray {
    
}
/**
 * 信息流|广告数据返回，开始渲染
 */
- (void)hjad_expressAdsManagerReadyToRender:(HJExpressAd *)expressAd expressAds:(NSArray<HJExpressAdModel *> *_Nullable)dataArray {
    
    HJExpressAdModel  *model = [dataArray firstObject];
    CGRect frame = model.expressAdView.frame;
    CGFloat height = frame.size.height;
    CGFloat width = frame.size.width;
    frame.origin = CGPointMake((self.view.frame.size.width - width) / 2, (self.view.frame.size.height - height)/2);
    model.expressAdView.frame = frame;

    [model registerContainer:self.view];
    
}
/**
 * 信息流|广告数据加载失败
 */
- (void)hjad_expressAdsManager:(HJExpressAd *)expressAd didFailWithError:(NSError *_Nullable)error {
    
}
/**
 * 信息流|广告被点击
 */
- (void)hjad_expressAdDidClick:(HJExpressAdModel *)expressAdModel {
    
}
/**
 * 信息流|用户手动点击不喜欢按钮、 关闭
 */
- (void)hjad_expressAdDislike:(HJExpressAdModel *)expressAdModel {
    [self.navigationController popViewControllerAnimated:YES];
}

@end
