#include <time.h>
#include <stdio.h>
#include <math.h>
#define num_for 1e7
#define N 10
double f1(int n,double a[],double x);
double f2(int n,double a[],double x);
void time_number(int k,int n,double a[],double x);

int main()
{
   int i,m=1;
   double a[N];
   double x=0.0;
   while(m!=0){
   printf("Plaese input x= \n");
   scanf("%lf",&x);

   for(i=0;i<N;i++){
		   a[i]=(double)i;
   }
   time_number(1,N,a,x);
   time_number(2,N,a,x);
   printf("Do you want to try again? Answer 1 for YES,0 for NO.\n");
   scanf("%d",&m);
   }

   return(0);
}

double f1(int n,double a[],double x)
{
	int i;
	double p=a[0];
	for(i=1;i<n;i++){
		p+=a[i]*pow(x,i);
	}
	return p;
}
double f2(int n,double a[],double x)
{
	int i;
	double p=a[n-1];
	for (i=n-2;i>=0;i--){
		p=a[i]+p*x;
	}
	return p;
}
void time_number(int k,int n,double a[],double x)
{  
   int i;
   clock_t start_t ,end_t;
   double total_t;
   if(k==1){
		start_t=clock();
		for(i=0;i<num_for;i++)
				f1(n,a,x);
		end_t=clock();
    }else if(k==2){
			start_t=clock();
			for(i=0;i<num_for;i++)
					f2(n,a,x);
			end_t=clock();
	 }
   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC/num_for;
   printf("CPU time spent:%7.2e\n", total_t  );
}
