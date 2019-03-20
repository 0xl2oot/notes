#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;

#define MINSUP 0.01    // 最小支持度

vector<vector<int> > sourceItems(100000, vector<int>(100));    // 存储原数据，提前申请一块空间
map<int, int> C1;        // 存储C1，各个项的总数
vector<map<vector<int>, int> > rankFrequentSets(10);    // 存储最后的n项集，提前申请一块空间
int minSup;    // 最小支持数量
int kcount;    // 最大kcount项

void readData() {
    // 读数据
    string str;
    ifstream fin("./retail.dat");
    int line = 1;
    // 从第1个位置存储数据，第0位存行数
    while(getline(fin, str)) {
        stringstream strstream(str);
        int num, j = 1;
        // 每行从第1个位置存数据，第0位存个数
        while(strstream>>num)
            sourceItems[line][j++] = num;
        sourceItems[line++][0] = j-1;    // 读完一行，行数加1
    }
    sourceItems[0][0] = line-1;    // 存储行数
    minSup = (line-1) * MINSUP;    // 最小支持数量
}

map<int, int> findC1() {
    // 读数据从第1行第1个数开始，即sourceItems[1][1]
    for(int i = 1; i <= sourceItems[0][0]; i++) {
        for(int j = 1; j <= sourceItems[i][0]; j++) {
            // C1全局定义的，存储C1，即各个项的总数
            if(C1.find(sourceItems[i][j]) == C1.end())
                C1.insert(make_pair(sourceItems[i][j], 1));
            else
                C1[sourceItems[i][j]]++;
        }
    }
    return C1;
}

map<vector<int>, int> findL1() {
    map<vector<int>, int> L1;
    map<int, int>::iterator it;
    for(it = C1.begin(); it != C1.end(); it++) {
        // 从C1中找频繁项，即数量大于minSup
        if(it->second >= minSup) {
            vector<int> item(2);
            item[0] = 1;
            item[1] = it->first;
            L1.insert(make_pair(item, it->second));
        }
    }
    rankFrequentSets[0] = L1;
    return L1;
}

bool linkable(vector<int> item1, vector<int> item2) {
    bool flag = true;
    // 检查前k-1项是否相同，相同可连接
    for(int i = 1; i < item1[0]; i++) {
        if(item1[i] != item2[i]) {
            flag = false;
            break;
        }
    }
    return flag;
}

vector<vector<int> > link(int k) {
    // 连接操作
    vector<vector<int> > Ckitems(5000, vector<int>(10));     
    // Ck项候选集，提前申请空间，估计MINSUP=0.01时二项候选集有5000以内的数量
    vector<vector<int> > keys(5000, vector<int>(10));        // Lk-1频繁项，vector形式，提前申请空间
    map<vector<int>, int> items = rankFrequentSets[k-2];     // Lk-1频繁项，map形式
    map<vector<int>, int>::iterator item;
    // 将map形式的Lk-1频繁项，存成vector，只需要频繁项，keys[0][0]存储频繁项数量
    int keyscount = 1;
    for(item = items.begin(); item != items.end(); item++) {
        keys[keyscount++] = item->first;
    }
    keys[0][0] = keyscount-1;
    
    if(k == 2) {
        // 生成2项候选集时直接连接即可
        int m = 1;
        for(int i = 1; i <= keys[0][0]; i++) {
            for(int j = i+1; j <= keys[0][0]; j++) {
                Ckitems[m][0] = k;
                Ckitems[m][1] = keys[i][1];
                Ckitems[m++][2] = keys[j][1];
            }
        }
        Ckitems[0][0] = m-1;
    }
    else {
        // 超过2项的候选集需要判断能否“自连接”
        int m = 1;
        for(int i = 1; i <= keys[0][0]; i++) {
            for(int j = i+1; j <= keys[0][0]; j++) {
                if(linkable(keys[i], keys[j])) {
                    Ckitems[m][0] = k;
                    for(int n = 1; n <= k-1; n++) {
                        Ckitems[m][n] = keys[i][n];
                    }
                    Ckitems[m++][k] = keys[j][k-1];
                }
            }
        }
        Ckitems[0][0] = m-1;
    }
    return Ckitems;
}

map<vector<int>, int> obtainFrequentSet(int k) {
    // 剪枝操作，生成频繁项，扫描Ck项候选集里的每一项是否在原数据中出现，出现计数加1，最后判断是否是频繁项
    vector<vector<int> > items = link(k);        // Ck项候选集，vector形式
    map<vector<int>, int> freSet;                // Lk频繁项，map形式
    for(int i = 1; i <= items[0][0]; i++) {
        int count = 0;
        for(int j = 1; j <= sourceItems[0][0]; j++) {
            bool flag = true;
            for(int k = 1; k <= items[i][0]; k++) {
                bool flag1 = false;
                for(int n = 1; n <= sourceItems[j][0]; n++) {
                    if(items[i][k] == sourceItems[j][n]) {
                        flag1 = true;
                        break;
                    }
                }
                if(flag1 == false) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                count++;
        }
        if(count > minSup) {
            freSet.insert(make_pair(items[i], count));
        }
    }

    rankFrequentSets[k-1] = freSet;
    return freSet;
}

void printRankFrequentSets() {
    int all = 0;
    for(int i = 0; i < kcount; i++) {
        map<vector<int>, int> items = rankFrequentSets[i];
        map<vector<int>, int>::iterator item;
        all = all + (int)items.size();
        cout<<i+1<<"项集有"<<items.size()<<"个"<<endl;
        for(item = items.begin(); item != items.end(); item++) {
            cout<<"[";
            vector<int> it = item->first;
            for(int j = 1; j <= it[0]; j++) {
                if(j != 1)
                    cout<<",";
                cout<<it[j];
            }
            cout<<"] = "<<item->second<<endl;
        }
    }
    cout<<"共有"<<all<<"项"<<endl;
}

int main() {
    readData();
    findC1();
    
    int count = 0;
    findL1();
    int k = 2;
    count = 0;
    while(obtainFrequentSet(k++).size() != 0) {
        kcount = k-1;
    }
    
    printRankFrequentSets();
    return 0;
}



