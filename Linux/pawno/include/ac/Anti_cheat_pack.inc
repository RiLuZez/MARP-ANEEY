#include <ac/rAgc>//Anti gun cheats -Rogue
#include <ac/FLaggers>//Lag spike\desnyc detector- Rogue
#include <ac/Opba>//Anti airbreak\teleport - Rogue
#include <ac/rAct>//Anti car trolls - Rogue
//#include <ac/AntiJC>//Anti jetpack cheats- Rogue
//#include <ac/rEac>//Anti carswing\particlespam - Lorenc_
//#include <ac/rAmc>//Anti money cheats- Rogue
//#include <ac/rAGM>//Anti godmode -Rogue
//#include <ac/rAntiBuggers>//Depresses 5 abusing bugs triggered by cheats. -Rogue
//#include <ac/AFkill> //Anti fake kill -Rogue
//#include <ac/AntiFC>//Anti fake clients - Rogue
//#include <ac/rAsc>//Anti speed cheats- Rogue
//#include <ac/rVM>//Anti illegal car mods -Emmet_
#include <ac/rAcs>//Anti car spam - Rogue
#include <ac/AntiSpam>//Anti chat spam- Rogue
//#include <ac/AntiSba>//Anti slide bug abuse- Rogue

#if !defined FILTERSCRIPT 

#if defined RogueAC_OnGameModeInit
	forward RogueAC_OnGameModeInit();
#endif

public OnGameModeInit()
{
	print("	 [[--|| Rogue-AC V7.0 ||--]]	 ");
	print("	 [[--|| Rogue Anti cheat version 7.0 ||--]]	  ");
	print("	 [[--|| Successfully Loaded! ||--]]	  ");
	#if defined RogueAC_OnGameModeInit
		return RogueAC_OnGameModeInit();
	#else
		return 1;
	#endif
}

#if defined _ALS_OnGameModeInit
  #undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit RogueAC_OnGameModeInit

#endif
