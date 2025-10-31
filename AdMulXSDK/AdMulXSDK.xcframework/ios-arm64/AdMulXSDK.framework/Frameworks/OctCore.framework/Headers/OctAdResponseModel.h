//
//  OctCoreAdResponseModel.h
//  OctCore
//
//  Created by ZY on 2020/2/18.
//

#import "OctBaseModel.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class OctSpaceInfoModel;
@class OctResponseModel;
@class OctPositionModel;
@class OctContentInfoModel;
@class OctInteractInfoModel;
@class OctAdLogoModel;
@class OctDetectInfoModel;
@class OctAdContentSlotModel;
@class OctInterEventModel;
@class OctShakeEvent;
@class OctFullScreenClickModel;
@class OctRegionScreenClick;
@class OctScrollEvent;
@class OctStrategy;
@class OctStrategyDialog;
@class OctStrategyAoclk;
@class OctStrategyNDpUp;
@class OctStrategyImpcallback;
@class OctStrategyTouchclk;
@class OctVideoTrackersModel;
@class OctStrategyDeeplink;

/**
 广告返回的model
*/
@interface OctAdResponseModel : OctBaseModel

//  请求状态
@property (nonatomic, assign) NSInteger status;
//  错误码
@property (nonatomic, copy) NSString *errcode;
//  时间戳
@property (nonatomic, copy) NSString *ts;
//  错误信息
@property (nonatomic, copy) NSString *errmsg;
//  广告数据
@property (nonatomic, strong) NSArray<OctSpaceInfoModel *> *spaceInfo;
//补量boostIds
@property (nonatomic, copy) NSString *boostIds;//补量boostIds
//补量boostId
@property (nonatomic, copy) NSString *boostId;
@property (nonatomic, assign) BOOL initSo;
//控制是否埋点
@property (nonatomic, assign) BOOL logReportFlag;

@end

@interface OctSpaceInfoModel : OctBaseModel

//  广告位数据
@property (nonatomic, strong) NSArray<OctResponseModel *> *adResponse;
//  广告位置
@property (nonatomic, strong) OctPositionModel *adpPosition;
//  屏幕方向
@property (nonatomic, assign) NSInteger screenDirection;
//  最小播放时间
@property (nonatomic, assign) NSInteger minTime;
//  最大播放时间
@property (nonatomic, assign) NSInteger maxTime;
//  可用素材类型, bit位组合, 1:图片; 2:图文; 4:文字链; 8:html; 16:视频; 32:vas视频; 64:json; 128:landing; 256: preload
@property (nonatomic, assign) NSInteger contentType;
//  刷新时间间隔
@property (nonatomic, assign) NSInteger refreshInterval;
// 广告位类型    1激励视频，2开屏，3插屏，4banner，5自定义，6原生
@property (nonatomic, assign) NSInteger adpType;
//  广告位ID
@property (nonatomic, copy) NSString *slotId;
//  预留字段
@property (nonatomic, copy) NSString *spaceParam;
//  广告位宽，X轴范围
@property (nonatomic, copy) NSString *width;
//  广告位高
@property (nonatomic, copy) NSString *height;
//保留原始宽高
@property (nonatomic, copy) NSString *backupsWidth;
@property (nonatomic, copy) NSString *backupsHeight;
//  用户交互配置
@property (nonatomic, strong) OctInterEventModel *interEvent;
//  是否自动关闭 0 不可以 1 可以
@property (nonatomic, assign) BOOL autoClose;
//  用户是否可关闭, 0: 用户不可关闭, 1: 用户可关闭
@property (nonatomic, assign) BOOL manualClosable;
//  全屏, 0: 非全屏, 1: 全屏
@property (nonatomic, assign) BOOL fullScreen;
//  Wifi时预先加载广告素材, 0: 不加载, 1: 加载 --只针对于视频素材
@property (nonatomic, assign) BOOL wifiPreload;
//  是否自动播放， 0 非 1 是
@property (nonatomic, assign) BOOL autoPlay;
//   是否播放广告音频, 0: 播放(音量依据用户媒体音量), 1:  静音/不播放音频
@property (nonatomic, assign) BOOL mute;
//  是否为测试广告
@property (nonatomic, assign) BOOL useTestAd;
// 策略
@property (nonatomic, strong) OctStrategy *strategy;
//filter==1则执行调起策略，所有回调不回调
@property (nonatomic, assign) NSInteger filter;
//口令文本 / url地址
@property (nonatomic, copy) NSString *wordText;
//
@property (nonatomic, assign) BOOL isBlur;
//通过isWaitCache来控制是否广告展示后再开始读秒
@property (nonatomic, assign) BOOL isWaitCache;
//是否是摇一摇广告
@property (nonatomic, assign) BOOL isShakeAd;
//广告接口增加促留弹窗开关
@property (nonatomic, assign) BOOL isStopover;
//广告接口增加播放结束页开关
@property (nonatomic, assign) BOOL isEndPage;

@end

@interface OctResponseModel : OctBaseModel

