/*题目：用c++实现链表的创建、插入节点、删除节点、遍历链表、查询链表功能
日期：2017年7月15日
作者：信1606 20163534 吕新
修改备注;修改于2017 7月20日
*/
#pragma once
#include<iostream>
using namespace std;

class  LinkedList
{
	int num;
	LinkedList * next;

public:
	 LinkedList(void);
	 ~ LinkedList(void);
	 LinkedList * creatlist();                    //链表的创建
	 LinkedList * charu(int n, LinkedList * head);//插入节点
	 LinkedList * shanchu( LinkedList * head);    //删除节点
	 void bianli( LinkedList *head);              //遍历链表
	 LinkedList * chaxun( LinkedList *head);      //查询链表
};

 LinkedList:: LinkedList(void)
 {
}


 LinkedList::~ LinkedList(void)
 {
}

 LinkedList *  LinkedList::creatlist()
 {
	 LinkedList *phead=NULL;
	 LinkedList *pend=NULL;
	 LinkedList *ps=NULL;

	cout<<"请输入数字（输入0时结束）"<<endl;
	ps=new  LinkedList;
	cin>>ps->num;

	while(ps->num!=0)
	{
	  if(phead==NULL)
		 phead=ps;
	  else
	     pend->next=ps;
	     pend=ps;
	     ps=new  LinkedList;
         cin>>ps->num;
	}
	pend->next=NULL;
	delete ps;
	return phead;
}

 LinkedList *  LinkedList::charu(int n, LinkedList * head)
{
	 LinkedList *p=head;            //指向插入点的后节点
	 LinkedList *q=NULL;            //指向插入点的前节点
	 LinkedList *r=NULL;            //指向新建节点

	cout<<"要插入的数值:"<<endl;
	cin>>n; 

	while((p!=NULL)&&(p->num<n))
	 {
		q=p;                        //后节点变为前节点
		p=p->next;
     }
	r=new  LinkedList;

	if(r==NULL)
	 {
		cout<<"不能插入"<<endl;
	    return head;
	 }
    r->num=n;

	if(q==NULL)
	 {
		r->next=p;
		return r;
	 }
	else
	 {
		q->next=r;
		r->next=p;
		return head;
	 }
}

 LinkedList *  LinkedList::shanchu( LinkedList *head)
{
	int n;
	 LinkedList *p=head;            //指向当前节点
	 LinkedList *q=NULL;            //指向当前节点的前节点
	cout<<"请输入要删除的数值:"<<endl;
	cin>>n;

	while(p&&p->num!=n)
	 {
		q=p;
		p=p->next;
	 }

	if(p==NULL)
	 {
		cout<<"不能找到这个数值"<<endl;
		return head;
	 }

	if(q==NULL)                     //删除链首节点
		head=head->next;
	else
		q->next=p->next;
	delete p;
	return head;
}

void  LinkedList::bianli( LinkedList *head)
{
	cout<<"输出链表中的数值为:"<<endl;
	 LinkedList *p=head;

	while(p)
	{
		cout<<p->num;

		if(p->next)
		  cout<<" -> ";
		  p=p->next;
	}
	cout<<endl;
}

 LinkedList *  LinkedList::chaxun( LinkedList *head)
{
	int n;
	LinkedList *p=head;
	cout<<"请输入要查询的数值:"<<endl;
	cin>>n;

	while(p)
	{
		if(p->num==n)
		 {
			cout<<"在此链表中找到了这个数值"<<endl;
			return p;
		 }
		p=p->next;
	}
	cout<<"在此链表中不能找到这个数值"<<endl;
	return NULL;
}
		
 void main()
{
	 LinkedList * h=NULL;
	 LinkedList l;
	 int m,a=1;
     LinkedList z;

	do
	 {
		cout<<"   输入1-5选择您要操作的内容      "<<endl;
		cout<<"   1创建链表                      "<<endl;
		cout<<"   2插入节点（数字）              "<<endl;
		cout<<"   3删除节点（数字）              "<<endl;
		cout<<"   4遍历节点                      "<<endl;
		cout<<"   5查询节点                      "<<endl;
		cout<<"   请选择                         "<<endl;
		cin>>m;
		switch(m)
		{
		  case 1:h=h->creatlist();break;
		  case 2:h=h->charu(3,h);break;
		  case 3:h=h->shanchu(h);break;
		  case 4:h->bianli(h);break;
		  case 5:l.chaxun(h);break;
		  case 6:a=0;
        }
	 }
while(a);
}