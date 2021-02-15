
// StudentSystem_BaseOn_Min_Max_HeapDlg.cpp: 实现文件
//
#pragma GCC optimize(2)
#pragma warning(disable:4996)
#pragma once
#include "framework.h"
#include "Min_Max_Heap.h"
#include "StudentSystem_BaseOn_Min_Max_Heap.h"
#include "StudentSystem_BaseOn_Min_Max_HeapDlg.h"
#include "afxdialogex.h"
#include "studentInfo.h"
#include "ADD.h"
#include "locale.h"
#include <fstream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

min_max_heap<student> Heap;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStudentSystemBaseOnMinMaxHeapDlg 对话框



CStudentSystemBaseOnMinMaxHeapDlg::CStudentSystemBaseOnMinMaxHeapDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENTSYSTEM_BASEON_MIN_MAX_HEAP_DIALOG, pParent)
	, m_name(_T(""))
	, m_grade(_T(""))
	, m_telephone(_T(""))
	, m_birsday(_T(""))
	, m_gender(_T(""))
	, m_date(_T(""))
	, m_stu(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentSystemBaseOnMinMaxHeapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_grade);
	DDX_Text(pDX, IDC_EDIT8, m_telephone);
	DDX_Control(pDX, IDC_EDIT9, m_studentid);
	DDX_Text(pDX, IDC_EDIT10, m_birsday);
	DDX_Control(pDX, IDC_EDIT11, m_birthplace);
	DDX_Text(pDX, IDC_EDIT12, m_gender);
	DDX_Text(pDX, IDC_EDIT11, m_date);
	DDX_Text(pDX, IDC_EDIT9, m_stu);
}

BEGIN_MESSAGE_MAP(CStudentSystemBaseOnMinMaxHeapDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON2, &CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton5)
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_BUTTON8, &CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CStudentSystemBaseOnMinMaxHeapDlg 消息处理程序

BOOL CStudentSystemBaseOnMinMaxHeapDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	setlocale(LC_CTYPE, "chs");
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	CRect rect;
	GetClientRect(&rect);
	DrawLineInit();
	CRect rc;
	CWnd* pWnd = GetDlgItem(IDC_STATIC);//参数为控件ID
	pWnd->GetWindowRect(&rc);//rc为控件的大小。
	ScreenToClient(&rc);
	int x = rc.left + rc.Width() / 2;
	int y = rc.top + rc.Height() / 2;
	midx = x;
	midy = y;


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CStudentSystemBaseOnMinMaxHeapDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。
void CStudentSystemBaseOnMinMaxHeapDlg::DrawLineInit()
{

	//初始化画笔、点变量数组
	m_pen[0].CreatePen(PS_SOLID, 1, RGB(0, 0, 0));     //黑色实线，1像素宽---参数：样式、宽度、颜色
	m_pen[1].CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); //红色实线，1像素宽
	m_pen[2].CreatePen(PS_DASH, 1, RGB(255, 0, 0));      //红色虚线，必须为一个像素宽
	m_pen[3].CreatePen(PS_DOT, 1, RGB(0, 0, 255));       //蓝色点线，必须为一个像素宽
	m_pen[4].CreatePen(PS_SOLID, 1, RGB(255, 255, 255));//红色双点虚线，必须为一个像素宽


	//绘制多边形的点数组
	m_point[0].x = 10;
	m_point[0].y = 100;
	m_point[1].x = 10;
	m_point[1].y = 120;
	m_point[2].x = 100;
	m_point[2].y = 105;
	m_point[3].x = 170;
	m_point[3].y = 120;
	m_point[4].x = 170;
	m_point[4].y = 100;

}

