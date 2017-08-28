#ifndef _CME
#define _CME

#include "filepath.h"
#include <QFile>
#include <QStringList>
#include <QProcess>

namespace ClientMessagesEnglish
{
    QFile *cme_bin_old = new QFile(appdir + "/Clientmessagesenglish.bin");
    QDir *cme_old_dir = new QDir(appdir + "/Clientmessagesenglish");
    QFile *cme_bin = new QFile(appdir + "/bins_unpack/bin/Clientmessagesenglish.bin");
    // 5:
    void DeleteCMEBin()
    {
        if(cme_bin_old->exists())
        {
            printf(cme_bin_old->remove() ? "removed old clientmessagesenglish.bin" : "failed to remove clientmessagesenglish.bin");
            printf("\n");
            delete cme_bin_old;
        }
    }
    // 6:

    void DeleteOldCME()
    {
        QFile cme_old_file(appdir + "/CME_OLD");
        if(cme_old_file.exists())
        {
            printf(cme_old_file.remove() ? "removed old CME file" : "failed removing old CME file");
            printf("\n");
        }
    }

    // 7:
    void DeleteCMEFolder()
    {
        if(cme_old_dir->exists())
        {
            QFile cme_old_file(appdir + "/Clientmessagesenglish/Clientmessagesenglish.bin");
            printf(cme_old_dir->removeRecursively() && cme_old_file.rename(appdir + "/CME_OLD") && cme_old_dir->removeRecursively() ? "cleaned CME dir" : "failed to clean CME dir");
            delete cme_old_dir;
        }
    }
    // 8:
    void CopyCMEBin()
    {
        if(cme_bin->exists())
        {
            printf(cme_bin->copy(appdir + "/Clientmessagesenglish.bin") ? "copied CME.bin" : "failed copying CME.bin");
            printf("\n");
            delete cme_bin;
        }
    }
    // 9:
    void ConvertCMEBin()
    {
        QStringList args;
        args << "Clientmessagesenglish.bin";
        printf(QProcess::execute("Gibbed.Cryptic.ConvertResource.exe",args) == 0 ? "converted CME.bin" : "failed converting CME.bin");
        printf("\n");
    }
}

#endif // _CME
