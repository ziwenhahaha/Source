
// StudentSystem_BaseOn_Min_Max_HeapDlg.h: 头文件
//

#pragma once
#include"studentInfo.h"
#include"Min_Max_Heap.h"
#include"point.h"
#include"ADD.h"
#include"DIALOG_CHECK.h"
//class student {};
// CStudentSystemBaseOnMinMaxHeapDlg 对话框
class CStudentSystemBaseOnMinMaxHeapDlg : public CDialogEx
{
// 构造
public:
	CStudentSystemBaseOnMinMaxHeapDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENTSYSTEM_BASEON_MIN_MAX_HEAP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	void OnPaint(double x, double y);
	
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int midx=0;
	int midy=0;
	int nowStudentNum=0;
	afx_msg void OnBnClickedButton1();
	CPen m_pen[5];
	CPoint m_point[5];
	int dist=0;
	void CStudentSystemBaseOnMinMaxHeapDlg::DrawLineInit();
	afx_msg void OnBnClickedButton6();

	void printHeap(min_max_heap<student>& Heap);
	void printCell(int posx, int posy, student st);
	void CStudentSystemBaseOnMinMaxHeapDlg::printEach(int left, int right, int height, int x,int prex,int prey);
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton2();
	void show(student st);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	CString m_name;
	CString m_grade;
	student special;
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	point pointset[1050];
	CString m_telephone;
	CEdit m_studentid;
	CString m_birsday;
	CEdit m_birthplace;
	CString m_gender;
	CString m_date;
	CString m_stu;
	ADD* adddialog;
	DIALOG_CHECK* dialog_check;
	afx_msg void OnBnClickedButton8();
};
