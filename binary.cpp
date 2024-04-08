#include <iostream>
using namespace std;
int main()
{
int array[10],i,search;
// Input array elements
cout<<"enter array elements"<<endl;
for(i=0;i<10;i++)
{
cin>>array[i];
}
cout<<"enter element you want to search"<<endl;
cin>>search;
//Binary search algorithm
int l=0; // Lower bound of the search range
int up=9; // upper bound of the search range
int mid=(l+up)/2; // midpoint bound of the search range
while(l<=up)
{
if(search>array[mid])
{
l=mid+1; // Update lower bound if search element is greater than middle element
}
else if(search==array[mid])
{
cout<<"element found"<<endl; //Element found
break;
}
else
{
up=mid-1; // Update upper bound if search element is less than middle element
}
mid=(l+up)/2;
}
if(l>up)
{
cout<<"not found"<<endl; //Element not found
}
return 0;
}

/*
Output:
svkm@svkm-VirtualBox:~$ cd Documents 
svkm@svkm-VirtualBox:~/Documents$ cd SY_IT_54
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$ g++ binary.cpp 
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$ ./a.out
enter array elements
13
14
16
17
18
20
25
28
34
36
enter element you want to search
38
not found
svkm@svkm-VirtualBox:-/Documents/SY_IT_54$ ./a.out
enter array elements
12
13
14
15
16
27
30
31
34
46
enter element you want to search
15 element found
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$*/
