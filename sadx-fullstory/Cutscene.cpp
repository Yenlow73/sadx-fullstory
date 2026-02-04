#include "pch.h"

void ev004D_t_missile(int state)
{
	//task* task_gattai = 0;

	switch ( state ) {
	case 1:
		player = EV_GetPlayer(0);
		tikal_dispSwitch(0);
		gSkyScale.x = 1.069f;
		gSkyScale.y = 1.309999f;
		gSkyScale.z = 1.309f;
		EV_CameraOn( );
		EV_PadOff( );
		EV_CanselOn( );
		SetBankDir(91);
		EventSe_Init(4);
		EV_InitPlayer(0);
		seqVars[ 1 ] = 0;
		EV_SetPos(player, 340.01001f, 0.0099999998f, 1650.25f);
		EV_SetAng(player, 0, 0x4300, 0);
		EV_SetMode(player, 0);
		EV_CreatePlayer(2, AmyRose, 340.01001f, 0.0099999998f, 1630.25f, 0, 0x7800, 0);
		EV_Wait(1);
		amy = EV_GetPlayer(2);
		EV_SetPos(amy, 340.01001f, 0.0099999998f, 1630.25f);
		EV_SetAng(amy, 0, 0x7800, 0);
		KOTORI = SetEventBirdie0( );
		EV_SetPos(KOTORI, 340.01001f, 0.0099999998f, 1630.25f);
		EV_SetAng(KOTORI,
			amy->twp->ang.x,
			0x4000 - amy->twp->ang.y,
			amy->twp->ang.z);
		EV_Wait(1);
		EV_SetMode(KOTORI, 0);
		EV_SetAction(KOTORI, &action_w_w9001_wing, &VER2_WING_TEXLIST, 1.0f, 1, 0);
		EV_CreateObjectFunc(&TEPODON, Create_EV_Eggmissile, 701.5f, -1300.25f, 3900.2f, 0xFFF0, 0, 0);
		EV_Wait(1);
		SetEggMissileParam(TEPODON, 0.25f);
		create_eggmoble(233.3f, 82.800003f, 1545.0f, 0, 0xD000, 0);
		EV_Wait(2);
		ChgEggMobleMod(5);
		EV_Wait(2);
		eggmoble = GetEggMobleTask( );
		EV_ClrAction(eggmoble);
		throughplayer_on(amy);
		EV_Wait(1);
		BGM_Play(MusicIDs_s_square);
		EV_CameraPos(1, 0, 136.0f, 30.200001f, 1507.8f);
		EV_CameraAng(1, 0, 0x1400, 0x2C00, 0);
		EV_CameraPos(1, 280, 76.779999f, 35.200001f, 1586.6f);
		EV_CameraAng(1, 280, 0x139A, 0x6177, 0);
		create_task_gattai_EV004D( );
		EV_Wait(20);
		EV_SetMode(player, 0);
		EV_SetMode(amy, 0);
		EV_SetAction(player, &action_m_m0002_miles, &MILES_TEXLIST, 1.0f, 1, 0);
		EV_SetAction(amy, &action_a_a0014_amy, &AMY_TEXLIST, 1.0f, 1, 0);
		EV_SetPath(player, &epathtag_cube_006d_14, 0.2f, 0);
		EV_Wait(40);
		EV_SetPath(KOTORI, &epathtag_cube_006d_14, 0.2f, 0);
		EV_Wait(220);
		EV_CameraPos(1, 200, -0.30000001f, 3.3900001f, 1510.0f);
		EV_CameraAng(1, 200, 0xC9A, 0x6377, 0);
		EV_Wait(200);
		EV_CameraTargetFree( );
		EV_CameraPos(1, 0, -67.400002f, 40.0f, 1497.0f);
		EV_CameraAng(1, 0, 0x347, 0x4ED7, 0);
		EV_CameraPos(1, 170, -69.300003f, 4.4000001f, 1496.3f);
		EV_CameraAng(1, 170, 0x247, 0x3207, 0);
		EV_ClrPath(player);
		kill_task_gattai_EV004D( );
		EV_ClrPath(KOTORI);
		EV_SetMode(amy, 3);
		EV_SetPos(amy, -91.699997f, 0.0f, 1479.1f);
		EV_SetAng(amy, 0, 0, 0);
		EV_SetAction(amy, AMY_ACTIONS[ 69 ], &AMY_TEXLIST, 1.0f, 1, 0);
		EV_SetMode(player, 3);
		EV_SetPos(player, -82.199997f, 0.0f, 1493.28f);
		EV_SetAng(player, 0, 0x8000, 0);
		EV_ClrAction(player);
		EV_SetAction(player, &action_m_m0109_miles, &MILES_TEXLIST, 1.0f, 1, 0);
		EV_Wait(10);
		EV_SetPos(KOTORI, -90.0f, 55.0f, 1520.5f);
		EV_SetAng(KOTORI,
			( int ) ( amy->twp->pos.x - 768.0f ),
			( int ) ( amy->twp->pos.y - 28672.0f ),
			( int ) ( amy->twp->pos.z ));
		EV_SetMode(KOTORI, 0);
		EV_SetAction(KOTORI, &action_w_w9001_wing, &VER2_WING_TEXLIST, 1.0f, 1, 0);
		moveObject(KOTORI, -90.0f, 54.0f, 1512.5f,
			amy->twp->pos.x - 0.5f,
			amy->twp->pos.y + 6.5f,
			amy->twp->pos.z + 6.0f,
			200);
		EV_Wait(85);
		EV_SetAction(amy, &action_a_a0011_amy, &AMY_TEXLIST, 1.2f, 1, 16);
		EV_Wait(75);
		EV_SetAction(player, &action_m_m0110_miles, &MILES_TEXLIST, 1.4f, 0, 0);
		EV_SetAction(player, &action_m_m0111_miles, &MILES_TEXLIST, 1.4f, 1, 8);
		EV_Wait(38);
		eggmoble_moveandturn(180.89999f, 8.5f, 1303.0f, 0xE000, 0xD600, 0xE000, 120, 0);
		EV_SetAng(amy, 0, 0, 0);
		EV_SetAng(player, 0, 0x5900, 0);
		EV_SetPos(KOTORI,
			amy->twp->pos.x - 0.5f,
			amy->twp->pos.y + 4.5f,
			amy->twp->pos.z + 5.4000001f);
		EV_SetAng(KOTORI,
			( int ) ( amy->twp->pos.x ),
			( int ) ( amy->twp->pos.y + 10496.0f ),
			( int ) ( amy->twp->pos.z ));
		EV_ClrAction(player);
		EV_SetAction(player, &action_m_m0109_miles, &MILES_TEXLIST, 1.0f, 1, 0);
		EV_SetAction(amy, AMY_ACTIONS[ 69 ], &AMY_TEXLIST, 1.0f, 1, 0);
		EV_CameraPos(1, 0, -90.599998f, 5.4000001f, 1498.1f);
		EV_CameraAng(1, 0, 0xC47, 0xC1D7, 0);
		EV_CameraAng(1, 140, 0xA47, 0xCFD7, 0);
		EV_Wait(140);
		ChgEggMobleMod(5);
		EventSe_Oneshot(25, 60, 0, 0);
		EV_CameraPos(1, 1, -90.599998f, 6.0f, 1498.1f);
		EV_Wait(1);
		EV_CameraPos(1, 1, -90.599998f, 5.6999998f, 1498.1f);
		EV_Wait(1);
		EV_CameraPos(1, 1, -90.599998f, 5.8000002f, 1498.1f);
		EV_Wait(1);
		EV_CameraPos(1, 1, -90.599998f, 5.5999999f, 1498.1f);
		EV_Wait(1);
		EV_CameraPos(1, 1, -90.599998f, 5.9000001f, 1498.1f);
		EV_Wait(1);
		EventSe_Oneshot(25, 40, 0, 0);
		RumbleA(0, 1);
		EV_CameraPos(1, 1, -90.599998f, 5.6999998f, 1498.1f);
		EV_Wait(1);
		EventSe_Oneshot(16, 30, 0, 0);
		RumbleA(0, 1);
		BGM_Stop( );
		EV_CameraPos(1, 1, -90.599998f, 5.9000001f, 1498.1f);
		EV_Wait(1);
		EV_CameraPos(1, 1, -90.599998f, 5.4000001f, 1498.1f);
		EV_Wait(1);
		EV_CameraPos(1, 1, -90.599998f, 5.5999999f, 1498.1f);
		EV_Wait(1);
		EV_CameraPos(1, 1, -90.599998f, 5.4000001f, 1498.1f);
		EV_Wait(1);
		RumbleA(0, 1);
		EV_CameraPos(1, 1, -90.599998f, 5.5f, 1498.1f);
		EV_Wait(1);
		EV_CameraPos(1, 1, -90.599998f, 5.4000001f, 1498.1f);
		EV_Wait(1);
		EV_CameraPos(1, 1, -90.599998f, 5.5f, 1498.1f);
		EV_Wait(1);
		EV_CameraPos(1, 1, -90.599998f, 5.4000001f, 1498.1f);
		EV_Wait(40);	
		EV_SetAng(player, 0, 0x3000, 0);
		EV_LookFree(player);
		EV_SetAng(amy, 0, 0x1000, 0);
		EV_SetPos(KOTORI,
			amy->twp->pos.x - 2.0f,
			amy->twp->pos.y + 5.0f,
			amy->twp->pos.z + 4.5f);
		EV_SetAng(KOTORI,
			( int ) ( amy->twp->pos.x ),
			( int ) ( amy->twp->pos.y + 10240.0f ),
			( int ) ( amy->twp->pos.z ));
		EV_Wait(1);
		EV_CameraPos(1, 0, -73.669998f, 5.9499998f, 1498.6f);
		EV_CameraAng(1, 0, 0x147, 0x2807, 0);
		EV_CameraPos(1, 120, -75.300003f, 6.02f, 1497.5f);
		EV_CameraAng(1, 120, 0x147, 0x28D7, 0);
		EV_Wait(130);
		EV_ClrFace(player);
		EV_SetFace(player, "BAABAAAAAABABAAAAABAA");
		EV_Wait(60);
		EV_ClrFace(player);
		EV_SetPos(KOTORI,
			amy->twp->pos.x - 5.0f,
			amy->twp->pos.y + 4.5f,
			amy->twp->pos.z + 6.5f);
		EV_SetAng(KOTORI,
			( int ) ( amy->twp->pos.x ),
			( int ) ( amy->twp->pos.y + 12288.0f ),
			( int ) ( amy->twp->pos.z ));
		EV_CameraPos(1, 0, -102.8f, 14.7f, 1508.2f);
		EV_CameraAng(1, 0, 0xFB47, 0xDBD7, 0);
		EV_CameraPos(0, 50, -100.17f, 8.6999998f, 1512.2f);
		EV_CameraAng(0, 50, 0xFB47, 0xE8D7, 0);
		EV_LookObject(amy, player, 6.0f, 5.0f, 0.0f);
		EV_SetAction(player, &action_m_m0139_miles, &MILES_TEXLIST, 0.80000001f, 0, 0);
		EV_SetAction(player, &action_m_m0140_miles, &MILES_TEXLIST, 1.0f, 0, 0);
		EV_Wait(50);
		EV_CameraTargetObj(1, 40, player, 0.0f, 5.0f, 0.0f, 0);
		EV_WaitAction(player);
		EV_ClrAction(player);
		EV_SetAction(player, MILES_ACTIONS[ 47 ], &MILES_TEXLIST, 1.0f, 1, 0);
		EV_MovePoint2(player, 11.2f, 0.0f, 1523.0f, 0.69999999f, 0.029999999f);
		EV_Wait(70);
		//EV_RemovePlayer(2);
		EV_FreeObject(&KOTORI);
		EV_MoveFree(player);
		EV_MovePoint2(player, 118.2f, 0.0f, 1465.0f, 0.30000001f, 0.029999999f);
		EV_SetPos(player, 21.01f, 0.0099999998f, 1523.25f);
		EV_SetAng(player, 0, 0x5646, 0);
		EV_CameraPos(1, 0, 37.799999f, 6.5f, 1518.5f);
		EV_CameraChase(player);
		EV_Wait(30);
		EV_ClrFace(player);
		if ( VoiceLanguage == Languages_Japanese )
		{
			EV_SetFace(player, "DABAADCCC");
		}
		if ( VoiceLanguage == Languages_English )
		{
			EV_SetFace(player, "DBED");
		}
		EV_SerifPlay(792);
		EV_Msg(msgTbl_ev004D[ TextLanguage ][ 0 ]); //"\aThat's Eggman!  I wonder\nwhat happen"...
		EV_Wait(90);
		EV_CameraChaseFree( );
		EV_MsgClose( );
		EV_CameraTargetFree( );
		EV_ClrFace(player);
		EV_CameraPos(1, 0, 120.9f, 4.5999999f, 1445.8f);
		EV_CameraAng(1, 0, 0xEAD, 0xF490, 0x400);
		EV_CameraPos(0, 100, 149.7f, 7.48f, 1455.38f);
		EV_CameraAng(0, 100, 0x7AD, 0xF790, 0x400);
		//EV_Wait(100);
		EV_CameraPos(0, 120, 155.17999f, 9.2299995f, 1430.86f);
		EV_CameraAng(0, 120, 0x5AD, 0xF790, 0x400);
		//EV_Wait(120);

		// Amy Cutscene Start

		BGM_Play(MusicIDs_theamy);

		hoge1 = CIchimaie2_Create(&texlist_icm006D, 0);
		CIchimaie2_SetTextureId(hoge1, 0);
		CIchimaie2_SetPriority(hoge1, -5.0f);
		hoge2 = CIchimaie2_Create(&texlist_icm006D, 0);
		CIchimaie2_SetTextureId(hoge2, 1);
		CIchimaie2_SetPriority(hoge2, -3.0f);

		KOTORI = SetEventBirdie0();
		//EV_SetPos(KOTORI, 340.01001f, 0.0099999998f, 1630.25f);
		EV_SetAng(KOTORI,
			amy->twp->ang.x,
			0x4000 - amy->twp->ang.y,
			amy->twp->ang.z);
		EV_SetMode(KOTORI, 0);
		EV_SetShadow(KOTORI, 0.5f);


		EV_CreateObject(&KOTORI,
			-16.4f, 4.0f, 1531.38f,
			( int ) amy->twp->pos.x,
			( int ) amy->twp->pos.y,
			( int ) amy->twp->pos.z);
		EV_SetMode(KOTORI, 0);
		EV_SetAction(KOTORI, &action_w_w9001_wing, &VER1_WING_TEXLIST, 1.0f, 1, 0);

		EV_SetMode(amy, 3);
		EV_SetPos(amy, -18.4f, 0.0f, 1534.46f);
		EV_SetAng(amy, 0, 0x8146, 0);
		EV_LookFree(amy);


		EV_ClrFace(amy);
		EV_Wait(40);
		EV_CameraPos(1, 180, -15.93f, 2.9200001f, 1519.62f);
		EV_CameraAng(1, 180, 0x300, 0x7800, 0);
		EV_ClrAction(amy);
		EV_SetAction(amy, &action_a_a0830_amy, &AMY_TEXLIST, 1.0f, 1, 8);
		
		EV_Wait(270);
		EV_SetFace(amy, "CDE");
		EV_SerifPlay(964);
		EV_Msg(msgTbl_ev006D[ TextLanguage ][ 0 ]); //"\aI wonder what Sonic is doing..."
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(amy);
		EV_SetFace(amy, "DECDED");
		EV_SerifPlay(965);
		EV_Msg(msgTbl_ev006D[ TextLanguage ][ 1 ]); //"\aHe's always rescuing me, it seems."
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(amy);
		EV_ClrAction(player);
		//EV_RemovePlayer(3);
		EV_Wait(1);
		//moveObject(KOTORI, -23.280001f, 9.0f, 1531.51f, -16.4f, 4.0f, 1531.38f, 60);
		if ( VoiceLanguage == Languages_Japanese )
		{
			EV_SetFace(amy, "NNN");
		}
		if ( VoiceLanguage == Languages_English )
		{
			EV_SetFace(amy, "FF");
		}
		EV_SerifPlay(966);
		//EV_LookFree(amy);
		EV_ClrAction(amy);
		EV_SetAction(amy, &action_a_a0831_amy, &AMY_TEXLIST, 0.5f, 1, 32);
		EV_Msg(msgTbl_ev006D[ TextLanguage ][ 2 ]); //"\aI should be more independent."
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(amy);
		EV_ClrAction(amy);
		EV_SetAction(amy, &action_a_a0833_amy, &AMY_TEXLIST, 1.0f, 1, 0);
		EV_CreateObject(&KOTORI,
			-17.4f, 0.0f, 1533.46f,
			( int ) amy->twp->pos.x,
			( int ) amy->twp->pos.y,
			( int ) amy->twp->pos.z);
		EV_ClrAction(KOTORI);
		EV_SetAction(KOTORI, &action_w_w0833_wing, &VER1_WING_TEXLIST, 1.0f, 1, 0);
		EV_MovePoint2(amy, 115.86f, 0.0053099999f, 1522.62f, 0.2f, 0.1f);
		stopObject(KOTORI);
		moveObjectOn(KOTORI, 0.0f, 0.0f, 0.0f, 50, amy);
		EV_Wait(40);
		EV_MsgClose( );
		EV_Wait(10);
		stopObject(KOTORI);
		moveObjectOn(KOTORI, 0.0f, 1.0f, 0.0f, 480, amy);
		EV_CameraTargetObj(1, 0, amy, 0.0f, 5.0f, 0.0f, 0);
		EV_CameraPos(1, 0, 15.409f, 9.6499996f, 1541.035f);
		EV_CameraAng(1, 0, 0xFA00, 0x3D00, 0);
		EV_CameraChase(amy);
		EV_Wait(40);
		EV_SetFace(amy, "CDEDCDEC");
		EV_SerifPlay(967);
		EV_MsgW(100, msgTbl_ev006D[ TextLanguage ][ 3 ]); //"\aYou know, you sure surprised me...\nb"...
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(amy);
		EV_CameraChaseFree( );
		EV_Wait(30);
		EV_SetFace(amy, "CDEDCDEC");
		EV_SerifPlay(968);
		EV_MsgW(100, msgTbl_ev006D[ TextLanguage ][ 4 ]); //"\aNo wonder they were after you,\nmy fe"...
		EV_ClrFace(amy);
		EV_Wait(40);
		EV_CameraPos(1, 60, 86.919998f, 7.5500002f, 1535.65f);
		EV_Wait(60);
		EV_MoveFree(amy);
		EV_SetAction(amy, &action_a_a0836_amy, &AMY_TEXLIST, 1.0f, 1, 0);
		EV_SetAction(KOTORI, &action_w_w0836_wing, &VER1_WING_TEXLIST, 1.0f, 1, 0);
		createModel(-109.708f, 10.005f, 1486.616f, 0, 0, 0, 1.0f, 1.0f, 1.0f, &object_locket_locket, &texlist_locket, 1);
		addmotModel(1, &action_locket, 0);
		EV_Wait(1);
		EV_SetFace(amy, "H");
		EV_SerifPlay(969);
		EV_Msg(msgTbl_ev006D[ TextLanguage ][ 5 ]); //"\aHey!   A pendant, wow!"
		EV_Wait(10);
		EV_CameraTargetFree( );
		EV_CameraPos(1, 0, -113.545f, 10.0f, 1486.52f);
		EV_CameraAng(1, 0, 0, 0xBF00, 0);
		EV_CameraPerspective(1, 1, 0x1C72);
		CIchimaie2_SetDstAlpha(hoge1, 1.0f, 1);
		playModel(1, 0, 0.0000099999997f, 1);
		EV_Wait(7);
		stopModel(1);
		EV_Wait(60);
		CIchimaie2_SetDstAlpha(hoge1, 0.80000001f, 40);
		EV_Wait(1);
		CIchimaie2_SetDstAlpha(hoge2, 1.0f, 40);
		EV_Wait(60);
		deleteModel(1);
		CIchimaie2_SetDstAlpha(hoge1, 0.0f, 40);
		EV_Wait(30);
		EV_CameraPos(0, 0, 102.383f, 7.5229998f, 1506.658f);
		EV_CameraTargetObj(1, 0, amy, 0.0f, 5.0f, 0.0f, 0);
		CIchimaie2_SetDstAlpha(hoge2, 0.0f, 40);
		EV_CameraPerspective(1, 30, 0x31C7);
		EV_Wait(1);
		EV_SetAction(KOTORI, &action_w_w0833_wing, &VER1_WING_TEXLIST, 1.0f, 1, 0);
		EV_SetAction(amy, &action_a_a0833_amy, &AMY_TEXLIST, 1.0f, 1, 0);
		stopObject(KOTORI);
		EV_MovePoint2(amy, 115.86f, 0.0053099999f, 1522.62f, 0.1f, 2.0f);
		moveObjectOn(KOTORI, 0.0f, 0.5f, 0.0f, 490, amy);
		EV_Wait(30);
		EV_SetFace(amy, "CD");
		EV_SerifPlay(970);
		EV_Msg(msgTbl_ev006D[ TextLanguage ][ 6 ]); //"\aSo, I'll help you find your family."
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(amy);
		EV_SetFace(amy, "CDEDCDE");
		EV_SerifPlay(971);
		EV_Msg(msgTbl_ev006D[ TextLanguage ][ 7 ]); //"\aDoes Eggman have them captive now?"
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(amy);
		EventSe_Oneshot(1338, 0, 0, 0);
		EV_Msg(msgTbl_ev006D[ TextLanguage ][ 8 ]); //"\a........"
		EV_Wait(60);
		EV_MsgClose( );
		EV_WaitMove(amy);
		stopObject(KOTORI);
		EV_SetAng(amy, 0, 0x1863, 0);
		EV_SetAng(KOTORI, 0, 0x1863, 0);
		moveObjectOn(KOTORI, 0.0f, 0.5f, 0.0f, 600, amy);
		EV_CameraTargetFree( );
		EV_CameraPos(1, 0, 121.319f, 9.6990004f, 1536.274f);
		EV_CameraAng(1, 0, 0xF59E, 0x10C0, 0);
		EV_SetAction(amy, &action_a_a0837_amy, &AMY_TEXLIST, 1.0f, 1, 0);
		EV_SetAction(KOTORI, &action_w_w0837_wing, &VER1_WING_TEXLIST, 1.0f, 1, 0);
		EV_SetFace(amy, "CD");
		EV_SerifPlay(972);
		EV_Msg(msgTbl_ev006D[ TextLanguage ][ 9 ]); //"\aI bet he does!"
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(amy);
		EV_SetFace(amy, "CD");
		EV_SerifPlay(973);
		EV_Msg(msgTbl_ev006D[ TextLanguage ][ 10 ]); //"\aSo, I'll help you find your family."
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(amy);
		EV_SetFace(amy, "EDCD");
		EV_SerifPlay(974);
		EV_Msg(msgTbl_ev006D[ TextLanguage ][ 11 ]); //"\aI've come this far. \nI may as well g"...
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(amy);
		EV_SetFace(amy, "UXI");
		EV_Wait(1);
		EV_SetFace(amy, "CDEDCD");
		EV_SerifPlay(975);
		EV_Msg(msgTbl_ev006D[ TextLanguage ][ 12 ]); //"\aThat robot said Dr. Eggman's base\nis"...
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(amy);
		EV_MsgCls( );
		EV_Wait(1);
		EV_CameraPos(1, 0, 157.75999f, 17.271f, 1566.0f);
		EV_CameraAng(1, 0, 0x600, 0x1A00, 0);
		EV_ClrAction(amy);
		EV_SetAction(amy, &action_a_a0832_amy, &AMY_TEXLIST, 1.0f, 1, 0);
		EV_FreeObject(&KOTORI);
		EV_MovePoint2(amy, 82.669998f, 0.0f, 1486.1851f, 0.30000001f, 0.30000001f);
		EV_SerifPlay(976);
		EV_Msg(msgTbl_ev006D[ TextLanguage ][ 13 ]); //"\aSo what d'ya say we check it out?"
		EV_Wait(1);
		EV_SerifWait( );
		throughplayer_off(amy);
		EV_Wait(60);

		// Amy Cutscene End

		
		EV_CameraPos(1, 0, 185.42999f, 13.66f, 1289.67f);
		EV_CameraAng(1, 0, 0x8AD, 0x8A00, 0x100);
		EV_CameraPos(0, 130, 185.89999f, 14.0f, 1291.5699f);
		EV_RemovePlayer(2);
		EV_SerifPlay(793);
		EV_Msg(msgTbl_ev004D[ TextLanguage ][ 1 ]); //"\aI'm finished!"
		EV_Wait(30);
		EV_Msg(msgTbl_ev004D[ TextLanguage ][ 2 ]); //"\aChaos was defeated, and now \nmy Egg "...
		EV_SerifWait( );
		EV_CameraAng(1, 120, 0x11AD, 0x8F00, 0x100);
		EV_SerifPlay(794);
		BGM_Stop( );
		EV_Msg(msgTbl_ev004D[ TextLanguage ][ 3 ]); //"\aNo matter!   I will destroy\nStation "...
		EV_SetPos(player, 136.2f, 0.0f, 1460.86f);
		EV_SetAng(player, 0, 0x7600, 0);
		EV_ClrAction(player);
		EV_SetAction(player, &action_m_m0109_miles, &MILES_TEXLIST, 1.0f, 1, 0);
		EV_Wait(77);
		EV_CameraPos(0, 9, 186.22f, 14.42f, 1292.4f);
		EventSe_Oneshot(1335, 110, 0, 0);
		EV_Wait(7);
		BGM_Play(MusicIDs_evtbgm01);
		EV_SerifWait( );
		EV_MsgClose( );
		EV_ClrAction(eggmoble);
		EV_SetAction(eggmoble, &action_gm_gm0029_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.2f, 1, 0);
		EV_CameraPos(0, 0, 180.11f, 14.24f, 1281.2f);
		EV_CameraAng(0, 0, 0xFDAD, 0x8800, 0);
		EV_CameraPos(0, 80, 193.84f, 18.27f, 1278.45f);
		EV_CameraAng(0, 80, 0xFDAD, 0x8800, 0);
		EV_Wait(20);
		EV_SetAction(eggmoble, &action_gm_gm0035_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.4f, 0, 4);
		EV_SetAction(eggmoble, &action_gm_gm0004_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.4f, 1, 8);
		EV_Wait(70);
		EV_CameraPos(0, 120, 193.08f, 45.84f, 1275.7f);
		EV_CameraAng(0, 120, 0x3AD, 0x8800, 0);
		EV_Wait(130);
		EV_CameraPos(0, 60, 216.11f, 53.27f, 1391.2f);
		EV_CameraAng(0, 60, 0x26D, 0x8800, 0);
		EV_CameraPos(0, 0, 167.11f, 29.84f, 1574.2f);
		EV_CameraAng(0, 0, 0x2AD, 0x9C00, 0x600);
		EV_CameraPos(0, 120, 113.11f, 40.040001f, 1618.2f);
		eggmoble_moveandturn(236.7f, 40.5f, 1404.0f, -0xE000, -22016, -0xE000, 120, 0);
		EV_Wait(120);
		moveObjectAngle2(TEPODON, 701.5f, -180.25f, 3300.2f, 701.5f, 86.25f, 3300.2f, 0xFFE0, 0, 0, 0xFFF0, 0x2000, 0, 200);
		EV_Wait(3);
		EV_SetPos(player, 118.2f, 0.0f, 1465.0f);
		EV_SetAng(player, 0, 0x1000, 0);
		EV_CameraPos(0, 0, 117.6f, 18.440001f, 1455.2f);
		EV_CameraAng(0, 0, 0xAD, 0x958D, 0);
		EV_CameraPos(1, 40, 106.0f, 4.1100001f, 1437.0f);
		EV_SetAction(player, &action_m_m9001_miles, &MILES_TEXLIST, 1.0f, 0, 0);
		EV_SetAction(player, &action_m_m9002_miles, &MILES_TEXLIST, 1.0f, 1, 0);
		EV_Wait(60);
		EV_CameraPos(0, 70, 96.330002f, 1.87f, 1442.1f);
		EV_CameraAng(0, 70, 0xEAD, 0x9C8D, 0x500);
		EV_SetAction(eggmoble, &action_gm_gm0035_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.0f, 1, 8);
		eggmoble_moveandturn(297.70001f, 8.5f, 1665.0f, 0, 0, 0, 140, 0);
		EV_Wait(70);
		EV_CameraPos(0, 80, 89.559998f, 1.1f, 1449.1801f);
		EV_CameraAng(0, 80, 0xEAD, 0x9C8D, 0x500);
		EV_Wait(80);
		EV_CameraPos(0, 0, 281.59f, 14.42f, 1640.5f);
		EV_CameraAng(0, 0, 0xEAD, 0x998D, 0xFA27);
		EV_CameraPos(0, 110, 277.54999f, 16.049999f, 1645.0f);
		EV_CameraAng(0, 110, 0x7C1, 0x9B7D, 0xFA27);
		eggmoble_moveandturn(297.70001f, 9.5f, 1665.0f, 0, 0x8000, 0, 120, 0);
		EV_Wait(110);
		EV_CameraPos(0, 90, 274.19f, 15.2f, 1648.0f);
		EV_CameraAng(0, 90, 0x7C1, 0x8F57, 0xFA27);
		EV_Wait(110);
		EV_ClrAction(player);
		EV_SetAction(player, &action_m_m0109_miles, &MILES_TEXLIST, 0.80000001f, 1, 0);
		EV_CameraPos(1, 0, 115.23f, 3.3800001f, 1476.6f);
		EV_CameraAng(1, 0, 0x9AD, 0xF68D, 0x100);
		EV_CameraPos(1, 110, 116.0f, 4.5599999f, 1471.8f);
		eggmoble_moveandturn(297.70001f, 9.0f, 1665.0f, 0, -0x8000, 0, 40, 0);
		ChgEggMobleMod(5);
		EV_ClrFace(player);
		if ( VoiceLanguage == Languages_Japanese )
		{
			EV_SetFace(player, "NOO");
		}
		EV_Wait(20);
		EV_SerifPlay(797);
		EV_Msg(msgTbl_ev004D[ TextLanguage ][ 4 ]); //"\aIf that missile is launched..."
		if ( VoiceLanguage == Languages_English )
		{
			EV_SetFace(player, "FO");
		}
		EV_SerifWait( );
		EV_ClrFace(player);
		EV_CameraPos(0, 0, 293.78f, 17.040001f, 1660.89f);
		EV_CameraAng(0, 0, 6317, 42125, 0xFE00);
		EV_CameraPos(0, 8, 295.07001f, 18.17f, 1661.91f);
		EV_CameraAng(0, 8, 6317, 42125, 0xFE00);
		EV_SerifPlay(798);
		EV_Msg(msgTbl_ev004D[ TextLanguage ][ 5 ]); //"\aReady?   Fire!"
		EV_SerifWait( );
		EV_MsgClose( );
		EV_CameraPos(0, 0, 192.56f, 19.780001f, 1430.8f);
		EV_CameraAng(0, 0, 0x7AD, 0x838D, 0x800);
		EV_CameraPos(0, 160, 111.46f, 0.41999999f, 1457.2f);
		EV_CameraAng(0, 160, 0x7AD, 0x8B8D, 0x800);
		RumbleA(0, 10);
		SetMissileEffect(TEPODON, 7);
		EventSe_Play(2, 745, 1800);
		EventSe_Volume(2, 10, 1);
		EV_Wait(1);
		EventSe_Volume(2, 100, 80);
		moveObjectAngle2(TEPODON, 701.5f, 86.25f, 3300.2f, 701.5f, 86.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(2);
		moveObjectAngle2(TEPODON, 701.5f, 86.25f, 3300.2f, 701.5f, 84.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(2);
		moveObjectAngle2(TEPODON, 701.5f, 84.25f, 3300.2f, 701.5f, 86.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(2);
		moveObjectAngle2(TEPODON, 701.5f, 86.25f, 3300.2f, 701.5f, 84.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(2);
		moveObjectAngle2(TEPODON, 701.5f, 84.25f, 3300.2f, 701.5f, 86.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 86.25f, 3300.2f, 701.5f, 84.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 84.25f, 3300.2f, 701.5f, 86.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 86.25f, 3300.2f, 701.5f, 84.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 84.25f, 3300.2f, 701.5f, 87.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 87.25f, 3300.2f, 701.5f, 84.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 84.25f, 3300.2f, 701.5f, 87.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 87.25f, 3300.2f, 701.5f, 84.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 84.25f, 3300.2f, 701.5f, 87.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 87.25f, 3300.2f, 701.5f, 85.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 85.25f, 3300.2f, 701.5f, 84.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 80.25f, 3300.2f, 701.5f, 86.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 86.25f, 3300.2f, 701.5f, 85.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 85.25f, 3300.2f, 701.5f, 80.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 80.25f, 3300.2f, 701.5f, 80.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 80.25f, 3300.2f, 701.5f, 85.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 85.25f, 3300.2f, 701.5f, 85.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 85.25f, 3300.2f, 701.5f, 80.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xFFFF, 0x2000, 0, 2);
		EV_Wait(1);
		moveObjectAngle2(TEPODON, 701.5f, 85.25f, 3300.2f, 701.5f, 1100.25f, 3300.2f, 0xFFFF, 0x2000, 0, 0xF000, 0x4000, 0, 200);
		EV_Wait(80);
		EV_ClrFace(player);
		EV_SetFace(player, "NO");
		EV_Wait(20);
		stopObjectAll( );
		EventSe_Stop(2);
		EventSe_Play(2, 745, 1800);
		EventSe_Volume(2, 50, 1);
		EV_CameraPos(0, 0, 119.8f, 5.8000002f, 1471.5f);
		EV_CameraAng(0, 0, 0x3AD, 0x88D, 0xFF00);
		EV_Wait(15);
		moveObjectAngle2(TEPODON, 351.5f, 320.25f, 2300.2f, 471.5f, 1030.25f, 1800.2f, 0xD800, 0x2000, 0, 0xD800, 0x6000, 0, 100);
		SetEggMissileParam(TEPODON, 0.60000002f);
		EV_Wait(15);
		EV_ClrFace(player);
		EventSe_Play(2, 745, 1800);
		EventSe_Volume(2, 70, 1);
		EV_CameraPos(1, 0, 120.19f, 0.89999998f, 1458.3f);
		EV_CameraAng(1, 0, 0xCFB, 0x828D, 0x300);
		EV_CameraPos(1, 75, 118.19f, 0.62f, 1457.15f);
		EV_CameraAng(1, 75, 0x18FB, 0x8C8D, 0xC00);
		EV_CameraPerspective(1, 80, 0x2FA5);
		EventSe_Stop(2);
		EventSe_Play(2, 745, 1800);
		EventSe_Volume(2, 80, 1);
		EV_Wait(10);
		eggmoble_moveandturn(297.70001f, 9.0f, 1665.0f, 0, -0x3400, 0, 30, 0);
		EV_Wait(5);
		ChgEggMobleMod(5);
		EV_Wait(65);
		EV_SetPos(player, 89.669998f, 0.0f, 1541.1f);
		EV_SetAng(player, 0x7AD, 0x3E90, 0);
		SetEggMissileParam(TEPODON, 0.25f);
		stopObjectAll( );
		EV_CameraPos(1, 0, -15.7f, 270.95001f, 1730.9f);
		EV_CameraAng(1, 0, 0x247, 0xD2D5, 0xFA00);
		EV_CameraPos(1, 170, -12.1f, 31.32f, 1689.4f);
		moveObjectAngle2(TEPODON, 1600.5f, 1300.25f, 1602.2f, 1612.5f, 100.25f, 1000.2f, 0x8B00, 0, 0x1C00, 0x8B00, 0x4000, 0, 160);
		EV_Wait(160);
		EventSe_Stop(2);
		BGM_Stop( );
		EventSe_Oneshot(1339, 110, 0, 0);
		RumbleA(0, 2);
		EV_CameraPos(1, 2, -12.1f, 31.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 32.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 31.0f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 33.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 32.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 34.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 31.0f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 33.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 30.0f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 31.32f, 1689.4f);
		EV_Wait(2);
		RumbleA(0, 2);
		EV_CameraPos(1, 2, -12.1f, 32.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 31.0f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 33.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 32.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 34.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 31.0f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 33.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 30.0f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 31.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 32.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 31.0f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 33.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 32.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 34.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 31.0f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 33.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 30.0f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 31.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 32.0f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 31.0f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 30.32f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 31.0f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 30.5f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 30.799999f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 30.6f, 1689.4f);
		EV_Wait(2);
		EV_CameraPos(1, 2, -12.1f, 30.700001f, 1689.4f);
		EV_Wait(10);
		EV_CameraPos(1, 130, -26.389999f, 29.0f, 1696.4f);
		EV_CameraAng(1, 130, 0x247, 0xD2D5, 0xFB00);
		EV_Wait(130);
		EV_FreeObject(&TEPODON);
		EV_CameraPos(1, 0, 101.28f, 4.6599998f, 1538.6f);
		EV_CameraAng(1, 0, 0x347, 0x57D5, 0xFF00);
		EV_CameraPos(1, 90, 99.660004f, 4.5799999f, 1536.12f);
		EV_ClrFace(player);
		EV_SetFace(player, "BAABAAAAABABAAABAAABBBAA");
		EV_Wait(100);
		EV_ClrFace(player);
		ChgEggMobleMod(5);
		EV_Wait(2);
		EV_CameraPos(1, 0, 302.70001f, 23.200001f, 1660.5f);
		EV_CameraAng(1, 0, 0xF047, 0x5FD5, 0xFB00);
		EV_CameraPos(0, 30, 298.10001f, 19.200001f, 1658.8f);
		EV_CameraAng(0, 30, 0x1147, 0x78D5, 0xFB00);
		EV_SerifPlay(799);
		EV_Msg(msgTbl_ev004D[ TextLanguage ][ 6 ]); //"\aAah!  No!   It was a dud!"
		EV_SerifWait( );
		EV_CameraPos(0, 30, 292.89999f, 16.0f, 1657.0f);
		EV_CameraAng(0, 30, 0x1300, 0x96D5, 0xFB00);
		EV_SetAction(eggmoble, &action_gm_gm0034_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.0f, 1, 8);
		EV_SerifPlay(800);
		EV_Msg(msgTbl_ev004D[ TextLanguage ][ 7 ]); //"\aI can't believe this!"
		EV_SerifWait( );
		EV_CameraPos(1, 0, 280.0f, 6.4000001f, 1698.5f);
		EV_CameraAng(1, 0, 0x247, 0xF4D5, 0x600);
		EV_CameraPos(1, 80, 245.86f, 10.36f, 1698.5f);
		EV_CameraAng(1, 80, 0x247, 0xF4D5, 0x600);
		EV_SerifPlay(801);
		EV_Msg(msgTbl_ev004D[ TextLanguage ][ 8 ]); //"\aAh!  I'll go and deal \nwith this mys"...
		eggmoble_moveandturn(297.70001f, 13.0f, 1665.0f, 0, -0x1000, 0, 60, 1);
		BGM_Play(MusicIDs_hurryup);
		EV_ClrAction(eggmoble);
		EV_Wait(65);
		EventSe_Play(1, 1336, 1800);
		EventSe_Volume(1, -60, 1);
		EV_Wait(1);
		EventSe_Volume(1, -50, 80);
		eggmoble_moveandturn(309.70001f, 19.0f, 1416.0f, 0, 0, 0, 100, 1);
		EV_Wait(70);
		EV_CameraPos(1, 0, 76.0f, 7.1999998f, 1552.5f);
		EV_CameraAng(1, 0, 0xFF47, 0xC6D5, 0x600);
		EV_CameraPos(0, 55, 73.699997f, 5.1999998f, 1538.8f);
		EV_Wait(50);
		EventSe_Volume(1, -80, 80);
		EV_CameraPos(1, 0, 104.0f, 0.80000001f, 1536.9f);
		EV_CameraAng(1, 0, 0xD47, 0x4AD5, 0x600);
		EV_CameraPos(1, 100, 96.5f, 3.6700001f, 1539.1f);
		EV_ClrFace(player);
		EV_SetFace(player, "OEE");
		EV_SerifPlay(802);
		EV_Msg(msgTbl_ev004D[ TextLanguage ][ 9 ]); //"\aOh, no!"
		EV_SerifWait( );
		EV_ClrFace(player);
		EV_SetFace(player, "DECDDDEEE"); //"\aI'd better get to that missile\nbefor"...
		EV_SerifPlay(803);
		EV_Msg(msgTbl_ev004D[ TextLanguage ][ 10 ]);
		eggmoble_moveandturn(309.70001f, 27.0f, 1416.0f, 0, -0x4000, 0, 125, 1);
		EV_Wait(40);
		EV_CameraPos(1, 0, 82.199997f, 8.0f, 1549.4f);
		EV_CameraAng(1, 0, 0x1347, 0xD5D5, 0x600);
		EV_CameraPos(1, 90, 83.900002f, 2.27f, 1549.4f);
		EV_CameraAng(1, 90, 0xA47, 0xD5D5, 0x600);
		EV_SerifWait( );
		EV_ClrFace(player);
		EV_Wait(60);
		EventSe_Stop(1);
		gSkyScale = SkyBoxScale_StationSquare[ ssActNumber ][ ClipLevel ];
		break;
	case 2:
		if ( hoge1 )
		{
			FreeTask(hoge1);
			hoge1 = 0;
		}
		if ( hoge2 )
		{
			FreeTask(hoge2);
			hoge2 = 0;
		}

		gSkyScale = SkyBoxScale_StationSquare[ ssActNumber ][ ClipLevel ];
		EV_CameraOff( );
		EV_PadOn( );
		EventSe_Stop(1);
		EventSe_Close( );
		stopObjectAll( );
		EV_ClrPath(player);
		kill_task_gattai_EV004D( );
		EV_ClrPath(KOTORI);
		EV_InitPlayer(0);
		EV_RemovePlayer(2);
		EV_FreeObject(&KOTORI);
		delete_eggmoble( );
		EV_FreeObject(&TEPODON);
		EV_Wait(1);
		break;
	}
}

void ev00F9_l_snoozecruise(int state)
{
	switch ( state ) {
	case 1:
		player = EV_GetPlayer(0);
		WHITE = 0;
		WHITE2 = 0;
		EV_CameraOn( );
		EV_PadOff( );
		EV_CanselOn( );
		EventSe_Init(1);
		EV_CameraPerspective(1, 1, 0x3111);
		WHITE = COverlayCreate(1.0f, 0.1f, 1.0f, 1.0f, 1.0f);
		EventSe_Play(0, 760, 1800);
		EventSe_Volume(0, -120, 120);
		EV_SetPos(player, -44.7327f, -263.29999f, 2621.6599f);
		EV_SetAng(player, 0x800, 0xD00, 0);
		EV_InitPlayer(0);
		EV_SetAction(player, SONIC_ACTIONS[1], &SONIC_TEXLIST, 1.0f, 1, 0);
		EV_SetFace(player, "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV");
		//EV_LookPoint(player, -45.220001f, -260.0f, 2632.0f);
		//tails = EV_GetPlayer(2);
		//EV_LookObject(tails, player, 0.0f, 6.0f, 0.0f); //Why is this before Tails is spawned. Would make his head follow Sonic but there's no change in the cutscene because he's already facing him.
		EV_CreatePlayer(2, MilesTalesPrower, -45.228001f, -263.1676f, 2639.0667f, 0x884, 0x8600, 0x44);
		EV_InitPlayer(2);
		EV_Wait(1);
		tails = EV_GetPlayer(2);
		EV_SetAction(tails, MILES_ACTIONS[ 79 ], &MILES_TEXLIST, 0.69999999f, 1, 0);
		EV_SerifPlay(1451);
		EV_Msg(msgTbl_ev00F9[ TextLanguage ][ 0 ]); //"\aSonic!   Wake up!"
		EV_Wait(10);
		if ( WHITE )
		{
			COverlaySetSpeed(WHITE, -0.0083333338f);
		}
		EV_CameraPos(1, 0, -47.595001f, -261.85699f, 2635.345f);
		EV_CameraAng(1, 0, 0x1B00, 0xFD00, 0x1600);
		EV_CameraPos(1, 100, -47.362999f, -259.39999f, 2632.2f);
		EV_CameraAng(0, 50, 0x1B00, 0xFD00, 0xF200);
		EV_Wait(50);
		EV_CameraAng(0, 30, 0x1B00, 0xFD00, 0xF00);
		EV_Wait(30);
		EV_CameraAng(0, 20, 0x1B00, 0xFD00, 0x800);
		EV_MsgClose( );
		EV_LookFree(player);
		EV_SetFace(player, "BA");
		EV_SerifPlay(1452);
		EV_Msg(msgTbl_ev00F9[ TextLanguage ][ 1 ]); //"\aAhhh... \nI was on a snooze cruise, I"...
		EV_Wait(20);
		EV_SetFace(player, "AEAAD");
		EV_Wait(1);
		EV_SetFace(tails, "NNNNNNNN");
		EV_SerifWait( );
		EV_CameraPerspective(1, 1, 0x6AAB);
		WHITE2 = COverlayCreate(0.5f, 0.0099999998f, 1.0f, 1.0f, 1.0f);
		EV_Wait(1);
		if ( WHITE2 )
		{
			COverlaySetSpeed(WHITE2, 0.0f);
		}
		EV_CameraPos(1, 0, -45.990002f, -259.466f, 2633.8799f);
		EV_CameraAng(1, 0, 0x300, 0x8600, 0x100);
		EV_CameraPerspective(0, 80, 0x3111);
		if ( WHITE2 )
		{
			COverlaySetSpeed(WHITE2, -0.011111111f);
		}
		EV_Wait(83);
		EV_SerifPlay(1453);
		EV_ClrFace(tails);
		EV_SetFace(tails, "PG");
		EV_Msg(msgTbl_ev00F9[ TextLanguage ][ 2 ]); //"\aGood thing you're okay."
		EV_Wait(1);
		EV_SerifWait( );
		EV_Wait(20);
		EV_ClrAction(player);
		EV_SetAction(player, SONIC_ACTIONS[ 1 ], &SONIC_TEXLIST, 1.0f, 1, 0);
		EV_CameraPos(1, 0, -50.599998f, -263.5f, 2648.3601f);
		EV_CameraAng(1, 0, 0x1100, 0xFA00, 0x300);
		EV_CameraPos(0, 180, -54.799999f, -250.10001f, 2649.6001f);
		EV_CameraAng(0, 180, 0xFB00, 0xE900, 0x300);
		EV_SerifPlay(1455);
		EV_SetFace(tails, "ECD");
		EV_Msg(msgTbl_ev00F9[ TextLanguage ][ 3 ]); //"\aYou just sort of conked out, there."
		EV_Wait(20);
		EV_LookPoint(player, -51.0f, -260.0f, 2641.0f);
		EV_Wait(5);
		EV_LookPoint(player, -37.0f, -260.0f, 2642.0f);
		EV_Wait(15);
		EV_LookPoint(player, -51.0f, -260.0f, 2641.0f);
		EV_Wait(10);
		EV_SetAction(player, SONIC_ACTIONS[ 1 ], &SONIC_TEXLIST, 1.0f, 1, 8);
		EV_LookFree(player);
		EV_SerifWait( );
		EV_Wait(20);
		EV_ClrFace(tails);
		EV_SetFace(tails, "ECD");
		EV_SerifPlay(1454);
		EV_Msg(msgTbl_ev00F9[ TextLanguage ][ 4 ]); //"\aKnuckles left already."
		EV_Wait(50);
		EV_ClrFace(tails);
		EV_CameraPos(1, 0, -55.57f, -260.39999f, 2623.6799f);
		EV_CameraAng(1, 0, 0x500, 0xA700, 0x300);
		EV_CameraPos(1, 250, -57.299999f, -260.17999f, 2626.1001f);
		EV_CameraAng(1, 250, 0x500, 0xAC00, 0x700);
		EV_SerifPlay(1456);
		EV_SetFace(tails, "CEF");
		EV_Msg(msgTbl_ev00F9[ TextLanguage ][ 5 ]); //"\aCome!  \nWe gotta go after the last E"...
		EV_Wait(1);
		EV_SerifWait( );
		EV_ClrFace(tails);
		EV_SetAction(player, &action_s_s0006_sonic, &SONIC_TEXLIST, 0.5f, 1, 12);
		EV_SerifPlay(1457);
		EV_Msg(msgTbl_ev00F9[ TextLanguage ][ 6 ]); //"\a?... Lead the way!"
		EV_Wait(1);
		EV_SerifWait( );
		EV_SetFace(tails, "CDP");
		EV_SerifPlay(1458);
		EV_Msg(msgTbl_ev00F9[ TextLanguage ][ 7 ]); //"\aIt should still be on board \nthe Tor"...
		EV_Wait(20);
		EV_SetAction(tails, &action_m_m0130_miles, &MILES_TEXLIST, 1.0f, 0, 0);
		EV_SetAction(tails, &action_m_m0131_miles, &MILES_TEXLIST, 1.0f, 1, 0);
		EV_SerifWait( );
		EV_MsgClose( );
		EventSe_Stop(0);
		break;
	case 2:
		EV_CameraOff( );
		EV_PadOn( );
		EV_SetPos(player, -47.2327f, -263.29999f, 2626.6599f);
		EV_SetAng(player, 0x800, 0xD00, 0);
		EV_InitPlayer(0);
		EV_RemovePlayer(2);
		if ( WHITE )
		{
			FreeTask(WHITE);
			WHITE = 0;
		}
		if ( WHITE2 )
		{
			FreeTask(WHITE2);
			WHITE2 = 0;
		}
		EventSe_Close( );
		break;
	}
}
