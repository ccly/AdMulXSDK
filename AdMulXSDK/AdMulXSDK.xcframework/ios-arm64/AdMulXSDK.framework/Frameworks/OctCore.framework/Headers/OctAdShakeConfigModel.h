//
//  OctAdShakeConfigModel.h
//  OctCore
//
//  Created by hongji cai on 2025/9/11.
//

#import <Foundation/Foundation.h>
#import "OctBaseModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface OctAdShakeConfigModel : OctBaseModel
//取值 <=3s, 默认3s
@property (nonatomic, assign) NSInteger time;
//取值 <180， 默认35
@property (nonatomic, assign) double angle;
//取值 <50， 默认15
@property (nonatomic, assign) double acceleration;
@end

NS_ASSUME_NONNULL_END
