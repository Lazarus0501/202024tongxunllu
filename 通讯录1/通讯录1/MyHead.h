#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct  NODE
{
	char*Tel;
	int Id;
	char*Name;
	struct NODE*pNext;
}Node;


typedef struct PAGE
{
	int OnePageInfo;		//һҳ��ʾ������  
	int TotalInfo;			//������
	int TotalPage;			//��ҳ��
	int CurrentPage;		//��ǰҳ
}Page;


int g_MenuType;
int g_Key;


Node *GetNode();
void AddNode(Node**ppHead,Node**ppEnd,Node*pNode);
int GetId();
char* GetName();
char* GetTel();
void InitInfo(Node**ppHead,Node**ppEnd,int n);
Page* GetPage(Node*pHead,int n);
void ShowInfo(Node*pHead,Page*pPage);
void TurnPage(Node*pHead,Page*pPage);
char GetKey();
void ShowMenu(Page*pPage);
void Browse(Node*pHead);
Node* GetNodeIn();
char* GetString();
void Query(Node*pHead);
void DeleteInfo(Node**ppHead,Node**ppEnd);
void DeleteNode(Node**ppHead,Node**ppEnd,int Id);
void UpdataInfo(Node*pHead);






