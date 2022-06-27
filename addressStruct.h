#include <iostream>
#include <map>

#pragma once
struct pStatic {
	uintptr_t BRIEFCASE_PSTATIC{ 0x86d760 };
	uintptr_t PROFILE_PSTATIC{ 0x2b17ec };
	uintptr_t GAME_STATUS{ 0xe3d718 };
	uintptr_t EQUIPED_WEAPON_STATIC{ 0x86d760 };
};


struct profile_offset {
	//profile
	uintptr_t  MONEY{ 0x7c };
	uintptr_t  HEALTH{ 0x88 };
	uintptr_t  MAX_HEALTH{ 0x8a };
	uintptr_t  ASHLEY_HEALTH{ 0x8c };
	uintptr_t  ASHLEY_MAX_HEALTH{ 0x8e };
	uintptr_t  WEAPON_EQUIPED{ 0x11958 };
};

struct briefcase_offset{
	//briefcase
	uintptr_t  BASE_BRIEFCASE{ 0x2 }; //from sum of base .. minus
	uintptr_t  BASE_BRIEFCASE_OFFSET{ 0x2 };
	uintptr_t  ITEM_OFFSET{ 0xE }; //from sum of base
};

struct item_offsets {
	uintptr_t BASE_ITEM {0x0};
	uintptr_t COORDINAT_SUM{ 0x2 }; //minus
	uintptr_t VALUE_OF_ITEM{ 0x2 };
	uintptr_t WEAPON_UPGRADE{ 0x6 };
	uintptr_t WEAPON_AMMO{ 0x8 };
	uintptr_t COORDINAT_BRIEFCASE{ 0xA };

};



