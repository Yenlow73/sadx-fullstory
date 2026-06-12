#include <pch.h>

void ev0032_t_meetingsonic(int state)
{
	switch ( state ) {
	case 1:
		player = EV_GetPlayer(0);
		EV_CameraOn( );
		EV_PadOff( );
		EV_CanselOn( );
		EV_InitPlayer(0);

		// Tails Intro

		BGM_Play(MusicIDs_themiles);
		EV_SetPos(player, -470.98999f, 0.0099999998f, 2023.55f);
		EV_SetAng(player, 0, 0x640B, 0);
		EV_SetAction(player, MILES_ACTIONS[ 80 ], &MILES_TEXLIST, 1.0f, 1, 0);
		EV_CreateObject(( task** ) &PURPLE,
			player->twp->pos.x,
			player->twp->pos.y,
			player->twp->pos.z,
			player->twp->ang.x,
			0x4000 - player->twp->ang.y,
			player->twp->ang.z);
		EV_CreatePlayer(2, SonicTheHedgehog,
			player->twp->pos.x + 20.0f,
			player->twp->pos.y,
			player->twp->pos.z - 10.0f,
			player->twp->ang.x,
			0x4000 - player->twp->ang.y,
			player->twp->ang.z);
		EV_Wait(1);
		sonic = EV_GetPlayer(2);
		EV_SetAction(sonic, SONIC_ACTIONS[ 3 ], &SONIC_TEXLIST, 1.0f, 1, 0);
		EV_CameraAng(1, 0, 0xD200, 0x8500, 0);
		EV_CameraPos(1, 0, -439.70001f, 100.41f, 1916.5699f);
		EV_Wait(1);
		EV_LookObject(sonic, player, 0.0f, 6.0f, 0.0f);
		EV_LookObject(player, sonic, 0.0f, 6.0f, 0.0f);
		EV_Wait(1);
		EV_MovePoint2(sonic, -450.67001f, 0.0099999998f, 1901.05f, 0.57999998f, 3.0f);
		EV_MovePoint2(player, -460.17001f, 1.01f, 1912.28f, 0.56f, 3.0f);
		EV_CameraAng(0, 90, 0xD200, 0x8500, 0);
		EV_CameraPos(0, 90, -447.70001f, 66.970001f, 1931.85f);
		EV_Wait(90);
		EV_CameraAng(0, 0, 0xFD00, 0xB800, 0);
		EV_CameraPos(0, 0, -495.04001f, 12.73f, 1963.4399f);
		EV_CameraAng(0, 110, 0xFD00, 0xD400, 0);
		EV_CameraPos(0, 110, -467.96899f, 5.2385998f, 1920.849f);
		EV_Wait(60);
		EV_MoveFree(player);
		EV_MoveFree(sonic);
		EV_Wait(1);
		EV_MovePoint2(sonic, -450.67001f, 0.0099999998f, 1901.05f, 0.57999998f, 3.0f);
		EV_MovePoint2(player, -457.17001f, 1.01f, 1917.28f, 0.56f, 3.0f);
		EV_ClrAction(sonic);
		EV_ClrAction(player);
		EV_SetFace(sonic, "GG");
		EV_SerifPlay(625);
		EV_Msg(msgTbl_ev0032[ TextLanguage ][ 0 ]); //"\aBoy, you're lucky \nI saw you come do"...
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(sonic);
		EV_MsgCls( );
		EV_Wait(30);
		EV_SetAng(player, 0, 0x7200, 0);
		EV_SetAng(sonic, 0, 0xEA00, 0);
		EV_LookFree(sonic);

		// Sonic Cutscene

		//EV_Wait(30);
		EV_SetPos(sonic, -450.67001f, 0.0099999998f, 1901.05f);
		EV_SetPos(player, -461.17001f, 0.0099999998f, 1912.28f);
		EV_SetAng(player, 0, 0x6800, 0);
		EV_SetAng(sonic, 0, 0xE200, 0);
		EV_SetAction(sonic, SONIC_ACTIONS[ 1 ], &SONIC_TEXLIST, 1.0f, 1, 8);
		EV_LookFree(sonic);
		EV_CameraAng(0, 0, 0xF800, 0x1B00, 0);
		EV_CameraPos(0, 0, -452.91f, 7.0700002f, 1927.46f);
		EV_CameraAng(0, 60, 0xFB00, 0xA00, 0);
		EV_Wait(40);
		EV_ClrFace(sonic);
		EV_SetFace(sonic, "DCECEAADCDE");
		EV_SerifPlay(419);
		EV_Msg(( msgTbl_ev0006[ TextLanguage ] )[ 2 ]); // "\aWhat happened, anyway?"
		EV_Wait(1);
		EV_SerifWait( );
		EV_SerifPlay(420);
		EV_Msg(( msgTbl_ev0006[ TextLanguage ] )[ 3 ]); // "\aYou're too good of a pilot \nto just "...
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(sonic);
		EV_MsgClose( );
		EV_Wait(5);
		EV_MovePoint2(player,
			sonic->twp->pos.x - 8.0f,
			sonic->twp->pos.y,
			sonic->twp->pos.z + 8.0f,
			0.56f, 0.059999999f);
		EV_CameraAng(0, 30, 0xFB00, 0x400, 0);
		EV_Wait(30);
		EV_ClrFace(player);
		EV_SetFace(player, "EDCDAAECDED");
		EV_SerifPlay(421);
		EV_MsgW(75, ( msgTbl_ev0006[ TextLanguage ] )[ 4 ]); // "\aThat was a test run using \na new pro"...
		EV_MsgW(35, ( msgTbl_ev0006[ TextLanguage ] )[ 5 ]); // "\aIt's got a few bugs to iron out."
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(player);
		EV_MsgClose( );
		EV_ClrFace(sonic);
		EV_SetFace(sonic, "FDCCDFD");
		EV_SerifPlay(422);
		EV_Msg(( msgTbl_ev0006[ TextLanguage ] )[ 6 ]); //"\aWhy not just use my plane, \nthe Torn"...
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(sonic);
		EV_MsgClose( );
		EV_CameraAng(0, 0, 0x200, 0x5300, 0);
		EV_CameraPos(0, 0, -442.64999f, 5.5999999f, 1902.02f);
		EV_SetPos(PURPLE,
			player->twp->pos.x,
			player->twp->pos.y,
			player->twp->pos.z);
		EV_SetAng(PURPLE,
			player->twp->ang.x,
			0x4000 - player->twp->ang.y,
			player->twp->ang.z);
		EV_ClrFace(player);
		if ( VoiceLanguage == Languages_Japanese )
		{
			EV_SetFace(player, "GCAAGDG");
		}
		if ( VoiceLanguage == Languages_English )
		{
			EV_SetFace(player, "GGDG");
		}
		EV_SerifPlay(423);
		EV_Msg(( msgTbl_ev0006[ TextLanguage ] )[ 7 ]); //"\aThanks, but you gotta check out\nmy n"...
		EV_Wait(1);
		EV_SerifWait( );
		EV_SerifPlay(424);
		EV_Msg(( msgTbl_ev0006[ TextLanguage ] )[ 8 ]); //"\aTa dahhh!"
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(player);
		EV_MsgClose( );
		EventSe_Oneshot(743, 0, 0, 0);
		EV_CameraAng(0, 0, 0xE100, 0x6700, 0);
		EV_CameraPos(0, 0, -444.47f, 26.940001f, 1889.1f);
		EV_SetAction(player, &action_m_m0104_miles, &MILES_TEXLIST, 1.0f, 1, 0);
		EV_SetAction(PURPLE, &action_m_m0104cp_m_em_purple, &M_EM_PURPLE_TEXLIST, 1.0f, 1, 0);
		EV_Wait(1);
		EV_CameraAng(0, 30, 0xE100, 0x6700, 0);
		EV_CameraPos(0, 30, -456.14001f, 6.0900002f, 1906.5699f);
		EV_Wait(60);
		EV_MsgClose( );
		EV_CameraAng(0, 0, 0xFB00, 0xE100, 0);
		EV_SetAction(sonic, &action_s_s0022_sonic, &SONIC_TEXLIST, 0.30000001f, 1, 8);
		EV_ClrFace(sonic);
		EV_SetFace(sonic, "IAADE");
		EV_SerifPlay(425);
		EV_Msg(( msgTbl_ev0006[ TextLanguage ] )[ 9 ]); //"\aWHOA!   \nA Chaos Emerald!"
		EV_Wait(1);
		EV_Wait(45);
		EV_MsgClose( );
		EV_SetAction(sonic, SONIC_ACTIONS[ 1 ], &SONIC_TEXLIST, 1.0f, 1, 8);
		EV_CameraAng(0, 0, 0xFD00, 0x5D00, 0);
		EV_CameraPos(0, 0, -450.79999f, 5.6100001f, 1901.96f);
		EV_CameraAng(0, 240, 0xFD00, 0x2400, 0);
		EV_CameraPos(0, 240, -441.94f, 6.71f, 1917.03f);
		EV_Wait(1);
		EV_ClrFace(sonic);
		EV_Wait(30);
		EV_ClrFace(player);
		if ( VoiceLanguage == Languages_Japanese )
		{
			EV_SetFace(player, "GEDCDCGDE");
		}
		if ( VoiceLanguage == Languages_English )
		{
			EV_SetFace(player, "GEDE");
		}
		EV_SerifPlay(426);
		EV_MsgW(70, ( msgTbl_ev0006[ TextLanguage ] )[ 10 ]); //"\aYep! I just happened to find \none of"...
		EV_MsgW(30, ( msgTbl_ev0006[ TextLanguage ] )[ 11 ]); //"\aduring one of my test flights. "
		EV_Wait(1);
		EV_SerifWait( );
		if ( VoiceLanguage == Languages_English )
		{
			EV_ClrFace(player);
		}
		EV_Wait(20);
		EV_SerifPlay(427);
		EV_Msg(( msgTbl_ev0006[ TextLanguage ] )[ 12 ]); //"\aThis thing's got unlimited power,\nya"...
		if ( VoiceLanguage == Languages_English )
		{
			EV_SetFace(player, "GEDE");
		}
		EV_Wait(20);
		EV_SerifWait( );
		if ( VoiceLanguage == Languages_English )
		{
			EV_ClrFace(player);
		}
		EV_SerifPlay(428);
		EV_Msg(( msgTbl_ev0006[ TextLanguage ] )[ 13 ]); //"\aSo I figured, why not use it \nto pow"...
		if ( VoiceLanguage == Languages_English )
		{
			EV_SetFace(player, "GEDE");
		}
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(player);
		EV_MsgCls( );
		EV_Wait(45);
		EV_ClrFace(player);
		if ( VoiceLanguage == Languages_Japanese )
		{
			EV_SetFace(player, "CG");
		}
		if ( VoiceLanguage == Languages_English )
		{
			EV_SetFace(player, "CGG");
		}
		EV_SerifPlay(429);
		EV_MsgW(60, ( msgTbl_ev0006[ TextLanguage ] )[ 14 ]); //"\aYou gotta come over to \nmy workshop,"...
		EV_MsgW(60, ( msgTbl_ev0006[ TextLanguage ] )[ 15 ]); //"\aI've got something I've gotta \nshow "...
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(player);
		EV_LookObject(sonic, player, 0.0f, 6.0f, 0.0f);
		EV_LookFree(player);
		EV_LookPoint(player,
			sonic->twp->pos.x,
			sonic->twp->pos.y,
			sonic->twp->pos.z);
		EV_CameraPos(0, 0, -444.83499f, 6.5500002f, 1912.076f);
		EV_CameraAng(0, 0, 0xB00, 0x1800, 0);
		EV_ClrAction(player);
		EV_ClrAction(PURPLE);
		EV_MovePoint2(player, -463.14001f, 0.0f, 1878.86f, 0.46000001f, 0.050000001f);
		EV_Wait(10);
		EV_SetAng(sonic, 0, 0xCA00, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xC800, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xC600, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xC400, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xC200, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xC000, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xBE00, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xBC00, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xBA00, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xB800, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xB400, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xB200, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xB000, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xAE00, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xAC00, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xAA00, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xA800, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xA600, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xA400, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xA200, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0xA000, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0x9E00, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0x9C00, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0x9A00, 0);
		EV_Wait(1);
		EV_SetAng(sonic, 0, 0x9800, 0);
		EV_ClrFace(player);
		EV_SetFace(player, "GEGCG");
		EV_SerifPlay(430);
		EV_MsgW(70, ( msgTbl_ev0006[ TextLanguage ] )[ 16 ]); //"\aIt's in the Mystic Ruins.   \nThe fas"...
		EV_MsgW(40, ( msgTbl_ev0006[ TextLanguage ] )[ 17 ]); //"\aLet's go!"
		EV_MovePoint2(player, -392.20999f, 0.0f, 1844.77f, 0.46000001f, 0.050000001f);
		EV_Wait(120);
		EV_MsgClose( );
		EV_ClrFace(player);
		EV_Wait(1);
		break;
	case 2:
		EV_SetPos(player, -416.5f, 0.0099999998f, 1848.1169f);
		EV_SetAng(player, 0, 0x646D, 0);
		EV_InitPlayer(0);
		EV_RemovePlayer(2);
		EventSe_Close();
		EV_FreeObject(&PURPLE);
		EV_CameraOff();
		EV_PadOn();
		break;
	}
};