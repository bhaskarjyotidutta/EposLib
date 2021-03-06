// CommandSetInputsOutputs_VCS_Drive.cpp: Implementierung der Klasse CCommandSetInputsOutputs_VCS_Drive.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "CommandSetInputsOutputs_VCS_Drive.h"

#include <CommunicationModel/CommonLayer/Classes/Commands/VirtualCommandSet/Command_VCS_Drive.h>
#include "CommandSetInputsPositionMarker_VCS_Drive.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////
CCommandSetInputsOutputs_VCS_Drive::CCommandSetInputsOutputs_VCS_Drive()
{
    m_strCommandSetName = COMMAND_SET_INPUTS_OUTPUTS;

    m_pCommand_DigitalInputConfiguration = NULL;
    m_pCommand_DigitalOutputConfiguration = NULL;
    m_pCommand_GetAllDigitalInputs = NULL;
    m_pCommand_GetAllDigitalOutputs = NULL;
    m_pCommand_GetAnalogInput = NULL;
    m_pCommand_SetAllDigitalOutputs = NULL;

    InitCommands();
    FillSetList();
}

CCommandSetInputsOutputs_VCS_Drive::~CCommandSetInputsOutputs_VCS_Drive()
{
    DeleteCommands();
    DeleteSetList();
}

void CCommandSetInputsOutputs_VCS_Drive::FillSetList()
{
    m_pCommand_CommandSetInputsPositionMarker  = new CCommandSetInputsPositionMarker_VCS_Drive();
}

void CCommandSetInputsOutputs_VCS_Drive::DeleteSetList()
{
    if(m_pCommand_CommandSetInputsPositionMarker)
    {
        delete m_pCommand_CommandSetInputsPositionMarker;
        m_pCommand_CommandSetInputsPositionMarker = NULL;
    }
}

WORD CCommandSetInputsOutputs_VCS_Drive::GetNewBitMask(WORD p_usConfiguration, WORD p_usOldMask, BOOL p_oState)
{
    WORD usNewMask;

    if(p_oState)
    {//bit set to 1
        usNewMask = 1;

        for(int i = 0; i < p_usConfiguration; i++)
            usNewMask <<= 1;

        usNewMask |= p_usOldMask;
    }
    else
    {//bit set to 0
        usNewMask = 0xFFFF;

        for(int i = 0; i < p_usConfiguration; i++)
            usNewMask <<= 1;
        usNewMask--;

        usNewMask &= p_usOldMask;
    }

    return usNewMask;
}

BOOL CCommandSetInputsOutputs_VCS_Drive::VCS_DigitalInputConfiguration(CLayerManagerBase* p_pManager, HANDLE p_hHandle, HANDLE p_hTransactionHandle, WORD p_usDigitalInputNb, WORD p_usConfiguration, BOOL p_oMask, BOOL p_oPolarity, BOOL p_oExecutionMask, CErrorInfo* p_pErrorInfo)
{
    BOOL oResult = FALSE;

    if(m_pCommand_DigitalInputConfiguration)
    {
        //Set Parameter Data
        m_pCommand_DigitalInputConfiguration->ResetStatus();
        m_pCommand_DigitalInputConfiguration->SetParameterData(0, &p_usDigitalInputNb, sizeof(p_usDigitalInputNb));
        m_pCommand_DigitalInputConfiguration->SetParameterData(1, &p_usConfiguration, sizeof(p_usConfiguration));
        m_pCommand_DigitalInputConfiguration->SetParameterData(2, &p_oMask, sizeof(p_oMask));
        m_pCommand_DigitalInputConfiguration->SetParameterData(3, &p_oPolarity, sizeof(p_oPolarity));
        m_pCommand_DigitalInputConfiguration->SetParameterData(4, &p_oExecutionMask, sizeof(p_oExecutionMask));

        //ExecuteCommand
        oResult = m_pCommand_DigitalInputConfiguration->Execute(p_pManager, p_hHandle, p_hTransactionHandle);

        //Get ErrorCode
        m_pCommand_DigitalInputConfiguration->GetErrorInfo(p_pErrorInfo);
    }

    return oResult;
}

