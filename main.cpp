#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& left, vector<int>& right, vector<int>& array){
    int leftSize = left.size();
    int rightSize = right.size();

    //indices for left, right and array
    int i = 0, l = 0, r = 0;

    while (l < leftSize && r < rightSize){
        if (left[l] < right[r]){
            array[i] = left[l];
            l++;
        }
        else{
            array[i] = right[r];
            r++;
        }
        i++;
    }

    while (l < leftSize){
        array[i] = left[l];
        l++;
        i++;
    }
}

void mergeSort(vector<int>& array){
    int n= array.size();
    if(n<=1){
        return;
    }
    int center = n/2;

    vector<int> left(center);
    vector<int> right(n-center);

    for (int i = 0; i < n; i++){
        if (i < center){
            left[i] = array[i];
        }
        else{
            right[i-center] = array[i];
        }
    }
    //divide the array into two parts
    mergeSort(left);
    mergeSort(right);

    merge(left, right, array);
}

int main(){
    vector <int> array = { 89, 90, 100, 12, 69, 54, 23, 34, 45, 56, 67, 78};

    mergeSort(array);
    for (int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
}