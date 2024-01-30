## To Find the Port name
1. Method 1 : Using powershell
```pwsh
[System.IO.Ports.SerialPort]::getportnames()
```
2. Using Windows Device Manager
- Press `Windows + X` and then `M`
- Find "Ports (COM & LPT) "
![](./Device%20Manager.png)