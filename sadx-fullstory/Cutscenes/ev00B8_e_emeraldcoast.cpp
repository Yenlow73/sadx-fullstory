#include <pch.h>

void ev00B8_e_emeraldcoast(int state)
{
	switch (state) {
	case 1:
		player = EV_GetPlayer(0);
		KOUKYU = 0;
		WHITE = 0;
		Frog = 0;
		EV_CameraOn();
		EV_PadOff();
		EV_CanselOn();

		// Big Cutscene

		EV_CreatePlayer(2, BigTheCat, 998.29999f, 78.0f, 777.29999f, 0x19F, 0x320, 0);
		EV_Wait(1);
		big = EV_GetPlayer(2);	
		SetBankDir(101);
		EV_Wait(1);		
		EV_SetPos(big, -761.0, 4.0f, 1438.0f);
		EV_SetAng(big, 0x19F, 0x320, 0);
		EV_ClrAction(big);
		EV_SetAction(big, &action_b_b0007_big, &BIG_TEXLIST, 0.80000001f, 1, 0);
		EV_CreateObject(&Frog,
			big->twp->pos.x - 6.0999999f,
			big->twp->pos.y + 9.5f,
			big->twp->pos.z + 3.0f,
			( int ) big->twp->pos.x - 0x4000,
			( int ) big->twp->pos.y - 0x4000,
			( int ) big->twp->pos.z);
		EV_Wait(1);
		EV_SetMode(Frog, 0);
		EV_SetPos(Frog,
			big->twp->pos.x - 5.0f,
			big->twp->pos.y + 7.8000002f,
			big->twp->pos.z + 6.6999998f);
		EV_SetAng(Frog,
			( int ) big->twp->pos.x - 0x1000,
			( int ) big->twp->pos.y + 0x2800,
			( int ) big->twp->pos.z);
		EV_SetAction(Frog, &action_f_f0003_frog, &big_kaeru_TEXLIST, 2.0f, 1, 0);
		moveObjectOn(Frog, -7.0f, 2.0f, 3.0f, 200, big);
		EV_InitPlayer(0);
		EV_Wait(1);
		EV_SetPos(player, -732.0, 4.0f, 1510.0);
		EV_SetAng(player, 0xF900, 0x9000, 0);
		EV_ClrAction(player);
		EV_SetAction(player, E102_ACTIONS[ 0 ], &E102_TEXLIST, 1.0f, 0, 0);
		EV_CameraPos(1, 0, -742.0, 15.0, 1503.0);
		EV_CameraTargetObj(1, 0, big, 0.0f, 7.0f, 0.0f, 0);
		EV_MovePoint2(big, -747.0, 15.0, 1470.0, 0.30000001f, 0.30000001f);
		EV_Wait(60);
		EV_PlayPad(0, &EV00D4_KAERU);
		EV_Wait(20);
		stopObject(Frog);
		EV_Wait(10);
		dsPlay_oneshot(1333, 0, 0, 0);
		EV_Wait(10);
		//EV_CameraTargetFree( );
		moveObjectOn(Frog, -13.0f, 3.2f, -15.0f, 600, player);
		EV_Wait(30);
		dsStop_num(1325);
		//EV_CameraPos(0, 90, -741.0, 15.0, 1499.0);
		//EV_CameraAng(0, 90, 0x342, 0xF2C0, 0);
		EV_SetAction(big, &action_b_b0006_big, &BIG_TEXLIST, 0.80000001f, 1, 16);
		EV_Wait(40);
		EV_SerifPlay(1335);
		EV_Msg(msgTbl_ev00D4[ TextLanguage ][ 0 ]); //"\aFroggy?"
		EV_Wait(50);
		EV_SetAng(player, 0, 0x2300, 0);
		EV_SetAction(player, E102_ACTIONS[ 2 ], &E102_TEXLIST, 2.5f, 1, 0);
		stopObject(Frog);
		EV_SetPos(Frog,
			player->twp->pos.x - 3.9000001f,
			player->twp->pos.y + 2.8f,
			player->twp->pos.z - 3.9000001f);
		EV_SetAng(Frog,
			( int ) player->twp->pos.x,
			( int ) player->twp->pos.y + 13056,
			( int ) player->twp->pos.z);
		EV_CameraPos(0, 100, -734.0, 15.0, 1502.0);
		EV_CameraAng(0, 100, 0xCBF, 0xBC4, 0);
		EV_SetAction(big, &action_b_b0012_big, &BIG_TEXLIST, 2.3f, 1, 2);
		EV_Wait(50);
		EV_SetAction(big, &action_b_b0012_big, &BIG_TEXLIST, 0.40000001f, 1, 12);
		EV_SetAng(big, 0x800, 0xA400, 0);
		EV_Wait(10);
		EV_SetAction(big, &action_b_b0012_big, &BIG_TEXLIST, 0.2f, 1, 8);
		EV_SerifPlay(1336);
		EV_Msg(msgTbl_ev00D4[ TextLanguage ][ 1 ]); //"\aUh oh!"
		EV_Wait(20);
		EV_SetAction(big, &action_b_b0012_big, &BIG_TEXLIST, 0.1f, 1, 8);
		EV_Wait(65);
		moveObjectOn(Frog, -15.0f, 6.8000002f, -16.5f, 600, player);
		EV_PlayPad(0, &EV00D4_GAMMA);
		dsStop_num(1326);
		EV_Wait(20);
		stopObject(Frog);
		moveObjectOn(Frog, -7.0f, 4.1999998f, -10.5f, 600, player);
		EV_ClrAction(big);
		EV_SetAction(big, &action_b_b0020_big, &BIG_TEXLIST, 2.0f, 1, 4);
		EV_ClrAction(player);
		EV_CameraPerspective(1, 60, 0x2EEF);
		EV_Wait(1);
		EV_CameraTargetObj(1, 30, big, 0.0f, 6.0f, 0.0f, 0);
		EV_CameraPos(1, 80, -714.0, 15.0, 1497.5);
		EV_SerifPlay(1337);
		EV_Msg(msgTbl_ev00D4[ TextLanguage ][ 2 ]); //"\aNO, hold on there!\nCome back, please"...
		EV_PlayPad(2, &EV00D4_BIG);
		EV_SerifPlay(1338);
		EV_CameraTargetFree( );
		EV_CameraAng(1, 110, 0x2100, 0x20C1, 0);
		EV_Msg(msgTbl_ev00D4[ TextLanguage ][ 3 ]); //"\aGive me my friend back!\nI'm beggin' "...
		EV_Wait(20);	
		stopObjectAll( );
		EV_SetAction(player, E102_ACTIONS[ 3 ], &E102_TEXLIST, 2.0f, 1, 0);
		EV_Wait(121);
		EV_MsgClose( );

		// Gamma Cutscene
		
		EventSe_Init(1);
		BGM_Play(MusicIDs_tical);
		EV_SetPos(big, 45.0, 5.0, 1075.0);
		EV_SetAng(big, 0xF900, 0xB000, 0);
		EV_ClrAction(big);
		EV_SetAction(big, BIG_ACTIONS[73], &BIG_TEXLIST, 0.2, 1, 0);
		EV_SetPos(player, 125.0, 5.0, 1175.0);
		EV_SetAng(player, 0, 0, 0);
		KOUKYU = CTikalLight_Create(
			player->twp->pos.x - 20.2862f,
			player->twp->pos.y + 18.0f,
			player->twp->pos.z + 17.0f);
		EV_SetMode(KOUKYU, 0);
		EV_CreateObject(&Frog,
			player->twp->pos.x + 13.0f,
			player->twp->pos.y,
			player->twp->pos.z + 14.0f, 0, 0x8000, 0);
		EV_SetMode(Frog, 0);
		EV_Wait(1);
		EV_SetAng(Frog, 0, -0x4900, 0);
		EV_ClrAction(player);
		EV_ClrAction(Frog);
		EV_SetAction(player, E102_ACTIONS[ 45 ], &E102_TEXLIST, 1.0f, 1, 0);
		EV_SetAction(Frog, &action_f_f0003_frog, &big_kaeru_TEXLIST, 1.0f, 1, 0);
		EV_CameraPos(1, 0,
			player->twp->pos.x,
			player->twp->pos.y + 16.497999f,
			player->twp->pos.z + 28.820999f);
		EV_CameraAng(1, 0, 0xF800, 0, 0);
		EV_SetPath(KOUKYU, &epathtag_E00B8TK, 0.60000002f, 2);
		EV_Wait(120);
		EV_CameraPos(1, 30,
			player->twp->pos.x,
			player->twp->pos.y + 15.717f,
			player->twp->pos.z + 24.9f);
		EventSe_Play(0, 760, 90);
		WHITE = COverlayCreate(0.016666668f, 0.0f, 1.0f, 1.0f, 1.0f);
		EV_Wait(90);
		break;
	case 2:
		EventSe_Close( );
		EV_CameraOff( );
		EV_PadOn( );
		EV_FreeObject(&Frog);
		EV_InitPlayer(0);
		if ( WHITE )
		{
			FreeTask(WHITE);
			WHITE = 0;
		}
		EV_ClrPath(KOUKYU);
		if ( KOUKYU )
		{
			FreeTask(KOUKYU);
			KOUKYU = 0;
		}
		stopObjectAll( );
		EV_RemovePlayer(2);
		EV_SerifStop( );
		break;
	}
};