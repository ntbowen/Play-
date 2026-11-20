#pragma once

#include <QString>

namespace QtUtils
{
	QString GetDiscImageFormatsFilter();

	//Translates an error message produced by the (non-Qt) emulator core.
	//Messages without a translation are returned unchanged.
	QString TranslateCoreError(const char* what);
}
