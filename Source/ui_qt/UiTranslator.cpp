#include "UiTranslator.h"
#include "AppConfig.h"
#include "PreferenceDefs.h"

#include <QCoreApplication>
#include <QTranslator>
#include <QLocale>
#include <QStringList>

namespace
{
	QTranslator* s_qtTranslator = nullptr;
	QTranslator* s_appTranslator = nullptr;

	QString GetTranslationName()
	{
		switch(CAppConfig::GetInstance().GetPreferenceInteger(PREF_UI_LANGUAGE))
		{
		case UI_LANGUAGE_ENGLISH:
			//The source strings are English, no translation needed.
			return QString();
		case UI_LANGUAGE_CHINESE_SIMPLIFIED:
			return QStringLiteral("play_zh_CN");
		default:
		{
			const QString systemLocale = QLocale::system().name();
			if(systemLocale.startsWith(QStringLiteral("zh_CN")) ||
			   systemLocale.startsWith(QStringLiteral("zh_SG")))
			{
				return QStringLiteral("play_zh_CN");
			}
			return QString();
		}
		}
	}
}

void UiTranslator::ApplyLanguage(QCoreApplication& app)
{
	const QString translationName = GetTranslationName();
	const QStringList searchPaths = {
	    QCoreApplication::applicationDirPath() + "/translations",              //Windows/Linux
	    QCoreApplication::applicationDirPath() + "/../Resources/translations", //macOS app bundle
	};

	auto replaceTranslator = [&](const QString& name, QTranslator*& slot) {
		if(slot != nullptr)
		{
			app.removeTranslator(slot);
			delete slot;
			slot = nullptr;
		}
		if(name.isEmpty())
		{
			return;
		}
		auto* translator = new QTranslator(&app);
		bool loaded = false;
		for(const auto& path : searchPaths)
		{
			if(translator->load(name, path))
			{
				loaded = true;
				break;
			}
		}
		if(loaded)
		{
			app.installTranslator(translator);
			slot = translator;
		}
		else
		{
			delete translator;
		}
	};

	//Qt's own translations for standard widgets (buttons, dialogs, ...).
	//Our catalogs are named play_<locale>, Qt's are named qt_<locale>/qtbase_<locale>.
	if(!translationName.isEmpty())
	{
		const QString localeName = translationName.mid(translationName.indexOf(QLatin1Char('_')) + 1);
		replaceTranslator(QStringLiteral("qt_") + localeName, s_qtTranslator);
		if(s_qtTranslator == nullptr)
		{
			replaceTranslator(QStringLiteral("qtbase_") + localeName, s_qtTranslator);
		}
	}
	else
	{
		replaceTranslator(QString(), s_qtTranslator);
	}
	replaceTranslator(translationName, s_appTranslator);
}
