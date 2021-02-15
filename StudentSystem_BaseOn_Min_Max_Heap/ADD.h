#pragma once


// ADD 对话框
#include "studentInfo.h"
#include "CMyListCtrl.h"
class ADD : public CDialogEx
{
	DECLARE_DYNAMIC(ADD)

public:
	ADD(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ADD();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	void add(student);
	student st;
	virtual INT_PTR DoModal();
	virtual BOOL OnInitDialog();
	CMyListCtrl m_list;
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
};
