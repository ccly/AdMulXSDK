//
//  HJDrawAd.h
//  HJAdSDK
//
//  Created by 枫 on 2025/9/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AdMulXSDK/HJDrawAdModel.h>

NS_ASSUME_NONNULL_BEGIN

@class HJDrawAd;

@protocol HJDrawAdDelegate <NSObject>
/**
 * draw|广告数据加载成功 开始渲染
 */
- (void)hjad_drawAdsManagerSuccessToLoad:(HJDrawAd *)drawAd drawAds:(NSArray<HJDrawAdModel *> *_Nullable)dataArray;
/**
 * draw|广告数据加载失败
 */
- (void)hjad_drawAdsManager:(HJDrawAd *)drawAd didFailWithError:(NSError *_Nullable)error;
/**
 * draw|广告被点击
 */
- (void)hjad_drawAdDidClick:(HJDrawAdModel *)drawAdModel;
/**
 * draw|广告被关闭
 */
- (void)hjad_drawAdViewClosed:(HJDrawAdModel *)drawAdModel;

@end

@interface HJDrawAd : NSObject

@property (nonatomic, weak) id<HJDrawAdDelegate> delegate;

// 初始化draw广告 adSize必传
- (instancetype)initWithSlotId:(NSString *)slotId controller:(UIViewController *)viewController adSize:(CGSize)adSize;

// 加载draw广告
- (void)loadAdData;

// show draw广告(弃用)
- (void)showAdFromView:(UIView *)view withDrawAdModel:(HJDrawAdModel *)model;

@end

NS_ASSUME_NONNULL_END
