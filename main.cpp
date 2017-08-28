#include <QCoreApplication>
#include "clientmessagesenglish.h"
#include "hogg.h"

int main(int argc, char *argv[])
{
    // QCoreApplication a(argc, argv);
    try
    {
        cout << "Attempting to run..." << endl;
        Hogg::DeleteBinsHogg();
        Hogg::DeleteBinsUnpack();
        Hogg::CopyBinsHogg();
        Hogg::UnpackBinsHogg();
        ClientMessagesEnglish::DeleteCMEBin();
        ClientMessagesEnglish::DeleteOldCME();
        ClientMessagesEnglish::DeleteCMEFolder();
        ClientMessagesEnglish::CopyCMEBin();
        ClientMessagesEnglish::ConvertCMEBin();
    }
    catch(exception)
    {
        cout << "error" << endl;
    }
    cin.get();
    // return a.exec();
    return 0;
}
