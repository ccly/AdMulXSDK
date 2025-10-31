//
//  MSSplashAdDelegate.h
//  MSAdSDKDev
//
//  Created by Liumaos on 2020/7/16.
//  Copyright © 2020 XiXiHaha. All rights reserved.
//

#ifndef MSSplashAdDelegate_h
#define MSSplashAdDelegate_h

@class MSSplashAd;

@protocol MSSplashAdDelegate <NSObject>

@optional
/**
 * 开屏广告加载成功回调
 * 回调说明：广告加载成功时触发
 * 使用场景：媒体如需要统计广告加载成功数可通过实现该回调来统计数据
 */
- (void)msSplashLoadedSuccess:(MSSplashAd *)splashAd;
/**
 * 开屏广告请求失败回调
 * 回调说明：如收到该回调说明本次请求已加载失败
 */
- (void)msSplashLoadedFail:(MSSplashAd *)splashAd withError:(NSError *)error;
/**
 * 开屏广告渲染成功回调
 * 回调说明：媒体收到此回调后调用show接口
 * 注意事项：⚠️如果调用是loadAndShowSplashAd接口则不需要调用show接口
 */
- (void)msSplashAdRenderSuccess:(MSSplashAd *)splashAd extInfo:(NSDictionary *)info;
/**
 * 开屏广告投屏成功回调
 */
- (void)msSplashPresent:(MSSplashAd *)splashAd;
/**
 * 开屏广告曝光成功回调
 */
- (void)msSplashExposure:(MSSplashAd *)splashAd;
/**
 * 开屏广告展示剩余时间（支持美数、广点通）
 */
- (void)msSplashAdLifeTime:(NSInteger)time splashAd:(MSSplashAd *)splashAd;
/**
 * 开屏广告未达到曝光要求
 * 可能情况：渲染失败、展示时产生的异常
 * 开发者收到此回调后不再进行展示广告相关逻辑
 * @param info 媒体可通过【error_type 】key获取具体错误类型 value是字符串int值（MSErrorCodeADRenderError为渲染失败，MSErrorCodeADShowError为展示时错误）
 */
- (void)msSplashAdFail:(MSSplashAd *)splashAd extInfo:(NSDictionary *)info error:(NSError *)error;
/**
 * 开屏广告点击回调
 */
- (void)msSplashClicked:(MSSplashAd *)splashAd;
/**
 * 开屏广告将要关闭回调
 */
- (void)msSplashWillClosed:(MSSplashAd *)splashAd;
/**
 * 开屏广告关闭回调
 */
- (void)msSplashClosed:(MSSplashAd *)splashAd;
/**
 * 广告落地页已经关闭
 */
- (void)msSplashDetailClosed:(MSSplashAd *)splashAd;
/**
 * 开屏广告跳过回调
 * 回调说明：点击跳过按钮时触发
 */
- (void)msSplashSkip:(MSSplashAd *)splashAd;

@end

#pragma mark 开屏广告其他扩展功能回调（包含统计、获取个性化参数等回调）

@protocol MSSplashAdExtensionFuctionDelegate <NSObject>

@optional
/**
 * 开始加载广告回调
 * 回调说明：当该广告位上配置多家渠道，每个渠道开始加载广告时触发 loadPlatform为当前开始加载的平台
 * 使用场景：媒体如需要统计各个渠道加载情况可通过实现该回调来统计数据
 */
- (void)msSplashStartLoaded:(MSSplashAd *)splashAd currentLoadPlatform:(MSPlatform)loadPlatform;
/**
 * 渠道加载失败回调
 * 回调说明：当前广告平台请求失败后调用，为保证填充，该广告位可能配置多家渠道，当前渠道请求失败后触发该回调，注意此回调并不代表本次请求动作已经结束且可能存在多次回调的情况
 * 使用场景：媒体如需要统计渠道加载失败数可通过实现该回调来统计数据
 */
- (void)msSplashPlatformError:(MSPlatform)platform
                     splashAd:(MSSplashAd *)splashAd
                        error:(NSError*)error;
@end

#endif /* MSSplashAdDelegate_h */
