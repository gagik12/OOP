set PROGRAM="%~1"


%PROGRAM% 16 10 ff > output\out1.txt
fc output\out1.txt reference\ref1.txt
if ERRORLEVEL 1 goto err

rem data incorrectly the value of "f" = 15 and radix = 12
%PROGRAM% 12 10 ff > output\out2.txt
fc output\out2.txt reference\ref2.txt
if ERRORLEVEL 1 goto err

rem int_max = 2147483647
%PROGRAM% 10 16 2147483647 > output\out3.txt
fc output\out3.txt reference\ref3.txt
if ERRORLEVEL 1 goto err

rem overflow int > int_max 
%PROGRAM% 10 16 214748364553 > output\out4.txt
fc output\out4.txt reference\ref4.txt
if ERRORLEVEL 1 goto err

rem underflow int = int_MIN
%PROGRAM% 10 16 -2147483648 > output\out5.txt
fc output\out5.txt reference\ref5.txt
if ERRORLEVEL 1 goto err

rem underflow int < int_MIN
%PROGRAM% 10 16 -2147483648462 > output\out6.txt
fc output\out6.txt reference\ref6.txt
if ERRORLEVEL 1 goto err

rem input 0
%PROGRAM% 10 16 0 > output\out7.txt
fc output\out7.txt reference\ref7.txt
if ERRORLEVEL 1 goto err

rem input ABCZDH in 36 radix
%PROGRAM% 36 10 ABCZDH > output\out8.txt
fc output\out8.txt reference\ref8.txt
if ERRORLEVEL 1 goto err

rem empty data value
%PROGRAM% 36 2  > output\out9.txt
fc output\out9.txt reference\ref9.txt
if ERRORLEVEL 1 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1