void CStudentSystemBaseOnMinMaxHeapDlg::OnPaint()
{

	dist = 15;
	CClientDC dc(this); // 用于绘制的设备上下文

	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CStudentSystemBaseOnMinMaxHeapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#include<string>

using namespace std;
void CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton1()
{
	UpdateData(true);
	if (m_name.GetLength() == 0 || m_grade.GetLength() == 0)
	{
		MessageBox(_T("名字和成绩不能为空"));
		return;
	}

	char buf[100] = {};
	student temp;
	int n = _ttoi(m_grade);

	string stra = CStringA(m_name);
	strncpy_s(buf, _countof(buf), stra.c_str(), m_name.GetLength());
	temp.setName( buf );
	

	if (m_date.GetLength() == 0) {
		temp.setBirthPlace("0");
	}
	else
	{
		string stra = CStringA(m_date);
		strncpy_s(buf, _countof(buf), stra.c_str(), m_date.GetLength());
		temp.setBirthPlace(buf);
	}
	
	
	if (m_stu.GetLength() == 0)
	{
		temp.setStudentId("0");
	}
	else
	{
		string stra = CStringA(m_stu);
		strncpy_s(buf, _countof(buf), stra.c_str(), m_stu.GetLength());
		temp.setStudentId(buf);
	}

	if (m_birsday.GetLength() == 0)
	{
		temp.setBirthDate("0");
	}else{
		string stra = CStringA(m_birsday);
		strncpy_s(buf, _countof(buf), stra.c_str(), m_birsday.GetLength());
		temp.setBirthDate(buf);
	}

	if(m_telephone.GetLength()==0)
		temp.setTelephone("0");
	else {
		string stra = CStringA(m_telephone);
		strncpy_s(buf, _countof(buf), stra.c_str(), m_telephone.GetLength());
		temp.setTelephone(buf);
	}

	temp.setGrade(n);

	if (m_gender.GetLength() == 0)
		temp.setGender("男");
	else {
		string stra = CStringA(m_gender);
		strncpy_s(buf, _countof(buf), stra.c_str(), m_gender.GetLength());
		temp.setGender(buf);
	}


	Invalidate(1);
	UpdateWindow();

	special = temp;
	Heap.insert(temp);
	printHeap(Heap);
}

void CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton6() //文件读入
{
	/*fstream file;
	file.open("StudentInfo.dat", ios::app | ios::out | ios::in);
	 
	file >> nowStudentNum;*/
	(int)freopen("StudentInfo.dat", "r", stdin);
	cin >> nowStudentNum;
	student temp;
	for (int i = 0; i < nowStudentNum; i++) {
		temp.read();
		Heap.insert(temp);
		special = temp;
		printHeap(Heap);
		Sleep(1000);
	}
	fclose(stdin);
	CString str;
	str.Format(_T("%d"), nowStudentNum);
	//MessageBox( str );

	//printCell(midx, midy, Heap.getMax());
	printHeap(Heap);
}



void CStudentSystemBaseOnMinMaxHeapDlg::printCell(int posx,int posy,student st)
{

	#define Old 0
	#define New 1
	CClientDC dc(this);
	CBrush brush(RGB(255, 255, 255));//画刷
	dc.SelectObject(& brush);
	CPen* oldPen;
	if (st == special)
	{
		oldPen=dc.SelectObject(&m_pen[1]);
	}
	else
	{
		oldPen=dc.SelectObject(&m_pen[Old]);
	}


	CString strText;


	char ch[100];
	strcpy(ch, st.getName());
	CString cstr(ch);
	strText.Format(_T("%s:%d"),cstr,st.getGrade());
	int height = 50;//纵坐标
	int weight = (int)strText.GetLength()*7;//横

	dc.Rectangle(posx- weight /2-5, posy-5, posx + weight / 2+10, posy + height / 2 );
	int length = strText.GetLength();
	dc.TextOut((int)posx - length * 3.2-2, (int)posy, strText);

	dc.SelectObject(oldPen);       //回复DC原画笔
}


void CStudentSystemBaseOnMinMaxHeapDlg::printEach(int left,int right,int height,int x, int prex, int prey)
{
	CClientDC dc(this);

	int mid = (left + right) / 2;

	dc.MoveTo(prex, prey+25);
	dc.LineTo(mid, height); //划线

	pointset[x].x = mid;
	pointset[x].y = height;

	printCell( mid , height, Heap.heap[x]);
	int shangxia = 50;
	if (x * 2 <= Heap.length)
	{
		printEach(left, mid , height*1.6, x*2, mid,height);
	}
	if (x *2+1 <= Heap.length)
	{
		printEach(mid, right, height * 1.6, x*2+1, mid, height);
	}
}
void CStudentSystemBaseOnMinMaxHeapDlg::printHeap(min_max_heap<student> &Heap)
{
	Invalidate(1);
	UpdateWindow();
	int posx, posy;
	posx = 5;
	posy = 20;
	if (!Heap.empty())
	{
		pointset[1].x = midx;
		pointset[1].y = 20;
		printCell(midx, 20, Heap.getMin());
		if (2 <= Heap.length)
			printEach(5,midx, 100,2,midx, posy);
		if (3 <= Heap.length)
			printEach(midx, midx * 2,100,3,midx, posy);
	}
}

void CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton7()
{
	freopen("StudentInfo.dat", "w", stdout);

	CString cstr("保存成功");
	MessageBox(cstr);

	cout << Heap.length << endl;

	for (int i = 1; i <= Heap.length; i++) {
		Heap.heap[i].write();
	}

	fclose(stdout);
}



void CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton2()//最大值
{
	// TODO: 在此添加控件通知处理程序代码
	if (!Heap.empty())
		show(Heap.getMax());
	else MessageBox(_T("系统现在没有人哦"));
}

void CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!Heap.empty())
		show(Heap.getMin());
	else MessageBox(_T("系统现在没有人哦"));
}

