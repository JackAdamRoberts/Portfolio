Class MainWindow
    Private Sub SpinButton_Click(sender As Object, e As RoutedEventArgs) Handles SpinButton.Click
        Dim generator As New Random
        CoinImage.Visibility = Visibility.Collapsed

        FirstNum.Text = generator.Next(0, 9)
        SecondNum.Text = generator.Next(0, 9)
        ThirdNum.Text = generator.Next(0, 9)

        If (FirstNum.Text = "7") And (SecondNum.Text = "7") And (ThirdNum.Text = "7") Then
            CoinImage.Visibility = Visibility.Visible
            My.Computer.Audio.Play("C:\Users\jrobe\Desktop\ArcadeRiff.wav")
        End If
    End Sub
End Class
