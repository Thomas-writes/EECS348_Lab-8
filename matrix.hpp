#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>

class Matrix {
public:
    std::vector<std::vector<int>> data; // creates a member variable that stores all the matrix data - not sure why this wasn't included in the code we were given
    Matrix(std::size_t N);
    Matrix(std::vector<std::vector<int>> nums);

    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    void set_value(std::size_t i, std::size_t j, int n);
    int get_value(std::size_t i, std::size_t j) const;
    int get_size() const;
    int sum_diagonal_major() const;
    int sum_diagonal_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void print_matrix() const;
};

#endif // __MATRIX_HPP__