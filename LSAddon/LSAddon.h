

#ifndef _LSAddon_h_
#define _LSAddon_h_

#ifdef EXPORT_DLL_ADDON
#define LSAddon_API __declspec(dllexport)
#else
#define LSAddon_API __declspec(dllimport)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <assert.h>
#include <conio.h>


#endif