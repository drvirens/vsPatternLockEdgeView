#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <dlog.h>
#include "bo_logger.h"

#define MODULE_INFO (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#if defined DEBUG
#define INF(fmt, arg...) dlog_print(DLOG_INFO, \
		LOG_TAG, "%s: %s(%d) > " fmt, MODULE_INFO, \
		__func__, __LINE__, ##arg)
#else
#define INF(fmt, arg...) (0)
#endif



#if defined DEBUG
#define DBG(fmt, arg...) dlog_print(DLOG_DEBUG, \
		LOG_TAG, "%s: %s(%d) > " fmt, MODULE_INFO, \
		__func__, __LINE__, ##arg)
#else
#define DBG(fmt, arg...) (0)
#endif




#if defined DEBUG
#define WARN(fmt, arg...) dlog_print(DLOG_WARN, \
		LOG_TAG, "%s: %s(%d) > " fmt, MODULE_INFO, \
		__func__, __LINE__, ##arg)
#else
#define WARN(fmt, arg...) (0)
#endif





#if defined DEBUG
#define ERR(fmt, arg...) dlog_print(DLOG_ERROR, \
		LOG_TAG, "%s: %s(%d) > " fmt, MODULE_INFO, \
		__func__, __LINE__, ##arg)
#else
#define ERR(fmt, arg...) (0)
#endif




//#define __VIREN_DEBUG_DBUS__ 1 //add this in settings - not here
#if defined __VIREN_DEBUG_DBUS__
#define DBUS_DBG(fmt, arg...) dlog_print(DLOG_DEBUG, \
		LOG_TAG, "%s: %s(%d) > " fmt, MODULE_INFO, \
		__func__, __LINE__, ##arg)
#else
#define DBUS_DBG(fmt, arg...) (0)
#endif





#if defined DEBUG
#define TRACE DBG("%s", __func__);
#else
#define TRACE 
#endif




#define RETM_IF(expr, fmt, arg...) \
{ \
	if (expr) { \
		ERR(fmt, ##arg); \
		return; \
	} \
}

#define RETVM_IF(expr, val, fmt, arg...) \
{ \
	if (expr) { \
		ERR(fmt, ##arg); \
		return (val); \
	} \
}

#endif /* __LOGGER_H__ */
