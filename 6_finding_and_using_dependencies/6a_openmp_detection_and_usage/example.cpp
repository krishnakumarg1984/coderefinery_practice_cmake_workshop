#include <omp.h>

#include <cstdlib>
#include <iostream>

int main() {
#pragma omp parallel
    {
        std::cout << "hello from thread " << omp_get_thread_num() << std::endl;
    }

    return EXIT_SUCCESS;
}
