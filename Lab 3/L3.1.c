#include<stdio.h>
#include<time.h>
#include<stdlib.h>

unsigned int opcount= 0;
void bubblesort(int arr[], int n){
    int i ,j, temp;
    for(i=0;i<n-1; i++){
        for(j=0;j<n-i-1;j++){
           if(arr[j] > arr[j+1]){
                opcount++;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
           }
        }
    }
}

int main(){
    int i;
    long long int n;
    clock_t start, endl;
    double cpu_time;
    printf("Enter size of array: ");
    scanf("%d", &n);
    srand(time(NULL));
    int arr1[n];
    printf("Enter elements: \n");
    for(i=0; i<n; i++)
        arr1[i] = (rand()%1000) +1;
    start = clock();
    bubblesort(arr1, n);
    endl = clock();
    cpu_time = (double)(endl-start)/CLOCKS_PER_SEC;
    for(i=0; i<n; i++)
        printf("%d ", arr1[i]);

    printf("Time taken: %e  Opcount:%d ", cpu_time, opcount);

    return 0;
}
