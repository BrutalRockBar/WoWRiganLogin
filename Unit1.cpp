//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "psapi.h"
#include "bass.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
HANDLE hProcess;
DWORD ProcessId;
HWND hokna;
extern HSTREAM chan;
TPoint pt;
double vol;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Timer1->Enabled=false;
AnsiString aLogin=bd->FieldByName("Login")->AsString;
AnsiString aPassword=bd->FieldByName("Password")->AsString;
char * cLogin = new char[aLogin.Length()];
char * cPassword = new char[aPassword.Length()];
strcpy(cLogin,aLogin.c_str());
strcpy(cPassword,aPassword.c_str());

for(int i=0;i<=aLogin.Length();i++)
{
if(cLogin[i]=='_')
{
 keybd_event(VK_LSHIFT , 0, 0, 0);
 keybd_event(VK_OEM_MINUS, 0,0,0);
 keybd_event(VK_OEM_MINUS, 0, KEYEVENTF_KEYUP, 0);
 keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0);
}
else if(cLogin[i]=='-')
{
 keybd_event(VK_OEM_MINUS, 0,0,0);
 keybd_event(VK_OEM_MINUS, 0, KEYEVENTF_KEYUP, 0);
}
else if(cLogin[i]=='[')
{
 keybd_event(0xDB, 0,0,0);
 keybd_event(0xDB, 0, KEYEVENTF_KEYUP, 0);
}
else if(cLogin[i]==']')
{
 keybd_event(0xDD, 0,0,0);
 keybd_event(0xDD, 0, KEYEVENTF_KEYUP, 0);
}
else
{
keybd_event(cLogin[i], 0,0,0);
keybd_event(cLogin[i], 0,KEYEVENTF_KEYUP,0);
}
}

keybd_event(VK_TAB, 0, 0 ,0);
keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP,0);

