/*************************************/
/* => Credits <=
/* mo3ad001 
/* Gordon` & Hans 
/* Azorbix
/* We11ington
/* ChaosMagican
/* Nightmare - > updated Menu Base.
/**************************************/

#ifndef _Main
#define _Main

#pragma once

#include "Files.h"

typedef HRESULT (WINAPI* oPresent)(LPDIRECT3DDEVICE9 pDevice,CONST RECT *pSourceRect, CONST RECT *pDestRect, HWND hDestWindowOverride, CONST RGNDATA *pDirtyRegion);
typedef HRESULT (WINAPI* oReset)(LPDIRECT3DDEVICE9 pDevice,D3DPRESENT_PARAMETERS* Parametri);

#define D3D9_Name L"d3d9.dll"
#define Font_Name "Verdana"
#define Hack_Name " Haxo v[0.0.0] Update"
#define Menu_Title " CheckBox Base Update"

#define Len_size  5

class cMain
{
public:
	LPD3DXFONT pFont;            // 
	LPDIRECT3DDEVICE9 pDevice;   //

	char *Decrypt(const char *plaintext);
	void *cMain::DetourCreate(BYTE *src, const BYTE *dst, const int len); //
	BOOL GameReady2Hook(VOID); //
	void DrawString(int x, int y, DWORD color, LPD3DXFONT g_pFont, const char *fmt, ...);//
	DWORD GetVTable(INT value); //
	
	void Render(LPDIRECT3DDEVICE9 pDevice);//
	VOID hkHook(VOID);              //
};

extern class cMain Main;

#endif