//0 for ammo , 1 for weapon , 2 for consumable,  3 for throwable, 4 for whatever , 5 for attachment
const std::map<uint16_t, int> cWeap = {
	{ 0, 0 }, //MagnumAmmo
	{ 1, 3 }, //HandGrenade
	{ 2, 3 }, //IncendiaryGrenade
	{ 3, 1 }, //Matilda
	{ 4, 0 }, //HandgunAmmo
	{ 5, 2 }, //FirstAidSpray
	{ 6, 2 }, //GreenHerb
	{ 7, 0 }, //RifleAmmo
	{ 8, 2 }, //ChickenEgg
	{ 9, 2 }, //BrownChickenEgg
	{ 10, 2 }, //GoldChickenEgg
	{ 11, 4 }, //AAA
	{ 12, 4 }, //PlagaSample
	{ 13, 4 }, //KrauserKnife (weap but bug caused)
	{ 14, 3 }, //FlashGrenade
	{ 15, 4 }, //SalazarFamilyInsignia
	{ 16, 4 }, //Bowgun (bug)
	{ 17, 0 }, //BowgunBolts
	{ 18, 2 }, //GreenHerbX2
	{ 19, 2 }, //GreenHerbX3
	{ 20, 2 }, //MixedHerbsGR
	{ 21, 2 }, //MixedHerbsGRY
	{ 22, 2 }, //MixedHerbsGY
	{ 23, 1 }, //RocketLauncherSpecial
	{ 24, 0 }, //ShotgunShells
	{ 25, 2 }, //RedHerb
	{ 26, 0 }, //HandcannonAmmo
	{ 27, 4 }, //HourglassWGoldDecor
	{ 28, 2 }, //YellowHerb
	{ 29, 4 }, //StoneTablet
	{ 30, 4 }, //LionOrnament
	{ 31, 4 }, //GoatOrnament
	{ 32, 0 }, //TMPAmmo1
	{ 33, 1 }, //Punisher
	{ 34, 1 }, //PunisherWSilencer
	{ 35, 1 }, //Handgun
	{ 36, 1 }, //HandgunWSilencer
	{ 37, 1 }, //Red9
	{ 38, 5 }, //Red9WStock
	{ 39, 1 }, //Blacktail
	{ 40, 1 }, //BlacktailWSilencer
	{ 41, 1 }, //BrokenButterfly
	{ 42, 1 }, //Killer7
	{ 43, 1 }, //Killer7WSilencer
	{ 44, 1 }, //Shotgun
	{ 45, 1 }, //Striker
	{ 46, 1 }, //Rifle
	{ 47, 1 }, //RifleSemiAuto
	{ 48, 1 }, //TMP
	{ 49, 4 }, //ActivationKeyBlue
	{ 50, 5 }, //TMPWStock
	{ 51, 4 }, //ActivationKeyRed
	{ 52, 1 }, //ChicagoTypewriter1
	{ 53, 3 }, //RocketLauncher (weap but 1 charge .. same as throwable)
	{ 54, 1 }, //MineThrower
	{ 55, 1 }, //Handcannon
	{ 56, 5 }, //CombatKnife (bug)
	{ 57, 4 }, //SerpentOrnament
	{ 58, 4 }, //MoonstoneRightHalf
	{ 59, 4 }, //InsigniaKey
	{ 60, 4 }, //RoundInsignia
	{ 61, 4 }, //FalseEye
	{ 62, 1 }, //CustomTMP
	{ 63, 5 }, //SilencerHandgun
	{ 64, 1 }, //Punisher2
	{ 65, 4 }, //PRL412 (weap charge)
	{ 66, 5 }, //StockRed9
	{ 67, 5 }, //StockTMP
	{ 68, 5 }, //ScopeRifle
	{ 69, 5 }, //ScopeSemiAutoRifle
	{ 70, 0 }, //MineDarts
	{ 71, 1 }, //Shotgun2
	{ 72, 4 }, //CaptureLuisCera
	{ 73, 4 }, //TargetPractice
	{ 74, 4 }, //LuisMemo
	{ 75, 4 }, //CastellanMemo
	{ 76, 4 }, //FemaleIntruder
	{ 77, 4 }, //ButlerMemo
	{ 78, 4 }, //SampleRetrieved
	{ 79, 4 }, //RitualPreparation
	{ 80, 4 }, //LuisMemo2
	{ 81, 1 }, //RifleSemiAutoWInfraredScope
	{ 82, 1 }, //KrauserBow
	{ 83, 1 }, //ChicagoTypewriter2
	{ 84, 4 }, //TreasureMapCastle
	{ 85, 4 }, //TreasureMapIsland
	{ 86, 4 }, //VelvetBlue
	{ 87, 4 }, //Spinel
	{ 88, 4 }, //PearlPendant
	{ 89, 4 }, //BrassPocketWatch
	{ 90, 4 }, //ElegantHeaddress
	{ 91, 4 }, //AntiquePipe
	{ 92, 4 }, //GoldBangleWPearls
	{ 93, 4 }, //AmberRing
	{ 94, 4 }, //Beerstein
	{ 95, 4 }, //GreenCatEye
	{ 96, 4 }, //RedCatEye
	{ 97, 4 }, //YellowCatEye
	{ 98, 4 }, //BeersteinG
	{ 99, 4 }, //BeersteinR
	{ 100, 4 }, //BeersteinY
	{ 101, 4 }, //BeersteinGR
	{ 102, 4 }, //BeersteinGY
	{ 103, 4 }, //BeersteinRY
	{ 104, 4 }, //BeersteinGRY
	{ 105, 4 }, //MoonstoneLeftHalf
	{ 106, 0}, //ChicagoTypewriterAmmo
	{ 107, 1}, //RifleWScope
	{ 108, 1}, //RifleSemiAutoWScope
	{ 109, 3}, //InfiniteLauncher
	{ 110, 4}, //KingGrail
	{ 111, 4 }, //QueenGrail
	{ 112, 4 }, //StaffOfRoyalty
	{ 113, 4 }, //GoldBars
	{ 114, 0 }, //Arrows
	{ 115, 4 }, //BonusTime
	{ 116, 4 }, //EmergencyLockCardKey
	{ 117, 4 }, //BonusPoints
	{ 118, 4 }, //GreenCatEye2
	{ 119, 4 }, //Ruby
	{ 120, 4 }, //TreasureBoxS
	{ 121, 4 }, //TreasureBoxL
	{ 122, 4 }, //BlueMoonstone
	{ 123, 4 }, //KeyToTheMine
	{ 124, 4 }, //AttachCaseS
	{ 125, 4 }, //AttachCaseM
	{ 126, 4 }, //AttachCaseL
	{ 127, 4 }, //AttachCaseXL
	{ 128, 4 }, //GoldenSword
	{ 129, 4 }, //IronKey
	{ 130, 4 }, //StoneOfSacrifice
	{ 131, 4 }, //StorageRoomCardKey
	{ 132, 4 }, //FreezerCardKey
	{ 133, 4 }, //PieceOfTheHolyBeastPanther
	{ 134, 4 }, //PieceOfTheHolyBeastSerpent
	{ 135, 4 }, //PieceOfTheHolyBeastEagle
	{ 136, 4 }, //JetSkiKey
	{ 137, 4 }, //DirtyPearlPendant
	{ 138, 4 }, //DirtyBrassPocketWatch
	{ 139, 4 }, //OldKey
	{ 140, 4 }, //CampKey
	{ 141, 4 }, //Dynamite
	{ 142, 4 }, //LiftActivationKey
	{ 143, 4 }, //GoldBangle
	{ 144, 4 }, //ElegantPerfumeBottle
	{ 145, 4 }, //MirrorWPearlAndRubies
	{ 146, 4 }, //WasteDisposalCardKey
	{ 147, 4 }, //ElegantChessboard
	{ 148, 1 }, //RiotGun
	{ 149, 2 }, //BlackBass
	{ 150, 4 }, //HourglassWGoldDecor2
	{ 151, 2 }, //BlackBassL
	{ 152, 4 }, //IlluminadosPendant
	{ 153, 1 }, //RifleWInfraredScope
	{ 154, 4 }, //Crown
	{ 155, 4 }, //CrownJewel
	{ 156, 4 }, //RoyalInsignia
	{ 157, 4 }, //CrownWithJewels
	{ 158, 4 }, //CrownWithInsignia
	{ 159, 4 }, //SalazarFamilyCrown
	{ 160, 0 }, //RifleAmmoInfrared
	{ 161, 4 }, //Emerald
	{ 162, 4 }, //BottleCaps
	{ 163, 4 }, //GalleryKey
	{ 164, 4 }, //EmblemRightHalf
	{ 165, 4 }, //EmblemLeftHalf
	{ 166, 4 }, //HexagonalEmblem
	{ 167, 4 }, //CastleGateKey
	{ 168, 4 }, //MixedHerbsRY
	{ 169, 4 }, //TreasureMapVillage
	{ 170, 4 }, //ScopeMineThrower
	{ 171, 1 }, //MineThrowerPlusScope
	{ 172, 4 }, //PlayingManual1
	{ 173, 4 }, //InfoOnAshley
	{ 174, 4 }, //PlayingManual2
};

