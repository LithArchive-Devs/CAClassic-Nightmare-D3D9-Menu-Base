/*************************************/
/* => Credits <=
/* mo3ad001 
/* Gordon` & Hans 
/* Azorbix
/* We11ington
/* ChaosMagican
/* Nightmare - > updated Menu Base.
/**************************************/

#include "Menu.h"

cMenu Menu;

bool flag;

#define STRING_DirectX /*DirectX*/Main.Decrypt("q–Ÿ’¡…")
#define STRING_Weapon /*Weapon*/Main.Decrypt("„’Žœ›")
#define STRING_Misc /*Misc*/Main.Decrypt("z– ")
#define STRING_Nothing /*Nothing*/Main.Decrypt("{œ¡•–›”")
#define STRING_SatChams /*SatChams*/Main.Decrypt("€Ž¡p•Žš ")
#define STRING_FullBright /*FullBright*/Main.Decrypt("s¢™™oŸ–”•¡")
#define STRING_NoFog /*NoFog*/Main.Decrypt("{œsœ”")
#define STRING_WireFrame /*WireFrame*/Main.Decrypt("„–Ÿ’sŸŽš’")
#define STRING_PlayerxWireFrame /*Player WireFrame*/Main.Decrypt("}™Ž¦’ŸM„–Ÿ’sŸŽš’")
#define STRING_NoFlash /*NoFlash*/Main.Decrypt("{œs™Ž •")
#define STRING_Glow /*Glow*/Main.Decrypt("t™œ¤")
#define STRING_NoSpread /*NoSpread*/Main.Decrypt("{œ€Ÿ’Ž‘")
#define STRING_PickUp /*PickUp*/Main.Decrypt("}–˜‚")
#define STRING_SuperJump /*SuperJump*/Main.Decrypt("€¢’Ÿw¢š")
#define STRING_ShowFps /*ShowFps*/Main.Decrypt("€•œ¤s ")
#define BeastMode ("Beast")

void cMenu::AddCheck (char* Name ,int x, int y , int h , int w , LPDIRECT3DDEVICE9 pDevice , int Tab)
{
	++MenuSt.NumberOfItems;

	if(CheckBox[Tab][0].State)
	{

		if(Menu.MouseClick( x , y ,h ,w + 8 * strlen( Name ) , MenuSt.NumberOfItems ,Tab ))
			CheckBox [Tab] [ MenuSt.NumberOfItems ].State = !CheckBox [Tab][ MenuSt.NumberOfItems ].State ;

		Menu.DrawBox( x ,y , w ,h ,1, 0xFFF6FFDD, 0xFF000000,0xFFFFFFFF,pDevice);
		Main.DrawString( x + w + 3 , y , 0xFF000000 , Main.pFont ,Name);

		if(CheckBox[Tab] [ MenuSt.NumberOfItems ].State)
			Main.DrawString( x + 2 , y - 2 , 0xFF0000FF , Main.pFont ,"X");
	}
}

void cMenu::AddTab(char* Name ,int x, int y , int h , int w , LPDIRECT3DDEVICE9 pDevice)
{
	if(Menu.MouseClick( x , y ,h ,w , 0, MenuSt.NumberOfTabs ))
	{
		for(int i = 0 ; i < 4 ; i++)
			CheckBox[i][0].State = false;
		CheckBox[ MenuSt.NumberOfTabs ][0].State = true ;
	}

	if(CheckBox[ MenuSt.NumberOfTabs ][0].State)
		Menu.DrawBox( x ,y , w ,h , 1,0xFF787878, 0xFF000000,0xFFFFFFFF,pDevice);
	else
		Menu.DrawBox( x ,y , w ,h ,1,0xFF959595, 0xFFFFFFFF, 0xFF000000,pDevice);

	Main.DrawString( x + 3 , y + 3 , 0xFF000000 , Main.pFont ,Name);

	MenuSt.NumberOfTabs ++;
}

