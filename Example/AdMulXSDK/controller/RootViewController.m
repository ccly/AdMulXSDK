//
//  RootViewController.m
//  AdMulXDemo
//
//  Created by 枫 on 2025/10/16.
//

#import "RootViewController.h"

#import "HJExpressAdViewController.h"
#import "HJBannerAdViewController.h"
#import "HJRewardAdViewController.h"
#import "HJDrawAdViewController.h"
#import "HJFullScreenAdViewController.h"
#import "HJHalfScreenAdViewController.h"
#import "HJVideoAdViewController.h"
#import <AdMulXSDK/AdMulXSDK.h>
#import "HJHUD.h"

@interface RootViewController ()<HJSplashAdDelegate>

@property (nonatomic, strong)  HJSplashAd *hjSplashAd;

@property (weak, nonatomic) IBOutlet UITableView *tableView;

@property (nonatomic, strong)  NSArray *listArr;

@end

@implementation RootViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.title = @"AdMulX";
    self.listArr = @[@{@"title":@"开屏广告", @"slotId":@"202509294325"},
                     @{@"title":@"banner广告", @"slotId":@"202509291711"},
                     @{@"title":@"激励广告", @"slotId":@"202509290391"},
                     @{@"title":@"draw广告", @"slotId":@"202509292916"},
                     @{@"title":@"信息流广告", @"slotId":@"202509291647"},
                     @{@"title":@"插全屏广告", @"slotId":@"202509295733"},
                     @{@"title":@"插半屏广告", @"slotId":@"202509296815"},
                     @{@"title":@"视频贴片广告", @"slotId":@"202510222829"},
    ];
}

/**
 * 开屏|已加载广告数据
 */
- (void)hjad_splashAdDidLoad:(HJSplashAd *)splashAd {
    
}
/**
 * 开屏|已加载完毕广告素材,准备展示，在此处展示广告
 */
- (void)hjad_splashAdContentDidLoad:(HJSplashAd *)splashAd {
    [HJHUD dismissHUD];
    [splashAd showSplashViewInRootViewController:self];
    
}
/**
 * 开屏|广告已经可见
 */
- (void)hjad_splashAdDidVisible:(HJSplashAd *)splashAd {
    
}
/**
 * 开屏|视频广告开始播放（仅适用于视频广告）
 */
- (void)hjad_splashAdVideoDidBeginPlay:(HJSplashAd *)splashAd {
    
}
/**
 * 开屏|广告数据加载失败
 */
- (void)hjad_splashAd:(HJSplashAd *)splashAd didFailWithError:(nonnull NSError *)error {
    [HJHUD dismissHUD];
}
/**
 * 开屏|点击跳过按钮调用此方法
 */
- (void)hjad_splashAd:(HJSplashAd *)splashAd didSkip:(NSTimeInterval)playDuration {
    
}
/**
 * 开屏|广告被点击
 */
- (void)hjad_splashAdDidClick:(HJSplashAd *)splashAd {
    
}
/**
 * 开屏|广告关闭
 */
- (void)hjad_splashAdDidAutoDismiss:(HJSplashAd *)splashAd {
    
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.listArr.count;
}

#pragma mark - UITableViewDataSource
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass(UITableViewCell.class)];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:NSStringFromClass(UITableViewCell.class)];
    }
    
    NSDictionary *dic = [self.listArr objectAtIndex:indexPath.row];
    
    UIImageView *arrowImage = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, 8, 16)];
    arrowImage.image = [UIImage imageNamed:@"icon_list_arrow"];
    cell.textLabel.font = [UIFont systemFontOfSize:16];
    cell.accessoryView = arrowImage;
    cell.textLabel.text = [dic objectForKey:@"title"];
    UIView *bgColorView = [[UIView alloc] init];
    bgColorView.backgroundColor = [UIColor colorWithRed:0/255.0 green:0/255.0 blue:0/255.0 alpha:0.05];
    [cell setSelectedBackgroundView:bgColorView];
    CGRect frame = CGRectMake(cell.imageView.frame.origin.x, cell.imageView.frame.origin.y, 20, 20);
    cell.imageView.frame = frame;
    cell.imageView.image = [UIImage imageNamed:@"icon_ad"];
    
    if(indexPath.row == [self.tableView numberOfRowsInSection:indexPath.section] -1) {
        cell.separatorInset = UIEdgeInsetsMake(0, 0, 0, self.view.bounds.size.width);
    } else {
        cell.separatorInset =  UIEdgeInsetsMake(0, 0, 0, 0) ;
    }
    return cell;
}

#pragma mark - UITableViewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    NSDictionary *dic = [self.listArr objectAtIndex:indexPath.row];

    NSString *value = [dic objectForKey:@"title"];
    
    NSString *slotId = [dic objectForKey:@"slotId"];
        
    if([value isEqualToString:@"开屏广告"]) {
        [HJHUD showHUDLoading];
        self.hjSplashAd = [[HJSplashAd alloc] initWithSlotId:slotId];
        self.hjSplashAd.delegate = self;
        [self.hjSplashAd loadAdData];
    }else if([value isEqualToString:@"banner广告"]) {
        HJBannerAdViewController *adVC = [[HJBannerAdViewController alloc] init];
        adVC.slotId = slotId;
        [self.navigationController pushViewController:adVC animated:YES];
    }else if([value isEqualToString:@"激励广告"]) {
        HJRewardAdViewController *adVC = [[HJRewardAdViewController alloc] init];
        adVC.slotId = slotId;
        [self.navigationController pushViewController:adVC animated:YES];
    }else if([value isEqualToString:@"draw广告"]) {
        HJDrawAdViewController *adVC = [[HJDrawAdViewController alloc] init];
        adVC.slotId = slotId;
        [self.navigationController pushViewController:adVC animated:YES];
    }else if([value isEqualToString:@"信息流广告"]) {
        HJExpressAdViewController *adVC = [[HJExpressAdViewController alloc] init];
        adVC.slotId = slotId;
        [self.navigationController pushViewController:adVC animated:YES];
    }else if([value isEqualToString:@"插全屏广告"]) {
        HJFullScreenAdViewController *adVC = [[HJFullScreenAdViewController alloc] init];
        adVC.slotId = slotId;
        [self.navigationController pushViewController:adVC animated:YES];
    }else if([value isEqualToString:@"插半屏广告"]) {
        HJHalfScreenAdViewController *adVC = [[HJHalfScreenAdViewController alloc] init];
        adVC.slotId = slotId;
        [self.navigationController pushViewController:adVC animated:YES];
    }else if([value isEqualToString:@"视频贴片广告"]) {
        HJVideoAdViewController *adVC = [[HJVideoAdViewController alloc] init];
        adVC.slotId = slotId;
        [self.navigationController pushViewController:adVC animated:YES];
    }
   
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 60;
}

@end
