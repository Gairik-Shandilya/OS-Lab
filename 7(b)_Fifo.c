#include<stdio.n>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
  char buff[25];
  int rfd,wfd;
  mkfifo("fif1",O_CREAT|0644);
  if (fork()==0){
    printf("Child writing into Fifo \n");
    wfd=open("fif1",O_WRONLY);
    write(wfd,"Hello",6);
  }
  else{
    rfd=open("fif1",O_RDONLY);
    read(rfd,buff,6);
    printf("Parent reads from fifo : %s \n",buff);
  }
  return 0;
}