void cMenu::Render(LPDIRECT3DDEVICE9 pDevice)
{
	if(!MenuSt.Load)
	{
		MenuSt.x = 100;
		MenuSt.y = 100;
		Menu.CheckBox[0][0].State = true; // Show Fist Tab .
		MenuSt.Load = true;
	}

	if( GetAsyncKeyState( VK_INSERT )&1)
		MenuSt.IsVisble = !MenuSt.IsVisble;
	
	if(MenuSt.IsVisble)
	{
		Menu.StyleRender (pDevice);// Style

		/////////////////////////////////////////////////////////////////////////////////////
		/*		Tabs		*/
		AddTab(STRING_DirectX,	Menu.MenuSt.x + 10		, Menu.MenuSt.y ,30 , 60 ,pDevice);
		AddTab(STRING_Weapon,	Menu.MenuSt.x + 75		, Menu.MenuSt.y ,30 , 60 ,pDevice);
		AddTab(STRING_Misc,		Menu.MenuSt.x + 140		, Menu.MenuSt.y ,30 , 60 ,pDevice);
		AddTab(STRING_Nothing,	Menu.MenuSt.x + 205		, Menu.MenuSt.y ,30 , 60 ,pDevice);

		MenuSt.NumberOfTabs = 0;

		////////////////////////////////////////////////////////////////////////////////////////
		int i = 2; // Tab 1
		/*		Left		*/
		AddCheck(STRING_SatChams			, MenuSt.x + 15  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,0);
		AddCheck(STRING_FullBright			, MenuSt.x + 15  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,0);
		AddCheck(STRING_NoFog				, MenuSt.x + 15  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,0);
		AddCheck(STRING_WireFrame			, MenuSt.x + 15  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,0);

		i = 2;
		/*		Right	 */
		AddCheck(STRING_PlayerxWireFrame	, MenuSt.x + 150  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,0);
		AddCheck(STRING_NoFlash				, MenuSt.x + 150  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,0);
		AddCheck(STRING_Glow				, MenuSt.x + 150  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,0);

		MenuSt.NumberOfItems = 0;
		//////////////////////////////////////////////////////////////////////////////////////////
		i = 2; // Tab 2
		AddCheck(STRING_NoSpread			, MenuSt.x + 15  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,1);
		AddCheck(STRING_PickUp				, MenuSt.x + 15  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,1);

		MenuSt.NumberOfItems = 0;
		///////////////////////////////////////////////////////////////////////////////////////////
		i =  2; // Tab 3
		AddCheck(STRING_SuperJump		, MenuSt.x + 15  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,2);
		AddCheck(STRING_ShowFps			, MenuSt.x + 15  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,2);
		AddCheck(BeastMode				, MenuSt.x + 15	 , MenuSt.y + (20 * i++) , 12, 12, pDevice ,2);

		MenuSt.NumberOfItems = 0;
		//////////////////////////////////////////////////////////////////////////////////////////
		i =  2; // Tab 4
		AddCheck(" Check1 on Tab 4" , MenuSt.x + 15  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,3);
		AddCheck(" Check2 on Tab 4" , MenuSt.x + 15  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,3);
		AddCheck(" Check3 on Tab 4" , MenuSt.x + 15  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,3);
		AddCheck(" Check4 on Tab 4" , MenuSt.x + 15  , MenuSt.y + (20 * i++) , 12, 12, pDevice ,3);

		MenuSt.NumberOfItems = 0;

		Menu.DrawMouse(pDevice);// Draw Mouse;
	}
}

bool cMenu::MouseClick( int x , int y , int h , int w , int Index , int Tab)
{
	POINT Cur;
	GetCursorPos( &Cur );

	if( Cur.x > x && Cur.x < x + w && Cur.y > y && Cur.y < y + h )
	{
		if( GetAsyncKeyState( VK_LBUTTON ) < 0 )
			CheckBox [Tab][Index].IsClicked = true;

		if(GetAsyncKeyState( VK_LBUTTON ) == 0 && CheckBox [Tab][Index].IsClicked )
		{
			CheckBox [Tab][Index].IsClicked = false;
			return true;
		}
	}else CheckBox [Tab][Index].IsClicked = false;
	return false;
}

void cMenu::DrawMouse(LPDIRECT3DDEVICE9 pDevice)
{
	POINT Cur;
	GetCursorPos( &Cur );
	Menu.DrawBox(Cur.x ,Cur.y,8,8,1,0xFFF6FFDD,0xFFF6FFDD,0xFFFFFFFF,pDevice);
}

void cMenu::DrawBox( int x, int y, int w, int h, int PX, D3DCOLOR BoxColor, D3DCOLOR BorderColor1, D3DCOLOR BorderColor2 
					,IDirect3DDevice9* pDevice ) 
{ 
	if( !pDevice )
		return;

    Menu.FillRGB( x, y, w, h,        BoxColor, pDevice ); 
    Menu.DrawBorder( x, y, w, h, PX,    BorderColor1, BorderColor2, pDevice ); 
}

void cMenu::DrawBorder( int x, int y, int w, int h, int px, D3DCOLOR BorderColor1, D3DCOLOR BorderColor2 ,
					   IDirect3DDevice9* pDevice ) 
{ 
	if( !pDevice )
		return;

    FillRGB( x, (y + h - px), w, px,     BorderColor2, pDevice ); 
    FillRGB( x, y, px, h,                BorderColor1, pDevice ); 
    FillRGB( x, y, w, px,                BorderColor1, pDevice ); 
    FillRGB( (x + w - px), y, px, h,     BorderColor2, pDevice ); 
} 

void cMenu::FillRGB( int x, int y, int w, int h, D3DCOLOR Color, IDirect3DDevice9* pDevice )
{
	if( !pDevice )
		return;

	const DWORD D3D_FVF = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	
	struct Vertex 
	{
		float x,y,z,ht;
		DWORD yourcolor;
	}
	V[4] = 
	{
		{(float)x		,(float)(y+h)	, 0.0f, 0.0f, Color},
		{(float)x		,(float)y		, 0.0f, 0.0f, Color},
		{(float)(x+w)	,(float)(y+h)	, 0.0f, 0.0f, Color},
		{(float)(x+w)	,(float)y		, 0.0f, 0.0f, Color}
	};
	
	pDevice->SetTexture( 0, NULL );
	pDevice->SetRenderState( D3DRS_LIGHTING, FALSE);
	pDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW);
	pDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
	pDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	pDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE );
	pDevice->SetRenderState( D3DRS_FOGENABLE, false );

	pDevice->SetFVF(D3D_FVF);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,V,sizeof(Vertex));
}