void CStudentSystemBaseOnMinMaxHeapDlg::show(student st)
{
	
	adddialog = new ADD();
	adddialog->Create(IDD_DIALOG_ADD);
	adddialog->add(st);
	adddialog->ShowWindow(SW_NORMAL);
	//

	/*char ch[100];
	strcpy(ch, st.getName());
	strcat(ch, " ");
	strcat(ch, st.getTelephone());
	strcat(ch, " ");
	strcat(ch, st.getStudentId());
	strcat(ch, " ");
	strcat(ch, st.getBirthDate());
	strcat(ch, " ");
	strcat(ch, st.getBirthPlace());
	strcat(ch, " ");
	strcat(ch, st.getGender());
	CString cstr(ch);


	cstr.Format(_T("%s %d"),cstr,st.getGrade());
	MessageBox(cstr);*/
}



void CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton4()
{
	if (!Heap.empty())
	{
		Invalidate(1);
		UpdateWindow();

		special = Heap.getMax();
		printHeap(Heap);
		Sleep(1000);

		Invalidate(1);
		UpdateWindow();

		Heap.popMax();
		printHeap(Heap);
	}
	else {
		MessageBox(_T("系统现在没有人哦"));
		return;
	}
}


void CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton5()
{
	if (!Heap.empty())
	{
		Invalidate(1);
		UpdateWindow();

		special = Heap.getMin();
		printHeap(Heap);
		Sleep(1000);

		Invalidate(1);
		UpdateWindow();

		Heap.popMin();
		printHeap(Heap);
	}
	else {
		MessageBox(_T("系统现在没有人哦"));
	}
}


void CStudentSystemBaseOnMinMaxHeapDlg::OnLButtonDblClk(UINT nFlags, CPoint p)  //处理双击
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnLButtonDblClk(nFlags, p);
	#define dist(p1,p2) sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)) 
	for (int i = 1; i <= Heap.length; i++)
	{
		if (dist(p, pointset[i]) < 50) {
			show(Heap.heap[i]);
			return;
		}
	}

}


void CStudentSystemBaseOnMinMaxHeapDlg::OnBnClickedButton8()
{
	MessageBox(_T("请大概等待十秒钟"));
	dialog_check = new DIALOG_CHECK();
	dialog_check->Create(IDD_DIALOG_CHECK);
	dialog_check->run();
	dialog_check->ShowWindow(SW_NORMAL);
}
