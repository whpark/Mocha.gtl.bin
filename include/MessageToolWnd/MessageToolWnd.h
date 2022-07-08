#pragma once

#include "AFX_EXT_MESSAGE_TOOL_WND.h"

#include "MIP/MIP.h"
#include "MessageTool.hpp"
#include "MessageWnd.h"
#define TIMER_MOCHA_CONNECT	7979
class CMessageWnd;
class AFX_EXT_API_MESSAGE_TOOL_WND CMessageToolWnd : public CWnd, public IWNDIPCommandTarget {
	friend class CMessageThread;
	DECLARE_DYNCREATE(CMessageToolWnd)

public:
	CMessageToolWnd(CWnd* pwndParent = NULL);							 // protected constructor used by dynamic creation
	virtual					~CMessageToolWnd();

public:
	static TRefPointer<CIPClient> s_rIPClient;

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

protected:
	CWnd* m_pwndParent;
	DECLARE_IP()
	DECLARE_IP_INTERFACE()

	ip_handler BOOL OnIPMessage(CIPCommand& cmd);
	ip_handler BOOL OnIPResponse(CIPCommand& cmd);
	ip_handler BOOL OnIPInput(CIPCommand& cmd);
	ip_handler BOOL OnIPAnimatioin(CIPCommand& cmd);

	void SetMessageData(const CIPVar& var, T_MESSAGE_DATA& tMD);

	TList<CMessageWnd> m_tMessageWnd;
	TList<CMessageWnd> m_tResponseWnd;
	TList<CMessageWnd> m_tInputWnd;
	TList<CMessageWnd> m_tAnimationWnd;
	int	m_iWndCount = 0;
public:
	void Initialize();
	void CalcWndStartPos(CSize& szStart, CSize szWnd, CRect& rect);
};

/*
	- ON_IP("Message", "Message", OnIPMessage) // �ܼ� Message ���.
		var :
			"Width" : int, defaule : 600 -> MessageWnd Width.
			"Height" : int, defaule : 230 -> MessageWnd Height.
			"Title" : CString, default : _T("Title")-> Message SetWindowText;

			"Font" : CString, default : _T("�������") -> Message Font;
			"FontSize" : int, default : 10 -> Message �۾� ũ��;
			"FontWeight" : int, default : 300 -> Message �۾� ����;
			"TextColor" : COLORREF, default : RGB_BLACK -> ���ڻ�;
			"BkColor" : COLORREF, default : GetSysColor(CTLCOLOR_DLG) -> ����
			"PenColor" : COLORREF, default : RGB_BLACK -> ���;

			"Message" : CString, default : _T("Message") -> Message ����.
			"Button" : CString, default : _T("Ok") -> ��ư ����. ex)Ok;Calce �� ���� _T(";")�� ���еǸ� 4������ �Է� ����.
			"Unit" : CString, default : _T("") -> Unit ���� �� ���.
			"Timeout" : int, default : INFINITE -> Message ���� �ð� (msec). ��ư Ŭ���� �ð��� ������� �����.

		varReault : ����.

	- ON_IP("Message", "Response", OnIPResponse) // Message ��� �� ��ư ����.
		var :
			"Width" : int, defaule : 600 -> MessageWnd Width.
			"Height" : int, defaule : 230 -> MessageWnd Height.
			"Title" : CString, default : _T("Title")-> Message SetWindowText;

			"Font" : CString, default : _T("�������") -> Message Font;
			"FontSize" : int, default : 10 -> Message �۾� ũ��;
			"FontWeight" : int, default : 300 -> Message �۾� ����;
			"TextColor" : COLORREF, default : RGB_BLACK -> ���ڻ�;
			"BkColor" : COLORREF, default : GetSysColor(CTLCOLOR_DLG) -> ����
			"PenColor" : COLORREF, default : RGB_BLACK -> ���;

			"Message" : CString, default : _T("Message") -> Message ����.
			"Button" : CString, default : _T("Ok") -> ��ư ����. ex)Ok;Calce �� ���� _T(";")�� ���еǸ� 4������ �Է� ����.
			"Unit" : CString, default : _T("") -> Unit ���� �� ���.
			"Timeout" : int, default : INFINITE -> Message ���� �ð� (msec). ��ư Ŭ���� �ð��� ������� �����.

		varReault : 
			"ButtonResult" : CString, ������ ��ư�� ����.

	- ON_IP("Message", "Input", OnIPInput) // Message ��� �� �Է� �� ���� ����.
		var :
			"Width" : int, defaule : 600 -> MessageWnd Width.
			"Height" : int, defaule : 230 -> MessageWnd Height.
			"Title" : CString, default : _T("Title")-> Message SetWindowText;

			"Font" : CString, default : _T("�������") -> Message Font;
			"FontSize" : int, default : 10 -> Message �۾� ũ��;
			"FontWeight" : int, default : 300 -> Message �۾� ����;
			"TextColor" : COLORREF, default : RGB_BLACK -> ���ڻ�;
			"BkColor" : COLORREF, default : GetSysColor(CTLCOLOR_DLG) -> ����
			"PenColor" : COLORREF, default : RGB_BLACK -> ���;

			"Message" : CString, default : _T("Message") -> Message ����.
			"Button" : CString, default : _T("Ok") -> ��ư ����. ex)Ok;Calce �� ���� _T(";")�� ���еǸ� 4������ �Է� ����. (Input�� ��� 4��° ��ư 1���� ���.)
			"Unit" : CString, default : _T("") -> Unit ���� �� ���.
			"Timeout" : int, default : INFINITE -> Message ���� �ð� (msec). ��ư Ŭ���� �ð��� ������� �����.
			"Password" : BOOL, defalult : FALSE -> �Է� ���� ������ Password�� ǥ���� �� ����.

		varReault :
			"InputResult" : CString, �Է��� ������ Return.\.


	- ON_IP("Message", "Animation", OnIPAnimatioin) // �������� Message�� ���� ���ݸ��� ���� �Ͽ� ���.
		var :
			"Width" : int, defaule : 600 -> MessageWnd Width.
			"Height" : int, defaule : 230 -> MessageWnd Height.
			"Title" : CString, default : _T("Title")-> Message SetWindowText;

			"Font" : CString, default : _T("�������") -> Message Font;
			"FontSize" : int, default : 10 -> Message �۾� ũ��;
			"FontWeight" : int, default : 300 -> Message �۾� ����;
			"TextColor" : COLORREF, default : RGB_BLACK -> ���ڻ�;
			"BkColor" : COLORREF, default : GetSysColor(CTLCOLOR_DLG) -> ����
			"PenColor" : COLORREF, default : RGB_BLACK -> ���;

			"Message" : CString, default : _T("Message") -> Message ����. ex)Message 1;Message 2;Message 3 �� ���� _T(";")�� ���еǸ� �Է� �� ���� * "AnimationInterval" ��ŭ Message�� ������.
			"Button" : CString, default : _T("Ok") -> ��ư ����. ex)Ok;Calce �� ���� _T(";")�� ���еǸ� 4������ �Է� ����. (Input�� ��� 4��° ��ư 1���� ���.)
			"Unit" : CString, default : _T("") -> Unit ���� �� ���.
			"AnimationInterval" : int, default : 1000 msec -> Message���� ���� �ð�.
		varReault : ����.
*/
