//
//  HJDrawAd.h
//  HJAdSDK
//
//  Created by 枫 on 2025/9/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "HJAdBidResult.h"

NS_ASSUME_NONNULL_BEGIN

@class HJDrawAd;

@protocol HJDrawAdDelegate <NSObject>
/**
 * draw|广告数据加载成功 开始渲染
 */
- (void)hjad_drawAdViewDidLoad:(HJDrawAd *)drawAd;
/**
 * draw|广告数据加载失败
 */
- (void)hjad_drawAd:(HJDrawAd *)drawAd didFailWithError:(NSError *_Nullable)error;
/**
 * draw|广告被点击
 */
- (void)hjad_drawAdDidClick:(HJDrawAd *)drawAd;
/**
 * draw|广告被关闭
 */
- (void)hjad_drawAdViewClosed:(HJDrawAd *)drawAd;

@end

@interface HJDrawAd : NSObject

@property (nonatomic, weak) id<HJDrawAdDelegate> delegate;

// 初始化draw广告 adSize必传
- (instancetype)initWithSlotId:(NSString *)slotId controller:(UIViewController *)viewController adSize:(CGSize)adSize;

// 加载draw广告
- (void)loadAdData;

// 显示draw广告
- (void)showAdFromView:(UIView *)view;

// 获取ecpm 只有广告拉取成功后，才可能有值、 -1表示无权限或无竞价功能
- (double)getEcpm;

// 移除draw广告
- (void)removeDrawAd;

// 竞价结果回传，若无竞价功能则无需处理
- (void)didReceiveBidResult:(HJAdBidResult *)result;

@end

NS_ASSUME_NONNULL_END
