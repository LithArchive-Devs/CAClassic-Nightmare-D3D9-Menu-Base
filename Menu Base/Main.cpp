/*************************************/
/* => Credits <=
/* mo3ad001 
/* Gordon` & Hans 
/* Azorbix
/* We11ington
/* ChaosMagican
/* Nightmare - > updated Menu Base.
/**************************************/

#include "Main.h"

cMain Main;

oPresent pPresent;
oReset pReset;

LPDIRECT3DDEVICE9 g_pDevice = NULL;

// Credits We11ington
char *cMain::Decrypt(const char *plaintext)
{
	int len = strlen(plaintext);
	char *cyphertext = new char[len + 1];
	for(int i = 0; i < len; ++i) {
		cyphertext[i] = plaintext[i] - 45;
	}
	cyphertext[len] = 0; 
	return cyphertext;
}

void cMain::Render(LPDIRECT3DDEVICE9 pDevice)
{	
	if(Main.pFont != NULL)
	{
		Main.DrawString(0 , 0, 0xFFFF0000, Main.pFont, Hack_Name); // Hack Title..

		Menu.Render (pDevice);//Menu Render
		Hack.hCommands();
		//etc...
	}else if (g_pDevice != pDevice)
	{
		g_pDevice = pDevice;
		try
		{ 
			if (Main.pFont != 0)
				Main.pFont->Release();
		} catch (...) {}
		Main.pFont = 0;
		D3DXCreateFontA(pDevice, 13, 0, FW_NORMAL, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, 
			DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, Font_Name, &Main.pFont);
	}
}

void cMenu::StyleRender(LPDIRECT3DDEVICE9 pDevice)
{
	Menu.DrawBox(Menu.MenuSt.x  - 5 , Menu.MenuSt.y  - 20, 300 , 150 ,5,0xFFD4D7D4,0xFF787878,0xFF787878,pDevice);
	Main.DrawString(Menu.MenuSt.x + 30 , Menu.MenuSt.y - 15 , 0xFF000000, Main.pFont, Menu_Title); // Menu Title..
}

HRESULT WINAPI MyPresent(LPDIRECT3DDEVICE9 pDevice, CONST RECT *pSourceRect, 
						   CONST RECT *pDestRect, HWND hDestWindowOverride, CONST RGNDATA *pDirtyRegion)
{
	_asm pushad;

	pDevice->SetTexture( NULL, NULL );
	pDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, D3DZB_TRUE );
	pDevice->SetFVF( D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1 );
	pDevice->SetRenderState( D3DRS_FOGENABLE, false );
	pDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE );

	Main.Render(pDevice);

	pDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_TRUE );
    pDevice->SetTexture(0, NULL); 

	_asm popad;
	return pPresent(pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT WINAPI MyReset(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters )
{
	_asm pushad;

	Main.pFont->OnLostDevice();

	HRESULT hRet = pReset(pDevice, pPresentationParameters);

	if(SUCCEEDED(hRet))
		Main.pFont->OnResetDevice();

	_asm popad;

	return pReset(pDevice, pPresentationParameters);
}

DWORD cMain::GetVTable(INT value)
{
	DWORD *Device = ***(DWORD ****)DeviceGame;

	if(Device == NULL)
		return 0;

	return Device[value];
}

VOID cMain::hkHook(VOID)
{
	DWORD cReset   = Main.GetVTable(16);
	DWORD cPresent = Main.GetVTable(17);

	pReset   = ( oReset   )Main.DetourCreate(( PBYTE ) cReset,   ( PBYTE ) &MyReset   ,Len_size );
	pPresent = ( oPresent )Main.DetourCreate(( PBYTE ) cPresent, ( PBYTE ) &MyPresent ,Len_size );
}

DWORD WINAPI dwHookThread(LPVOID)
{
	while(!Main.GameReady2Hook())
		Sleep(500);

	Main.hkHook();
	return NULL;
}

BOOL APIENTRY DllMain ( HMODULE hDll, DWORD dwReason, LPVOID lpReserved )
{
	DisableThreadLibraryCalls(hDll);
	if ( dwReason == 1 )
		CreateThread(NULL, NULL,dwHookThread, NULL, NULL, NULL);

	return TRUE;
}

void cMain::DrawString(int x, int y, DWORD color, LPD3DXFONT g_pFont, const char *fmt, ...) 
{
	if(!g_pFont)
		return;

	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	g_pFont->DrawTextA(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}

void *cMain::DetourCreate(BYTE *src, const BYTE *dst, const int len)
{
	__asm pushad;
	unsigned int hkPointers[] = { 0xE9, 0x90 };
	BYTE *jmp = (BYTE*)malloc(len+5);
	DWORD dwBack;

	VirtualProtect( src, len, PAGE_EXECUTE_READWRITE, &dwBack );

	memcpy( jmp, src, len );
	jmp += len;
	jmp[0] = hkPointers[0];
	*(DWORD*)(jmp+1) = (DWORD)(src+len - jmp) - 5;
	src[0] = hkPointers[0];
	*(DWORD*)(src+1) = (DWORD)(dst - src) - 5;

	for( int i=5; i<len; i++ ) 
		src[i]=hkPointers[1];

	VirtualProtect( src, len, dwBack, &dwBack );

	FlushInstructionCache( GetCurrentProcess(), src, PAGE_EXECUTE );
	return (jmp-len);
	__asm popad;
}

BOOL cMain::GameReady2Hook(VOID)
{
	if(GetModuleHandleA("d3d9.dll") != NULL && GetModuleHandleA("CShell.dll") != NULL && GetModuleHandleA("ClientFX.fxd") != NULL)
		return TRUE;

	return FALSE;
}