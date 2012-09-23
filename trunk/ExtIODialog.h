#pragma once
#include "LayeredWindowHelperST\LayeredWindowHelperST.h"
#include "SelectComPort\ComPortCombo.h"
#include "ExtIODialogClasses.h"

// CExtIODialog dialog

#define ID_CLOCK_TIMER	1

class CExtIODialog : public CDialog
{
	DECLARE_DYNAMIC(CExtIODialog)

public:
	CExtIODialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CExtIODialog();

	void ChangeMode(unsigned long lofreq, unsigned long tunefreq);

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	// Generated message map functions
	//{{AFX_MSG(CGenericMFCDlg)
	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
	afx_msg void OnClose();
	afx_msg BOOL OnDeviceChange(UINT nEventType, DWORD_PTR dwData);
	//}}AFX_MSG

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	CComPortCombo m_comboPorts;
	CGainSliderCHA m_GainSliderA;
	CGainSliderCHB m_GainSliderB;
	CPhaseSliderCoarse m_PhaseSliderCoarse;
	CPhaseSliderFine m_PhaseSliderFine;
	CCheckBoxDiversity m_DiversityCheck;
	CCheckBoxSyncGain m_SyncGainCheck;
	CCheckBoxSyncTune m_SyncTuneCheck;
	CPhaseInfo m_PhaseInfo;
	CTransparencySlider m_TransparencySlider;
	CCheckBoxDllIQ m_DllIQ;	
	CDataRateInfo m_DataRateInfo;
	CCheckBoxDebugConsole m_DebugConsoleCheck;
	
	DECLARE_MESSAGE_MAP()

public:
	int m_nChannelMode;
	afx_msg void OnBnClickedOk();

private:
	CLayeredWindowHelperST	m_Layered;

public:
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBnClickedRadioCmode1();
	afx_msg void OnBnClickedRadioCmode2();
	afx_msg void OnBnClickedRadioCmode3();
	afx_msg void OnBnClickedRadioCmode4();
	afx_msg void OnBnClickedRadioCmode5();
};
