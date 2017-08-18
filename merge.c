//Merge sort
#include <stdio.h>
#include <string.h>
int len;
void merge(int arr[], int i, int mid, int j) {
    int temp[len];
    int l = i;//l,i->starting index value
    int r = j;//r,j->end index value
    int m = mid + 1; //center index value of all sub arrays
    int k = l; //starting index value

    while(l <= mid && m <= r) {
        if(arr[l] <= arr[m]) {
            temp[k++] = arr[l++];
        }
        else {
            temp[k++] = arr[m++];
        }
    }

    while(l <= mid)
        temp[k++] = arr[l++];

    while(m <= r) {
        temp[k++] = arr[m++];
    }

    for(int a = i; a <= j; a++) {
        arr[a] = temp[a];
    }
}
void mergesort(int arr[], int i, int j) {
    int mid = 0;
    if(i < j) {
        mid = (i + j) / 2; // 2 4 1 5 8 6 3 1 9--> 2 4 1 5 ,8 6 3 1 9-->
        mergesort(arr, i, mid);//left 
        mergesort(arr, mid + 1, j);//right
        merge(arr, i, mid, j);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    len = n;
    mergesort(arr, 0, len - 1);
    for(int i=0;i<len;i++)
        printf("%d ",arr[i]);
    return 0;
}
