#include <iostream>
using namespace std;

int main()
{
    cout << "Selection Sort " << endl;
    int n;
    cout << "Enter the size : ";
    cin>>n;

    int arr[n];
    cout << "Enter the array : ";

    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[i]){
                int temp = arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    cout << "Selection Sorted Array : ";
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
