//
//  HJAdBidResult.h
//  HJAdSDK
//
//  Created by 枫 on 2025/12/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, HJAdNType) {
    HJAdNGDTType    =   1,  // 优量汇
    HJAdNCSJType    =   2,  // 穿山甲
    HJAdNKSType     =   3,  // 快手
    HJAdNBDType     =   4,  // 百度
    HJAdNWINDType   =   5,  // sigmob
    HJAdNOtherType  =   99, // 其他
};

@interface HJAdBidResult : NSObject

// 本轮竞价输赢
@property (nonatomic, assign) BOOL win;

// 本轮参与竞价的最高出价(单位分)
@property (nonatomic, assign) NSInteger price;

// 本轮参与竞价的竞胜方
@property (nonatomic, assign) HJAdNType adnType;

@end

NS_ASSUME_NONNULL_END
