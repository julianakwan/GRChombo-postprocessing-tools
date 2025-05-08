/* GRChombo
 * Copyright 2012 The GRChombo collaboration.
 * Please refer to LICENSE in GRChombo's root directory.
 */

#include "SmallDataIOReader.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>


#ifdef _OPENMP
#include <omp.h>
#endif

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " "
                  << "/path/to/prefix \"surface1 surface2...\"" << std::endl;
        return 0;
    }

    using Clock = std::chrono::steady_clock;

    SmallDataIOReader test_reader;
}
