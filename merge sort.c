#include <stdio.h>
void read(int arr[], int n) {
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}
int partition (int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high- 1; j++) {
    if (arr[j] < pivot) {
        i++;
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
  }
  int k=arr[i+1];
  arr[i+1]=arr[high];
  arr[high]=k;
  return (i + 1);
}
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main()
{
	int n;
	printf("Enter number of elements in array :");
	scanf("%d",&n);
	int arr[n];
	read(arr,n);
	 printf("The array elements are:\n");
	display(arr,n);
	quickSort(arr, 0, n - 1); 
	 printf("The array elements after sorted:\n");
	 display(arr,n);
}
