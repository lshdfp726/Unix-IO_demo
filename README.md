# Unix-IO_demo
研究学习 Unix/linux IO

### lshIO.c 实验目的:

 lshIO.c 是具体针Unix/IO 的描述文件符实现的一层封装，主要是针对网络套接字socket 的数据读取处理的，socket 使用的读取是文件描述符 而不是 标准IO提供的 FILE 抽象结构。

终端下 使用 make，即可编译出main 目标文件 可以通过注释 main.c 里面 main 函数 去测试lshIO.c 接口
