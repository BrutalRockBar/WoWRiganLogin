object Form2: TForm2
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1054#1087#1094#1080#1080
  ClientHeight = 201
  ClientWidth = 522
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 87
    Width = 48
    Height = 13
    Caption = 'WoW.exe'
  end
  object Label2: TLabel
    Left = 25
    Top = 57
    Width = 31
    Height = 13
    Caption = #1056#1072#1076#1080#1086
  end
  object Label4: TLabel
    Left = 8
    Top = 147
    Width = 113
    Height = 13
    Caption = #1047#1072#1076#1077#1088#1078#1082#1072' '#1074#1074#1086#1076#1072' ('#1089#1077#1082')'
  end
  object Label5: TLabel
    Left = 8
    Top = 120
    Width = 36
    Height = 13
    Caption = #1057#1087#1086#1089#1086#1073
  end
  object Edit1: TEdit
    Left = 62
    Top = 84
    Width = 419
    Height = 21
    MaxLength = 255
    TabOrder = 0
  end
  object Button1: TButton
    Left = 487
    Top = 84
    Width = 25
    Height = 25
    Caption = '...'
    TabOrder = 1
    OnClick = Button1Click
  end
  object CheckBox1: TCheckBox
    Left = 8
    Top = 8
    Width = 137
    Height = 17
    Caption = #1040#1074#1090#1086#1079#1072#1087#1091#1089#1082' '#1089' '#1089#1080#1089#1090#1077#1084#1086#1081
    TabOrder = 2
  end
  object CheckBox2: TCheckBox
    Left = 8
    Top = 31
    Width = 105
    Height = 17
    Caption = #1042#1082#1083#1102#1095#1080#1090#1100' '#1088#1072#1076#1080#1086
    TabOrder = 3
  end
  object ComboBox1: TComboBox
    Left = 62
    Top = 54
    Width = 145
    Height = 21
    Style = csDropDownList
    TabOrder = 4
    Items.Strings = (
      'RadioRecord.fm'
      'Radio.Aplus.by'
      'RadioUltra.ru')
  end
  object Button2: TButton
    Left = 406
    Top = 167
    Width = 75
    Height = 25
    Caption = #1054#1050
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 325
    Top = 167
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 6
    OnClick = Button3Click
  end
  object Edit2: TEdit
    Left = 127
    Top = 144
    Width = 18
    Height = 21
    MaxLength = 1
    TabOrder = 7
    OnKeyPress = Edit2KeyPress
  end
  object ComboBox2: TComboBox
    Left = 62
    Top = 117
    Width = 171
    Height = 21
    Style = csDropDownList
    TabOrder = 8
    Items.Strings = (
      #1041#1099#1089#1090#1088#1099#1081'('#1056#1077#1082#1086#1084#1077#1085#1076#1086#1074#1072#1085#1086')'
      #1052#1077#1076#1083#1077#1085#1085#1099#1081)
  end
  object OpenDialog1: TOpenDialog
    Left = 360
    Top = 8
  end
end
