#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#define MINSUP 0.005

using namespace std;

// 节点类
class FPNode;

// 记录经过每一个节点的路径的头尾
struct Route
{
	FPNode* head;
	FPNode* tail;
};

typedef std::map<string,Route> itemRoute; // 记录经过每一个节点的路径的头尾，经过一个节点可能有多条路径

// FPTree类
class FPTree
{
	private:
		FPNode* root;	// 根节点
		itemRoute routes;	// 记录每一个节点的头尾，经过一个节点可能有多条路径
	public:
		FPTree();	// FPTree构造方法
		FPNode* getRoot(){return this->root;};	// 返回FPTree的根节点
		void add(vector<string> items);			// 添加节点，一行数据
		void update_route(FPNode* n);			// 更新横向链尾节点或者新增横向的链
		map<string,vector<FPNode*> > getItems(); // 获取所有节点的节点内容以及节点，放入map
		vector<FPNode*> getNodes(string item);	// 获取所有经过此节点内容的节点
		vector<vector<FPNode*> > getPrefixPaths(string item); // 获取所有经过此节点内容的节点路径
};


class FPNode
{
	private:
		FPTree* tree;	// 树指针
		string item;	// 节点内容
		unsigned count;	// 数量
		FPNode* parent;	// 父节点
		vector<FPNode*> children;// 子节点，可能不止一个
		FPNode* neighbor;	// 相邻节点，即相同内容的节点
	public:
		FPNode(FPTree* tr,string s,unsigned c); // 节点构造方法
		~FPNode();

		void add(FPNode* child);	// 增加子节点
		FPNode* search(string i);	// 查找项
		bool contain(string i);		// 判断是否包含项
		FPTree* getTree(){return this->tree;};	// 获取树的指针
		string getItem(){return this->item;};	// 获取节点内容
		unsigned getCount(){return this->count;};	// 获取数量
		void setCount(unsigned i){this->count = i;}; // 设置数量
		void increment(){this->count +=1;};	// 自增加1
		bool isRoot();	// 判断是否是根节点
		bool isLeaf();  // 判断是否是叶节点
		FPNode* getParent(){return this->parent;};	// 获取父节点
		void setParent(FPNode* p){this->parent = p;};	// 设置父节点
		FPNode* getNeighbor(){return this->neighbor; };	// 获取邻居节点，即相同内容的节点
		void setNeighbor(FPNode* n){ this->neighbor = n;};	// 设置邻居节点，即相同内容的节点
		vector<FPNode*> getChildren(){return this->children;}; // 获取孩子节点
};

// ###### FPTree类的构造方法 ######
// FPTree构造方法
FPTree::FPTree(){
	// 在root处新建一个节点
	FPNode* n_new = new FPNode(this,"",0);
	this->root = n_new;
}

// 新添加节点，一行数据
void FPTree::add(vector<string> transaction){
	FPNode* point = this->root; // 从根节点开始
	for(vector<string>::iterator it = transaction.begin(); it != transaction.end(); ++it){
		FPNode* next_point = point->search(*it);	// 看是否已经有节点，若有自增加1即可
		if(next_point){
			next_point->increment(); // 自增加1
		}else{
			 FPNode* n_new = new FPNode(this,*it,1); // 新节点设置数量为1
			 next_point = n_new;
			 point->add(next_point);// 将节点加入point的子节点
			 this->update_route(next_point); // 将新节点加入路径中，更新
		}
		point = next_point; // 指向下一个节点
	}
}

// 更新路径
void FPTree::update_route(FPNode* n){
	itemRoute::iterator it;
	it = this->routes.find(n->getItem()); // 查找经过此节点内容的路径，在这个路径的右边添加相同节点内容的节点
	if(it != this->routes.end()){
		Route r = it->second;
		r.tail->setNeighbor(n);
		r.tail = n;
		this->routes[n->getItem()] = r;
	}else{
		Route r_new;
		r_new.head = n;
		r_new.tail = n;
		this->routes[n->getItem()] = r_new;
	}
}

// 获取每一个节点内容，以及他的节点，放入map中，可能有相同的节点内容
map<string, vector<FPNode*> > FPTree::getItems(){
	std::map<string, vector<FPNode*> > items;
	for(std::map<string,Route>::iterator it=this->routes.begin(); it!=this->routes.end(); ++it){
		items[it->first] = this->getNodes(it->first);
	}
	return items;
}

