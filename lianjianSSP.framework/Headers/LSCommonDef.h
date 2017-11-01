//
//  LSCommonDef.h
//  lianjianSSP
//
//  Created by ghyud on 2017/10/26.
//  Copyright © 2017年 SHENZHEN LIANTRONICS CO.,LTD. All rights reserved.
//

#ifndef LSCommonDef_h
#define LSCommonDef_h

typedef NS_ENUM(NSInteger, LSErrorCode) {
    LSErrorCodeOK                       = 100,//>>成功
    LSErrorCodeSystemError              = 101,//>>系统错误，请联系管理员
    LSErrorCodeMissParameterError       = 102,//>>缺少参数
    LSErrorCodeInvalidArgumentError     = 103,//>>参数非法
    LSErrorCodeInvalidTsError           = 104,//>>ts已过期
    LSErrorCodeNotExistError            = 105,//>>广告位信息不存在
    LSErrorCodeAdFilterError            = 106,//>>广告位策略过虑
    LSErrorCodeSignError                = 107,//>>sign错误
    LSErrorCodeNotMatchError            = 200, //>>找不到符合的广告信息
    LSErrorCodeTagNotExistError         = 999,//>>tagid 为空
    LSErrorCodeLoadFailed               = -999 //加载失败
};

typedef NS_ENUM(NSInteger, LSAnimation) {
    LSAnimationTransitionAuto = 0,
    LSAnimationTransitionFade,
    LSAnimationTransitionMoveIn,
    LSAnimationTransitionPush,
    LSAnimationTransitionReveal,
    LSAnimationTransitionCube,
    LSAnimationTransitionOglFlip,
    LSAnimationTransitionRippleEffect
};

typedef enum {
    LSAdEventType_DidLoadAd = 0,     //广告预加载完成
    LSAdEventType_FailLoadAd,        //广告加载失败
    LSAdEventType_DidShowAd,         //广告显示
    LSAdEventType_DismissAd,         //广告关闭
    LSAdEventType_DidClickAd,        //广告点击
    LSAdEventType_WillPresentModal,  //应用内打开链接
    LSAdEventType_DismissModal,      //关闭内嵌页面
}LSAdEventType;

#endif /* LSCommonDef_h */
