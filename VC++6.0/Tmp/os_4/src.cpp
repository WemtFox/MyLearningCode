#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <malloc.h>

using namespace std;
//状态的宏变量
#define READY 1
#define WORK 2
#define BLOCK -1
#define FINISH -2
#define ListHeade -3

struct PCB {
	int ID;
	int PRIORITY;
	int CPUTIME;
	int ALLTIME;
	int STARTBLOCK;
	int BLOCKTIME;
	int STATE;
	PCB *next;
};
typedef PCB *PCBlist;

PCBlist readylist;
PCBlist blocklist;
PCBlist run;
PCBlist finishlist;

void InitQueue(){
	readylist = (PCBlist)malloc(sizeof(PCB));
	readylist->next = NULL;
	blocklist = (PCBlist)malloc(sizeof(PCB));
	blocklist->next = NULL;
	finishlist = (PCBlist)malloc(sizeof(PCB));
	finishlist->next = NULL;
}

//插队
void Insert(PCBlist list, PCB &pcb){
	PCBlist p,q;
	p = list;
	q = list->next;
	while (q != NULL && (q->PRIORITY)>(pcb.PRIORITY))
	{
		p = q;
		q = q->next;
	}
	pcb.next = q;
	p->next = &pcb;
}

void CreatePs(int id,int priority,int CPUtime,int alltime,int startblock,int blocktime){
	PCBlist p;
	//申请内存，利用传进来的参数初始化PCB的各个属性
	p = (PCBlist)malloc(sizeof(PCB));
	p ->ID = id;	//id
	p ->PRIORITY = priority;	//优先级
	p ->CPUTIME = CPUtime;		//
	p ->ALLTIME = alltime;
	p ->STARTBLOCK = startblock;
	p ->BLOCKTIME = blocktime;
	p ->STATE = READY;	//状态
	p ->next = NULL;
	Insert(readylist, *p);	//插入就绪队列
}

void GetPriority(){
	run = readylist->next;
	if (run)
	{
		readylist->next = run->next;
		run->next = NULL;
	}else{
		readylist->next = NULL;
	}
}

void KillPS(){
	Insert(finishlist, *run);
	run->STATE = FINISH;
	run = NULL;
}

void ResetPriority(){
	run->PRIORITY = ((run->PRIORITY)-3);
	if (run->PRIORITY<0)
	{
		run->PRIORITY = 0;
	}
	PCB *p;
	p = readylist->next;
	while (p != NULL)
	{
		p->PRIORITY++;
		p = p->next;
	}
}


void ResetBlockList(){
	PCBlist q1,q2;
	q2 = blocklist;
	q1 = blocklist->next;
	while (q1 != NULL)
	{
		q1->BLOCKTIME--;
		if (q1->BLOCKTIME == 0)
		{
			q2->next = q1->next;
			Insert(readylist, *q1);
			q1->STATE = READY;
			q1 = q2->next;
		}else{
			q1 = q2->next;
		}	
	}
}

void ExcutePS(){
	run->CPUTIME++;
	run->ALLTIME--;
}

