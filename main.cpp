#include<iostream>
#include <chrono>
#include <unistd.h>
using namespace std;


void fillArray(int arr[], const int N, int absRange) {
    srand(time(0));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % (absRange * 2) - absRange;
    }
}

void findArrayMinMax(int arr[], const int N, int &mn, int &mx) {
    mn = arr[0];
    mx = arr[0];
    for (int i = 0; i < N; i++) {
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }   
}

int findArrayAverage(int arr[], const int N) {
    int mn, mx;
    findArrayMinMax(arr, N, mn, mx); 
    return (mx + mn) / 2;
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

int defaultSearch(int arr[], int value, const int N) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

void bubbleSort(int arr[], const int N) {
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

void shakerSort(int arr[], const int N) {
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

void combSort(int arr[], const int N) {
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

void insertSort(int arr[], const int N) {
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

void quickSort(int arr[], int start, int end)
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
        cin.clear(); // Clearing the input stream from possible errors
        cin.sync();
        short int workPoint;
        
        cout << "Select point of work (number 1 to 8): ";
        cin >> workPoint;

        switch (workPoint)
        {
            case 1: {
                fillArray(arr, N, 100);
                for (int i = 0; i < N; i++) {
                    cout << arr[i] << " ";
                }
                break;
            }
            case 2: {
                auto start = chrono::steady_clock::now();
                quickSort(arr, 0, N - 1);
                auto end = chrono::steady_clock::now();
                cout << "Quick sort time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mcs" << "\n";
                break;
            }
            case 3: {
                auto start = chrono::steady_clock::now();
                int mn, mx;
                findArrayMinMax(arr, N, mn, mx);
                auto end = chrono::steady_clock::now();
                cout << "Unsorted: Min " << mn << ", Max " << mx << "\n" 
                << "Search time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mcs" << "\n";

                quickSort(arr, 0, N - 1);
                start = chrono::steady_clock::now();
                cout << "\n" << "Sorted: Min " << arr[0] << ", Max " << arr[N - 1] << "\n";
                end = chrono::steady_clock::now();
                cout << "Search time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mcs" << "\n"; 
                break; 
            } 
            case 4: {
                int average = findArrayAverage(arr, N);
                cout << "Unsorted average: " << average << "\n";

                auto start = chrono::steady_clock::now();
                int count = 0;
                for (int i = 0; i < N; i++) {
                    if (arr[i] == average) {
                        cout << i << " ";
                        count++;
                    }
                }
                auto end = chrono::steady_clock::now();

                if (count != 0) cout << "\n";
                cout << "Search time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mcs" << "\n";
                cout << "Count of elements: "<< count << "\n";

                quickSort(arr, 0, N - 1);
                average = (arr[0] + arr[N - 1]) / 2;
                cout << "\n" << "Sorted average: " << average << "\n";

                start = chrono::steady_clock::now();
                count= 0;
                int index = binarySearch(arr, average, 0, N - 1);
                for (int i = index - 1; i > -1; i--) {
                    if (arr[i] == average) {
                        cout << i << " ";
                        count++;    
                    }
                    else break;
                }
                for (int i = index; i < N; i++) {
                    if (arr[i] == average) {
                        cout << i << " ";
                        count++;    
                    }
                    else break;
                }
                end = chrono::steady_clock::now();
                if (count != 0) cout << "\n";
                cout << "Search time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mcs" << "\n"; 
                
                cout << "Count of elements: "<< count;
                break;   
            }     
            case 5: {
                int a;
                cout << "\n" << "Enter an integer: ";
                cin >> a;
                if (!cin.good()) {
                    cout << "\n" << "You entered an incorrect value";
                    break;
                }

                quickSort(arr, 0, N - 1);

                if (a > arr[(N - 1) / 2]) {
                    for (int i = N - 1; i >= 0; i--) {
                        if (arr[i] < a) {
                            cout << i + 1;
                            break;
                        }
                    }
                } else if (a < arr[(N - 1) / 2]) {
                    for (int i = 0; i < N; i++) {
                        if (arr[i] >= a) {
                            cout << i;
                            break;
                        }
                    }
                } else cout << arr[(N - 1) / 2];
                break;
            }  
            case 6: {
                int b;
                cout << "\n" << "Enter an integer: ";
                cin >> b;
                if (!cin.good()) {
                    cout << "\n" << "You entered an incorrect value";
                    break;
                }

                quickSort(arr, 0, N - 1);

                if (b > arr[(N - 1) / 2]) {
                    for (int i = N - 1; i >= 0; i--) {
                        if (arr[i] <= b) {
                            cout << N - i - 1;
                            break;
                        }
                    }
                } else if (b < arr[(N - 1) / 2]) {
                    for (int i = 0; i < N; i++) {
                        if (arr[i] > b) {
                            cout << N - i;
                            break;
                        }
                    }
                } else cout << arr[(N - 1) / 2];
                break;
            } 
            case 7: {
                int number;
                cout << "\n" << "Enter an integer: ";
                cin >> number;
                if (!cin.good()) {
                    cout << "\n" << "You entered an incorrect value";
                    break;
                }
                quickSort(arr, 0, N - 1);

                auto start = chrono::steady_clock::now();
                cout << "Binary: ";
                if (binarySearch(arr, number, 0, N - 1) != -1) cout << "true";
                else cout << "false";
                auto end = chrono::steady_clock::now();
                cout << ", search time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mcs" << "\n";
                
                start = chrono::steady_clock::now();
                cout << "Default: ";
                if (defaultSearch(arr, number, N) != -1) cout << "true";
                else cout << "false";
                end = chrono::steady_clock::now();
                cout << ", search time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mcs" << "\n";

                break;
            } 
            case 8: {
                int firstIndex, secondIndex;
                cout << "\n" << "Enter an 2 integers: ";
                cin >> firstIndex;
                cin >> secondIndex;
                if (!cin.good()) {
                    cout << "\n" << "You entered an incorrect value";
                    break;
                }
                if (firstIndex < 0 || secondIndex < 0 || firstIndex >= N || secondIndex >= N) {
                    cout << "\n" << "You entered incorrect indexes";
                    break;
                }

                swap(arr[firstIndex], arr[secondIndex]);

                break;
            } 
            default: {
                cout << "\n" << "You did not enter a number in the range from 1 to 8";
                break;
            }
        }
        
        cin.clear(); // Clearing the input stream from possible errors
        cin.sync();
        
        char printArray;
        cout << "\n" << "Print the result array? (Y/N) ";
        cin >> printArray;
        
        if (printArray == 'Y' || printArray == 'y') {
            for (int i = 0; i < N; i++) cout << arr[i] << " ";
        }
        cin.clear();
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