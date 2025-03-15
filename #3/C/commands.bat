g++ gen.cpp -o gen.exe
for /L %%i in (1,1,20) do call :generate %%i
del gen.exe
goto :EOF

:generate
    gen.exe %1.in %1.out
    timeout /T 1 /nobreak > nul
exit /b
