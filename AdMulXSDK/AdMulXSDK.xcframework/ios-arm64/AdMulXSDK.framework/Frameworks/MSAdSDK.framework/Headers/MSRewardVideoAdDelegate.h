//
//  MSRewardVideoAdDelegate.h
//  MSAdSDK
//
//  Created by Liumaos on 2020/7/20.
//  Copyright © 2020 XiXiHaha. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MSRewardVideoAd;

@protocol MSRewardVideoAdDelegate <NSObject>

@optional
/**
 广告数据加载成功回调
 @param msRewardVideoAd MSRewardVideoAd 实例
 */
- (void)msRewardVideoLoadedSuccess:(MSRewardVideoAd *)msRewardVideoAd;
/**
 视频广告各种错误信息回调
 回调说明：如收到该回调说明本次请求已失败
 @param msRewardVideoAd MSRewardVideoAd 实例
 @param error 具体错误信息
 */
- (void)msRewardVideoLoadedFail:(MSRewardVideoAd *)msRewardVideoAd error:(NSError *)error;
/**
 * 广告未达到曝光要求
 * 可能情况：渲染失败、展示时产生的异常
 * 开发者收到此回调后不再进行展示广告相关逻辑
 * @param info 媒体可通过【error_type 】key获取具体错误类型 value是字符串int值（MSErrorCodeADRenderError为渲染失败，MSErrorCodeADShowError为展示时错误）
 */
- (void)msRewardVideoAdFail:(MSRewardVideoAd *)RewardVideoAd extInfo:(NSDictionary *)info error:(NSError *)error;
/**
 视频数据下载成功回调，已经下载过的视频会直接回调,在该回调中调用show接口
 @param msRewardVideoAd MSRewardVideoAd 实例
 */
- (void)msRewardVideoCached:(MSRewardVideoAd *)msRewardVideoAd;
/**
 激励视频渲染成功
 */
- (void)msRewardVideoRenderSuccess:(MSRewardVideoAd *)msRewardVideoAd;
/**
 视频播放页即将展示回调
 @param msRewardVideoAd MSRewardVideoAd 实例
 */
- (void)msRewardVideoWillShow:(MSRewardVideoAd *)msRewardVideoAd;
/**
 视频广告曝光回调
 @param msRewardVideoAd MSRewardVideoAd 实例
 */
- (void)msRewardVideoExposure:(MSRewardVideoAd *)msRewardVideoAd;
/**
 视频广告开始播放回调
 @param msRewardVideoAd MSRewardVideoAd 实例
 支持平台：美数、快手、百度
 */
- (void)msRewardVideoStartPlaying:(MSRewardVideoAd *)msRewardVideoAd;
/**
 视频广告暂停播放回调
 @param msRewardVideoAd MSRewardVideoAd 实例
 支持平台：美数
 */
- (void)msRewardVideoStopPlaying:(MSRewardVideoAd *)msRewardVideoAd;
/**
 视频广告恢复播放回调
 @param msRewardVideoAd MSRewardVideoAd 实例
 用户触发某些跳转逻辑后再次回到当前页面观看视频时触发，比如点击广告跳转落地页、跳出应用再次回到应用等场景
 支持平台：美数
 */
- (void)msRewardVideoResumePlaying:(MSRewardVideoAd *)msRewardVideoAd;
/**
 视频播放页关闭回调
 @param msRewardVideoAd MSRewardVideoAd 实例
 */
- (void)msRewardVideoClosed:(MSRewardVideoAd *)msRewardVideoAd;
/**
 视频广告信息点击回调
 @param msRewardVideoAd MSRewardVideoAd 实例
 */
- (void)msRewardVideoClicked:(MSRewardVideoAd *)msRewardVideoAd;
/**
 视频广告点击跳过回调
 @param msRewardVideoAd MSRewardVideoAd 实例
 @param currentTime 当前播放时间
 支持平台：
 ms     支持返回currentTime
 快手    低版本不会返回currentTime 默认0 高版本会返回currentTime
 穿山甲  不会返回currentTime 默认0
 sigmob 不会返回currentTime 默认0
 */
- (void)msRewardVideoClickSkip:(MSRewardVideoAd *)msRewardVideoAd currentTime:(NSTimeInterval)currentTime;
/**
 视频广告播放达到激励条件回调
 @param msRewardVideoAd MSRewardVideoAd 实例
 @param adInfo 激励信息包含的内容格式示例如下：
 {
  @"GDTRewardInfo" : 字典，//广点通返回的信息,注意此字段只有广点通平台激励视频才会返回，媒体获取时务必检查是否为空
  @"rewardVerify"  : @"1",//是否达到发放奖励条件，此值为必传项，取值范围【0-1】，0:未达到，1:达到
  @"rewardName"    : @"各种豆",//奖励名称，该值可能为空，可在美数平台进行配置
  @"rewardAmount"  : @"10",//奖励数量，该值可能为空，可在美数平台进行配置
  @"rewardVerifyError" : @"未知错误",//服务端验证错误信息，该值可能为空
 }
 详解：是否支持服务端验证都会触发激励回调，其他详解请查看接入文档
 */
- (void)msRewardVideoReward:(MSRewardVideoAd *)msRewardVideoAd extInfo:(NSDictionary *)adInfo;
/**
 视频广告视频播放完成
 @param msRewardVideoAd MSRewardVideoAd 实例
 */
- (void)msRewardVideoFinish:(MSRewardVideoAd *)msRewardVideoAd;

@end

#pragma mark 激励视频扩展功能回调（包含统计、获取个性化参数等回调）
@protocol MSRewardVideoAdExtensionFunctionDelegate <NSObject>

@optional
/**
   渠道加载失败回调
 * 回调说明：当前广告平台请求失败后调用，为保证填充，该广告位可能配置多家渠道，当前渠道请求失败后触发该回调，注意此回调并不代表本次请求动作已经结束且可能存在多次回调的情况
 * 使用场景：媒体如需要统计渠道加载失败数可通过实现该回调来统计数据
 @param msRewardVideoAd MSRewardVideoAd 实例
 @param platform 广告平台
 @param error 具体错误信息
 */
- (void)msRewardVideoPlatformError:(MSRewardVideoAd *)msRewardVideoAd platform:(MSPlatform)platform error:(NSError *)error;
@end
