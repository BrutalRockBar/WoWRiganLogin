//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TTrackBar *TrackBar1;
	TTimer *Timer1;
	TCheckBox *CheckBox1;
	void __fastcall FormMouseEnter(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormMouseLeave(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
