#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

void print_permissions(){

}

int main(){
  struct stat sb;
  stat("test.txt", &sb);
  char buff[50];
  sprintf(buff, "size of file: %luB", sb.st_size);
  printf("%s which is %fKB\n", buff, (float) sb.st_size / 1000);
  printf("permissions of file: %o\n", sb.st_mode);
  printf("time of last access: %s\n", ctime( &(sb.st_atime) ));
}
