//
//  MSCustomBannerEventProtocol.h
//  MSAdSDK
//
//  Created by leej on 2022/5/17.
//  Copyright © 2022 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
//已废弃协议
@protocol MSCustomBannerDeprecatedEventProtocol <NSObject>

@optional
/**
 *  banner广告曝光调用
 */
- (void)msCustomBannerShow:(UIView *)bannerAd MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomBannerShow:extInfo:替代");
/**
 *  banner条点击调用
 */
- (void)msCustomBannerClicked:(UIView *)bannerAd MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomBannerClicked:extInfo:替代");
/**
    广告渲染失败调用
 */
- (void)msCustomBannerAdRenderFail:(UIView *)bannerAd error:(NSError *)error MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomBannerAdRenderFail:error:extInfo:替代");
@end

@protocol MSCustomBannerEventProtocol <MSCustomBannerDeprecatedEventProtocol>

@optional
/**
 * 广告开始加载素材
 */
- (void)msCustomBannerStartLoadSource:(UIView * _Nullable)bannerAd;
/**
 * 广告素材加载成功调用
 */
- (void)msCustomBannerLoadSourceSuccess:(UIView * _Nullable)bannerAd extInfo:(NSDictionary *_Nullable)extInfo;
/**
 * 广告素材加载失败调用
 */
- (void)msCustomBannerLoadSourceFailed:(UIView * _Nullable)bannerAd error:(NSError *)error extInfo:(NSDictionary *_Nullable)extInfo;

@required
/**
 *  广告加载成功调用
 */
- (void)msCustomBannerLoaded:(UIView *)bannerAd;
/**
 *  广告加载失败调用
 */
- (void)msCustomBannerError:(NSError *)error;
/**
    广告渲染成功调用
 */
- (void)msCustomBannerAdRenderSuccess:(UIView *)bannerAd;
/**
    广告渲染失败调用
 */
- (void)msCustomBannerAdRenderFail:(UIView *)bannerAd error:(NSError *)error extInfo:(NSDictionary *_Nullable)extInfo;
/**
 *  banner广告曝光调用
 *  @param bannerAd 广告视图
 *  @param extInfo 媒体个性化参数
 */
- (void)msCustomBannerShow:(UIView *)bannerAd extInfo:(NSDictionary *_Nullable)extInfo;
/**
 *  banner条点击调用
 */
- (void)msCustomBannerClicked:(UIView *)bannerAd extInfo:(NSDictionary *_Nullable)extInfo;
/**
 *  banner条被用户关闭时调用
 */
- (void)msCustomBannerClosed:(UIView *)bannerAd;
/**
 *  banner广告点击以后弹出全屏广告页完毕调用
 */
- (void)msCustomBannerDetailShow:(UIView *)bannerAd;
/**
 *  全屏广告页已经被关闭调用
 */
- (void)msCustomBannerDetailClosed:(UIView *)bannerAd;
@end

NS_ASSUME_NONNULL_END
