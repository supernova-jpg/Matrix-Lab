#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
 
typedef struct {
	int m, n;
	double **v;
} mat_t, *mat;

typedef struct{
    int m;
    double *v;
}vect_t, *vect;


mat matrix_new(int m, int n)
{
    int i;
	mat x = (mat) malloc(sizeof(mat_t)); // x是一个矩阵的指针
	x->v = (double**) malloc(sizeof(double*) * m);
	x->v[0] = (double*) calloc(sizeof(double), m * n); //x[0]是矩阵每一行的指针
	for (i = 0; i < m; i++)
		x->v[i] = x->v[0] + n * i;
	x->m = m;
	x->n = n;
	return x;
}

void Vprint(double *p, int num)
{
	int i;
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

void matrix_show(double **m,int a)
{
    int i,j;
    printf("\n");
	for(i=0; i< a; i++) {
		for (j=0; j< a; j++) {
			printf(" %.8g\t\t", m[i][j]);
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
	    for(j=0;j<a;j++)
		{
		    scanf("%lf",A[k]+j);
		}
    }
}

void Unit_matrix(double **A,int a)
{
    int i,j;
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            A[i][j]=0;
        }
        A[i][i]=1;
    }
}

void LU_decompose(double **A,double **L,int a)
{
    int i,j,k;
    double det=1;
    for(k=0;k<a;k++)
    {
        for(i=k+1;i<a;i++)
        {
            L[i][k]=A[i][k]/A[k][k];
            for(j=k;j<a;j++)
            {
                A[i][j]-= A[k][j] * L[i][k];
            }
        }
    }
    for(k=0;k<a;k++)
    {
        det *= A[k][k];
    }
    printf("\ndet A= %.6g\n\n",det);

}

mat matrix_copy(double** a, int m)
{
    int i,j;
	mat x = matrix_new(m,m);
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
			x->v[i][j] = a[i][j];
	return x;
}

void eqsolve(double **A, double **L, int a, double *b)
{
    int i,k;
    //step1
    for(i=1;i<a;i++)
    {
        for(k=0;k<i;k++)
        {
            b[i]-=L[i][k]*b[k];
        }
    }
    //step2
    b[a-1] /= A[a-1][a-1];
    for(i=a-2;i>=0;i--)
    {
        for(k=i+1;k<a;k++)
        {
            b[i]-= A[i][k]*b[k];
        }
        b[i] /= A[i][i];
    }
    printf("The solution vector of this equation system is:\n");
    Vprint(b,a);
}

int main()
{  
	mat A,L,U;
    int judge=1,a;
    do
    {
        printf("Please input the dimension of this linear equation:\n");
        scanf("%d",&a);
        U= matrix_new(a,a);

	    Matrscan(U->v,a);

        A=matrix_copy(U->v,a);
        L=matrix_new(a,a);
        Unit_matrix(L->v,a);
        LU_decompose(U->v,L->v,a);

	while(judge==1)
	{
        puts("A");
        matrix_show(A->v,a);
        puts("L");
        matrix_show(L->v,a);
        puts("U");
        matrix_show(U->v,a);

        double b[a];

        VectorScan(b,a);
        puts("b1");
        Vprint(b,a);

        eqsolve(U->v,L->v,a,b);
        printf("If you want to modify your column vector, press 1:\n");
	    scanf("%d",&judge);
	    system("cls");
	}
        matrix_delete(A);
        matrix_delete(L);
        printf("If you want to start a new session, press 2:\n");
	    scanf("%d",&judge);
        system("cls");

    }  while(judge==2);
    system("pause");
	return 0;
}