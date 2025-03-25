#include<iostream>
using namespace std;
class Heap {
    public:
    int arr[100]{};
    int size;
    Heap(){
        arr[0] = -1;
        size = 0;
    }
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }
    void deleteFromHeap(){
        if(size == 0){
            cout << "Nothing to delete." << endl;
            return;
        }
        // root = last
        arr[1] = arr[size];
        // Remove the last node
        size--;
        // Propagate the root to it's correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }else{
                return;
            }
        }
    }
    void print(){
        for(int i=1; i<= size; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }
};
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    } 
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n){
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}
int main(){
    Heap maxHeap;
    maxHeap.insert(50);
    maxHeap.insert(55);
    maxHeap.insert(53);
    maxHeap.insert(52);
    maxHeap.insert(54);
    maxHeap.print();
    int arr[] = {-1,54,53,55,52,50};
    int n = 5;
    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }
    cout << "Array elements after heapify:" << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }cout << endl;
    cout << "Array elements after heap sort:" << endl;
    heapSort(arr, n);
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}