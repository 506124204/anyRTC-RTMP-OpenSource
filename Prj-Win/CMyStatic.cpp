#include "CMyStatic.h"



CMyStatic::CMyStatic()
{
}


CMyStatic::~CMyStatic()
{
}
BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	ON_WM_SIZE()
END_MESSAGE_MAP()


void CMyStatic::OnSize(UINT nType, int cx, int cy)
{
	CStatic::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
}
