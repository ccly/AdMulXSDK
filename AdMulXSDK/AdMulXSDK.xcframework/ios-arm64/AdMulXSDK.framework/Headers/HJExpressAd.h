//
//  HJExpressAd.h
//  HJAdSDK
//
//  Created by 枫 on 2025/9/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AdMulXSDK/HJExpressAdModel.h>

NS_ASSUME_NONNULL_BEGIN

@class HJExpressAd;

@protocol HJExpressAdDelegate <NSObject>
/**
 * 信息流|广告数据加载成功
 */
- (void)hjad_expressAdsManagerSuccessToLoad:(HJExpressAd *)expressAd expressAds:(NSArray<HJExpressAdModel *> *_Nullable)dataArray;
/**
 * 信息流|广告数据返回，开始渲染
 */
- (void)hjad_expressAdsManagerReadyToRender:(HJExpressAd *)expressAd expressAds:(NSArray<HJExpressAdModel *> *_Nullable)dataArray;
/**
 * 信息流|广告数据加载失败
 */
- (void)hjad_expressAdsManager:(HJExpressAd *)expressAd didFailWithError:(NSError *_Nullable)error;
/**
 * 信息流|广告被点击
 */
- (void)hjad_expressAdDidClick:(HJExpressAdModel *)expressAdModel;
/**
 * 信息流|用户手动点击不喜欢按钮、 关闭
 */
- (void)hjad_expressAdDislike:(HJExpressAdModel *)expressAdModel;

@end

@interface HJExpressAd : NSObject

@property (nonatomic, weak) id<HJExpressAdDelegate> delegate;

// 初始化express广告 adSize必传
- (instancetype)initWithSlotId:(NSString *)slotId controller:(UIViewController *)viewController adSize:(CGSize)adSize;

// 加载express广告
- (void)loadAdData;

@end

NS_ASSUME_NONNULL_END
