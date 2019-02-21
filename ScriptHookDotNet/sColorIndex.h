/*
* Copyright (c) 2009-2011 Hazard (hazard_x@gmx.net / twitter.com/HazardX)
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#pragma once
#pragma managed

namespace GTA {

	[System::ComponentModel::TypeConverter(GTA::Design::ColorConverter::typeid)] 
	public value class ColorIndex {

	private:
		int pIndex;

	internal:

		static array<int>^ colary =  {0x0A0A0A, 0x252527, 0x656A79, 0x58595A, 0x9CA1A3, 0x96918C, 0x515459, 0x3F3E45,
			0xA5A9A7, 0x979592, 0x767B7C, 0x5A5752, 0xADB0B0, 0x848988, 0x949D9F, 0xA4A7A5, 0x585853, 0xA4A096, 
			0xAFB1B1, 0x6D6C6E, 0x64686A, 0x525661, 0x8C929A, 0x5B5D5E, 0xBDBEC6, 0xB6B6B6, 0x646464, 0xE20606, 
			0x960800, 0x6B0000, 0x611009, 0x4A0A0A, 0x730B0B, 0x570707, 0x260306, 0x9E0000, 0x140002, 0x0F0404, 
			0x0F080A, 0x39191D, 0x552725, 0x4C2929, 0x741D28, 0x6D2837, 0x730A27, 0x640D1B, 0x620B1C, 0x731827, 
			0xAB988F, 0x20202C, 0x44624F, 0x2E5B20, 0x1E2E32, 0x304F45, 0x4D6268, 0x5E7072, 0x193826, 0x2D3A35, 
			0x335F3F, 0x47783C, 0x93A396, 0x9AA790, 0x263739, 0x4C75B7, 0x46597A, 0x5D7E8D, 0x3B4E78, 0x3D4A68, 
			0x6D7A88, 0x162248, 0x272F4B, 0x4E6881, 0x6A7A8C, 0x6F8297, 0x0E316D, 0x395A83, 0x204B6B, 0x2B3E57, 
			0x364155, 0x6C8495, 0x4D5D60, 0x406C8F, 0x134573, 0x105082, 0x385694, 0x001C32, 0x596E87, 0x223457, 
			0x20202C, 0xF5890F, 0x917347, 0x8E8C46, 0xAAAD8E, 0xAE9B7F, 0x96816C, 0x7A7560, 0x9D9872, 0x989586, 
			0x9C8D71, 0x691E3B, 0x722A3F, 0x7C1B44, 0x221918, 0x7F6956, 0x473532, 0x695853, 0x624428, 0x7D6256, 
			0xAA9D84, 0x7B715E, 0xAB9276, 0x635C5A, 0xC9C9C9, 0xD6DAD6, 0x9F9D94, 0x93A396, 0x9C9C98, 0xA7A28F, 
			0x0F6A89, 0xA19983, 0xA3ADC6, 0x9B8B80, 0x8494AB, 0x9EA4AB, 0x86446E, 0xE20606, 0x47783C, 0xD78E10, 
			0x2A77A1, 0x421F21, 0x6F675F, 0xFC2600, 0xFC6D00, 0xFFFFFF};

		static array<String^>^ colnamary = {"Black", "BlackPoly", "ConcordBluePoly", "PewterGrayPoly", "SilverStonePoly",
			"WinningSilverPoly", "SteelGrayPoly", "ShadowSilverPoly", "SilverStonePoly2", "PorcelainSilverPoly", "GrayPoly",
			"AnthraciteGrayPoly", "AstraSilverPoly", "AscotGray", "ClearCrystalBlueFrostPoly", "SilverPoly", "DarkTitaniumPoly", 
			"TitaniumFrostPoly", "PoliceWhite", "MediumGrayPoly", "MediumGrayPoly2", "SteelGrayPoly2", "SlateGray",
			"GunMetalPoly", "LightBlueGrey", "SecuricorLightGray", "ArcticWhite", "VeryRed", "TorinoRedPearl", "FormulaRed",
			"BlazeRed", "GracefulRedMica", "GarnetRedPoly", "DesertRed", "CabernetRedPoly", "TurismoRed", "DesertRed2",
			"CurrantRedSolid", "CurrantRedPoly", "ElectricCurrantRedPoly", "MediumCabernetSolid", "WildStrawberryPoly",
			"MediumRedSolid", "BrightRed", "BrightRed2", "MediumGarnetRedPoly", "BrilliantRedPoly", "BrilliantRedPoly2",
			"AlabasterSolid", "TwilightBluePoly", "TorchRed", "Green", "DeepJewelGreen", "AgateGreen", "PetrolBlueGreenPoly",
			"Hoods", "Green2", "DarkGreenPoly", "RioRed", "SecuricorDarkGreen", "SeafoamPoly", "PastelAlabasterSolid",
			"MidnightBlue", "StrikingBlue", "SaxonyBluePoly", "JasperGreenPoly", "MarinerBlue", "HarborBluePoly",
			"DiamondBluePoly", "SurfBlue", "NauticalBluePoly", "LightCrystalBluePoly", "MedRegattaBluePoly", "SpinnakerBlueSolid",
			"UltraBluePoly", "BrightBluePoly", "NassauBluePoly", "MediumSapphireBluePoly", "SteelBluePoly",
			"LightSapphireBluePoly", "MalachitePoly", "MediumMauiBluePoly", "BrightBluePoly2", "BrightBluePoly3", "Blue",
			"DarkSapphireBluePoly", "LightSapphireBluePoly2", "MediumSapphireBlueFiremist", "TwilightBluePoly2", "TaxiYellow",
			"RaceYellowSolid", "PastelAlabaster", "OxfordWhiteSolid", "Flax", "MediumFlax", "PuebloBeige", "LightIvory",
			"SmokeSilverPoly", "BisqueFrostPoly", "ClassicRed", "VermilionSolid", "VermillionSolid", "BistonBrownPoly",
			"LightBeechwoodPoly", "DarkBeechwoodPoly", "DarkSablePoly", "MediumBeechwoodPoly", "WoodrosePoly", "SandalwoodFrostPoly",
			"MediumSandalwoodPoly", "CopperBeige", "WarmGreyMica", "White", "FrostWhite", "HoneyBeigePoly", "SeafoamPoly2",
			"LightTitaniumPoly", "LightChampagnePoly", "ArcticPearl", "LightDriftwoodPoly", "WhiteDiamondPearl", "AntelopeBeige",
			"CurrantBluePoly", "CrystalBluePoly", "TempleCurtainPurple", "CherryRed", "SecuricorDarkGreen2", "TaxiYellow2",
			"PoliceCarBlue", "MellowBurgundy", "DesertTaupePoly", "LammyOrange", "LammyYellow", "VeryWhite"};

		static String^ GetNameOf(int Index);
		static ColorIndex FromKnownName(String^ Name);

	public:
		ColorIndex(int ColorIndex);
		//Color(System::Drawing::Color color);

		property int Index {
			int get();
		}
		property String^ Name {
			String^ get();
		}

		property int R {
			int get();
		}
		property int G {
			int get();
		}
		property int B {
			int get();
		}

		int ToARGB();
		System::Drawing::Color ToColor();

		//static Color FromARGB(int ARGB);
		//static Color FromColor(System::Drawing::Color color);

		static operator ColorIndex (int source);
		static operator System::Drawing::Color (ColorIndex source);
		//static operator Color (System::Drawing::Color source);

		static property ColorIndex Black { ColorIndex get(){ return ColorIndex(0); } }
		static property ColorIndex BlackPoly { ColorIndex get(){ return ColorIndex(1); } }
		static property ColorIndex ConcordBluePoly { ColorIndex get(){ return ColorIndex(2); } }
		static property ColorIndex PewterGrayPoly { ColorIndex get(){ return ColorIndex(3); } }
		static property ColorIndex SilverStonePoly { ColorIndex get(){ return ColorIndex(4); } }
		static property ColorIndex WinningSilverPoly { ColorIndex get(){ return ColorIndex(5); } }
		static property ColorIndex SteelGrayPoly { ColorIndex get(){ return ColorIndex(6); } }
		static property ColorIndex ShadowSilverPoly { ColorIndex get(){ return ColorIndex(7); } }
		static property ColorIndex SilverStonePoly2 { ColorIndex get(){ return ColorIndex(8); } }
		static property ColorIndex PorcelainSilverPoly { ColorIndex get(){ return ColorIndex(9); } }
		static property ColorIndex GrayPoly { ColorIndex get(){ return ColorIndex(10); } }
		static property ColorIndex AnthraciteGrayPoly { ColorIndex get(){ return ColorIndex(11); } }
		static property ColorIndex AstraSilverPoly { ColorIndex get(){ return ColorIndex(12); } }
		static property ColorIndex AscotGray { ColorIndex get(){ return ColorIndex(13); } }
		static property ColorIndex ClearCrystalBlueFrostPoly { ColorIndex get(){ return ColorIndex(14); } }
		static property ColorIndex SilverPoly { ColorIndex get(){ return ColorIndex(15); } }
		static property ColorIndex DarkTitaniumPoly { ColorIndex get(){ return ColorIndex(16); } }
		static property ColorIndex TitaniumFrostPoly { ColorIndex get(){ return ColorIndex(17); } }
		static property ColorIndex PoliceWhite { ColorIndex get(){ return ColorIndex(18); } }
		static property ColorIndex MediumGrayPoly { ColorIndex get(){ return ColorIndex(19); } }
		static property ColorIndex MediumGrayPoly2 { ColorIndex get(){ return ColorIndex(20); } }
		static property ColorIndex SteelGrayPoly2 { ColorIndex get(){ return ColorIndex(21); } }
		static property ColorIndex SlateGray { ColorIndex get(){ return ColorIndex(22); } }
		static property ColorIndex GunMetalPoly { ColorIndex get(){ return ColorIndex(23); } }
		static property ColorIndex LightBlueGrey { ColorIndex get(){ return ColorIndex(24); } }
		static property ColorIndex SecuricorLightGray { ColorIndex get(){ return ColorIndex(25); } }
		static property ColorIndex ArcticWhite { ColorIndex get(){ return ColorIndex(26); } }
		static property ColorIndex VeryRed { ColorIndex get(){ return ColorIndex(27); } }
		static property ColorIndex TorinoRedPearl { ColorIndex get(){ return ColorIndex(28); } }
		static property ColorIndex FormulaRed { ColorIndex get(){ return ColorIndex(29); } }
		static property ColorIndex BlazeRed { ColorIndex get(){ return ColorIndex(30); } }
		static property ColorIndex GracefulRedMica { ColorIndex get(){ return ColorIndex(31); } }
		static property ColorIndex GarnetRedPoly { ColorIndex get(){ return ColorIndex(32); } }
		static property ColorIndex DesertRed { ColorIndex get(){ return ColorIndex(33); } }
		static property ColorIndex CabernetRedPoly { ColorIndex get(){ return ColorIndex(34); } }
		static property ColorIndex TurismoRed { ColorIndex get(){ return ColorIndex(35); } }
		static property ColorIndex DesertRed2 { ColorIndex get(){ return ColorIndex(36); } }
		static property ColorIndex CurrantRedSolid { ColorIndex get(){ return ColorIndex(37); } }
		static property ColorIndex CurrantRedPoly { ColorIndex get(){ return ColorIndex(38); } }
		static property ColorIndex ElectricCurrantRedPoly { ColorIndex get(){ return ColorIndex(39); } }
		static property ColorIndex MediumCabernetSolid { ColorIndex get(){ return ColorIndex(40); } }
		static property ColorIndex WildStrawberryPoly { ColorIndex get(){ return ColorIndex(41); } }
		static property ColorIndex MediumRedSolid { ColorIndex get(){ return ColorIndex(42); } }
		static property ColorIndex BrightRed { ColorIndex get(){ return ColorIndex(43); } }
		static property ColorIndex BrightRed2 { ColorIndex get(){ return ColorIndex(44); } }
		static property ColorIndex MediumGarnetRedPoly { ColorIndex get(){ return ColorIndex(45); } }
		static property ColorIndex BrilliantRedPoly { ColorIndex get(){ return ColorIndex(46); } }
		static property ColorIndex BrilliantRedPoly2 { ColorIndex get(){ return ColorIndex(47); } }
		static property ColorIndex AlabasterSolid { ColorIndex get(){ return ColorIndex(48); } }
		static property ColorIndex TwilightBluePoly { ColorIndex get(){ return ColorIndex(49); } }
		static property ColorIndex TorchRed { ColorIndex get(){ return ColorIndex(50); } }
		static property ColorIndex Green { ColorIndex get(){ return ColorIndex(51); } }
		static property ColorIndex DeepJewelGreen { ColorIndex get(){ return ColorIndex(52); } }
		static property ColorIndex AgateGreen { ColorIndex get(){ return ColorIndex(53); } }
		static property ColorIndex PetrolBlueGreenPoly { ColorIndex get(){ return ColorIndex(54); } }
		static property ColorIndex Hoods { ColorIndex get(){ return ColorIndex(55); } }
		static property ColorIndex Green2 { ColorIndex get(){ return ColorIndex(56); } }
		static property ColorIndex DarkGreenPoly { ColorIndex get(){ return ColorIndex(57); } }
		static property ColorIndex RioRed { ColorIndex get(){ return ColorIndex(58); } }
		static property ColorIndex SecuricorDarkGreen { ColorIndex get(){ return ColorIndex(59); } }
		static property ColorIndex SeafoamPoly { ColorIndex get(){ return ColorIndex(60); } }
		static property ColorIndex PastelAlabasterSolid { ColorIndex get(){ return ColorIndex(61); } }
		static property ColorIndex MidnightBlue { ColorIndex get(){ return ColorIndex(62); } }
		static property ColorIndex StrikingBlue { ColorIndex get(){ return ColorIndex(63); } }
		static property ColorIndex SaxonyBluePoly { ColorIndex get(){ return ColorIndex(64); } }
		static property ColorIndex JasperGreenPoly { ColorIndex get(){ return ColorIndex(65); } }
		static property ColorIndex MarinerBlue { ColorIndex get(){ return ColorIndex(66); } }
		static property ColorIndex HarborBluePoly { ColorIndex get(){ return ColorIndex(67); } }
		static property ColorIndex DiamondBluePoly { ColorIndex get(){ return ColorIndex(68); } }
		static property ColorIndex SurfBlue { ColorIndex get(){ return ColorIndex(69); } }
		static property ColorIndex NauticalBluePoly { ColorIndex get(){ return ColorIndex(70); } }
		static property ColorIndex LightCrystalBluePoly { ColorIndex get(){ return ColorIndex(71); } }
		static property ColorIndex MedRegattaBluePoly { ColorIndex get(){ return ColorIndex(72); } }
		static property ColorIndex SpinnakerBlueSolid { ColorIndex get(){ return ColorIndex(73); } }
		static property ColorIndex UltraBluePoly { ColorIndex get(){ return ColorIndex(74); } }
		static property ColorIndex BrightBluePoly { ColorIndex get(){ return ColorIndex(75); } }
		static property ColorIndex NassauBluePoly { ColorIndex get(){ return ColorIndex(76); } }
		static property ColorIndex MediumSapphireBluePoly { ColorIndex get(){ return ColorIndex(77); } }
		static property ColorIndex SteelBluePoly { ColorIndex get(){ return ColorIndex(78); } }
		static property ColorIndex LightSapphireBluePoly { ColorIndex get(){ return ColorIndex(79); } }
		static property ColorIndex MalachitePoly { ColorIndex get(){ return ColorIndex(80); } }
		static property ColorIndex MediumMauiBluePoly { ColorIndex get(){ return ColorIndex(81); } }
		static property ColorIndex BrightBluePoly2 { ColorIndex get(){ return ColorIndex(82); } }
		static property ColorIndex BrightBluePoly3 { ColorIndex get(){ return ColorIndex(83); } }
		static property ColorIndex Blue { ColorIndex get(){ return ColorIndex(84); } }
		static property ColorIndex DarkSapphireBluePoly { ColorIndex get(){ return ColorIndex(85); } }
		static property ColorIndex LightSapphireBluePoly2 { ColorIndex get(){ return ColorIndex(86); } }
		static property ColorIndex MediumSapphireBlueFiremist { ColorIndex get(){ return ColorIndex(87); } }
		static property ColorIndex TwilightBluePoly2 { ColorIndex get(){ return ColorIndex(88); } }
		static property ColorIndex TaxiYellow { ColorIndex get(){ return ColorIndex(89); } }
		static property ColorIndex RaceYellowSolid { ColorIndex get(){ return ColorIndex(90); } }
		static property ColorIndex PastelAlabaster { ColorIndex get(){ return ColorIndex(91); } }
		static property ColorIndex OxfordWhiteSolid { ColorIndex get(){ return ColorIndex(92); } }
		static property ColorIndex Flax { ColorIndex get(){ return ColorIndex(93); } }
		static property ColorIndex MediumFlax { ColorIndex get(){ return ColorIndex(94); } }
		static property ColorIndex PuebloBeige { ColorIndex get(){ return ColorIndex(95); } }
		static property ColorIndex LightIvory { ColorIndex get(){ return ColorIndex(96); } }
		static property ColorIndex SmokeSilverPoly { ColorIndex get(){ return ColorIndex(97); } }
		static property ColorIndex BisqueFrostPoly { ColorIndex get(){ return ColorIndex(98); } }
		static property ColorIndex ClassicRed { ColorIndex get(){ return ColorIndex(99); } }
		static property ColorIndex VermilionSolid { ColorIndex get(){ return ColorIndex(100); } }
		static property ColorIndex VermillionSolid { ColorIndex get(){ return ColorIndex(101); } }
		static property ColorIndex BistonBrownPoly { ColorIndex get(){ return ColorIndex(102); } }
		static property ColorIndex LightBeechwoodPoly { ColorIndex get(){ return ColorIndex(103); } }
		static property ColorIndex DarkBeechwoodPoly { ColorIndex get(){ return ColorIndex(104); } }
		static property ColorIndex DarkSablePoly { ColorIndex get(){ return ColorIndex(105); } }
		static property ColorIndex MediumBeechwoodPoly { ColorIndex get(){ return ColorIndex(106); } }
		static property ColorIndex WoodrosePoly { ColorIndex get(){ return ColorIndex(107); } }
		static property ColorIndex SandalwoodFrostPoly { ColorIndex get(){ return ColorIndex(108); } }
		static property ColorIndex MediumSandalwoodPoly { ColorIndex get(){ return ColorIndex(109); } }
		static property ColorIndex CopperBeige { ColorIndex get(){ return ColorIndex(110); } }
		static property ColorIndex WarmGreyMica { ColorIndex get(){ return ColorIndex(111); } }
		static property ColorIndex White { ColorIndex get(){ return ColorIndex(112); } }
		static property ColorIndex FrostWhite { ColorIndex get(){ return ColorIndex(113); } }
		static property ColorIndex HoneyBeigePoly { ColorIndex get(){ return ColorIndex(114); } }
		static property ColorIndex SeafoamPoly2 { ColorIndex get(){ return ColorIndex(115); } }
		static property ColorIndex LightTitaniumPoly { ColorIndex get(){ return ColorIndex(116); } }
		static property ColorIndex LightChampagnePoly { ColorIndex get(){ return ColorIndex(117); } }
		static property ColorIndex ArcticPearl { ColorIndex get(){ return ColorIndex(118); } }
		static property ColorIndex LightDriftwoodPoly { ColorIndex get(){ return ColorIndex(119); } }
		static property ColorIndex WhiteDiamondPearl { ColorIndex get(){ return ColorIndex(120); } }
		static property ColorIndex AntelopeBeige { ColorIndex get(){ return ColorIndex(121); } }
		static property ColorIndex CurrantBluePoly { ColorIndex get(){ return ColorIndex(122); } }
		static property ColorIndex CrystalBluePoly { ColorIndex get(){ return ColorIndex(123); } }
		static property ColorIndex TempleCurtainPurple { ColorIndex get(){ return ColorIndex(124); } }
		static property ColorIndex CherryRed { ColorIndex get(){ return ColorIndex(125); } }
		static property ColorIndex SecuricorDarkGreen2 { ColorIndex get(){ return ColorIndex(126); } }
		static property ColorIndex TaxiYellow2 { ColorIndex get(){ return ColorIndex(127); } }
		static property ColorIndex PoliceCarBlue { ColorIndex get(){ return ColorIndex(128); } }
		static property ColorIndex MellowBurgundy { ColorIndex get(){ return ColorIndex(129); } }
		static property ColorIndex DesertTaupePoly { ColorIndex get(){ return ColorIndex(130); } }
		static property ColorIndex LammyOrange { ColorIndex get(){ return ColorIndex(131); } }
		static property ColorIndex LammyYellow { ColorIndex get(){ return ColorIndex(132); } }
		static property ColorIndex VeryWhite { ColorIndex get(){ return ColorIndex(133); } }

		virtual String^ ToString() override;

	};

}