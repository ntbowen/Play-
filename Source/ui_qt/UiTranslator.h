#pragma once

class QCoreApplication;

namespace UiTranslator
{
//Installs the translators for the language selected in the settings.
//Any previously installed UI translators are removed first, so this can be
//called again when the language preference changes.
void ApplyLanguage(QCoreApplication& app);
}
