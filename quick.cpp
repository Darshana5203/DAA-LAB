#include<iostream>
using namespace std;
//function prototypes
void quick(int a[], int l, int up);
int partition(int a[], int l, int up);
int main()
{
int n;
//Input size of the array
cout<<"enter the size of an array"<<endl;
cin>>n;
int arr[n];
//Input array elements
cout<<"enter array elements"<<endl;
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
int low = 0;
int up = n-1;
//Callquicksort function
quick(arr, low, up);
//Output sorted elements
cout << "sorted elements are" << endl;
for (int i = 0; i <= up; i++) {
cout << arr[i] << " ";
}
cout << endl;
return 0;
}
//Quicksort function
void quick(int a[], int l, int up) {
if (l >= up) {
return;
}
int pvtloc = partition(a, l, up);
quick(a, l, pvtloc - 1); //left sublist
quick(a, pvtloc + 1, up); //right sublist
}
//partition function to rearrange elements around a pivot
int partition(int a[], int l, int up) {
//Best case if the lower index is greater then or equal to the upper index return lower index
if (l >= up) {
return l;
}
//Initialization
int temp, pvt;
int i = l + 1;
int j = up;
pvt = a[l]; //Choose the first element as pivot
//Partitioning process
while (i <= j) {
while (a[i] < pvt) {
i++;
}
while (a[j] > pvt) {
j--;
}
if (i < j) {
    //Swap elements if they are out of place
temp = a[i];
a[i] = a[j];
a[j] = temp;
i++;
j--;
} else {
i++;
}
}
// Swap pivot with element at position j
temp = a[l];
a[l] = a[j];
a[j] = temp;
return j; // return the pivot's final position
}
/*
Output:
svkm@svkm-VirtualBox:~$ cd Documents
svkm@svkm-VirtualBox:~/Documents$ cd SY_IT_54
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$ g++ quick.cpp 
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$ ./a.out
enter the size of an array
7
enter array elements
7
9
5
4
6
2
3
sorted elements are
2 3 4 5 6 7 9
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$
*/