void print(){
	if(run)cout<<"\tRUNNING PROG: P"<<run->ID<<endl;//输出运行的pid
	cout<<"\tREADY_QUEUE: ";
	PCBlist r;
	r=readylist->next;
	while(r!=NULL)
	{
		cout<<"->"<<r->ID;	//输出就绪队列的pid
		r=r->next;
	}
	cout<<endl;
	cout<<"\tBLOCK_QUEUE: ";
	r=blocklist->next;
	while(r!=NULL)
	{
		cout<<"->"<<r->ID;	////输出阻塞队列的pid
		r=r->next;
	}
	cout<<endl<<endl;
	cout<<"========================================================================="<<endl;
	PCBlist P0,P1,P2,P3,P4;
	r=run;
	while(r!=NULL)
	{
		switch(r->ID)
		{
		  case 0: P0=r;break;
		  case 1: P1=r;break;
		  case 2: P2=r;break;
		  case 3: P3=r;break;
		  case 4: P4=r;break;
		}
		r=r->next;
	}
	r=readylist->next;
	while(r!=NULL)
	{
		switch(r->ID){
		  case 0: P0=r;break;
		  case 1: P1=r;break;
		  case 2: P2=r;break;
		  case 3: P3=r;break;
		  case 4: P4=r;break;
		}
		r=r->next;
	}
	r=blocklist->next;
	while(r!=NULL)
	{
		switch(r->ID){
		  case 0: P0=r;break;
		  case 1: P1=r;break;
		  case 2: P2=r;break;
		  case 3: P3=r;break;
		  case 4: P4=r;break;
		}
		r=r->next;
	}
	r=finishlist->next;
	while(r!=NULL)
	{
		switch(r->ID){
		  case 0: P0=r;break;
		  case 1: P1=r;break;
		  case 2: P2=r;break;
		  case 3: P3=r;break;
		  case 4: P4=r;break;
		}
		r=r->next;
	}
	//按规则输出信息
	cout<<"ID"<<'\t'<<'\t'<<P0->ID<<'\t'<<P1->ID<<'\t'<<P2->ID<<'\t'<<P3->ID<<'\t'<<P4->ID<<endl;
	cout<<"PRIORITY"<<'\t'<<P0->PRIORITY<<'\t'<<P1->PRIORITY<<'\t'<<P2->PRIORITY<<'\t'<<P3->PRIORITY<<'\t'<<P4->PRIORITY<<endl;
	cout<<"CPUTIME"<<'\t'<<'\t'<<P0->CPUTIME<<'\t'<<P1->CPUTIME<<'\t'<<P2->CPUTIME<<'\t'<<P3->CPUTIME<<'\t'<<P4->CPUTIME<<endl;
	cout<<"ALLTIME"<<'\t'<<'\t'<<P0->ALLTIME<<'\t'<<P1->ALLTIME<<'\t'<<P2->ALLTIME<<'\t'<<P3->ALLTIME<<'\t'<<P4->ALLTIME<<endl;
	cout<<"STARTBLOCK"<<'\t'<<P0->STARTBLOCK<<'\t'<<P1->STARTBLOCK<<'\t'<<P2->STARTBLOCK<<'\t'<<P3->STARTBLOCK<<'\t'<<P4->STARTBLOCK<<endl;
	cout<<"BLOCKTIME"<<'\t'<<P0->BLOCKTIME<<'\t'<<P1->BLOCKTIME<<'\t'<<P2->BLOCKTIME<<'\t'<<P3->BLOCKTIME<<'\t'<<P4->BLOCKTIME<<endl;
	cout<<"STATE"<<'\t'<<'\t';
	//输出进程状态
	switch(P0->STATE){
		case READY: cout<<"READY"<<'\t';break;
		case WORK: cout<<"WORK"<<'\t';break; 
		case BLOCK: cout<<"BLOCK"<<'\t';break;
		case FINISH:cout<<"FINISH"<<'\t';break;
	}
	switch(P1->STATE){
		case READY: cout<<"READY"<<'\t';break;
		case WORK: cout<<"WORK"<<'\t';break; 
		case BLOCK: cout<<"BLOCK"<<'\t';break;
		case FINISH:cout<<"FINISH"<<'\t';break;
	}
	switch(P2->STATE){
		case READY: cout<<"READY"<<'\t';break;
		case WORK: cout<<"WORK"<<'\t';break; 
		case BLOCK: cout<<"BLOCK"<<'\t';break;
		case FINISH:cout<<"FINISH"<<'\t';break;
	}
	switch(P3->STATE){
		case READY: cout<<"READY"<<'\t';break;
		case WORK: cout<<"WORK"<<'\t';break; 
		case BLOCK: cout<<"BLOCK"<<'\t';break;
		case FINISH:cout<<"FINISH"<<'\t';break;
	}
	switch(P4->STATE){
		case READY: cout<<"READY"<<endl;break;
		case WORK: cout<<"WORK"<<endl;break; 
		case BLOCK: cout<<"BLOCK"<<endl;break;
		case FINISH:cout<<"FINISH"<<endl;break;
	}
	cout<<" "<<endl;
}

void RunPs(){
	GetPriority();
	run->STATE = WORK;
	print();
	while (run != NULL)
	{
		ExcutePS();
		ResetPriority();
		if (run->ALLTIME == 0)
		{
			KillPS();
		}
		if (run && run->STARTBLOCK != -1)
		{
			run->STARTBLOCK--;
		}
		if (blocklist->next != NULL)
		{
			ResetBlockList();
		}
		if (run & run->STARTBLOCK == 0)
		{
			Insert(blocklist, *run);
			run->STATE = BLOCK;
		}else{
			if (run)
			{
				Insert(readylist, *run);
				run->STATE = READY;
			}
		}
		print();
		GetPriority();
		print();
	}
}

int main(){
	InitQueue();
	CreatePs(0,9,0,3,2,3);
	CreatePs(1,38,0,3,-1,0);
	CreatePs(2,30,0,6,-1,0);
	CreatePs(3,29,0,3,-1,0);
	CreatePs(4,0,0,4,-1,0);
	RunPs();
	return 0;	
}