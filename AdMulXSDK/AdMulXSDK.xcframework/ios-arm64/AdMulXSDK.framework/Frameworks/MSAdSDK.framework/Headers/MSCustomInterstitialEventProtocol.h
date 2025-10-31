//
//  MSCustomInterstitialEventProtocol.h
//  MSAdSDK
//
//  Created by leej on 2022/5/16.
//  Copyright © 2022 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
//已废弃协议
@protocol MSCustomInterstitialDeprecatedEventProtocol <NSObject>

@optional

- (void)msCustomInterstitialEventShow MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomInterstitialEventShow:extInfo:替代");

- (void)msCustomInterstitialEventClicked MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomInterstitialEventClicked:extInfo:替代");

@end

@protocol MSCustomInterstitialEventProtocol <MSCustomInterstitialDeprecatedEventProtocol>

@optional
/**
 * 广告开始加载素材
 */
- (void)msCustomInterstitialEventStartLoadSource:(UIView * _Nullable)adView;
/**
 * 广告素材加载成功调用
 */
- (void)msCustomInterstitialEventLoadSourceSuccess:(UIView * _Nullable)adView extInfo:(NSDictionary *_Nullable)extInfo;
/**
 * 广告素材加载失败调用
 */
- (void)msCustomInterstitialEventLoadSourceFailed:(UIView * _Nullable)adView error:(NSError *)error extInfo:(NSDictionary *_Nullable)extInfo;

@required
/**
 *  广告加载成功调用
 */
- (void)msCustomInterstitialEventLoaded;
/**
 *  广告加载失败调用
 */
- (void)msCustomInterstitialEventError:(NSError *)error;
/**
 *  广告渲染成功调用
 */
- (void)msCustomInterstitialEventRenderSuccess;
/**
 *  广告渲染失调用
 */
- (void)msCustomInterstitialEventRenderFailed:(NSError *)error;
/**
 *  插屏广告视图展示成功调用
 *  @param adView 广告视图
    @param extInfo 广告个性化参数
 */
- (void)msCustomInterstitialEventShow:(UIView * _Nullable)adView extInfo:(NSDictionary *_Nullable)extInfo;
/**
   平台广告展示失败调用
 */
- (void)msCustomInterstitialEventShowFail:(NSError *)error;
/**
 *  插屏广告展示结束调用
 */
- (void)msCustomInterstitialEventClosed;
/**
 *  插屏广告点击调用
 *  @param adView 广告视图
    @param extInfo 广告个性化参数
 */
- (void)msCustomInterstitialEventClicked:(UIView *_Nullable)adView extInfo:(NSDictionary *_Nullable)extInfo;
/**
 *  广告落地页被关闭调用
 */
- (void)msCustomInterstitialEventDetailClosed;
@end

NS_ASSUME_NONNULL_END
