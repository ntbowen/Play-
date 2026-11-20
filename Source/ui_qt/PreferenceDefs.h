#pragma once

#define PREFERENCE_AUDIO_ENABLEOUTPUT "audio.enableoutput"
#define PREF_UI_SHOWEECPUUSAGE "ui.showeecpuusage"
#define PREF_UI_PAUSEWHENFOCUSLOST "ui.pausewhenfocuslost"
#define PREF_UI_SHOWEXITCONFIRMATION "ui.showexitconfirmation"
#define PREF_UI_LANGUAGE "ui.language"
#define PREF_VIDEO_GS_HANDLER "video.gshandler"
#define PREF_INPUT_PAD1_PROFILE "input.pad1.profile"

//Values for PREF_UI_LANGUAGE
enum UiLanguage
{
	UI_LANGUAGE_SYSTEM = 0,
	UI_LANGUAGE_ENGLISH = 1,
	UI_LANGUAGE_CHINESE_SIMPLIFIED = 2,
};
