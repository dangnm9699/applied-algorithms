#include <bits/stdc++.h>

using namespace std;

// Chọn phần tử đầu làm Pivot
int PartitionL(int a[], int left, int right){
	int pivot = a[left];
	int i = left + 1, j = right;
	while (true){
		// Tìm phần tử >= Pivot
		while ((i <= right) && (a[i]) < pivot) i ++;
		// Tìm phần tử <= Pivot
		while ((j >= left)  && (a[j]) > pivot) j --;
		// Khi biến tăng >= biến lùi thì thoát vòng lặp
		if(i >= j)
			break;
		// Swap 2 giá trị vừa tìm được bên trên
		swap(a[i], a[j]);
		// Tăng biến tăng, giảm biến lùi để xét các phần tử tiếp theo
		i ++;
		j --;
	}
	// Swap để đưa giá trị Pivot vào giữa
	swap(a[j], a[left]);
	// Trả về vị trí của Pivot
	return j;
}

// Chọn phần tử cuối làm Pivot
int PartitionR(int a[], int left, int right){
	int pivot = a[right];
	int i = left, j = right - 1;
	while (true){
		// Tìm phần tử >= Pivot
		while ((i <= right) && (a[i] < pivot)) i ++;
		// Tìm phần tử <= Pivot
		while ((j >= left)  && (a[j] > pivot)) j --;
		// Khi biến tăng >= biến lùi thì thoát vòng lặp
		if(i >= j)
			break;
		// Swap 2 giá trị vừa tìm được bên trên
		swap(a[i], a[j]);
		// Tăng biến tăng, giảm biến lùi để xét các phần tử tiếp theo
		i ++;
		j --;
	}
	// Swap để đưa giá trị Pivot vào giữa
	swap(a[right], a[i]);
	// Trả về vị trí của Pivot
	return i;
}

//
void QuickSort(int a[], int left, int right){
	if (left < right){
		//
		int pivot = PartitionR(a, left, right);
		//
		QuickSort(a, left, pivot - 1);
		//
		QuickSort(a, pivot + 1, right);
	}
}

//
int main(){	
	int n;
	cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++){
		cin >> a[i];
    }
    QuickSort(a, 1, n);
    for (int i = 1; i < n; i++){
        cout << a[i] << " ";
    }
	cout << a[n];
    return 0;
}