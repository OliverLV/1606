/*��Ŀ����c++ʵ������Ĵ���������ڵ㡢ɾ���ڵ㡢����������ѯ������
���ڣ�2017��7��15��
���ߣ���1606 20163534 ����
�޸ı�ע;�޸���2017 7��20��
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
	 LinkedList * creatlist();                    //����Ĵ���
	 LinkedList * charu(int n, LinkedList * head);//����ڵ�
	 LinkedList * shanchu( LinkedList * head);    //ɾ���ڵ�
	 void bianli( LinkedList *head);              //��������
	 LinkedList * chaxun( LinkedList *head);      //��ѯ����
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

	cout<<"���������֣�����0ʱ������"<<endl;
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
	 LinkedList *p=head;            //ָ������ĺ�ڵ�
	 LinkedList *q=NULL;            //ָ�������ǰ�ڵ�
	 LinkedList *r=NULL;            //ָ���½��ڵ�

	cout<<"Ҫ�������ֵ:"<<endl;
	cin>>n; 

	while((p!=NULL)&&(p->num<n))
	 {
		q=p;                        //��ڵ��Ϊǰ�ڵ�
		p=p->next;
     }
	r=new  LinkedList;

	if(r==NULL)
	 {
		cout<<"���ܲ���"<<endl;
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
	 LinkedList *p=head;            //ָ��ǰ�ڵ�
	 LinkedList *q=NULL;            //ָ��ǰ�ڵ��ǰ�ڵ�
	cout<<"������Ҫɾ������ֵ:"<<endl;
	cin>>n;

	while(p&&p->num!=n)
	 {
		q=p;
		p=p->next;
	 }

	if(p==NULL)
	 {
		cout<<"�����ҵ������ֵ"<<endl;
		return head;
	 }

	if(q==NULL)                     //ɾ�����׽ڵ�
		head=head->next;
	else
		q->next=p->next;
	delete p;
	return head;
}

void  LinkedList::bianli( LinkedList *head)
{
	cout<<"��������е���ֵΪ:"<<endl;
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
	cout<<"������Ҫ��ѯ����ֵ:"<<endl;
	cin>>n;

	while(p)
	{
		if(p->num==n)
		 {
			cout<<"�ڴ��������ҵ��������ֵ"<<endl;
			return p;
		 }
		p=p->next;
	}
	cout<<"�ڴ������в����ҵ������ֵ"<<endl;
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
		cout<<"   ����1-5ѡ����Ҫ����������      "<<endl;
		cout<<"   1��������                      "<<endl;
		cout<<"   2����ڵ㣨���֣�              "<<endl;
		cout<<"   3ɾ���ڵ㣨���֣�              "<<endl;
		cout<<"   4�����ڵ�                      "<<endl;
		cout<<"   5��ѯ�ڵ�                      "<<endl;
		cout<<"   ��ѡ��                         "<<endl;
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