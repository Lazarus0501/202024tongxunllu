#include"MyHead.h"

int main()
{
	Node* pHead = NULL;
	Node* pEnd = NULL;
	char c;
	while(1)
	{
		printf("1.�鿴ͨѶ¼\n");
		printf("2.�����Ϣ\n");
		printf("3.��ѯ��Ϣ\n");
		printf("4.ɾ����Ϣ\n");
		printf("5.�޸���Ϣ\n");
		printf("q.�˳�\n");

		c = GetKey();

		switch(c)
		{
		case '1':
			g_MenuType = 1;
			Browse(pHead);
			break;
		case '2':
			AddNode(&pHead,&pEnd,GetNodeIn());
			break;
		case '3':
			g_MenuType = 3;
			Query(pHead);
			break;
		case '4':
			g_MenuType = 4;
			DeleteInfo(&pHead,&pEnd);
			break;
		case '5':
			g_MenuType = 5;
			UpdataInfo(pHead);
			break;
		case 'q':
			return 0;
			break;
		}
	}


	return 0;
}

Node*GetNode()
{
	Node* pNode =(Node*)malloc(sizeof(Node));
	pNode->Id = GetId();
	pNode->Name = GetName();
	pNode->Tel = GetTel();
	pNode->pNext = NULL;

	return pNode;
}

void AddNode(Node**ppHead,Node**ppEnd,Node*pNode)
{
	if(*ppHead == NULL)
	{
		*ppHead = pNode;
	}
	else
	{
		(*ppEnd)->pNext = pNode;
	}
	*ppEnd = pNode;

	return;
}

int GetId()
{
	int static i =1;

	return i++;
}

char* GetName()
{
	char*pName = (char*)malloc(6);
	int i;

	for( i = 0; i<5; i++)
	{
		pName[i] = rand() % 26 +'a';
	}
	pName[i] = '\0';

	return pName;
}



char* GetTel()
{
	char*pTel = (char*)malloc(12);
	int i;
	switch( rand() % 4)
	{
	case 0:
		strcpy_s(pTel,12,"189");
		break;
	case 1:
		strcpy_s(pTel,12,"186");
		break;
	case 2:
		strcpy_s(pTel,12,"130");
		break;
	case 3:
		strcpy_s(pTel,12,"180");
		break;
	}
	for( i = 3; i < 11; i++)
	{
		pTel[i] = rand() % 10 + '\0';
	}

	pTel[i] = '\0';

	return pTel;
}

void InitInfo(Node**ppHead,Node**ppEnd,int n)
{
	int i;
	srand( (unsigned int )time (NULL) );
	for(i = 0; i < n; i++)
		AddNode(ppHead,ppEnd,GetNode());

	return ;
}

Page* GetPage(Node*pHead,int n)
{
	Page* pPage = (Page*)malloc(sizeof(Page));
	pPage->OnePageInfo = n;
	pPage->TotalInfo = 0;
	pPage->TotalPage = 0;
	pPage->CurrentPage = 0;

	//�����������
	while(pHead != NULL)
	{
		pPage->TotalInfo ++;
		pHead = pHead->pNext;
	}

	//�������ҳ��
	if(pPage->TotalInfo % pPage->OnePageInfo == 0 )
		pPage->TotalPage = pPage->TotalInfo / pPage->OnePageInfo;
	else
		pPage->TotalPage = pPage->TotalInfo /pPage->OnePageInfo +1;

	return pPage;
}

void ShowInfo(Node*pHead,Page*pPage)
{
	int nBegin = (pPage->CurrentPage - 1) * pPage->OnePageInfo +1;
	int nEnd = (pPage->CurrentPage) * pPage->OnePageInfo;
	int count = 0;

	//��������
	while(pHead != NULL)
	{
		//��������
		count++;
		//����ڼ�����Χ��
		if(nBegin <= count && count <= nEnd)
		{
			//���
			printf("%d %s %s\n",pHead->Id,pHead->Name,pHead->Tel);
		}
		pHead = pHead->pNext;
	}

	return ;

}

void TurnPage(Node*pHead,Page*pPage)
{
	char c = 's';

	while(1)
	{
		switch (c)
		{
		case 's':
			if(pPage->CurrentPage < pPage->TotalPage)
			{
				pPage->CurrentPage ++;
				ShowInfo(pHead,pPage);
				ShowMenu(pPage);
			}
			else
				printf("�Ѿ������һҳ��\n");
			break;
		case 'w':
			if(pPage->CurrentPage > 1)
			{
				pPage->CurrentPage --;
				ShowInfo(pHead,pPage);
				ShowMenu(pPage);
			}
			else 
				printf("�Ѿ��ǵ�һҳ��\n");
			break;
		case 'b':
			return;
			break;
		case 'c':
			return;
			break;
		case 'd':
			return;
			break;
		case 'u':
			return;
			break;

		default:
			printf("������\n");
			break;
		}
		c = GetKey();
		g_Key = c;
	}
	return;
}

char GetKey()
{
	char c;
	char z;
	int flag = 1;

	while( (c = getchar()) != '\n' || 1 == flag )
	{
		z = c;
		flag = 0;
	}
	
	return z;
}

