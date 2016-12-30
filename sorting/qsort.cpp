#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int newf(int arr[], int left, int right) {
    cout<<"newf got called"<<endl; return 1;
}

int part(int arr[], int left, int right) {
    int i, j, k, l, p = arr[left];
    int green = left+1, yellow = left+1;
    int n = right;
    while(green<n) {
        if(green<n && yellow==green && arr[green]<=p) {
            green++; yellow++;
        }
        else if(green<n && arr[green]>p) {
            green++;
        }
        else if(green<n && arr[green]<=p) {
            swap(arr[yellow], arr[green]);
            green++; yellow++;
        }
    }
    yellow--;
    swap(arr[yellow], arr[left]);
    //for(i=left;i<right;i++) cout<<arr[i]<<" "; cout<<" partmid: "<<yellow<<endl;
    return yellow;
}

void quickSort(int arr[], int left, int right) {
   if(right-left<=1) return;
   int mid = part(arr, left, right);
   quickSort(arr, left, mid);
   quickSort(arr, mid+1, right);
    //cout<<"Before printing. left. mid. right"<<left<<" "<<mid<<" "<<right<<" "<<arr[left]<<" "<<arr[mid]<<" "<<arr[right]<<endl;
    //for(int i=left;i<right;i++) cout<<arr[i]<<" "; cout<<" mid: "<<mid<<endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < (int)n; i++) {
        cin >> arr[i];
    }
    //for(int i = 0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
    quickSort(arr, 0, n);
    for(int i = 0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
    return 0;
}
