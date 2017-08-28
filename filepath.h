#pragma once
#include <QString>
#include <QDir>
#include <iostream>
using namespace std;

QString appdir(QDir::currentPath());
// The following has to be replaced by YOUR path to bins.hogg
// Do NOT change anything else, unless you know what you are doing
QString bindir("F:/Steam/steamapps/common/StarTrekOnline/StarTrekOnline/Playtest/piggs/bins.hogg");
// Path to clientmessagesenglish.bin file in the unpacked bins.hogg
QString cmedir(appdir + "/bins_unpack/bin/Clientmessagesenglish.bin");
