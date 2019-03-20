VERSION 5.00
Begin VB.Form Form1 
   Appearance      =   0  'Flat
   BackColor       =   &H00FFFFFF&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "计算器"
   ClientHeight    =   6060
   ClientLeft      =   45
   ClientTop       =   390
   ClientWidth     =   3915
   BeginProperty Font 
      Name            =   "宋体"
      Size            =   14.25
      Charset         =   134
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   6500
   ScaleMode       =   0  'User
   ScaleWidth      =   4000
   StartUpPosition =   3  '窗口缺省
   Begin VB.Label Label3 
      Alignment       =   1  'Right Justify
      BackColor       =   &H00FFFFFF&
      Caption         =   "0"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   26.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   746
      Left            =   0
      TabIndex        =   2
      Top             =   653
      Width           =   3915
   End
   Begin VB.Label Label2 
      Alignment       =   1  'Right Justify
      BackColor       =   &H00FFFFFF&
      Height          =   466
      Left            =   0
      TabIndex        =   1
      Top             =   93
      Width           =   3915
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BackColor       =   &H00FFFFFF&
      Caption         =   "     AC"
      DataField       =   "1"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000008&
      Height          =   780
      Index           =   0
      Left            =   0
      TabIndex        =   0
      Top             =   1200
      Width           =   975
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Public op As Integer
Public a As Integer
Public b As Integer
Private Sub Form_Load()

    Label1(0).Top = 1500
    Label1(0).Height = 1000
    Label1(0).Width = 1000
    Label1(0).BackColor = RGB(255, 255, 255)
    Dim i As Integer
    For i = 1 To 18
        Load Label1(i)
        Label1(i).Left = 1000 * (i Mod 4)
        Label1(i).Top = 1000 * Int(i / 4) + 1500
        Label1(i).Visible = True
        Select Case i
            Case 1
                Label1(i).Caption = vbCrLf & "Back" & vbCrLf
            Case 2
                Label1(i).Caption = vbCrLf & "÷" & vbCrLf
            Case 3
                Label1(i).Caption = vbCrLf & "×" & vbCrLf
            Case 4, 5, 6
                Label1(i).Caption = vbCrLf & i + 3 & vbCrLf
                Label1(i).DataField = i + 3
            Case 7
                Label1(i).Caption = vbCrLf & "-" & vbCrLf
            Case 8, 9, 10
                Label1(i).Caption = vbCrLf & i - 4 & vbCrLf
                Label1(i).DataField = i - 4
            Case 11
                Label1(i).Caption = vbCrLf & "+" & vbCrLf
            Case 12, 13, 14
                Label1(i).Caption = vbCrLf & i - 11 & vbCrLf
                Label1(i).DataField = i - 11
            Case 15
                Label1(i).Caption = vbCrLf & vbCrLf & vbCrLf & "=" & vbCrLf
            Case 16
                Label1(i).Caption = vbCrLf & "%" & vbCrLf
            Case 17
                Label1(i).Caption = vbCrLf & "0" & vbCrLf
                Label1(i).DataField = 0
            Case 18
                Label1(i).Caption = vbCrLf & "." & vbCrLf
        End Select
    Next
    Label1(15).Height = 2000
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Dim i As Integer
    For i = 0 To 18
        Label1(i).BackColor = RGB(255, 255, 255)
    Next
End Sub


Private Sub Label1_Click(Index As Integer)
    Select Case Index
        Case 0
            Label2.Caption = ""
            Label3.Caption = "0"
        Case 1
            Label3.Caption = Left(Label3.Caption, Len(Label3.Caption) - 1)
            If Label3.Caption = "" Then
                Label3.Caption = "0"
            End If
        Case 4, 5, 6, 8, 9, 10, 12, 13, 14, 16
            If Label3.Caption <> "0" Then
                Label3.Caption = Label3.Caption & Label1(Index).DataField
            Else
                Label3.Caption = Label1(Index).DataField
            End If
        Case 2
            op = 4
            a = Label3.Caption
            Label2.Caption = Label3.Caption
            Label3.Caption = "÷"
        Case 3
            op = 3
            a = Label3.Caption
            Label2.Caption = Label3.Caption
            Label3.Caption = "×"
        Case 7
            op = 2
            a = Label3.Caption
            Label2.Caption = Label3.Caption
            Label3.Caption = "-"
        Case 11
            op = 1
            a = Label3.Caption
            Label2.Caption = Label3.Caption
            Label3.Caption = "+"
        Case 15
            If op = 1 Then
                b = Right(Label3.Caption, Len(Label3.Caption) - 1)
                Label2.Caption = Label2.Caption & Label3.Caption
                Label3.Caption = "=" & (a + b)
            ElseIf op = 2 Then
                b = Right(Label3.Caption, Len(Label3.Caption) - 1)
                Label2.Caption = Label2.Caption & Label3.Caption
                Label3.Caption = "=" & a - b
            ElseIf op = 3 Then
                b = Right(Label3.Caption, Len(Label3.Caption) - 1)
                Label2.Caption = Label2.Caption & Label3.Caption
                Label3.Caption = "=" & a * b
            ElseIf op = 4 Then
                b = Right(Label3.Caption, Len(Label3.Caption) - 1)
                Label2.Caption = Label2.Caption & Label3.Caption
                Label3.Caption = "=" & a / b
            Else
                Label2.Caption = Label3.Caption
                Label3.Caption = "=" & Label3.Caption
            End If
    End Select
End Sub

Private Sub Label1_MouseDown(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    Label1(Index).BackColor = RGB(225, 225, 225)
End Sub

Private Sub Label1_MouseMove(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    For i = 0 To 18
        Label1(i).BackColor = RGB(255, 255, 255)
    Next
    Label1(Index).BackColor = RGB(245, 245, 245)
End Sub
Private Sub Label1_MouseUp(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
    Label1(Index).BackColor = RGB(255, 255, 255)
End Sub
