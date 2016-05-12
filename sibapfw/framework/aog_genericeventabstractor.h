// -*- mode: c++; c-basic-offset: 4; c-basic-style: bsd; -*-
/*
*   This program is free software; you can redistribute it and/or
*   modify it under the terms of the GNU Lesser General Public License as
*   published by the Free Software Foundation; either version 3.0 of
*   the License, or (at your option) any later version.
*
*   This file is part of the SIBAP Prototyping Framework
*   http://pedromateo.github.io/sibap/
*/

#ifndef AOG_GENERICEVENTABSTRACTOR_H
#define AOG_GENERICEVENTABSTRACTOR_H

#include <framework/aog_forward.h>
#include <framework/aog_eventobservable.h>

#include <map>


namespace csu {
namespace aog {
namespace framework {

enum EventEnum {
    CLICK,
    DOUBLECLICK,
    WHEEL,
    FOCUSIN,
    FOCUSOUT,
    MOUSEOVERENTER,
    MOUSEOVERLEAVE,
    MOUSEOVERMOVE,
    KEYPRESS,
    KEYRELEASE,
    SHOW,
    HIDE,
    REPAINT
};

const std::string EventNames[]={
    "click",
    "doubleclick",
    "wheel",
    "focusin",
    "focusout",
    "mouseoverenter",
    "mouseoverleave",
    "mouseovermove",
    "keypress",
    "keyrelease",
    "show",
    "hide",
    "repaint"
};

class GenericEventAbstractor: public csu::aog::framework::EventObservable
{
public:
    GenericEventAbstractor(BehaviorConfiguration* context);

public:
    virtual void install()=0;
    virtual void uninstall()=0;
    bool isValidEvent(const std::string &);

protected:
    virtual void mapEvents()=0;

protected:
    BehaviorConfiguration* context_;

    typedef std::map<unsigned int,std::string> EventMap;
    EventMap eventMap_;
};

}
}
}

#endif // AOG_GENERICEVENTABSTRACTOR_H
