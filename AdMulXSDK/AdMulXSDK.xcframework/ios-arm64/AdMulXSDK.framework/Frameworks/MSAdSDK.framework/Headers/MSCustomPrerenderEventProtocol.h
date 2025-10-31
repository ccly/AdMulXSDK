//
//  MSCustomPrerenderEventProtocol.h
//  MSAdSDK
//
//  Created by leej on 2022/5/20.
//  Copyright © 2022 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//已废弃协议
@protocol MSCustomPrerenderDeprecatedEventProtocol <NSObject>

@optional
/**
 *  信息流模版广告曝光调用
 */
- (void)msCustomPrerenderShow:(UIView *)adView MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomPrerenderShow:adInfo:替代");
/**
 *  广告点击时调用
 */
- (void)msCustomPrerenderClicked:(UIView *)adView MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomPrerenderClicked:adInfo:替代");

@end

@protocol MSCustomPrerenderEventProtocol <MSCustomPrerenderDeprecatedEventProtocol>

@optional
/**
 * 广告开始加载素材
 */
- (void)msCustomPrerenderStartLoadSource:(UIView * _Nullable)adView;
/**
 * 广告素材加载成功调用
 */
- (void)msCustomPrerenderLoadSourceSuccess:(UIView * _Nullable)adView extInfo:(NSDictionary *_Nullable)extInfo;
/**
 * 广告素材加载失败调用
 */
- (void)msCustomPrerenderLoadSourceFailed:(UIView * _Nullable)adView error:(NSError *)error extInfo:(NSDictionary *_Nullable)extInfo;
/**
 * 广告将要曝光
 */
- (void)msCustomPrerenderwillShow:(UIView * _Nullable)adView;

@required
/**
 *  广告加载成功后调用
 */
- (void)msCustomPrerenderLoaded:(NSArray<UIView*>*)adViewArray;
/**
 *  广告加载失败后调用
 */
- (void)msCustomPrerenderError:(NSError *)error;
/**
 *  广告视图渲染成功调用
 */
- (void)msCustomPrerenderRenderSuccess:(UIView *)adView adInfo:(NSDictionary *)adInfo;
/**
 *  广告视图渲染失败调用
 */
- (void)msCustomPrerenderRenderError:(UIView *)adView error:(NSError *)error;
/**
 *  广告曝光调用
 *  @param adView 广告视图
    @param adInfo 媒体个性化参数
 */
- (void)msCustomPrerenderShow:(UIView *)adView adInfo:(NSDictionary *_Nullable)adInfo;
/**
 *  广告点击时调用
 *  @param adView 广告视图
    @param adInfo 媒体个性化参数
 */
- (void)msCustomPrerenderClicked:(UIView *)adView adInfo:(NSDictionary *_Nullable)adInfo;
/**
 *  广告被关闭时调用
 */
- (void)msCustomPrerenderClosed:(UIView *)adView;
/**
   视频播放状态
 */
- (void)msCustomPrerenderPlayerStatus:(MSPlayerPlayState)status adView:(UIView *)adView;
@end

NS_ASSUME_NONNULL_END
