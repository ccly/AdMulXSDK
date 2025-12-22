//
//  HJHUD.m
//  AdMulXDemo
//
//  Created by 枫 on 2025/11/19.
//

#import "HJHUD.h"

@implementation HJHUD

// show HUD Status
+ (void)showHUDLoading {
    
    [SVProgressHUD setDefaultMaskType:SVProgressHUDMaskTypeClear];
    [SVProgressHUD showWithStatus:nil];
    [SVProgressHUD dismissWithDelay:90.0f];
    
}


// show HUD
+ (void)showHUD {
    
    [SVProgressHUD setDefaultMaskType:SVProgressHUDMaskTypeGradient];
    [self showWithStatus:nil];
    
}

// dismiss HUD
+ (void)dismissHUD{
    
    [SVProgressHUD dismiss];
}

+ (void)showStatu:(NSString*)statu{
    
    [SVProgressHUD showImage:[UIImage imageNamed:@""] status:statu];
    [SVProgressHUD setBackgroundColor:[UIColor colorWithRed:187/255.0 green:187/255.0 blue:187/255.0 alpha:1]];
    [SVProgressHUD dismissWithDelay:2.0];
    
}


@end
