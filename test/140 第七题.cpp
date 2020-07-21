#include<stdio.h>  
#include <time.h> 
#include <stdlib.h> 
#define N 100000 //��������������ĸ��� 
//�������� 
void InsertSort(int* pData,int Count)  
{  
  int iTemp;  
  int iPos;  
  for(int i=1;i<Count;i++)  
  {  
   iTemp = pData[i]; 
   iPos = i-1; 
   while((iPos>=0) && (iTemp<pData[iPos]))  
   {  
    pData[iPos+1] = pData[iPos];  
    iPos--;  
   }  
   pData[iPos+1] = iTemp;  
  }  
} 
//�������� 
void run(int *pData,int left,int right) 
{ 
 int middle,i,j; 
 int t; 
 i=left; 
 j=right; 
 middle=pData[(left+right)/2];   //�ҵ��м�Ԫ�� 
 do{ 
  while((pData[i]<middle)&&(i<right)) 
   i++; 
  while((pData[j]>middle)&&(j>left)) 
   j--; 
  if(i<=j) 
  {            //����Ԫ�� 
   t=pData[i]; 
   pData[i]=pData[j]; 
   pData[j]=t; 
   i++; 
   j--; 
  } 
 }while(i<=j); 
 if(left<j) 
  run(pData,left,j); 
 if(right>i) 
  run(pData,i,right); 
} 
 
void QuickSort(int *pData,int Count) 
{ 
 run(pData,0,Count-1); 
} 
 
int main(void) 
{ 
 clock_t start; 
 int arry[N],a,b,c; 
 int i = 0; 
 srand(time(NULL)); 
 printf("����100000�������~\n"); 
 for(i = 0; i < N; i++) 
  arry[i] = rand(); 
 printf("����������~\n"); 
 start = clock(); 
InsertSort(arry, N); 
 printf("������������ %d ������ʱ�䣺%d\n", N, clock()-start);
 for(i = 0; i < N; i++) 
  arry[i] = rand(); 
 printf("����������~\n"); 
 start = clock(); 
 QuickSort(arry, N); 
 printf("������������ %d ������ʱ�䣺%d\n", N, clock()-start);
  return 0; 
}

