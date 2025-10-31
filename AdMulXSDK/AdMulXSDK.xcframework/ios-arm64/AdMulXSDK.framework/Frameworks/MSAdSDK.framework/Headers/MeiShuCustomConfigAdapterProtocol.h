//
//  MeiShuCustomConfigAdapterProtocol.h
//  MSAdSDK
//
//  Created by mstech_ios on 2025/6/9.
//  Copyright © 2025 Adxdata. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MeiShuCPSDKConfigModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MeiShuCustomConfigAdapterProtocol <NSObject>
@required
/// adn初始化方法
/// @param initConfig 初始化配置，包括appid、appkey基本信息和部分用户传递配置
- (void)initializeAdapterWithConfiguration:(MeiShuCPSDKConfigModel *_Nullable)initConfig;
/// adn的版本号
- (NSString *_Nonnull)networkSdkVersion;
@optional
/// adapter的版本号
- (NSString *_Nonnull)adapterVersion;
@end

NS_ASSUME_NONNULL_END
