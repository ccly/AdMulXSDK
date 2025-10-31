//
//  BUNativeExpressRewardedVideoAd.h
//  BUAdSDK
//
//  Copyright © 2019 bytedance. All rights reserved.
//

#import "BUInterfaceBaseObject.h"
#import "BUAdSDKDefines.h"
#import "BUMaterialMeta.h"
#import "BUMopubAdMarkUpDelegate.h"
#import "BUAdClientBiddingProtocol.h"
#import "BUDictionary.h"
#import "BUCustomEventProtocol.h"
@class BUNativeExpressRewardedVideoAd;
@class BURewardedVideoModel;

NS_ASSUME_NONNULL_BEGIN

/// define the type of  native express rewarded video Ad
typedef NS_ENUM(NSUInteger, BUNativeExpressRewardedVideoAdType) {
    BUNativeExpressRewardedVideoAdTypeEndcard         = 0,  // video + endcard
    BUNativeExpressRewardedVideoAdTypePurePlayable    = 2,  // pure playable
};


@protocol BUNativeExpressRewardedVideoAdDelegate <NSObject,BUCustomEventProtocol>

@optional
/**
 This method is called when video ad material loaded successfully.
 */
- (void)nativeExpressRewardedVideoAdDidLoad:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when video ad materia failed to load.
 @param error : the reason of error
 */
- (void)nativeExpressRewardedVideoAd:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *_Nullable)error;
/**
  this methods is to tell delegate the type of native express rewarded video Ad
 */
// Mediation:/// @Note :  当加载聚合维度广告时，不支持该回调。
- (void)nativeExpressRewardedVideoAdCallback:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd withType:(BUNativeExpressRewardedVideoAdType)nativeExpressVideoType;

/**
 This method is called when cached successfully.
 For a better user experience, it is recommended to display video ads at this time.
 And you can call [BUNativeExpressRewardedVideoAd showAdFromRootViewController:]. 
 */
- (void)nativeExpressRewardedVideoAdDidDownLoadVideo:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when rendering a nativeExpressAdView successed.
 It will happen when ad is show.
 */
// Mediation:/// @Note :  (针对聚合维度广告)<6300版本不会回调该方法，>=6300开始会回调该方法，但不代表最终展示广告的渲染结果。
- (void)nativeExpressRewardedVideoAdViewRenderSuccess:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when a nativeExpressAdView failed to render.
 @param error : the reason of error
 */
// Mediation:/// @Note :  (针对聚合维度广告)<6300版本不会回调该方法，>=6300开始会回调该方法，但不代表最终展示广告的渲染结果。
- (void)nativeExpressRewardedVideoAdViewRenderFail:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd error:(NSError *_Nullable)error;

/**
 This method is called when video ad slot will be showing.
 */
// Mediation:/// @Note :  当加载聚合维度广告时，支持该回调的adn有：CSJ
- (void)nativeExpressRewardedVideoAdWillVisible:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when video ad slot has been shown.
 */
- (void)nativeExpressRewardedVideoAdDidVisible:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when video ad is about to close.
 */
// Mediation:/// @Note :  当加载聚合维度广告时，支持该回调的adn有：CSJ
- (void)nativeExpressRewardedVideoAdWillClose:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when video ad is closed.
 */
- (void)nativeExpressRewardedVideoAdDidClose:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when video ad is clicked.
 */
- (void)nativeExpressRewardedVideoAdDidClick:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when the user clicked skip button.
 */
- (void)nativeExpressRewardedVideoAdDidClickSkip:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when video ad play completed or an error occurred.
 @param error : the reason of error
 */
- (void)nativeExpressRewardedVideoAdDidPlayFinish:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *_Nullable)error;

/**
 Server verification which is requested asynchronously is succeeded. now include two v erify methods:
      1. C2C need  server verify  2. S2S don't need server verify
 @param verify :return YES when return value is 2000.
 */
- (void)nativeExpressRewardedVideoAdServerRewardDidSucceed:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd verify:(BOOL)verify;

/**
  Server verification which is requested asynchronously is failed.
  @param rewardedVideoAd express rewardVideo Ad
  @param error request error info
 */
- (void)nativeExpressRewardedVideoAdServerRewardDidFail:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd error:(NSError *_Nullable)error;

/**
 This method is called when another controller has been closed.
 @param interactionType : open appstore in app or open the webpage or view video ad details page.
 */
- (void)nativeExpressRewardedVideoAdDidCloseOtherController:(BUNativeExpressRewardedVideoAd *)rewardedVideoAd interactionType:(BUInteractionType)interactionType;

@end

/// Please note: This Class does not take effect on Pangle global, only use it when you have traffic from mainland China.
 __attribute__((objc_subclassing_restricted))
@interface BUNativeExpressRewardedVideoAd : BUInterfaceBaseObject <BUMopubAdMarkUpDelegate, BUAdClientBiddingProtocol>
@property (nonatomic, strong) BURewardedVideoModel *rewardedVideoModel;
@property (nonatomic, weak, nullable) id<BUNativeExpressRewardedVideoAdDelegate> delegate;

/// media configuration parameters.
@property (nonatomic, copy, readonly, nullable) BUDictionary *mediaExt;

/**
 Is  materialMeta from the preload, default is NO
*/
@property (nonatomic, assign, readonly) BOOL materialMetaIsFromPreload __deprecated;

/**
 The expiration timestamp of materialMeta
 */
@property (nonatomic, assign, readonly) NSTimeInterval expireTimestamp;

- (instancetype)initWithSlotID:(NSString *)slotID rewardedVideoModel:(BURewardedVideoModel *)model;

/**
 Initializes Rewarded video ad with ad slot and frame.
 @param slot A object, through which you can pass in the reward unique identifier, ad type, and so on.
 @param model Rewarded video model.
 @return BUNativeExpressRewardedVideoAd
*/
- (instancetype)initWithSlot:(BUAdSlot *)slot rewardedVideoModel:(BURewardedVideoModel *)model;

/**
 Ad slot material id
 */
- (NSString *)getAdCreativeToken;

- (void)loadAdData;

/**
 Display video ad.
 @param rootViewController : root view controller for displaying ad.
 @return : whether it is successfully displayed.
 */
- (BOOL)showAdFromRootViewController:(UIViewController *)rootViewController;

/**
 If ritSceneType is custom, you need to pass in the values for sceneDescirbe.
 @param ritSceneType  : optional. Identifies a custom description of the presentation scenario.
 @param sceneDescirbe : optional. Identify the scene of presentation.
 */
- (BOOL)showAdFromRootViewController:(UIViewController *)rootViewController ritScene:(BURitSceneType)ritSceneType ritSceneDescribe:(NSString *_Nullable)sceneDescirbe;

/**
 Get the expiration timestamp of materialMeta 
 @warning: The value of this field is only accurate after the video is downloaded successfully or after the access is successfully obtained
 @Note :  This API is only useful in China area.
 */
- (NSTimeInterval)getExpireTimestamp;

@end

NS_ASSUME_NONNULL_END
