#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int T;
class SeqList
{
public:
    T *data;
    int MaxSize; //顺序表最多可以存放的元素个数。
    int last; //顺序表最后一个元素的下标，初始值为-1。
    SeqList(int sz);
    void Input()//首先输入元素的个数，然后顺次输入元素的值。
    {
        int i;
        cin>>last;
        last--;
        for( i=0;i<=last;i++)
        {
            cin>>data[i];
        }
    }
    void Output()//输出线性表的所有元素。
    {
        cout<<"The elements are:"<<endl;
        int i;
        for(i=0;i<=last;i++)
            cout<<data[i]<<endl;
    }
    void Insert(int x, int i )//在线性表中第i个位置插入值为x的元素。
    {
        int j;
        for(j=last;j>=i;j--)
        {
            data[j+1]=data[j];
        }
        data[i]=x;
        last++;
    }
    int Remove ( int x )//从线性表中删除第一个值等于x的元素。
    {

        //x=data[i-1];
        for(int j=0;j<=last;j++)
        {
            if(data[j]==x)
            {
                for(int t=j;t<last;t++)
                {
                    data[t]=data[t+1];
                }
                last--;
            }
        }

    }
};
SeqList::SeqList(int sz)
{
    if(sz>0)
    {
        data = new T[sz];
        MaxSize = sz;
        last = -1;
        if(data == NULL)
        {
            cout<<"error!!"<<endl;
            exit(1);
        }
    }

}
int main()
 {
  SeqList myList(100);
  myList.Input();
  myList.Output ();
  int i;
  for( i=0;i<5;i++)
	 myList.Insert(i+10,i);
  myList.Output ();
  for( i=10;i<15;i++)
     myList.Remove(i);
  myList.Output ();
  return 0;
 }
