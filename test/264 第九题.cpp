#include<iostream>
#include<string>
#include<iomanip>
#include <cstdlib> 
using namespace std;
struct Element
{
	char ch;
	int weight;
	int lchild, rchild, parent;
};
struct HCode
{
	char  data;
	char  code[100];
};
int Select(Element H[], int i)       //ѡ��������С��
{
	int min = 11000;
	int min1;
	for (int k = 0; k<i; k++)
	{
		if (H[k].weight<min && H[k].parent == -1)
		{
			min = H[k].weight;
			min1 = k;
		}
	}
	H[min1].parent = 1;
	return min1;
}
void Reverse(char c[])  	//���ַ�������
{
	int n = 0;
	char temp;
	while (c[n + 1] != '\0')
	{
		n++;
	}
	for (int i = 0; i <= n / 2; i++)
	{
		temp = c[i];
		c[i] = c[n - i];
		c[n - i] = temp;
	}
}
void HuffmanTree(Element H[], int w[], int n)     //�����������
{
	int i1 = 0, i2 = 0;
	for (int i = 0; i<2 * n - 1; i++)
	{
		H[i].lchild = -1;
		H[i].parent = -1;
		H[i].rchild = -1;
	}
	for (int l = 0; l<n; l++)
	{
		H[l].weight = w[l];
	}
	for (int k = n; k<2 * n - 1; k++)
	{
		int i1 = Select(H, k);
		int i2 = Select(H, k);
		if (i1>i2)
		{
			int temp;
			temp = i1;
			i1 = i2;
			i2 = temp;
		}
		H[i1].parent = k;
		H[i2].parent = k;
		H[k].weight = H[i1].weight + H[i2].weight;
		H[k].lchild = i1;
		H[k].rchild = i2;
	}
}
void CreateCodeTable(Element H[], HCode HC[], int n)      //��������������
{
	HC = new HCode[n];
	for (int i = 0; i<n; i++)
	{
		HC[i].data = H[i].ch;
		int ic = i;
		int ip = H[i].parent;
		int k = 0;
		while (ip != -1)
		{
			if (ic == H[ip].lchild)   //���ӱ�'0'
				HC[i].code[k] = '0';
			else
				HC[i].code[k] = '1';  //�Һ��ӱ�'1'
			k++;
			ic = ip;
			ip = H[ic].parent;
		}
		HC[i].code[k] = '\0';
		Reverse(HC[i].code);
	}
	cout << setiosflags(ios::left)
		<< setw(5) << "n"
		<< setw(12) << "weight"
		<< setw(12) << "LChild"
		<< setw(12) << "RChild"
		<< setw(12) << "parent"
		<< setw(12) << "char"
		<< setw(12) << "code"
		<< endl;
	for (int i = 0; i<2 * n - 1; i++)
	{
		if (i<n)
		{
			cout << setiosflags(ios::left)
				<< setw(5) << i
				<< setw(12) << H[i].weight
				<< setw(12) << H[i].lchild
				<< setw(12) << H[i].rchild
				<< setw(12) << H[i].parent
				<< setw(12) << HC[i].data
				<< setw(12) << HC[i].code
				<< endl;
		}
		else
			cout << setiosflags(ios::left)
			<< setw(5) << i
			<< setw(12) << H[i].weight
			<< setw(12) << H[i].lchild
			<< setw(12) << H[i].rchild
			<< setw(12) << H[i].parent
			<< setw(12) << "\\0"
			<< setw(12) << "\\0"
			<< endl;
	}
}
void Decode(Element H[], HCode HC[], int n, char *s)    //���뺯��
{
	cout << "��������Ϊ��";
	int i = 2 * (n - 1);      //�����
	while (*s != '\0')
	{
		if (*s == '0')
			i = H[i].lchild;
		else
			i = H[i].rchild;
		if (H[i].lchild == -1)
		{
			cout << H[i].ch;
			i = 2 * n - 2;
		}
		s++;
	}
	cout << endl;
}
int main()
{
	Element H[20];
	HCode HC[20];
	int n;
	int select;
	while (1)
	{
		system("cls");
		cout << "\t *------------------------------------------*\n";
		cout << "\t *          1������������ַ���             *\n";
		cout << "\t *          2������������                 *\n";
		cout << "\t *          3��������                       *\n";
		cout << "\t *          4�����˳�                       *\n";
		cout << "\t *------------------------------------------*\n";
		cout << "\t ��Ҫ����ı���ǣ�1--4��:";
		cin >> select;
		if (select == 4)  break;
		switch (select) {
		case 1:
		{
			cout << endl;
			cout << "�������ַ�����С��";
			cin >> n;
			cout << endl;
			char s;
			HCode HC[20];
			int e[20];
			for (int t = 0; t < n; t++)
			{
				cout << "�������" << t + 1 << "���ַ���";
				cin >> s;
				H[t].ch = s;
				HC[t].data = H[t].ch;
				cout << "��������ַ���Ȩֵ��";
				cin >> e[t];
				cout << endl;
			}
			HuffmanTree(H, e, n);
			system("pause");
			break;
		}
		case 2:
			CreateCodeTable(H, HC, n);
			system("pause");
			break;
		case 3:
		{
			cout << endl;
			cout << "������������ݣ�";
			char s[200] = { '\0' };
			cin >> s;
			Decode(H, HC, n, s);
			system("pause");
			break;
		}
		default:
			cout << "û�д�ѡ��,������ѡ��" << endl;
		}
	}
}