BOOL CCommandSetInputsOutputs_VCS_Drive::VCS_DigitalOutputConfiguration(CLayerManagerBase* p_pManager, HANDLE p_hHandle, HANDLE p_hTransactionHandle, WORD p_usDigitalOutputNb, WORD p_usConfiguration, BOOL p_oState, BOOL p_oMask, BOOL p_oPolarity, CErrorInfo* p_pErrorInfo)
{
    BOOL oResult = FALSE;

    if(m_pCommand_DigitalOutputConfiguration)
    {
        //Set Parameter Data
        m_pCommand_DigitalOutputConfiguration->ResetStatus();
        m_pCommand_DigitalOutputConfiguration->SetParameterData(0, &p_usDigitalOutputNb, sizeof(p_usDigitalOutputNb));
        m_pCommand_DigitalOutputConfiguration->SetParameterData(1, &p_usConfiguration, sizeof(p_usConfiguration));
        m_pCommand_DigitalOutputConfiguration->SetParameterData(2, &p_oState, sizeof(p_oState));
        m_pCommand_DigitalOutputConfiguration->SetParameterData(3, &p_oMask, sizeof(p_oMask));
        m_pCommand_DigitalOutputConfiguration->SetParameterData(4, &p_oPolarity, sizeof(p_oPolarity));

        //ExecuteCommand
        oResult = m_pCommand_DigitalInputConfiguration->Execute(p_pManager, p_hHandle, p_hTransactionHandle);

        //Get ErrorCode
        m_pCommand_DigitalOutputConfiguration->GetErrorInfo(p_pErrorInfo);
    }

    return oResult;
}

BOOL CCommandSetInputsOutputs_VCS_Drive::VCS_GetAllDigitalInputs(CLayerManagerBase *p_pManager, HANDLE p_hHandle, HANDLE p_hTransactionHandle, WORD *p_pusInputs, CErrorInfo* p_pErrorInfo)
{
    BOOL oResult = FALSE;

    if(m_pCommand_GetAllDigitalInputs)
    {
        //Set Parameter Data
        m_pCommand_GetAllDigitalInputs->ResetStatus();

        //ExecuteCommand
        oResult = m_pCommand_GetAllDigitalInputs->Execute(p_pManager, p_hHandle, p_hTransactionHandle);

        //Get ReturnParameter Data
        m_pCommand_GetAllDigitalInputs->GetReturnParameterData(0, p_pusInputs, sizeof(*p_pusInputs));

        //Get ErrorCode
        m_pCommand_GetAllDigitalInputs->GetErrorInfo(p_pErrorInfo);
    }

    return oResult;
}

BOOL CCommandSetInputsOutputs_VCS_Drive::VCS_GetAllDigitalOutputs(CLayerManagerBase *p_pManager, HANDLE p_hHandle, HANDLE p_hTransactionHandle, WORD *p_pusOutputs, CErrorInfo* p_pErrorInfo)
{
    BOOL oResult = FALSE;

    if(m_pCommand_GetAllDigitalOutputs)
    {
        //Set Parameter Data
        m_pCommand_GetAllDigitalOutputs->ResetStatus();

        //ExecuteCommand
        oResult = m_pCommand_GetAllDigitalOutputs->Execute(p_pManager, p_hHandle, p_hTransactionHandle);

        //Get ReturnParameter Data
        m_pCommand_GetAllDigitalOutputs->GetReturnParameterData(0, p_pusOutputs, sizeof(*p_pusOutputs));

        //Get ErrorCode
        m_pCommand_GetAllDigitalOutputs->GetErrorInfo(p_pErrorInfo);
    }

    return oResult;
}

BOOL CCommandSetInputsOutputs_VCS_Drive::VCS_GetAnalogInput(CLayerManagerBase *p_pManager, HANDLE p_hHandle, HANDLE p_hTransactionHandle, WORD p_usNumber, WORD *p_pusAnalog, CErrorInfo* p_pErrorInfo)
{
    BOOL oResult = FALSE;

    if(m_pCommand_GetAnalogInput)
    {
        //Set Parameter Data
        m_pCommand_GetAnalogInput->ResetStatus();
        m_pCommand_GetAnalogInput->SetParameterData(0, &p_usNumber, sizeof(p_usNumber));

        //ExecuteCommand
        oResult = m_pCommand_GetAnalogInput->Execute(p_pManager, p_hHandle, p_hTransactionHandle);

        //Get ReturnParameter Data
        m_pCommand_GetAnalogInput->GetReturnParameterData(0, p_pusAnalog, sizeof(*p_pusAnalog));

        //Get ErrorCode
        m_pCommand_GetAnalogInput->GetErrorInfo(p_pErrorInfo);
    }

    return oResult;
}

