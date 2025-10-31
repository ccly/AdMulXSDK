//
//  MeiShuCPRewardAdConfigModel.h
//  MSAdSDK
//
//  Created by mstech_ios on 2025/6/4.
//  Copyright © 2025 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kMeiShuCPRewardAdMediaDrawingKey;//请求开屏展示类型
extern NSString *const kMeiShuCPRewardAdMediaVideoMutedKey;//设置视频静音开关
extern NSString *const kMeiShuCPRewardAdMediaClkLimitKey;//广告请求接口类型
extern NSString *const kMeiShuCPRewardAdMediaUserIDKey;//设置的userId
extern NSString *const kMeiShuCPRewardAdMediaDirectionKey;//视频展示方向
extern NSString *const kMeiShuCPRewardAdMediaRewardCountKey;//奖励数量
extern NSString *const kMeiShuCPRewardAdMediaRewardNameKey;//奖励名称
extern NSString *const kMeiShuCPRewardAdMediaExpireTimestampKey;//
extern NSString *const kMeiShuCPRewardAdMediaMediaExtConfigKey;//媒体个性化参数
extern NSString *const kMeiShuCPRewardAdMediaAdnNameKey;//广告源名称
extern NSString *const kMeiShuCPRewardAdMediaPresentVCKey;// 广告展示的控制器
extern NSString *const kMeiShuCPRewardAdMediaAutoRenderKey;//是否自动渲染
extern NSString *const kMeiShuCPRewardAdMediaADNAcceptIDKey;//当前广告源接受方ID

@interface MeiShuCPRewardAdConfigModel : NSObject
/**
 请求激励视频展示类型
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
 必须，媒体选择服务端验证需设置的userId
 */
@property(nonatomic,copy,readonly)NSString *userId;
/**
 设置视频展示方向 默认竖屏展示
 */
@property(nonatomic,assign,readonly)MSRewardAdShowDirection direction;
/**
 奖励数量
 */
@property(nonatomic,assign,readonly)NSInteger rewardCount;
/**
 奖励名称
 */
@property(nonatomic,copy,readonly)NSString *rewardName;
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
 广告展示的控制器
 */
@property(nonatomic,weak,readonly)UIViewController *presentVc;
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
