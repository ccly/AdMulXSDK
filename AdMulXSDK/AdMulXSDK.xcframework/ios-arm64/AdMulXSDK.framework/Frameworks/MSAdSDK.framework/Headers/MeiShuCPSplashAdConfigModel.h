//
//  MeiShuCPSplashAdConfigModel.h
//  MSAdSDK
//
//  Created by mstech_ios on 2025/5/23.
//  Copyright © 2025 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kMeiShuCPSplashAdMediaWindowKey;//广告window
extern NSString *const kMeiShuCPSplashAdMediaAdSizeKey;//广告size
extern NSString *const kMeiShuCPSplashAdMediaAdnNameKey;//广告源名称
extern NSString *const kMeiShuCPSplashAdMediaDrawingKey;//请求开屏展示类型
extern NSString *const kMeiShuCPSplashAdMediaShowTimeKey;//开屏展示时长
extern NSString *const kMeiShuCPSplashAdMediaSkipViewKey;//自定义跳过按钮
extern NSString *const kMeiShuCPSplashAdMediaClkLimitKey;//广告交互类型
extern NSString *const kMeiShuCPSplashAdMediaPresentVcKey;//广告展示的控制器
extern NSString *const kMeiShuCPSplashAdMediaVideoMutedKey;//设置视频静音开关
extern NSString *const kMeiShuCPSplashAdMediaFetchDelayKey;//广告加载超时时长
extern NSString *const kMeiShuCPSplashAdMediaBottomSizeKey;//底部logo size
extern NSString *const kMeiShuCPSplashAdMediaBottomViewKey;//开屏广告底部视图
extern NSString *const kMeiShuCPSplashAdMediaAutoRenderKey;//是否自动渲染
extern NSString *const kMeiShuCPSplashAdMediaClickTextKey;//开屏点击文案
extern NSString *const kMeiShuCPSplashAdMediaNeedZoomViewKey;//是否展示点睛
extern NSString *const kMeiShuCPSplashAdMediaMediaExtConfigKey;//媒体个性化参数
extern NSString *const kMeiShuCPSplashAdMediaHideSkipButtonKey;//隐藏跳过按钮
extern NSString *const kMeiShuCPSplashAdMediaShowAfterLoadKey;//加载成功后是否立即展示
extern NSString *const kMeiShuCPSplashAdMediaExpireTimestampKey;//广告过期时长
extern NSString *const kMeiShuCPSplashAdMediaRequestAdInterfaceKey;//广告请求接口类型
extern NSString *const kMeiShuCPSplashAdMediaHideSplashStatusBarKey;//隐藏状态栏
extern NSString *const kMeiShuCPSplashAdMediaADNAcceptIDKey;//当前广告源接受方ID

@interface MeiShuCPSplashAdConfigModel : NSObject
/**
 广告size
 */
@property(nonatomic,assign,readonly)CGSize adSize;
/**
 是否展示点睛
 */
@property(nonatomic,assign,readonly)BOOL isNeedZoomView;
/**
 开屏展示时长 单位s
 */
@property(nonatomic,assign,readonly)NSInteger splashShowTime;
/**
 请求开屏展示类型
 */
@property(nonatomic,assign,readonly)NSInteger requestAdType;
/**
 开屏广告底部视图
 */
@property(nonatomic,weak,readonly,nullable)UIView *bottomView;
/**
 窗口
 */
@property(nonatomic,weak,readonly)UIWindow *window;
/**
 底部logo size
 即@property(nonatomic,weak)UIView *bottomView; 的size
 */
@property(nonatomic,assign,readonly)CGSize splashBottomSize;
/**
 广告交互类型
 */
@property(nonatomic,assign,readonly)NSInteger adInteractionType;
/**
 广告加载超时时长 单位s
 */
@property(nonatomic,assign,readonly)NSInteger splashLoadFetchDelay;
/**
 自定义跳过按钮
 */
@property(nonatomic,weak,readonly,nullable)UIView *skipView;
/**
 广告展示的控制器
 */
@property(nonatomic,weak,readonly)UIViewController *presentVc;
/**
 加载成功后是否立即展示
 */
@property(nonatomic,assign,readonly)BOOL isShowAfterLoad;
/**
 开屏点击文案
 */
@property(nonatomic,copy,readonly)NSString *splashClickText;
/**
 隐藏跳过按钮 默认不隐藏
 */
@property(nonatomic,assign,readonly)BOOL hideSkipButton;
/**
 隐藏状态栏
 */
@property(nonatomic,assign,readonly)BOOL hideSplashStatusBar;
/**
 设置视频静音开关 默认静音
 */
@property(nonatomic,assign,readonly)BOOL videoMuted;
/**
 广告过期时长 单位s
 */
@property(nonatomic,assign)NSInteger expire_timestamp;
/**
 媒体其他个性化参数
 */
@property(nonatomic,strong,readonly,nullable)NSDictionary *mediaExtConfig;
/**
 当前广告源名称
 */
@property(nonatomic,copy,readonly,nullable)NSString *adnName;
/**
 广告请求接口类型
 */
@property(nonatomic,assign,readonly)MSAdType requestAdInterface;
/**
 * 是否自动渲染 默认YES （可选参数）
 */
@property(nonatomic,assign)BOOL isAutoRender;
/**
 当前广告源接受方ID
 */
@property(nonatomic,copy,readonly,nullable)NSString *adnAcceptID;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
