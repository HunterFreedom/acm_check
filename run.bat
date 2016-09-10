 g++ a.cpp -o a -std=c++11
 g++ b.cpp -o b -std=c++11
 g++ rand.cpp -o rand -std=c++11
 :loop
 rand.exe > in.txt          
 a.exe < in.txt  > oa.txt  
 b.exe < in.txt > ob.txt
 fc /A oa.txt  ob.txt
 if not errorlevel 1 goto loop
 pause
 :end    