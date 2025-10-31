//
//  MSCustomDrawEventProtocol.h
//  MSAdSDK
//
//  Created by leej on 2022/5/19.
//  Copyright © 2022 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//已废弃协议
@protocol MSCustomDrawDeprecatedEventProtocol <NSObject>

@optional
/**
 *  draw广告曝光调用
 */
- (void)msCustomDrawAdVideoShowSuccess:(UIView *)adView MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomDrawAdVideoShowSuccess:extInfo:替代");
/**
 视频缓存成功调用
 */
- (void)msCustomDrawAdVideoCacheSuccess MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomDrawAdVideoCacheSuccess:extInfo:替代");
/**
 视频缓存失败调用
 */
- (void)msCustomDrawAdVideoCacheFailedError:(NSError *)error MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomDrawAdVideoCacheFailedError:extInfo:替代");
/**
 视频被点击调用
 */
- (void)msCustomDrawAdVideoDidClick:(UIView *)adView MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomDrawAdVideoDidClick:extInfo:替代");

@end

@protocol MSCustomDrawEventProtocol <MSCustomDrawDeprecatedEventProtocol>

@optional
/**
 * 广告开始加载素材
 */
- (void)msCustomDrawAdStartLoadSource:(UIView * _Nullable)adView;

@required
/**
 DrawAd广告物料加载成功调用
 */
- (void)msCustomDrawAdLoadSuccess;
/**
 DrawAd广告物料加载失败调用
 */
- (void)msCustomDrawAdLoadFailError:(NSError *)error;
/**
 视频缓存成功调用
 */
- (void)msCustomDrawAdVideoCacheSuccess:(NSDictionary *_Nullable)extInfo;
/**
 视频缓存失败调用
 */
- (void)msCustomDrawAdVideoCacheFailedError:(NSError *)error extInfo:(NSDictionary *_Nullable)extInfo;
/**
 视频展示成功调用
 @param adView 广告视图
 @param extInfo 媒体个性化参数
 */
- (void)msCustomDrawAdVideoShowSuccess:(UIView *)adView extInfo:(NSDictionary *_Nullable)extInfo;
/**
 视频展示失败调用
 */
- (void)msCustomDrawAdVideoShowFailedError:(NSError *)error;
/**
 视频准备开始播放调用
 */
- (void)msCustomDrawAdVideoDidStartPlaying;
/**
 视频暂停播放调用
 */
- (void)msCustomDrawAdVideoDidPause;
/**
 视频重播调用
 */
- (void)msCustomDrawAdVideoDidReplay;
/**
 视频播放完成调用
 */
- (void)msCustomDrawAdVideoDidComplete;
/**
 视频播放失败调用
 */
- (void)msCustomDrawAdVideoPlayingFailedError:(NSError *)error;
/**
 视频被点击调用
 */
- (void)msCustomDrawAdVideoDidClick:(UIView *)adView extInfo:(NSDictionary *_Nullable)extInfo;
/**
 视频被关闭调用
 */
- (void)msCustomDrawAdVideoDidClosed:(UIView *)adView;
/**
 广告落地页已经关闭调用
 */
- (void)msCustomDrawAdVideoDetailClosed;
@end

NS_ASSUME_NONNULL_END
