// CommandSetGeneralGateway_DCS_Epos.h: Schnittstelle f�r die Klasse CCommandSetGeneralGateway_DCS_Epos.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CommandSetGeneralGateway_DCS_Epos_H__EF064ED0_0546_4F1A_875E_6F64B26B530C__INCLUDED_)
#define AFX_CommandSetGeneralGateway_DCS_Epos_H__EF064ED0_0546_4F1A_875E_6F64B26B530C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <CommunicationModel/Common/CommunicationModelDefinitions.h>
#include <CommunicationModel/CommonLayer/ErrorHandling/ErrorInfo.h>
#include "../BaseClasses/CommandSetBase_DCS.h"
#include <Classes/XXMLFile.h>

class CGateway;
class CCommand_DCS_Epos;
class CLayerManagerBase;

class CCommandSetGeneralGateway_DCS_Epos : public CCommandSetBase_DCS
{
public:
    BOOL DCS_SendCANFrame(CLayerManagerBase* pManager, HANDLE hHandle, HANDLE hTransactionHandle, WORD wCobID, WORD wLength, void* pData, CErrorInfo* pErrorInfo = NULL);
    BOOL DCS_RequestCANFrame(CLayerManagerBase* pManager, HANDLE hHandle, HANDLE hTransactionHandle, WORD wCobID, WORD wLength, void* pData, CErrorInfo* pErrorInfo = NULL);
    BOOL DCS_ReadCANFrame(CLayerManagerBase* pManager, HANDLE hHandle, HANDLE hTransactionHandle, WORD wCobID, WORD wLength, void* pData, DWORD p_ulTimeOut, CErrorInfo* pErrorInfo = NULL);


    CXXMLFile::CElementPart* StoreToXMLFile(CXXMLFile* pFile, CXXMLFile::CElementPart* pParentElement);

    CCommandSetGeneralGateway_DCS_Epos();
    virtual ~CCommandSetGeneralGateway_DCS_Epos();

//JournalManager
    virtual void InitJournalManager(CJournalManagerBase* pJournalManager);
    virtual void ResetJournalManager();

//Gateway
    virtual BOOL InitGateway(CGateway *pGateway);

private:
    void DeleteCommands();
    void InitCommands();

    CCommand_DCS_Epos* m_pCommand_SendCANFrame;
    CCommand_DCS_Epos* m_pCommand_RequestCANFrame;
    CCommand_DCS_Epos* m_pCommand_ReadCANFrame;
};

#endif // !defined(AFX_CommandSetGeneralGateway_DCS_Epos_H__EF064ED0_0546_4F1A_875E_6F64B26B530C__INCLUDED_)
