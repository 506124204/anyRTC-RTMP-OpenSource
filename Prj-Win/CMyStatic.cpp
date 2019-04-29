#include "CMyStatic.h"

extern int gLiving;

CMyStatic::CMyStatic():mLiving(0){
	brush.CreateSolidBrush(RGB(255, 255, 255));
}


CMyStatic::~CMyStatic(){
}
BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CMyStatic::OnSize(UINT nType, int cx, int cy){
	CStatic::OnSize(nType, cx, cy);
	Invalidate();
}


BOOL CMyStatic::OnEraseBkgnd(CDC* pDC){
	return FALSE;
	return CStatic::OnEraseBkgnd(pDC);
}

void CMyStatic::OnPaint(){
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()
	CRect rc;
	GetClientRect(rc);
	dc.FillSolidRect(rc, RGB(0, 0, 0));
	CString strMsg = "";
	
	if (mLiving == 0) {
		strMsg = "��������ֱ��������,���Ժ�...";
	}else if(mLiving == 1) {
		strMsg = "���ڲ�ѯƵ���Ƿ�ʼֱ�������Ժ�...";
	}else if (mLiving == 2) {
		strMsg = "ֱ�����������������տ����ھ���ֱ��¼��";
	}else if (mLiving == 3) {
		strMsg = "Ŀǰ����ֱ�����������տ����ھ���ֱ��¼��";
	}else if (mLiving == 4) {
		strMsg = "Ŀǰ����ֱ�����������տ����ھ���ֱ��¼��";
	}else if (mLiving == 99) {
		strMsg = "ֱ�������У��������ϳ���...";
	}
	COLORREF clr = dc.SetTextColor(RGB(255, 0, 0));
	dc.DrawText(strMsg, rc, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	dc.SetTextColor(clr);

}


void CMyStatic::SetLiving(int living){
	mLiving = living;
	Invalidate();
}


int CMyStatic::GetLiving(){
	return mLiving;
}
