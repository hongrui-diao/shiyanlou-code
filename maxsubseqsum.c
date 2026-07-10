//二重循环暴力
int maxsubseqsum1(int A[],int N)
{
		int i,j;
		int Thissum,Maxsum=0;
		for(i=0;i<N;i++){
				Thissum=0;
				for (j=i;j<N;j++){
						Thissum+=A[j];
						if(Thissum>Maxsum){
								Maxsum=Thissum;
						}
				}
		}
		return Maxsum;
}
//三重循环暴力
int maxsubseqsum2(int A[],int N)
{
		int i,j,k;
		int THissum,Maxsum=0;
		for (i=0;i<N;i++){
				for(j=i;j<N;j++){
						Thissum=0;
						for(k=i;k<=j;k++){
								Thissum+=A[k];
								if(Thissum>Maxsum){
										Maxsum=THissum;
								}
						}
				}
		}
		return Maxsum;
}
//分而治之
int maxsubseqsum3(int A[], int left, int right)
{
    // 递归终止：只剩一个元素
    if(left == right)
    {
        return A[left];
    }

    int mid = (left + right) / 2;
    // 1. 递归求左半最大值
    int maxLeft = maxsubseqsum3(A, left, mid);
    // 2. 递归求右半最大值
    int maxRight = maxsubeqsum3(A, mid+1, right);

    // 3. 求跨越中点的最大子列和
    // 向左延伸最大值
    int leftSum = 0, maxCrossL = MINF;
    for(int i = mid; i >= left; i--)
    {
        leftSum += A[i];
        if(leftSum > maxCrossL)
            maxCrossL = leftSum;
    }
    // 向右延伸最大值
    int rightSum = 0, maxCrossR = MINF;
    for(int i = mid+1; i <= right; i++)
    {
        rightSum += A[i];
        if(rightSum > maxCrossR)
            maxCrossR = rightSum;
    }
    int maxCross = maxCrossL + maxCrossR;

    // 取三者最大值
    int tempMax = maxLeft > maxRight ? maxLeft : maxRight;
    int allMax = tempMax > maxCross ? tempMax : maxCross;
    return allMax;
}
//在线处理
int maxsubseqsum4(int A[],int N)
{
		int i;
		int Thissum,Maxsum;
		Thissum=Maxsum=0;
		for (i=0;i<N;i++){
				Thissum+=A[i];
				if (Thissum>Maxsum)
						Maxsum=Thissum;
				else if (Thissum<0)
						Thissum=0;
		}
		return Maxsum;
}
