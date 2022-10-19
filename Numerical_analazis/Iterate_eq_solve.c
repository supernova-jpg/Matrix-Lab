#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

enum Bool
{False,True};

typedef struct {
	int m, n;
	double **v;
} mat_t, *mat;

typedef struct{
    int m;
    double *v;
}vect_t, *vect;

vect vector_new(int m)
{
    int i;
    vect x= (vect) malloc(sizeof(vect_t)); //x是一个向量的指针
    x->v = (double*) malloc(sizeof(double*));
    x->m = m;
    return x;
}
 
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

void UnitVect(double *p,int num)
{
    int i;
    for(i=0;i<num;i++)
    {
        *(p+i)=0;
    }
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

void vector_delete(vect m)
{
    free(m->v);
    free(m);
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
	for(i=0; i< a; i++) 
    {
		for (j=0; j< a; j++) 
        {
			printf(" %.10g\t\t", m[i][j]);
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
    printf("\n");
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
    printf("\n");
}

bool Matjudge(double **A, int a)
{
    int i,j;
    double sum;
    bool judge = True;
    for(i=0;i<a;i++)
    {
        sum=0;
        for(j=0;j<a;j++)
        {
            if(i!=j)
            {
                sum+= fabs(A[i][j]);
            }
        }
        if(sum< fabs(A[i][i]))
        {
            judge *= True;
        }
        else
        {
            judge *= False;
            printf("This is not a diagonally-dominant matrix\n,So we can't solve this equation system!\n\n\n");
            break;
        }
        
    }
    return judge;
}


double EQ_Solve(double **A,double *b,double *x, double *y, double w,int a)
{
    int i,j;
    double sum, index;
    index = x[0];
    for(i=0;i<a;i++)
    {
        sum=0;
        for(j=0;j<a;j++)
        {
            if(i!=j)
                sum += A[i][j] * x[j];
        }
        x[i]= w*((b[i]-sum)/A[i][i])+ (1-w)*y[i];
    }
    for(i=0;i<a;i++)
    {
        y[i]=x[i];
    }
    return(fabs(index-x[0]));

}

int main()
{  
	mat A,L,U;
    int judge=1;
    do
    {
        int a;
        double err=16,w;
        printf("Please input the dimension of this linear equation:\n");
        scanf("%d",&a);
        printf("Please input your relaxation parameter:\n");
        scanf("%lf",&w);
        A= matrix_new(a,a);
	    Matrscan(A->v,a);
        puts("A");
        matrix_show(A->v,a);
        if(Matjudge(A->v,a))
        {
            vect b= vector_new(a);
            VectorScan(b->v,a);
            puts("b");
            Vprint(b->v,a);
            vect x= vector_new(a);
            UnitVect(x->v,a);
            vect y= vector_new(a);        
        };
               
        short int i=1;
        while(Matjudge(A->v,a)&& err>=1e-7)
        {
            err = EQ_Solve(A->v,b->v,x->v,y->v,w,a);
            printf("The step %d of iteration\n",i);
            puts("x");
            Vprint(x->v,a);
            i++;
        };

        //vector_delete(b);
        //vector_delete(x);
        matrix_delete(A);
        printf("Do you want to start a new session?\n");
        scanf("%d",&judge);
	    system("cls");
	}while(judge);
    system("pause");
	return 0;
}