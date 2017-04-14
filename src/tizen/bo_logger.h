/*
 * bo_logger.h
 *
 *  Created on: Feb 3, 2017
 *      Author: virendra.shakya
 */

#ifndef BO_LOGGER_H_
#define BO_LOGGER_H_

#include <app.h>
#include <Elementary.h>
#include <system_settings.h>
#include <efl_extension.h>
#include <dlog.h>



#ifdef  LOG_TAG
#undef  LOG_TAG
#endif
#define LOG_TAG "    vsNodeView    "

#if !defined(PACKAGE)
#define PACKAGE "org.example.bopagedscroller"
#endif

#endif /* BO_LOGGER_H_ */
