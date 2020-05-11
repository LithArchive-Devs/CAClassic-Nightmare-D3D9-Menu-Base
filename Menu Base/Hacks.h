/*************************************/
/* => Credits <=
/* mo3ad001 
/* Gordon` & Hans 
/* Azorbix
/* We11ington
/* ChaosMagican
/* Nightmare - > updated Menu Base.
/**************************************/

#ifndef _Hack
#define _Hack

#pragma once

#include "Files.h"

struct Flags
{
	bool Flag[15];
};

class cHack
{
public:
	Flags Flag;
	void hCommands(void);
	void __stdcall pRun_Command(const char* szCommand); 
	void PatchCommand(bool MenuVal ,char *commandOn, char *commandOff, bool& zsFlag);
};

extern class cHack Hack;

#endif