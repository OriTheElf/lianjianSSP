//
//  LSAdConfig.h
//  lianjianSSP
//
//  Created by ghyud on 2017/9/29.
//  Copyright © 2017年 SHENZHEN LIANTRONICS CO.,LTD. All rights reserved.
//

#import <Foundation/Foundation.h>

//typedef NS_ENUM(NSInteger, LSADFormat) {
//    LSADFormatJSON = 0,
//    LSADFormatHTML
//};

@interface LSAdConfig : NSObject
@property (nonatomic, assign) BOOL testMode;
+ (LSAdConfig *)shared;


/**
 打开日志输出 (default NO)

 @param log YES 输出日志。
 */
+ (void)openLog:(BOOL)log;

@end