void ShowMenu(Page*pPage)
{
	switch (g_MenuType)
	{
	case 1:
		printf("��ǰ��%dҳ  ��%dҳ  ��%d��  w��һҳ  s��һҳ  b����\n",pPage->CurrentPage,pPage->TotalPage,pPage->TotalInfo);
		break;
	case 3:
		printf("��ǰ��%dҳ  ��%dҳ  ��%d��  w��һҳ  s��һҳ  c���²�ѯ  b����\n",pPage->CurrentPage,pPage->TotalPage,pPage->TotalInfo);
		break;
	case 4:
		printf("��ǰ��%dҳ  ��%dҳ  ��%d��  w��һҳ  s��һҳ  dɾ����Ϣ  b����\n",pPage->CurrentPage,pPage->TotalPage,pPage->TotalInfo);
		break;
	case 5:
		printf("��ǰ��%dҳ  ��%dҳ  ��%d��  w��һҳ  s��һҳ  u�޸���Ϣ  b����\n",pPage->CurrentPage,pPage->TotalPage,pPage->TotalInfo);
		break;
	default:
		break;
	}

	return;
}



void Browse(Node* pHead)
{
	Page*pPage = GetPage(pHead,10);

	TurnPage(pHead,pPage);

	return;
}

Node* GetNodeIn()
{
	Node*pNode = (Node*)malloc(sizeof(Node));

	pNode->Id = GetId();
	printf("����������");
	pNode->Name = GetString();
	printf("������绰����");
	pNode->Tel = GetString();
	pNode->pNext = NULL;

	return pNode;
}

char* GetString()
{
	int size = 5;
	char*str = (char*)malloc(sizeof(size));
	int count = 0;
	char *newstr = NULL;
	char*pMark = str;
	char c;

	while( (c = getchar()) != '\n' )
	{
		*str = c;
		count++;
		str++;
		if( count + 1 == size)
		{
			*str = '\0';
			size+=5;
			newstr = (char*)malloc(size);
			strcpy_s(newstr,size,pMark);
			free(pMark);
			pMark = newstr;
			str = newstr + count;
		}
	}
	*str = '\0';

	return pMark;
}

void Query(Node*pHead)
{
	char* pKW = NULL;
	Node*pNewHead = NULL;
	Node*pNewEnd = NULL;
	Node*pTemp = NULL;
	Node*pMark = NULL;
	Node*pDel = NULL;
	//1.����ؼ���
	while(1)
	{
		while(1)
		{
			printf("������ؼ��֣�");
			pKW = GetString();
			printf("aȷ�� ��������������");

			if(GetKey() == 'a')
			{
				break;
			}

			else
			{
				free(pKW);
				pKW = NULL;
			}
		}

		//2.ƥ��
		pHead = pMark;
		while( pHead != NULL )
		{
			if( strncmp(pHead->Name,pKW,strlen(pKW)) == 0)
			{
				//����һ���µĽڵ� ���µ�������
				pTemp = (Node*)malloc(sizeof(Node));
				pTemp->Id = pHead->Id;
				pTemp->Name = pHead->Name;
				pTemp->Tel = pHead->Tel;
				pTemp->pNext = NULL;

				AddNode(&pNewHead,&pNewEnd,pTemp);
			}
			pHead = pHead->pNext;
		}
		//3.��ҳ��ʾ
		Browse(pNewHead);
		//4.���ԭ��������
		while(pNewHead != NULL)
		{
			pDel = pNewHead;
			pNewHead = pNewHead->pNext;
			free(pDel);
			pDel = NULL;
		}
		pNewEnd = NULL;

		if('b' == g_Key || 'd' == g_Key || 'u' == g_Key)
		{
			break;
		}
	}

	return;
}

void DeleteNode(Node**ppHead,Node**ppEnd,int Id)
{
	Node*pDel = NULL;
	Node*pMark = *ppHead;

	if( (*ppHead)->Id == Id)
	{
		pDel = *ppHead;
		*ppHead = (*ppHead)->pNext;
		free(pDel->Name);
		free(pDel->Tel);
		free(pDel);
		pDel = NULL;
		return;
	}

	while(pMark->pNext != NULL)
	{
		if(pMark->pNext->Id == Id)
		{
			pDel = pMark->pNext;
			pMark->pNext = pMark->pNext->pNext;
			free(pDel->Name);
			free(pDel->Tel);
			free(pDel);
			pDel = NULL;
			if(pMark->pNext == *ppEnd)
			{
				*ppEnd = pMark;
			}
			return;
		}
		pMark = pMark->pNext;
	}
	return;
}

void DeleteInfo(Node**ppHead,Node**ppEnd)
{
	char*pId = NULL;
	int Id;
	//1.��ѯ
	while(1)
	{
		Query(*ppHead);

		if('b' == g_Key)
		return;

		printf("������Ҫɾ���ı�ţ�\n");

		scanf("%d",&Id);

		DeleteNode(ppHead,ppEnd,Id);

		printf("Y����ɾ�����������˳�\n");

		if( g_Key != 'y' )
		{
			break;
		}

	}
	return;
}


void UpdataInfo(Node*pHead)
{
	char*pId = NULL;
	int Id;
	char*str;
	//1.��ѯ
	Query(pHead);
	if('b' == g_Key)
	{
		return;
	}
		//2.����Ҫ�޸ĵı��
	printf("������Ҫ�޸ĵı��:\n");

	pId = GetString();
	Id = atoi(pId);
	free(pId);
	pId = NULL;
	//3.�޸�
		//�������� ͨ������ҵ�Ҫ�޸ĵĽڵ�
	while(pHead != NULL)
	{
		if(pHead->Id == Id)
		{
			/*printf("����������:\n");
			free(pHead->Name);
			pHead->Name = GetString();
			printf("������绰:\n");
			free(pHead->Tel);
			pHead->Tel = GetString();*/

			printf("����������:\n");
			str = GetString();
			if(strlen(str) > 0)
			{
				free(pHead->Name);
				pHead->Name = str;
			}

			printf("������绰:\n");
			str = GetString();
			if(strlen(str) > 0)
			{
				free(pHead->Tel);
				pHead->Tel = str;
			}

			return;
		}
		pHead = pHead->pNext;
	}

	return;




}

















