#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,8,6,3,9,10};
    int i,j,k,temp;
    for(i = 0; i < 5; i++){
        k = i;
        for(j = i + 1; j < 6; j++){
            if(arr[j] > arr[k])
                k = j;
        }
        if(k != i){
            temp = arr[k];
            arr[k] = arr[i];
            arr[i] = temp;
        }
    }

    cout<<"Selection Sort½µÐò£º"<<endl;
    for(i = 0 ; i < 6; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
