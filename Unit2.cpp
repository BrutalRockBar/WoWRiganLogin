//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <Registry.hpp>
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
 TRegistry *reg = new TRegistry();
 reg->RootKey=HKEY_CURRENT_USER;

 Form1->bdS->Edit();
 if(CheckBox2->Checked==true) Form1->bdS->FieldByName("RadioPlayStart")->AsString=1;
 else Form1->bdS->FieldByName("RadioPlayStart")->AsString=0;
 if(CheckBox1->Checked==true)
 {
 Form1->bdS->FieldByName("AutoStartWin")->AsString=1;
 reg->OpenKey("Software\\Microsoft\\Windows\\CurrentVersion\\Run",true);
 reg->WriteString("ÐûãàíAutoLogin",Application->ExeName);
 reg->CloseKey();
 }
 else
 {
 Form1->bdS->FieldByName("AutoStartWin")->AsString=0;
 reg->OpenKey("Software\\Microsoft\\Windows\\CurrentVersion\\Run",true);
 reg->DeleteValue("ÐûãàíAutoLogin");
 reg->CloseKey();
 }
 if(ComboBox1->Text=="RadioRecord.fm")
 {
	 Form1->bdS->FieldByName("RadioDefault")->AsString="http://www.radiorecord.fm/listen/record_128k";
 }
 if(ComboBox1->Text=="Radio.Aplus.by")
 {
	 Form1->bdS->FieldByName("RadioDefault")->AsString="http://shoutcast.byfly.by:88/aplus";
 }
 if(ComboBox1->Text=="RadioUltra.ru")
 {
	 Form1->bdS->FieldByName("RadioDefault")->AsString="http://94.25.53.132:80/ultra-128.mp3";
 }

 if(ComboBox2->Text=="Áûñòðûé(Ðåêîìåíäîâàíî)")
 {
   Form1->bdS->FieldByName("Mode")->AsString=0;
 }
 if(ComboBox2->Text=="Ìåäëåííûé")
 {
   Form1->bdS->FieldByName("Mode")->AsString=1;
 }
 Form1->bdS->FieldByName("WowDir")->AsString=Edit1->Text;
 Form1->bdS->FieldByName("Timer")->AsString=Edit2->Text;
 Form1->bdS->Post();
 Form2->Close();
 Form1->FormCreate(Form2);
 delete reg;
 reg = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
if(Form1->bdS->FieldByName("AutoStartWin")->AsString == 1) CheckBox1->Checked=true;
else CheckBox1->Checked=false;
if(Form1->bdS->FieldByName("RadioPlayStart")->AsString == 1) CheckBox2->Checked=true;
else CheckBox2->Checked=false;
 if(Form1->bdS->FieldByName("RadioDefault")->AsString=="http://www.radiorecord.fm/listen/record_128k")
 {
	 ComboBox1->ItemIndex=0;
 }
 if(Form1->bdS->FieldByName("RadioDefault")->AsString=="http://shoutcast.byfly.by:88/aplus")
 {
	 ComboBox1->ItemIndex=1;
 }
 if(Form1->bdS->FieldByName("RadioDefault")->AsString=="http://94.25.53.132:80/ultra-128.mp3")
 {
	 ComboBox1->ItemIndex=2;
 }

  if(Form1->bdS->FieldByName("Mode")->AsString==0)
 {
   ComboBox2->ItemIndex=0;
 }
 if(Form1->bdS->FieldByName("Mode")->AsString==1)
 {
   ComboBox2->ItemIndex=1;
 }
Edit1->Text=Form1->bdS->FieldByName("WowDir")->AsString;
Edit2->Text=Form1->bdS->FieldByName("Timer")->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
OpenDialog1->Execute();
Edit1->Text=OpenDialog1->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
{
if(Key>='0' && Key<='9'){}
else Key=0;
}
//---------------------------------------------------------------------------

