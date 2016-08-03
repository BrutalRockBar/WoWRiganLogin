object Form3: TForm3
  Left = 0
  Top = 500
  BorderStyle = bsNone
  Caption = 'Form3'
  ClientHeight = 163
  ClientWidth = 45
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poDesigned
  OnMouseEnter = FormMouseEnter
  OnMouseLeave = FormMouseLeave
  PixelsPerInch = 96
  TextHeight = 13
  object TrackBar1: TTrackBar
    Left = 8
    Top = 8
    Width = 27
    Height = 137
    Max = 100
    Orientation = trVertical
    TabOrder = 0
    ThumbLength = 30
    OnChange = TrackBar1Change
  end
  object CheckBox1: TCheckBox
    Left = 16
    Top = 139
    Width = 17
    Height = 17
    TabOrder = 1
    OnClick = CheckBox1Click
  end
  object Timer1: TTimer
    Interval = 3000
    OnTimer = Timer1Timer
    Left = 8
    Top = 48
  end
end
