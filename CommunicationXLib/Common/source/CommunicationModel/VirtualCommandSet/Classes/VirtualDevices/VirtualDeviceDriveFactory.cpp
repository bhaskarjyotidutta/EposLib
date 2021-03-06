#include "stdafx.h"
#include "VirtualDeviceDriveFactory.h"

/*DON'T EDIT THIS FILE! autogenerated code by XlibFactoryBuilder 1.0.2.3*/

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

BOOL CVirtualDeviceDriveFactory::GetAllIdentifiers(std::list<CStdString>& p_rTargets)
{
	BOOL oResult = FALSE;

	p_rTargets.clear();

	p_rTargets.push_back(DEVICE_EPOS);
	p_rTargets.push_back(DEVICE_ESAM);

	oResult = TRUE;

	return oResult;
}

BOOL CVirtualDeviceDriveFactory::CreateInstance(CStdString p_Name, CGatewayVCStoDCS*& p_rpNewInstance)
{
	BOOL oResult = FALSE;

	if(p_Name.CompareNoCase(DEVICE_EPOS) == 0)
	{
		p_rpNewInstance = new CGatewayDriveToEpos();
		oResult = TRUE;
	}
	else if(p_Name.CompareNoCase(DEVICE_ESAM) == 0)
	{
		p_rpNewInstance = new CGatewayDriveToEsam();
		oResult = TRUE;
	}

	return oResult;
}
