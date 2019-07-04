#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CM3FORMRESULT_LIB)
#  define CM3FORMRESULT_EXPORT Q_DECL_EXPORT
# else
#  define CM3FORMRESULT_EXPORT Q_DECL_IMPORT
# endif
#else
# define CM3FORMRESULT_EXPORT
#endif
