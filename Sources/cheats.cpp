#include "cheats.hpp"
#include "CTRPluginFramework/Graphics/Color.hpp"
#include "string.h"
namespace CTRPluginFramework
{
	u32 offset;
	u32 data32;
	u32 cmp32;
	u16 data16;
	u16 cmp16;
	u8 data8;
	
	/************************
	*						*
	*						*
	*						*
	************************/
	void enkaunto(MenuEntry *entry)
	{
		Keyboard key("野性のポケモンに",{"遭遇しない","遭遇する"});
		int check=key.Open();
		switch(check){
			
			case 0: MessageBox("遭遇チート","野性のポケモンに遭遇しなくなりました")();
			Process::Write32(offset + 0x0436AE0, 0x1A000004);
			Process::Write32(offset + 0x0436AE8, 0xE21110FF);
			break;
			
			case 1: MessageBox("遭遇チート","野性のポケモンに遭遇するようになりました")();
			Process::Write32(offset + 0x0436AE0, 0x0A000004);
			Process::Write32(offset + 0x0436AE8, 0xE2011001);
			break;
		}
	}

	void bike(MenuEntry *entry)
	{
		offset = 0x08000000;
		Process::Write32(offset + 0x0C67194, 0x00000001);
		offset = 0;
		data32 = 0;
		data16 = 0;
		data8 = 0;
	}

	void walk(MenuEntry *entry)
	{
		offset = 0x08000000;
		Process::Write32(offset + 0x0C67194, 0x00000000);
		offset = 0;
		data32 = 0;
		data16 = 0;
		data8 = 0;
	}

	void colorchange(MenuEntry* entry)
	{
		offset = 0x15000000;
		data32 = 0;
		data16 = 0;
		data8 = 0;
		for (int i = 0; i < 7; i++)
		{
			if (Process::Read32(offset + 0x0D58FB8, cmp32) && cmp32 == 0x82728D64 + i * 0x01000000)
			{
				Process::Write32(offset + 0x0D58FB8, 0x00020010);
				Process::Write32(offset + 0x0D58FBC, 0x0001FF00 + i * 0x01000000);
				Process::Write32(0x8803D28, 0x00000004);
				break;
			}
		}
		if (Process::Read32(offset + 0x0D59304, cmp32) && cmp32 == 0x0004000C)
		{
			Process::Write32(offset + 0x0D59308, 0x6A598D64);
			Process::Write32(offset + 0x0D5930C, 0x7DD19752);
			Process::Write32(offset + 0x0D59310, 0x7D2B6843);
			Process::Write32(offset + 0x0D59314, 0x82726C34);
			Process::Write32(offset + 0x0D59318, 0xE0A8E0A7);
			Process::Write32(offset + 0x0D5931C, 0x0000000A);
		}
		offset = 0;
	}

	void ngword(MenuEntry *entry)
	{
		Process::Write32(offset + 0x02A543C, 0x00000000);
		Process::Write32(offset + 0x02A5B34, 0x00000000);
	}

	void hankaku(MenuEntry *entry)
	{
		offset = 0x15D59000;
		if (Process::Read32(offset + 0x0000304, cmp32) && cmp32 == 0x0004000C)
		{
			Process::Write32(offset + 0x0000198, 0x00420041);
			Process::Write32(offset + 0x000019C, 0x00440043);
			Process::Write32(offset + 0x00001A0, 0x00460045);
			Process::Write32(offset + 0x00001A4, 0x00480047);
			Process::Write32(offset + 0x00001A8, 0x004A0049);
			Process::Write32(offset + 0x00001AC, 0x004C004B);
			Process::Write32(offset + 0x00001B0, 0x004E004D);
			Process::Write32(offset + 0x00001B4, 0x0050004F);
			Process::Write32(offset + 0x00001B8, 0x00520051);
			Process::Write32(offset + 0x00001BC, 0x00540053);
			Process::Write32(offset + 0x00001C0, 0x00560055);
			Process::Write32(offset + 0x00001C4, 0x00580057);
			Process::Write32(offset + 0x00001C8, 0x005A0059);
			Process::Write32(offset + 0x00001CC, 0x00620061);
			Process::Write32(offset + 0x00001D0, 0x00640063);
			Process::Write32(offset + 0x00001D4, 0x00660065);
			Process::Write32(offset + 0x00001D8, 0x00680067);
			Process::Write32(offset + 0x00001DC, 0x006A0069);
			Process::Write32(offset + 0x00001E0, 0x006C006B);
			Process::Write32(offset + 0x00001E4, 0x006E006D);
			Process::Write32(offset + 0x00001E8, 0x0070006F);
			Process::Write32(offset + 0x00001EC, 0x00720071);
			Process::Write32(offset + 0x00001F0, 0x00740073);
			Process::Write32(offset + 0x00001F4, 0x00760075);
			Process::Write32(offset + 0x00001F8, 0x00780077);
			Process::Write32(offset + 0x00001FC, 0x007A0079);
			Process::Write32(offset + 0x0000200, 0x00310030);
			Process::Write32(offset + 0x0000204, 0x00330032);
			Process::Write32(offset + 0x0000208, 0x00350034);
			Process::Write32(offset + 0x000020C, 0x00370036);
			Process::Write32(offset + 0x0000210, 0x00390038);
			Process::Write32(offset + 0x0000214, 0x0040002E);
			Process::Write16(offset + 0x0000218, 0x00000020);
			offset = 0;
			data32 = 0;
			data16 = 0;
			data8 = 0;
		}
	}

