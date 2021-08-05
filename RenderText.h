#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>

enum fonts
{
	CalibriFont,
	AGENCYB,
	AGENCYR,
	ALGER,
	ANTQUAB,
	ANTQUABI,
	ANTQUAI,
	arial,
	arialbd,
	arialbi,
	ariali,
	ARIALN,
	ARIALNB,
	ARIALNBI,
	ARIALNI,
	ariblk,
	ARLRDBD,
	bahnschrift,
	BASKVILL,
	BAUHS93,
	BELL,
	BELLB,
	BELLI,
	BERNHC,
	BKANT,
	BOD_B,
	BOD_BI,
	BOD_BLAI,
	BOD_BLAR,
	BOD_CB,
	BOD_CBI,
	BOD_CI,
	BOD_CR,
	BOD_I,
	BOD_PSTC,
	BOD_R,
	BOOKOS,
	BOOKOSB,
	BOOKOSBI,
	BOOKOSI,
	BRADHITC,
	BRITANIC,
	BRLNSB,
	BRLNSDB,
	BRLNSR,
	BROADW,
	BRUSHSCI,
	BSSYM7,
	calibrib,
	calibrii,
	calibril,
	calibrili,
	calibriz,
	CALIFB,
	CALIFI,
	CALIFR,
	CALIST,
	CALISTB,
	CALISTBI,
	CALISTI,
	cambriab,
	cambriai,
	cambriaz,
	Candara,
	Candarab,
	Candarai,
	Candaral,
	Candarali,
	Candaraz,
	CASTELAR,
	CENSCBK,
	CENTAUR,
	CENTURY,
	CHILLER,
	COLONNA,
	comic,
	comicbd,
	comici,
	comicz,
	consola,
	consolab,
	consolai,
	consolaz,
	constan,
	constanb,
	constani,
	constanz,
	COOPBL,
	COPRGTB,
	COPRGTL,
	corbel,
	corbelb,
	corbeli,
	corbell,
	corbelli,
	corbelz,
	cour,
	courb,
	courbi,
	couri,
	CURLZ___,
	ebrima,
	ebrimabd,
	ELEPHNT,
	ELEPHNTI,
	ENGR,
	ERASBD,
	ERASDEMI,
	ERASLGHT,
	ERASMD,
	FELIXTI,
	FORTE,
	FRABK,
	FRABKIT,
	FRADM,
	FRADMCN,
	FRADMIT,
	FRAHV,
	FRAHVIT,
	framd,
	FRAMDCN,
	framdit,
	FREESCPT,
	FRSCRIPT,
	FTLTLT,
	Gabriola,
	gadugi,
	gadugib,
	GARA,
	GARABD,
	GARAIT,
	georgia,
	georgiab,
	georgiai,
	georgiaz,
	GIGI,
	GIL_____,
	GILB____,
	GILBI___,
	GILC____,
	GILI____,
	GILLUBCD,
	GILSANUB,
	GLECB,
	GLSNECB,
	GOTHIC,
	GOTHICB,
	GOTHICBI,
	GOTHICI,
	GOUDOS,
	GOUDOSB,
	GOUDOSI,
	GOUDYSTO,
	HARLOWSI,
	HARNGTON,
	HATTEN,
	holomdl2,
	HPSimplified,
	HPSimplified_BdIt,
	HPSimplified_It,
	HPSimplified_Lt,
	HPSimplified_LtIt,
	HPSimplified_Rg,
	//
	hpsimplifiedjpan_light,
	//
	hpsimplifiedjpan_regular,
	HTOWERT,
	HTOWERTI,
	impact,
	IMPRISHA,
	INFROMAN,
	Inkfree,
	ITCBLKAD,
	ITCEDSCR,
	ITCKRIST,
	javatext,
	JOKERMAN,
	JUICE___,
	KUNSTLER,
	l_10646,
	LATINWD,
	LBRITE,
	LBRITED,
	LBRITEDI,
	LBRITEI,
	LCALLIG,
	LFAX,
	LFAXD,
	LFAXDI,
	LFAXI,
	LHANDW,
	LSANS,
	LSANSD,
	LSANSDI,
	LSANSI,
	LTYPE,
	LTYPEB,
	LTYPEBO,
	LTYPEO,
	lucon,
	MAGNETOB,
	MAIAN,
	MATURASC,
	MISTRAL,
	mmrtext,
	MOD20,
	MTCORSVA,
	NIAGENG,
	NIAGSOL,
	OCRAEXT,
	OLDENGL,
	ONYX,
	pala,
	palab,
	palabi,
	palai,
	PALSCRI,
	PAPYRUS,
	PARCHM,
	PER_____,
	PERB____,
	PERBI___,
	PERI____,
	PERTIBD,
	PERTILI,
	PLAYBILL,
	POORICH,
	PRISTINA,
	RAGE,
	RAVIE,
	REFSAN,
	REFSPCL,
	ROCC____,
	ROCCB___,
	ROCK,
	ROCKB,
	ROCKBI,
	ROCKEB,
	ROCKI,
	SCHLBKB,
	SCHLBKBI,
	SCHLBKI,
	SCRIPTBL,
	segmdl2,
	segoepr,
	segoeprb,
	segoesc,
	segoescb,
	segoeui,
	segoeuib,
	segoeuii,
	segoeuil,
	segoeuisl,
	segoeuiz,
	//
	SegoeWP_Black_0,
	//
	SegoeWP_Bold_0,
	//
	SegoeWP_Light_0,
	//
	SegoeWP_Semibold_0,
	//
	SegoeWP_Semilight_0,
	seguibl,
	seguibli,
	seguiemj,
	seguihis,
	seguili,
	seguisb,
	seguisbi,
	seguisli,
	seguisym,
	SHOWG,
	SNAP____,
	STENCIL,
	sylfaen,
	symbol,
	tahoma,
	tahomabd,
	TCB_____,
	TCBI____,
	TCCB____,
	TCCEB,
	TCCM____,
	TCM_____,
	TCMI____,
	TEMPSITC,
	times,
	timesbd,
	timesbi,
	timesi,
	trebuc,
	trebucbd,
	trebucbi,
	trebucit,
	verdana,
	verdanab,
	verdanai,
	verdanaz,
	VINERITC,
	VIVALDII,
	VLADIMIR,
	webdings,
	wingding,
	WINGDNG2,
	WINGDNG3
};

