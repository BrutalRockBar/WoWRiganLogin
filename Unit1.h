//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Bde.DBTables.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.MPlayer.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TDBGrid *DBGrid1;
	TDataSource *DataSource1;
	TTimer *Timer1;
	TTimer *Timer2;
	TADOTable *bd;
	TButton *Button2;
	TBitBtn *BitBtn1;
	TImage *Image1;
	TImage *Image2;
	TButton *Button3;
	TButton *Button4;
	TTrayIcon *TrayIcon1;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	TLabel *Label1;
	TLabel *Label2;
	TMediaPlayer *MediaPlayer1;
	TPopupMenu *PopupMenu2;
	TMenuItem *N2;
	TButton *Button5;
	TADOTable *bdS;
	TMenuItem *RadioRecordfm1;
	TMenuItem *RadioAplusby1;
	TMenuItem *RadioUltraru1;
	TLabel *Label3;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Radio();
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall TrayIcon1DblClick(TObject *Sender);
	void __fastcall TrayIcon1Click(TObject *Sender);
	void __fastcall RadioRecordfm1Click(TObject *Sender);
	void __fastcall RadioAplusby1Click(TObject *Sender);
	void __fastcall RadioUltraru1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
