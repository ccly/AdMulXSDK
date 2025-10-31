//
//  MSExpressFullScreenVideoAdDelegate.h
//  MSAdSDK
//
//  Created by leej on 2022/2/14.
//  Copyright © 2022 Adxdata. All rights reserved.
//

#ifndef MSExpressFullScreenVideoAdDelegate_h
#define MSExpressFullScreenVideoAdDelegate_h

@class MSExpressFullScreenVideoAd;

@protocol MSExpressFullScreenVideoAdDelegate <NSObject>

@optional
/**
 * 加载成功回调
 * 回调说明：广告加载成功时触发
 * 使用场景：媒体如需要统计广告加载成功数可通过实现该回调来统计数据
 */
- (void)msExpressFullScreenVideoAdLoadSuccess:(MSExpressFullScreenVideoAd *)video;
/**
 全屏视频准备就绪
 注意：
 1、请在此回调中展示广告，即调用show接口
 2、展示广告（调用show接口）前请做广告的有效性检查，即获取isReady属性状态
 */
- (void)msExpressFullScreenVideoAdRenderSuccess:(MSExpressFullScreenVideoAd *)video extInfo:(NSDictionary *)info;
/**
 * 全屏视频未达到曝光要求
 * 可能情况：渲染失败、展示时产生的异常
 * 开发者收到此回调后不再进行展示广告相关逻辑
 * @param info 媒体可通过【error_type 】key获取具体错误类型 value是字符串int值（MSErrorCodeADRenderError为渲染失败，MSErrorCodeADShowError为展示时错误）
 */
- (void)msExpressFullScreenVideoAdFail:(MSExpressFullScreenVideoAd *)video extInfo:(NSDictionary *)info error:(NSError *)error;
/**
 全屏视频广告物料加载失败，即最终加载失败
 */
- (void)msExpressFullScreenVideoAdLoadFail:(MSExpressFullScreenVideoAd *)video error:(NSError *)error;
/**
 全屏视频开始播放
 */
- (void)msExpressFullScreenVideoAdDidStarted:(MSExpressFullScreenVideoAd *)video;
/**
 全屏视频展示成功
 */
- (void)msExpressFullScreenVideoAdExposure:(MSExpressFullScreenVideoAd *)video;
/**
 全屏视频播放完成或视频播放途中发生异常错误
 */
- (void)msExpressFullScreenVideoAdDidPlayFinish:(MSExpressFullScreenVideoAd *)video withError:(NSError *)error;;
/**
 全屏视频已被关闭
 @param progress 该参数仅在美数、百度平台下有效
 */
- (void)msExpressFullScreenVideoAdDidClose:(MSExpressFullScreenVideoAd *)video withPlayingProgress:(CGFloat)progress;
/**
 全屏视频跳过按钮被点击
 @param progress 该参数仅在美数、百度平台下有效
 */
- (void)msExpressFullScreenVideoAdDidSkip:(MSExpressFullScreenVideoAd *)video withPlayingProgress:(CGFloat)progress;
/**
 全屏视频被点击
 @param progress 该参数仅在美数、百度平台下有效
 */
- (void)msExpressFullScreenVideoAdDidClick:(MSExpressFullScreenVideoAd *)video withPlayingProgress:(CGFloat)progress;
@end

#pragma mark 全屏广告扩展功能回调（包含统计、获取个性化参数等回调）

@protocol MSExpressFullScreenVideoAdExtensionFunctionDelegate <NSObject>

@optional
/**
   渠道加载失败回调
 * 回调说明：当前广告平台请求失败后调用，为保证填充，该广告位可能配置多家渠道，当前渠道请求失败后触发该回调，注意此回调并不代表本次请求动作已经结束且可能存在多次回调的情况
 * 使用场景：媒体如需要统计渠道加载失败数可通过实现该回调来统计数据
 */
- (void)msExpressFullScreenVideoAdPlatformError:(MSPlatform)platform
                                        videoAd:(MSExpressFullScreenVideoAd *)video
                                          error:(NSError *)error;
@end
#endif /* MSExpressFullScreenVideoAdDelegate_h */
