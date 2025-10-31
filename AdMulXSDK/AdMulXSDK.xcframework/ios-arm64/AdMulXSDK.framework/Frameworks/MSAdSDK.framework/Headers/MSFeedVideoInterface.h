//
//  MSNativeFeedVideoInterface.h
//  MSAdSDK
//
//  Created by Liumaos on 2020/8/28.
//  Copyright © 2020 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MSFeedVideoConfig.h"
#import "MSFeedVideoDelegate.h"

@protocol MSFeedVideoInterface <NSObject>
@optional
- (void)registerDataObject:(id<MSFeedAdMeta>)dataObject
            clickableViews:(NSArray<UIView *>*)clickableViews MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用registerDataObject：adContainer:clickableViews替代");
@required
- (void)registerDataObject:(id<MSFeedAdMeta>)dataObject
               adContainer:(UIView *)adContainer
            clickableViews:(NSArray<UIView *>*)clickableViews;
-(void)unregisterDataObject;
-(void) config:(MSFeedVideoConfig*)config
     presentVc:(UIViewController*)presentVc
      delegate:(id<MSFeedVideoDelegate>)delegate;
- (void)playVideo;
- (void)pauseVideo;
- (void)muteVideo:(BOOL)isMute;
- (void)replayVideo;
/**
 * 视频广告时长，单位 s
 */
- (CGFloat)totalTime;
/**
 * 视频广告已播放时长，单位 s
 */
- (CGFloat)currentTime;
/**
 当外部需要再次更新播放器size后需调用该接口通知内部
 调用时机：绑定事件（即调用registerDataObject接口）之后调用
 */
- (void)resizeAdVideo:(CGSize)adsize;
@end