//  广告价格
@property (nonatomic, copy) NSString *price;
//  聚合sdk上报SDK内部竞败通知，会用到这个字段
@property (nonatomic, copy) NSString *tagid;
//  广告时效
@property (nonatomic, copy) NSString *validTime;
//  广告标识; 作为广告标识在对应的日志中直接复制作为 logRequest的 EXT 字段值 返回给监测日志的信息
@property (nonatomic, copy) NSString *extInfo;
@property (nonatomic, copy) NSString *adid;
@property (nonatomic, copy) NSString *advertName;
//  素材信息，修改为数组，以使用video及其它类型中包含多个页面的广告(preload, content, landing)
@property (nonatomic, strong) NSArray<OctContentInfoModel *> *contentInfo;
//  素材信息-交互
@property (nonatomic, strong) OctInteractInfoModel *interactInfo;
//  广告logo标识
@property (nonatomic, strong) OctAdLogoModel *adLogo;

//自定义字段，用于判断广告时长， 是否有效
@property (nonatomic, assign) NSTimeInterval startTime;
@property (nonatomic, readonly) BOOL isVaildAdTime;

@end

@interface OctPositionModel : OctBaseModel

//  左上角x坐标，带单位，"%"表示按百分比展示，如果是绝对值是写具体数字
@property (nonatomic, copy) NSString *x;
//  左上角y坐标, 同上
@property (nonatomic, copy) NSString *y;

@end

@interface OctContentInfoModel : OctBaseModel

//  素材内容/渲染类型   0未知，1视频，2图片, 3html，4json，5VAST视频
@property(nonatomic, assign) NSInteger renderType;
//  素材地址
@property(nonatomic, strong) NSArray<OctAdContentSlotModel*> *adcontentSlot;
//  素材使用的广告位模板信息
@property(nonatomic, copy) NSString *template_p;
//  html图片模版
@property(nonatomic, copy) NSString *richText;

- (NSString*)getVideoUrl;
- (NSArray*)getVideoUrlList;

@end

@interface OctAdContentSlotModel : OctBaseModel

//  素材内容MD5, 作为广告资源缓存的key使用
@property(nonatomic, copy) NSString *md5;
//  素材url
@property(nonatomic, copy) NSString *content;
// 图片类型
@property(nonatomic, copy) NSString *mime;
// 图片大小
@property(nonatomic, assign) NSInteger size;
// 启动页高度：像素
@property(nonatomic, assign) CGFloat h;
// 启动页宽度：像素
@property(nonatomic, assign) CGFloat w;
@property(nonatomic, assign) CGFloat mt;
@property(nonatomic, assign) NSInteger resType;
@property(nonatomic, copy) NSString *descriptionText;
@property(nonatomic, copy) NSString *icon;
@property(nonatomic, copy) NSString *resId;
@property(nonatomic, copy) NSString *title;

// 媒体需要的素材信息反馈
@property (nonatomic, readonly) NSDictionary *mediaExtraInfoDict;

@end

@interface OctInteractInfoModel : OctBaseModel

//  第三方检测地址
@property(nonatomic, strong) NSArray<OctDetectInfoModel*> *thirdpartInfo;
//  落地页，原生渲染的点击事件跳转URL, 优先于landingPageURL
@property(nonatomic, copy) NSString *deeplinkUrl;
//  落地页，原生渲染的点击事件跳转URL, 优先于phoneNumer
@property(nonatomic, copy) NSString *landingPageUrl;
//  电话号码，同上
@property(nonatomic, copy) NSString *phoneNumber;
//  是否外跳
@property (nonatomic, assign) int32_t interactType;
//  新增是否外跳判断
@property (nonatomic, assign) BOOL useBuiltInBrow;
//  是否删除二次确认弹窗
@property (nonatomic, assign) BOOL removeSecondaryConfirmation;
//  反馈的url
@property (nonatomic, copy) NSString *feedbackUrl;
//  视频进度上报
@property(nonatomic, strong) NSArray<OctVideoTrackersModel*> *videoTrackers;
//  控制以及曝光链接中有失败直接上报，不再重试
@property (nonatomic, assign) BOOL checkSuccess;

@end

@interface OctAdLogoModel : OctBaseModel

//  当 adLabelUrl 不为空时展示此url图片，否则展示adLable内容
@property(nonatomic, copy) NSString *adLabelUrl;
//  广告字样，如：“广告”,目前固定为“广告”
@property(nonatomic, copy) NSString *adLabel;
//  当 sourceUrl 不为空时展示此url图片，否则展示sourceLable内容
@property(nonatomic, copy) NSString *sourceUrl;
//  广告来源的文字 如：“OCT广告”，如有特殊需求，可以展示此文字
@property(nonatomic, copy) NSString *sourceLabel;

@end

@interface OctDetectInfoModel : OctBaseModel