BOOL CCommandSetInputsOutputs_VCS_Drive::VCS_SetAllDigitalOutputs(CLayerManagerBase *p_pManager, HANDLE p_hHandle, HANDLE p_hTransactionHandle, WORD p_usOutputs, CErrorInfo* p_pErrorInfo)
{
    BOOL oResult = FALSE;

    if(m_pCommand_SetAllDigitalOutputs)
    {
        //Set Parameter Data
        m_pCommand_SetAllDigitalOutputs->ResetStatus();
        m_pCommand_SetAllDigitalOutputs->SetParameterData(0, &p_usOutputs, sizeof(p_usOutputs));

        //ExecuteCommand
        oResult = m_pCommand_SetAllDigitalOutputs->Execute(p_pManager, p_hHandle, p_hTransactionHandle);

        //Get ErrorCode
        m_pCommand_SetAllDigitalOutputs->GetErrorInfo(p_pErrorInfo);
    }

    return oResult;
}

void CCommandSetInputsOutputs_VCS_Drive::InitCommands()
{
    DeleteCommands();

    //Init DigitalInputConfiguration
    m_pCommand_DigitalInputConfiguration = new CCommand_VCS_Drive();
    m_pCommand_DigitalInputConfiguration->InitCommand(DRIVE_DIGITAL_INPUT_CONFIGURATION);

    //Init DigitalOutputConfiguration
    m_pCommand_DigitalOutputConfiguration = new CCommand_VCS_Drive();
    m_pCommand_DigitalOutputConfiguration->InitCommand(DRIVE_DIGITAL_OUTPUT_CONFIGURATION);

    //Init GetAllDigitalInputs
    m_pCommand_GetAllDigitalInputs = new CCommand_VCS_Drive();
    m_pCommand_GetAllDigitalInputs->InitCommand(DRIVE_GET_ALL_DIGITAL_INPUTS);

    //Init GetAllDigitalOutputs
    m_pCommand_GetAllDigitalOutputs = new CCommand_VCS_Drive();
    m_pCommand_GetAllDigitalOutputs->InitCommand(DRIVE_GET_ALL_DIGITAL_OUTPUTS);

    //Init GetAnalogInput
    m_pCommand_GetAnalogInput = new CCommand_VCS_Drive();
    m_pCommand_GetAnalogInput->InitCommand(DRIVE_GET_ANALOG_INPUT);

    //Init SetAllDigitalOutputs
    m_pCommand_SetAllDigitalOutputs = new CCommand_VCS_Drive();
    m_pCommand_SetAllDigitalOutputs->InitCommand(DRIVE_SET_ALL_DIGITAL_OUTPUTS);
}

void CCommandSetInputsOutputs_VCS_Drive::DeleteCommands()
{
    if(m_pCommand_DigitalInputConfiguration)
    {
        delete m_pCommand_DigitalInputConfiguration;
        m_pCommand_DigitalInputConfiguration = NULL;
    }

    if(m_pCommand_DigitalOutputConfiguration)
    {
        delete m_pCommand_DigitalOutputConfiguration;
        m_pCommand_DigitalOutputConfiguration = NULL;
    }

    if(m_pCommand_GetAllDigitalInputs)
    {
        delete m_pCommand_GetAllDigitalInputs;
        m_pCommand_GetAllDigitalInputs = NULL;
    }

    if(m_pCommand_GetAllDigitalOutputs)
    {
        delete m_pCommand_GetAllDigitalOutputs;
        m_pCommand_GetAllDigitalOutputs = NULL;
    }

    if(m_pCommand_GetAnalogInput)
    {
        delete m_pCommand_GetAnalogInput;
        m_pCommand_GetAnalogInput = NULL;
    }

    if(m_pCommand_SetAllDigitalOutputs)
    {
        delete m_pCommand_SetAllDigitalOutputs;
        m_pCommand_SetAllDigitalOutputs = NULL;
    }
}

