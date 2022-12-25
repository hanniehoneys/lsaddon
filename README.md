# lsaddon
Simple Discord RPC for Lost Saga


**Tutorial LSAddon for Discord RPC**
_only working with client side_

:diamond_shape_with_a_dot_inside: extract LSAddon folder inside lostsaga source
:diamond_shape_with_a_dot_inside: Edit APPLICATION_ID inside LostRPC.cpp , and then build the project 
:diamond_shape_with_a_dot_inside: add include #include **"../LSAddon/LSAddon.h"** & **#include "../LSAddon/LostRPC.h"** inside **stdafx.h** from client 
:diamond_shape_with_a_dot_inside: add **#pragma comment(lib, "../../lib/LSAddon.lib")** above #pragma comment(lib, "../../lib/LSLog.lib")  inside **stdafx.h** from client 
:diamond_shape_with_a_dot_inside: call **UpdateLostRPC(const char* szDetail, const char* szState); **  in the file you want to make changes to the discord RPC. ***ex : UpdateLostRPC("Opening Game", "Loading");***
