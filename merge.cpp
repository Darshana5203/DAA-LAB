#include<iostream>
using namespace std;
#define max 100
//Function prototypes
void merge_sort(int arr[],int low,int up);
void merge_s(int arr[],int temp[],int low1,int up1,int low2,int up2);
void copy_s(int arr[],int temp[],int low,int up);
int main()
{
int i,n,arr[max];
cout<<"enter the size of array:"<<endl;
cin>>n;
cout<<"enter array elements "<<endl;
for(i=0;i<n;i++)
{
cin>>arr[i];
}
merge_sort(arr,0,n-1);
cout<<"sorted list is "<<endl;
for(i=0;i<n;i++)
cout<<arr[i]<<" ";
return 0;
}
//Merge sort function
void merge_sort(int arr[],int low,int up)
{
int mid;
int temp[max];
if(low<up)
{
mid=(low+up)/2;
merge_sort(arr,low,mid); //left sublist
merge_sort(arr,mid+1,up); //right sublist
merge_s(arr,temp,low,mid,mid+1,up);
copy_s(arr,temp,low,up);
}
}
//merge_s function to merge two sorted sublists
void merge_s(int arr[],int temp[],int low1,int up1,int low2,int up2)
{
int i=low1;
int j=low2;
int k=low1;
//merge element from both sublists into temp array
while((i<=up1)&&(j<=up2))
{
if(arr[i]<=arr[j])
temp[k++]=arr[i++];
else
temp[k++]=arr[j++];
}
//copy any remaining elements from first sublist
while(i<=up1)
temp[k++]=arr[i++];
//copy any remaining elements from second sublist
while(j<=up2)
temp[k++]=arr[j++];
}
//function to copy elements from temp array back to ariginal array
void copy_s(int arr[],int temp[],int low,int up)
{
int i;
for(i=low;i<=up;i++)
arr[i]=temp[i];
}
/*
output:
svkm@svkm-VirtualBox:~$ cd Documents
svkm@svkm-VirtualBox:~$ cd SY_IT_54 
svkm@svkm-VirtualBox:-/Documents/SY_IT_54$ g++ merge.cpp
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$./a.out
enter the size of array:
6
enter array elements
45
32
25
15
87
39
sorted list is
15 25 32 39 45 87 
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$
*/
