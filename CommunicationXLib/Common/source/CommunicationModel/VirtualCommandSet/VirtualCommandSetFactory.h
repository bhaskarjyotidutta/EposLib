#pragma once

/*DONT EDIT THIS FILE! autogenerated code by XlibFactoryBuilder 1.0.2.3*/

#include <list>
#include <StdString.h>

#include "Classes/VirtualDevices/VirtualDevice_Drive.h"
#include "Classes/VirtualDevices/VirtualDevice_Drive2.h"
#include "Classes/VirtualDevices/VirtualDevice_Plc.h"
#include "Classes/VirtualDevices/VirtualDevice_Plc2.h"

class CVirtualCommandSetFactory
{
public:
	static BOOL GetAllIdentifiers(std::list<CStdString>& p_rTargets);
	static BOOL CreateInstance(CStdString p_Name, CVirtualDeviceBase*& p_rpInstance);
};