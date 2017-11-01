//
//  LMAdInstlManager.h
//  lianjianSSP
//
//  Created by ghyud on 2017/10/11.
//  Copyright © 2017年 SHENZHEN LIANTRONICS CO.,LTD. All rights reserved.
//  插屏

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LSAdInstlManagerDelegate.h"

typedef enum {
//    AdInstlCloseButtonPosition_Default,//默认靠右
    AdInstlCloseButtonPosition_Left,// 靠左
    AdInstlCloseButtonPosition_Right// 靠右
}AdInstlCloseButtonPosition; //关闭按钮位置配置

/// iPhone and iPod Touch ad size. Typically 300x250.
FOUNDATION_EXTERN CGSize const kLSSize300x250;

FOUNDATION_EXTERN CGSize const kLSSize300x300;

//iPad
FOUNDATION_EXTERN CGSize const kLSSize600x500;
//iPad
FOUNDATION_EXTERN CGSize const kLSSize600x600;
//iPad
FOUNDATION_EXTERN CGSize const kLSSize1200x1200;

@interface LSAdInstlManager : NSObject

@property (nonatomic, weak)   id<LSAdInstlManagerDelegate>delegate;
//广告位id
@property (nonatomic, strong) NSString *placementID;

/**
 自动切换时间(秒)（范围[20...60],设置为0不轮播,默认20s）
 */
@property (nonatomic) NSUInteger refreshInterval;

@property (nonatomic, assign) AdInstlCloseButtonPosition closePostion;// default  AdInstlCloseButtonPosition_Right
//点击后是否移除广告广告  YES 是 NO 否  default NO
@property (nonatomic, assign, getter=isHiddenWhenClicked) BOOL hiddenWhenClicked;

//default full screen
@property (nonatomic, assign) CGSize instlSize;

/**
 广告点击跳转
 
 @return YES 应用内打开  NO跳转Safari打开链接  default NO
 */
@property (nonatomic, assign) BOOL openInside;


/**
 default LSAnimationTransitionFade
 */
@property (nonatomic, assign) LSAnimation animation;


+ (LSAdInstlManager *)managerWithPlacementID:(NSString *)placementID
                                    delegate:(id<LSAdInstlManagerDelegate>)delegate;

//加载插屏广告
- (void)loadAdInstl;

/**
 展示插屏广告
 建议在代理回调中调用
 @param controller 需要加载插屏广告的视图
 */
- (void)showAdInstlFromViewController:(UIViewController *)controller;

@end
