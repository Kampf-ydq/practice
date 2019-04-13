#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,8,6,3,9,10};
    int i,j,k,temp;
    for(i = 1 ; i < 6; i++){

        temp = arr[i];//´ý²åÈëÊý´æÈëtemp

        for(j = i - 1; j >= 0 && arr[j] < temp; j--){
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = temp;
    }

    cout<<"Insertion Sort½µÐò£º"<<endl;
    for(i = 0 ; i < 6; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
