#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#include "lshIO.h"

#define MAX_BUF 1024

void ex1(int argc, char **argv);
void ex2(int argc, char **argv);
int ex3(void);

int main(int argc, char **argv) {
   
    // ex3();
    // ex2(argc, argv);
    ex1(argc, argv);

    // char *fileName = "test.txt";
    // int fileDes = open(fileName, O_RDWR, S_IRUSR | S_IWUSR);
    // if(fileDes < 0) {
    //     perror("Error");

    //     return 0;
    // }

    // int n;
    // lshRio_t rio;
    // char buf[1024];
    // lshRio_readinitb(&rio, fileDes);
    // while ((n = lshc_readline(&rio, buf, 1024)) != 0)
    // {
    //     lsh_writen(fileDes, buf, n);
    // }

    return 0;
}

//标准输入重定向到标准输出，或者输入文件参数重定向标准输出
void ex1(int argc, char **argv)
{
    char buf[MAX_BUF];
    int n;
    lshRio_t rio;
    int fd;

    if (argc == 2) 
    {
        if ((fd = open(argv[1], O_RDONLY, 0)) < 0) {
            perror("open");
            exit(1);
        }
        lshRio_readinitb(&rio, fd);
    }
    else 
    {
        lshRio_readinitb(&rio, STDIN_FILENO);
    }
    while ((n = lshc_readline(&rio, buf, MAX_BUF)) != 0)
        lsh_writen(STDOUT_FILENO, buf, n);
}


//检查文件元数据
void ex2(int argc, char **argv)
 {
    int fd;
    struct stat s;
    if((fd = open("test.txt", O_RDONLY, 0)) < 0)
        printf("open test.txt failed");
    
    fstatcheck(fd, &s);

    close(fd);
}