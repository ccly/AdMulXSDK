//
//  OctopusNativeAdDataModel.h
//  OctopusAdDemo
//
//  Created by guantou on 2023/11/15.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class OctResponseModel;
@class OctSpaceInfoModel;
@class OctMediaView;
@class OctBlurView;
@class OctDisposeResponseModel;

@interface OctNativeAdDataModel : NSObject

//  按钮文字
@property (nonatomic, strong, readonly) NSString *octAction;
//  广告标题
@property (nonatomic, strong, readonly) NSString *octHeadline;
//  广告图片素材
@property (nonatomic, strong, readonly) NSArray *octImages;
//  广告文字素材
@property (nonatomic, strong, readonly) NSArray *octTexts;
//  广告视频素材
@property (nonatomic, strong, readonly) NSArray *octVideos;
//  octImages中第一个图片的宽， 当octIsVideo=NO时，才有效
@property (nonatomic, assign, readonly) NSInteger octWidth;
//  octImages中第一个图片的高， 当octIsVideo=NO时，才有效
@property (nonatomic, assign, readonly) NSInteger octHeight;


// 由于广告法规定，必须添加logo，（建议：广告图片放置在广告的左下角，logo放置在广告的右下角）
//  广告图片，当此字符串不为空时，加载adLabelURL的图片。
@property (nonatomic, strong, readonly) NSString *octLabelURL;
//  广告文字，当adLabelURL为空时，使用adLabel的文字
@property (nonatomic, strong, readonly) NSString *octLabel;
//  logo图片，当此字符串不为空时，加载logoURL的图片。
@property (nonatomic, strong, readonly) NSString *octLogoURL;
//  logo文字，当logoURL为空时，使用logoLabel的文字
@property (nonatomic, strong, readonly) NSString *octLogoLabel;
// AppIcon的url
@property (nonatomic, strong, readonly) NSString *appIconUrl;


//摇一摇的UIImageView视图， 调用startAnimating方法，即可开启摇一摇的动画，视图width / height = 1 ：1
@property (nonatomic, strong, readonly) UIImageView *octShakeImageView;
//是否是视频
@property(nonatomic, assign, readonly) BOOL octIsVideo;
//如果octIsVideo=YES，那么会提供视图播放器视图
@property(nonatomic, strong, readonly) OctMediaView *octMediaView;
/**
 高斯模糊的图片视图， 自己调整frame的大小就可以，默认显示图片octImages.firstObject, 防止图片变形; 当octIsVideo=true时，blurView=nil
 也可以自定义OctBlurView， 来展示图片
 */
@property(nonatomic, strong, readonly) OctBlurView *blurView;


// 绑定展示视图和广告点击View（该视图点击可以跳转到落地页）
- (void)bindVieWithContainer:(UIView *)containerView clickableViews:(NSArray *)clickableViews;
// 添加关闭视图（该视图点击，可以关闭广告）
- (void)addADCloseTarget:(UIView*)targetView;
// 添加摇一摇视图， 调用此方法后， sdk内会开启摇一摇的监听, 以及targetView的点击响应
- (void)addShakeTarget:(UIView*)targetView;


/**
 SDK内部方法，无需调用与使用
 */
- (instancetype)initWithData:(OctDisposeResponseModel*)disposeModel;

@end

NS_ASSUME_NONNULL_END