CXXMLFile::CElementPart* CCommandSetInputsOutputs_VCS_Drive::StoreToXMLFile(CXXMLFile* p_pFile, CXXMLFile::CElementPart* p_pParentElement)
{
    CXXMLFile::CElement* pElement = NULL;
    BOOL oCheckVisibility = FALSE;

    if(p_pFile && p_pParentElement)
    {
        //CommandSet Elements
        pElement = (CXXMLFile::CElement*)p_pFile->AddElement(p_pParentElement);
        p_pFile->SetText(pElement, "CommandSet");
        pElement->SetAt("Name", m_strCommandSetName);

        //Command Elements
        if(m_pCommand_DigitalInputConfiguration && !m_pCommand_DigitalInputConfiguration->StoreToXMLFile(p_pFile, pElement, oCheckVisibility)) return FALSE;
        if(m_pCommand_DigitalOutputConfiguration && !m_pCommand_DigitalOutputConfiguration->StoreToXMLFile(p_pFile, pElement, oCheckVisibility)) return FALSE;
        if(m_pCommand_GetAllDigitalInputs && !m_pCommand_GetAllDigitalInputs->StoreToXMLFile(p_pFile, pElement, oCheckVisibility)) return FALSE;
        if(m_pCommand_GetAllDigitalOutputs && !m_pCommand_GetAllDigitalOutputs->StoreToXMLFile(p_pFile, pElement, oCheckVisibility)) return FALSE;
        if(m_pCommand_GetAnalogInput && !m_pCommand_GetAnalogInput->StoreToXMLFile(p_pFile, pElement, oCheckVisibility)) return FALSE;
        if(m_pCommand_SetAllDigitalOutputs && !m_pCommand_SetAllDigitalOutputs->StoreToXMLFile(p_pFile, pElement, oCheckVisibility)) return FALSE;

        //Command Group
        if(m_pCommand_CommandSetInputsPositionMarker && !m_pCommand_CommandSetInputsPositionMarker->StoreToXMLFile(p_pFile, pElement)) return pElement;
    }

    return pElement;
}

void CCommandSetInputsOutputs_VCS_Drive::InitJournalManager(CJournalManagerBase *p_pJournalManager)
{
    if(m_pCommand_DigitalInputConfiguration) m_pCommand_DigitalInputConfiguration->InitJournalManager(p_pJournalManager);
    if(m_pCommand_DigitalOutputConfiguration) m_pCommand_DigitalOutputConfiguration->InitJournalManager(p_pJournalManager);
    if(m_pCommand_GetAllDigitalInputs) m_pCommand_GetAllDigitalInputs->InitJournalManager(p_pJournalManager);
    if(m_pCommand_GetAllDigitalOutputs) m_pCommand_GetAllDigitalOutputs->InitJournalManager(p_pJournalManager);
    if(m_pCommand_GetAnalogInput) m_pCommand_GetAnalogInput->InitJournalManager(p_pJournalManager);
    if(m_pCommand_SetAllDigitalOutputs) m_pCommand_SetAllDigitalOutputs->InitJournalManager(p_pJournalManager);

    if(m_pCommand_CommandSetInputsPositionMarker) m_pCommand_CommandSetInputsPositionMarker->InitJournalManager(p_pJournalManager);
}

void CCommandSetInputsOutputs_VCS_Drive::ResetJournalManager()
{
    if(m_pCommand_DigitalInputConfiguration) m_pCommand_DigitalInputConfiguration->ResetJournalManager();
    if(m_pCommand_DigitalOutputConfiguration) m_pCommand_DigitalOutputConfiguration->ResetJournalManager();
    if(m_pCommand_GetAllDigitalInputs) m_pCommand_GetAllDigitalInputs->ResetJournalManager();
    if(m_pCommand_GetAllDigitalOutputs) m_pCommand_GetAllDigitalOutputs->ResetJournalManager();
    if(m_pCommand_GetAnalogInput) m_pCommand_GetAnalogInput->ResetJournalManager();
    if(m_pCommand_SetAllDigitalOutputs) m_pCommand_SetAllDigitalOutputs->ResetJournalManager();

    if(m_pCommand_CommandSetInputsPositionMarker) m_pCommand_CommandSetInputsPositionMarker->ResetJournalManager();
}

BOOL CCommandSetInputsOutputs_VCS_Drive::InitGateway(CGateway *p_pGateway)
{
    if(m_pCommand_DigitalInputConfiguration && !m_pCommand_DigitalInputConfiguration->InitGateway(p_pGateway)) return FALSE;
    if(m_pCommand_DigitalOutputConfiguration && !m_pCommand_DigitalOutputConfiguration->InitGateway(p_pGateway)) return FALSE;
    if(m_pCommand_GetAllDigitalInputs && !m_pCommand_GetAllDigitalInputs->InitGateway(p_pGateway)) return FALSE;
    if(m_pCommand_GetAllDigitalOutputs && !m_pCommand_GetAllDigitalOutputs->InitGateway(p_pGateway)) return FALSE;
    if(m_pCommand_GetAnalogInput && !m_pCommand_GetAnalogInput->InitGateway(p_pGateway)) return FALSE;
    if(m_pCommand_SetAllDigitalOutputs && !m_pCommand_SetAllDigitalOutputs->InitGateway(p_pGateway)) return FALSE;

    if(m_pCommand_CommandSetInputsPositionMarker && !m_pCommand_CommandSetInputsPositionMarker->InitGateway(p_pGateway)) return FALSE;

    return TRUE;
}

