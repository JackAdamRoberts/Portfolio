Class MainWindow
    Private Sub TestButton_Click(sender As Object, e As RoutedEventArgs) Handles TestButton.Click
        Dim sampleText As String
        sampleText = InputString.Text
        If sampleText.Contains("River") Then
            Output.Text = "The string 'River' was found."
        Else
            Output.Text = "The string 'River' was not found."
        End If
    End Sub

    Private Sub InputString_TextChanged(sender As Object, e As TextChangedEventArgs) Handles InputString.TextChanged

    End Sub
End Class
