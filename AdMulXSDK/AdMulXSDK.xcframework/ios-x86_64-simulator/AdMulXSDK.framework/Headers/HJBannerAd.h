//
//  HJBannerAd.h
//  HJAdSDK
//
//  Created by 枫 on 2025/9/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AdMulXSDK/HJAdBidResult.h>

NS_ASSUME_NONNULL_BEGIN

@class HJBannerAd;

@protocol HJBannerAdDelegate <NSObject>

/**
 Banner广告请求成功.
 */
- (void)hjad_bannerAdViewDidLoad:(HJBannerAd *)bannerAd;
/**
 Banner广告请求失败.
 */
- (void)hjad_bannerAdView:(HJBannerAd *)bannerAd didFailWithError:(NSError *_Nullable)error;
/**
 Banner广告渲染成功.新广告渲染成功回调 开始展示
 */
- (void)hjad_bannerAdViewRenderSuccess:(HJBannerAd *)bannerAd;
/**
 Banner广告可见. 新广告可见回调.
 */
- (void)hjad_bannerAdViewBecomVisible:(HJBannerAd *)bannerAd;
/**
 Banner广告被点击.
 */
- (void)hjad_bannerAdViewDidClick:(HJBannerAd *)bannerAd;
/**
 Banner广告关闭.
 */
- (void)hjad_bannerAdViewDidClose:(HJBannerAd *)bannerAd;

@end

@interface HJBannerAd : NSObject

@property (nonatomic, weak) id<HJBannerAdDelegate> delegate;

// banner广告view
@property (nonatomic, strong) UIView *bannerAdView;

// 初始化banner广告 广告位的大小必传
- (instancetype)initWithSlotId:(NSString *)slotId controller:(UIViewController *)viewController;

// 加载banner广告
- (void)loadAdData;

// 显示banner广告
- (void)showAdFromView:(UIView *)view;

// 展示成功（不需处理）
- (void)onShowAdView;

// 获取ecpm 只有广告拉取成功后，才可能有值、 -1表示无权限或无竞价功能
- (double)getEcpm;

// 移除banner广告
- (void)removeBannerAd;

// 竞价结果回传，若无竞价功能则无需处理
- (void)didReceiveBidResult:(HJAdBidResult *)result;

@end

NS_ASSUME_NONNULL_END
