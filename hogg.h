#ifndef _HOGG
#define _HOGG

#include <QFile>
#include <QStringList>
#include <QProcess>
#include <cstdio>
#include "filepath.h"
namespace Hogg
{
    QFile *hogg_origin = new QFile(bindir);
    QFile hogg_current(appdir + "/bins.hogg");
    QDir *bins_unpack = new QDir(appdir + "/bins_unpack");
    // 1:
    void DeleteBinsHogg()
    {
        if(hogg_current.exists())
        {
            printf(hogg_current.remove() ? "removed bins.hogg" : "could not remove bins.hogg");
            printf("\n");
            hogg_current.close();
        }
    }
    // 2:
    void DeleteBinsUnpack()
    {
        if(bins_unpack->exists())
        {
            printf(bins_unpack->removeRecursively() ? "removed bins_unpack" : "could not remove bins_unpack");
            printf("\n");
            delete bins_unpack;
        }
    }
    // 3:
    void CopyBinsHogg()
    {
        printf(hogg_origin->copy(appdir + "/bins.hogg") ? "copied bins.hogg" : "could not copy bins.hogg");
        printf("\n");
    }
    // 4:
    void UnpackBinsHogg()
    {
        QStringList args;
        args << "bins.hogg";
        printf(QProcess::execute("Gibbed.Cryptic.Unpack.exe",args) == 0 ? "unpacked bins.hogg" : "failed to unpack bins.hogg");
    }
}

#endif // _HOGG
