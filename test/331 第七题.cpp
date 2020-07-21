#include <iostream>
using namespace std;
 
 
void swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
 
void FullSort(int arr[], int start, int end)
{
    if(start == end)
    {
	for(int i = 0; i <= end; i++)
	{
	    cout << arr[i] << " ";
	}
	cout << endl;
	return;
    }
    
    else
    {
	for(int i = start; i <= end; i++)
	{
	    cout << "i = " << i << endl;
	    swap(arr, i, start);
	    cout << "arr[start] = " << arr[start] << endl;
	    FullSort(arr, start+1, end);
	    swap(arr, i, start);
	}
    }
}
 
int main()
{
    int arr[] = {1,2,3,4};
    FullSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
}
