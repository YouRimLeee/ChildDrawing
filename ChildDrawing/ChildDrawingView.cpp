
// ChildDrawingView.cpp: CChildDrawingView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ChildDrawing.h"
#endif

#include "ChildDrawingDoc.h"
#include "ChildDrawingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildDrawingView

IMPLEMENT_DYNCREATE(CChildDrawingView, CView)

BEGIN_MESSAGE_MAP(CChildDrawingView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CChildDrawingView 생성/소멸

CChildDrawingView::CChildDrawingView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CChildDrawingView::~CChildDrawingView()
{
}

BOOL CChildDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CChildDrawingView 그리기

void CChildDrawingView::OnDraw(CDC* pDC)
{
	CChildDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(500, 10, L"어린이용 도형, 색깔 공부");

	pDC->Rectangle(20, 60, 300, 210);

	pDC->TextOutW(330, 110, L"이 도형은 직사각형이에요");
	pDC->TextOutW(330, 130, L"직사각형은 4개의 선분으로 이루어진 도형이에요^^");
	pDC->Ellipse(50, 240, 250, 430);
	pDC->TextOutW(330, 300, L"이 도형은 원이에요");
	pDC->TextOutW(330, 320, L"원은 둥글게 그려진 모양이에요^^");

	pDC->Rectangle(m_ptLeftTop.x, m_ptLeftTop.y, m_ptRightBottom.x, m_ptRightBottom.y);
	CBrush brush;
	brush.CreateSolidBrush(RGB(0, 0, 255));
	pDC->SelectObject(&brush);
	pDC->Rectangle(20, 450, 300, 580);
	brush.DeleteObject();
	pDC->TextOutW(330, 510, L"이 색은 파란색이에요^^");
	CBrush brush1;
	brush1.CreateSolidBrush(RGB(0, 255, 0));
	pDC->SelectObject(&brush1);
	pDC->Rectangle(20, 630, 300, 760);
	brush1.DeleteObject();
	pDC->TextOutW(330, 690, L"이 색은 초록색이에요^^");
	CBrush brush2;
	brush2.CreateSolidBrush(RGB(255, 0, 0));
	pDC->SelectObject(&brush2);
	pDC->Rectangle(20, 800, 300, 930);
	pDC->TextOutW(330, 860, L"이 색은 빨간색이에요^^");

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CChildDrawingView 인쇄

BOOL CChildDrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CChildDrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CChildDrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CChildDrawingView 진단

#ifdef _DEBUG
void CChildDrawingView::AssertValid() const
{
	CView::AssertValid();
}

void CChildDrawingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChildDrawingDoc* CChildDrawingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChildDrawingDoc)));
	return (CChildDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CChildDrawingView 메시지 처리기


void CChildDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonDown(nFlags, point);
}


void CChildDrawingView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonUp(nFlags, point);
}


void CChildDrawingView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnMouseMove(nFlags, point);
}
