#include<iostream>
using namespace std;
void merge(int arr[],int s,int e)
{
    int mid=(s+e)/2;

    int lenLeft=mid-s+1;
    int lenRight=e-mid;


    //create the left and right array

    int *left=new int[lenLeft];
    int *right=new int[lenRight];
    
    int k=s;
   //copy the value to left array
   for(int i=0;i<lenLeft;i++)
   {
    left[i]=arr[k];
    k++;
   } 
   //copy the to right array
    k=mid+1;
   for(int i=0;i<lenRight;i++)
     {
        right[i]=arr[k];
        k++;
     }

     int leftIndex=0;
     int rightIndex=0;
     int mainArrayIndex = s;

     while(leftIndex<lenLeft&&rightIndex<lenRight)
     {
        if(left[leftIndex]<right[rightIndex])
        {
            arr[mainArrayIndex]=left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrayIndex]=right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
     }

     //1case left array ended
    while(leftIndex<lenLeft)
    {
        arr[mainArrayIndex]=left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
    }

    //2 case right ended
     while(rightIndex<lenRight)
    {
        arr[mainArrayIndex]=right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
    }
    
    delete[] left;
    delete[] right;
}
void mergeSort(int arr[],int s,int e)
{ 
    if(s>=e)
    {
        return;
    }

    int mid=(s+e)/2;

    //left side array
mergeSort(arr,s,mid);
    //right side array
mergeSort(arr,mid+1,e);

    //merge them along with sorting
    merge(arr,s,e);
    
}
int main()
{
    int arr[]={9,4,2,6,1,7,5,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    int s=0;
    int e=size-1;
    cout << "Before merge sort: " << endl;
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	mergeSort(arr,s,e);

	cout << "After merge sort: " << endl;
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;


  return 0;
}