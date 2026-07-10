#include <stdio.h>
void PrintN(int n);
int main()
{
		int n=0;
		printf("Please input n=:\n");
		scanf("%d",&n);
		PrintN(n);
		return 0;
}
void PrintN(int n)
/*
{
		int i;
		for(i=1;i<=n;i++){
				printf("%d\n",i);
		}
}
*/
{
		if(n){
			PrintN(n-1);
			printf("%d\n",n);
		}
		return;
}