// 获取此节点内容的所有节点
vector<FPNode*> FPTree::getNodes(string item){
	vector<FPNode*> nodes;
	FPNode* node = this->routes[item].head;
	while(node){
		nodes.push_back(node);
		node = node->getNeighbor();
	}
	return nodes;
}

// 获取路径
vector<FPNode*> collect_path(FPNode* n){
	vector<FPNode*> path;
	while(n && !(n->isRoot()) ){
		path.push_back(n);
		n = n->getParent();
	}
	reverse(path.begin(),path.end());
	return path;
}

// 获取经过此节点内容（多个节点）的前序路径，按节点内容查找
vector<vector<FPNode*> > FPTree::getPrefixPaths(string item){
	vector<FPNode*> nodes = this->getNodes(item);
	vector< vector<FPNode*> > paths;
	for(vector<FPNode*>::iterator it = nodes.begin(); it!=nodes.end(); it++){
		paths.push_back(collect_path(*it)); 
	}
	return paths;
}

// ###### FPNode类的构造方法 ######
// FPNode类的构造方法
FPNode::FPNode(FPTree* tr,string s,unsigned c){
	this->tree =tr;	// 树
	this->item =s;	// 节点内容
	this->count =c;	// 数量
	this->neighbor = NULL;	// 邻居节点初始为NULL
}

// 添加子节点
void FPNode::add(FPNode* child)
{
	// 两个步骤，父节点添加子节点，子节点添加父节点
	this->children.push_back(child);
	child->setParent(this);
}

// 查找节点，按内容查找，返回值为节点或NULL
FPNode* FPNode::search(string i){
	for(vector<FPNode*>::iterator it = this->children.begin(); it != this->children.end(); ++it){
		if((*it)->item == i){
			return(*(it)); 
		}
	}
	return(NULL);
}

// 查找节点，按内容查找，返回值为true or false
bool FPNode::contain(string i){
	for(vector<FPNode*>::iterator it = this->children.begin(); it != this->children.end(); ++it){ 
		if((*it)->item == i){
				return(true);
		}
	}
	return(false);
}

// 判断是否为根节点，内容为空数量为零
bool FPNode::isRoot(){
	if((this->getCount() == 0) && (this->item.empty()) ){
		return true;
	}
	else{
		return false;
	}
}

// 判断是否为叶节点，即看有没有子节点
bool FPNode::isLeaf(){
	if(this->children.size() == 0){
		return true;
	}
	else{
		return false;
	}
}

// ###### 从所有前序路径中生成候选集Tree
// 跟FPTree过程类似，只不过使用了已有路径
FPTree* conditional_tree(vector<vector<FPNode*> > paths){
	FPTree* tree = new FPTree();
	string condition_item;
	vector<string> items;

	for(vector<vector<FPNode*> >::iterator path=paths.begin(); path!=paths.end(); ++path){
		if(condition_item.empty()){
			condition_item = (*path).back()->getItem();
		}

		FPNode* point = tree->getRoot();
		for(vector<FPNode*>::iterator n=(*path).begin(); n!=(*path).end(); ++n){
			FPNode* next_point = point->search((*n)->getItem() );
			
			if(!(next_point)){
				items.push_back((*n)->getItem());
				unsigned count =0;
				if((*n)->getItem() == condition_item)
					count = (*n)->getCount();
				next_point = new FPNode(tree,(*n)->getItem(),count);
				point->add(next_point);
				tree->update_route(next_point);
			}
			point = next_point;
		} 
	}

	vector<vector<FPNode*> > prefix_paths = tree->getPrefixPaths(condition_item);
	
	for(vector<vector<FPNode*> >::iterator path = prefix_paths.begin(); path!=prefix_paths.end(); ++path){
			unsigned count = (*path).back()->getCount();
			for(vector<FPNode*>::iterator it = (*path).begin(); it!= (--(*path).end() ) ;++it){
				(*it)->setCount( (*it)->getCount() + count );
			}
			
	}
	return tree;
}

