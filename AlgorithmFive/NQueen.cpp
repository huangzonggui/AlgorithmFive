//Description:����n�ʺ����� ������� ����n<=14  
#include <iostream>  
#include <fstream>  
#include <algorithm>  
#include <functional>  
#include <queue>  

using namespace std;  
ifstream in("input.txt");//ͨ���ļ�����ʺ���������еĸ��� 
ofstream out("output.txt");//����ʺ�ӵ�һ�е���n���е�λ��

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
	int t;//�ѷ���t���ʺ�  
	int *loc;//loc[1:t]  
	int n;//������n���ʺ�  
	bool checkNext(int next);  
	void printQ();  
};  

bool Node::checkNext(int next){  
	int i,j;  
	for (i = 1; i <= t; ++i)  
	{  
		if (loc[i] == next)//���ͬ��  
		{  
			return false;  
		}  
		if (loc[i] - next == t + 1 - i)//��ⷴб�� �в�==�в�  
		{  
			return false;  
		}  
		if (loc[i] - next == i - t - 1)//�����б��  
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
	int n;//n�ʺ�  
	int ansNum;//����n�ʺ��ĸ���  
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
	in>>cases;//��һ����n���ʺ� 
	for(int Case = 1; Case <= cases; ++Case){  
		int n;  
		in>>n;  
		Queen Q(n);  
		Q.ArrangQueen();  
		out<<Case<<"���ʺ���"<<Case<<"��"<<Case<<"�е�������������"<<Q.ansNum<<"�ְڷ�(����������ǻʺ�ӵ�1�е���"<<Case<<"�е��е�λ��)\n"<<endl;//n���ʺ���n��n�е���������ansNum�ְڷ�
	}  
// 	Queen Q(cases);
// 	Q.ArrangQueen();
// 	out<<cases<<""<<Q.ansNum<<endl;
	return 0;  
}