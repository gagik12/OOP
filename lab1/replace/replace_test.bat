set PROGRAM="%~1"

rem Replacement of empty data.
%PROGRAM% input.txt %TEMP%\output1.txt "" ""
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output1.txt checkOutput\out1.txt
if ERRORLEVEL 1 goto testFailed

rem Replacement of empty data.
%PROGRAM% input.txt %TEMP%\output2.txt  ma mama
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output2.txt checkOutput\out2.txt
if ERRORLEVEL 1 goto testFailed

rem Replacement of empty data.
%PROGRAM% input.txt %TEMP%\output3.txt  1231234 replaced
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output3.txt checkOutput\out3.txt
if ERRORLEVEL 1 goto testFailed

rem Replacement of empty data.
%PROGRAM% input.txt %TEMP%\output4.txt  "," "|"
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output4.txt checkOutput\out4.txt
if ERRORLEVEL 1 goto testFailed

rem Replacement of empty data.
%PROGRAM% input.txt %TEMP%\output5.txt  s SSSS
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output5.txt checkOutput\out5.txt
if ERRORLEVEL 1 goto testFailed


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1