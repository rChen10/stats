#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

char *print_permissions(int x){
  //brute force, but perhaps there is a better way
  if (x == 01)
    return "--x";
  if (x == 02)
    return "-w-";
  if (x == 03)
    return "-wx";
  if (x == 04)
    return "r--";
  if (x == 05)
    return "r-x";
  if (x == 06)
    return "rw-";
  if (x == 07)
    return "rwx";
  else
    return "---";
}

int main(){
  struct stat sb;
  stat("test.txt", &sb);
  char buff[50];
  sprintf(buff, "size of file: %luB", sb.st_size);
  printf("%s which is %fKB\n", buff, (float) sb.st_size / 1000);

  char pbuff[9];
  int perm = sb.st_mode;
  sprintf(pbuff, "%s%s%s", print_permissions(perm % 8),
	  print_permissions(perm % 8 % 8),
	  print_permissions(perm % 8 % 8 % 8));
  printf("permissions of file: %s\n", pbuff);
  printf("time of last access: %s\n", ctime( &(sb.st_atime) ));
}
