    //
    // Created by will on 5/14/18.
    //
#include "library.h"
#include <vector>

#include <map>


void Eventbus::add_listener(EVENT event,PyMethodObject listener){
    listeners[event].insert(listener);
}
