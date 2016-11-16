set PROGRAM="%~1"


echo search the maximum area and minimum perimeter
%PROGRAM% input\in1.txt > output\out1.txt
if ERRORLEVEL 1 goto err
fc /b output\out1.txt reference\ref1.txt
IF ERRORLEVEL 1 GOTO err

echo Invalid number of parameters
%PROGRAM% input\in2.txt > output\out2.txt
if ERRORLEVEL 1 goto err
fc /b output\out2.txt reference\ref2.txt
IF ERRORLEVEL 1 GOTO err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1