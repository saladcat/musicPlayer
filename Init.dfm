object Form1: TForm1
  Left = 371
  Top = 55
  Width = 1162
  Height = 707
  VertScrollBar.Position = 189
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object grp_Self: TGroupBox
    Left = 39
    Top = -81
    Width = 169
    Height = 317
    Caption = 'grp_Self'
    TabOrder = 0
    object btn_LoveMs: TButton
      Left = 20
      Top = 30
      Width = 92
      Height = 30
      Caption = 'btn_LoveMs'
      TabOrder = 0
      OnClick = btn_LoveMsClick
    end
    object btn_HisMs: TButton
      Left = 20
      Top = 138
      Width = 92
      Height = 31
      Caption = 'btn_HisMs'
      TabOrder = 1
    end
    object btn_MoodMs: TButton
      Left = 20
      Top = 197
      Width = 92
      Height = 31
      Caption = 'btn_MoodMs'
      TabOrder = 2
    end
    object btn_AlarmMs: TButton
      Left = 20
      Top = 246
      Width = 92
      Height = 31
      Caption = 'btn_AlarmMs'
      TabOrder = 3
    end
    object btn_LocalMs: TButton
      Left = 20
      Top = 79
      Width = 92
      Height = 31
      Caption = 'btn_LocalMs'
      TabOrder = 4
    end
  end
  object grp_MsList: TGroupBox
    Left = 39
    Top = 264
    Width = 169
    Height = 218
    Caption = 'grp_MsList'
    TabOrder = 1
    object btn_MsList1: TButton
      Left = 20
      Top = 30
      Width = 92
      Height = 30
      Caption = 'btn_MsList1'
      TabOrder = 0
    end
    object btn_MsList2: TButton
      Left = 20
      Top = 89
      Width = 92
      Height = 30
      Caption = 'btn_MsList2'
      TabOrder = 1
    end
    object btn_MsList3: TButton
      Left = 20
      Top = 148
      Width = 92
      Height = 30
      Caption = 'btn_MsList3'
      TabOrder = 2
    end
  end
  object btn_Figure: TButton
    Left = 39
    Top = -169
    Width = 149
    Height = 60
    Caption = 'btn_Figure'
    TabOrder = 2
  end
  object grp_Init_MsList: TGroupBox
    Left = 236
    Top = 18
    Width = 730
    Height = 464
    Caption = 'grp_Init_MsList'
    TabOrder = 3
    object btn_CreMsList: TButton
      Left = 39
      Top = 89
      Width = 149
      Height = 70
      Caption = 'btn_CreMsList'
      TabOrder = 0
    end
    object btn_MsList01: TButton
      Left = 463
      Top = 89
      Width = 119
      Height = 70
      Caption = 'btn_MsList01'
      TabOrder = 1
    end
    object btn_MsList02: TButton
      Left = 59
      Top = 286
      Width = 110
      Height = 99
      Caption = 'btn_MsList02'
      TabOrder = 2
    end
    object btn_MsList03: TButton
      Left = 463
      Top = 276
      Width = 139
      Height = 109
      Caption = 'btn_MsList03'
      TabOrder = 3
    end
  end
  object grp_ConWins: TGroupBox
    Left = 601
    Top = -179
    Width = 365
    Height = 60
    Caption = 'grp_ConWins'
    TabOrder = 4
    object rbtn_WinMin: TRadioButton
      Left = 0
      Top = 30
      Width = 100
      Height = 20
      Caption = 'rbtn_WinMin'
      TabOrder = 0
    end
    object rbtn_WinMax: TRadioButton
      Left = 108
      Top = 30
      Width = 110
      Height = 20
      Caption = 'rbtn_WinMax'
      TabOrder = 1
    end
    object rbtn_WinClose: TRadioButton
      Left = 226
      Top = 30
      Width = 140
      Height = 20
      Caption = 'rbtn_WinClose'
      TabOrder = 2
    end
  end
  object grp_PreMs: TGroupBox
    Left = 236
    Top = -92
    Width = 730
    Height = 109
    Caption = 'grp_PreMs'
    TabOrder = 5
    object Edit1: TEdit
      Left = 176
      Top = 32
      Width = 145
      Height = 24
      TabOrder = 0
      Text = 'Edit1'
    end
  end
  object grp_Search: TGroupBox
    Left = 236
    Top = -179
    Width = 218
    Height = 60
    Caption = 'grp_Search'
    TabOrder = 6
    object txt_Search: TEdit
      Left = 10
      Top = 30
      Width = 90
      Height = 24
      TabOrder = 0
      Text = 'txt_Search'
    end
    object btn_Search: TButton
      Left = 108
      Top = 20
      Width = 93
      Height = 30
      Caption = 'btn_Search'
      TabOrder = 1
    end
  end
  object btn_DressTrans: TButton
    Left = 463
    Top = -159
    Width = 129
    Height = 30
    Caption = 'btn_DressTrans'
    TabOrder = 7
  end
  object grp_MsCon: TGroupBox
    Left = 20
    Top = 510
    Width = 346
    Height = 129
    Caption = 'grp_MsCon'
    TabOrder = 8
    object btn_Play: TButton
      Left = 118
      Top = 30
      Width = 70
      Height = 30
      Caption = 'btn_Play'
      TabOrder = 0
      OnClick = btn_PlayClick
    end
    object btn_Pause: TButton
      Left = 118
      Top = 71
      Width = 80
      Height = 40
      Caption = 'btn_Pause'
      TabOrder = 1
    end
    object btn_Next: TButton
      Left = 217
      Top = 20
      Width = 70
      Height = 40
      Caption = 'btn_Next'
      TabOrder = 2
    end
    object btn_Pre: TButton
      Left = 10
      Top = 30
      Width = 92
      Height = 30
      Caption = 'btn_Pre'
      TabOrder = 3
    end
  end
  object grp_Playig: TGroupBox
    Left = 404
    Top = 510
    Width = 542
    Height = 129
    Caption = 'grp_Playig'
    TabOrder = 9
    object playingSongName: TLabel
      Left = 192
      Top = 16
      Width = 113
      Height = 16
      Caption = 'playingSongName'
    end
    object btn_openPlayList: TSpeedButton
      Left = 456
      Top = 56
      Width = 25
      Height = 25
      OnClick = btn_openPlayListClick
    end
    object btn_openLrc: TSpeedButton
      Left = 24
      Top = 32
      Width = 73
      Height = 65
      OnClick = btn_openLrcClick
    end
    object ProgressBar1: TProgressBar
      Left = 128
      Top = 49
      Width = 287
      Height = 21
      Min = 0
      Max = 100
      TabOrder = 0
    end
  end
  object MediaPlayer: TMediaPlayer
    Left = 968
    Top = 3
    Width = 253
    Height = 73
    TabOrder = 10
  end
  object diaLoadMs: TOpenDialog
    Options = [ofHideReadOnly, ofAllowMultiSelect, ofEnableSizing]
    Left = 160
    Top = 136
  end
  object lrcTimer: TTimer
    Enabled = False
    Interval = 50
    OnTimer = lrcTimerTimer
    Left = 1032
    Top = 280
  end
end
