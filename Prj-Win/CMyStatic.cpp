#include "CMyStatic.h"



CMyStatic::CMyStatic()
{
	brush.CreateSolidBrush(RGB(255, 255, 255));
}


CMyStatic::~CMyStatic()
{
}
BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	//ON_WM_CTLCOLOR_REFLECT()
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CMyStatic::OnSize(UINT nType, int cx, int cy)
{
	CStatic::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
}


BOOL CMyStatic::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*
	CBrush brush(RGB(255, 255, 255));
	CBrush *pOldBrush = pDC->SelectObject(&brush);

	CRect rect;
	GetClientRect(&rect);

	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOldBrush);
	*/

	return TRUE;


	return CStatic::OnEraseBkgnd(pDC);
}


HBRUSH CMyStatic::CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/)
{
	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
	
	return (HBRUSH)brush.GetSafeHandle();
	return NULL;
}


void CMyStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()
	CRect rc;
	GetClientRect(rc);

	CPen p;
	p.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	dc.MoveTo(0, 0);
	dc.LineTo(100, 100);
	dc.FillSolidRect(rc, RGB(0, 0, 0));
}
