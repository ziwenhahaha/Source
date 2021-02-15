// DIALOG_CHECK.cpp: 实现文件
//
#pragma GCC optimize(2)
#include "pch.h"
#include "StudentSystem_BaseOn_Min_Max_Heap.h"
#include "DIALOG_CHECK.h"
#include "afxdialogex.h"


// DIALOG_CHECK 对话框

IMPLEMENT_DYNAMIC(DIALOG_CHECK, CDialogEx)

DIALOG_CHECK::DIALOG_CHECK(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CHECK, pParent)
{

}

DIALOG_CHECK::~DIALOG_CHECK()
{
}

void DIALOG_CHECK::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(DIALOG_CHECK, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &DIALOG_CHECK::OnBnClickedButton2)
END_MESSAGE_MAP()


// DIALOG_CHECK 消息处理程序

#include<set>
#include<vector>
#include<cstdlib>
#include<time.h>
#include"studentInfo.h"
#include"Min_Max_Heap.h"
using namespace std;
int arr[400500];
set<student> st;
min_max_heap<student> tHeap;
long long Baoli(int n)
{
	clock_t start, finish;
	long long totaltime;
	start = clock();
	vector<student> v;
	student stu;
	for (int i = 0; i < n; i++) {
		stu.setName("000");
		stu.setGrade(arr[i]);
		v.push_back(stu);
		student minn, maxx;
		minn.setName("000");
		minn.setGrade((int)1e8);
		maxx.setName("000");
		maxx.setGrade(0);
		for (int j = 0; j < i; j++)
		{
			if (maxx < v[j]) maxx = v[j];
			if (v[j] < minn) minn = v[j];
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		student minn, maxx;
		vector<student> ::iterator index_minn, index_maxx;
		minn.setName("000");
		minn.setGrade((int)1e8 + 5);

		maxx.setName("000");
		maxx.setGrade(0);

		vector<student> ::iterator it;
		for (it = v.begin(); it != v.end(); it++)
		{
			if (maxx < *it)  maxx = *it, index_maxx = it;
			if (*it < minn) minn = *it, index_minn = it;
		}
		if (i % 2 == 1) { //弹出最小值
			v.erase(index_minn);
		}
		else {
			v.erase(index_maxx);
		}

		minn.setName("000");
		minn.setGrade((int)1e8 + 5);

		maxx.setName("000");
		maxx.setGrade(0);
		for (it = v.begin(); it != v.end(); it++)
		{
			if (maxx < *it)  maxx = *it, index_maxx = it;
			if (*it < minn) minn = *it, index_minn = it;
		}
	}

	finish = clock();
	totaltime = (finish - start);
	return totaltime;
}

long long setting(int n) {

	st.clear();
	clock_t start, finish;
	long long totaltime;
	start = clock();


	student temp;
	for (int i = 0; i < n; i++)
	{
		temp.setName("000");
		temp.setGrade(arr[i]);
		st.insert(temp);

		student minn, maxx;
		minn = *st.begin();
		maxx = *st.rbegin();
	}
	set<student>::iterator ip;
	for (int i = n - 1; i >= 2; i--)
	{
		if (st.empty()) break;
		if (i % 2 == 1) {
			st.erase(st.begin());
		}
		else {
			ip = st.end();
			st.erase(--ip);
		}
		if (st.empty()) break;
		student minn, maxx;
		minn = *st.begin();
		maxx = *st.rbegin();
	}

	finish = clock();
	totaltime = (long long)(finish - start);
	return totaltime;
}

long long test_Heap(int n)
{
	clock_t start, finish;
	long long totaltime;
	start = clock();
	while (!tHeap.empty()) tHeap.popMax();
	student temp;
	for (int i = 0; i < n; i++)
	{
		temp.setName("000");
		temp.setGrade(arr[i]);
		tHeap.insert(temp);
		student minn, maxx;
		minn = tHeap.getMin();
		maxx = tHeap.getMax();
	}
	for (int i = n - 1; i >= 1; i--)
	{
		if (tHeap.empty()) break;
		if (i % 2 == 1) {
			tHeap.popMin();
		}
		else {
			tHeap.popMax();
		}
		student minn, maxx;
		minn = tHeap.getMin();
		maxx = tHeap.getMax();
	}
	finish = clock();
	totaltime = (finish - start);
	return totaltime;
}
void DIALOG_CHECK::run()
{
	int a[] = { 5,10,50,100,500,1000,5000,10000,20000,50000,100000,200000,400000 };

	srand(time(NULL));
	for (int i = 0; i <= 400020; i++)
		arr[i] = rand() % ((int)(1e8));

	for (int i = 0; i < 7; i++)
	{
		long long time_baoli = Baoli(a[i]);
		long long time_set = setting(a[i]);
		long long time_Heap = test_Heap(a[i]);
		CString cstr0,cstr1, cstr2, cstr3;
		cstr0.Format(_T("%d"), a[i]);
		cstr1.Format(_T("%lld"), time_baoli);
		cstr2.Format(_T("%lld"), time_set);
		cstr3.Format(_T("%lld"), time_Heap);

		m_list.InsertItem(i, cstr0);
		m_list.SetItemText(i, 1, cstr1);
		m_list.SetItemText(i, 2, cstr2);
		m_list.SetItemText(i, 3, cstr3);

		
	}
	for (int i = 7; i < 13; i++)
	{
		//long long time_baoli = Baoli(a[i]);
		long long time_set = setting(a[i]);
		long long time_Heap = test_Heap(a[i]);
		CString cstr0, cstr1, cstr2, cstr3;
		cstr0.Format(_T("%d"), a[i]);
		cstr1.Format(_T("∞"));
		cstr2.Format(_T("%lld"), time_set);
		cstr3.Format(_T("%lld"), time_Heap);

		m_list.InsertItem(i, cstr0);
		m_list.SetItemText(i, 1, cstr1);
		m_list.SetItemText(i, 2, cstr2);
		m_list.SetItemText(i, 3, cstr3);

	}
	UpdateData(false);
}


void DIALOG_CHECK::OnBnClickedButton2()
{
	DIALOG_CHECK::OnOK();
}


BOOL DIALOG_CHECK::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect rect;
	m_list.GetClientRect(&rect);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	int width = rect.Width() / 5;
	m_list.InsertColumn(0, _T("数据量"), LVCFMT_CENTER, width);
	m_list.InsertColumn(1, _T("暴力写法"), LVCFMT_CENTER, width);
	m_list.InsertColumn(2, _T("STL的set"), LVCFMT_CENTER, width);
	m_list.InsertColumn(3, _T("自己写的min_max_Heap"), LVCFMT_CENTER, width*2);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
