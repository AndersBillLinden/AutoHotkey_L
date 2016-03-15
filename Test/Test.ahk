#SingleInstance force

+^1:: ; Hotkey is Shift + Control + 1
WinSet, Transparent, 150, A ; the active window
return

+^2:: ; Hotkey is Shift + Control + 2
WinSet, Transparent, OFF, A ; the active window
return

+^5:: ; Hotkey is Shift + Control + 5
RegKeyAddAccessRule, HKEY_CURRENT_USER\Test, THQUIRREL\anders, R
MsgBox Was setting registry permission to read
return

+^6:: ; Hotkey is Shift + Control + 6
WinGetTitle, OldTitle, A
InputBox, NewTitle, Input window title, %OldTitle%
if !ErrorLevel
	WinSetTitle, %NewTitle%
return

+^7:: ; Hotkey is Shift + Control + 7
MsgBox Icon positions will not be editable
return

+^8:: ; Hotkey is Shift + Control + 8
MsgBox Icon positions will be editable
return

+^9:: ; Hotkey is Shift + Control + 9 - Kill window
WinKill, A ; the active window
return