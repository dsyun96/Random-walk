#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define NSTEP 100    // 걸음 수
#define NSIM 10000   // 실행 횟수

int main() {
	int p;  // 매 걸음 후의 위치를 저장
	double sum[NSTEP], sum_sq[NSTEP];  // 매 걸음 후의 위치와 위치 제곱 누적 배열
	FILE *f;
	
	/* 추가로 필요한 변수들을 선언하는 부분 */
	int i, k;

	srand(time(NULL));

	/* sum과 sum_sq 배열의 원소들을 초기화하는 부분 */
	for (i = 0; i < NSTEP; i++)
		sum[i] = sum_sq[i] = 0.0;

	for (i = 0; i < NSIM; i++) {          // 실행 횟수만큼 반복
		p = 0;                        // 걸음을 걷기 전 원점으로 초기화
		for (k = 1; k < NSTEP; k++) { // 걸음 수만큼 반복

			/* 마구잡이 걷기 모의 실험하는 부분 */
			if (rand() % 2 == 0) ++p;
			else --p;

			sum[k] += p;            // k번째 걸음 후의 위치 누적
			sum_sq[k] += p * p;     // k번째 걸음 후의 위치 제곱 누적
		}
	}

	/* sum과 sum_sq 배열로부터 평균, 표준편차를 계산해서 파일에 "걸음수 위치평균 표준편차" 형식으로 한 줄에 세 값을 출력하는 부분 */
	f = fopen("data.txt", "w");
	for (i = 1; i < NSTEP; i++) {
		fprintf(f, "%d %.3f %.3f\n", i, sum[i] / NSIM,
			sqrt((sum_sq[i] - 2 * sum[i] / NSIM * sum[i] + NSIM * (sum[i] / NSIM) * (sum[i] / NSIM)) / NSIM));
	}

	fclose(f);

	return 0;
}
