//
//  HJDrawAdViewController.m
//  AdMulXDemo
//
//  Created by 枫 on 2025/10/16.
//

#import "HJDrawAdViewController.h"
#import <AdMulXSDK/HJDrawAd.h>

@interface HJDrawAdViewController ()<HJDrawAdDelegate>

@property (nonatomic, strong) HJDrawAd *hjDrawAd;

@end

@implementation HJDrawAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
   
    [self loadHJDrawAd];
    
}

-(void) loadHJDrawAd {
    self.hjDrawAd = [[HJDrawAd alloc] initWithSlotId:@"202509292916" controller:self adSize:[UIScreen mainScreen].bounds.size];
    self.hjDrawAd.delegate = self;
    [self.hjDrawAd loadAdData];
}


/**
 * draw|广告数据加载成功 开始渲染
 */
- (void)hjad_drawAdsManagerSuccessToLoad:(HJDrawAd *)drawAd drawAds:(NSArray<HJDrawAdModel *> *_Nullable)dataArray {
    
    HJDrawAdModel  *model = [dataArray firstObject];
    CGRect frame = model.drawAdView.frame;
    CGFloat height = frame.size.height;
    CGFloat width = frame.size.width;
    frame.origin = CGPointMake((self.view.frame.size.width - width) / 2, (self.view.frame.size.height - height)/2);
    model.drawAdView.frame = frame;
    
    [model registerContainer:self.view];
    
}
/**
 * draw|广告数据加载失败
 */
- (void)hjad_drawAdsManager:(HJDrawAd *)drawAd didFailWithError:(NSError *_Nullable)error {
    
}
/**
 * draw|广告被点击
 */
- (void)hjad_drawAdDidClick:(HJDrawAdModel *)drawAdModel {
    
}
/**
 * draw|广告被关闭
 */
- (void)hjad_drawAdViewClosed:(HJDrawAdModel *)drawAdModel {
    [self.navigationController popViewControllerAnimated:YES];
}


@end
