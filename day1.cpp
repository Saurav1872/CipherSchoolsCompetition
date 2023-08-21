#include <iostream>
using namespace std;


int maxWater(int heights[], int size) {
    int start = 0;
    int end =  size-1;
    int maxWater = 0;

    while(start < end) {
        int mh = (heights[start] <= heights[end]) ? heights[start]:heights[end];
        maxWater = (maxWater >= (mh * (end-start))) ? maxWater : (mh * (end-start));
        if(heights[start] < heights[end]) {
            start++;
        }
        else {
            end--;
        }
    }

    return maxWater;
}
int main() {
    // test case 1
    int heights1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test Case 1" << endl << "Input:" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << heights1[i] << " ";
    }
    cout << endl << "Output:" << endl;
    
    cout << maxWater(heights1, 9) << endl << endl;

    // test case 2
    int heights2[] = {1, 1};

    cout << "Test Case 2" << endl << "Input:" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << heights2[i] << " ";
    }
    cout << endl << "Output:" << endl;
    cout << maxWater(heights2, 2) << endl;
}