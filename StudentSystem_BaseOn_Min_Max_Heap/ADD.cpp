// ADD.cpp: 实现文件
//

#include "pch.h"
#include "StudentSystem_BaseOn_Min_Max_Heap.h"
#include "ADD.h"
#include "afxdialogex.h"


// ADD 对话框

IMPLEMENT_DYNAMIC(ADD, CDialogEx)

ADD::ADD(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD, pParent)
{

}

ADD::~ADD()
{
}

void ADD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(ADD, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ADD::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ADD::OnBnClickedButton2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &ADD::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// ADD 消息处理程序


void ADD::OnBnClickedButton1()
{
	ADD::OnOK();
}


void ADD::OnBnClickedButton2()
{
	ADD::OnCancel();
}
void ADD::add(student st)
{
	this->st = st;



	CString str_name(st.getName());
	this->m_list.InsertItem(0, str_name);

	CString str_telephone(st.getTelephone());
	m_list.SetItemText(0, 1, str_telephone);
	
	CString str_studentid(st.getStudentId());
	m_list.SetItemText(0, 2, str_studentid);

	CString str_birthday(st.getBirthDate());
	m_list.SetItemText(0, 3, str_birthday);

	CString str_birthplace(st.getBirthPlace());
	m_list.SetItemText(0, 4, str_birthplace);

	CString str_gender(st.getGender());
	m_list.SetItemText(0, 5, str_gender);

	CString str_grade;
	str_grade.Format(_T("%d"), st.getGrade());
	m_list.SetItemText(0, 6, str_grade);

	UpdateData(false);
}

INT_PTR ADD::DoModal()
{
	// TODO: 在此添加专用代码和/或调用基类
	return CDialogEx::DoModal();
}


BOOL ADD::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect rect;
	m_list.GetClientRect(&rect);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	int width = rect.Width() / 7;
	m_list.InsertColumn(0, _T("姓名"), LVCFMT_CENTER, width);
	m_list.InsertColumn(1, _T("手机"), LVCFMT_CENTER, width);
	m_list.InsertColumn(2, _T("学号"), LVCFMT_CENTER, width);
	m_list.InsertColumn(3, _T("生日"), LVCFMT_CENTER, width);
	m_list.InsertColumn(4, _T("出生地"), LVCFMT_CENTER, width);
	m_list.InsertColumn(5, _T("性别"), LVCFMT_CENTER, width);
	m_list.InsertColumn(6, _T("成绩"), LVCFMT_CENTER, width);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ADD::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
