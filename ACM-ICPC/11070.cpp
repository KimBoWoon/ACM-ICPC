#include<cstdio>
#include<cstdlib>

#pragma warning(disable:4996)

int main()
{
	int n, m, a, b, p, q;
	int no_cases, i, j, k;
	double w;
	double min = 30000, max = -1;


	scanf("%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		double arr[2000][3] = { '0' };
		min = 30000;
		max = -1;
		scanf("%d %d", &n, &m);
		{
			for (j = 0; j < m; j++)
			{
				scanf("%d %d %d %d", &a, &b, &p, &q);
				arr[a][1] += p;
				arr[a][2] += q;
				arr[b][1] += q;
				arr[b][2] += p;
			}

			for (k = 1; k <= n; k++)
			{
				w = ((arr[k][1])*(arr[k][1])) * 1000 / (((arr[k][1])*(arr[k][1])) + ((arr[k][2])*(arr[k][2])));

				if (arr[k][1] == 0 && arr[k][2] == 0)
					w = 0;
				if (w < min)
					min = w;
				if (w > max)
					max = w;
			}
			printf("%d\n%d\n", (int)max, (int)min);
		}
	}
}