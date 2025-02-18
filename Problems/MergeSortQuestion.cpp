#include <iostream>
#include <cstring>
using namespace std;
void merge(string books[], int s, int mid, int e){
    int l1 = mid - s + 1;
    int l2 = e - mid;

    string first[l1], second[l2];
    for(int i=0; i<l1; i++){
        first[i] = books[s+i];
    }
    for(int j=0; j<l2; j++){
        second[j] = books[mid+1+j];
    }
    int i=0, j=0, k = s;
    while(i < l1 && j < l2){
        if(first[i] < second[j]){
            books[k] = first[i];
            i++;
        }else{
            books[k] = second[j];
            j++;
        }
        k++;
    }
    while(i < l1){
        books[k] = first[i];
            i++;
            k++;
    }
    while(j < l2){
        books[k] = second[j];
            j++;
            k++;
    }
}
void mergeSort(string books[], int s, int e){
    if (s < e){
        int mid = s + (e-s)/2;
        mergeSort(books, s, mid);
        mergeSort(books, mid+1, e);
        merge(books, s, mid, e);
    }
}
int main(){
    int n = 5;
    string books[] = {
        "War and Peace", 
        "Anna Karenina", 
        "Moby Dick", 
        "Great Expectations",
        "The Odyssey"
    };
    cout << "Before Sorting:" << endl;
    for(int i=0; i < n; i++){
        cout << books[i] << ", ";
    }
    mergeSort(books, 0, n-1);
    cout << endl;
    cout << "After Sorting:" << endl;
    for(int i=0; i < n; i++){
        cout << books[i] << ", ";
    }
    return 0;
}