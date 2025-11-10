#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int b[r - l + 1];
    while (i <= m && j <= r)
        b[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    while (i <= m) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (i = 0; i < k; i++) a[l + i] = b[i];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    mergeSort(a, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
