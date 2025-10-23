//
//  HJRewardAd.h
//  HJAdSDK
//
//  Created by 枫 on 2025/9/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class HJRewardAd;

@protocol HJRewardAdDelegate <NSObject>

/**
 * 激励|已加载广告数据
 */
- (void)hjad_rewardAdDidLoad:(HJRewardAd *)rewardAd;
/**
 * 激励|视频广告从请求到缓存到展示发生任何失败均调用此方法
 */
- (void)hjad_rewardAd:(HJRewardAd *)rewardAd didFailWithError:(NSError *_Nullable)error;
/**
 * 激励|视频等资源成功时调用此方法，收到此回调后广告才能开始展示，否则资源是未下载完成的
 */
- (void)hjad_rewardAdVideoDidLoad:(HJRewardAd *)rewardAd;
/**
 * 激励|视频广告已经关闭
 */
- (void)hjad_rewardAdDidClose:(HJRewardAd *)rewardAd;
/**
 * 激励|视频广告被点击
 */
- (void)hjad_rewardAdDidClick:(HJRewardAd *)rewardAd;
/**
 * 激励|广告被点击跳过
 */
- (void)hjad_rewardAdDidClickSkip:(HJRewardAd *)rewardAd;
/**
 * 激励|用户获得奖励时回调
 */
- (void)hjad_rewardAd:(HJRewardAd *)rewardAd hasReward:(BOOL)hasReward;

@end

@interface HJRewardAd : NSObject

@property (nonatomic, weak) id<HJRewardAdDelegate> delegate;

// 初始化激励广告 服务器回调自定义透传参数
- (instancetype)initWithSlotId:(NSString *)slotId rewardAdExtra:(NSString *)extra;

// 加载激励广告
- (void)loadAdData;

// 显示激励广告
- (void)showAdFromRootViewController:(UIViewController *)viewController;

// 移除激励广告
- (void)removeRewardAd;

// 获取ecpm 只有广告拉取成功后，才可能有值、 -1表示无权限或无竞价功能
- (double)getEcpm;

@end

NS_ASSUME_NONNULL_END
