//
//  HJAdManager.h
//  HJAdSDK
//
//  Created by 枫 on 2025/9/9.
//

#import <Foundation/Foundation.h>
#import <AdMulXSDK/HJAdConfig.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^HJCompletionHandler)(BOOL success, NSError * _Nullable error);

@interface HJAdManager : NSObject

// 初始化SDK
+ (void)startWithAsyncConfig:(HJAdConfig *)config completionHandler:(HJCompletionHandler)completionHandler;

@end

NS_ASSUME_NONNULL_END
