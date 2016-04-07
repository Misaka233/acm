
#include <string>
#include <iostream>
#include <malloc.h>
using namespace std;
typedef struct binode
{
	char data;
	struct binode * lchild;
    struct binode * rchild;
}binode, * bitree;
void build(bitree & t,string qian,string zhong)
{
    if(qian.length()==0)
    {
        t=NULL;
        return ;
    }
    char root=qian[0];
    int index=zhong.find(root);
    string l_zhong=zhong.substr(0,index);
    string r_zhong=zhong.substr(index+1);
    int l_length=l_zhong.length();
    int r_length=r_zhong.length();
    string l_qian=qian.substr(1,l_length);
    string r_qian=qian.substr(l_length+1);
    t=(bitree)malloc(sizeof(binode));
    if(t!=NULL)
    {
        t->data=root;
        build(t->lchild,l_qian,l_zhong);
        build(t->rchild,r_qian,r_zhong);
    }
}
void qianxu(bitree & t)
 {
	 if(t!=NULL)
	 {
		 cout<<t->data;
         qianxu(t->lchild);
         qianxu(t->rchild);
	 }
 }


void zhongxu(bitree & t)
 {
	 if(t!=NULL)
	 {

         zhongxu(t->lchild);
		 cout<<t->data;
         zhongxu(t->rchild);
	 }
 }
void hou(bitree &t)
{
    if(t!=NULL)
    {
        hou(t->lchild);
        hou(t->rchild);
        cout<<t->data;
    }
}
int main()
{
    bitree t;
	string qian,zhong;
	cin>>qian>>zhong;
	build(t,qian,zhong);

	qianxu(t);
	cout<<endl;
	zhongxu(t);
	cout<<endl;
	hou(t);
	system("PAUSE");
	return 0;
}
