//Process creation using wait(),sleep() and exit()
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
  pid_t id1=fork();
  pid_t id2=fork();
  if(id1>0 && id2>0){
    wait(NULL);
    wait(NULL);
    printf("Parent terminated \n");
  }
  else if(id==0 && id2>0){
    sleep(2);
    wait(NULL);
    printf("1st child terminated \n");
  }
  else if(id1>0 && id2==0){
    sleep(1);
    printf("2nd child terminated \n");
  }
  else{
    printf("Grand child terminated \n");
    exit();
  }
  return 0;
}
/*OUTPUT -
Grand child terminated 
2nd child terminated
1st child terminated
Parent terminated
*/

/*Program to create parent process sort the integers using insertion sort 
and waits for child process to sort the integers using selection sort*/

#include<stdio.h>
#include<unistd.h>
void selection(int arr[],int n){
  int i , j,small;
  for(int i=0; i<n-1;i i++){
    small=i;
    for(j=i+1; j<n; j++){
      if(arr[j]<arr[small]){
        small=j;
      }
    }
    int temp =arr[small];
    arr[small]=arr[i];
    arr[i]=temp;
  }
}
void printarray (int arra[], int size){
  for(int i=0; i<size; i++){
    printf("%d",array[i]);
  }
  printf("\n");
}
void insertionsort(int array[], int size){
  for(int step=1 ; step<size ; step++){
    int key = array[step];
    int j = step - 1;
    while( key<array[j] && j>=0){
      array[j+1] = array[j];
      --j;
    }
    array[j+1]=key;
  }
}
int main(){
  int data[] = {9,5,1,4,3}
  int size = sizeof(data)/sizeof(data[0]);
  int pid= fork();
  printarray(data,size);
  if(pid==0){
    printf("Sorting array with selection sort \n");
    selection(data,size);
    printarray(data,size);
  }
  else{
    sleep(1);
    printf("Sorting array with insertion sort \n");
    insertionsort(data,size);
    printf("\n");
    printarray(data,size);
  }
}
/* OUTPUT -
Before sorting : 9 5 1 4 3
Sorting array with selection sort in child process
1 3 4 5 9
Sorting array with insertion sort in parent process
1 3 4 5 9
*/
    
