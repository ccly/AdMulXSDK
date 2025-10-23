//
//  HJExpressAdModel.h
//  HJAdSDK
//
//  Created by 枫 on 2025/9/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HJExpressAdModel : NSObject

// 信息流广告 view
@property (nonatomic, strong) UIView *expressAdView;

/**
 *  viewControllerForPresentingModalView
 *  详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

// 获取ecpm, -1表示无权限或无竞价功能
@property (nonatomic, assign) double ecpm;

// show Express广告
- (void)registerContainer:(UIView *)view;

// 对象id
@property (nonatomic, strong) NSString *modelId;

// 对象code
@property (nonatomic, strong) NSString *modelCode;

// 对象标识
@property (nonatomic, strong) NSString *modelType;

// 类型
@property (nonatomic, assign) NSInteger adType;

@end

NS_ASSUME_NONNULL_END
