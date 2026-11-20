#pragma once

#include <QCoreApplication>
#include <QString>
#include <cstring>

//Maps internal PS2 button names (see PS2::CControllerInfo::m_buttonName) to
//translated, human readable names for the controller configuration UI.
inline QString ControllerButtonDisplayName(const char* internalName)
{
	struct Entry
	{
		const char* internalName;
		const char* text;
	};
	static const Entry entries[] = {
	    {"analog_left_x", QT_TR_NOOP("Left Stick X")},
	    {"analog_left_y", QT_TR_NOOP("Left Stick Y")},
	    {"analog_right_x", QT_TR_NOOP("Right Stick X")},
	    {"analog_right_y", QT_TR_NOOP("Right Stick Y")},
	    {"dpad_up", QT_TR_NOOP("D-Pad Up")},
	    {"dpad_down", QT_TR_NOOP("D-Pad Down")},
	    {"dpad_left", QT_TR_NOOP("D-Pad Left")},
	    {"dpad_right", QT_TR_NOOP("D-Pad Right")},
	    {"select", QT_TR_NOOP("Select")},
	    {"start", QT_TR_NOOP("Start")},
	    {"square", QT_TR_NOOP("Square")},
	    {"triangle", QT_TR_NOOP("Triangle")},
	    {"circle", QT_TR_NOOP("Circle")},
	    {"cross", QT_TR_NOOP("Cross")},
	    {"l1", QT_TR_NOOP("L1")},
	    {"l2", QT_TR_NOOP("L2")},
	    {"l3", QT_TR_NOOP("L3")},
	    {"r1", QT_TR_NOOP("R1")},
	    {"r2", QT_TR_NOOP("R2")},
	    {"r3", QT_TR_NOOP("R3")},
	};
	for(const auto& entry : entries)
	{
		if(strcmp(internalName, entry.internalName) == 0)
		{
			return QCoreApplication::translate("ControllerConfigDialog", entry.text);
		}
	}
	return QString::fromUtf8(internalName);
}
