#include <QCoreApplication>
#include <cassert>
#include "InputProviderQtMouse.h"
#include "string_format.h"

#define PROVIDER_ID 'QtMo'

uint32 CInputProviderQtMouse::GetId() const
{
	return PROVIDER_ID;
}

std::string CInputProviderQtMouse::GetTargetDescription(const BINDINGTARGET& target) const
{
	assert(target.providerId == PROVIDER_ID);
	auto description = [&]() -> QString {
		switch(target.keyId)
		{
		case Qt::LeftButton:
			return QCoreApplication::translate("CInputProviderQtMouse", "Left Button");
		case Qt::RightButton:
			return QCoreApplication::translate("CInputProviderQtMouse", "Right Button");
		default:
			return QCoreApplication::translate("CInputProviderQtMouse", "Unknown button %1").arg(target.keyId);
		}
	}();
	return QCoreApplication::translate("CInputProviderQtMouse", "Mouse: %1")
	    .arg(description)
	    .toStdString();
}

BINDINGTARGET CInputProviderQtMouse::MakeBindingTarget(Qt::MouseButton mouseButton)
{
	return BINDINGTARGET(PROVIDER_ID, DeviceIdType{{0}}, mouseButton, BINDINGTARGET::KEYTYPE::BUTTON);
}

void CInputProviderQtMouse::OnMousePress(Qt::MouseButton mouseButton)
{
	OnInput(MakeBindingTarget(mouseButton), 1);
}

void CInputProviderQtMouse::OnMouseRelease(Qt::MouseButton mouseButton)
{
	OnInput(MakeBindingTarget(mouseButton), 0);
}
