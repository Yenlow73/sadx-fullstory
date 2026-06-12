#include "pch.h"

PVMEntry texTbl_ev001C[] = 
{
	(char*)("M_EM_YELLOW"), &M_EM_YELLOW_TEXLIST,
	(char*)("M_EM_SKY"), &M_EM_SKY_TEXLIST,
	(char*)("EV_EGGMOBLE0"), &EV_EGGMOBLE0_TEXLIST,
	(char*)("CHAOS4_COMMON"), &CHAOS4_COMMON_TEXLIST,
	(char*)("EV_EGGMOBLE0"), &EV_EGGMOBLE0_TEXLIST,
	(char*)("SHAPE_FROG"), &texlist_shape_frog,
	0
};

void ev001C_s_beforechaos6(int state)
{
	switch (state) 
	{
	case 1:
		player = EV_GetPlayer(0);
		Frog = 0;
		C_EME_Y = 0;
		C_EME_S = 0;
		FLASH = 0;
		EV_CameraOn();
		EV_PadOff();
		EV_CanselOn();
		SetBankDir(112);
		EventSe_Init(4);
		EV_InitPlayer(0);
		EV_CreatePlayer(5, BigTheCat, 115.0f, 744.0f, -480.0f, 0, 0xB8A9, 0);
		EV_CreateObject(&C_EME_Y, 973.29999f, 126.5f, 823.5f, 0xFFF0, 0x19E0, 0x54);
		EV_CreateObject(&C_EME_S, 973.29999f, 126.5f, 823.5f, 0xFFF0, 0x19E0, 0x54);
		EV_CreateObjectFunc(&Frog, set_shapefrog, 51.200001f, 748.5f, -463.0f, 0, 0xA900, 0);
		EV_Wait(1);
		EV_SetPos(C_EME_Y, 4.8000002f, 740.5f, -440.60001f);
		EV_SetAng(C_EME_Y, 0x600, 0x9FF3, 0);
		EV_SetPos(C_EME_S, 2.8f, 740.5f, -440.60001f);
		EV_SetAng(C_EME_S, 0x600, 0x9FF3, 0);
		big = EV_GetPlayer(5);
		EV_SetPos(big, 62.5f, 747.5f, -456.60001f);
		EV_SetAng(big, 0x600, 0x9FF3, 0);
		EV_SetPos(player, -169.7f, 594.0f, -809.40002f);
		EV_SetAng(player, 0x300, 0x100, 0);
		EV_SetMode(Frog, 0);
		EV_SetMode(C_EME_Y, 0);
		EV_SetMode(C_EME_S, 0);
		EV_SetAction(Frog, &_action_f_f0001_frog, &texlist_shape_frog, 1.0f, 1, 0);
		EV_SetAction(C_EME_Y, &action_m_em_yellow, &M_EM_YELLOW_TEXLIST, 1.0f, 1, 1);
		EV_SetAction(C_EME_S, &action_m_em_yellow, &M_EM_SKY_TEXLIST, 1.0f, 1, 1);
		EV_SetAction(big, BIG_ACTIONS[23], &BIG_TEXLIST, 1.0f, 1, 1);
		EV_SetShadow(Frog, 0.60000002f);
		create_eggmoble(77.400002f, 825.79999f, -429.10001f, 0, 0, 0);
		EV_Wait(3);
		CreateChaos4(5.3000002f, 745.0f, -500.70001f, 0, 0x6800, 0, 80);
		StgChaos6CtrlOn(-321.0f, 592.5f, -289.85001f, 0, 0, 0, 100);
		EV_Wait(1);
		ChangeMotionSpeedChaos4(1.0f);
		StgChaos6Human2Water();
		EV_SetPos(big, 62.5f, 747.5f, -456.60001f);
		EV_SetAng(big, 0x900, 0xA000, 0);
		BGM_Play(MusicIDs_evtbgm04);
		EventSe_Play(1, 1337, 1800);
		EventSe_Volume(1, 20, 1);
		EventSe_Pan(1, 20, 1);
		EV_CameraPos(1, 0, -40.450001f, 756.0f, -470.17999f);
		EV_CameraAng(1, 0, 0xFF54, 0xB0E5, 0xFFB2);
		EV_CameraPos(1, 110, -34.18f, 758.16998f, -495.35999f);
		EV_CameraAng(1, 110, 0x154, 0xBAE5, 0xFFB2);
		EV_Wait(125);
		EV_CameraPos(1, 0, -22.32f, 751.09998f, -518.40002f);
		EV_CameraAng(0, 0, 0xC29, 0x84A9, 0xFFE0);
		EV_CameraPos(0, 55, 15.93f, 766.0f, -529.79999f);
		EV_CameraAng(0, 55, 0x429, 0x6AA9, 0xFEE0);
		EV_Wait(55);
		EV_CameraPos(0, 50, 34.200001f, 775.40002f, -495.79999f);
		EV_CameraAng(0, 50, 0x1029, 0x4DA8, 0xFEE0);
		EV_Wait(50);
		EV_CameraPos(0, 85, 28.450001f, 769.92999f, -480.70001f);
		EV_CameraAng(0, 85, 0x1E29, 0x19A8, 0xFBE0);
		EV_Wait(25);
		EV_CameraPerspective(0, 140, 0x29F5);
		EV_Wait(85);
		EV_CameraPos(0, 0, 83.199997f, 749.67999f, -491.5f);
		EV_CameraAng(0, 0, 0xF29, 0x4BA8, 0xFEE0);
		EV_CameraPos(0, 80, 88.129997f, 749.44f, -466.20001f);
		EV_CameraAng(0, 80, 0x1329, 0x3DA8, 0xFEE0);
		EV_Wait(110);
		EV_SetAction(big, BIG_ACTIONS[23], &BIG_TEXLIST, 1.0f, 1, 8);
		EV_CameraPerspective(1, 1, 0x31C7);
		EV_Wait(1);
		EV_CameraPos(1, 0, 61.0f, 756.0f, -487.0f);
		EV_CameraAng(1, 0, 0xB29, 0x81A9, 0xFFE0);
		EV_SerifPlay(1367);
		EV_Msg(msgTbl_ev00DE[TextLanguage][0]); //"\aSo! I see you're trying to escape! \n"...
		eggmoble_moveandturn(11.0f, 765.0f, -411.0f, 0, -22016, 0, 100, 0);
		EV_CameraAng(1, 60, 0xB29, 0x74C2, 0xFFE0);
		EV_Wait(120);
		ChgEggMobleMod(5);
		EV_SerifWait();
		EV_MsgCls();
		EV_SetPos(big, 62.5f, 747.5f, -456.60001f);
		EV_SetAng(big, 0x600, 0x92F3, 0);
		EV_CameraTargetFree();
		EV_CameraPos(1, 0, 27.799999f, 778.59998f, -477.60001f);
		EV_CameraAng(1, 0, 0, 0x1F3, 0);
		EV_SerifPlay(1368);
		EV_Msg(msgTbl_ev00DE[TextLanguage][1]); //"\aChaos!   Grab him.   Get that frog!"
		EV_CameraAng(1, 25, 0x400, 0x10F3, 0);
		EV_Wait(23);
		EV_CameraPos(1, 8, 27.0f, 778.79999f, -479.39999f);
		EV_Wait(40);
		EV_LookFree(big);
		EV_CameraPos(1, 0, 39.5f, 765.5f, -479.95999f);
		EV_CameraPos(1, 100, 42.599998f, 757.59998f, -475.29999f);
		EV_CameraTargetObj(1, 0, Frog, 0.0f, 0.0f, 0.0f, 0);
		EV_Wait(40);
		EV_MsgClose();
		EV_SetPos(C_EME_S, 18.5f, 781.0f, -415.39999f);
		EV_SetAng(C_EME_S, 0, 0, 0);
		EV_SetAction(GetEggMobleTask(), &action_gm_gm0023_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.1f, 1, 0);
		EV_SerifPlay(1369);
		EV_Msg(msgTbl_ev00DE[TextLanguage][2]); //"\aAnd don't forget the Chaos Emerald."
		EV_CameraTargetFree();
		EV_CameraPos(1, 0, 14.3f, 781.91998f, -414.0f);
		EV_CameraAng(1, 0, 0xEDB3, 0x6031, 0);
		EV_Wait(20);
		EV_CameraPos(0, 17, 21.700001f, 785.35999f, -419.88f);
		EV_CameraAng(0, 17, 0xEDB3, 0x6531, 0);
		EV_Wait(60);
		EV_SerifWait();
		EV_MsgClose();
		EV_CameraPos(1, 0, 56.467999f, 747.63f, -460.75f);
		EV_CameraAng(1, 0, 0x56A, 0x2474, 0);
		EV_CameraAng(1, 140, 0x146A, 0x2474, 2048);
		EV_CameraPerspective(1, 1, 0x1DDE);
		EV_Wait(170);
		EV_CameraPerspective(1, 1, 0x31C7);
		EV_Wait(1);
		EV_CameraPos(1, 0, 51.900002f, 753.29999f, -480.79999f);
		EV_CameraAng(1, 0, 0xF66A, 0x7C74, 0);
		EV_CameraPos(1, 80, 51.400002f, 752.0f, -475.0f);
		EV_SetAction(Frog, &_action_f_f0001_frog, &texlist_shape_frog, 1.8f, 1, 0);
		EV_Wait(30);
		EV_SetAction(Frog, &_action_f_f0001_frog, &texlist_shape_frog, 3.3f, 1, 0);
		EV_Wait(30);
		EV_SetAction(Frog, &_action_f_f0001_frog, &texlist_shape_frog, 4.0f, 1, 0);
		EV_Wait(20);
		EV_CameraPos(1, 0, 48.700001f, 748.63f, -455.29999f);
		EV_CameraAng(1, 0, 0xFB6A, 0xEED9, 0);
		EV_CameraPos(1, 80, 44.369999f, 749.52002f, -459.0f);
		EV_CameraAng(1, 80, 0xFB6A, 0xDAD9, 0);
		EV_Wait(25);
		chg_frogshape(1);
		EV_Wait(55);
		chg_frogshape(6);
		EV_SetAction(Frog, &_action_f_f0001_frog, &texlist_shape_frog, 0.89999998f, 1, 0);
		EV_Wait(10);
		EV_SetPos(C_EME_Y, 51.200001f, 748.5f, -463.0f);
		EV_SetAng(C_EME_Y, 0, 0, 0);
		EV_CameraPos(1, 60, 41.630001f, 747.5f, -465.17999f);
		EV_CameraAng(1, 60, 0xE6A, 0xBCD9, 0);
		EV_SetAction(Frog, &_action_f_f0001_frog, &texlist_shape_frog, 0.5f, 1, 0);
		EV_Wait(40);
		chg_frogshape(0);
		EV_Wait(20);
		crushLightOn(C_EME_Y->twp->pos.x, C_EME_Y->twp->pos.y, C_EME_Y->twp->pos.z - 0.5f, 2, 22, 0.2f, 0.69999999f, 0xFFFFFF64, 0xFFFF1Eu);
		moveObject(C_EME_Y, 51.200001f, 748.34998f, -463.0f, 49.110001f, 748.34998f, -466.0f, 110);
		EV_Wait(140);
		EV_CameraPos(0, 0, 47.400002f, 749.33002f, -490.60001f);
		EV_CameraAng(0, 0, 0x600, 0x88FB, 0x80);
		EV_CameraPos(0, 70, 35.66f, 750.09998f, -497.39999f);
		EV_CameraAng(0, 70, 0x600, 0x88FB, 0x80);
		EV_Wait(20);
		crushLightOff();
		EV_Wait(50);
		EV_SetPath(C_EME_Y, &epathtag_CEMY00DE, 0.079999998f, 0);
		EV_CameraTargetObj(1, 20, C_EME_Y, 0.0f, 0.0f, 0.0f, 0);
		EV_Wait(40);
		EV_SetPath(C_EME_S, &epathtag_CEMS00DE, 0.25f, 0);
		EV_CameraPos(0, 140, 55.799999f, 745.5f, -501.39999f);
		EV_CameraTargetObj(1, 20, C_EME_S, 0.0f, 0.0f, 0.0f, 0);
		EventSe_Play(1, 1333, 1800);
		EventSe_Volume(1, 110, 1);
		EventSe_Pan(1, -30, 1);
		EV_Wait(30);
		BGM_Play(MusicIDs_evtbgm01);
		crushLightOn(11.0f, 780.0f, -497.20001f, 3, 10, 0.40000001f, 2.0f, 0xFFFFFF64, 0xFFFF1Eu);
		EV_Wait(15);
		crushLightOff();
		crushLightOn(14.77f, 777.07001f, -494.97f, 3, 11, 0.5f, 2.5999999f, 0xFF1E1EFF, 0x8282FFu);
		EV_Wait(70);
		FLASH = COverlayCreate(0.000019999999f, 0.30000001f, 1.0f, 1.0f, 1.0f);
		EV_FreeObject(&C_EME_Y);
		EV_FreeObject(&C_EME_S);
		DeleteChaos4();
		StgChaos6SetPos(-5.3000002f, 745.0f, -500.70001f);
		StgChaos6SetAng(0, 0x6800, 0);
		StgChaos6Water2Human();
		EV_SetAction(GetEggMobleTask(), &action_gm_gm0021_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.1f, 1, 0);
		EV_SetAction(big, &action_b_b0020_big, &BIG_TEXLIST, 1.2f, 1, 0);
		EV_CameraTargetFree();
		EV_CameraPos(1, 0, 23.700001f, 751.09998f, -470.70001f);
		EV_CameraAng(1, 0, 0x700, 0x12D1, 0x18);
		EV_CameraPos(0, 25, 26.700001f, 784.59998f, -464.39999f);
		EV_CameraAng(0, 25, 0xEA00, 0x12D1, 0x18);
		crushLightOff();
		EV_Wait(30);
		if (FLASH)
		{
			COverlaySetSpeed(FLASH, -0.0099999998f);
		}
		EV_CameraPos(0, 80, 51.299999f, 757.79999f, -436.39999f);
		EV_CameraAng(0, 80, 0, 0x18D1, 0x18);
		EV_Wait(80);
		if (FLASH)
		{
			COverlaySetSpeed(FLASH, -0.0000000099999999f);
		}
		EventSe_Stop(1);
		EV_SetAction(big, &action_b_b0020_big, &BIG_TEXLIST, 1.4f, 1, 0);
		EV_LookFree(big);
		EV_CameraPos(1, 0, 15.0f, 783.79999f, -420.60001f);
		EV_CameraAng(1, 0, 0xF200, 0x6D0C, 0);
		EV_CameraPos(1, 90, 14.6f, 782.79999f, -417.5f);
		EV_CameraAng(1, 90, 0xF254, 0x6D0C, 0);
		EV_SerifPlay(1371);
		EV_Msg(msgTbl_ev00DE[TextLanguage][3]); //"\aAll right!   And now for the frog."
		EV_SerifWait();
		EV_MsgCls();
		EV_CameraPos(1, 0, 56.799999f, 750.20001f, -473.14999f);
		EV_CameraAng(1, 0, 0xFD50, 0x7E0C, 0);
		EV_CameraPos(0, 8, 50.799999f, 750.20001f, -473.45001f);
		EV_Wait(17);
		EV_CameraPos(1, 0, 15.0f, 778.92999f, -416.5f);
		EV_CameraAng(1, 0, 0xFF50, 0x680C, 0);
		EV_CameraAng(1, 80, 0x550, 0x680C, 0);
		EV_SerifPlay(1370);
		EV_Msg(msgTbl_ev00DE[TextLanguage][4]); //"\aThe frog is possessed by your tail. "
		EV_SetAction(Frog, &_action_f_f0001_frog, &texlist_shape_frog, 1.5f, 1, 0);
		EV_Wait(85);
		EV_CameraPos(1, 0, 58.599998f, 758.0f, -470.53f);
		EV_CameraAng(1, 0, 0xD50, 0x8F0C, 0);
		EV_SerifWait();
		EV_CameraTargetFree();
		EV_Msg(msgTbl_ev00DE[TextLanguage][5]); //"\aOnce you get your tail, \nyou'll be c"...
		EV_SerifPlay(1372);
		EV_CameraPos(1, 0, 5.9000001f, 753.5f, -451.0f);
		EV_CameraAng(1, 0, 0x1154, 0x220C, 0);
		EV_CameraPos(0, 50, 28.299999f, 752.70001f, -470.16f);
		EV_Wait(50);
		EV_CameraPos(1, 0, 13.7f, 788.5f, -419.79999f);
		EV_CameraAng(1, 0, 0xE354, 0x770C, 0);
		EV_CameraPos(0, 50, 13.0f, 786.0f, -416.79999f);
		EV_Wait(90);
		EV_CameraPos(1, 0, 52.700001f, 753.5f, -471.70001f);
		EV_CameraAng(1, 0, 0x1154, 0x9A0C, 0xFB00);
		EV_SerifWait();
		EV_MsgClose();
		EV_CameraPos(1, 0, 32.200001f, 795.79999f, -474.29999f);
		EV_CameraAng(1, 0, 0xEA54, 0x270C, 0xFB00);
		EV_CameraPos(1, 40, 38.73f, 771.79999f, -471.0f);
		EV_CameraAng(1, 40, 0xF854, 0x270C, 0);
		EV_Wait(40);
		EV_SetAction(big, BIG_ACTIONS[23], &BIG_TEXLIST, 1.4f, 1, 0);
		EV_CameraPos(1, 0, 56.900002f, 750.0f, -463.10999f);
		EV_CameraAng(1, 100, 0x56, 0x2D0C, 0);
		EV_CameraAng(1, 100, 0x454, 0x2D0C, 0);
		EV_CameraPerspective(1, 100, 0x24FA);
		EV_Wait(120);
		EV_CameraPerspective(1, 1, 0x31C7);
		EV_Wait(1);
		EV_CameraPos(1, 0, 80.870003f, 763.0f, -460.70001f);
		EV_CameraAng(1, 0, 0xF6CC, 0x40DA, 0x100);
		EV_CameraPos(1, 100, 80.599998f, 763.09998f, -466.70001f);
		EV_CameraAng(1, 100, 0xF7C8, 0x3ADA, 0x200);
		EV_SetAction(Frog, &_action_f_f0002_frog, &texlist_shape_frog, 1.0f, 1, 0);
		moveObject(Frog, 53.0f, 750.0f, -461.20001f, 2.8f, 773.0f, -486.0f, 130);
		EV_WaitMove(Frog);
		EV_Wait(120);
		EV_SetAction(Frog, &action_f_f0010_frog, &texlist_shape_frog, 1.0f, 1, 0);
		if (FLASH)
		{
			FreeTask(FLASH);
			FLASH = 0;
		}
		FLASH = COverlayCreate(0.000019999999f, 0.30000001f, 0.60000002f, 0.60000002f, 1.0f);
		EV_CameraPos(1, 0, 8.8699999f, 773.70001f, -486.0f);
		EV_CameraAng(1, 0, 0x100, 0x3629, 0x400);
		EV_CameraPos(1, 90, 9.5699997f, 771.59998f, -481.29999f);
		EV_CameraAng(1, 90, 0x123C, 0x3000, 0x400);
		EV_Wait(40);
		chg_frogshape(2);
		EventSe_Oneshot(6, 60, 0, 0);
		EV_Wait(60);
		EventSe_Oneshot(6, 90, 0, 0);
		EV_CameraPos(1, 50, 6.8000002f, 771.59998f, -482.29999f);
		EV_CameraAng(1, 50, 0x53C, 0x3029, 0x400);
		EV_Wait(50);
		EV_MsgCls();
		EV_MsgClose();
		if (FLASH)
		{
			FreeTask(FLASH);
			FLASH = 0;
		}
		EV_CameraPos(1, 0, -64.169998f, 761.70001f, -464.0f);
		EV_CameraAng(1, 0, 0x103C, 0xD229, 0x400);
		EV_CameraPos(1, 80, -82.300003f, 757.70001f, -506.0f);
		EV_CameraAng(1, 80, 0x163C, 0xC929, 0x400);
		crushLightOn(-35.400002f, 791.20001f, -523.90002f, 4, 10, 0.5f, 2.5999999f, 0xFFDCDCB4, 0xB4B428u);
		EV_Wait(20);
		EventSe_Play(2, 1334, 1800);
		EventSe_Volume(2, 128, 1);
		EventSe_Pan(2, 20, 1);
		FLASH = COverlayCreate(0.015f, 0.30000001f, 1.0f, 1.0f, 0.94999999f);
		EV_Wait(60);
		if (FLASH)
		{
			COverlaySetSpeed(FLASH, -0.050000001f);
		}
		EV_CameraPos(1, 0, -70.169998f, 864.70001f, -497.0f);
		EV_CameraAng(1, 0, 0xE03C, 0xD729, 0x400);
		EV_CameraPos(0, 70, -28.17f, 820.70001f, -445.0f);
		EV_CameraAng(0, 70, 0x83C, 0x229, 0x400);
		EV_Wait(70);
		EV_CameraPos(0, 140, -7.6500001f, 849.70001f, -412.0f);
		EV_CameraAng(0, 140, 0xE83C, 0x329, 64768);
		EventSe_Stop(2);
		EventSe_Oneshot(1336, 128, -10, 0);
		EV_LookFree(big);
		EV_SetPos(player, 171.60001f, 747.0f, -397.39999f);
		EV_SetAng(player, 0, 0x9600, 0);
		EV_SetPos(big, 66.099998f, 759.5f, -458.29999f);
		EV_SetAng(big, 0x900, 0x9AF3, 0);
		EV_ClrAction(player);
		EV_SetAction(player, SONIC_ACTIONS[6], &SONIC_TEXLIST, 1.2f, 1, 0);
		EV_Wait(5);
		EV_Wait(40);
		EventSe_Oneshot(1335, 128, -10, 0);
		EV_Wait(40);
		crushLightOff();
		EV_MovePoint2(player, 70.599998f, 747.0f, -477.0f, 1.6f, 0.1f);
		EV_Wait(40);
		EV_CameraPos(1, 0, 39.5f, 756.70001f, -469.39999f);
		EV_CameraAng(1, 0, 0x500, 0xB129, 0);
		EV_CameraAng(1, 90, 0x500, 0xBB29, 0);
		//BGM_Play(MusicIDs_thesonic);
		EV_WaitMove(player);
		EventSe_Oneshot(18, 100, 0, 0);
		EV_SetAng(player, 0xF800, 0xB500, 0);
		EV_SetAction(player, SONIC_ACTIONS[7], &SONIC_TEXLIST, 1.4f, 0, 16);
		EV_WaitAction(player);
		EV_SetAction(player, SONIC_ACTIONS[1], &SONIC_TEXLIST, 1.0f, 1, 4);
		EV_ClrFace(player);

		// Sonic perspective

		EV_SerifPlay(561);
		if (VoiceLanguage == Languages_Japanese)
		{
			EV_SetFace(player, "FE");
		}
		if (VoiceLanguage == Languages_English)
		{
			EV_SetFace(player, "FBBBD");
		}
		EV_Msg((msgTbl_ev001C[TextLanguage])[0]); //"\aOh no!  Not again!"
		EV_SerifWait();
		EV_ClrFace(player);
		EV_MsgClose();
		EV_CameraPos(0, 0, 77.620003f, 750.47998f, -531.90002f);
		EV_CameraAng(0, 0, 0x1030, 0x41B0, 0);
		EV_CameraPos(0, 110, 79.110001f, 750.47998f, -496.0f);
		EV_Wait(30);

		EV_SetPos(player, 104.3f, 744.0f, -522.0f);     
		EV_SetAng(player, 0xF829, 0xC6A9, 0);
		StgChaos6CtrlOn(5.3000002f, 745.0f, -500.70001f, 0, -0x500, 0, 0x38E);
		eggmoble_moveandturn(20.0f, 780.0f, -421.0f, 0, 0xF600, 0, 100, 0);
		EV_Wait(1);
		//EV_SetMode(Frog, 0);
		EV_SetPos(Frog, 24.459999f, 763.88501f, -516.44f);
		EV_SetAng(Frog, 0xF800, -0xA630, 0);
		//EV_SetAction(Frog, &_action_f_f0010_frog, &texlist_shape_frog, 0.2f, 1, 0);
		EV_SetPos(big, 115.0f, 744.0f, -480.0f);
		EV_SetAng(big, 0, 0xB8A9, 0);

		EV_SerifPlay(565);
		EV_SetFace(player, "EAADC");
		EV_Msg((msgTbl_ev001C[TextLanguage])[1]); //"\aChaos!   \nCould this be the same bea"...
		EV_Wait(50);
		EV_CameraPerspective(0, 1, 0x238E);
		EV_CameraPos(0, 0, 98.739998f, 746.0f, -515.40002f);
		EV_CameraAng(0, 0, 0x1030, 0xE0B0, 0xFC00);
		EV_CameraPos(0, 60, 97.260002f, 746.15002f, -516.70001f);
		EV_SerifWait();
		EV_ClrFace(player);
		EV_MsgClose();
		EV_SerifPlay(562);
		EV_Msg((msgTbl_ev001C[TextLanguage])[2]); //\aHa ha ha ha ha! "
		EV_SetAction(player, &action_s_s0004_sonic, &SONIC_TEXLIST, 1.0f, 1, 8);
		EV_MsgClose();
		EV_SetAng(player, 0xF829, 0xC2A9, 0);
		EV_CameraPerspective(1, 80, 0x31C7);
		EV_CameraPos(1, 60, 103.0f, 746.59003f, -531.34003f);
		EV_CameraAng(1, 60, 0x1030, 0x7AB0, 0xFC00);
		EV_SerifPlay(563);
		EV_Msg((msgTbl_ev001C[TextLanguage])[3]); //"\aOh, yes!  \nAttack Sonic, now!"
		EV_Wait(60);
		EV_CameraPos(0, 140, 96.839996f, 746.16803f, -539.78003f);
		EV_CameraAng(0, 140, 0xA29, 0x7DA9, 0);
		EV_SerifWait();
		EV_MovePoint2(big, 110.0f, 746.0f, -482.42999f, 0.60000002f, 0.0f);
		EV_SerifPlay(564);
		EV_Msg((msgTbl_ev001C[TextLanguage])[4]); //"\aFroggy!"
		EV_Wait(1);
		EV_SerifWait();
		EV_MsgClose();
		EV_CameraPos(0, 0, 44.82f, 757.46997f, -531.28003f);
		EV_CameraAng(0, 0, 0xA29, 0x59A9, 0xFFE0);
		EV_CameraPerspective(0, 70, 0x1C72);
		EV_CameraPos(0, 70, 39.34f, 759.20001f, -527.28003f);
		EV_SerifPlay(566);
		EV_Msg((msgTbl_ev001C[TextLanguage])[5]); //"\aI must save Froggy!"
		EV_Wait(60);
		EV_MsgClose();
		EV_ClrAction(big);
		EV_CameraPos(0, 0, 87.540001f, 745.79999f, -539.62f);
		EV_CameraAng(0, 0, 0x729, 0x97B0, 0);
		EV_Wait(1);
		EV_SetAction(player, &action_s_s0038_sonic, &SONIC_TEXLIST, 0.60000002f, 1, 8);
		EV_SerifPlay(567);
		EV_MsgW(60, (msgTbl_ev001C[TextLanguage])[6]); // "\aIf he's your friend, \nI'll help you."
		EV_SetAction(big, &action_b_b0013_big, &BIG_TEXLIST, 0.80000001f, 0, 8);
		EV_SetAction(big, &action_b_b0014_big, &BIG_TEXLIST, 0.80000001f, 1, 0);
		EV_MsgClose();
		EV_CameraPos(1, 80, 91.769997f, 745.59998f, -543.84003f);
		EV_CameraAng(1, 80, 0x729, 0x9640, 0);
		EV_Wait(20);
		EV_SetAction(player, &action_s_s0067_sonic, &SONIC_TEXLIST, 0.69999999f, 0, 8);
		EV_SetAction(player, SONIC_ACTIONS[123], &SONIC_TEXLIST, 1.0f, 1, 8);
		EV_SerifPlay(568);
		EV_SetFace(player, "FEF");
		EV_Msg((msgTbl_ev001C[TextLanguage])[7]); //"\aJust leave it to me!"
		EV_Wait(1);
		EV_SerifWait();
		EV_CameraPerspective(1, 40, 0x31C7);
		EV_ClrFace(player);
		EV_ClrAction(big);
		EV_MovePoint2(big, 91.0f, 757.0f, -290.0f, 0.0f, 2.0f);
		EV_MsgClose();
		EV_Wait(10);
		EV_CameraPerspective(1, 1, 0x31C7);
		EV_CameraPos(1, 0, 27.6f, 788.85999f, -420.79999f);
		EV_CameraAng(1, 0, 0xC30, 0x43B0, 0x200);
		eggmoble = GetEggMobleTask();
		EV_ClrAction(eggmoble);
		EV_SetAction(eggmoble, &action_gm_gm0004_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.0f, 1, 0);
		EV_SerifPlay(569);
		EV_Msg((msgTbl_ev001C[TextLanguage])[8]); //"\aHa ha ha ha ha!"
		EV_RemovePlayer(2);
		EV_SerifWait();
		EV_CameraPerspective(0, 260, 0x293F);
		EV_CameraPos(0, 260, 38.7356f, 807.90002f, -390.44601f);
		EV_CameraAng(0, 260, 0xF068, 0x1B3, 0);
		EV_SerifPlay(570);
		EV_SetAction(eggmoble, &action_gm_gm0020_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.0f, 0, 8);
		EV_SetAction(eggmoble, &action_gm_gm0021_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.0f, 0, 8);
		EV_SetAction(eggmoble, &action_gm_gm0021_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.0f, 0, 8);
		EV_SetAction(eggmoble, &action_gm_gm0020_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.0f, 1, 8);
		EV_Msg((msgTbl_ev001C[TextLanguage])[9]); // "\aNow I have 6 of \nthe Chaos Emeralds."
		EV_Wait(1);
		EV_SerifWait();
		EV_SerifPlay(571);
		EV_Msg((msgTbl_ev001C[TextLanguage])[10]); // "\aThere's only one more \nleft to find."
		EV_Wait(1);
		EV_SetAction(eggmoble, &action_gm_gm0025_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.0f, 0, 16);
		EV_SerifWait();
		EV_SerifPlay(572);
		EV_Msg((msgTbl_ev001C[TextLanguage])[11]); //"\aI even found \nChaos' missing tail!"
		EV_Wait(1);
		EV_WaitAction(eggmoble);
		EV_CameraPos(1, 0, 73.755997f, 754.0f, -515.62f);
		EV_CameraAng(1, 0, 0xF729, 0xC8A9, 0x100);
		EV_CameraPos(0, 40, 92.667999f, 744.0f, -514.70001f);
		EV_CameraAng(1, 30, 0x1329, 0xDA49, 0x200);
		EV_CameraPerspective(0, 40, 0x18E4);
		EV_SerifPlay(573);
		EV_SetFace(player, "FEF");
		EV_Msg((msgTbl_ev001C[TextLanguage])[12]); //"\aYou won't get away \nwith this, you m"...
		EV_SetAction(player, &action_s_s0005_sonic, &SONIC_TEXLIST, 0.80000001f, 0, 4);
		EV_SetAction(player, &action_s_s0007_sonic, &SONIC_TEXLIST, 0.80000001f, 1, 4);
		EV_Wait(20);
		EV_CameraPos(0, 50, 93.25f, 744.0f, -513.88849f);
		EV_CameraAng(0, 50, 0x1329, 0xDEA9, 0x200);
		EV_Wait(45);
		EV_CameraPerspective(0, 1, 0x271C);
		EV_CameraPos(1, 0, 45.169998f, 785.5f, -432.39999f);
		EV_CameraAng(1, 0, 0x900, 0x5000, 0x200);
		EV_CameraPos(0, 200, 38.068001f, 793.89001f, -418.56699f);
		EV_CameraAng(0, 200, 0, 0x4000, 0);
		EV_ClrAction(eggmoble);
		EV_SetAction(eggmoble, &action_gm_gm0025_eggmoble, &EV_EGGMOBLE0_TEXLIST, 0.40000001f, 0, 8);
		EV_SetAction(eggmoble, &action_gm_gm0022_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.0f, 0, 8);
		EV_SetAction(eggmoble, &action_gm_gm0003_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.3f, 1, 6);
		EV_SerifPlay(574);
		EV_Msg((msgTbl_ev001C[TextLanguage])[13]); //"\aI will!"
		EV_SerifWait();
		EV_SerifPlay(575);
		EV_Msg((msgTbl_ev001C[TextLanguage])[14]); //"\aYou're no match for Chaos - even\ntho"...
		EV_SerifWait();
		EV_SetAction(eggmoble, &action_gm_gm0024_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.0f, 0, 6);
		EV_SetAction(eggmoble, &action_gm_gm0020_eggmoble, &EV_EGGMOBLE0_TEXLIST, 1.0f, 1, 8);
		EV_MsgClose();
		EV_SetAction(player, &action_s_s0009_sonic, &SONIC_TEXLIST, 0.80000001f, 1, 8);
		EV_SerifPlay(576);
		EV_Msg((msgTbl_ev001C[TextLanguage])[15]); // "\aOkay Chaos! Destroy them all...\nImme"...
		EV_Wait(45);
		EV_CameraPos(1, 40, 119.05f, 744.28998f, -519.79999f);
		EV_CameraAng(1, 40, 0xF00, 0x4300, 0x200);
		EV_MsgClose();
		EV_Wait(20);
		EV_CameraPos(1, 50, 118.88f, 744.42999f, -522.70001f);
		EV_CameraAng(1, 50, 0xF00, 0x4300, 0x200);
		EV_Wait(70);
		break;
	case 2:
		EV_CameraOff();
		EV_PadOn();
		EV_InitPlayer(0);
		EV_SerifStop();
		DeleteChaos4();	
		EV_RemovePlayer(2);
		EV_RemovePlayer(5);
		EV_RemovePlayer(3);
		EV_RemovePlayer(4);
		EV_FreeObject(&C_EME_Y);
		EV_FreeObject(&C_EME_S);
		EV_FreeObject(&Frog);
		delete_eggmoble();
		crushLightOff();
		if (FLASH)
		{
			FreeTask(FLASH);
			FLASH = 0;
		}
		StgChaos6CtrlOff();
		EV_ClrPath(C_EME_Y);
		EV_ClrPath(C_EME_S);
		EventSe_Close();
		EV_Wait(1);		
		break;
	}
}