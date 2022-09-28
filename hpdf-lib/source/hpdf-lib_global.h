#ifndef HPDFLIB_GLOBAL_H
#define HPDFLIB_GLOBAL_H
#include <QtCore/qglobal.h>

#if defined(HPDFLIB_LIBRARY)
#  define HPDFLIBSHARED_EXPORT  Q_DECL_EXPORT
#else
#  define HPDFLIBSHARED_EXPORT  Q_DECL_IMPORT
#endif
#endif // HPDFLIB_GLOBAL_H
