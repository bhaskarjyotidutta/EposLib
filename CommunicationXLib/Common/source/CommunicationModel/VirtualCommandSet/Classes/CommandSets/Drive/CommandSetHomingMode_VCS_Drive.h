// CommandSetHomingMode_VCS_Drive.h: Schnittstelle f�r die Klasse CCommandSetHomingMode_VCS_Drive.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CommandSetHomingMode_VCS_Drive_H__D86438FA_A3E0_4E0F_B28B_56910B64E752__INCLUDED_)
#define AFX_CommandSetHomingMode_VCS_Drive_H__D86438FA_A3E0_4E0F_B28B_56910B64E752__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <CommunicationModel/Common/CommunicationModelDefinitions.h>


#include <CommunicationModel/CommonLayer/ErrorHandling/ErrorInfo.h>
#include "../BaseClasses/CommandSetBase_VCS.h"
#include <Classes/XXMLFile.h>

class CGateway;
class CCommand_VCS_Drive;
class CLayerManagerBase;

class CCommandSetHomingMode_VCS_Drive : public CCommandSetBase_VCS
{
public:
    BOOL VCS_StopHoming(CLayerManagerBase* p_pManager, HANDLE p_hHandle, HANDLE p_hTransactionHandle, CErrorInfo* p_pErrorInfo = NULL);
    BOOL VCS_FindHome(CLayerManagerBase* p_pManager, HANDLE p_hHandle, HANDLE p_hTransactionHandle, __int8 p_bHomingMethod, CErrorInfo* p_pErrorInfo = NULL);
    BOOL VCS_SetHomingParameter(CLayerManagerBase* p_pManager, HANDLE p_hHandle, HANDLE p_hTransactionHandle, DWORD p_ulHomingAcceleration, DWORD p_ulSpeedSwitch, DWORD p_ulSpeedIndex, long p_lHomeOffset, WORD p_usCurrentThreshold, long p_lHomePosition=0, CErrorInfo* p_pErrorInfo = NULL);
    BOOL VCS_GetHomingParameter(CLayerManagerBase* p_pManager, HANDLE p_hHandle, HANDLE p_hTransactionHandle, DWORD *p_pulHomingAcceleration, DWORD *p_pulSpeedSwitch, DWORD *p_pulSpeedIndex, long *p_plHomeOffset, WORD* p_pusCurrentThreshold, long *p_plHomePosition = NULL, CErrorInfo* p_pErrorInfo = NULL);
    BOOL VCS_DefinePosition(CLayerManagerBase* p_pManager, HANDLE p_hHandle, HANDLE p_hTransactionHandle, long p_lHomePosition, CErrorInfo* p_pErrorInfo = NULL);

    CXXMLFile::CElementPart* StoreToXMLFile(CXXMLFile* p_pFile, CXXMLFile::CElementPart* p_pParentElement);

    CCommandSetHomingMode_VCS_Drive();
    virtual ~CCommandSetHomingMode_VCS_Drive();

//JournalManager
    virtual void InitJournalManager(CJournalManagerBase *p_pJournalManager);
    virtual void ResetJournalManager();

//Gateway
    virtual BOOL InitGateway(CGateway *p_pGateway);

private:
    void InitCommands();
    void DeleteCommands();
    CCommand_VCS_Drive* m_pCommand_FindHome;
    CCommand_VCS_Drive* m_pCommand_GetHomingParameter;
    CCommand_VCS_Drive* m_pCommand_SetHomingParameter;
    CCommand_VCS_Drive* m_pCommand_StopHoming;
    CCommand_VCS_Drive* m_pCommand_DefinePosition;
};

#endif // !defined(AFX_CommandSetHomingMode_VCS_Drive_H__D86438FA_A3E0_4E0F_B28B_56910B64E752__INCLUDED_)
