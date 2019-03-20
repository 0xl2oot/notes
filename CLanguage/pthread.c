// 前面的 Peterson's Algorithm 留下了一个问题
// 就是锁机制只能判断临界资源是否被占用
// 所以他解决了互斥问题，但是他不能确定前面的进程是否完成
// 所以他不能用于同步问题中。
// 信号量机制很好地解决了这个问题


// 在 Linux 下，sleep() 函数的头文件是：unistd.h
// 但在 MinGW GCC 下没有了这个函数的定义
// 到是在 windows.h 文件中有 Sleep() 函数的定义
// 其单位是 ms 级的延迟处理。因此作如下处理

#if defined(WIN32) || defined(WIN64)  
#include <windows.h>  
#define sleep(n) Sleep(1000 * (n))  
#else  
#include <unistd.h>  
#endif

#include <stdio.h>
#include <pthread.h>	// 引入多线程


int flag[2] = {0 , 0};	// 接下来哪一个进程能够执行的标志
int turn = 0;
int pub = 1;			// 临界区变量

void *P0() {
	int i = 0;
	while(1){
		flag[0] = 1;
		turn = 1;		
		while(flag[1] && turn);
		// 临界区开始
		pub += 1;
		printf("进程P0的第%d次执行，pub = %d\n",i++,pub);
		// 临界区结束
		flag[0] = 0;
		// 其他程序
		sleep(1);
	}
	pthread_exit(NULL);
}

void *P1() {
	int i = 0;
	while(1){	
		flag[1] = 1;
		turn = 0;
		while(flag[0] && !turn);
		// 临界区开始
		pub += 2;
		printf("进程P1的第%d次执行，pub = %d\n",i++,pub);
		// 临界区结束
		flag[1] = 0;
		// 其他程序
		sleep(3);
	}
	pthread_exit(NULL);
}


int main() {
	pthread_t threads[2];		// 创建线程数组
	pthread_create(&threads[0], NULL, P0, NULL);
	pthread_create(&threads[1], NULL, P1, NULL);
	pthread_exit(NULL);
	return 0;
}