class RenderText
{
	public:
		int Init();
		void Load();
		SDL_Texture* CreateNewTexture(const char* Text, SDL_Rect TextRect, fonts font, SDL_Colour textColour, int FontSize = 82);
		void Clean();
	private:
		TTF_Font* M_CalibriFont = nullptr;
		TTF_Font* M_AGENCYB = nullptr;
		TTF_Font* M_AGENCYR = nullptr;
		TTF_Font* M_ALGER = nullptr;
		TTF_Font* M_ANTQUAB = nullptr;
		TTF_Font* M_ANTQUABI = nullptr;
		TTF_Font* M_ANTQUAI = nullptr;
		TTF_Font* M_arial = nullptr;
		TTF_Font* M_arialbd = nullptr;
		TTF_Font* M_arialbi = nullptr;
		TTF_Font* M_ariali = nullptr;
		TTF_Font* M_ARIALN = nullptr;
		TTF_Font* M_ARIALNB = nullptr;
		TTF_Font* M_ARIALNBI = nullptr;
		TTF_Font* M_ARIALNI = nullptr;
		TTF_Font* M_ariblk = nullptr;
		TTF_Font* M_ARLRDBD = nullptr;
		TTF_Font* M_bahnschrift = nullptr;
		TTF_Font* M_BASKVILL = nullptr;
		TTF_Font* M_BAUHS93 = nullptr;
		TTF_Font* M_BELL = nullptr;
		TTF_Font* M_BELLB = nullptr;
		TTF_Font* M_BELLI = nullptr;
		TTF_Font* M_BERNHC = nullptr;
		TTF_Font* M_BKANT = nullptr;
		TTF_Font* M_BOD_B = nullptr;
		TTF_Font* M_BOD_BI = nullptr;
		TTF_Font* M_BOD_BLAI = nullptr;
		TTF_Font* M_BOD_BLAR = nullptr;
		TTF_Font* M_BOD_CB = nullptr;
		TTF_Font* M_BOD_CBI = nullptr;
		TTF_Font* M_BOD_CI = nullptr;
		TTF_Font* M_BOD_CR = nullptr;
		TTF_Font* M_BOD_I = nullptr;
		TTF_Font* M_BOD_PSTC = nullptr;
		TTF_Font* M_BOD_R = nullptr;
		TTF_Font* M_BOOKOS = nullptr;
		TTF_Font* M_BOOKOSB = nullptr;
		TTF_Font* M_BOOKOSBI = nullptr;
		TTF_Font* M_BOOKOSI = nullptr;
		TTF_Font* M_BRADHITC = nullptr;
		TTF_Font* M_BRITANIC = nullptr;
		TTF_Font* M_BRLNSB = nullptr;
		TTF_Font* M_BRLNSDB = nullptr;
		TTF_Font* M_BRLNSR = nullptr;
		TTF_Font* M_BROADW = nullptr;
		TTF_Font* M_BRUSHSCI = nullptr;
		TTF_Font* M_BSSYM7 = nullptr;
		TTF_Font* M_calibrib = nullptr;
		TTF_Font* M_calibrii = nullptr;
		TTF_Font* M_calibril = nullptr;
		TTF_Font* M_calibrili = nullptr;
		TTF_Font* M_calibriz = nullptr;
		TTF_Font* M_CALIFB = nullptr;
		TTF_Font* M_CALIFI = nullptr;
		TTF_Font* M_CALIFR = nullptr;
		TTF_Font* M_CALIST = nullptr;
		TTF_Font* M_CALISTB = nullptr;
		TTF_Font* M_CALISTBI = nullptr;
		TTF_Font* M_CALISTI = nullptr;
		TTF_Font* M_cambriab = nullptr;
		TTF_Font* M_cambriai = nullptr;
		TTF_Font* M_cambriaz = nullptr;
		TTF_Font* M_Candara = nullptr;
		TTF_Font* M_Candarab = nullptr;
		TTF_Font* M_Candarai = nullptr;
		TTF_Font* M_Candaral = nullptr;
		TTF_Font* M_Candarali = nullptr;
		TTF_Font* M_Candaraz = nullptr;
		TTF_Font* M_CASTELAR = nullptr;
		TTF_Font* M_CENSCBK = nullptr;
		TTF_Font* M_CENTAUR = nullptr;
		TTF_Font* M_CENTURY = nullptr;
		TTF_Font* M_CHILLER = nullptr;
		TTF_Font* M_COLONNA = nullptr;
		TTF_Font* M_comic = nullptr;
		TTF_Font* M_comicbd = nullptr;
		TTF_Font* M_comici = nullptr;
		TTF_Font* M_comicz = nullptr;
		TTF_Font* M_consola = nullptr;
		TTF_Font* M_consolab = nullptr;
		TTF_Font* M_consolai = nullptr;
		TTF_Font* M_consolaz = nullptr;
		TTF_Font* M_constan = nullptr;
		TTF_Font* M_constanb = nullptr;
		TTF_Font* M_constani = nullptr;
		TTF_Font* M_constanz = nullptr;
		TTF_Font* M_COOPBL = nullptr;
		TTF_Font* M_COPRGTB = nullptr;
		TTF_Font* M_COPRGTL = nullptr;
		TTF_Font* M_corbel = nullptr;
		TTF_Font* M_corbelb = nullptr;
		TTF_Font* M_corbeli = nullptr;
		TTF_Font* M_corbell = nullptr;
		TTF_Font* M_corbelli = nullptr;
		TTF_Font* M_corbelz = nullptr;
		TTF_Font* M_cour = nullptr;
		TTF_Font* M_courbd = nullptr;
		TTF_Font* M_courbi = nullptr;
		TTF_Font* M_couri = nullptr;
		TTF_Font* M_CURLZ___ = nullptr;
		TTF_Font* M_ebrima = nullptr;
		TTF_Font* M_ebrimabd = nullptr;
		TTF_Font* M_ELEPHNT = nullptr;
		TTF_Font* M_ELEPHNTI = nullptr;
		TTF_Font* M_ENGR = nullptr;
		TTF_Font* M_ERASBD = nullptr;
		TTF_Font* M_ERASDEMI = nullptr;
		TTF_Font* M_ERASLGHT = nullptr;
		TTF_Font* M_ERASMD = nullptr;
		TTF_Font* M_FELIXTI = nullptr;
		TTF_Font* M_FORTE = nullptr;
		TTF_Font* M_FRABK = nullptr;
		TTF_Font* M_FRABKIT = nullptr;
		TTF_Font* M_FRADM = nullptr;
		TTF_Font* M_FRADMCN = nullptr;
		TTF_Font* M_FRADMIT = nullptr;
		TTF_Font* M_FRAHV = nullptr;
		TTF_Font* M_FRAHVIT = nullptr;
		TTF_Font* M_framd = nullptr;
		TTF_Font* M_FRAMDCN = nullptr;
		TTF_Font* M_framdit = nullptr;
		TTF_Font* M_FREESCPT = nullptr;
		TTF_Font* M_FRSCRIPT = nullptr;
		TTF_Font* M_FTLTLT = nullptr;
		TTF_Font* M_Gabriola = nullptr;
		TTF_Font* M_gadugi = nullptr;
		TTF_Font* M_gadugib = nullptr;
		TTF_Font* M_GARA = nullptr;
		TTF_Font* M_GARABD = nullptr;
		TTF_Font* M_GARAIT = nullptr;
		TTF_Font* M_georgia = nullptr;
		TTF_Font* M_georgiab = nullptr;
		TTF_Font* M_georgiai = nullptr;
		TTF_Font* M_georgiaz = nullptr;
		TTF_Font* M_GIGI = nullptr;
		TTF_Font* M_GIL_____ = nullptr;
		TTF_Font* M_GILB____ = nullptr;
		TTF_Font* M_GILBI___ = nullptr;
		TTF_Font* M_GILC____ = nullptr;
		TTF_Font* M_GILI____ = nullptr;
		TTF_Font* M_GILLUBCD = nullptr;
		TTF_Font* M_GILSANUB = nullptr;
		TTF_Font* M_GLECB = nullptr;
		TTF_Font* M_GLSNECB = nullptr;
		TTF_Font* M_GOTHIC = nullptr;
		TTF_Font* M_GOTHICB = nullptr;
		TTF_Font* M_GOTHICBI = nullptr;
		TTF_Font* M_GOTHICI = nullptr;
		TTF_Font* M_GOUDOS = nullptr;
		TTF_Font* M_GOUDOSB = nullptr;
		TTF_Font* M_GOUDOSI = nullptr;
		TTF_Font* M_GOUDYSTO = nullptr;
		TTF_Font* M_HARLOWSI = nullptr;
		TTF_Font* M_HARNGTON = nullptr;
		TTF_Font* M_HATTEN = nullptr;
		TTF_Font* M_holomdl2 = nullptr;
		TTF_Font* M_HPSimplified = nullptr;
		TTF_Font* M_HPSimplified_BdIt = nullptr;
		TTF_Font* M_HPSimplified_It = nullptr;
		TTF_Font* M_HPSimplified_Lt = nullptr;
		TTF_Font* M_HPSimplified_LtIt = nullptr;
		TTF_Font* M_HPSimplified_Rg = nullptr;
		//
		TTF_Font* M_hpsimplifiedjpan_light = nullptr;
		//
		TTF_Font* M_hpsimplifiedjpan_regular = nullptr;
		TTF_Font* M_HTOWERT = nullptr;
		TTF_Font* M_HTOWERTI = nullptr;
		TTF_Font* M_impact = nullptr;
		TTF_Font* M_IMPRISHA = nullptr;
		TTF_Font* M_INFROMAN = nullptr;
		TTF_Font* M_Inkfree = nullptr;
		TTF_Font* M_ITCBLKAD = nullptr;
		TTF_Font* M_ITCEDSCR = nullptr;
		TTF_Font* M_ITCKRIST = nullptr;
		TTF_Font* M_javatext = nullptr;
		TTF_Font* M_JOKERMAN = nullptr;
		TTF_Font* M_JUICE___ = nullptr;
		TTF_Font* M_KUNSTLER = nullptr;
		TTF_Font* M_l_10646 = nullptr;
		TTF_Font* M_LATINWD = nullptr;
		TTF_Font* M_LBRITE = nullptr;
		TTF_Font* M_LBRITED = nullptr;
		TTF_Font* M_LBRITEDI = nullptr;
		TTF_Font* M_LBRITEI = nullptr;
		TTF_Font* M_LCALLIG = nullptr;
		TTF_Font* M_LFAX = nullptr;
		TTF_Font* M_LFAXD = nullptr;
		TTF_Font* M_LFAXDI = nullptr;
		TTF_Font* M_LFAXI = nullptr;
		TTF_Font* M_LHANDW = nullptr;
		TTF_Font* M_LSANS = nullptr;
		TTF_Font* M_LSANSD = nullptr;
		TTF_Font* M_LSANSDI = nullptr;
		TTF_Font* M_LSANSI = nullptr;
		TTF_Font* M_LTYPE = nullptr;
		TTF_Font* M_LTYPEB = nullptr;
		TTF_Font* M_LTYPEBO = nullptr;
		TTF_Font* M_LTYPEO = nullptr;
		TTF_Font* M_lucon = nullptr;
		TTF_Font* M_MAGNETOB = nullptr;
		TTF_Font* M_MAIAN = nullptr;
		TTF_Font* M_MATURASC = nullptr;
		TTF_Font* M_MISTRAL = nullptr;
		TTF_Font* M_mmrtext = nullptr;
		TTF_Font* M_MOD20 = nullptr;
		TTF_Font* M_MTCORSVA = nullptr;
		TTF_Font* M_NIAGENG = nullptr;
		TTF_Font* M_NIAGSOL = nullptr;
		TTF_Font* M_OCRAEXT = nullptr;
		TTF_Font* M_OLDENGL = nullptr;
		TTF_Font* M_ONYX = nullptr;
		TTF_Font* M_pala = nullptr;
		TTF_Font* M_palab = nullptr;
		TTF_Font* M_palabi = nullptr;
		TTF_Font* M_palai = nullptr;
		TTF_Font* M_PALSCRI = nullptr;
		TTF_Font* M_PAPYRUS = nullptr;
		TTF_Font* M_PARCHM = nullptr;
		TTF_Font* M_PER_____ = nullptr;
		TTF_Font* M_PERB____ = nullptr;
		TTF_Font* M_PERBI___ = nullptr;
		TTF_Font* M_PERI____ = nullptr;
		TTF_Font* M_PERTIBD = nullptr;
		TTF_Font* M_PERTILI = nullptr;
		TTF_Font* M_PLAYBILL = nullptr;
		TTF_Font* M_POORICH = nullptr;
		TTF_Font* M_PRISTINA = nullptr;
		TTF_Font* M_RAGE = nullptr;
		TTF_Font* M_RAVIE = nullptr;
		TTF_Font* M_REFSAN = nullptr;
		TTF_Font* M_REFSPCL = nullptr;
		TTF_Font* M_ROCC____ = nullptr;
		TTF_Font* M_ROCCB___ = nullptr;
		TTF_Font* M_ROCK = nullptr;
		TTF_Font* M_ROCKB = nullptr;
		TTF_Font* M_ROCKBI = nullptr;
		TTF_Font* M_ROCKEB = nullptr;
		TTF_Font* M_ROCKI = nullptr;
		TTF_Font* M_SCHLBKB = nullptr;
		TTF_Font* M_SCHLBKBI = nullptr;
		TTF_Font* M_SCHLBKI = nullptr;
		TTF_Font* M_SCRIPTBL = nullptr;
		TTF_Font* M_segmdl2 = nullptr;
		TTF_Font* M_segoepr = nullptr;
		TTF_Font* M_segoeprb = nullptr;
		TTF_Font* M_segoesc = nullptr;
		TTF_Font* M_segoescb = nullptr;
		TTF_Font* M_segoeui = nullptr;
		TTF_Font* M_segoeuib = nullptr;
		TTF_Font* M_segoeuii = nullptr;
		TTF_Font* M_segoeuil = nullptr;
		TTF_Font* M_segoeuisl = nullptr;
		TTF_Font* M_segoeuiz = nullptr;
		//
		TTF_Font* M_SegoeWP_Black_0 = nullptr;
		//
		TTF_Font* M_SegoeWP_Bold_0 = nullptr;
		//
		TTF_Font* M_SegoeWP_Light_0 = nullptr;
		//
		TTF_Font* M_SegoeWP_Semibold_0 = nullptr;
		//
		TTF_Font* M_SegoeWP_Semilight_0 = nullptr;
		TTF_Font* M_seguibl = nullptr;
		TTF_Font* M_seguibli = nullptr;
		TTF_Font* M_seguiemj = nullptr;
		TTF_Font* M_seguihis = nullptr;
		TTF_Font* M_seguili = nullptr;
		TTF_Font* M_seguisb = nullptr;
		TTF_Font* M_seguisbi = nullptr;
		TTF_Font* M_seguisli = nullptr;
		TTF_Font* M_seguisym = nullptr;
		TTF_Font* M_SHOWG = nullptr;
		TTF_Font* M_SNAP____ = nullptr;
		TTF_Font* M_STENCIL = nullptr;
		TTF_Font* M_sylfaen = nullptr;
		TTF_Font* M_symbol = nullptr;
		TTF_Font* M_tahoma = nullptr;
		TTF_Font* M_tahomabd = nullptr;
		TTF_Font* M_TCB_____ = nullptr;
		TTF_Font* M_TCBI____ = nullptr;
		TTF_Font* M_TCCB____ = nullptr;
		TTF_Font* M_TCCEB = nullptr;
		TTF_Font* M_TCCM____ = nullptr;
		TTF_Font* M_TCM_____ = nullptr;
		TTF_Font* M_TCMI____ = nullptr;
		TTF_Font* M_TEMPSITC = nullptr;
		TTF_Font* M_times = nullptr;
		TTF_Font* M_timesbd = nullptr;
		TTF_Font* M_timesbi = nullptr;
		TTF_Font* M_timesi = nullptr;
		TTF_Font* M_trebuc = nullptr;
		TTF_Font* M_trebucbd = nullptr;
		TTF_Font* M_trebucbi = nullptr;
		TTF_Font* M_trebucit = nullptr;
		TTF_Font* M_verdana = nullptr;
		TTF_Font* M_verdanab = nullptr;
		TTF_Font* M_verdanai = nullptr;
		TTF_Font* M_verdanaz = nullptr;
		TTF_Font* M_VINERITC = nullptr;
		TTF_Font* M_VIVALDII = nullptr;
		TTF_Font* M_VLADIMIR = nullptr;
		TTF_Font* M_webdings = nullptr;
		TTF_Font* M_wingding = nullptr;
		TTF_Font* M_WINGDNG2 = nullptr;
		TTF_Font* M_WINGDNG3 = nullptr;

		std::vector<TTF_Font*> Fonts;
		std::vector<const char*> FontsFileAdress;
};
