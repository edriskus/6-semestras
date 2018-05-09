#include <time.h>
#include <stdio.h>

int main() {
  clock_t t;
	t = clock();
	double r = 1;
	printf("Calculating..\n");
	for(int i = 0; i < 100000; i++) {
    for(int j = 0; j < 100000; j++) {
      r+=r/i+j;
    }
	}
  t = clock() - t;
	printf("%d clicks, %f seconds, %f", t, ((float)t)/CLOCKS_PER_SEC, r);
	return 0;
}
