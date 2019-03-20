//#include <iostream>
//
//using namespace std;
//int main() {
//	for(int i = 0; i < 2; i++){
//		for(int j = 0; j < 2; j++){
//			for(int k = 0; k < 2; k++){
//				for(int m = 0; m < 2; m++){
//					for(int n = 0; n < 2; n++)
//						cout<<i<<j<<k<<m<<n<<endl;
//				}
//			}
//		}
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main(){
//	int t;
//	cin>>t;
//	cout<<t/3600<<":"<<(t%3600)/60<<":"<<t%60;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main(){
//	int a,b,c;
//	cin>>a>>b>>c;
//	int hi = max(a,max(b,c));
//	while(1){
//		if(hi%a == 0 && hi%b == 0 && hi%c == 0)
//			break;
//		hi++;
//	}
//	cout<<hi;
//	return 0;
//}

//#define LOCAL
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int num[1000001];
//int temp[1000001]; 
//int main(){
//#ifdef LOCAL 
//	freopen("input.txt", "r", stdin);
//#endif
//	int n, m;
//	int l, r, k;
//	cin>>n;
//	for(int i = 0; i < n; i++)
//		cin>>num[i];
//	cin>>m;
//	while(m--){
//		cin>>l>>r>>k;
//		for(int i = l - 1, j= 0; i < r; i++, j++){
//			temp[j] = num[i];
//		}
//		sort(temp,temp+r-l+1);
//		cout<<temp[r-l+1-k]<<endl;
//	}
//	return 0;
//}

#define LOCAL
#include <iostream>
using namespace std;
int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n, num[101];
	while (cin>>n && n != 0) {
		int sum = 0;
		int temp = 0;
		for(int i = 0; i < n; i++)
			cin>>num[i];
		for(int i = 0; i < n; i++){
			if(temp > 0)
				temp += num[i];
			else 
				temp = num[i];
			if(temp > sum)
				sum = temp;
		}
		cout<<sum<<endl;
	}	
	return 0;
}

//#define LOCAL
//#include <iostream>
//using namespace std;
//int main(){
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//#endif
//	
//	return 0;
//}


