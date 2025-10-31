//
//  MSCustomAdapterProtocol.h
//  MSAdSDK
//
//  Created by leej on 2022/5/16.
//  Copyright © 2022 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MSCustomAdapterProtocol <NSObject>

@optional
/**
 注册获取初始化sdk相关参数
 */
- (void)registSdkWithInfo:(NSDictionary *)info MeiShuAdDEPRECATED_MSG("该回调已废弃，请在平台端配置初始化类名");
/**
 获取渠道SDK版本
 */
- (NSString *)networkSdkVersion;
/**
 获取ecpm
 注意：如获取不到，请传0
 */
- (NSInteger)adapterEcpm;
/**
 获取美数平台上配置的个性化参数
 */
- (void)configMediaParamsOnPlatform:(NSDictionary *)mediaParams;
//发送竞胜结果
- (void)sendWinNotification:(NSInteger)price MeiShuAdDEPRECATED_MSG("该回调已废弃，请使用sendWinNotification：otherHighestPrice替代");
//发送竞胜结果及竞价失败的媒体最高价
- (void)sendWinNotification:(NSInteger)price otherHighestPrice:(NSInteger)highestPrice;
/**
 发送竞败结果
 @param price 当前竞价胜出的价格
 @param reason 竞价失败原因
 @param adnId 当前竞价胜出平台渠道ID
 */
- (void)sendLossNotification:(NSInteger)price reason:(MSAdBiddingErrorType)reason adnId:(NSString *)adnId;
@end

NS_ASSUME_NONNULL_END
