#include<stdio.h>
#include "omp.h"
void main()
{
	int psum;
	int tsum;
	double start;
	double end;
	start = omp_get_wtime();
	int thr;
	printf("Enter number of threads...");
	int t;
	scanf("%d",&t);
	printf("\nNumber of threads..%d\n",t);
	#pragma omp parallel private(psum) shared(tsum)
	{
		
		omp_set_num_threads(t);
		psum=0;
		tsum=0;
		int i;
		#pragma omp parallel for
            for( i = 1; i <= 1000; i++)
			{
                psum=psum+i;
            }

        #pragma omp critical
        {
             tsum=tsum+psum;
        }

	}
	end = omp_get_wtime();
	printf("\nSum is... %d",tsum);
	printf("\nWork took %f seconds\n\n\n", end - start);
}

