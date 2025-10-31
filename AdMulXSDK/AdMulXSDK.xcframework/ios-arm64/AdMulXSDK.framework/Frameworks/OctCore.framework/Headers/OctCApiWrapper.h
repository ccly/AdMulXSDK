//
//  OctCApiWrapper.h
//  OctAdSDK
//
//  Created by hongji cai on 2024/2/6.
//

#import <Foundation/Foundation.h>

#import <sys/stat.h>
#import <sys/sysctl.h>
#import <sys/mount.h>

NS_ASSUME_NONNULL_BEGIN

typedef int (*OctSysctlCallBack)(int *, u_int, void *, size_t *, void *, size_t);
typedef int (*OctSysctlbynameCallBack)(const char *, void *, size_t *, void *, size_t);
typedef size_t (*OctStrlenCallBack)(const char *__s);
typedef char* (*OctStrstrCallBack)(const char *__big, const char *__little);

@interface OctCApiWrapper : NSObject
+ (OctCApiWrapper *)shared;

@property (nonatomic) OctSysctlCallBack sysctlCallBack;
@property (nonatomic) OctSysctlbynameCallBack sysctlbynameCallBack;
@property (nonatomic) OctStrlenCallBack strlenCallBack;
@property (nonatomic) OctStrstrCallBack strstrCallBack;

- (NSString*)octSysctl:(int*)mib mibLen:(int)mibLen;
- (u_long)octStrlen:(char*)s;
- (char*)octStrstr:(char*)big little: (char*)little;
- (u_long)octSysctlbyname:(char*)modelKey model:(void*)model;

@end

NS_ASSUME_NONNULL_END
