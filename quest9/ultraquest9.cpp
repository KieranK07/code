#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int>& A, int left, int right) {
    // base case
    if (left >= right) {
        return;
    }

    // partition by creating a pivot
    int pivot = A[right];
    int i = left;

    // rearrange around the pivot
    for (int j = left; j < right; j++) {
        // if selected element is less than pivot
        if (A[j] < pivot) {
            // swap em
            swap(A[i], A[j]);
            i++;
        }
    }

    //new pivot position is i
    swap(A[i], A[right]);

    // recursive calls for left and right partitions
    quicksort(A, left, i - 1);
    quicksort(A, i + 1, right);
}

int main() {
    // vector for 10 integers
    vector<int> A(10);

    // input integers
    for (int i = 0; i < 10; i++) {
        cout << "enter element " << i + 1 << ": ";
        cin >> A[i];
    }

    // sort with bounds
    quicksort(A, 0, 9);

    // output sorted 
    for (int x : A) {
        cout << x << " ";
    }
    cout << endl;
}