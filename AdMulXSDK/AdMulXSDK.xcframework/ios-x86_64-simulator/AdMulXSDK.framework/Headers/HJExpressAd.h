//
//  HJExpressAd.h
//  HJAdSDK
//
//  Created by 枫 on 2025/9/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "HJAdBidResult.h"

NS_ASSUME_NONNULL_BEGIN

@class HJExpressAd;

@protocol HJExpressAdDelegate <NSObject>
/**
 * express|广告数据加载成功 开始渲染
 */
- (void)hjad_expressAdViewDidLoad:(HJExpressAd *)expressAd;
/**
 * express|广告数据加载失败
 */
- (void)hjad_expressAd:(HJExpressAd *)expressAd didFailWithError:(NSError *_Nullable)error;
/**
 * express|广告被点击
 */
- (void)hjad_expressAdDidClick:(HJExpressAd *)expressAd;
/**
 * express|广告被关闭
 */
- (void)hjad_expressAdViewClosed:(HJExpressAd *)expressAd;

@end

@interface HJExpressAd : NSObject

@property (nonatomic, weak) id<HJExpressAdDelegate> delegate;

// express广告view
@property (nonatomic, strong) UIView *expressAdView;

// 初始化express广告 adSize必传
- (instancetype)initWithSlotId:(NSString *)slotId controller:(UIViewController *)viewController adSize:(CGSize)adSize;

// 加载express广告
- (void)loadAdData;

// 显示express广告
- (void)showAdFromView:(UIView *)view;

// 获取ecpm 只有广告拉取成功后，才可能有值、 -1表示无权限或无竞价功能
- (double)getEcpm;

// 移除express广告
- (void)removeExpressAd;

// 竞价结果回传，若无竞价功能则无需处理
- (void)didReceiveBidResult:(HJAdBidResult *)result;

@end

NS_ASSUME_NONNULL_END
