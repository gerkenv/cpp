#include<vector>
#include<iostream>
using namespace std;

template<typename T>
void printArray( vector<T>& array ) {
    for ( int i = 0; i < array.size(); i++ ) {
        cout << array[i] << endl;
    }
}
