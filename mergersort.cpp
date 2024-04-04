// #include <iostream>
// using namespace std;

// void mergeSort(int arr[],int s, int e){


//     int mid = (s+e)/2;
//     int lenLeft = mid - s + 1;
//     int lenRight = e - mid;


//     int *left = new int[lenLeft];
//     int *Right = new int[lenRight]; 

//     // copy values from original array to left array
//     int k = s;
//     for(int i = 0; i<lenLeft; i++){
//         left[i] = arr[k];
//         k++;
//     }
//  int k = mid+1;
//     for(int i = 0; i<lenRight; i++){
//         right[i] = arr[k];
//         k++;
//     }
// //actual merge logic here
// // left array is already sorted
// //right array is already sorted
// int leftIndex = 0;
// int rightIndex = 0;
// // yahi pr galti karte h log
// int mainArrayIndex = s;
// while(leftIndex<lenLeft && rightIndex <lenRight){
//     if(left[leftIndex]< Right[rightIndex]) {
//         arr[mainArrayIndex] = left[leftIndex];
//         mainArrayIndex++;
//         leftIndex++;
//     }
//     else{
//         arr[mainArrayIndex] = Right[rightIndex];
//         mainArrayIndex++;
//         rightIndex++;
//     }
//      //corner case
//      //1 case:- left array exhaust but right array mein element abhi bhi bache hai
//      while(rightIndex< lenRight){
//         arr[mainArrayIndex] = Right[rightIndex] ;
//         mainArrayIndex++;
//         rightIndex++;
//      }
//      //2 case:- right array exhaust but left array mein element abhi bhi bache hai
//      while(leftIndex< lenLeft){
//         arr[mainArrayIndex] = left[leftIndex] ;
//         mainArrayIndex++;
//         leftIndex++;
//      }
//      delete[] left;
//      delete[] Right;
//     }

//     //base case
//     if(s>=e){
//         return;
//   
//       mid = (s+e)/2;
// mergeSort(arr, s, mid);
// mergeSort(arr, mid+1, e);
// mergeSort(arr, s, e);
// }
// int main(){
//     int arr[] = {1,3,48,2,7};
//     int size= 5;
//     int s =0;
//     int e = size-1;

//   cout << "before merge sort ";
//     for(int i=0; i<size; i++){
//         cout<< arr[i] << " ";
         
//     }
//     cout<<endl;
//     mergeSort(arr, s, e);

//     cout<<"after merge sort: " << endl;
//     for(int i=0; i<size; i++){
//         cout<< arr[i] << " ";
         
//     }
//     cout<<endl;
   
//     return 0;
// }
#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    // ... merge logic ... (assuming the actual merge logic is implemented here)
}

void mergeSort(int arr[], int s, int e) {
    if (s >= e) {
        return;
    }

    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

int main() {
    int arr[] = {1, 3, 48, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate size correctly

    cout << "Before merge sort: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, size - 1); // Use correct bounds for the array

    cout << "After merge sort: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
