#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
 
typedef struct {
	int m, n;
	double ** v;
} mat_t, *mat;
 
mat matrix_new(int m, int n)
{
    int i;
	mat x = (mat)malloc(sizeof(mat_t));
	x->v = (double**)malloc(sizeof(double*) *m);
	x->v[0] = (double*)calloc(sizeof(double), m * n);
	for (i = 0; i < m; i++)
		x->v[i] = x->v[0] + n * i;
	x->m = m;
	x->n = n;
	return x;
}
 
void matrix_delete(mat m)
{
	free(m->v[0]);
	free(m->v);
	free(m);
}
 
void matrix_transpose(mat m)
{
    int i,j;
	for (i = 0; i < m->m; i++) {
		for (j = 0; j < i; j++) {
			double t = m->v[i][j];
			m->v[i][j] = m->v[j][i];
			m->v[j][i] = t;
		}
	}
}
 
mat matrix_copy(int n, double** a, int m)
{
    int i,j;
	mat x = matrix_new(n, n);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			x->v[i][j] = a[i][j];
	return x;
}
 
mat matrix_mul(mat x, mat y)
{
    int i,j,k;
	if (x->n != y->m) 
    return 0;
	mat r = matrix_new(x->m, y->n);
	for (i = 0; i < x->m; i++)
		for (j = 0; j < y->n; j++)
			for (k = 0; k < x->n; k++)
				r->v[i][j] += x->v[i][k] * y->v[k][j];
	return r;
}
 
mat matrix_minor(mat x, int d)
{
    int i,j;
	mat m = matrix_new(x->m, x->n);
	for (i = 0; i < d; i++)
		m->v[i][i] = 1;
	for (i = d; i < x->m; i++)
		for (j = d; j < x->n; j++)
			m->v[i][j] = x->v[i][j];
	return m;
}
 
/* c = a + b * s */
double *vmadd(double a[], double b[], double s, double c[], int n)
{
    int i;
	for (i = 0; i < n; i++)
		c[i] = a[i] + s * b[i];
	return c;
}
 
