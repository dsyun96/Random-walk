#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define NSTEP 100    // ���� ��
#define NSIM 10000   // ���� Ƚ��

int main() {
	int p;  // �� ���� ���� ��ġ�� ����
	double sum[NSTEP], sum_sq[NSTEP];  // �� ���� ���� ��ġ�� ��ġ ���� ���� �迭
	FILE *f;
	
	/* �߰��� �ʿ��� �������� �����ϴ� �κ� */
	int i, k;

	srand(time(NULL));

	/* sum�� sum_sq �迭�� ���ҵ��� �ʱ�ȭ�ϴ� �κ� */
	for (i = 0; i < NSTEP; i++)
		sum[i] = sum_sq[i] = 0.0;

	for (i = 0; i < NSIM; i++) {          // ���� Ƚ����ŭ �ݺ�
		p = 0;                        // ������ �ȱ� �� �������� �ʱ�ȭ
		for (k = 1; k < NSTEP; k++) { // ���� ����ŭ �ݺ�

			/* �������� �ȱ� ���� �����ϴ� �κ� */
			if (rand() % 2 == 0) ++p;
			else --p;

			sum[k] += p;            // k��° ���� ���� ��ġ ����
			sum_sq[k] += p * p;     // k��° ���� ���� ��ġ ���� ����
		}
	}

	/* sum�� sum_sq �迭�κ��� ���, ǥ�������� ����ؼ� ���Ͽ� "������ ��ġ��� ǥ������" �������� �� �ٿ� �� ���� ����ϴ� �κ� */
	f = fopen("data.txt", "w");
	for (i = 1; i < NSTEP; i++) {
		fprintf(f, "%d %.3f %.3f\n", i, sum[i] / NSIM,
			sqrt((sum_sq[i] - 2 * sum[i] / NSIM * sum[i] + NSIM * (sum[i] / NSIM) * (sum[i] / NSIM)) / NSIM));
	}

	fclose(f);

	return 0;
}