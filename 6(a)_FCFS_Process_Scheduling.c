// IMPLEMENTATION OF FCFS PROCESS SCHEDULING
#include<stdio.h>
int main(){
  int n,bt[20] ,wt[20], tat[20], avgwt=0, avgtat=0,i,j;
  printf("Enter total no of processes : ");
  scanf("%d" ,&n);
  printf("Enter Burst time :\n");
  for(i=0; i<n; i++){
    printf("P[%d] : ",i+1);
    scanf("%d", ,&bt[i]);
  }
  wt[0]=0;
  for(i=1;i<n;i++){
    wt[i]=0;
    for(j=0;j<i;j++){
      wt[i]+=bt[j];
    }
  }
    printf("\n Process \t Burst Time \t Waiting Time \t Turn around time\n");
    for(i=0;i<n;i++){
      tat[i]=bt[i]+wt[i];
      avgwt+=wt[i];
      avgtat+=tat[i];
      printf("\n P[%d] \t\t %d \t\t %d \t/t %d \n",i+1,bt[i],wt[i],tat[i]);
  }
 avgwt/=i;
 avgtat/=i;
 printf("\n Average Waiting Time : %d ",avgwt);
 printf("\n Average Turn Around Time : xd(n", avgtat);
 return 0;
 }
 /*OUTPUT-
 Enter total no of processes : 5
Enter Burst time : :
P[1] : 10
P[2] 5
P[3] : 8
P[4] : 12
P[5] : 2
   Process    Burst Time    Waiting Time    Turn around time
 
 P[1]           10              0               10
 P[2]            5              10              15
 P[3]            8              15              23
 P[4]           12              23              35
 P[5]           2               35              37
 Average Waiting Time : 16
 Average Turn Around Time : 24

 */
