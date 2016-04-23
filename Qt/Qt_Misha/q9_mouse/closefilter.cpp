#include "closefilter.h"
#include "mouseobserver.h"

bool CloseFilter::eventFilter(QObject * sender, QEvent *event)
{
    if(event->type() == QEvent::Close){
        event->ignore();
        return static_cast<MouseObserver*>(sender)->getNeedSave();;
    }

    return false;
}

CloseFilter::CloseFilter(QObject *pobj)
{

}
