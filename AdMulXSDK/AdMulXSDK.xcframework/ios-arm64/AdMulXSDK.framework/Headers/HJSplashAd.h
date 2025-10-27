//
//  HJSplashAd.h
//  HJAdSDK
//
//  Created by 枫 on 2025/9/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@class HJSplashAd;

@protocol HJSplashAdDelegate <NSObject>

/**
 * 开屏|已加载广告数据
 */
- (void)hjad_splashAdDidLoad:(HJSplashAd *)splashAd;
/**
 * 开屏|已加载完毕广告素材,准备展示，在此处展示广告
 */
- (void)hjad_splashAdContentDidLoad:(HJSplashAd *)splashAd;
/**
 * 开屏|广告已经可见
 */
- (void)hjad_splashAdDidVisible:(HJSplashAd *)splashAd;
/**
 * 开屏|视频广告开始播放（仅适用于视频广告）
 */
- (void)hjad_splashAdVideoDidBeginPlay:(HJSplashAd *)splashAd;
/**
 * 开屏|广告数据加载失败
 */
- (void)hjad_splashAd:(HJSplashAd *)splashAd didFailWithError:(nonnull NSError *)error;
/**
 * 开屏|点击跳过按钮调用此方法
 */
- (void)hjad_splashAd:(HJSplashAd *)splashAd didSkip:(NSTimeInterval)playDuration;
/**
 * 开屏|广告被点击
 */
- (void)hjad_splashAdDidClick:(HJSplashAd *)splashAd;
/**
 * 开屏|广告关闭
 */
- (void)hjad_splashAdDidAutoDismiss:(HJSplashAd *)splashAd;

@end

@interface HJSplashAd : NSObject

@property (nonatomic, weak) id<HJSplashAdDelegate> delegate;

// 初始化开屏广告
- (instancetype)initWithSlotId:(NSString *)slotId;

// 加载开屏广告
- (void)loadAdData;

// 显示开屏广告
- (void)showSplashViewInRootViewController:(UIViewController *)viewController;

// 移除开屏广告
- (void)removeSplashAd;

// 获取ecpm 只有广告拉取成功后，才可能有值、 -1表示无权限或无竞价功能
- (double)getEcpm;

@end

NS_ASSUME_NONNULL_END
