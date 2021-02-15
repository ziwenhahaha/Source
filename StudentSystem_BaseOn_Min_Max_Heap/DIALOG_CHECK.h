#pragma once


// DIALOG_CHECK 对话框

class DIALOG_CHECK : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_CHECK)

public:
	DIALOG_CHECK(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DIALOG_CHECK();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHECK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	void run();
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
};
