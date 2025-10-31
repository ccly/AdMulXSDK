//
//  MSCustomFullScreenVideoEventProtocol.h
//  MSAdSDK
//
//  Created by leej on 2022/5/19.
//  Copyright © 2022 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//已废弃协议
@protocol MSCustomFullScreenVideoDeprecatedEventProtocol <NSObject>

@optional
/**
 *  全屏视频广告曝光调用
 */
- (void)msCustomFullScreenVideoAdShowSuccess:(UIView *_Nullable)adView MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomFullScreenVideoAdShowSuccess:extInfo:替代");
/**
 全屏视频缓存成功调用
 */
- (void)msCustomFullScreenVideoAdCacheSuccess MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomFullScreenVideoAdCacheSuccess:extInfo:替代");
/**
 全屏视频缓存失败调用
 */
- (void)msCustomFullScreenVideoAdCacheFailed:(NSError *)error MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomFullScreenVideoAdCacheFailed:extInfo:替代");
/**
 全屏视频被点击调用
 */
- (void)msCustomFullScreenVideoAdDidClick:(UIView *_Nullable)adView withPlayingProgress:(CGFloat)progress MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomFullScreenVideoAdDidClick:withPlayingProgress:extInfo:替代");
@end

@protocol MSCustomFullScreenVideoEventProtocol <MSCustomFullScreenVideoDeprecatedEventProtocol>

@optional
/**
 * 广告开始加载素材
 */
- (void)msCustomFullScreenStartLoadSource:(UIView * _Nullable)adView;

@required
/**
 全屏视频广告物料加载成功调用
 */
- (void)msCustomFullScreenVideoAdLoadSuccess;
/**
 全屏视频广告物料加载失败调用
 */
- (void)msCustomFullScreenVideoAdLoadFail:(NSError *)error;
/**
 全屏视频缓存成功调用
 */
- (void)msCustomFullScreenVideoAdCacheSuccess:(NSDictionary *_Nullable)extInfo;
/**
 全屏视频缓存失败调用
 */
- (void)msCustomFullScreenVideoAdCacheFailed:(NSError *)error extInfo:(NSDictionary *_Nullable)extInfo;
/**
 全屏视频开始播放调用
 */
- (void)msCustomFullScreenVideoAdDidStarted;
/**
 全屏视频展示成功调用
 @param adView 广告视图
 @param extInfo 媒体个性化参数
 */
- (void)msCustomFullScreenVideoAdShowSuccess:(UIView *_Nullable)adView extInfo:(NSDictionary *_Nullable)extInfo;
/**
 全屏视频展示失败调用
 */
- (void)msCustomFullScreenVideoAdShowFailed:(NSError *)error;
/**
 全屏视频播放完成或视频播放途中发生异常错误调用
 */
- (void)msCustomFullScreenVideoAdDidPlayFinish:(NSError *)error;
/**
 全屏视频已被关闭调用
 */
- (void)msCustomFullScreenVideoAdDidCloseWithPlayingProgress:(CGFloat)progress;
/**
 全屏视频跳过按钮被点击调用
 */
- (void)msCustomFullScreenVideoAdDidSkipWithPlayingProgress:(CGFloat)progress;
/**
 全屏视频被点击调用
 */
- (void)msCustomFullScreenVideoAdDidClick:(UIView *_Nullable)adView withPlayingProgress:(CGFloat)progress extInfo:(NSDictionary *_Nullable)extInfo;
@end

NS_ASSUME_NONNULL_END
