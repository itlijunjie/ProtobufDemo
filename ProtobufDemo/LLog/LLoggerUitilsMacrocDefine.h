//
//  LLoggerUitilsMacrocDefine.h
//  Logic
//
//  Created by lijunjie on 24/8/14.
//  Copyright (c) 2015年 lijunjie. All rights reserved.
//

#import <CocoaLumberjack/CocoaLumberjack.h>

//异步打印日志开关
#define L_LOG_ASYNC_ON

#ifdef L_LOG_ASYNC_ON
    #define L_LOG_ASYNC YES
#else
    #define L_LOG_ASYNC NO
#endif

//L日志总开关
#ifdef DEBUG
    #define LLogOn
#endif
#ifdef LLogOn
    //注释这行取消普通日志输出,取消注释打开,标示符号 $JJ$
    #define LLOG_INFO_TAG

    //开启同步日志输出
    #define LLOG_SYNC_LOG_TAG
#endif

//L日志
#ifdef LLOG_INFO_TAG
    #define LLog(frmt, ...) LOG_MAYBE(L_LOG_ASYNC, DDLogLevelVerbose, DDLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, @"$INFO$ => \n\n" frmt@"\n",## __VA_ARGS__)
#else
    #define LLog(frmt, ...)
#endif

//同步日志
#ifdef LLOG_SYNC_LOG_TAG
    #define LLOG_SYNC_LOG(frmt, ...) LOG_MAYBE(NO, DDLogLevelVerbose, DDLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, @"$SYNC_LOG$ => " frmt,## __VA_ARGS__)
#else
    #define LLOG_SYNC_LOG(frmt, ...)
#endif
