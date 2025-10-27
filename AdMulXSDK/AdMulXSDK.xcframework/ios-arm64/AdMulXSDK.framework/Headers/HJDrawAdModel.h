//
//  HJDrawAdModel.h
//  HJAdSDK
//
//  Created by 枫 on 2025/9/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HJDrawAdModel : NSObject

// draw对象
@property (nonatomic, strong) id  drawAdModel;

// draw视图
@property (nonatomic, strong) UIView *drawAdView;

// 获取ecpm, -1表示无权限或无竞价功能
@property (nonatomic, assign) double ecpm;

// show draw广告
- (void)registerContainer:(UIView *)view ;

// 对象id
@property (nonatomic, strong) NSString *modelId;

// 对象code
@property (nonatomic, strong) NSString *modelCode;

// 对象标识
@property (nonatomic, strong) NSString *modelType;

@end

NS_ASSUME_NONNULL_END