/* m = I - v v^T */
mat vmul(double *v, int n)
{
    int i,j;
	mat x = matrix_new(n, n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			x->v[i][j] = -2 *  v[i] * v[j];
	for (i = 0; i < n; i++)
		x->v[i][i] += 1;
 
	return x;
}
 
/* ||x|| */
double vnorm(double *x, int n)
{
    int i;
	double sum = 0;
	for (i = 0; i < n; i++) 
	{
		sum += x[i] * x[i];
	}
	return sqrt(sum);
}
 
/* y = x / d */
double* vdiv(double x[], double d, double y[], int n)
{
    int i;
	for (i = 0; i < n; i++) 
	{
		y[i] = x[i] / d;
	}
	return y;
}
 
/* take c-th column of m, put in v */
double* mcol(mat m, double *v, int c)
{
    int i;
	for (i = 0; i < m->m; i++)
		v[i] = m->v[i][c];
	return v;
}
 
void matrix_show(mat m,int a,int b)
{
    int i,j;
	for(i=0; i< a; i++) {
		for (j=0; j< b; j++) {
			printf(" %.8g\t", m->v[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
 
void householder(mat m, mat *R, mat *Q)
{
    int i,k;
	mat q[m->m];
	mat z = m, z1;
	for (k = 0; k < m->n && k < m->m - 1; k++)
	{
		double e[m->m], x[m->m], a;
		z1 = matrix_minor(z, k);
		if (z != m) matrix_delete(z);
		z = z1;
 
		mcol(z, x, k);
		a = vnorm(x, m->m);
		if (m->v[k][k] > 0) 
		{
			a = -a;
		}
		for (i = 0; i < m->m; i++)
			e[i] = (i == k) ? 1 : 0;
 
		vmadd(x, e, a, e, m->m);
		vdiv(e, vnorm(e, m->m), e, m->m);
		q[k] = vmul(e, m->m);
		z1 = matrix_mul(q[k], z);
		if (z != m)
		{
		matrix_delete(z);
		}
		z = z1;
	}
	matrix_delete(z);
	*Q = q[0];
	*R = matrix_mul(q[0], m);
	for (i = 1; i < m->n && i < m->m - 1; i++)
	{
		z1 = matrix_mul(q[i], *Q);
		if (i > 1) matrix_delete(*Q);
		*Q = z1;
		matrix_delete(q[i]);
	}
	matrix_delete(q[0]);
	z = matrix_mul(*Q, m);
	matrix_delete(*R);
	*R = z;
	matrix_transpose(*Q);
}

void Matrscan(double **A,int a, int b)
{
	int j,k;
	for(k=0; k<a;k++)
	{
		printf("Please input line %d of matrix A:\n",k+1);
	    for(j=0;j<b;j++)
		{
		    scanf("%lf",A[k]+j);
		}
    }
}

mat matrix_trans(mat x, double q)
{
	int i;
	for (i = 0; i< x->m; i++)
		x->v[i][i] += q;
	return x;
}

mat utimate_solve(mat x)
{
	double a,b;
    a = x->v[0][0]+ x->v[1][1];
	b = (x->v[0][0]*x->v[1][1])-(x->v[0][1]*x->v[1][0]);
    x->v[0][0]=(a+sqrt(a*a-4*b))/2.0;
	x->v[1][1]=(a-sqrt(a*a-4*b))/2.0;
    x->v[0][1]=x->v[1][0]=0;
	return x;
}

void Vprint(double *p, int num)
{
	int i;
    for(i=0; i<num; i++)
    {
        printf("%.8g\n",*(p+i));
    }
    printf("\n");
}


void Eigenvector(mat A, double r, int a)
{
	int i,j,k;
	double q = 0;
	double b[A->m];
	//step1
	for(i=0; i<a;i++)
	{
		A->v[i][i] -= r;
		b[i] = 0.0;
	}
	//step2
	for(k=0;k<a;k++)
    {
        for(i=k+1;i<a;i++)
        {
            q = A->v[i][k]/A->v[k][k];
            for(j=k;j<a;j++)
            {
                A->v[i][j]-= A->v[k][j] * q;
            }
        }
    }
    //step3
    b[a-1] = 1.0;
	

    for(i=a-2;i>=0;i--)
    {
        for(k=i+1;k<a;k++)
        {
            b[i]-= A->v[i][k]*b[k];
        }
        b[i] /= A->v[i][i];
    }
	q = vnorm(b,a);
	for(i=0;i<a;i++)
	{
		b[i] /= q;
	}

	
	printf("The eigenvector corresponding with eigenvalue %.8g is:\n",r);
	Vprint(b,a);
}



int main()
{  
	mat R, Q;
    int a,judge=1,j;
	double c;
	while(judge)
	{
        printf("Please input the dimension of this matrix:\n");
        scanf("%d",&a);
		int e= a;
	    mat x= matrix_new(a,a);
	    Matrscan(x->v,a,a);
		mat A = matrix_copy(e, x->v, e);
		double b[A->m];
	
	    for(j=0; j<=100 & a>=3; j++) 
	    {
			c = x->v[a-1][a-1];
			puts("x"); matrix_show(x,a,a);
			x= matrix_trans(x,-c);
            householder(x, &R, &Q);
		    printf("The %d step of iteration is:\n",j);

	        puts("Q"); matrix_show(Q,a,a);
	        puts("R"); matrix_show(R,a,a);
		    x = matrix_mul(R, Q);
			x = matrix_trans(x,c);

			if(fabs(x->v[a-1][a-2])<=1e-9)
			{
				b[a-1] = x->v[a-1][a-1];
				a--;
				x= matrix_copy(a,x->v,a);
			}

	    };

		puts("x"); matrix_show(x,a,a);
		x = utimate_solve(x);
        puts("x"); matrix_show(x,a,a);

		b[0]=x->v[0][0];
		b[1]=x->v[1][1];

	    printf("The eigvalue of this matrix is:\n\n");
	    Vprint(b,e);

		matrix_delete(x);
	    matrix_delete(R);
	    matrix_delete(Q);

		for(j=0; j<e; j++)
		{
			mat B = matrix_copy(e, A->v, e);
			Eigenvector(B,b[j],e);
			matrix_delete(B);
		}
		matrix_delete(A);
	    printf("Do you want to continue?(1Y0N)\n");
	    scanf("%d",&judge);
	    system("cls");
	}
    system("pause");
	return 0;
}