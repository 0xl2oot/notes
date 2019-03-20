// 第一章
// 起泡排序

void bubblesort(int A[], int n){
	for(bool sorted = false; sorted = !sorted; n--){
		for(int i = 1; i < n; i++){ // 自左向右，逐对检查A[0,n]内各相邻元素
			if(A[i-1] > A[i]){ // 若逆序，则
				swap(A[i-1],A[i]); // 令其互换
				sorted = false; // 清除（全局）有序标志
			}
		}
	}
}

// 数组求和， 线性递归

sum(int A[], int n){
	return (n<1)?0:sum(A,n-1)+A[n-1];
}

// 数组倒置

void reverse(int* A, int lo, int hi){
	// 递归版
	if(lo < hi){
		swap(A[lo], A[hi]);
		reverse(A, lo + 1, hi - 1);
	}
	// 迭代原始版
	next:
		if(lo < hi){
			swap(A[lo], A[hi]);
			lo++;
			hi--;
			goto next;
		}
	// 迭代精简版
	while(lo < hi){
		swap(A[lo++],A[hi--]);
	}
}

// 数组求和，二分递归

sum(int A[], int lo, int hi){
	if(lo == hi) return A[lo];
	int mi = (lo + hi) >> 1;
	return sum(A, lo, mi) + sum(A, mi + 1, hi);
}

// Max 迭代1，2n-3

void max2(int A[], int lo, int hi, int & x1, int & x2){
	for(x1 = lo, int i = lo + 1; i < hi; i++)
		if(A[x1] < A[i]) x1 = i;
	for(x2 = lo, int i = lo + 1; i < x1; i++)
		if(A[x2] < A[i]) x2 = i;
	for(int i = x1 + 1; i < hi; i++)
		if(A[x2] < A[i]) x2 = i;
}

// Max 迭代2，2n-3
void max2(int A[], int lo, int hi, int & x1; int & x2){
	if(a[x1 = lo] < A[x2 = lo + 1])
		swap(x1,x2);
	for(int i = lo + 2; i < hi; i++){
		if(A[x2] < A[i])
			if(A[x1] < A[x2 = i])
			swap(x1,x2);
	}
}

// Max 递归分治，5n/3-2

void max2(int A[], int lo, int hi, int & x1; int & x2) {
	if(lo + 2 == hi) {
		if(a[x1 = lo] < A[x2 = lo + 1])
			swap(x1,x2);
		return ;
	}
	if(lo + 3 == hi) {
		if(a[x1 = lo] < A[x2 = lo + 1])
			swap(x1,x2);
		if(A[x2] < A[lo + 2])
			if(A[x1] < A[x2 = lo + 2])
				swap(x1,x2);
		return ;
	}
	int mi = (lo + hi) >> 1;
	int x1L, x2L, x1R, x2R;
	max2(A, lo, mi, x1L, x2L);
	max2(A, mi, hi, x2L, x2R);
	if(A[x1L] > A[x1R]){
		x1 = x1L;
		x2 = A[x2L] > A[x1R] ? x2L : x1R;
	}
	else {
		x1 = x1R;
		x2 = A[x1L] > A[x2R] ? x1L : x2R;
	}
}

// fib():递归
int fib(n){
	return (2 > n) ? n : fib(n-1) + fib(n-2);
}

// fib():迭代
int fib(n){
	// 解决方法A（记忆：memoization）
	// 解决方法B（动态规划：dynamic programming）
	f = 0; g = 1;
	while(0 < n--) {
		g = g + f;
		f = g - f;
	}
	return g;
}

// 最长公共子序列:LCS:递归
int LCS(char A[], char B[], int n, int m) {
	if(n <= 0 || m <= 0)
		return 0;
	if(A[n-1] == B[m-1])
		return LCS(A, B, n - 1, m - 1) + 1;
	else
		return max(LCS(A, B, n, m - 1),LCS(A, B, n - 1, m);
}

// 迭代
int C[2001][2001];
int LCS(char A[], char B[], int n, int m) {
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(A[i-1] == B[j-1])
				C[i][j] = C[i-1][j-1] + 1;
			else 
				C[i][j] = max(C[i-1][j], C[i][j-1]);
		}
	}
	return C[n][m];
}


