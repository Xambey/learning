#ifndef CLOSEFILTER_H
#define CLOSEFILTER_H

#include "QObject.h"

class CloseFilter : public QObject
{
protected:
    virtual bool eventFilter(QObject*, QEvent*);
public:
    CloseFilter(QObject* pobj = 0);
};

#endif // CLOSEFILTER_H
