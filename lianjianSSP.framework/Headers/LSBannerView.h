//
//  LSBannerView.h
//  lianjianSSP
//
//  Created by Liantronics on 2017/9/5.
//  Copyright © 2017年 SHENZHEN LIANTRONICS CO.,LTD. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LSCommonDef.h"

typedef NS_ENUM(NSInteger, LSBannerPosition) {
    LSBannerPositionTop = 1,
    LSBannerPositionBottom
};

/// iPhone and iPod Touch ad size. Typically 320x50.
FOUNDATION_EXTERN CGSize const kLSSizeBanner;

/// Taller version of kCGSizeBanner. Typically 320x100.
FOUNDATION_EXTERN CGSize const kLSSizeLargeBanner;

/// Medium Rectangle size for the iPad (especially in a UISplitView's left pane). Typically 300x250.
FOUNDATION_EXTERN CGSize const kLSSizeMediumRectangle;

/// Full Banner size for the iPad (especially in a UIPopoverController or in
/// UIModalPresentationFormSheet). Typically 468x60.
FOUNDATION_EXTERN CGSize const kLSSizeFullBanner;

/// Leaderboard size for the iPad. Typically 728x90.
FOUNDATION_EXTERN CGSize const kLSSizeLeaderboard;

@class LSBannerView;
@protocol LSBannerViewDelegate <NSObject>
@optional
/**
 移除Banner时回调
 */
- (void)bannerDidDismiss;

/**
 广告展示成功的回调
 */
- (void)bannerDidShowToUser;

/**
 广告展示的网页加载完毕
 */
- (void)bannerDidCompleteLoadWeb;
@end

@interface LSBannerView : UIView

/**
 横幅广告位置（默认为:LSBannerPositionTop）
 */
@property (nonatomic, assign) LSBannerPosition position;

/**
 相对顶部或底部的偏移（范围:[0...100],默认为0）
 */
@property (nonatomic, assign) CGFloat offset;

/**
 广告尺寸大小
 可选推荐尺寸:
 kLSSizeBanner [320x50]
 kLSSizeLargeBanner [320x100]
 kLSSizeMediumRectangle [320x250]
 kLSSizeFullBanner [468x60]
 kLSSizeLeaderboard [728x90]）
 */
@property (nonatomic, assign) CGSize adSize;

/**
 自动切换时间(秒)（范围[20...60],设置为0不轮播,默认20s）
 */
@property (nonatomic) NSUInteger refreshInterval;

/**
 代理对象
 */
@property (nonatomic, weak) id <LSBannerViewDelegate> delegate;

/**
 宿主视图控制器（必选项）
 */
@property (nonatomic, weak) UIViewController * hostController;

/**
 是否使用Safari打开广告详情
 */
@property (nonatomic, assign) BOOL showAdDetailUsingSafari;

/**
 快速创建横幅广告的方法
 
 @param tagid 广告位id
 @param setup 对横幅广告进行设置的回调Block
 */
+ (void)bannerWithTagid:(NSString *)tagid setup:(void(^)(LSBannerView *set))setup;

@end
