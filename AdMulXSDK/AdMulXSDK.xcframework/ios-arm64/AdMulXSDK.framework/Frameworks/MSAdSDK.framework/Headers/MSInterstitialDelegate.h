//
//  MSInterstitialDelegate.h
//  MSAdSDKDev
//
//  Created by Liumaos on 2020/7/23.
//  Copyright © 2020 Adxdata. All rights reserved.
//

#ifndef MSInterstitialDelegate_h
#define MSInterstitialDelegate_h


@class MSInterstitialAd;

@protocol MSInterstitialDelegate <NSObject>

@optional
/**
 * 加载成功回调
 * 回调说明：广告加载成功时触发
 * 使用场景：媒体如需要统计广告加载成功数可通过实现该回调来统计数据
 */
- (void)msInterstitialLoadedSuccess:(MSInterstitialAd *)msInterstitialAd;
/**
 *  广告预加载失败回调
 *  详解:当接收服务器返回的广告数据失败后调用该函数
 */
- (void)msInterstitialLoadedFail:(MSInterstitialAd *)msInterstitialAd error:(NSError *)error;
/**
 * 插屏广告渲染成功回调 可以进行展示 在此回调中调用show接口展示广告
 */
- (void)msInterstitialAdRenderSuccess:(MSInterstitialAd *)msInterstitialAd extInfo:(NSDictionary *)info;
/**
 *  插屏广告视图展示成功回调
 *  详解: 插屏广告展示成功回调该函数
 */
- (void)msInterstitialExposure:(MSInterstitialAd *)msInterstitialAd;
/**
 * 插屏广告未达到曝光要求
 * 可能情况：渲染失败、展示时产生的异常
 * 开发者收到此回调后不再进行展示广告相关逻辑
 * @param info 媒体可通过【error_type 】key获取具体错误类型 value是字符串int值（MSErrorCodeADRenderError为渲染失败，MSErrorCodeADShowError为展示时错误）
 */
- (void)msInterstitialAdFail:(MSInterstitialAd *)msInterstitialAd extInfo:(NSDictionary *)info error:(NSError *)error;
/**
 *  插屏广告展示结束回调
 *  详解: 插屏广告展示结束回调该函数
 */
- (void)msInterstitialClosed:(MSInterstitialAd *)msInterstitialAd;
/**
 *  插屏广告点击回调
 */
- (void)msInterstitialClicked:(MSInterstitialAd *)msInterstitialAd;
/**
 *  全屏广告页被关闭
 */
- (void)msInterstitialDetailClosed:(MSInterstitialAd *)msInterstitialAd;

@end

#pragma mark 插屏扩展功能回调（包含统计、获取个性化参数等回调）

@protocol MSInterstitialExtensionFunctionDelegate <NSObject>

@optional
/**
   渠道加载失败回调
 * 回调说明：当前广告平台请求失败后调用，为保证填充，该广告位可能配置多家渠道，当前渠道请求失败后触发该回调，注意此回调并不代表本次请求动作已经结束且可能存在多次回调的情况
 * 使用场景：媒体如需要统计渠道加载失败数可通过实现该回调来统计数据
 */
- (void)msInterstitialPlatformError:(MSPlatform)platform ad: (MSInterstitialAd *)msInterstitialAd error:(NSError *)error;
@end
#endif /* MSInterstitialDelegate_h */
