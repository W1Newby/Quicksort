#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void swap(int a,int b);
void printarr();
int getamt();
void create_array(int lo, int hi, int count);
int ssort(int left, int right);
void smartsort(int left, int right);
void fillarray();

int *arr;
int amt = 0;  //amount of numbers to be sorted.
int ret = 0;  //mostly for debugging and holding unused return values.

int main(void) {

    fillarray();
    
    printf("\nOriginal order:\n");
    printarr();
  
    smartsort(0, amt-1);  //caling the function

    printf("Final ordering:\n");
    printarr();  
   
    return 0;
}
void fillarray()
{
  printf("How many elements in the array?\n");
    int ret = scanf("%d", &amt);
    arr = (int*)malloc (amt * sizeof(int));
  printf("Please enter the array elements:\n");
    for(int i = 0; i<amt; ++i) {
      ret = scanf("%d", &arr[i]);
    }
}

void swap(int a, int b) {
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

void printarr() {
  for(int i =0; i<amt; ++i)
    printf("%d, ", arr[i]);
  printf("\n");
}
int getamt(){
  printf("How many elements in the array?\n");
  int ret = scanf("%d", &amt);
  arr = (int*)malloc (amt * sizeof(int));
  return amt;
}

void create_array(int lo, int hi, int count) {
   srand(time(0)); 
  arr = (int*)malloc (amt * sizeof(int));
  int num = 0;
    for (int i = 0; i < amt; i++) {
        num = (rand() % (hi - lo + 1)) + lo;
        arr[i]=num;
    }
}
int ssort(int p1, int p2) {

  int pivot=arr[p1];
  
  while(p1<=p2) {
    while(pivot>arr[p1]) {
      p1++;
    }
    while(pivot<arr[p2]) {
      p2--;
    }
  
    if(p1<=p2) {
      swap(p1,p2);
      p1++;
      p2--;
    }
  }
  return p1;
}//closes quicksort function

void smartsort(int left, int right) {

    if(left<right) {
      int midpoint=ssort(left,right);
      if(left<midpoint-1)
        smartsort(left, midpoint-1);
      if(right>midpoint)
        smartsort(midpoint,right);
    }  
}

