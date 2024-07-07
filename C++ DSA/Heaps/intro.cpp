#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletion() {
        if (size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;

        int i = 1;

        while (i < size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            } else if (rightIndex < size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            } else {
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n; i > 1; i--) {
        swap(arr[i], arr[1]);
        heapify(arr, i - 1, 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletion();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    cout << "Original array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapsort(arr, n);

    cout << "Sorted array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //using priority queue here
    //default it is a maxheap

    priority_queue<int> pq;

    pq.push(4);
    pq.push(3);
    pq.push(5);
    pq.push(3);
    
    cout<<"element at top"<<pq.top()<<endl;
    pq.pop();
    cout<<"element at top"<<pq.top()<<endl;
    cout<<"size is"<< pq.size()<<endl;

    if(pq.empty()){
        cout<<"pq is empty"<<endl;

    }
    else{
        cout<<"pq is not empty"<<endl;
    }




    //min heap
    priority_queue<int, vector<int>, greater<int> > minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);



    cout<<"element at top"<<minheap.top()<<endl;
    minheap.pop();
    cout<<"element at top"<<minheap.top()<<endl;
    cout<<"size is"<< minheap.size()<<endl;

    if(minheap.empty()){
        cout<<"minheap is empty"<<endl;

    }
    else{
        cout<<"minheap is not empty"<<endl;
    }
    return 0;
}



//heap creation for zero ase index is from n/2 -1 to greater than 0
//and for 1 base iundexing n/2 to greater than 0
