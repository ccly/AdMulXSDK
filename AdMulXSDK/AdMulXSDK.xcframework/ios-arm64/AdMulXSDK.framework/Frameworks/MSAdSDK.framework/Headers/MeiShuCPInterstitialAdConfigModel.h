//
//  MeiShuCPInterstitialAdConfigModel.h
//  MSAdSDK
//
//  Created by mstech_ios on 2025/6/4.
//  Copyright © 2025 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kMeiShuCPInterstitialAdMediaDrawingKey;//请求开屏展示类型
extern NSString *const kMeiShuCPInterstitialAdMediaVideoMutedKey;//设置视频静音开关
extern NSString *const kMeiShuCPInterstitialAdMediaClkLimitKey;//广告交互类型
extern NSString *const kMeiShuCPInterstitialAdMediaColseAfterClickKey;//广告被点击后是否展示广告
extern NSString *const kMeiShuCPInterstitialAdMediaExpireTimestampKey;//广告过期时长
extern NSString *const kMeiShuCPInterstitialAdMediaMediaExtConfigKey;//媒体个性化参数
extern NSString *const kMeiShuCPInterstitialAdMediaAdnNameKey;//广告源名称
extern NSString *const kMeiShuCPInterstitialAdMediaRequestAdInterfaceKey;//广告请求接口类型
extern NSString *const kMeiShuCPInterstitialAdMediaAdSizeKey;//广告size
extern NSString *const kMeiShuCPInterstitialAdMediaAutoRenderKey;//是否自动渲染
extern NSString *const kMeiShuCPInterstitialAdMediaADNAcceptIDKey;//当前广告源接受方ID

@interface MeiShuCPInterstitialAdConfigModel : NSObject
/**
 请求插屏展示类型
 */
@property(nonatomic,assign,readonly)NSInteger requestAdType;
/**
 设置视频静音开关 默认静音
 */
@property(nonatomic,assign,readonly)BOOL videoMuted;
/**
 广告交互类型
 */
@property(nonatomic,assign,readonly)NSInteger adInteractionType;
/**
 广告被点击后是否展示广告
 */
@property(nonatomic,assign,readonly)BOOL isNeedCloseAdAfterClick;
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
 插屏广告尺寸
 */
@property(nonatomic,assign)CGSize adSize;
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
