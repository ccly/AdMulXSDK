//
//  MSCustomBannerAdapterProtocol.h
//  MSAdSDK
//
//  Created by leej on 2022/5/17.
//  Copyright © 2022 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MSCustomAdapterProtocol.h"
#import "MSCustomBannerEventProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MSCustomBannerAdapterProtocol <MSCustomAdapterProtocol>

@required
/**
 *  加载广告
 *  详解：pid - 广告位 id
 */
- (UIView *)loadAndShow:(NSString *)pid
              presentVC:(UIViewController *)presentVC
                 adSize:(CGSize)adSize
            bannerEvent:(id<MSCustomBannerEventProtocol>)event;
/**
  渲染广告
 */
- (void)renderAd;

-(UIView *)adnBannerAdView;

-(void)dismissBanner;
/**
 广告是否有效
 如果三方提供查询广告是否有效接口则用三方的，否则按照三方广告过期时长进行处理
 */
- (BOOL)isAdValid;

@optional

- (void)updateCustomAdapterCurrentPresentVC:(UIViewController *)presentVC;

@end

NS_ASSUME_NONNULL_END
