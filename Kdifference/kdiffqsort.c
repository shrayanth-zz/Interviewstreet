#include <stdio.h>
#include <math.h>
#define MAXN 100000

void swap(int *a,int *b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

int keypos(int i,int j )
{
   return((i+j) /2);
}

void qsort(int ls[],int m,int n)
{
   int k1,i,j,k;
   if( m < n)
   {
      k = keypos(m,n);
      swap(&ls[m],&ls[k]);
      k1 = ls[m];
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (ls[i] <= k1))
                i++;
         while((j >= m) && (ls[j] > k1))
                j--;
         if( i < j)
                swap(&ls[i],&ls[j]);
      }
      swap(&ls[m],&ls[j]);
      qsort(ls,m,j-1);
      qsort(ls,j+1,n);
   }
}
void read(int ls[],int num)
{
   int i;
   for(i=0;i<num;i++)
       scanf("%d",&ls[i]);
}

void print(int ls[],int num)
{
   int i;
   for(i=0;i<num;i++)
      printf("%d\t",ls[i]);
}


int main()

{

	int N,k,a[MAXN];
	long i,j;
	int count =0;
	scanf("%d %d",&N,&k);

	read (a,N);
	qsort(a,0,N);
	print(a,N);
   
	//if ((a[N]-a[0])<k)
	//	printf("%11d",count);
	//else
	{

		for (i=N;i>=0;i--)
		{

			for (j=i-1;j>=0;j--)

			{

				if ((a[i]-a[j])>k)

					break;
				else if ((a[i]-a[j])==k)

					count++;
			}
		}

		printf("%11d",count);
	}






}

