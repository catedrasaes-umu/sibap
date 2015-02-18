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

#ifndef AOG_GENERICFILEMANAGER_H
#define AOG_GENERICFILEMANAGER_H

#include <framework/aog_forward.h>
#include <framework/aog_fileobservable.h>

// Filesystem operations
#include <boost/filesystem.hpp>

// Obtain dates of files
#include <boost/date_time.hpp>

//Thread management
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>

#include <map>

namespace csu {
namespace aog {
namespace framework {


class GenericFileManager: public FileObservable
{
private:

    class WatchDog
    {
    public:
        WatchDog(GenericFileManager *manager);
        void start();
        void stop();
        void monitor();
    private:
        boost::thread * rthread_;
        GenericFileManager * manager_;
        bool  monitoring_;
    };

public:
    GenericFileManager(BehaviorConfiguration* context);
    virtual ~GenericFileManager();
    void clearFiles();

    // Service Methods
    bool updateFiles();
    bool initiated();

    const StringList * files();

protected:
    bool updateConfig();

protected:
    BehaviorConfiguration* context_;


private:
    // Supporting Methods
    void loadFiles(StringList);
    bool loadSingleFile(boost::filesystem::path);
    bool loadDirectory(boost::filesystem::path path);
    bool hasChanged(const std::string&,const std::string&);
    inline std::string getFileLastDate(boost::filesystem::path path);
    void reloadSingleFile(boost::filesystem::path path);

    void lock();
    void unlock();
    bool locked();

private:
    /// Attributes
    std::map<std::string,std::string> fileTimeMap_; // map of <files names,last wirte date>
    WatchDog * watchdog_;
    bool locked_;
    bool initiated_;
    StringList fileList_;
    std::string configFile_;
    std::string lastWriteConfigFile_;
};

}
}
}
#endif // AOG_GENERICFILEMANAGER_H
