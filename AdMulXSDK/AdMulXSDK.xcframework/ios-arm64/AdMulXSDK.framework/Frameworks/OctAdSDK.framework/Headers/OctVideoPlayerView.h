//
//  OctVideoPlayerView.h
//  OctAdSDK
//
//  Created by hongji cai on 2024/11/16.
//

#import <UIKit/UIKit.h>
#import "OctMediaView.h"

NS_ASSUME_NONNULL_BEGIN

@interface OctVideoPlayerView : UIView
//视频的显示模式，默认OctVedioShowModelResizeAspect
@property (nonatomic, assign) OctVedioShowModel showModel;
//声音控制视图, 外部可以改变frame。 width / height = 1 / 1
@property (nonatomic, strong, readonly) UIView *voiceControlView;
/**
 音量控制 ， YES：无声
*/
@property (nonatomic, assign) BOOL muted;

- (instancetype)initWithFrame:(CGRect)frame videoUrl:(NSString*)videoUrl;
@end

NS_ASSUME_NONNULL_END
