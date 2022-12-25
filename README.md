# lsaddon
Simple Discord RPC for Lost Saga


**Tutorial LSAddon for Discord RPC**
_only working with client side_

- extract LSAddon folder inside lostsaga source <br>
- Edit APPLICATION_ID inside LostRPC.cpp , and then build the project <br>
- add include #include **"../LSAddon/LSAddon.h"** & **#include "../LSAddon/LostRPC.h"** inside **stdafx.h** from client <br>
- add **#pragma comment(lib, "../../lib/LSAddon.lib")** above #pragma comment(lib, "../../lib/LSLog.lib")  inside **stdafx.h** from client <br>
- call **UpdateLostRPC(const char* szDetail, const char* szState); **  in the file you want to make changes to the discord RPC. ***ex : UpdateLostRPC("Opening Game", "Loading");*** <br>
