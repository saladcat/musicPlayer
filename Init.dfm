object Form1: TForm1
  Left = 2194
  Top = 48
  Width = 967
  Height = 857
  AutoSize = True
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
  object Image1: TImage
    Left = 508
    Top = 483
    Width = 105
    Height = 105
  end
  object SpeedButton3: TSpeedButton
    Left = 32
    Top = 40
    Width = 25
    Height = 25
  end
  object Label4: TLabel
    Left = 96
    Top = 40
    Width = 41
    Height = 16
    Caption = 'Label2'
  end
  object grp_Self: TGroupBox
    Left = 19
    Top = 98
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
      OnClick = btn_HisMsClick
    end
    object btn_MoodMs: TButton
      Left = 20
      Top = 189
      Width = 93
      Height = 36
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
      OnClick = btn_LocalMsClick
    end
  end
  object grp_MsList: TGroupBox
    Left = 19
    Top = 443
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
    Left = 19
    Top = 10
    Width = 149
    Height = 60
    Caption = 'btn_Figure'
    TabOrder = 2
  end
  object grp_Init_MsList: TGroupBox
    Left = 216
    Top = 197
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
      OnClick = btn_CreMsListClick
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
    Left = 636
    Top = 0
    Width = 310
    Height = 60
    Caption = 'grp_ConWins'
    TabOrder = 4
    object rbtn_WinMin: TRadioButton
      Left = 16
      Top = 30
      Width = 100
      Height = 20
      Caption = 'rbtn_WinMin'
      TabOrder = 0
      OnClick = rbtn_WinMinClick
    end
    object rbtn_WinClose: TRadioButton
      Left = 162
      Top = 30
      Width = 140
      Height = 20
      Caption = 'rbtn_WinClose'
      TabOrder = 1
      OnClick = rbtn_WinCloseClick
    end
  end
  object grp_PreMs: TGroupBox
    Left = 216
    Top = 87
    Width = 730
    Height = 109
    Caption = 'grp_PreMs'
    TabOrder = 5
    object btn_hisMs1: TSpeedButton
      Left = 32
      Top = 40
      Width = 73
      Height = 33
    end
    object btn_hisMs2: TSpeedButton
      Left = 136
      Top = 32
      Width = 129
      Height = 49
    end
    object btn_hisMs3: TSpeedButton
      Left = 304
      Top = 24
      Width = 161
      Height = 65
    end
    object btn_hisMs4: TSpeedButton
      Left = 520
      Top = 16
      Width = 193
      Height = 81
    end
  end
  object grp_Search: TGroupBox
    Left = 216
    Top = 0
    Width = 277
    Height = 60
    Caption = 'grp_Search'
    TabOrder = 6
    object txt_Search: TEdit
      Left = 10
      Top = 22
      Width = 159
      Height = 24
      TabOrder = 0
      Text = 'txt_Search'
    end
    object btn_Search: TButton
      Left = 172
      Top = 20
      Width = 93
      Height = 30
      Caption = 'btn_Search'
      TabOrder = 1
      OnClick = btn_SearchClick
    end
  end
  object btn_DressTrans: TButton
    Left = 499
    Top = 20
    Width = 129
    Height = 30
    Caption = 'btn_DressTrans'
    TabOrder = 7
  end
  object grp_MsCon: TGroupBox
    Left = 0
    Top = 681
    Width = 346
    Height = 129
    Caption = 'grp_MsCon'
    TabOrder = 8
    object volumeBar: TImage
      Left = 121
      Top = 96
      Width = 5
      Height = 14
      AutoSize = True
      Picture.Data = {
        07544269746D617016010000424D160100000000000036000000280000000500
        00000E0000000100180000000000E0000000120B0000120B0000000000000000
        00003B3228322B22322B22312A213C322800332D229E958C898073A0968C302B
        2200312A217E756C5E55487C736A322B2200322B227069604E453B706960322B
        2200302B22655D5641382E645C55322B22002F2A215B554E352F245B554E322B
        2200302B2257514A312B2057514A322B2200302B225A544D352F245A544D312C
        2300302B22625C553E382D625C55302B22002F2C246F685F51443C71685E2F2C
        2400312A217D746A5D53497B756A322C2100332D22897F756D6157887E74332D
        2200342B21A49B918F857BA39A90342B22003A3429322C21312A21302B223D34
        2AFF}
      OnMouseMove = volumeBarMouseMove
    end
    object Label1: TLabel
      Left = 152
      Top = 64
      Width = 41
      Height = 16
      Caption = 'Label1'
    end
    object btn_Play: TButton
      Left = 134
      Top = 22
      Width = 75
      Height = 35
      Caption = 'btn_Play'
      TabOrder = 0
      OnClick = btn_PlayClick
    end
    object btn_Next: TButton
      Left = 241
      Top = 20
      Width = 70
      Height = 40
      Caption = 'btn_Next'
      TabOrder = 1
      OnClick = btn_NextClick
    end
    object btn_Pre: TButton
      Left = 18
      Top = 24
      Width = 92
      Height = 36
      Caption = 'btn_Pre'
      TabOrder = 2
      OnClick = btn_PreClick
    end
    object TrackBar: TTrackBar
      Left = 216
      Top = 80
      Width = 121
      Height = 25
      Orientation = trHorizontal
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 3
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = TrackBarChange
    end
    object Edit1: TEdit
      Left = 40
      Top = 64
      Width = 81
      Height = 24
      TabOrder = 4
      Text = 'Edit1'
    end
  end
  object grp_Playig: TGroupBox
    Left = 384
    Top = 681
    Width = 565
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
    object processBarbar: TImage
      Left = 128
      Top = 72
      Width = 5
      Height = 14
      AutoSize = True
      Picture.Data = {
        07544269746D617016010000424D160100000000000036000000280000000500
        00000E0000000100180000000000E0000000120B0000120B0000000000000000
        00003B3228322B22322B22312A213C322800332D229E958C898073A0968C302B
        2200312A217E756C5E55487C736A322B2200322B227069604E453B706960322B
        2200302B22655D5641382E645C55322B22002F2A215B554E352F245B554E322B
        2200302B2257514A312B2057514A322B2200302B225A544D352F245A544D312C
        2300302B22625C553E382D625C55302B22002F2C246F685F51443C71685E2F2C
        2400312A217D746A5D53497B756A322C2100332D22897F756D6157887E74332D
        2200342B21A49B918F857BA39A90342B22003A3429322C21312A21302B223D34
        2AFF}
      OnMouseMove = processBarbarMouseMove
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
    Left = 36
    Top = 630
    Width = 253
    Height = 73
    Visible = False
    TabOrder = 10
  end
  object grp_SongList: TGroupBox
    Left = 212
    Top = 94
    Width = 737
    Height = 577
    Caption = 'grp_SongList'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    Visible = False
    object lb_SongListName: TLabel
      Left = 184
      Top = 40
      Width = 497
      Height = 41
      Caption = 'lb_SongListName'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Microsoft YaHei UI'
      Font.Style = []
      ParentFont = False
    end
    object btn_PlaySelct: TSpeedButton
      Left = 48
      Top = 96
      Width = 65
      Height = 49
      OnClick = btn_PlaySelctClick
    end
    object btn_delSongList: TSpeedButton
      Left = 184
      Top = 96
      Width = 73
      Height = 49
      OnClick = btn_delSongListClick
    end
    object btn_sort: TSpeedButton
      Left = 328
      Top = 96
      Width = 73
      Height = 49
    end
    object btn_SongListSearch: TSpeedButton
      Left = 592
      Top = 104
      Width = 89
      Height = 41
    end
    object GroupBox1: TGroupBox
      Left = 200
      Top = 168
      Width = 489
      Height = 385
      Caption = 'GroupBox1'
      TabOrder = 0
      object btn_song5: TSpeedButton
        Left = 32
        Top = 280
        Width = 25
        Height = 25
        OnClick = btn_song5Click
      end
      object lb_song0: TLabel
        Left = 96
        Top = 40
        Width = 55
        Height = 16
        Caption = 'lb_song0'
      end
      object btn_song1: TSpeedButton
        Left = 32
        Top = 88
        Width = 25
        Height = 25
        OnClick = btn_song1Click
      end
      object lb_song1: TLabel
        Left = 96
        Top = 88
        Width = 41
        Height = 16
        Caption = 'Label2'
      end
      object btn_song2: TSpeedButton
        Left = 32
        Top = 136
        Width = 25
        Height = 25
        OnClick = btn_song2Click
      end
      object lb_song2: TLabel
        Left = 96
        Top = 136
        Width = 41
        Height = 16
        Caption = 'Label2'
      end
      object btn_song3: TSpeedButton
        Left = 32
        Top = 184
        Width = 25
        Height = 25
        OnClick = btn_song3Click
      end
      object lb_song3: TLabel
        Left = 96
        Top = 184
        Width = 41
        Height = 16
        Caption = 'Label2'
      end
      object btn_song4: TSpeedButton
        Left = 32
        Top = 232
        Width = 25
        Height = 25
        OnClick = btn_song4Click
      end
      object lb_song4: TLabel
        Left = 96
        Top = 232
        Width = 41
        Height = 16
        Caption = 'Label2'
      end
      object btn_song0: TSpeedButton
        Left = 32
        Top = 40
        Width = 25
        Height = 25
        Caption = 's'
        OnClick = btn_song0Click
      end
      object lb_song5: TLabel
        Left = 96
        Top = 288
        Width = 41
        Height = 16
        Caption = 'Label2'
      end
      object btn_nextSongListPage: TSpeedButton
        Left = 440
        Top = 344
        Width = 25
        Height = 25
        OnClick = btn_nextSongListPageClick
      end
      object btn_preSongListPage: TSpeedButton
        Left = 392
        Top = 344
        Width = 25
        Height = 25
        OnClick = btn_preSongListPageClick
      end
      object btn_selctAll: TSpeedButton
        Left = 32
        Top = 336
        Width = 41
        Height = 33
        OnClick = btn_selctAllClick
      end
    end
    object txt_songListSearch: TEdit
      Left = 464
      Top = 112
      Width = 113
      Height = 25
      TabOrder = 1
      Text = 'txt_songListSearch'
    end
  end
  object diaLoadMs: TOpenDialog
    Options = [ofHideReadOnly, ofAllowMultiSelect, ofEnableSizing]
    Left = 168
    Top = 80
  end
  object lrcTimer: TTimer
    Enabled = False
    Interval = 50
    OnTimer = lrcTimerTimer
    Left = 56
    Top = 664
  end
  object globle_timer: TTimer
    Interval = 50
    OnTimer = globle_timerTimer
    Left = 328
    Top = 72
  end
end