	void tncha(MenuEntry *entry)
	{
		memcpy((void*)0x08803CF8,(void*)0x08C79C84,0);
		offset = 0;
		data32 = 0;
		data16 = 0;
		data8 = 0;
	}

	void akabou(MenuEntry *entry)
	{
		offset = 0x08000000;
		MessageBox("名前変更","名前が変更されました")();
		Process::Write32(offset + 0x0C79C84, 0x00020010);
		Process::Write32(offset + 0x0C79C88, 0xFF00BD07);
		Process::Write32(offset + 0x0C79C8C, 0x00020010);
		Process::Write32(offset + 0x0C79C90, 0x0000BD00);
		Process::Write32(offset + 0x0C79C94, 0xE080E080);
		Process::Write32(offset + 0x0C79C98, 0xE080E080);
		Process::Write32(offset + 0x0C79C9C, 0xE08000A0);
	}

	void clash(MenuEntry *entry)
	{
		offset = 0x003F8000;
		Process::Write32(offset + 0x0000100, 0xE3A03000);
		Process::Write32(offset + 0x0000108, 0xE3A03000);
		Process::Write32(offset + 0x0000110, 0xE1A01001);
	}

	void opinf(MenuEntry *entry)
	{
		offset = 0x08000000;
		Process::Write32(offset + 0x0C7BB64, 0x0000000A);
	}

	void clearhistory(MenuEntry *entry)
	{
		offset = 0x08000000;
		Process::Write32(offset + 0x0C84C7C, 0x00000000);
	}

	void nice99999(MenuEntry *entry)
	{
		u32 hr;
		Process::Read32(0x8C82B90, hr);
		Keyboard keyboard(
			Utils::Format("好きな数を10進数で入力してください", hr));
		keyboard.IsHexadecimal(false);
		keyboard.Open(hr);
		Process::Write32(0x8C82B90, hr);
	}
	
	void nicehatena(MenuEntry *entry)
	{
		offset = 0x08000000;
		Process::Write32(offset + 0x0C82B90, 0x0001ADAF);
	}

	void birthday99999(MenuEntry *entry)
	{
		u32 hr;
		Process::Read32(0x8C82B94, hr);
		Keyboard keyboard(
			Utils::Format("好きな数を10進数で入力してください", hr));
		keyboard.IsHexadecimal(false);
		keyboard.Open(hr);
		Process::Write32(0x8C82B94, hr);
	}

	void birthdayhatena(MenuEntry *entry)
	{
		offset = 0x08000000;
		Process::Write32(offset + 0x0C82B94, 0x0001ADAF);
	}

	void batllewon(MenuEntry *entry)
	{
		u32 hr;
		Process::Read32(0x8C82AEC, hr);
		Keyboard keyboard(
			Utils::Format("好きな数を10進数で入力してください", hr));
		keyboard.IsHexadecimal(false);
		keyboard.Open(hr);
		Process::Write32(0x8C82AEC, hr);
	}

	void trade(MenuEntry *entry)
	{
		u32 hr;
		Process::Read32(0x8C82AE4, hr);
		Keyboard keyboard(
			Utils::Format("好きな数を10進数で入力してください", hr));
		keyboard.IsHexadecimal(false);
		keyboard.Open(hr);
		Process::Write32(0x8C82AE4, hr);
	}

	void gtsup(MenuEntry *entry)
	{
		offset = 0x00000000;
		Process::Write8(offset + 0x8C7D1C0, 0x00000000);
	}

	void gtszorua(MenuEntry *entry)
	{
		offset = 0x00000000;
		Process::Write16(offset + 0x83349FC, 0x0000023A);
	}

	void gtsgender(MenuEntry *entry)
	{
		offset = 0x00000000;
		Process::Write8(offset + 0x8334A00, 0x000000A8);
	}

	void gtslevel(MenuEntry *entry)
	{
		offset = 0x00000000;
		Process::Write8(offset + 0x8334A04, 0x000000A6);
	}

}

