//
//  HJBannerAdViewController.m
//  AdMulXDemo
//
//  Created by 枫 on 2025/10/16.
//

#import "HJBannerAdViewController.h"
#import <AdMulXSDK/HJBannerAd.h>

@interface HJBannerAdViewController ()<HJBannerAdDelegate>

@property (weak, nonatomic) IBOutlet UIButton *showAdBtn;

@property (nonatomic, strong) HJBannerAd *hjBannerAd;

@end

@implementation HJBannerAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"banner广告";

}

- (IBAction)loadAd:(UIButton *)sender {
    [self loadHJBannerAd];
}

- (IBAction)showAd:(UIButton *)sender {
    
    self.showAdBtn.userInteractionEnabled = NO;
    [self.showAdBtn setBackgroundColor:[UIColor lightGrayColor]];
        
    CGRect frame = self.hjBannerAd.bannerAdView.frame;
    CGFloat height = frame.size.height;
    CGFloat width = frame.size.width;
    frame.origin = CGPointMake((self.view.frame.size.width - width) / 2, (self.view.frame.size.height - height)/2);
    self.hjBannerAd.bannerAdView.frame = frame;
    [self.hjBannerAd showAdFromView:self.view];

}


-(void) loadHJBannerAd{

    if(self.hjBannerAd) {
        [self.hjBannerAd.bannerAdView removeFromSuperview];
        [self.hjBannerAd removeBannerAd];
    }
    
    self.hjBannerAd = [[HJBannerAd alloc] initWithSlotId:self.slotId controller:self adSize:CGSizeMake([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.width/6.4)];
    self.hjBannerAd.delegate = self;
    
    [self.hjBannerAd loadAdData];
}

/**
 Banner广告请求成功.
 */
- (void)hjad_bannerAdViewDidLoad:(HJBannerAd *)bannerAd {
    
}
/**
 Banner广告请求失败.
 */
- (void)hjad_bannerAdView:(HJBannerAd *)bannerAd didFailWithError:(NSError *_Nullable)error {
    
}
/**
 Banner广告渲染成功.新广告渲染成功回调 开始展示
 */
- (void)hjad_bannerAdViewRenderSuccess:(HJBannerAd *)bannerAd {
    self.showAdBtn.userInteractionEnabled = YES;
    [self.showAdBtn setBackgroundColor:[UIColor darkGrayColor]];
}
/**
 Banner广告可见. 新广告可见回调.
 */
- (void)hjad_bannerAdViewBecomVisible:(HJBannerAd *)bannerAd {
    
}
/**
 Banner广告被点击.
 */
- (void)hjad_bannerAdViewDidClick:(HJBannerAd *)bannerAd {
    
}
/**
 Banner广告关闭.
 */
- (void)hjad_bannerAdViewDidClose:(HJBannerAd *)bannerAd {
    
}


@end
