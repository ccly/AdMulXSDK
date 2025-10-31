//
//  OctSplashImageViewController.h
//  OctopusAdSDK
//
//  Created by guantou on 2020/1/13.
//

#import <UIKit/UIKit.h>
#import <OctCore/OctBaseViewController.h>
#import <OctCore/OctAdvertisingType.h>

NS_ASSUME_NONNULL_BEGIN

@class OctSpaceInfoModel;
@protocol OctWorkerDelegate;
@class OctBuyerModel;
@class OCTStrategyHelper;
@class OctAdRecordModel;
@class OctBusinessReport;
@class OctAdSplash;

@interface OctSplashImageViewController : OctBaseViewController

- (instancetype)initWithSpaceInfo:(OctSpaceInfoModel *)spaceInfo BottomView:(UIView *)bottomView SkipView:(UIView *)skipView isVedio:(BOOL)isVedio;

@property (nonatomic, strong) OctBuyerModel *buyerModel;
@property (nonatomic, weak) id<OctWorkerDelegate> delegate;
//特殊处理， 临时保留广告对象, 在广告关闭时， 需要主动置nil
@property (nonatomic, strong, nullable) OctAdSplash *adSplash;
//从落地页回到广告页时， 如果此时倒计时还未结束，是否关闭广告
@property (nonatomic, assign) BOOL isCloseAfterBackToAdvert;

//@property (nonatomic, weak) UIWindow *containerWindow;

@property (nonatomic, copy) NSString *randomUUID;

@property (nonatomic, strong) OCTStrategyHelper *strategyHelper;

@property (nonatomic, strong) OctAdRecordModel *adRecordModel;

@property (nonatomic, strong, readonly) OctBusinessReport *businessReport;

/**控制视频的音量控制按钮是否展示（默认显示）*/
@property (nonatomic, assign) BOOL isHiddenVoiceButton;
//设置倒计时的时间, 取值 >= 3s
@property (nonatomic, assign) NSInteger countDownSeconds;
//
@property (nonatomic, assign) uint64_t startReqTime;

- (void)addCloseView:(void(^)(BOOL isExpose))exposeBlock;

- (void)reportDeepLink:(BOOL)isSuccess;

// 上报竞价成功
- (void)oct_reportWinPrice:(NSString*)secondPrice;

// 上报竞价失败
- (void)oct_reportLossPrice:(NSString*)winPrice loseReason:(NSString*)reason winBidder:(NSString *)bidder;

//控制倒计时开启
- (void)startCountDown:(BOOL)isStart;

@end

NS_ASSUME_NONNULL_END
