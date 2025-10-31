//
//  MSCustomRewardEventProtocol.h
//  MSAdSDK
//
//  Created by leej on 2022/5/17.
//  Copyright © 2022 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
//已废弃协议
@protocol MSCustomRewardDeprecatedEventProtocol <NSObject>

@optional
/**
 视频广告曝光调用
 */
- (void)msCustomRewardVideoShow MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomRewardVideoShow:extInfo:替代");
/**
 视频广告信息点击调用
 */
- (void)msCustomRewardVideoClicked MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomRewardVideoClicked:extInfo:替代");
/**
 视频数据下载成功调用
 */
- (void)msCustomRewardVideoCached MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomRewardVideoCached:extInfo:替代");
/**
 视频广告播放达到激励条件调用
 @param rewardNum  奖励数量 不传默认按后端返回结果为准
 @param rewardName 奖励名称 不传默认按后端返回结果为准
 @param verify 是否验证成功 0:验证失败 1：验证成功 必传
 */
- (void)msCustomRewardVideoReward:(NSString * _Nullable)rewardNum
                       rewardName:(NSString * _Nullable)rewardName
                           verify:(NSString * _Nonnull)verify MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomRewardVideoReward:rewardName:verify:extInfo:替代");
@end

@protocol MSCustomRewardEventProtocol <MSCustomRewardDeprecatedEventProtocol>

@optional
/**
 * 广告开始加载素材
 */
- (void)msCustomRewardVideoStartLoadSource:(UIView * _Nullable)adView;

@required
/**
 广告数据加载成功调用
 */
- (void)msCustomRewardVideoLoaded;
/**
 视频数据下载成功调用
 */
- (void)msCustomRewardVideoCached:(UIView * _Nullable)adView extInfo:(NSDictionary *_Nullable)extInfo;
/**
 * 广告素材加载失败调用
 */
- (void)msCustomRewardVideoCachedFailed:(UIView * _Nullable)adView error:(NSError *_Nullable)err extInfo:(NSDictionary *_Nullable)extInfo;
/**
 激励视频渲染成功调用
 */
- (void)msCustomRewardVideoRenderSuccess;
/**
 激励视频渲染失败调用
 */
- (void)msCustomRewardVideoRenderFail:(NSError *)error;
/**
 视频播放页即将展示调用
 */
- (void)msCustomRewardVideoWillShow;
/**
 视频广告曝光调用
 @param adView 广告视图
 @param extInfo 广告个性化参数
 */
- (void)msCustomRewardVideoShow:(UIView *_Nullable)adView extInfo:(NSDictionary *_Nullable)extInfo;
/**
 视频播放页关闭调用
 */
- (void)msCustomRewardVideoClosed;
/**
 视频广告信息点击调用
 @param adView 广告视图
 @param extInfo 广告个性化参数
 */
- (void)msCustomRewardVideoClicked:(UIView *_Nullable)adView extInfo:(NSDictionary *_Nullable)extInfo;
/**
 视频广告开始播放调用
 */
- (void)msCustomRewardVideoStartPlaying;
/**
 视频广告暂停播放调用
 */
- (void)msCustomRewardVideoStopPlaying;
/**
 视频广告恢复播放调用
 */
- (void)msCustomRewardVideoResumePlaying;
/**
 视频广告播放异常调用
 */
- (void)msCustomRewardVideoPlayingError:(NSError *)error;
/**
 视频广告点击跳过调用
 */
- (void)msCustomRewardVideoClickSkipAndCurrentTime:(NSTimeInterval)currentTime;
/**
 视频广告错误调用
 */
- (void)msCustomRewardVideoError:(NSError *)error;
/**
 视频广告播放达到激励条件调用
 @param rewardNum  奖励数量 不传默认按后端返回结果为准
 @param rewardName 奖励名称 不传默认按后端返回结果为准
 @param verify 是否验证成功 0:验证失败 1：验证成功 必传
 @param extInfo 额外参数
 */
- (void)msCustomRewardVideoReward:(NSString * _Nullable)rewardNum
                       rewardName:(NSString * _Nullable)rewardName
                           verify:(NSString * _Nonnull)verify
                          extInfo:(NSDictionary * _Nullable)extInfo;
/**
 视频广告视频播放完成调用
 */
- (void)msCustomRewardVideoFinish;
@end

NS_ASSUME_NONNULL_END
