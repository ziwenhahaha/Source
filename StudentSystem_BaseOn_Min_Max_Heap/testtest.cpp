
#include<iostream>
#include<cmath>
#include<iomanip>
#include <conio.h>
#include"studentInfo.h"
using namespace std;

template<class item>
class min_max_heap{
	private:
		const int MIN=1;
		const int MAX=2;

		int tail;

		int getStatus(int x)
		{
			if((int)(log(x)/log(2))%2==0) return MIN;
				else return MAX;
		}
		void pushUP(int index,int status)
		{
			if(index==1||(index/2==1)) return; //������Ǹ��ڵ���ߵ�һ������� 
			if(status==MIN)
			{
				if(heap[index]<heap[index/2/2])
				{
					swap(heap[index],heap[index/2/2]);
					pushUP(index/2/2,MIN);
				}
			}
			if(status==MAX)
			{
				if(heap[index/2/2]<heap[index])
				{
					swap(heap[index/2/2],heap[index]);
					pushUP(index/2/2,MAX);
				}
			}
		}
		bool static minmin(item x,item y) //Ϊ����ָ����� 
		{
			return x<y;
		}
		bool static maxmax(item x,item y) //Ϊ����ָ����� 
		{
			return y<x;
		}
	public:	
		item heap[200050];
		int length;

		void insert(item x) //��������
		{
			if(tail==1){  //����˶��ǿնѣ���ֱ�Ӳ���. 
				heap[tail++]=x;
				length++;
				return;
			}
			heap[tail]=x;
			int now=getStatus(tail);
			if(now==MIN) //�����ǰҪ�������С���. 
			{
				if(heap[tail] < heap[tail/2]){
					pushUP(tail,MIN);
				}else{
					swap(heap[tail],heap[tail/2]);
					pushUP(tail/2,MAX);
				}
			}
			if(now==MAX)
			{
				if(heap[tail]<heap[tail/2])
				{
					swap(heap[tail],heap[tail/2]);
					pushUP(tail/2,MIN);
				}else
				{
					pushUP(tail,MAX);
				}
			}
			tail++;
			length++;
		}
		bool empty()
		{
			return length==0;
		}
		void popMax() //�������
		{
			int index=1;
			for(int i=1;i<=min(length,3);i++)
				if(heap[index]<heap[i])
					index=i;
			item temp=heap[length];
			length--;
			tail--;
			heap[index]=temp;
			if(index*2>length) return;
			pushDown(index,maxmax);
		}
		void pushDown(int root,bool (*cmp)(item a,item b))
		{
			int index=root;
			if(root*2<=length && cmp(heap[root*2],heap[index]))     index=root*2;
			if(root*2+1<=length && cmp(heap[root*2+1],heap[index])) index=root*2+1;
			int lson=root*2;
			int rson=root*2+1;
			if(lson*2<=length && cmp(heap[lson*2],heap[index]))     index=lson*2;
			if(lson*2+1<=length && cmp(heap[lson*2+1],heap[index])) index=lson*2+1;
			
			if(rson*2<=length && cmp(heap[rson*2],heap[index]))     index=rson*2;
			if(rson*2+1<=length && cmp(heap[rson*2+1],heap[index])) index=rson*2+1;
			
			if(index==root) //�����Сֵ�Ѿ��Ǹ�����ô����
				return;
			
			if(index<=root*2+1){ // ���index�Ǹ��ڵ�Ķ��� 
				swap(heap[index],heap[root]); 
			} else {			 // ���index�Ǹ��ڵ������ 
				swap(heap[index],heap[root]);
				int parent=index/2;
				if(cmp(heap[parent],heap[index])){
					swap(heap[parent],heap[index]);
				}
			}
		}
		void popMin() //������Сֵ 
		{
			item temp=heap[length];
			if(length==2){
				heap[1]=temp;
				length--;
				tail--;
				return;
			}
			heap[1]=heap[length];
			length--;
			tail--;
			pushDown(1,minmin);
		}
		item getMax()   //�õ����ֵ
		{
			int ans=1;
			for(int i=1;i<=min(length,3);i++)
				if(heap[ans]<heap[i])
					ans=i;
			return heap[ans];
		}
		item getMin() //�õ���Сֵ
		{
			return heap[1];
		}
};
int  main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		student temp;
		//temp.read();
	} 
 } 

