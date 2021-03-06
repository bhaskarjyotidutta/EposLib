// Command_VCS_DataRecorder.h: Schnittstelle f�r die Klasse CCommand_VCS_DataRecorder.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Command_VCS_DataRecorder_H__9B23BC0A_DD33_499E_B6F6_116AF15BE465__INCLUDED_)
#define AFX_Command_VCS_DataRecorder_H__9B23BC0A_DD33_499E_B6F6_116AF15BE465__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <CommunicationModel/CommonLayer/Classes/Commands/VirtualCommandSet/BaseClasses/Command_VCS.h>
#include "Command_VCS_DataRecorder_Definitions.h"

class CCommand_VCS_DataRecorder : public CCommand_VCS
{
public:
    CCommand_VCS_DataRecorder();
    CCommand_VCS_DataRecorder(DWORD p_ulCommandId);
    virtual ~CCommand_VCS_DataRecorder();

    BOOL InitCommand(DWORD p_ulCommandId);

    CCommand_VCS_DataRecorder& operator=(CCommand_VCS_DataRecorder& other);
    CCommandRoot*CloneCommand();

private:
    BOOL InitCommand_DataRecording(DWORD p_ulCommandId);
	    
    //Data Recorder
    void SetDefaultParameter_SetRecorderParameter();
    void SetDefaultParameter_GetRecorderParameter();
    void SetDefaultParameter_EnableTrigger();
    void SetDefaultParameter_DisableAllTriggers();
    void SetDefaultParameter_ActivateChannel();
    void SetDefaultParameter_DeactivateAllChannels();
    void SetDefaultParameter_StartRecorder();
    void SetDefaultParameter_StopRecorder();
    void SetDefaultParameter_ForceTrigger();
    void SetDefaultParameter_IsRecorderRunning();
    void SetDefaultParameter_IsRecorderTriggered();
    void SetDefaultParameter_ReadChannelVectorSize();
    void SetDefaultParameter_ReadChannelDataVector();
    void SetDefaultParameter_ReadDataBuffer();
    void SetDefaultParameter_ExtractChannelDataVector();
   
};

#endif // !defined(AFX_Command_VCS_DataRecorder_H__9B23BC0A_DD33_499E_B6F6_116AF15BE465__INCLUDED_)
