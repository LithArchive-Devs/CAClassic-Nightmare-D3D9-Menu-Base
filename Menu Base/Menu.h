/*************************************/
/* => Credits <=
/* mo3ad001 
/* Gordon` & Hans 
/* Azorbix
/* We11ington
/* ChaosMagican
/* Nightmare - > updated Menu Base.
/**************************************/

#ifndef _Memu
#define _Memu

#pragma once

#include "Files.h"

//Menu Settings
///////////////////////////////////////////////////////////////
/* Tab Count		*/   #define Tab_Count		5
/* CheckBox Count	*/   #define CheckBox_Count	15
//////////////////////////////////////////////////////////////

struct MenuSt_t
{
	int x , y;
	int NumberOfItems , NumberOfTabs;
	bool IsVisble , Load;
};

struct CheckBox_t
{
	bool State , IsClicked;
};



class cMenu
{
public:
	MenuSt_t MenuSt;
	CheckBox_t CheckBox[Tab_Count][CheckBox_Count];

	void AddTab(char* Name ,int x, int y , int h , int w , LPDIRECT3DDEVICE9 pDevice);
	void AddCheck (char* Name ,int x, int y , int h , int w , LPDIRECT3DDEVICE9 pDevice , int Tab);
	bool MouseClick( int x , int y , int h , int w , int Index , int Tab);
	void Render(LPDIRECT3DDEVICE9 pDevice);
	void DrawMouse(LPDIRECT3DDEVICE9 pDevice);
	void StyleRender(LPDIRECT3DDEVICE9 pDevice);

	//DrawStuf
	void DrawBox( int x, int y, int w, int h, int PX, D3DCOLOR BoxColor, D3DCOLOR BorderColor1, D3DCOLOR BorderColor2 
					,IDirect3DDevice9* pDevice );
	void DrawBorder( int x, int y, int w, int h, int px, D3DCOLOR BorderColor1, D3DCOLOR BorderColor2 ,
					   IDirect3DDevice9* pDevice ) ;
	void FillRGB( int x, int y, int w, int h, D3DCOLOR yourcolor, IDirect3DDevice9* pDevice );
};

extern class cMenu Menu;

#endif