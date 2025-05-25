/* GRChombo
 * Copyright 2012 The GRChombo collaboration.
 * Please refer to LICENSE in GRChombo's root directory.
 */

#include "SmallDataIOReader.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <map>

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

    //    std::cout << "Coords width? " << file_structure.coords_width <<
    //    std::endl; std::cout << "Data width? " << file_structure.data_width <<
    //    std::endl;

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

    auto data = test_reader.get_columns("x_1 x_2", 0);

    for (int ncols = 0; ncols < 2; ++ncols)
    {
        for (auto it = data[ncols].begin(); it != data[ncols].end(); ++it)
        {
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;
    }

    SmallDataIOReader::file_structure_t known_file_structure;
    known_file_structure.num_blocks = 2;
    known_file_structure.block_starts = {0, 401};
    known_file_structure.num_data_rows = {2, 2};
    known_file_structure.num_data_columns = {7, 7};
    known_file_structure.num_header_rows = {2, 2};

    test_reader.close();
}
