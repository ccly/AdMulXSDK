//
//  BUMMediatedNativeAdViewCreator.h
//  BUAdSDK
//
//  Created by 🦁 on 2022/12/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// 媒体Native非模板广告视图构造协议
/// 📣 adapter开发者可不配置数据内容，外部开发者在接入时需手动填充BUMMediatedNativeAdData中数据
@protocol BUMMediatedNativeAdViewCreator <NSObject>

/// 是否支持自定义事件按钮，如果为YES，开发者可以配置 callToActionBtn 的数据，默认为YES
@property (nonatomic, assign, readonly) BOOL hasSupportActionBtn;

/// 广告标题视图
@property (nonatomic, strong, nullable, readonly) UILabel *titleLabel;

/// 广告描述信息视图
@property (nonatomic, strong, nullable, readonly) UILabel *descLabel;

/// 广告图标视图
@property (nonatomic, strong, nullable, readonly) UIImageView *iconImageView;

/// 广告图片视图
@property (nonatomic, strong, nullable, readonly) UIImageView *imageView;

/// 广告事件按钮
@property (nonatomic, strong, nullable, readonly) UIButton *callToActionBtn;

/// 广告商视图
@property (nonatomic, strong, nullable, readonly) UIView *advertiserView;

/// 不喜欢广告按钮
@property (nonatomic, strong, nullable, readonly) UIButton *dislikeBtn;

/// 视频视图
@property (nonatomic, strong, nullable, readonly) UIView *mediaView;

/// 商城页视图（当前仅适用csj）
@property (nonatomic, strong, nullable, readonly) UIView *ecMallView;

/// 广告图标视图
@property (nonatomic, strong, nullable, readonly) UIView *adLogoView;

@end
