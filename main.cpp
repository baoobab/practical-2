#include<iostream>
#include <chrono>
#include <unistd.h>
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

    const int N = 100;
    int arr[N] = {};

    cout << "Navigation:" << "\n"
    << "1) Create an integer array of size N = 100. The elements of the array must take a random value in the range from -99 to 99" << "\n"
    << "2) Sort the array (from smallest to largest)" << "\n"
    << "3) Find the max and min element of the array. Calculate the search time for these elements in sorted array and unsorted" << "\n"
    << "4) Prints the average of max and min values in sorted and unsorted arrays. Prints the indexes of all elements that are equal to this value and their number" << "\n"
    << "5) Prints the number of elements in sorted array that are less then number <a>" << "\n"
    << "6) Prints the number of elements in sorted array that are greater than the number <b>" << "\n"
    << "7) Displays information about whether the <number> in sorted array. And compare binary search with regular search alorithm (*)" << "\n"
    << "8) Swaps array elements on <indexes>" << "\n";

    while(true) {
        short int workPoint;
        
        cout << "Select point of work (number 1 to 8): ";
        cin >> workPoint;

        switch (workPoint)
        {
            case 1: {
                fillArray(arr, N, 100);
                break;
            }
            case 2: {
                auto start = chrono::steady_clock::now();
                bubbleSort(arr, N);
                auto end = chrono::steady_clock::now();
                cout << "Elapsed time in microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microsec" << "\n";
                cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisec" << "\n";
                break;
            }
            case 3: {
                break; 
            } 
            case 4: {
                break;   
            }     
            case 5: {
                break;
            }  
            case 6: {
                break;
            } 
            case 7: {
                break;
            } 
            case 8: {
                break;
            } 
            default: {
                cout << "\n" << "You did not enter a number in the range from 1 to 8";
                break;
            }
        }
        
        cin.clear(); // Clearing the input stream from possible errors
        cin.sync();

        char stopFlag;
        cout << "\n" << "Continue the program? (Y/N) ";
        cin >> stopFlag;
        
        if (stopFlag != 'Y' && stopFlag != 'y') {
            break;
        }
    }

    return 0;
}