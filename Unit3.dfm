object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Cracker reader'
  ClientHeight = 522
  ClientWidth = 757
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 757
    Height = 421
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 0
    ExplicitHeight = 408
    object TabSheet1: TTabSheet
      Caption = 'Chart'
      ExplicitHeight = 373
      object Chart1: TChart
        Left = 0
        Top = 0
        Width = 749
        Height = 320
        Legend.CheckBoxes = True
        Title.Text.Strings = (
          'TChart')
        View3D = False
        Align = alClient
        TabOrder = 0
        ExplicitHeight = 323
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series1: TLineSeries
          Legend.Text = 'Sgnal'
          LegendTitle = 'Sgnal'
          Brush.BackColor = clDefault
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series2: TLineSeries
          Legend.Text = 'Sync'
          LegendTitle = 'Sync'
          Brush.BackColor = clDefault
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series3: TLineSeries
          Legend.Text = 'From file'
          LegendTitle = 'From file'
          Brush.BackColor = clDefault
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
      object Panel3: TPanel
        Left = 0
        Top = 320
        Width = 749
        Height = 73
        Align = alBottom
        TabOrder = 1
        object Label3: TLabel
          Left = 4
          Top = 6
          Width = 65
          Height = 13
          Caption = 'Tic per period'
        end
        object Label4: TLabel
          Left = 85
          Top = 6
          Width = 59
          Height = 13
          Caption = 'Tic start pos'
        end
        object Label9: TLabel
          Left = 590
          Top = 6
          Width = 68
          Height = 13
          Caption = 'Shift in signals'
        end
        object Label10: TLabel
          Left = 664
          Top = 6
          Width = 69
          Height = 13
          Caption = 'Data start pos'
        end
        object Label11: TLabel
          Left = 376
          Top = 37
          Width = 31
          Height = 13
          Caption = 'Total: '
        end
        object Label12: TLabel
          Left = 376
          Top = 56
          Width = 41
          Height = 13
          Caption = 'Current:'
        end
        object Edit1: TEdit
          Left = 4
          Top = 27
          Width = 75
          Height = 21
          TabOrder = 0
          Text = '125'
          OnChange = Edit1Change
        end
        object Edit2: TEdit
          Left = 85
          Top = 27
          Width = 68
          Height = 21
          TabOrder = 1
          Text = '1000'
          OnChange = Edit2Change
        end
        object Button8: TButton
          Left = 376
          Top = 6
          Width = 114
          Height = 25
          Caption = 'From File'
          TabOrder = 2
          OnClick = Button8Click
        end
        object Button9: TButton
          Left = 496
          Top = 6
          Width = 40
          Height = 25
          Caption = '<<<'
          Enabled = False
          TabOrder = 3
          OnClick = Button9Click
        end
        object Button10: TButton
          Left = 542
          Top = 6
          Width = 42
          Height = 25
          Caption = '>>>'
          Enabled = False
          TabOrder = 4
          OnClick = Button10Click
        end
        object Edit6: TEdit
          Left = 590
          Top = 27
          Width = 68
          Height = 21
          TabOrder = 5
          Text = '100'
        end
        object Edit7: TEdit
          Left = 664
          Top = 27
          Width = 73
          Height = 21
          TabOrder = 6
          Text = '0'
        end
        object Button12: TButton
          Left = 496
          Top = 37
          Width = 88
          Height = 21
          Caption = 'Refresh'
          TabOrder = 7
          OnClick = Button12Click
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Settings'
      ImageIndex = 1
      ExplicitLeft = 3
      ExplicitTop = 22
      ExplicitHeight = 380
      object Label2: TLabel
        Left = 0
        Top = 6
        Width = 44
        Height = 13
        Caption = 'Com Port'
      end
      object Label5: TLabel
        Left = 3
        Top = 88
        Width = 121
        Height = 13
        Caption = 'Write buffer size in packs'
      end
      object Label7: TLabel
        Left = 3
        Top = 115
        Width = 80
        Height = 13
        Caption = 'Output file name'
      end
      object Label8: TLabel
        Left = 3
        Top = 64
        Width = 133
        Height = 13
        Caption = 'Internal buffer size in packs'
      end
      object Button6: TButton
        Left = 194
        Top = 3
        Width = 75
        Height = 25
        Caption = 'Reopen'
        TabOrder = 0
        OnClick = Button6Click
      end
      object Button7: TButton
        Left = 275
        Top = 3
        Width = 75
        Height = 25
        Caption = 'Refresh'
        TabOrder = 1
        OnClick = Button7Click
      end
      object ComboBox1: TComboBox
        Left = 52
        Top = 3
        Width = 136
        Height = 21
        TabOrder = 2
        Text = 'COM7'
      end
      object Edit3: TEdit
        Left = 148
        Top = 85
        Width = 121
        Height = 21
        TabOrder = 3
        Text = '1000'
      end
      object Edit4: TEdit
        Left = 148
        Top = 112
        Width = 121
        Height = 21
        TabOrder = 4
        Text = 'dump_file_'
      end
      object CheckBox2: TCheckBox
        Left = 275
        Top = 114
        Width = 97
        Height = 17
        Caption = 'Rewrite'
        Checked = True
        State = cbChecked
        TabOrder = 5
      end
      object Edit5: TEdit
        Left = 148
        Top = 58
        Width = 53
        Height = 21
        TabOrder = 6
        Text = '100'
      end
      object Button11: TButton
        Left = 207
        Top = 54
        Width = 62
        Height = 25
        Caption = 'Change'
        TabOrder = 7
        OnClick = Button11Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Raw Data'
      ImageIndex = 2
      ExplicitHeight = 373
      object Panel2: TPanel
        Left = 0
        Top = 361
        Width = 749
        Height = 32
        Align = alBottom
        TabOrder = 0
        ExplicitTop = 341
        object Button2: TButton
          Left = 1
          Top = 7
          Width = 128
          Height = 25
          Align = alCustom
          Caption = 'Clear'
          TabOrder = 0
          OnClick = Button2Click
        end
      end
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 749
        Height = 361
        Align = alClient
        Lines.Strings = (
          'Memo1')
        MaxLength = 32000
        ScrollBars = ssVertical
        TabOrder = 1
        ExplicitHeight = 341
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 421
    Width = 757
    Height = 60
    Align = alBottom
    TabOrder = 1
    ExplicitTop = 416
    object Label1: TLabel
      Left = 89
      Top = 40
      Width = 41
      Height = 13
      Caption = 'readed: '
    end
    object Label6: TLabel
      Left = 170
      Top = 40
      Width = 103
      Height = 13
      Caption = 'iterations:'
    end
    object Button1: TButton
      Left = 8
      Top = 9
      Width = 75
      Height = 25
      Caption = 'Read'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button3: TButton
      Left = 89
      Top = 9
      Width = 75
      Height = 25
      Caption = 'Start'
      TabOrder = 1
      OnClick = Button3Click
    end
    object Button5: TButton
      Left = 223
      Top = 8
      Width = 50
      Height = 25
      Caption = '>>>'
      TabOrder = 2
      OnClick = Button5Click
    end
    object CheckBox1: TCheckBox
      Left = 8
      Top = 40
      Width = 97
      Height = 17
      Caption = 'try dump ?'
      TabOrder = 3
    end
    object Button4: TButton
      Left = 170
      Top = 9
      Width = 47
      Height = 25
      Caption = '<<<'
      TabOrder = 4
      OnClick = Button4Click
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 481
    Width = 757
    Height = 41
    Align = alBottom
    TabOrder = 2
    ExplicitTop = 472
    object Panel5: TPanel
      Left = 1
      Top = 1
      Width = 185
      Height = 39
      Align = alLeft
      TabOrder = 0
      ExplicitLeft = 8
      ExplicitTop = -2
      ExplicitHeight = 41
      object Panel6: TPanel
        Left = 1
        Top = 1
        Width = 183
        Height = 37
        Align = alClient
        TabOrder = 0
        ExplicitLeft = 186
        ExplicitWidth = 570
        ExplicitHeight = 39
        object ProgressBar1: TProgressBar
          Left = 1
          Top = 1
          Width = 181
          Height = 35
          Align = alClient
          TabOrder = 0
        end
      end
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 10
    OnTimer = Button1Click
    Left = 712
    Top = 8
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 672
    Top = 8
  end
end
