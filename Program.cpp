/*
    Creating Popup Menu In Client Window
*/

#include<afxwin.h>

class MyFrame:public CFrameWnd
{
public:
		MyFrame()
		{
			Create(0,"Context Menu");
		}
		void OnContextMenu(CWnd *pwnd,CPoint pt)
		{
			CRect r;
			GetClientRect(&r);

			if(r.PtInRect(pt))
			{
				CMenu mymenu;
				mymenu.CreatePopupMenu();
				mymenu.AppendMenu(MF_STRING,101,"&Line");
				mymenu.AppendMenu(MF_STRING,102,"&Rectangle");
				mymenu.AppendMenu(MF_STRING,103,"&Triangle");
				mymenu.AppendMenu(MF_STRING,104,"&Circle");
				
				mymenu.TrackPopupMenu(TPM_CENTERALIGN|
					TPM_LEFTALIGN|TPM_TOPALIGN|TPM_BOTTOMALIGN|TPM_VCENTERALIGN,
					pt.x,pt.y,pwnd,0);

			}
			CFrameWnd::OnContextMenu(pwnd,pt);
		}
		
		void draw(UINT id)
		{
			 switch(id)
			 {
			 
				 case 101:
						MessageBox("draw line","LINE",0);
						break;
				 case 102:
						MessageBox("Draws Rectangle");
						break;
			     case 103:
						MessageBox("Draws Triangle");
						break;
			      case 104:
						MessageBox("Draws Circle");
						break;
			 }
		}
			 
	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(MyFrame,CFrameWnd)
ON_WM_CONTEXTMENU()
ON_COMMAND_RANGE(101,104,draw)
END_MESSAGE_MAP()

class MyApp:public CWinApp
{
public:
		int InitInstance()
		{
			MyFrame *ptr;
			ptr=new MyFrame();
			m_pMainWnd=ptr;
			ptr->ShowWindow(1);
			return 1;
		}
};
MyApp Obj;
