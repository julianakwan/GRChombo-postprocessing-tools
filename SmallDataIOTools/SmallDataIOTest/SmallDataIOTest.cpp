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
    // if (argc != 3)
    // {
    //     std::cout << "Usage: " << argv[0] << " "
    //               << "/path/to/prefix \"surface1 surface2...\"" << std::endl;
    //     return 0;
    // }

    // using Clock = std::chrono::steady_clock;

    SmallDataIOReader test_reader;
    test_reader.open("punctures.dat");
    test_reader.determine_file_structure();
    auto file_structure = test_reader.get_file_structure();
    std::cout << "Number of blocks: " << file_structure.num_blocks << std::endl;

    for (int i = 0; i < file_structure.num_blocks; i++)
    {
        std::cout << "Block starts: " << file_structure.block_starts[i]
                  << std::endl;
        std::cout << "Number of columns in Block " << i << ": "
                  << file_structure.num_data_columns[i] << std::endl;
        std::cout << "Number of rows in Block " << i << ": "
                  << file_structure.num_data_rows[i] << std::endl;
        std::cout << "Number of header rows in Block " << i << ": "
                  << file_structure.num_header_rows[i] << std::endl;
	
    }
    auto header = test_reader.get_header_strings(1, 0);

    for (auto it = header.begin(); it != header.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    auto header_data = test_reader.get_data_from_header(1, 0);

    for (auto it = header_data.begin(); it != header_data.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    auto data = test_reader.get_all_data_columns(0);

    for (int ncols = 0; ncols < file_structure.num_data_columns[0]; ++ncols)
    {
        for (auto it = data[ncols].begin(); it != data[ncols].end(); ++it)
        {
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;
    }

    test_reader.close();
}
