// -*- mode: c++; c-basic-offset: 4; c-basic-style: bsd; -*-
/*
*   This program is free software; you can redistribute it and/or
*   modify
*   it under the terms of the GNU Lesser General Public License as
*   published by the Free Software Foundation; either version 3.0 of
*   the License, or (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU Lesser General Public License for more details.
*
*   You should have received a copy of the GNU Lesser General Public
*   License along with this library; if not, write to the Free Software
*   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
*   02111-1307 USA
*
*   This file is part of the Aspect-Oriented Behavior Framework,
*   https://sourceforge.net/projects/aobf/
*
*/

#ifndef AOG_GENERICELEMENTREGISTRAR_H
#define AOG_GENERICELEMENTREGISTRAR_H

#include <framework/aog_forward.h>

#include <boost/any.hpp>

#include <set>

namespace csu {
namespace aog {
namespace framework {


class GenericElementRegistrar
{
public:

    ///
    /// Constructor
    /// @param context is the verification context
    ///
    GenericElementRegistrar(BehaviorConfiguration* context);
    ~GenericElementRegistrar();

    ///
    /// Element registration method
    /// @param object is a generic object that can be used or not
    ///
    virtual boost::any registerGUIElements(boost::any& object) = 0;

    virtual void windowCreate(const std::string & windowName)=0;
    virtual void windowDelete(const std::string & windowName)=0;

protected:
    ///
    /// Element registration update (without providing context)
    ///
    virtual boost::any updateGUIElementRegister() = 0;



protected:

    /// In order to let this method to be general, the parameter must be
    /// the class name to register inside a std string. Specifica classes, should
    /// get and convert their classes names to strings.
    void registerClass(const std::string className);

    /// Check if a class, indexed by its name, can be registered
    bool isRegistrable(const std::string className);

protected:
    BehaviorConfiguration* context_;

private:
    typedef std::set<std::string> RegisterSet;
    RegisterSet registerSet_;
};


}
}
}
#endif // AOG_GENERICELEMENTREGISTRAR_H
