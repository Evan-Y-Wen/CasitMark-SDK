#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CM3FORMPATTERN_LIB)
#  define CM3FORMPATTERN_EXPORT Q_DECL_EXPORT
# else
#  define CM3FORMPATTERN_EXPORT Q_DECL_IMPORT
# endif
#else
# define CM3FORMPATTERN_EXPORT
#endif