//	{ }, //AlertOrder
//	{ }, //AboutTheBlueMedallions
//	{ }, //ChiefNote
//	{ }, //ClosureOfTheChurch
//	{ }, //AnonymousLetter
//	{ }, //PlayingManual3
//	{ }, //SeraAndTheThirdParty
//	{ }, //TwoRoutes
//	{ }, //VillageLastDefense
//	{ }, //ButterflyLamp
//	{ }, //GreenEye
//	{ }, //RedEye
//	{ }, //BlueEye
//	{ }, //ButterflyLampG
//	{ }, //ButterflyLampR
//	{ }, //ButterflyLampB
//	{ }, //ButterflyLampGR
//	{ }, //ButterflyLampGB
//	{ }, //ButterflyLampRB
//	{ }, //ButterflyLampRGB
//	{ }, //PrisonKey
//	{ }, //PlatinumSword
//	{ }, //InfraredScope
//	{ }, //ElegantMask
//	{ }, //GreenGem
//	{ }, //RedGem
//	{ }, //PurpleGem
//	{ }, //ElegantMaskG
//	{ }, //ElegantMaskR
//	{ }, //ElegantMaskP
//	{ }, //ElegantMaskGR
//	{ }, //ElegantMaskGP
//	{ }, //ElegantMaskRP
//	{ }, //ElegantMaskRGP
//	{ }, //GoldenLynx
//	{ }, //GreenStoneOfJudgement
//	{ }, //RedStoneOfFaith
//	{ }, //BlueStoneOfTreason
//	{ }, //GoldenLynxG
//	{ }, //GoldenLynxR
//	{ }, //GoldenLynxB
//	{ }, //GoldenLynxGR
//	{ }, //GoldenLynxGB
//	{ }, //GoldenLynxRB
//	{ }, //GoldenLynxGRB
//	{ }, //LeonWithRocketLauncher
//	{ }, //LeonWithShotgun
//	{ }, //LeonWithHandgun
//	{ }, //AshleyGraham
//	{ }, //LuisSera
//	{ }, //DonJose
//	{ }, //DonDiego
//	{ }, //DonEsteban
//	{ }, //DonManuel
//	{ }, //DrSalvador
//	{ }, //Merchant
//	{ }, //ZealotWithScythe
//	{ }, //ZealotWithShield
//	{ }, //ZealotWithBowgun
//	{ }, //LeaderZealot
//	{ }, //SoldierWithDynamite
//	{ }, //SoldierWithStunRod
//	{ }, //SoldierWithHammer
//	{ }, //Isabel
//	{ }, //Maria
//	{ }, //AdaWong
//	{ }, //BellaSisters
//	{ }, //DonPedro
//	{ }, //JJ
//	{ }, //LetterFromAda
//	{ }, //LuisMemo3
//	{ }, //PaperAirplane
//	{ }, //OurPlan
//	{ }, //LuisMemo4
//	{ }, //KrauserNote
//	{ }, //LuisMemo5
//	{ }, //OurMission
//	{ }, //AAA2
//	{ }, //AAA3
//	{ }, //TacticalVest
//	{ }, //AAA4
//	{ }, //Punisher3
//	{ }, //Handgun2
//	{ }, //Shotgun3
//	{ }, //MineThrower2
//	{ }, //Handcannon2
//	{ }, //MineThrowerPlusScope2
//	{ }, //MissionDirectives1
//	{ }, //MissionDirectives2
//	{ }, //MissionDirectives3
//	{ }, //MissionDirectives4
//	{ }, //MissionDirectives5
//	{ }, //Mission1TreasureMap
//	{ }, //Mission2TreasureMap
//	{ }, //Mission3TreasureMap
//	{ }, //Mission4TreasureMap
//	{ },  //Mission5TreasureMap
//}; 