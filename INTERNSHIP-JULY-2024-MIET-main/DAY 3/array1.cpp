#include <bits/stdc++.h>
using namespace std;

// Array

int main()
{
    // int a[5];
    // int b[5]={1,2,3,3,4};
    // int c[]={1,2,3,4,4,5,6,7};
    // int d[5]={1,2};
    // int e[5]={0};
    // for (int i =0 ; i<5 ; i++ ){
    //     cout<<b[i];
    // }

    int a[5] = {1, 3, 5, 7, 9};

    cout << "Completely Initialized Int Array A: " << endl;

    for (int x : a) // For each loop very easy and important for Array data structure. //Read as for x in array a.

        // For each loop iterates through elements of the array. Introduced in C++ 11.

        cout << x << endl;

    cout << endl;

    int b[6] = {1, 3, 5}; // Keeping the array incomplete to see what is the outcome result.

    cout << "Partial Initialized Int Array B: " << endl;

    for (int y : b) // Shows that for each loop will work according to size of array and not according //to number of elements initialized in the array.

        cout << y << endl;

    cout << endl;

    float c[6] = {1.2, 2.4, 3.6, 48.54, 99.48, 54.08};
    cout << "Completely Initialized Float Array C:";

    for (float z : c)

        cout << z << endl;

    cout << endl;


    float d[6] = {12.6, 82.4, 43.6, 4.54, 77.48, 84.08};
    cout << "Completely Initialized Float Array D with auto : "<<endl;

    for (auto z : d)   //no need to know the type of array

        cout << z << endl;

    cout << endl;

    char e[5] = {'A',66,'C',68,'E'};
    cout << "Completely Initialized char Array e with auto : "<<endl;

    for (auto z : e) //no need to know the type of array

        cout << z << endl;

    cout << endl;


    return 0;
}



