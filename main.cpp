#include <cstdlib>
#include <iostream>

using namespace std;

void printarray(int *arr,int len);
void bubblesort(int *arr, int len);
void bubblesort_alternate(int *arr, int len);
void selectionsort(int *arr, int len);
void insertionsort(int *arr, int len); //incomplete
void mergesort(int *arr, int i, int j); //incomplete
void quicksort(int *arr, int len); //incomplete
void merge(int *arr, int* arr2, int len);
void radixsort(int *arr, int len);

int main(void) {  
    int size = 10; // change array size here
    int array[size] = {5,3,6,12,8,2,2,1,6,9}; //change array as required here
    bubblesort_alternate(array,size); //change sorting function here
    printarray(array,size);
    return 0;
}

void printarray(int *arr, int len){
    for (int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubblesort(int *arr, int len){
    /* Best case - O(n**2)
     * Worst case - O(n**2)
     * stable
     * in-place
     */   
    for (int i = 0; i < len; i++){
        for (int j = 1;j < len - i; j++){
            if (arr[j-1] > arr[j]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bubblesort_alternate(int *arr, int len){
    /* Best case - O(n), when the while loop only runs once
     * Worst case - O(n**2)
     * stable
     * in-place
     */   
    bool sorted = false;
    while(!sorted){
        sorted = true;
        
        for (int i = 1; i < len; i++){
            if (arr[i-1]>arr[i]){
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
                sorted = false;
            }
        }
    }
}

void selectionsort(int *arr, int len){
    for (int i = 0; i < len; i++){
        int min = i;
        
        for (int j = i; j < len; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        
        if (min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void insertionsort(int *arr, int len){
    for (int i = 1; i < len; i++){
        int temp = arr[i];
        
    }
    
}

void merge(int *arr, int* arr2, int len);
    

void mergesort(int *arr, int i, int j){
    
}

