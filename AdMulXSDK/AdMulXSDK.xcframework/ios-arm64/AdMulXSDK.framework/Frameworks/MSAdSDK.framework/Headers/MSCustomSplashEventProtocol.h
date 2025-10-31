//
//  MSCustomSplashEventProtocol.h
//  MSAdSDK
//
//  Created by leej on 2022/4/26.
//  Copyright © 2022 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//已废弃协议
@protocol MSCustomSplashDeprecatedEventProtocol <NSObject>

@optional
/**
 * 开屏广告加载成功调用
 */
- (void)msCustomSplashEventSplashLoaded  MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomSplashEventSplashLoaded:extInfo:替代");
/**
 *  开屏广告渲染成功调用
 */
- (void)msCustomSplashEventRenderSuccess MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomSplashEventRenderSuccess:extInfo:替代");
/**
 *  开屏广告曝光成功调用
 */
- (void)msCustomSplashEventSplashShow MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomSplashEventSplashShowWithSplashView:extInfo:替代");
/**
 *  开屏广告点击调用
 */
- (void)msCustomSplashEventSplashClicked MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomSplashEventSplashClicked:extInfo:替代");

@end

@protocol MSCustomSplashEventProtocol <MSCustomSplashDeprecatedEventProtocol>

@optional
/**
 * 开屏广告开始加载素材
 */
- (void)msCustomSplashEventSplashStartLoadSource:(UIView * _Nullable)splashView;
/**
 * 开屏广告素材加载成功调用
 */
- (void)msCustomSplashEventSplashLoadSourceSuccess:(UIView * _Nullable)splashView extInfo:(NSDictionary *_Nullable)extInfo;
/**
 * 开屏广告素材加载失败调用
 */
- (void)msCustomSplashEventSplashLoadSourceFailed:(UIView * _Nullable)splashView error:(NSError *_Nullable)err extInfo:(NSDictionary *_Nullable)extInfo;

@required
/**
 * 开屏广告加载成功调用
 */
- (void)msCustomSplashEventSplashLoaded:(UIView * _Nullable)splashView extInfo:(NSDictionary *_Nullable)extInfo;
/**
 *  开屏广告失败调用
 */
- (void)msCustomSplashEventError:(NSError *)error;
/**
 *  开屏广告渲染成功调用
 *  splashView:广告视图
 *  extInfo：媒体个性化参数
 */
- (void)msCustomSplashEventRenderSuccess:(UIView * _Nullable)splashView extInfo:(NSDictionary *_Nullable)extInfo;
/**
 *  开屏广告渲染失败调用
 */
- (void)msCustomSplashEventRenderFailedError:(NSError *)error;
/**
 * 开屏广告投屏成功调用
 */
- (void)msCustomSplashEventSplashPresent;
/**
 *  开屏广告曝光成功调用
 *  splashView:广告视图
 *  extInfo：媒体个性化参数
 */
- (void)msCustomSplashEventSplashShowWithSplashView:(UIView * _Nullable)splashView extInfo:(NSDictionary *_Nullable)extInfo;
/**
 *  开屏广告曝光失败调用
 */
- (void)msCustomSplashEventSplashAdShowFail:(NSError *)error;
/**
 *  开屏广告点击调用
 *  splashView:广告视图
 *  extInfo：媒体个性化参数
 */
- (void)msCustomSplashEventSplashClicked:(UIView * _Nullable)splashView extInfo:(NSDictionary *_Nullable)extInfo;
/**
 *  开屏广告将要关闭调用
 */
- (void)msCustomSplashEventSplashWillClosed;
/**
 *  开屏广告关闭调用
 */
- (void)msCustomSplashEventSplashClosed;
/**
 *  点击以后全屏广告页已经关闭调用
 */
- (void)msCustomSplashEventSplashDetailClosed;
/**
 * 当用户点击跳过按钮时触发调用
 */
- (void)msCustomSplashEventSplashSkip;
/**
 * 开屏广告展示剩余时间
 */
- (void)msCustomSplashAdLifeTime:(NSInteger)time;

@end

NS_ASSUME_NONNULL_END
