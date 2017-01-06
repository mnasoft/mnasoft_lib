#ifndef MNASOFT_LIB_GLOBAL_H
#define MNASOFT_LIB_GLOBAL_H

#include <QtCore/QtGlobal>

#if defined(MNAS_LIBRARY)
#  define MNASOFT_EXPORT Q_DECL_EXPORT
#else
#  define MNASOFT_EXPORT Q_DECL_IMPORT
#endif

#endif //MNASOFT_LIB_GLOBAL_H
