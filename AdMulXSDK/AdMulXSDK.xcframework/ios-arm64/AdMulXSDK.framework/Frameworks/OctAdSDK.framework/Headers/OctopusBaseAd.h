//
//  OctopusBaseAd.h
//  OctopusAdSDK
//
//  Created by guantou on 2023/10/24.
//

#import <Foundation/Foundation.h>
#import <OctCore/OctAdShakeConfigModel.h>

NS_ASSUME_NONNULL_BEGIN

/**
     * 竞价失败原因
     * 1001 底价过滤
     * 1002 bid价格低于最高价
     * 1003 素材黑名单过滤
     * 1004 竞品过滤
     * 1005 超时过滤
     * 1006 其它过滤
     */

typedef NS_ENUM(NSInteger, OctAdBiddingFailReason) {
    OctAdBiddingLossReasonPriceFilter = 1001,
    OctAdBiddingLossReasonLowFilter = 1002,
    OctAdBiddingLossReasonBlacklistFilter = 1003,
    OctAdBiddingLossReasonCompeteFilter = 1004,
    OctAdBiddingLossReasonTimeoutFilter = 1005,
    OctAdBiddingLossReasonOther = 1006
};

/**
     * 竞价胜出者
     * CSJ 穿山甲/头条
     * GDT 优量汇/广点通
     * KUAISHOU 快手
     * BAIDU 百青藤/百度
     * SIGMOB sigmob
     * OPPO oppo
     * VIVO vivo
     * HUAWEI 华为
     * XIAOMI 小米
     * OCTOPUS 章鱼
     * JD 京东
     * QM 趣盟
     * ONEWAY 万唯
     * OTHER 其他家
     */
extern NSString *const kOCTWinBidderCSJ;
extern NSString *const kOCTWinBidderGDT;
extern NSString *const kOCTWinBidderKUAISHOU;
extern NSString *const kOCTWinBidderBAIDU;
extern NSString *const kOCTWinBidderSIGMOB;
extern NSString *const kOCTWinBidderOPPO;
extern NSString *const kOCTWinBidderVIVO;
extern NSString *const kOCTWinBidderHUAWEI;
extern NSString *const kOCTWinBidderXIAOMI;
extern NSString *const kOCTWinBidderOCTOPUS;
extern NSString *const kOCTWinBidderJD;
extern NSString *const kOCTWinBidderQM;
extern NSString *const kOCTWinBidderONEWAY;
extern NSString *const kOCTWinBidderOTHER;

@interface OctopusBaseAd : NSObject

////  请求广告
//- (void)requestAds;

/**开屏广告需要方法及其变量*/
@property (nonatomic, strong) UIView *bottomView;
@property (nonatomic, strong) UIView *skipView;
/**控制视频的音量控制按钮是否展示（默认显示）*/
@property (nonatomic, assign) BOOL isHiddenVoiceButton;
/**请求超时时长*/
@property (nonatomic, assign) double timeoutInterval;
/**广告是否有效*/
@property (nonatomic, readonly) BOOL isValidAdvert;

/**
 媒体需要的素材信息反馈, key的定义如下：
 素材ID:id，类型:imageMode(0或1)
 标题:title，描述:description，
 图片地址:imageUrl，视频地址:videoUrl,
 广告主品牌lcon:iconUrl
 */
@property (nonatomic, readonly) NSDictionary *mediaExtraInfoDict;

/**
 摇一摇基本返回参数 key的定义如下：
 加速度:acceleration
 角度：angle
 时间:time
 */
@property (nonatomic, readonly) NSDictionary *shakeParamInfoDict;

/**
摇一摇是否可用， 默认YES
 */
@property (nonatomic, assign) BOOL isCanShake;
/**
摇一摇相关参数配置
 */
@property (nonatomic, strong) OctAdShakeConfigModel *shakeConfigModel;

//竞价成功时上报接口 secondWinPrice竞价第二名价格，单位是分
- (void)sendWinNotice:(NSInteger)secondWinPrice;
//竞价失败时上报接口 winPrice 胜出者价格 单位分 lossReason 竞价失败原因 winBidder 胜出者 （非必填）
- (void)sendLossNotice:(OctAdBiddingFailReason)lossReason winnerPirce:(NSInteger)winPrice winBidder:(NSString * _Nullable )bidder;
//获取requestId
- (NSString*)getRequestId;
//
- (NSString*)getTagId;

@end

NS_ASSUME_NONNULL_END
