#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int variable;
int do_something() {
	variable = 42;
	printf("in child process\n");
	//close(fd);
	// _exit(0);
	return 0;
}
int main(int argc, char *argv[]) {
	void *child_stack;
	char tempch;
	variable = 9;
	//fd = open("./test.txt",O_RDWR);
	child_stack = (void *)malloc(16384);
	printf("The variable was %d\n",variable);
	clone(do_something, child_stack+10000, CLONE_VM |CLONE_FILES,NULL);
	sleep(3); /* 延时以便子进程完成关闭文件操作、修改变量 */
	printf("The variable is now %d\n",variable);
	//if(read(fd,&tempch,1) < 1) {
	//	perror("File Read Error");
	//	exit(1);
	//}
	//printf("We could read from the file\n");
	return 0;
}
