#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>

// all of your function definitions should be in this file now

class Matrix {
public:
    Matrix(std::size_t N) : size(N), data(N, std::vector<int>(N, 0)) {}

    Matrix(std::vector<std::vector<int>> nums) : size(nums.size()), data(nums) {}

    Matrix operator+(const Matrix &rhs) const {
        Matrix result(size);
        for (std::size_t i = 0; i < size; ++i)
            for (std::size_t j = 0; j < size; ++j)
                result.data[i][j] = data[i][j] + rhs.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix &rhs) const {
        Matrix result(size);
        for (std::size_t i = 0; i < size; ++i)
            for (std::size_t j = 0; j < size; ++j)
                for (std::size_t k = 0; k < size; ++k)
                    result.data[i][j] += data[i][k] * rhs.data[k][j];
        return result;
    }

    void set_value(std::size_t i, std::size_t j, int n) {
        data[i][j] = n;
    }

    int get_value(std::size_t i, std::size_t j) const {
        return data[i][j];
    }

    int get_size() const {
        return static_cast<int>(size);
    }

    int sum_diagonal_major() const {
        int sum = 0;
        for (std::size_t i = 0; i < size; ++i)
            sum += data[i][i];
        return sum;
    }

    int sum_diagonal_minor() const {
        int sum = 0;
        for (std::size_t i = 0; i < size; ++i)
            sum += data[i][size - 1 - i];
        return sum;
    }

    void swap_rows(std::size_t r1, std::size_t r2) {
        std::vector<int> temp = data[r1];
        data[r1] = data[r2];
        data[r2] = temp;
    }

    void swap_cols(std::size_t c1, std::size_t c2) {
        for (std::size_t i = 0; i < size; ++i) {
            int temp = data[i][c1];
            data[i][c1] = data[i][c2];
            data[i][c2] = temp;
        }
    }

    void print_matrix() const {
        for (std::size_t i = 0; i < size; ++i) {
            for (std::size_t j = 0; j < size; ++j) {
                // Simple space padding
                if (data[i][j] < 10) {
                    print_char(' ');
                }
                if (data[i][j] < 100) {
                    print_char(' ');
                }
                print_number(data[i][j]);
                print_char(' ');
            }
            print_char('\n');
        }
    }

private:
    std::size_t size;
    std::vector<std::vector<int>> data;

    // Minimal output helper functions to simulate printing without <iostream>
    void print_char(char c) const {
        putchar(c);
    }

    void print_number(int n) const {
        // Only works for non-negative integers, up to 999
        if (n == 0) {
            putchar('0');
            return;
        }

        char buf[4];
        int len = 0;
        while (n > 0 && len < 4) {
            buf[len++] = '0' + (n % 10);
            n /= 10;
        }
        // print digits in reverse order
        for (int i = len - 1; i >= 0; --i) {
            putchar(buf[i]);
        }
    }
};

#endif // __MATRIX_HPP__
