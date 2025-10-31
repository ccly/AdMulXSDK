//
//  MSCustomVideoEventProtocol.h
//  MSAdSDK
//
//  Created by leej on 2022/5/18.
//  Copyright © 2022 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//已废弃协议
@protocol MSCustomVideoDeprecatedEventProtocol <NSObject>

@optional
/**
 *  贴片广告曝光调用
 */
- (void)msCustomVideoShow:(UIView *)videoAd MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomVideoShow:extInfo:替代");
/**
 *  视频广告点击调用
 */
- (void)msCustomVideoClick:(UIView *)videoAd MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用msCustomVideoClick:extInfo:替代");

@end

@protocol MSCustomVideoEventProtocol <MSCustomVideoDeprecatedEventProtocol>

@optional
/**
 * 广告开始加载素材
 */
- (void)msCustomVideoStartLoadSource:(UIView * _Nullable)videoAd;
/**
 * 广告素材加载成功调用
 */
- (void)msCustomVideoLoadSourceSuccess:(UIView * _Nullable)videoAd extInfo:(NSDictionary *_Nullable)extInfo;
/**
 * 广告素材加载失败调用
 */
- (void)msCustomVideoLoadSourceFailed:(UIView * _Nullable)videoAd error:(NSError *)error extInfo:(NSDictionary *_Nullable)extInfo;

@required
/**
 *  视频广告加载成功调用
 */
- (void)msCustomVideoLoad;
/**
 * 广告渲染成功回调
 */
- (void)msCustomVideoRenderSuccess:(UIView *)videoAd extInfo:(NSDictionary *_Nullable)info;
/**
 * 广告渲染失败回调
 */
- (void)msCustomVideoRenderFailed:(UIView *)videoAd extInfo:(NSDictionary *_Nullable)info error:(NSError *_Nullable)error;
/**
 *  视频广告成功展示调用
 *  @param videoAd 广告视图
 *  @param extInfo 媒体自定义参数
 */
- (void)msCustomVideoShow:(UIView *)videoAd extInfo:(NSDictionary *_Nullable)extInfo;
/**
    视频广告播放失败调用
 */
-(void)msCustomVideoPlayingError:(UIView *)videoAd error:(NSError *)error;
/**
 *  视频广告加载失败调用
 */
- (void)msCustomVideoError:(NSError *)error;
/**
 *  视频广告点击调用
 */
- (void)msCustomVideoClick:(UIView *)videoAd extInfo:(NSDictionary *_Nullable)extInfo;
/**
 *  视频广告点击关闭调用
 */
- (void)msCustomVideoClose:(UIView *)videoAd;
/**
 *  视频广告size更新调用
 */
- (void)msCustomVideoResize:(UIView *)videoAd adSize:(CGSize)adSize;
/**
 *  视频广告播放完成调用
 */
- (void)msCustomVideoCompletion:(UIView *)videoAd;

@end

NS_ASSUME_NONNULL_END
