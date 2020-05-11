/*************************************/
/* => Credits <=
/* mo3ad001 
/* Gordon` & Hans 
/* Azorbix
/* We11ington
/* ChaosMagican
/* Nightmare - > updated Menu Base.
/**************************************/

#include "Hacks.h"

cHack Hack;

void __stdcall cHack::pRun_Command(const char* szCommand)
{
	__asm 
	{
		PUSHAD
		PUSH szCommand;
		MOV EAX, LTClientEXE
		CALL EAX
		ADD ESP, 0x4
		POPAD
	}
}

void cHack::PatchCommand(bool MenuVal,char *commandOn,char *commandOff,bool& zsFlag)
{
	if(MenuVal)
	{
		if(zsFlag == true)
		{
			Hack.pRun_Command(commandOn);
			zsFlag = false;
		}
	}else{
		if(zsFlag == false)
		{
			Hack.pRun_Command(commandOff);
			zsFlag = true;
		}
	}
}

void cHack::hCommands(void)
{

	int i = 0;
	Hack.PatchCommand( Menu.CheckBox[0][1].State , "SkelModelStencil 1.000000",		"SkelModelStencil 0.000000"			, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[0][2].State , "FullBright 1.000000",			"FullBright 0.000000"				, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[0][3].State , "FogEnable 0.000000",			"FogEnable 1.000000"				, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[0][4].State , "WireFrame 1.000000",			"WireFrame 0.000000"				, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[0][5].State , "WireframeModels 1.000000",		"WireframeModels 0.000000"			, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[0][6].State , "DrawVolumeEffects 0.000000",	"DrawVolumeEffects 1.000000"		, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[0][7].State , "ScreenGlowEnable 1.000000",		"ScreenGlowEnable 0.000000"			, Hack.Flag.Flag[i++]);

	Hack.PatchCommand( Menu.CheckBox[1][1].State , "PerturbRotationEffect 0.000000",		"PerturbRotationEffect 3.000000"		, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[1][1].State , "PerturbIncreaseSpeed 0.000000",			"PerturbIncreaseSpeed 0.000000"			, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[1][1].State , "PerturbWalkPercent 0.000000",			"PerturbWalkPercent 0.000000"			, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[1][1].State , "PerturbFiringIncreaseSpeed 0.000000",	"PerturbFiringIncreaseSpeed 0.000000"	, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[1][2].State , "ActivationDistance 9999.000000",		"ActivationDistance 100.000000"		, Hack.Flag.Flag[i++]);
	
	Hack.PatchCommand( Menu.CheckBox[2][1].State , "JumpVel 600.000000",		"JumpVel 330.000000"				, Hack.Flag.Flag[i++]);
	Hack.PatchCommand( Menu.CheckBox[2][2].State , "ShowFPS 1.000000",			"ShowFPS 0.000000"					, Hack.Flag.Flag[i++]);
	
}