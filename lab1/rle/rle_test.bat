set PROGRAM="%~1"

rem pack
%PROGRAM% pack input\in1.txt  output\out1.txt
fc output\out1.txt reference\ref1.txt
if ERRORLEVEL 1 goto err

rem pack
%PROGRAM% pack input\in2.txt  output\out2.txt
fc output\out2.txt reference\ref2.txt
if ERRORLEVEL 1 goto err

rem pack
%PROGRAM% pack input\in3.txt  output\out3.txt
fc output\out3.txt reference\ref3.txt
if ERRORLEVEL 1 goto err

rem unpack
%PROGRAM% unpack input\in4.txt  output\out4.txt
fc output\out4.txt reference\ref4.txt
if ERRORLEVEL 1 goto err

rem unpack
%PROGRAM% unpack input\in5.txt  output\out5.txt
fc output\out5.txt reference\ref5.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1