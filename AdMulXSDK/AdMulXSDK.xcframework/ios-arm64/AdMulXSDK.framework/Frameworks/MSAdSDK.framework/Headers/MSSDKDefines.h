//
//  GDTSDKDefines.h
//  GDTMobApp
//
//  Created by royqpwang on 2017/11/6.
//  Copyright © 2017年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define MeiShuAdDEPRECATED_MSG(insteadString) DEPRECATED_MSG_ATTRIBUTE(insteadString)

typedef NS_ENUM(NSInteger,MSLogLevel) {
    MSLogNone  = 0,  //不打印Log
    MSLogError = 1, //只打印Error
    MSLogAll   = 2//全部打印
};
/**
 广告平台
 */
typedef NS_ENUM(NSInteger, MSPlatform) {
    MSPlatformMS      = 0, // 美数
    MSPlatformGDT     = 1, // 广点通
    MSPlatformBU      = 2, // 穿山甲
    MSPlatformBD      = 3, // 百度
    MSPlatformKS      = 6, // 快手
    MSPlatformJD      = 7, // 京东
    MSPlatformCP      = 8, // 自定义平台
    MSPlatformSigMob  = 9  // sigMob
};
/**
 请求广告参数secure值
 */
typedef NS_ENUM(NSInteger, MSSecure) {
    MSSecureHttp  = 0,  // 仅支持http
    MSSecureHttps = 1,  // 仅支持https
    MSSecureAll   = 2,  // 支持http 和 https
};
/**
 信息流布局类型
 */
typedef NS_ENUM(NSInteger, MSNativeAdType) {
    MSNativeAdLeftImage         = 0,   // 展示左图右文+下载按钮
    MSNativeAdLeftImageNoButton = 1,   // 展示左图右文
    MSNativeAdBottomImage       = 2,   // 展示上文下大图
    MSNativeAdThreeImage        = 3,   // 三图
    MSNativeAdVideo             = 4,   // 视频
};
/**
 性别
 */
 typedef NS_ENUM(NSInteger, MSGender) {
     MSGenderUnknown = -1,   // 未知
     MSGenderMale = 1,       // 男性
     MSGenderFemale = 10,    // 女性
 };
/**
 * 广告类型
 */
 typedef NS_ENUM(NSInteger, MSAdType) {
     MSAdTypeFeed            = 1,  // 自渲染信息流
     MSAdTypeFeedPreRender   = 2,  // 模板渲染信息流
     MSAdTypeBanner          = 3,  // 横幅 banner
     MSAdTypeSplash          = 4,  // 开屏
     MSAdTypeInterstitial    = 5,  // 插屏
     MSAdTypePaster          = 6,  // 贴片
     MSAdTypeReward          = 7,  // 激励视频
     MSAdTypeDraw            = 8,  // 信息流视频
     MSAdTypeFullScreenVideo = 9,  // 全屏视频
     MSAdTypeNativeExpressAd = 10  // 新版信息流（自渲染and模版）
 };
/**
 * 错误码
 */
typedef NS_ENUM(NSInteger,MSErrorCode) {
    MSErrorCodeADLoadImageError         = -1,  //加载图片失败
    MSErrorCodeADLoadStyleError         = 3,   //广告加载方式异常
    MSErrorCodeNoADError                = 204, //无广告
    MSErrorCodeADCancleError            = 700, //广告被取消加载
    MSErrorCodeADMaterialError          = 1001,//素材URL不合法
    MSErrorCodeADNetWorkError           = 3001,//网络错误
    MSErrorCodeADTypeError              = 4003,//广告类型错误
    MSErrorCodeADLoadVideoError         = 6020,//视频加载失败或者视频广告资源地址不存在
    MSErrorCodeADPidError               = 6021,//广告位id异常
    MSErrorCodeADNotValidError          = 6022,//广告无效
    MSErrorCodeUndefinedError           = 6666,//未知错误
    MSErrorCodeADLoadFailError          = 800001, //资源加载失败
    MSErrorCodeADNotSupportSDKError     = 800002, //未聚合该sdk或sdk版本过低
    MSErrorCodeADNotValidParamError     = 800003, //设置的广告参数异常
    MSErrorCodeADNotValidClassNameError = 800004, //设置的广告类名参数异常
    MSErrorCodeADContentParseError      = 800005, //广告解析异常
    MSErrorCodeADShowError              = 800006, //广告展示异常
    MSErrorCodeADSDKInitError           = 800007,//初始化SDK异常
    MSErrorCodeADSourceBiddingFailError = 800008,//广告源竞价失败
    MSErrorCodeADRenderError            = 800009,//广告渲染失败
};
/**
 广告点击类型
 */
typedef NS_ENUM(NSInteger, MSTargetType) {
    MSTargetTypeDetail = 0,     // 详情页
    MSTargetTypeDownload = 1,   // 下载
};
/**
 视频播放状态
 */
typedef NS_ENUM(NSInteger, MSPlayerPlayState) {
    MSPlayerStateStarted   = 0,
    MSPlayerStateFailed    = 1,
    MSPlayerStatePlaying   = 2,
    MSPlayerStateStopped   = 3,
    MSPlayerStatePause     = 4
};
typedef NS_ENUM(NSInteger,MSAdBiddingErrorType) {
    MSAdBiddingTimeoutErrorType = 0,//超时
    MSAdBiddingLossErrorType    = 1,//竞价失败
    MSAdBiddingLoadErrorType    = 2 //加载失败
};
