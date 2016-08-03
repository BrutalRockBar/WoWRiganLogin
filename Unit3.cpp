//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "bass.h"
#include "Unit1.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
HSTREAM chan;
extern double vol;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormMouseEnter(TObject *Sender)
{
Timer1->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
Form3->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormMouseLeave(TObject *Sender)
{
Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::TrackBar1Change(TObject *Sender)
{
Timer1->Enabled=false;
double a=TrackBar1->Max-TrackBar1->Position;
double b=TrackBar1->Max;
vol=a/b;
if (CheckBox1->Checked!=true)
BASS_ChannelSetAttribute(chan, BASS_ATTRIB_VOL, vol);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::CheckBox1Click(TObject *Sender)
{
if (CheckBox1->Checked==true)
{
	 BASS_ChannelSetAttribute(chan, BASS_ATTRIB_VOL, 0);
}
else
{
	 BASS_ChannelSetAttribute(chan, BASS_ATTRIB_VOL, vol);
}
}
//---------------------------------------------------------------------------