// 看后缀中有没有item这一项
bool item_in_vector(string item,vector<string> v){
	for(vector<string>::iterator it=v.begin(); it!=v.end(); it++){
		if(*it == item)
			return true;
	}
	return false;
}

// 查找频繁项集，每次都加上后缀suffix
void find_with_suffix(vector<vector<string> >& freqitemsets ,FPTree* tree,vector<string> suffix,int& minimun_support){
	map<string,vector<FPNode*> > items = tree->getItems(); // 获取树的每一个节点内容，放入items中，可能有相同的节点内容

	for(map<string,vector<FPNode*> >::iterator m=items.begin(); m!= items.end(); ++m){
		int support = 0;
		// 求出支持度
		for(vector<FPNode*>::iterator it=m->second.begin(); it!=m->second.end();++it){
			support += (*it)->getCount(); 
		}

		if((support >= minimun_support) && !( item_in_vector(m->first,suffix) )){
			// 有可能有相同的节点内容，所以看后缀中有没有item这一项
			vector<string> found_set = suffix; // 已经查找到的后缀
			found_set.push_back(m->first);		// 加上新找到的
			freqitemsets.push_back(found_set);	// 放入最终的频繁项集中
			FPTree* cond_tree; // 从所有前序路径中生成候选集Tree
			cond_tree = conditional_tree(tree->getPrefixPaths(m->first));
			find_with_suffix(freqitemsets,cond_tree,found_set,minimun_support); // 递归
		}
	}
}

// ###### 挖掘函数
vector<vector<string> > find_frequent_itemsets(vector<vector<string> >& transactions,int minimun_support){
	map<string,int> itemCount;
	for(vector<vector<string> >::iterator transaction=transactions.begin(); transaction!=transactions.end(); ++transaction){
		for(vector<string>::iterator item=(*transaction).begin(); item!=(*transaction).end(); ++item){
			itemCount[*item]+=1;
		} 
	}

	cout << "除去小于最小支持度的项" << endl;
	for(map<string,int>::iterator it=itemCount.begin(); it!= itemCount.end();  ){
		if(it->second < minimun_support){
			itemCount.erase(it++);
		}
		else{
			it++;
		}
	}

	cout << "构造FPtree（原始）" << endl;
	FPTree* fptree = new FPTree();
	
	for(vector<vector<string> >::iterator transaction=transactions.begin(); transaction!=transactions.end(); ++transaction){
		fptree->add((*transaction));
	}
	cout << "构造FPTree完成" << endl;
	vector<string> suffix; // 初始后缀为空的
	vector<vector<string> > freqitemsets; // 最终的频繁项集
	
	cout<< "开始挖掘" << endl;
	find_with_suffix(freqitemsets,fptree, suffix ,minimun_support);
	cout << "挖掘结束，打印结果！" << endl;
	return freqitemsets;
}

int main(){
	int minSup = 0;
	string line;
	ifstream f("retail.dat");
	vector<vector<string> > transactions;
	
	printf("开始读数据\n");
	if(f.is_open())
	{
		while(getline(f,line)) 
		{
			std::vector<string> transaction;
			
			stringstream ss(line);
			string k;
			while(getline(ss,k,' '))
			{
				transaction.push_back(k);
			}
			transactions.push_back(transaction);
		}
		f.close();
	}
	minSup = transactions.size() * MINSUP+1;
	cout<<"最小支持度："<<minSup<<endl;
	// 挖掘函数
	vector<vector<string> > freq_itemsets = find_frequent_itemsets(transactions,minSup);
	// 打印结果
	int count[10] = {0};
	int maxitemcount = 0; 
	for(vector<vector<string> >::iterator it=freq_itemsets.begin();it!=freq_itemsets.end();++it){
		
		int temp = (*it).size();
		if(temp > maxitemcount) maxitemcount = temp;
		count[temp]++;
		
		for(vector<string>::iterator item=(*it).begin() ; item!=(*it).end() ; ++item){
			cout << (*item) << " ";
		}
		cout << endl;
	 
		count[0] += 1;
	}
	for(int i = 1; i <= maxitemcount; i++) 
		cout<<i<<"项集有"<<count[i]<<"项"<<endl;
	cout << "共有频繁项：" << count[0] << endl; 
	return(0);
}