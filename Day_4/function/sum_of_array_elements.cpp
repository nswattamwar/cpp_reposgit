#include<iostream>
using namespace std;

int sum(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum of array elements: " << sum(arr, n) << endl;
    return 0;
}   

// Output
// Sum of array elements: 15
//
// Note: The function sum() takes an array and its size as arguments and returns the sum of all elements in the array.
// The main() function creates an array of integers and calculates the sum of its elements using the sum() function. The result is then printed to the console.
// The output of this program is:
// Sum of array elements: 15
// This indicates that the sum of the elements {1, 2, 3, 4, 5} in the array is 15.
// You can modify the array elements or add more elements to test the function with different inputs.
// You can also create other functions to perform different operations on arrays, such as finding the maximum or minimum element, calculating the average, or sorting the elements. Experiment with different functions and array operations to enhance your understanding of arrays and functions in C++.
//
// Practice
