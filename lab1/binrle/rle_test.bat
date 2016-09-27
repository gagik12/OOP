set PROGRAM="%~1"

%PROGRAM% pack input\in1.txt output\out1PACK.txt
if ERRORLEVEL 1 goto err

%PROGRAM% unpack output\out1PACK.txt output\out1UNPACK.txt
fc input\in1.txt output\out1UNPACK.txt
if ERRORLEVEL 1 goto err



rem 255 identical characters
%PROGRAM% pack input\in2.txt output\out2PACK.txt
if ERRORLEVEL 1 goto err

%PROGRAM% unpack output\out2PACK.txt output\out2UNPACK.txt
fc input\in2.txt output\out2UNPACK.txt
if ERRORLEVEL 1 goto err



rem empty file
%PROGRAM% pack input\in3.txt output\out3PACK.txt
if ERRORLEVEL 1 goto err

%PROGRAM% unpack output\out3PACK.txt output\out3UNPACK.txt
fc input\in3.txt output\out3UNPACK.txt
if ERRORLEVEL 1 goto err



rem 256 identical characters
%PROGRAM% pack input\in4.txt output\out4PACK.txt
if ERRORLEVEL 1 goto err

%PROGRAM% unpack output\out4PACK.txt output\out4UNPACK.txt
fc input\in4.txt output\out4UNPACK.txt
if ERRORLEVEL 1 goto err



echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1