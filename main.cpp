#include<iostream>
using namespace std;


void fillArray(int *arr, const int N, int absRange) {
    srand(time(0));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % (absRange * 2) - absRange;
    }
}

int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == value) {
            return mid;
        }
        
        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }
        
        return binarySearch(arr, value, mid + 1, end);
    }
    
    return -1;
}

void bubbleSort(int *arr, const int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            int swap = arr[j];
            if (arr[j] > arr[j + 1]) {
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }     
}

void shakerSort(int *arr, const int N) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int swap = arr[j];
            if (arr[j] > arr[j + 1]) {
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }

        for (int j = N - i - 2; j > i; j--) {
            int swap = arr[j];
            if (arr[j - 1] > arr[j]) {
                arr[j] = arr[j - 1];
                arr[j - 1] = swap;
            }
        }
    } 
}

void combSort(int *arr, const int N) {
	float k = 1.247;
    float S = N - 1;
	int count = 0;

	while (S >= 1)
	{
		for (int i = 0; i + S < N; i++)
		{
			if (arr[i] > arr[int(i + S)])
			{
				int swap = arr[int(i + S)];
				arr[int(i + S)] = arr[i];
				arr[i] = swap;
			}
		}
		S /= k;
	}

    bubbleSort(arr, N);
}

void insertSort(int *arr, const int N) {
    int i, key, j;
    for (i = 1; i < N; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int* arr, int start, int end)
{
	int mid;
	int f = start; 
	int l = end;
	mid = arr[(f + l )/ 2];
	while (f < l)
	{
		while (arr[f] < mid) f++;
		while (arr[l]> mid) l--;
		if (f <= l)
		{
			swap(arr[f], arr[l]);
			f++;
			l--;
		}
	}
	if (start < l) quickSort(arr, start, l);
	if (f < end) quickSort(arr, f, end);
}

int main() {
    setlocale(LC_ALL, "Russian");
    return 0;
}