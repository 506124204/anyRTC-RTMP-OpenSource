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
	//ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()


void CMyStatic::OnSize(UINT nType, int cx, int cy)
{
	CStatic::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
}


BOOL CMyStatic::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CBrush brush(RGB(255, 255, 255));
	CBrush *pOldBrush = pDC->SelectObject(&brush);

	CRect rect;
	GetClientRect(&rect);

	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOldBrush);

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