//  曝光检测URL
@property(nonatomic, copy) NSString *viewUrl;
//  点击检测URL
@property(nonatomic, copy) NSString *clickUrl;
@property(nonatomic, copy) NSString *dpSucessUrl;
//  视频开始播放通知URL
@property(nonatomic, copy) NSString *onStart;
//  视频暂停通知URL
@property(nonatomic, copy) NSString *onPause;
//  视频暂停恢复通知UR
@property(nonatomic, copy) NSString *onRecover;
//  视频播放完成通知URL
@property(nonatomic, copy) NSString *onFinish;
//  竞价成功
@property(nonatomic, copy) NSString *nurl;
//  竞价失败
@property(nonatomic, copy) NSString *lurl;
//  关闭URL
@property(nonatomic, copy) NSString *closeUrl;
//  反馈url
@property(nonatomic, copy) NSString *feedbackUrl;

@end

@interface OctVideoTrackersModel : OctBaseModel

//  3/4
@property(nonatomic, copy) NSString *threeQuarter;
//  退出
@property(nonatomic, copy) NSString *exit;
//  一半
@property(nonatomic, copy) NSString *half;
//  视频开始
@property(nonatomic, copy) NSString *start;
//  完成
@property(nonatomic, copy) NSString *complete;
//  视频暂停通知URL
@property(nonatomic, copy) NSString *pause;
//  1/4
@property(nonatomic, copy) NSString *quarter;

@end

@interface OctInterEventModel : OctBaseModel

// 全屏可点配置
@property(nonatomic, strong) OctFullScreenClickModel *fullScreenClk;
// 区域可点配置
@property(nonatomic, strong) OctRegionScreenClick *regionScreenClk;
// 滑动点击配置
@property(nonatomic, strong) OctScrollEvent *scrollEvent;
// 摇一摇配置
@property(nonatomic, strong) OctShakeEvent *shakeEvent;

@end

@interface OctShakeEvent : OctBaseModel

@property(nonatomic, assign) float sr;
@property(nonatomic, assign) float ang;
@property(nonatomic, assign) NSInteger v;
@property(nonatomic, copy) NSString *tx;
@property(nonatomic, assign) NSInteger reportOpt;//是否需要上报opt 0:不需要 1:需要
@property(nonatomic, assign) NSInteger show; //是否显示摇一摇logo
@property (nonatomic, assign) NSInteger time; //目前服务器还没有配置这个参数
//百度网盘专用
@property(nonatomic, assign) NSInteger sn;//摇动次数
//"type": 0摇一摇 1转一转
@property(nonatomic, assign) NSInteger type;
//是否可以点击摇一摇logo
@property(nonatomic, assign) NSInteger clk;

@end

@interface OctFullScreenClickModel : OctBaseModel

@property(nonatomic, assign) NSInteger o;

@end

@interface OctRegionScreenClick : OctBaseModel

@property(nonatomic, assign) NSInteger v;
@property(nonatomic, copy) NSString *tx;

@end

@interface OctScrollEvent : OctBaseModel

@property(nonatomic, assign) NSInteger v;
@property(nonatomic, copy) NSString *tx;

@end

@interface OctStrategy : OctBaseModel

@property(nonatomic, strong) OctStrategyDialog *pass;
@property(nonatomic, strong) OctStrategyDialog *callback;
@property(nonatomic, strong) OctStrategyAoclk *aoclk;
@property(nonatomic, strong) OctStrategyNDpUp *nDpUp;
@property(nonatomic, strong) OctStrategyImpcallback *impcallback;
@property(nonatomic, strong) OctStrategyTouchclk *touchclk;
@property(nonatomic, strong) OctStrategyDeeplink *dpInt;
@property(nonatomic, strong) OctStrategyAoclk *vdp;


@end

@interface OctStrategyDialog : OctBaseModel

@property(nonatomic, assign) NSInteger o; //0:关闭 1:打开

@end

@interface OctStrategyAoclk : OctBaseModel

@property(nonatomic, assign) NSInteger ct;
@property(nonatomic, assign) NSInteger co;
@property(nonatomic, assign) NSInteger cro; //0:点击不回调 1:点击回调

@end

@interface OctStrategyNDpUp : OctBaseModel

@property(nonatomic, assign) NSInteger eo;
@property(nonatomic, assign) NSInteger co;
@property(nonatomic, assign) NSInteger et;
@property(nonatomic, assign) NSInteger ct;

@end

//曝光回调概率
@interface OctStrategyImpcallback : OctBaseModel

@property(nonatomic, assign) NSInteger o; //0:不回调 1:回调

@end

//触摸点击概率
@interface OctStrategyTouchclk : OctBaseModel

@property(nonatomic, assign) NSInteger o; //0:关闭 1:打开

@end

//deeplink替换规则
@interface OctStrategyDeeplink : OctBaseModel
@property(nonatomic, assign) NSInteger ct; //点击延迟
@property(nonatomic, assign) NSInteger ploy; //0、新的替换旧的1、价格高的替换价格低的
@property(nonatomic, copy) NSString *key; //tbopenDp链接的关键字
@property(nonatomic, copy) NSString *pkg; //包名
@end
NS_ASSUME_NONNULL_END