// 第二章
// Vector 模板类
typedef int Rank; // 秩
#define DEFAULT_CAPACITY 3 // 默认初始容量(实际应用中可设置为更大) 
template <typename T> class Vector { // 向量模板类
	protected: 
		Rank _size; int _capacity; T* _elem; // 规模，容量，数据区
		void copyFrom(T const* A, Rank lo, Rank hi); // 复制数组区间A[lo, hi)
		void expand(); // 空间不足时扩容
		void shrink(); // 装填因子过小时压缩
		bool bubble(Rank lo, Rank hi); // 扫描交换
		void bubbleSort(Rank lo, Rank hi); // 起泡排序算法
		Rank max(Rank lo, Rank hi); // 选取最大元素
		void selectionSort(Rank lo, Rank hi); // 选择排序算法
		void merge(Rank lo, Rank mi, Rank hi); // 归并算法
		void mergeSort(Rank lo, Rank hi); // 归并排序算法
		Rank partition(Rank lo, Rank hi); // 轴点构造算法
		void quickSort(Rank lo, Rank hi); // 快速排序算法
		void heapSort(Rank lo, Rank hi); // 堆排序（稍后结合完全堆讲解）
		// 内部函数
	public:
		// 构造函数
		Vector(int c = DEFAULT_CAPACITY, int s = 0; T v = 0) {
			// 容量为c，规模为s，所有元素初始为v
			_elem = new T[_capacity = c];
			for(_size = 0; _size < s; _elem[_size++] = v)
				// s <= c
				;
		}
		Vector(T const* A, Rank n) {
			// 数组整体复制
			copyFrom(A, 0, n);
		}
		Vector(T const* A, Rank lo, Rank hi) {
			// 区间复制
			copyFrom(A, lo, hi);
		}
		Vector(Vector<T> const& V) {
			// 向量整体复制
			copyFrom(V._elem, 0, V._size);
		}
		Vector(Vector<T> const& V, Rank lo, Rank hi) {
			// 向量区间复制
			copyFrom(V._elem, lo, hi);
		}
		// 析构函数
		~Vector(){
			// 释放内部空间
			delete [] _elem;
		}
		// 只读接口
		Rank size() const {
			// 规模
			return _size;
		}
		bool empty() const {
			// 判空
			return !_size;
		}
		int disordered() const; // 判断向量是否已经排序
		Rank find(T const& e) const {
			return find(e, 0, _size);
		}
		Rank search(T const& e) const {
			// 有序向量的整体查找
			return (0 >= _size) ? -1 : search(e, 0, _size);
		}
		Rank search(T const& e, Rank lo, Rank hi) const {
			// 有序向量的整体查找
			;
		}
		// 可写接口
		T& operator[](Rank r) const; // 重载下标操作符，可以类似于数组形式引用各元素
		Vector<T> & operator = (Vector<T> const& ); // 重载赋值操作符，以便直接克隆向量
		T remove(Rank r); // 删除秩为R的向量
		int remove(Rank lo, Rank hi); // 删除在指定区间的元素
		Rank insert(Rank r, T const& e); // 插入元素
		Rank insert(T const& e) { 
			// 默认作为末元素插入
			return insert(_size, e);
		}
		void sort(Rank lo, Rank hi); // 对[lo, hi)排序
		void sort() {
			// 对整体排序
			sort(0, _size);
		}
		void unsort(Rank lo, Rank hi); // 对[lo, hi)置乱
		void unsort(){
			// 整体置乱
			unsort(0, _size);
		}
		int deduplicate(); // 无序去重
		int uniquify(); //有序去重
		// 遍历接口
		void traverse(void(* )(T& )); // 遍历（使用函数指针，只读或局部性修改）
		template<typename VST>void traverse(VST& ); // 遍历（使用函数对象，可全局性修改）
};


template <typename T> // T为基本类型，或已经重载赋值操作符'='
void Vector<T>::copyFrom(T* const A, Rank lo, Rank hi) {
	_elem = new T[_capacity = 2*(hi - lo)]; // 分配空间
	_size = 0; // 规模清零
	while(lo < hi) // A[lo, hi)内的元素逐一
		_elem[_size++] = A[lo++]; // 复制至_elem[0, hi-lo)
}















