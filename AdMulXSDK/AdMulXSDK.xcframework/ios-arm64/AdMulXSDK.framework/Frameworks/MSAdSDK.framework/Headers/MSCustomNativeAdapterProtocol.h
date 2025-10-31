//
//  MSCustomNativeAdapterProtocol.h
//  MSAdSDK
//
//  Created by leej on 2022/5/20.
//  Copyright © 2022 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MSCustomAdapterProtocol.h"
#import "MSCustomNativeEventProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MSCustomNativeAdapterProtocol <MSCustomAdapterProtocol>

@required
/**
 *  加载广告
 *  详解：pid - 广告位 id
 */
- (void)loadAdPid:(NSString *)pid
          adCount:(NSInteger)adCount
        presentVC:(UIViewController *)presentVC
            event:(id<MSCustomNativeEventProtocol>)event;
/**
  渲染广告
 */
- (void)renderAd;

@optional
/**
 检测广告是否有效
 注意：
 当信息流是自渲染类型 调用方法 【self  checkAdIsValid:data adView:nil】
 当信息流是模版类型 调用方法 【self  checkAdIsValid:nil adView:adView】
 */
- (BOOL)checkAdIsValid:(id<MSFeedAdMeta> _Nullable)adData adView:(UIView *_Nullable)adView;
//更新vc
- (void)updateCustomAdapterCurrentPresentVC:(UIViewController *)presentVC;
@end

NS_ASSUME_NONNULL_END
