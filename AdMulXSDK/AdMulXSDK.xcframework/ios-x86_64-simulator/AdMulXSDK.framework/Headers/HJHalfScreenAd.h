//
//  HJHalfScreenAd.h
//  HJAdSDK
//
//  Created by 枫 on 2025/9/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class HJHalfScreenAd;

@protocol HJHalfScreenAdDelegate <NSObject>

/**
 * 插屏|已加载广告数据 展示广告
 */
- (void)hjad_halfScreenAdDidLoad:(HJHalfScreenAd *)halfScreenAd;

/**
 * 插屏|已加载完毕广告素材,准备展示，在此处展示广告
 */
- (void)hjad_halfScreenAdVideoDidLoad:(HJHalfScreenAd *)halfScreenAd ;
/**
 * 插屏|广告加载、渲染失败
 */
- (void)hjad_halfScreenAdRenderFail:(HJHalfScreenAd *)halfScreenAd error:(NSError *)error;
/**
 * 插屏|广告被点击
 */
- (void)hjad_halfScreenAdDidClick:(HJHalfScreenAd *)halfScreenAd;
/**
 * 插屏|广告被点击跳过
 */
- (void)hjad_halfScreenAdDidClickSkip:(HJHalfScreenAd *)halfScreenAd;
/**
 * 插屏|广告已经关闭
 */
- (void)hjad_halfScreenAdDidClose:(HJHalfScreenAd *)halfScreenAd;


@end

@interface HJHalfScreenAd : NSObject


@property (nonatomic, weak) id<HJHalfScreenAdDelegate> delegate;

// 初始化插屏半屏广告
- (instancetype)initWithAdSlotId:(NSString *)slotId;

// 加载插屏半屏广告
- (void)loadAdData;

// 显示插屏半屏广告
- (void)showAdFromRootViewController:(UIViewController *)viewController;

// 移除插屏半屏广告
- (void)removeHalfScreenAd;

// 获取ecpm 只有广告拉取成功后，才可能有值、 -1表示无权限或无竞价功能
- (double)getEcpm;

@end


NS_ASSUME_NONNULL_END
