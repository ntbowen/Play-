#include "QtUtils.h"
#include "DiskUtils.h"
#include <QStringList>
#include <QCoreApplication>

QString QtUtils::GetDiscImageFormatsFilter()
{
	std::string fileFilter;
	const auto& extensions = DiskUtils::GetSupportedExtensions();
	for(auto extensionIterator = extensions.begin();
	    extensionIterator != extensions.end(); extensionIterator++)
	{
		if(extensionIterator != extensions.begin())
		{
			fileFilter += " ";
		}
		fileFilter += "*" + *extensionIterator;
	}
	return QCoreApplication::translate("QtUtils", "Disc images(%1)").arg(QString::fromStdString(fileFilter));
}
