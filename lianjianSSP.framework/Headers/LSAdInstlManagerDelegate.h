//
//  LMADInstlManagerDelegate.h
//  lianjianSSP
//
//  Created by ghyud on 2017/10/11.
//  Copyright © 2017年 SHENZHEN LIANTRONICS CO.,LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSCommonDef.h"

@class LSAdInstlManager;

@protocol LSAdInstlManagerDelegate <NSObject>

@optional

/**
 数据信息回调

 @param manager 插屏对象
 @param code 错误码
 @param error 错误信息
 */
- (void)adInstlManager:(LSAdInstlManager *)manager didRequestFinish:(LSErrorCode)code error:(NSError *)error;


/**
 广告状态信息／事件回调

 @param manager 插屏对象
 @param eventType 事件类型
 @param error 错误信息
 */
- (void)adInstlManager:(LSAdInstlManager *)manager withEvent:(LSAdEventType)eventType error:(NSError *)error;


@end
