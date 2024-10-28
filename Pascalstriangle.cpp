#include <iostream>
using namespace std;

void printPascalsTriangle(int n) {
    for (int row = 0; row < n; row++) {
        int val = 1;  // Initialize first value of each row
        for (int space = 0; space < n - row - 1; space++) {
            cout << "  ";  // Print spaces for alignment
        }
        for (int col = 0; col <= row; col++) {
            cout << val << "   ";  // Print the current value and spaces
            val = val * (row - col) / (col + 1);  // Calculate next value
        }
        cout << endl;  // Move to the next row
    }
}

int main() {
    int numRows;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;
    printPascalsTriangle(numRows);
    return 0;
}
