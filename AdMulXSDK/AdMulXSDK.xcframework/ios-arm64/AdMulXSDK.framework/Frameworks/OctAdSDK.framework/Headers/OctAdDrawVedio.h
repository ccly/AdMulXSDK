//
//  OctAdDrawVedio.h
//  OctopusAdDemo
//
//  Created by guantou on 2023/11/16.
//
#import "OctopusBaseAd.h"

NS_ASSUME_NONNULL_BEGIN

@protocol OctDrawVedioDelegate;

@interface OctAdDrawVedio : OctopusBaseAd

// controller 展示view的控制器或者弹出落地页的需要的控制器，此参数不能为空
@property (nonatomic, weak) UIViewController *controller;

// 设置原生广告的代理
@property (nonatomic, weak)id<OctDrawVedioDelegate> delegate;

//是否是视频广告
@property (nonatomic, readonly) BOOL isVideoAd;

// 原生初始化
- (instancetype)initWithSlotId:(NSString *)slotId;

// 加载广告
- (void)loadAd;

// 获取广告返回价格(价格单位：分)
- (int)getPrice;

// 广告是否加载成功
- (BOOL)isLoaded;

// 获取广告时效(单位：毫秒)
- (NSInteger)getValidTime;

// 广告加载成功后获得的 View广告（数组内部为加载完成的View形式广告，直接add到目标View）
@property (nonatomic, strong, readonly) NSArray *drawVedioAdViews;

/**
 销毁广告视图
 */
- (void)destroyAdView;

@end

@protocol OctDrawVedioDelegate <NSObject>

// 加载成功
- (void)octad_drawVedioSuccessToLoad:(OctAdDrawVedio *)drawVedioAd;

// 加载失败
- (void)octad_drawVedioAd:(OctAdDrawVedio *)drawVedioAd didFailWithError:(NSError * _Nullable)error;

// 广告曝光
- (void)octad_drawVedioDidVisible:(OctAdDrawVedio *)drawVedioAd;

// 广告点击
- (void)octad_drawVedioAdViewDidClick:(OctAdDrawVedio *)drawVedioAd;

// 广告关闭
- (void)octad_drawVedioAdViewDidClose:(OctAdDrawVedio *)drawVedioAd;

// 广告落地页关闭
- (void)octad_drawVedioAdViewWillCloseOtherView:(OctAdDrawVedio *)drawVedioAd;

// 视频播放开始
- (void)octad_drawVedioAdViewVedioPlayStart:(OctAdDrawVedio *)drawVedioAd;

// 视频播放结束
- (void)octad_drawVedioAdViewVedioPlayEnd:(OctAdDrawVedio *)drawVedioAd;

@end

NS_ASSUME_NONNULL_END
