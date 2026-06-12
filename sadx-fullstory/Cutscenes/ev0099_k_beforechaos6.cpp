#include <pch.h>

void ev0099_k_beforechaos6(int state)
{
	switch (state) {
	case 1:
		player = EV_GetPlayer(0);
		EV_CameraOn();
		EV_PadOff();
		EV_CanselOn();
		EV_Wait(1);
		EV_InitPlayer(0);
		SetBankDir(77);
		BGM_Play(MusicIDs_egcarer1);
		EV_SetPos(player, -79.190002f, 743.21997f, -549.66998f);
		EV_SetAng(player, 0, 0xA9F4, 0xFCCF);

		// Sonic Intro
		
		EV_CreatePlayer(2, SonicTheHedgehog, -44.900002f, 745.65002f, -231.87f, 0x2CE, 0x725E, 0x119);
		StgChaos6CtrlOn(16.0f, 560.0f, -30.0f, 0, 0, 0, 910);
		EV_Wait(1);
		EV_ClrAction(player);
		EV_SetAction(player, KNUCKLES_ACTIONS[ 82 ], &KNUCKLES_TEXLIST, 1.0f, 1, 0);
		sonic = EV_GetPlayer(2);

		create_eggmoble(0.0f, 780.0f, -386.04001f, 0, 0x4000, 0);
		EV_Wait(1);
		EV_ClrAction(sonic);
		EV_SetAction(sonic, SONIC_ACTIONS[ 123 ], &SONIC_TEXLIST, 0.5f, 1, 0);
		EV_ClrAction(player);
		EV_SetAction(player, KNUCKLES_ACTIONS[ 82 ], &KNUCKLES_TEXLIST, 1.0f, 1, 0);
		eggmoble = GetEggMobleTask( );
		EV_ClrAction(eggmoble);
		EV_SetAction(eggmoble, &action_gm_gm0002_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.0f, 1, 0);
		dsPlay_timer_v(1337, 0xCB80001, 1, 100, 600, 0.0f, 780.0f, -386.04001f);
		EV_Wait(1);

		seteggmobleparam(0.5f, 0x100);
		EV_CameraPerspective(0, 1, 0x1C72);
		EV_CameraPos(0, 0, 161.73f, 833.98999f, -87.220001f);
		EV_CameraAng(0, 0, 0xF494, 0x1A0C, 0xFA00);
		EV_CameraPos(0, 90, 141.27f, 837.52002f, -73.279999f);
		EV_Wait(90);
		EV_CameraPerspective(0, 1, 0x1555);
		EV_CameraPos(0, 0, -80.660004f, 752.10999f, -184.75f);
		EV_CameraAng(0, 0, 0x1CA, 0xEB29, 0);
		EV_CameraPos(0, 60, -88.489998f, 751.40002f, -170.81f);
		dsPlay_timer_v(1337, 0xCB80001, 1, 30, 180, 0.0f, 780.0f, -386.04001f);
		EV_Wait(60);
		EV_CameraPerspective(0, 1, 0x1555);
		EV_CameraPos(1, 0, -21.030001f, 780.5f, -342.64999f);
		EV_CameraAng(1, 0, 0x7CA, 0xE8AD, 0);
		EV_CameraPos(1, 140, -27.75f, 780.5f, -346.98999f);
		EV_CameraAng(1, 140, 0x7CA, 0xE5A5, 0);
		
		EV_SetPos(player, 139.57001f, 743.65002f, -265.67999f);
		EV_SetAng(player, 0x1CB, 0xBFF7, 0xFD71);
		EV_ClrAction(player);
		EV_SetAction(player, KNUCKLES_ACTIONS[ 56 ], &KNUCKLES_TEXLIST, 2.5f, 1, 0);
		EV_SerifPlay(577);
		EV_Msg(( msgTbl_ev001D[ TextLanguage ] )[ 0 ]); //"\aNo way!   \nI can't believe this!"
		EV_SetAction(eggmoble, &action_gm_gm0002_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.0f, 1, 0);
		EV_Wait(60);
		EV_ClrAction(sonic);
		EV_SetAction(sonic, SONIC_ACTIONS[ 1 ], &SONIC_TEXLIST, 0.80000001f, 1, 8);
		EV_Wait(40);
		EV_MsgClose( );
		EV_MovePoint2(player, 21.969999f, 747.63f, -253.89999f, 1.75f, 0.059999999f);
		EV_Wait(30);
		dsStop_id(213385217);
		EV_CameraTargetFree( );
		EV_CameraTargetObj(1, 0, player, 0.0f, 6.0f, 0.0f, 0);
		EV_CameraPos(0, 0, 116.31f, 752.71997f, -322.29999f);
		EV_SerifPlay(578);
		EV_MsgW(30, ( msgTbl_ev001D[ TextLanguage ] )[ 1 ]); //"\aSonic!"
		EV_MsgClose( );
		EV_WaitMove(player);
		EV_ClrAction(player);
		EV_SetAction(player, KNUCKLES_ACTIONS[ 82 ], &KNUCKLES_TEXLIST, 1.0f, 1, 0);
		EV_SetAng(player, 0x317, 0x8772, 0);
		EV_LookPoint(player, 0.0f, 803.0f, -387.04001f);
		EV_Wait(15);
		EV_LookObject(sonic, player, 0.0f, 10.0f, 0.0f);
		EV_CameraTargetFree( );
		EV_CameraPos(1, 15, 51.720001f, 751.31f, -278.45001f);
		EV_CameraAng(1, 15, 0xFF50, 0x57DB, 0);
		EV_Wait(30);
		EV_ClrFace(sonic);
		switch ( VoiceLanguage ) {
		case 0:
			EV_SetFace(sonic, "CED");
			break;
		case 1:
			EV_SetFace(sonic, "CBBBDF");
			break;
		}
		EV_Wait(10);
		EV_SerifPlay(579);
		EV_Msg(( msgTbl_ev001D[ TextLanguage ] )[ 2 ]); //"\aHey there, Knuckles."
		EV_Wait(35);
		if ( VoiceLanguage == Languages_Japanese )  EV_ClrFace(sonic);
		EV_Wait(5);
		EV_CameraPos(1, 45, -27.59f, 750.82001f, -240.23f);
		EV_CameraAng(1, 45, 0xFE50, 0x50DB, 0);
		EV_Msg(( msgTbl_ev001D[ TextLanguage ] )[ 3 ]); //"\aGlad you finally made it! \nI thought"..
		if ( VoiceLanguage == Languages_Japanese ) EV_SetFace(sonic, "CEFD");
		EV_Wait(60);
		EV_ClrFace(sonic);
		EV_Wait(5);
		EV_SetFace(sonic, "CEFD");
		EV_Wait(10);
		EV_ClrFace(sonic);
		EV_SetFace(sonic, "D");
		EV_Wait(15);
		EV_ClrFace(sonic);
		EV_Wait(30);
		EV_MsgClose( );
		EV_Wait(5);
		ChgEggMobleMod(5);
		EV_Wait(5);
		EV_CameraPerspective(0, 1, 0x238E);
		EV_CameraPos(0, 0, 18.65f, 778.13f, -373.26001f);
		EV_CameraAng(0, 0, 0xF94, 0x2E0C, 0xFD00);
		EV_CameraPos(0, 70, 69.360001f, 771.59003f, -342.66f);
		EV_CameraAng(0, 70, 0xD94, 0x2C0C, 0xFD00);
		EV_LookFree(sonic);
		
		EV_SerifPlay(581);
		eggmoble_moveandturn(0.0f, 785.0f, -386.04001f, 0, -0x4000, 0, 50, 0);
		EV_MsgW(45, ( msgTbl_ev001D[ TextLanguage ] )[ 4 ]); //"\aUntil we meet again, Sonic!  "
		EV_MsgClose( );


		EV_LookPoint(player, -50.330002f, 748.34003f, -350.01001f);

		EV_CameraPos(0, 35, 73.580002f, 769.95001f, -340.54001f);
		EV_CameraAng(0, 35, 0xD94, 0x2D0C, 0xFD00);
		ChgEggMobleSMod(1);
		eggmoble_moveandturn(-300.0f, 755.0f, -400.0f, 0, 0, 0, 90, 1);
		dsPlay_oneshot_v(1341, 0, 0, 120, 0.0f, 780.0f, -386.04001f);
		EV_Wait(25);
		EV_CameraPerspective(0, 1, 0x3111);
		EV_CameraPos(0, 0, -35.049999f, 749.29999f, -230.52f);
		EV_CameraAng(0, 0, 0x194, 0x2B0C, 0xFD00);
		EV_CameraPos(0, 70, -22.0f, 748.71997f, -223.14f);
		EV_ClrAction(sonic);
		EV_SetAction(sonic, SONIC_ACTIONS[ 4 ], &SONIC_TEXLIST, 2.75f, 1, 0);
		EV_MovePoint2(sonic, -217.33f, 748.34003f, -350.01001f, 1.75f, 0.059999999f);
		EV_SerifPlay(580);
		EV_MsgW(45, ( msgTbl_ev001D[ TextLanguage ] )[ 5 ]); //"\aStop!  Come back here!"
		EV_MsgClose( );
		EV_CameraPos(0, 0, -233.17999f, 750.09998f, -345.82999f);
		EV_CameraTargetObj(1, 0, sonic, 0.0f, 6.0f, 0.0f, 0);
		EV_SetPos(sonic, -217.33f, 748.34003f, -350.01001f);
		EV_ClrAction(sonic);
		EV_Wait(20);
		EV_PlayPad(2, &EV001D_S_JUMP);
		EV_Wait(5);
		eggmoble_moveandturn(-600.0f, 300.0f, -500.0f, 0, -0x500, 0, 120, 1);
		EV_CameraTargetFree();
		EV_CameraPos(0, 0, -447.75f, 635.0f, -436.70001f);
		EV_CameraAng(0, 0, 0xDCF8, 0x3180, 0);
		SONIC_JUMP = CSkyWalk_create2(sonic, 4800.0f);
		EV_SetPos(sonic, -600.0f, 600.0f, -450.0f);
		EV_SetAng(sonic, 0, 0xC000, 0);
		EV_Wait(1);
		EV_ClrAction(sonic);
		EV_Wait(20);
		if(SONIC_JUMP)
		{
			FreeTask(SONIC_JUMP);
			SONIC_JUMP = 0;
		}
		EV_Wait(60);
		
		// Sonic Intro Ends

		//EV_RemovePlayer(2);
		EV_CameraPos(0, 0, 15.56f, 749.26001f, -262.51001f);
		EV_CameraAng(0, 0, 0x894, 0xA80C, 0);
		EV_CameraPos(0, 360, 12.79f, 749.26001f, -258.35001f);
		EV_Msg(msgTbl_ev0099[ TextLanguage ][ 5 ]); //"\aI'd better let Sonic handle it from h"...
		EV_SerifPlay(1151);
		EV_SetFace(player, "CEDCD");
		EV_Wait(50);
		if ( VoiceLanguage == Languages_Japanese )
		{
			EV_ClrFace(player);
		}
		EV_Msg(msgTbl_ev0099[ TextLanguage ][ 6 ]); //"\aHe'll do okay."
		EV_Wait(10);
		if ( VoiceLanguage == Languages_English )
		{
			EV_ClrFace(player);
		}
		if ( VoiceLanguage == Languages_Japanese )
		{
			EV_SetFace(player, "CEDCD");
		}
		if ( VoiceLanguage == Languages_English )
		{
			EV_SetFace(player, "D");
		}
		EV_Wait(50);
		if ( VoiceLanguage == Languages_Japanese )
		{
			EV_ClrFace(player);
		}
		EV_Wait(25);
		delete_eggmoble( );
		EV_Msg(msgTbl_ev0099[ TextLanguage ][ 7 ]); //"\aNow... I must return to \nAngel Islan"...
		EV_SerifPlay(1152);
		EV_SetFace(player, "ECED");
		EV_Wait(30);
		StgChaos6SetPos(5.4000001f, 750.0f, -400.0f);
		StgChaos6SetAng(0, 0x4000, 0);
		EV_Wait(10);
		EV_SetFace(player, "CEDCD");
		EV_Wait(90);
		if ( VoiceLanguage == Languages_Japanese )
		{
			EV_ClrFace(player);
		}
		EV_Wait(15);
		BGM_Stop( );
		EV_LookFree(player);
		EV_LookPoint(player, 0.0f, 803.0f, -387.04001f);
		EV_Wait(9);
		if ( VoiceLanguage == Languages_English )
		{
			EV_ClrFace(player);
		}
		EV_Wait(21);
		EV_CameraPos(0, 0, 8.6700001f, 751.87f, -235.23f);
		EV_CameraAng(0, 0, 0x994, 0xF80C, 0);
		EV_CameraPos(0, 200, 6.9000001f, 748.38f, -220.75f);
		BGM_Play(MusicIDs_evtbgm01);
		EV_Msg(msgTbl_ev0099[ TextLanguage ][ 8 ]); //"\aNo!  It can't be!"
		EV_SerifPlay(1153);
		EV_SetFace(player, "FEFF");
		EV_Wait(80);
		EV_ClrFace(player);
		EV_Wait(30);
		EV_Msg(msgTbl_ev0099[ TextLanguage ][ 9 ]); //"\aI guess he didn't get enough\nthe fir"...
		EV_SerifPlay(1154);
		EV_SetFace(player, "EDFF");
		EV_Wait(80);
		EV_ClrFace(player);
		EV_Wait(30);
		EV_SetAction(player, &action_k_k0012_knuckles, &KNUCKLES_TEXLIST, 1.0f, 0, 2);
		EV_SetAction(player, &action_k_k0013_knuckles, &KNUCKLES_TEXLIST, 1.0f, 1, 0);
		EV_Msg(msgTbl_ev0099[ TextLanguage ][ 10 ]); //"\aYou can't stop me from \nrestoring th"...
		EV_SerifPlay(1155);
		EV_SetFace(player, "FFFF");
		EV_Wait(70);
		EV_ClrFace(player);
		EV_Wait(10);
		EV_SetFace(player, "FFE");
		EV_Wait(40);
		EV_ClrFace(player);
		EV_MsgClose( );
		EV_Wait(60);
		break;
	case 2:
		EV_CameraOff( );
		EV_PadOn( );
		dsStop_all( );
		if ( SONIC_JUMP ) {
			FreeTask(SONIC_JUMP);
			SONIC_JUMP = 0;
		}
		if ( B_OUT ) {
			FreeTask(B_OUT);
			B_OUT = 0;
		}
		EV_InitPlayer(0);
		EV_RemovePlayer(2);
		delete_eggmoble( );
		StgChaos6CtrlOff( );
		EV_SetPos(player, 0.0f, 744.0f, -568.0f);
		EV_SetAng(player, 0, 0, 0);
		EV_Wait(1);
		break;
	}
};