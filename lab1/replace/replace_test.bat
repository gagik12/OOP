set PROGRAM="..\Debug\replace.exe"

rem Replacement of empty data.
%PROGRAM% input.txt output1.txt "" ""
if !ERRORLEVEL 1 goto err

rem Search string empty.
%PROGRAM% input.txt output2.txt "$fbbn682545964312312312345" ""
if ERRORLEVEL 1 goto err

rem Replace the empty string.
%PROGRAM% input.txt output3.txt "" "empty replace"
if ERRORLEVEL 1 goto err

rem Replacing ma at mama.
%PROGRAM% input.txt output4.txt "ma" "mama"
if ERRORLEVEL 1 goto err

rem Replacing 1231234 at replaced.
%PROGRAM% input.txt output5.txt "1231234" "replaced"
if ERRORLEVEL 1 goto err

rem Replacing *&$$ at sign.
%PROGRAM% input.txt output6.txt "*&$$" "sign"
if ERRORLEVEL 1 goto err

rem Replacing fbbn at sign.
%PROGRAM% input.txt output6.txt "fbbns" "word"
if ERRORLEVEL 1 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1