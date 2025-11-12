//
//  HJAdConfig.h
//  HJAdSDK
//
//  Created by 枫 on 2025/9/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HJAdConfig : NSObject

@property (nonatomic, copy) NSString *appId;

// optional, enable personalized recommendation, default is YES

@property (nonatomic, assign) bool enablePersonalRecommend;

// optional, enable programmatic recommendation, default is YES
@property (nonatomic, assign) bool enableProgrammaticRecommend;

// optional, idfa
@property (nonatomic, copy) NSString *idfa;

// optional, longitude
@property (nonatomic, assign) double longitude;

// optional, latitude
@property (nonatomic, assign) double latitude;

// SDK version
+ (NSString *) getSDKVersion;

// SDK bundle name
+ (NSString *) getSDKBundleName;

@end

NS_ASSUME_NONNULL_END
