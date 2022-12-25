#pragma once


#ifndef _LostRPC_h_
#define _LostRPC_h_

class LSAddon_API LostRPC
{

public:
	LostRPC();
	virtual ~LostRPC();
};

extern LSAddon_API LostRPC LSAddon;

#define ioASSERT(f)			{if(!(f)) {LOG.DebugLog(0, __FILE__,__LINE__,"ASSERT Fail,return");		    assert(f);return;}}
#define ioASSERT_minusone(f){if(!(f)) {LOG.DebugLog(0, __FILE__,__LINE__,"ASSERT Fail,return -1");		assert(f);return -1;}}
#define ioASSERT_false(f)	{if(!(f)) {LOG.DebugLog(0, __FILE__,__LINE__,"ASSERT Fail,return false");	assert(f);return false;}}

LSAddon_API void SetDiscordID(const char* szDiscordID);
LSAddon_API void UpdateLostRPC(const char* szDetail, const char* szState);


#endif	// _CLog_h_


