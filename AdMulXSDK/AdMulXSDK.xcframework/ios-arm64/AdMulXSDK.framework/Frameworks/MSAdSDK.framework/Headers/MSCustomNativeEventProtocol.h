//
//  MSCustomNativeEventProtocol.h
//  MSAdSDK
//
//  Created by leej on 2022/5/20.
//  Copyright © 2022 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//已废弃协议
@protocol MSCustomNativeDeprecatedEventProtocol <NSObject>

@optional
/**
 *  信息流广告曝光调用
 */
- (void)msCustomNativeShow:(id<MSFeedAdMeta> _Nullable)feedAdData adContainerView:(UIView *)adContainerView MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomNativeShow:adContainerView:extInfo:替代");
/**
 *  广告被点击调用
 */
- (void)msCustomNativeClick:(id<MSFeedAdMeta>)feedAdData MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomNativeClick:adView:extInfo:替代");

@end

@protocol MSCustomNativeEventProtocol <MSCustomNativeDeprecatedEventProtocol>
/**
 *  原生广告加载广告成功调用
 */
- (void)msCustomNativeLoaded:(NSArray *)nativeAdDataArray;
/**
 *  原生广告加载广告失败调用
 */
- (void)msCustomNativeError:(NSError *)error;
/**
 *  原生模版广告渲染成功调用
 */
- (void)msCustomNativeRenderSuccess:(UIView *)adView adInfo:(NSDictionary *)adInfo;
/**
 *  原生广告模版渲染失败调用
 */
- (void)msCustomNativeRenderError:(UIView *)adView error:(NSError *)error;
/// 原生广告即将展现调用
/// @param feedAdData 如果是自渲染类型feedAdData参数传入广告物料对象，模版类型不传
/// @param adContainerView 如果是自渲染类型传入广告容器，模版类型传广告模版view
/// @param extInfo 媒体自定义参数
///
- (void)msCustomNativeShow:(id<MSFeedAdMeta> _Nullable)feedAdData adContainerView:(UIView *)adContainerView extInfo:(NSDictionary *_Nullable)extInfo;
/// 原生广告被点击调用
/// @param feedAdData 如果是自渲染类型feedAdData参数传入广告物料对象，模版类型不传
/// @param adView 如果是自渲染类型传入广告容器，模版类型传广告模版view
/// @param extInfo 媒体自定义参数
///
- (void)msCustomNativeClick:(id<MSFeedAdMeta> _Nullable)feedAdData adView:(UIView *)adView extInfo:(NSDictionary *_Nullable)extInfo;
/// 原生广告被关闭调用
/// @param feedAdData 如果是自渲染类型feedAdData参数传入广告物料对象，模版类型不传
/// @param adView 如果是自渲染类型传入广告容器，模版类型传广告模版view
///
- (void)msCustomNativeClosed:(id<MSFeedAdMeta> _Nullable)feedAdData adView:(UIView *)adView;
/**
 *  原生广告落地页已展现调用
 */
- (void)msCustomNativeDetailShow;
/**
 * 落地页关闭时调用
 */
- (void)msCustomNativeDetailClosed;
/**
   模版广告视频播放状态
 */
- (void)msCustomNativePlayerStatus:(MSPlayerPlayState)status adView:(UIView *)adView;
@end

NS_ASSUME_NONNULL_END
