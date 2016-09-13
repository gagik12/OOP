set PROGRAM="..\Debug\replace.exe"

rem Replacement of empty data.
%PROGRAM% input.txt output/output1.txt "" ""
if ERRORLEVEL 1 goto err
fc.exe output\output1.txt checkOutput\out1.txt
if ERRORLEVEL 1 goto testFailed

rem Search string empty.
%PROGRAM% input.txt output\output2.txt "" "$fbbn682545964312312312345"
if ERRORLEVEL 1 goto err
fc.exe output\output2.txt checkOutput\out2.txt
if ERRORLEVEL 1 goto testFailed

rem Replace the empty string.
%PROGRAM% input.txt output\output3.txt  "empty_replace" ""
if ERRORLEVEL 1 goto err
fc.exe output\output3.txt checkOutput\out3.txt
if ERRORLEVEL 1 goto testFailed

rem Replacing ma at mama.
%PROGRAM% input.txt output\output4.txt "ma" "mama"
if ERRORLEVEL 1 goto err
fc.exe output\output4.txt checkOutput\out4.txt
if ERRORLEVEL 1 goto testFailed

rem Replacing 1231234 at replaced.
%PROGRAM% input.txt output\output5.txt "1231234" "replaced"
if ERRORLEVEL 1 goto err
fc.exe output\output5.txt checkOutput\out5.txt
if ERRORLEVEL 1 goto testFailed

rem Replacing *&$$ at sign.
%PROGRAM% input.txt output\output6.txt "*&$$" "sign"
if ERRORLEVEL 1 goto err
fc.exe output\output6.txt checkOutput\out6.txt
if ERRORLEVEL 1 goto testFailed

rem Replacing fbbn at sign.
%PROGRAM% input.txt output\output7.txt "fbbns" "word"
if ERRORLEVEL 1 goto err
fc.exe output\output7.txt checkOutput\out7.txt
if ERRORLEVEL 1 goto testFailed


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1