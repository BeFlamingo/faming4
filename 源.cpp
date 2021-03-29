#include<iostream>
using namespace std;
#define size 100
void Merge(int a[], int TmpA[], int L, int R, int RightEnd) {
	int LeftEnd = R - 1;
	int Tmp = L;
	int NumElements = RightEnd - L + 1;
	while (L <= LeftEnd && R <= RightEnd) {
		if (a[L] < a[R]) {
			TmpA[Tmp++] = a[L++];
		}
		else {
			TmpA[Tmp++] = a[R++];
		}
	}
	while (L <= LeftEnd) {
		TmpA[Tmp++] = a[L++];
	}
	while (R <= RightEnd) {
		TmpA[Tmp++] = a[R++];
	}
	for (int i = 0; i < NumElements; i++, RightEnd--) {
		a[RightEnd] = TmpA[RightEnd];
	}
}
void MSort(int A[], int TmpA[], int L, int RightEnd) {
	int Center;
	if (L < RightEnd) {
		Center = (L + RightEnd) / 2;
		MSort(A, TmpA, L, Center);
		MSort(A, TmpA, Center + 1, RightEnd);
		Merge(A, TmpA, L, Center + 1, RightEnd);
	}
}
void Merge_sort(int A[], int N) {
	int TmpA[size];
	MSort(A, TmpA, 0, N - 1);
}
int main() {
	int number;
	int a[size];
	int TmpA[size];
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> a[i];
	}
	Merge_sort(a, number);
	for (int i = 0; i < number; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}