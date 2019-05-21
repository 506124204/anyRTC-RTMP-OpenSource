#include "CMyStaticHis.h"



extern int gLiving;

CMyStaticHis::CMyStaticHis() :mLiving(0) {
	brush.CreateSolidBrush(RGB(255, 255, 255));
}


CMyStaticHis::~CMyStaticHis() {
}
BEGIN_MESSAGE_MAP(CMyStaticHis, CStatic)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CMyStaticHis::OnSize(UINT nType, int cx, int cy) {
	CStatic::OnSize(nType, cx, cy);
	Invalidate();
}


BOOL CMyStaticHis::OnEraseBkgnd(CDC* pDC) {
	return FALSE;
	return CStatic::OnEraseBkgnd(pDC);
}

void CMyStaticHis::OnPaint() {
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()
	CRect rc;
	GetClientRect(rc);
	dc.FillSolidRect(rc, RGB(0, 0, 0));
	CString strMsg = "";

	if (mLiving == 0) {
		strMsg = "��Ƶ���ڻ�����...���Ժ�...";
	}
	else if (mLiving == 1) {
		strMsg = "��Ƶ���ڻ�����...���Ժ�...";
	}
	else if (mLiving == 2) {
		strMsg = "��Ƶ���Ž�����";
	}
	else if (mLiving == 3) {
		strMsg = "��Ƶ���ڻ�����...���Ժ�...";
	}
	else if (mLiving == 4) {
		strMsg = "��Ƶ���ڻ�����...���Ժ�...";
	}
	else if (mLiving == 99) {
		strMsg = "ֱ�������У��������ϳ���...";
	}
	COLORREF clr = dc.SetTextColor(RGB(255, 0, 0));
	dc.DrawText(strMsg, rc, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	dc.SetTextColor(clr);

}


void CMyStaticHis::SetLiving(int living) {
	mLiving = living;
	Invalidate();
}


int CMyStaticHis::GetLiving() {
	return mLiving;
}
