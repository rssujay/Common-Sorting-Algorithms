#include <cstdlib>
#include <iostream>

using namespace std;

void printarray(int *arr,int len);
void bubblesort(int *arr, int len);
void bubblesort_alternate(int *arr, int len);
void selectionsort(int *arr, int len);
void insertionsort(int *arr, int len); //incomplete
void mergeSort(int *arr, int i, int j); //incomplete
void quicksort(int a[], int i, int j); //incomplete
void merge(int a[], int i, int mid, int j);
void radixsort(int *arr, int len);
void swap(int a[],int i, int j);
int partition(int a[], int i, int j);

int main(void) {  
    int size = 10; // change array size here
    int array[] = {5,3,6,12,8,2,2,1,6,9}; //change array as required here
    //bubblesort_alternate(array,size); //change sorting function here
    quicksort(array,0,9);
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
    /* Best case: O(n**2)
     * Worst case: O(n**2)
     * Idea: look for the biggest/smallest element and put to one side
     */
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

void insertionsort(int arr[], int n) {
    /* Best case: O(n) (Ascending Order)
     * Worst case: O(n**2)
     * stable
     * in-place
     * Idea: arranging like how you would arrange cards
     */
    int i, key, j;
    for (i = 1; i < n; i++) {
	key = arr[i];
	j = i-1;
	while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
	}
	arr[j+1] = key;
    }
}

void mergeSort(int a[], int i, int j){
    /* Best case - O(n log n)
     * Worst case - O(n log n)
     * stable
     * in-place
     * Idea: divide and conquer (divide until it is trivially sorted, and then
     * combine together
     */ 
    if (i< j) {
        int mid = (i+j)/2; // divide
        mergeSort(a,i,mid); // recursion
	mergeSort(a,mid+1,j);
	merge(a, i, mid, j); //conquer
	}
}

void merge(int a[], int i, int mid, int j) {  
    // Merges a[i..mid] a[mid+1..j] into a[i..j]
    int n = j-i+1;
    int* b = new int[n]; //temp. storage
    int left=i, right=mid+1, ib=0;
    while (left<=mid && right<=j) {
	if (a[left] <= a[right])
            b[ib++] = a[left++];
	else
            b[ib++] = a[right++];
        } 
    // Copy the remaining elements into b
    while (left<=mid) b[ib++] = a[left++];
    while (right<=j) b[ib++] = a[right++];
    // Copy the result back into array a
    for (int k=0;k<n;++k) 
	a[i+k] = b[k];
    delete [] b;
}

void quicksort(int a[], int i, int j){
    /* Best case - O(n log n)
     * Worst case - O(n**2) (if the array is sorted in any way)
     * unstable
     * in-place
     * Idea: select a pivot, see which terms are bigger and smaller than pivot,
     * shift pivot to the middle of the two sections, then repeat for each side
     */ 
    if (i < j) {
	int pivotIdx = partition(a, i, j); 
	//pivot untouched
	quicksort(a, i, pivotIdx-1); 
	quicksort(a, pivotIdx+ 1, j);
    }
}


int partition(int a[], int i, int j) {
    // helper function for quicksort
    int p = a[i];		// p is the pivot
    int m = i;			// initially S1 and S2 are empty
    for (int k = i+1; k<=j; ++k) { 	// process unknown region
	if (a[k] < p) {	// put a[k] to S1
            ++m;
            swap(a,k,m);
        } else {	// put a[k] to S2! Do nothing!
        }
    }
    swap(a,i,m); // put the pivot at the right place
    return m;
}

void swap(int a[],int i, int j){ 
    //helper function to swap two elements in an array
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

