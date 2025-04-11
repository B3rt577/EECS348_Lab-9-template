#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "matrix.hpp"

// Template function for updating rows with either int or double
template <typename T>
void update_row(std::vector<T>& row, std::size_t col_index, T new_val) {
    if (col_index < row.size()) {
        row[col_index] = new_val;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./matrix <input_file>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cout << "Failed to open file.\n";
        return 1;
    }

    std::size_t N;
    int type_flag;
    file >> N >> type_flag;

    std::vector<std::vector<int>> mat1_data(N, std::vector<int>(N));
    std::vector<std::vector<int>> mat2_data(N, std::vector<int>(N));

    if (type_flag == 0) {
        for (std::size_t i = 0; i < N; ++i)
            for (std::size_t j = 0; j < N; ++j)
                file >> mat1_data[i][j];
        for (std::size_t i = 0; i < N; ++i)
            for (std::size_t j = 0; j < N; ++j)
                file >> mat2_data[i][j];

        Matrix m1(mat1_data);
        Matrix m2(mat2_data);

        std::cout << "Matrix 1:\n";
        m1.print_matrix();

        std::cout << "Matrix 2:\n";
        m2.print_matrix();

        std::cout << "Matrix 1 + Matrix 2:\n";
        Matrix added = m1 + m2;
        added.print_matrix();

        std::cout << "Matrix 1 * Matrix 2:\n";
        Matrix multiplied = m1 * m2;
        multiplied.print_matrix();

        std::cout << "Sum of Matrix 1 major diagonal: " << m1.sum_diagonal_major() << "\n";
        std::cout << "Sum of Matrix 1 minor diagonal: " << m1.sum_diagonal_minor() << "\n\n";

        std::cout << "After swapping rows 0 and 1 of Matrix 1:\n";
        m1.swap_rows(0, 1);
        m1.print_matrix();

        std::cout << "After swapping columns 0 and 1 of Matrix 2:\n";
        m2.swap_cols(0, 1);
        m2.print_matrix();

        std::cout << "Updating Matrix 1 at (2, 3) to 99:\n";
        m1.set_value(2, 3, 99);
        m1.print_matrix();

        std::cout << "Updating row vector directly using template function:\n";
        std::vector<int> example_row = {1, 2, 3, 4};
        update_row(example_row, 2, 99);
        for (int val : example_row) std::cout << val << " ";
        std::cout << "\n";

    } else {
        std::cout << "Double matrix support is not implemented in this version.\n";
    }

    return 0;
}