for(int i=0;i<=aPassword.Length();i++)
{
if(cPassword[i]=='_')
{
 keybd_event(VK_LSHIFT , 0, 0, 0);
 keybd_event(VK_OEM_MINUS, 0,0,0);
 keybd_event(VK_OEM_MINUS, 0, KEYEVENTF_KEYUP, 0);
 keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0);
}
else if(cPassword[i]=='-')
{
 keybd_event(VK_OEM_MINUS, 0,0,0);
 keybd_event(VK_OEM_MINUS, 0, KEYEVENTF_KEYUP, 0);
}
else if(cPassword[i]=='[')
{
 keybd_event(0xDB, 0,0,0);
 keybd_event(0xDB, 0, KEYEVENTF_KEYUP, 0);
}
else if(cPassword[i]==']')
{
 keybd_event(0xDD, 0,0,0);
 keybd_event(0xDD, 0, KEYEVENTF_KEYUP, 0);
}
else
{
keybd_event(cPassword[i], 0,0,0);
keybd_event(cPassword[i], 0,KEYEVENTF_KEYUP,0);
}
}
keybd_event(VK_RETURN, 0, 0,0);
keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
bd->Append();
bd->FieldByName("Login")->AsString=Edit1->Text;
bd->FieldByName("Password")->AsString=Edit2->Text;
bd->Post();
Edit1->Text="Login";
Edit2->Text="Password";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
if (Key==0x16)Key=0;
if(Key>='a' && Key<='z')Key=toupper(Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
{
if (Key==0x16)Key=0;
if(Key>='a' && Key<='z')Key=toupper(Key);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DBGrid1DblClick(TObject *Sender)
{
AnsiString str = bdS->FieldByName("WowDir")->AsString;
WinExec(str.c_str(),SW_SHOW);
hokna= FindWindow (0, "World Of Warcraft");
   if (!(hokna)) {
   Timer2->Enabled=false;
  }
  if (!(GetWindowThreadProcessId(hokna, &ProcessId))) {
   ShowMessage ("WoW íå íàéäåí");
   Timer2->Enabled=false;
  }
  else
  {
  Timer2->Enabled=true;
  Form1->Hide();
  TrayIcon1->Visible = true;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{int oldSize;
if (!(hokna)) {
   Timer2->Enabled=false;
  }
hProcess = OpenProcess(PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, false, ProcessId);
PROCESS_MEMORY_COUNTERS pmc;
GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc));
if(bdS->FieldByName("Mode")->AsString==0)
{
if(pmc.WorkingSetSize==oldSize) {Timer1->Enabled=true;Timer2->Enabled=false;}
else oldSize=pmc.WorkingSetSize;
}

if(bdS->FieldByName("Mode")->AsString==1)
{
if(pmc.WorkingSetSize/1024>=125000) {Timer1->Enabled=true;Timer2->Enabled=false;}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
bd->Delete();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
if(Form1->Width==800)
{
Form1->Width=492;
DBGrid1->Columns->Items[1]->Visible=false;
DBGrid1->Width=177;
Button1->Visible=false;
Button2->Visible=false;
Button5->Visible=false;
Edit1->Visible=false;
Edit2->Visible=false;
DBGrid1->Options=TDBGridOptions()>>dgEditing ;
}
else
{
Form1->Width=800;
DBGrid1->Columns->Items[1]->Visible=true;
DBGrid1->Width=345;
Button1->Visible=true;
Button2->Visible=true;
Button5->Visible=true;
Edit1->Visible=true;
Edit2->Visible=true;
DBGrid1->Options=TDBGridOptions()<<dgEditing ;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
Form1->Hide();
TrayIcon1->Visible = true;
	TrayIcon1->BalloonTimeout = 3000;
	TrayIcon1->BalloonTitle = "ÐûãàíAutoLogin";
	TrayIcon1->BalloonHint = "BrutalRockBar";
	TrayIcon1->ShowBalloonHint();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N1Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
long SC_DRAGMOVE = 0xF012;
if(Button == mbLeft)
{ ReleaseCapture();
SendMessage(Handle, WM_SYSCOMMAND, SC_DRAGMOVE, 0);}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
Timer1->Interval=bdS->FieldByName("Timer")->AsString*1000;
if(bdS->FieldByName("RadioPlayStart")->AsString==1) {vol=1; Radio(); }
else BASS_ChannelStop(chan);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Radio()
{
BASS_ChannelStop(chan);
BASS_Init( -1,44100, BASS_DEVICE_3D,0,NULL);
BASS_SetConfig(BASS_CONFIG_NET_PLAYLIST, 1);
AnsiString b=bdS->FieldByName("RadioDefault")->AsString;
char *a=b.c_str();
chan=BASS_StreamCreateURL(a, 0, BASS_STREAM_STATUS, NULL, 0);
BASS_ChannelSetAttribute(chan, BASS_ATTRIB_VOL, vol);
BASS_ChannelPlay(chan,FALSE);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrayIcon1DblClick(TObject *Sender)
{
Form1->Show();
SetWindowPos(Form1->Handle, HWND_TOPMOST, 0, 0, 0, 0,SWP_NOMOVE | SWP_NOSIZE);
SetWindowPos(Form1->Handle, HWND_NOTOPMOST, 0, 0, 0, 0,SWP_NOMOVE | SWP_NOSIZE);
TrayIcon1->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrayIcon1Click(TObject *Sender)
{
GetCursorPos(&pt);
Form3->Left=pt.x-Form3->Width/2;
Form3->Top=pt.y-Form3->Height-15;
Form3->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RadioRecordfm1Click(TObject *Sender)
{
 bdS->Edit();
 bdS->FieldByName("RadioPlayStart")->AsString=1;
 bdS->FieldByName("RadioDefault")->AsString="http://www.radiorecord.fm/listen/record_128k";
 bdS->Post();
 Radio();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioAplusby1Click(TObject *Sender)
{
 bdS->Edit();
 bdS->FieldByName("RadioPlayStart")->AsString=1;
 bdS->FieldByName("RadioDefault")->AsString="http://shoutcast.byfly.by:88/aplus";
 bdS->Post();
 Radio();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioUltraru1Click(TObject *Sender)
{
 bdS->Edit();
 bdS->FieldByName("RadioPlayStart")->AsString=1;
 bdS->FieldByName("RadioDefault")->AsString="http://94.25.53.132:80/ultra-128.mp3";
 bdS->Post();
 Radio();
}
//---------------------------------------------------------------------------



