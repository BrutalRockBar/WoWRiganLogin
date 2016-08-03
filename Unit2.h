//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TOpenDialog *OpenDialog1;
	TLabel *Label1;
	TEdit *Edit1;
	TButton *Button1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TComboBox *ComboBox1;
	TLabel *Label2;
	TButton *Button2;
	TButton *Button3;
	TLabel *Label4;
	TEdit *Edit2;
	TComboBox *ComboBox2;
	TLabel *Label5;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
