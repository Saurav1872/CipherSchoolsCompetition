#include <iostream>
using namespace std;

bool checkTriplet(int arr[], int size) {
    for (int i = 0; i < size - 2; ++i) {
        int l = i + 1;
        int r = size - 1;

        while (l < r) {
            if ((arr[l] + arr[r]) == -arr[i]) {
                return 1;
            } 
            else if ((arr[l] + arr[r]) < -arr[i]) {
                l++;
            } 
            else {
                r--;
            }
        }
    }
    return 0;
}

int main() {
    
    int arr1[] = {-1, 0, 1, 2, -3};
    cout << "Test Case 1" << endl << "Input:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl << "Output:" << endl;
    cout << checkTriplet(arr1, 5) << endl;

    cout << endl << endl;

    int arr2[] = {1, 2, 3};
    cout << "Test Case 2" << endl << "Input:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl << "Output:" << endl;
    cout << checkTriplet(arr2, 3) << endl;

    return 0;
}
