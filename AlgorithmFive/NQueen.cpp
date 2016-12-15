//Description:经典n皇后问题 广度优先 建议n<=14  
#include <iostream>  
#include <fstream>  
#include <algorithm>  
#include <functional>  
#include <queue>  

using namespace std;  
ifstream in("input.txt");//通过文件输入皇后个数和行列的个数 
ofstream out("output.txt");//输出皇后从第一列到第n列行的位置

class Node{  
public:  
	Node(int n){  
		t = 0;  
		this->n = n;  
		loc = new int[n + 1];  
		for (int i = 0; i<= n; ++i)  
		{  
			loc[i] = 0;  
		}  
	}  
	Node(const Node &other){  
		this->t = other.t;  
		this->n = other.n;  
		this->loc = new int [n + 1];  
		for (int i = 0; i <= n; ++i){  
			this->loc[i] = other.loc[i];  
		}  
	}  
	int t;//已放置t个皇后  
	int *loc;//loc[1:t]  
	int n;//共放置n个皇后  
	bool checkNext(int next);  
	void printQ();  
};  

bool Node::checkNext(int next){  
	int i,j;  
	for (i = 1; i <= t; ++i)  
	{  
		if (loc[i] == next)//检测同行  
		{  
			return false;  
		}  
		if (loc[i] - next == t + 1 - i)//检测反斜线 行差==列差  
		{  
			return false;  
		}  
		if (loc[i] - next == i - t - 1)//检测正斜线  
		{  
			return false;  
		}  
	}  
	return true;  
}  

void Node::printQ(){  
	for (int i = 1; i <= n; ++i)  
	{  
		out<<loc[i]<<" ";  
	}  
	out<<endl;  
}  

class Queen{  
public:  
	int n;//n皇后  
	int ansNum;//对于n皇后解的个数  
	Queen(int n){  
		this->n = n;  
		ansNum = 0;  
	}  
	void ArrangQueen();  
};  

void Queen::ArrangQueen(){  
	queue<Node> Q;  
	Node ini(n);  
	Q.push(ini);  
	while(!Q.empty()){  
		Node father = Q.front();  
		Q.pop();  
		if (father.t == n)  
		{  
			father.printQ();  
			++ansNum;  
		}  
		for (int i = 1; i <= n; ++i)  
		{  
			if (father.checkNext(i))  
			{  
				Node Child(father);  
				++Child.t;  
				Child.loc[Child.t] = i;  
				Q.push(Child);  
			}  
		}  
	}     
}  

int main(){  
	//#define in cin  
	//#define out cout  
	int cases;  
	in>>cases;//第一个是n个皇后 
	for(int Case = 1; Case <= cases; ++Case){  
		int n;  
		in>>n;  
		Queen Q(n);  
		Q.ArrangQueen();  
		out<<Case<<"个皇后在"<<Case<<"行"<<Case<<"列的棋盘上有以上"<<Q.ansNum<<"种摆法(上面的序列是皇后从第1列到第"<<Case<<"列的行的位置)\n"<<endl;//n个皇后在n行n列的棋盘上有ansNum种摆法
	}  
// 	Queen Q(cases);
// 	Q.ArrangQueen();
// 	out<<cases<<""<<Q.ansNum<<endl;
	return 0;  
}