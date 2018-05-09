#include <iostream>
#include <time.h>



int main() {
        clock_t t;
    double r =1;

        t = clock();
    for(int i=0;i<100000;i++)
    for(int j=0;j<100000;j++)
	r+=r/i+j;
    t = clock() - t;

    std::cout << "laikas: "<<((float)t)/(float)CLOCKS_PER_SEC << std::endl;
    std::cout << "Hello World! "<<r << std::endl;
    return 0;
}