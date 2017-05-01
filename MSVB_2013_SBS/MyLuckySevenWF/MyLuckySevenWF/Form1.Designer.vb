<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.SpinButton = New System.Windows.Forms.Button()
        Me.EndButton = New System.Windows.Forms.Button()
        Me.FirstNum = New System.Windows.Forms.Label()
        Me.SecondNum = New System.Windows.Forms.Label()
        Me.ThirdNum = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.CoinImage = New System.Windows.Forms.PictureBox()
        CType(Me.CoinImage, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'SpinButton
        '
        Me.SpinButton.Location = New System.Drawing.Point(24, 42)
        Me.SpinButton.Name = "SpinButton"
        Me.SpinButton.Size = New System.Drawing.Size(88, 29)
        Me.SpinButton.TabIndex = 0
        Me.SpinButton.Text = "Spin"
        Me.SpinButton.UseVisualStyleBackColor = True
        '
        'EndButton
        '
        Me.EndButton.Location = New System.Drawing.Point(24, 87)
        Me.EndButton.Name = "EndButton"
        Me.EndButton.Size = New System.Drawing.Size(88, 29)
        Me.EndButton.TabIndex = 1
        Me.EndButton.Text = "End"
        Me.EndButton.UseVisualStyleBackColor = True
        '
        'FirstNum
        '
        Me.FirstNum.AutoSize = True
        Me.FirstNum.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.FirstNum.Font = New System.Drawing.Font("Segoe UI Semibold", 24.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.FirstNum.Location = New System.Drawing.Point(181, 18)
        Me.FirstNum.Name = "FirstNum"
        Me.FirstNum.Size = New System.Drawing.Size(47, 56)
        Me.FirstNum.TabIndex = 2
        Me.FirstNum.Text = "0"
        Me.FirstNum.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'SecondNum
        '
        Me.SecondNum.AutoSize = True
        Me.SecondNum.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.SecondNum.Font = New System.Drawing.Font("Segoe UI Semibold", 24.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.SecondNum.Location = New System.Drawing.Point(285, 18)
        Me.SecondNum.Name = "SecondNum"
        Me.SecondNum.Size = New System.Drawing.Size(47, 56)
        Me.SecondNum.TabIndex = 3
        Me.SecondNum.Text = "0"
        Me.SecondNum.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'ThirdNum
        '
        Me.ThirdNum.AutoSize = True
        Me.ThirdNum.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.ThirdNum.Font = New System.Drawing.Font("Segoe UI Semibold", 24.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.ThirdNum.Location = New System.Drawing.Point(395, 18)
        Me.ThirdNum.Name = "ThirdNum"
        Me.ThirdNum.Size = New System.Drawing.Size(47, 56)
        Me.ThirdNum.TabIndex = 4
        Me.ThirdNum.Text = "0"
        Me.ThirdNum.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Font = New System.Drawing.Font("Segoe UI Semibold", 18.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label4.ForeColor = System.Drawing.Color.DarkRed
        Me.Label4.Location = New System.Drawing.Point(12, 133)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(185, 41)
        Me.Label4.TabIndex = 5
        Me.Label4.Text = "Lucky Seven"
        '
        'CoinImage
        '
        Me.CoinImage.AccessibleName = "CoinImage"
        Me.CoinImage.Image = Global.MyLuckySevenWF.My.Resources.Resources.Coins
        Me.CoinImage.Location = New System.Drawing.Point(213, 99)
        Me.CoinImage.Name = "CoinImage"
        Me.CoinImage.Size = New System.Drawing.Size(414, 201)
        Me.CoinImage.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.CoinImage.TabIndex = 6
        Me.CoinImage.TabStop = False
        Me.CoinImage.Visible = False
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(639, 312)
        Me.Controls.Add(Me.CoinImage)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.ThirdNum)
        Me.Controls.Add(Me.SecondNum)
        Me.Controls.Add(Me.FirstNum)
        Me.Controls.Add(Me.EndButton)
        Me.Controls.Add(Me.SpinButton)
        Me.Name = "Form1"
        Me.Text = "Form1"
        CType(Me.CoinImage, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents SpinButton As Button
    Friend WithEvents EndButton As Button
    Friend WithEvents FirstNum As Label
    Friend WithEvents SecondNum As Label
    Friend WithEvents ThirdNum As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents CoinImage As PictureBox
End Class
