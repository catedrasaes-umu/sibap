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

#ifndef LUA_ASPECTENGINE_H
#define LUA_ASPECTENGINE_H

#include <framework/aog_forward.h>
#include <framework/aog_genericbehaviorengine.h>

#include <lua5.1/lua.hpp>
#include <boost/regex.hpp>

namespace csu {
namespace aog {
namespace vlang {
namespace lua {

class Lua_BehaviorEngine: public csu::aog::framework::GenericBehaviorEngine
{
public:
    Lua_BehaviorEngine(csu::aog::framework::BehaviorConfiguration* context);

    bool functionExists(const std::string & func);
    void initialize(void);
    void resetEngine();

protected:
    bool callFunction(const std::string & func);
    bool callFunction(const csu::aog::framework::FunctionSet & funcList);
    void registerFunction(const std::string &state,boost::function <bool(void)>  transitionFunc);
    void registerLogGlobalFunc(const std::string &funcName, boost::function<void (std::string)>fp);
    void registerLogSpecificFunc(const std::string &funcName, boost::function<void (std::string,std::string)>fp);
    void deleteFunction(const std::string & func);



private:
    const csu::aog::framework::FunctionSet * loadScriptsinEngine(const csu::aog::framework::StringList * scripts);
    const csu::aog::framework::FunctionSet * processGlobals();

private:
    lua_State * L_;


};

}
}
}
}
#endif // LUA_ASPECTENGINE_H
