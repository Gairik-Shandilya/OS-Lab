/*The concept of overlays is that whenever a process is running it will not use 
the complete program at the same time, it will use only some part of it. 
Then overlays concept says that whatever part you required, 
you load it and once the part is done, then you just unload it, 
means just pull it back and get the new part you required and run it. */


//Execute the following program and write the output

// $vi ex51.c ----filename
#include<stdio.h>
#include<unistd.h>
int main(){
  printf("Transfer to execlp function \n");
  execlp("head","head","-2","f1",NULL);
  printf("This line will not execute");
  return 0;
}
/* OUTPUT -
Transfer to execlp function
head: cannot open "f1" for reading : No such file or directory 
*/

//Rewrite Q1 with execl() function Pass the 3rd and 4th arguement of the function execl() through the command line arguements
// $vi ex52.c ---- filename
#include<stdio.h>
#include<unistd.h>
int main(){
  printf("Transfer to execl function \n");
  execl("head","head","-2","f1",NULL);
  printf("This line will not execute");
  return 0;
}
/* OUTPUT -
Transfer to execl function
This line will not be executed
*/

//Rewrite Q1 with execv() function Pass the 3rd and 4th arguement of the function execl() through the command line arguements
// $vi ex53.c ---- filename
#include<stdio.h>
#include <unistd.h>
int main(){
  printf("Transfer to execv function \n");
  char *arg_list []= {"f1","ARG1","ARG2",NULL);
  execv("f1",arg_list);
  printf("This line will not be executed");
  return 0;
}                   
/* OUTPUT -
Transfer to execv function
This line will not be executed
*/
