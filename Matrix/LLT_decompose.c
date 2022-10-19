#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
 
typedef struct {
	int m, n;
	double **v;
} mat_t, *mat;

mat matrix_new(int m, int n)
{
    int i;
	mat x = (mat) malloc(sizeof(mat_t));
	x->v = (double**) malloc(sizeof(double*) * m);
	x->v[0] = (double*) calloc(sizeof(double), m * n);
	for (i = 0; i < m; i++)
		x->v[i] = x->v[0] + n * i;
	x->m = m;
	x->n = n;
	return x;
}

void Vprint(double *p, int num)
{
	int i;
    printf("\n");
    for(i=0;i<num;i++)
   {
        printf("%g\n",*(p+i));
   }
   printf("\n");
}



void matrix_delete(mat m)
{
	free(m->v[0]);
	free(m->v);
	free(m);
}

void matrix_show_A(double **m,int a)
{
    int i,j;
    printf("\n");
	for(i=0; i< a; i++) {
		for (j=0; j< a; j++) {
			printf(" %.8g\t", m[i][j]);
		}
		printf("\n");
	}
}

void trans_show(double **m, int a)
{
    int i,j;
    printf("\n");
    puts("L");
	for(i=0; i< a; i++) {
		for (j=0; j< a; j++) {
			printf(" %.8g\t", m[i][j]);
		}
		printf("\n");
	}
    printf("\n");
	puts("L^T");
    for(i=0; i< a; i++) {
	    for (j=0; j< a; j++) {
		   printf(" %.8g\t", m[j][i]);
		}
		printf("\n");
    }
    printf("\n");
}

void VectorScan(double *A,int a)
{
    int i;
    printf("Please input the column vector of this equation:\n");
    for(i=0;i<a;i++)
    {
       scanf("%lf",A+i);
    }
}

void Matrscan(double **A,int a)
{
	int j,k;
	for(k=0; k<a;k++)
	{
		printf("Please input line %d of matrix A:\n",k+1);
	    for(j=0;j<k+1;j++)
		{
		    scanf("%lf",A[k]+j); //扫描了一个下三角矩阵
		}
    }
    for(k=0;k<a;k++)
    {
        for(j=k;j<a;j++)
        {
            A[k][j]=A[j][k];
        }
    }
}


void LLT_decompose(double **A,double **L,int a)
{
    int i,j,k;
    double sum;
    for(j=0;j<a;j++)
    {
        sum=0;
        for(k=0;k<j;k++)
        {
            sum += L[j][k]*L[j][k];
        }
        L[j][j]= sqrt(A[j][j]-sum);
        for(i=j+1;i<a;i++)
        {
            sum=0;
            for(k=0;k<j;k++)
            {
                sum += L[i][k]*L[j][k]; 
            }
            L[i][j]=(A[i][j]-sum)/L[j][j];
        }
    }
}


void eqsolve(double **L, int a, double *b)
{
    int i,k;
    //step1
    b[0] /= L[0][0];
    for(i=1;i<a;i++)
    {
        for(k=0;k<i;k++)
        {
            b[i]-= L[i][k]*b[k];
        }
        b[i] /= L[i][i];
    }
    //step2
    b[a-1] /= L[a-1][a-1];
    for(i=a-2;i>=0;i--)
    {
        for(k=i+1;k<a;k++)
        {
            b[i]-= L[k][i]*b[k];
        }
        b[i] /= L[i][i];
    }
    puts("x");
    Vprint(b,a);
}

int main()
{
	mat A,L;
    int judge=1,a;
    do
    {
    printf("Please input the dimension of this linear equation:\n");
    scanf("%d",&a);
    A= matrix_new(a,a);
	Matrscan(A->v,a);
    L=matrix_new(a,a);
    
	while(judge==1)
	{
        puts("A");
        matrix_show_A(A->v,a);
        LLT_decompose(A->v,L->v,a);
        trans_show(L->v,a);
        double b[a];
        VectorScan(b,a);
        printf("\n");
        puts("b");
        Vprint(b,a);
        eqsolve(L->v,a,b);
        printf("If you want to modify your column vector, press 1:\n");
	    scanf("%d",&judge);
	    system("cls");
	}
    matrix_delete(A);
    matrix_delete(L);
    printf("If you want to start a new session, press 2:\n");
	scanf("%d",&judge);
    system("cls");
    } while(judge==2);
    system("pause");
	return 0;
}