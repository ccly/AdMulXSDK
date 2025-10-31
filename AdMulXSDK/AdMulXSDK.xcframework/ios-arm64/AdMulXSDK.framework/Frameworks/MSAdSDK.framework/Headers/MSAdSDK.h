//
//  MSAdSDK.h
//  MSAdSDK
//
//  Created by yang on 2019/8/5.
//  Copyright © 2019年 yang. All rights reserved.
//

#import <MSAdSDK/MSPublicHeader.h>

@interface MSAdSDK : NSObject
/**
 设置支持的通信协议
 */
@property(nonatomic,assign,class)MSSecure secure;
/**
 日志打印，调试广告时，打开日志，可查看具体详细log，上线前务必关闭log
 */
@property(nonatomic,assign,class)MSLogLevel logLevel;
/**
 获取广告SDK字符串类型版本号
 */
@property(nonatomic,copy,class,readonly,getter=getVersionName)NSString *versionName;
/**
 获取广告SDK int类型版本号
 */
@property(nonatomic,assign,class,readonly,getter=getVersionCode)NSInteger versionCode;
/**
 SDK初始化接口
 注意事项：
 1、务必传入appId
 2、初始化1次即可，不要多次调用该接口
 3、configBlock中仅设置SDK全局配置，不要在此block中加载广告
 */
+ (BOOL)startSDKWithAppid:(NSString *)appId configBlock:(void(^)(void))configBlock;
//获取平台版本号
+ (NSString*)platformVersion:(MSPlatform)platform;
//检测SDK聚合信息
+ (NSDictionary *)checkSdkIntegration;
@end
