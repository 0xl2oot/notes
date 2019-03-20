# VBS批处理PPT转为打印格式







```vb

Sub toGray()
Dim oShape As Shape
Dim oSlide As Slide
Dim oTxtRange As TextRange
Dim oShapeRange As ShapeRange
On Error Resume Next
 For Each oSlide In ActivePresentation.Slides
    oSlice.Background.Fill.ForeColor _
         .RGB = RGB(255, 255, 255)
    oSlice.Background.Fill.BackColor _
         .RGB = RGB(255, 255, 255)
   For Each oShape In oSlide.Shapes
      oShape.Fill.ForeColor _
        .RGB = RGB(255, 255, 255)
      oShape.Fill.BackColor _
        .RGB = RGB(255, 255, 255)
      Set oTxtRange = oShape.TextFrame.TextRange
      If Not IsNull(oTxtRange) Then
      With oTxtRange.Font
        '.Name = "宋体"                             '更改为需要的字体
        '.Size = 15                                         '改为所需的文字大小
        .Bold = msoFalse
        .Shadow.Visible = msoFalse
        .Color.RGB = RGB(Red:=0, Green:=0, Blue:=0)   '改成想要的文字颜色，用RGB参数表示
      End With
      End If
    Next
 Next
End Sub


```



```vb
'终极版
Sub ReColor()
    Dim sld As Slide
    Dim sh As Shape
    For Each sld In ActivePresentation.Slides
        For Each sh In sld.Shapes
            Call ReColorSH(sh)
        Next
    Next

    ActivePresentation.ExtraColors.Add RGB(Red:=255, Green:=255, Blue:=255)
    If ActivePresentation.HasTitleMaster Then
        With ActivePresentation.TitleMaster.Background
            .Fill.Visible = msoTrue
            .Fill.ForeColor.RGB = RGB(255, 255, 255)
            .Fill.Transparency = 0#
            .Fill.Solid
        End With
    End If
    With ActivePresentation.SlideMaster.Background
        .Fill.Visible = msoTrue
        .Fill.ForeColor.RGB = RGB(255, 255, 255)
        .Fill.Transparency = 0#
        .Fill.Solid
    End With
    With ActivePresentation.Slides.Range
        .FollowMasterBackground = msoTrue
        .DisplayMasterShapes = msoFalse
    End With

End Sub
  
Function ReColorSH(sh As Shape)
    Dim ssh As Shape
    If sh.Type = msoGroup Then ' when the shape itself is a group
        For Each ssh In sh.GroupItems
        Call ReColorSH(ssh)  ' the recursion
        Next
        '改变公式中文字的颜色为黑色，不知如何设置为其他颜色
        ElseIf sh.Type = msoEmbeddedOLEObject Then ' recolor the equation
   If Left(sh.OLEFormat.ProgID, 8) = "Equation" Then
                sh.PictureFormat.ColorType = msoPictureBlackAndWhite
                sh.PictureFormat.Brightness = 0
                sh.PictureFormat.Contrast = 1
                'sh.Fill.Visible = msoFalse
   End If
        '改变文本框中文字的颜色，可自己设定
        ElseIf sh.HasTextFrame Then
            ' /* 当前幻灯片中的当前形状包含文本. */
            If sh.TextFrame.HasText Then
                ' 引用文本框架中的文本.
                Set trng = sh.TextFrame.TextRange
                ' /* 遍历文本框架中的每一个字符. */
                For i = 1 To trng.Characters.Count
                    ' 这里请自行修改为原来的颜色值 (白色).
                    'If trng.Characters(i).Font.Color = vbWhite Then
                        ' 这里请自行修改为要替换的颜色值 (黑色).
                        trng.Characters(i).Font.Color = vbBlack
                    'End If
                Next
            End If
    End If
End Function

```

