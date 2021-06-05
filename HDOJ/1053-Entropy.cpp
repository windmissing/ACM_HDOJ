#include <iostream>   
#include <iomanip>
#include <queue>   
#include <string>   
using namespace std;  ;  

int main(){ 
	string s;
	while(cin>>s){  
		if(s == "END")break;  

		int pl[27],len;
		//统计频度    
		memset(pl,0,sizeof pl);  
		len=s.length();  
		for(int i=0;i<len;i++){  
			if(s[i]=='_')pl[0]++;  
			else pl[s[i]-'A'+1]++;  
		}  
		//判断是否单一字符   
		bool yes=0;   
		for(int i=0;i<27;i++){  
			if(pl[i]==len){  
				cout<<len*8<<' '<<len<<' '<<8.0<<endl;
				yes=1;  
				break;    
			}     
		}  
		if(yes)continue;  

		//使用优先队列统计HUFFMAN编码    
		priority_queue<int,vector<int>,greater<int> > q;   
		for(int i=0;i<27;i++)
			if(pl[i]!=0)
				q.push(pl[i]);  
		int ans=0,a,b; 
		while(1){  
			a=q.top();q.pop();  
			if(q.empty())break;  
			b=q.top();q.pop();  
			ans+=a+b;  
			q.push(a+b);  
		}   
		cout<<len*8<<' '<<ans<<' ';
		cout<<setiosflags(ios::fixed)<<setprecision(1)<<(len*8.0/ans)<<endl;
	}     
	return 0;     
}
 


 
 
