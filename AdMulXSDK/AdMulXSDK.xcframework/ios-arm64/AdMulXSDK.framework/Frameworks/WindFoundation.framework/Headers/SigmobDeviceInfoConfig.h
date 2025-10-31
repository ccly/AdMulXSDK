//
//  SigmobDeviceInfoConfig.h
//  WindFoundation
//
//  Created by duyuwei on 2024/12/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol SigmobDeviceInfoConfigProtocol <NSObject>

- (BOOL)isCanUseAfterLoadAction;

@end

@interface SigmobDeviceInfoConfig : NSObject

@property (nonatomic, weak) id<SigmobDeviceInfoConfigProtocol> configDelegate;

@property (nonatomic, assign) BOOL isAdLoaded;

- (BOOL)isCanUseDeviceInfo;

@end

NS_ASSUME_NONNULL_END
