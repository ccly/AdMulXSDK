//
//  HJVideoAd.h
//  HJAdSDK
//
//  Created by 枫 on 2025/10/22.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class HJVideoAd;

@protocol HJVideoAdDelegate <NSObject>
/**
 * video|广告数据加载成功 开始渲染
 */

- (void)hjad_videoAdViewDidLoad:(HJVideoAd *)videoAd;
/**
 * video|广告数据加载失败
 */
- (void)hjad_videoAdsManager:(HJVideoAd *)videoAd didFailWithError:(NSError *_Nullable)error;
/**
 * video|广告被点击 video
 */
- (void)hjad_videoAdDidClick:(HJVideoAd *)videoAd;
/**
 * video|广告被关闭
 */
- (void)hjad_videoAdViewClosed:(HJVideoAd *)videoAd;

@end

@interface HJVideoAd : NSObject

@property (nonatomic, weak) id<HJVideoAdDelegate> delegate;

// 初始化video广告 adSize必传
- (instancetype)initWithSlotId:(NSString *)slotId controller:(UIViewController *)viewController adSize:(CGSize)adSize;

// 加载video广告
- (void)loadAdData;

// show video广告(弃用)
- (void)showAdFromView:(UIView *)view;

// 移除video广告
- (void)removeVideoAd;

// 获取ecpm 只有广告拉取成功后，才可能有值、 -1表示无权限或无竞价功能
- (double)getEcpm;


@end

NS_ASSUME_NONNULL_END
