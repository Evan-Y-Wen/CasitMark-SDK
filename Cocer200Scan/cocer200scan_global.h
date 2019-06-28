#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(COCER200SCAN_LIB)
#  define COCER200SCAN_EXPORT Q_DECL_EXPORT
# else
#  define COCER200SCAN_EXPORT Q_DECL_IMPORT
# endif
#else
# define COCER200SCAN_EXPORT
#endif
