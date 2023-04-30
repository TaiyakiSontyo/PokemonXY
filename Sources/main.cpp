#include "CTRPluginFramework.hpp"
#include "cheats.hpp"
#include "csvc.h"
#include "string.h"
#include <chrono>
#include <thread>

namespace CTRPluginFramework
{
	const std::string NewLINE = "\n";//改行
	std::string CTRPFname = "PokemonXY";//3gx名前
	std::string about1 = "By Twitter";//about1行目
	std::string about2 = "@Noel_cheat";//about2行目
	std::string about3 = "@rurutanko810";//about3行目
	std::string about4 = "@piyobara";//about4行目
	std::string about5 = "@x2rin1";//about5行目
	std::string about6 = "@0041x";//about6行目
	std::string taiyaki = "taiyaki#0001/@TaiyakiSontyo";//taiyaki
	static MenuEntry *AddArg(void *arg, MenuEntry *entry)
	{
		if (entry != nullptr)
			entry->SetArg(arg);
		return (entry);
	}

	static MenuEntry *EntryWithHotkey(MenuEntry *entry, const Hotkey& hotkey)
	{
		if (entry != nullptr)
		{
			entry->Hotkeys += hotkey;
			entry->SetArg(new std::string(entry->Name()));
			entry->Name() += "" + hotkey.ToString();
			entry->Hotkeys.OnHotkeyChangeCallback([](MenuEntry *entry, int index)
				{
					std::string *name = reinterpret_cast<std::string*>(entry->GetArg());

					entry->Name() = *name + "" + entry->Hotkeys[0].ToString();
				});
		}
		return (entry);
	}

	static MenuEntry *EntryWithHotkey(MenuEntry *entry, const std::vector<Hotkey>& hotkeys)
	{
		if (entry != nullptr)
		{
			for (const Hotkey& hotkey : hotkeys)
				entry->Hotkeys += hotkey;
		}
		return (entry);
	}

	static MenuEntry *EnabledEntry(MenuEntry *entry)
	{
		if (entry != nullptr) entry->Enable();
		return (entry);
	}

	PluginMenu *Pmenu;

	void InitMenu()
	{
		MenuFolder *benri = new MenuFolder("便利なコード");
		    *benri += new MenuEntry("野生のポケモンと遭遇しない",nullptr,enkaunto,"※固定シンボルはエンカウントします");
			*benri += new MenuEntry("どこでも自転車に乗れる",bike,"画面リフレッシュ後に適用されます");
			*benri += new MenuEntry("自転車から降りる時やバグが起きた時用",walk,"画面リフレッシュ後に適用されます");
			*Pmenu += benri;
		MenuFolder *pss = new MenuFolder("PSS関連");
			MenuFolder *cuskey = new MenuFolder("カスタムキーボード");
		    	*cuskey += new MenuEntry("カラーチェンジ",colorchange,"最初に〇色と入力すると色が変わる\nハッピーサインでのみ使用可能");
				*cuskey += new MenuEntry("アルファベット半角",hankaku,"ハッピーサインでのみ使用可能");
				*cuskey += new MenuEntry("NGワード規制回避",ngword);
			pss->Append(cuskey);
			MenuFolder *namechanges = new MenuFolder("名前変更");
				*namechanges += new MenuEntry("ハッピーサインから名前変更",nullptr,tncha);
				*namechanges += new MenuEntry("名前:■■",nullptr,akabou);
			pss-> Append(namechanges);
		 	*pss += new MenuEntry("クラッシュ無効化",clash,"カラーコードによるクラッシュを無効化");
		 	*pss += new MenuEntry("O-パワー無限",opinf);
		 	*pss += new MenuEntry("履歴削除",clearhistory);
		 	*pss += new MenuEntry("ナイス数変更",nullptr,nice99999);
		 	*pss += new MenuEntry("ナイス:?9999",nicehatena);
		 	*pss += new MenuEntry("おめでとう数変更",nullptr,birthday99999);
		 	*pss += new MenuEntry("おめでとう:?9999",birthdayhatena);
		 	*pss += new MenuEntry("対戦勝利回数変更",nullptr,batllewon);
		 	*pss += new MenuEntry("ポケモン交換回数変更",nullptr,trade);
		*Pmenu += pss;
		MenuFolder *gts = new MenuFolder("GTS");
	    	*gts += new MenuEntry("何度でも預けられる",gtsup);
		 	*gts += new MenuEntry("欲しいポケモンがゾロアになる",gtszorua);
		 	*gts += new MenuEntry("欲しいポケモンの性別の条件が性別になる",gtsgender);
		 	*gts += new MenuEntry("欲しいポケモンのレベルの条件がレベルになる",gtslevel);
	    *Pmenu += gts;
	}

	int main(void)
	{
		std::chrono::milliseconds duration(3000);
  		std::this_thread::sleep_for(duration);
		MessageBox("チート画面で下画面の'Tools'の中の'Settings'の中の'auto'の項目4点にチェックを入れると、設定したものとFavoriteを記憶します。\n他の3gxからの変更やバージョンの変更で動作がおかしい場合は" << Color::Yellow << " CTRPFData.bin " << Color::White << "を削除して初期設定を行ってください\n\nなにかバグ等不具合があれば" << Color::Cyan << " ∮Rei#2830" << Color::White << "または" << Color::Cyan << "Taiyaki#0001"  << Color::White << "まで。",DialogType::DialogOk).SetClear(ClearScreen::None)();
		Pmenu = new PluginMenu(CTRPFname, 1, 0, 0, about1 + NewLINE + about2 + NewLINE + about3 + NewLINE + about4 + NewLINE + about5 + NewLINE + about6 + NewLINE);
		Pmenu->SynchronizeWithFrame(true);
		OSD::Notify("Pokemon XY");
		OSD::Notify(Color::Red << "P" << 
					Color::Orange << "l" << 
					Color::Yellow << "u" <<
					Color::Lime << "g" <<
					Color::Green << "i" << 
					Color::Cyan << "n " << 
					Color::Blue << "R" <<
					Color::Purple << "e" << 
					Color::Red << "a" << 
					Color::Orange << "d" << 
					Color::Yellow << "y" << 
					Color::Lime << "!");
		Pmenu->ShowWelcomeMessage(false);
		InitMenu();
		Pmenu->Run();
		delete Pmenu;
		return 0;
	}

}
