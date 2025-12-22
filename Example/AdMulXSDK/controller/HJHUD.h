//
//  HJHUD.h
//  AdMulXDemo
//
//  Created by 枫 on 2025/11/19.
//

#import <SVProgressHUD/SVProgressHUD.h>

NS_ASSUME_NONNULL_BEGIN

@interface HJHUD : SVProgressHUD

// Loading HUD
+ (void)showHUDLoading;

// show HUD
+ (void)showHUD;

// dismiss HUD
+ (void)dismissHUD;

// show Status
+ (void)showStatu:(NSString*)statu;

@end

NS_ASSUME_NONNULL_END
