#include "matrix.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"


Matrix::Matrix(size_t N) { // creates a variable that stores a vector of vectors of ints
    data.resize(N, std::vector<int>(N, 0)); // initialized an empty vector of vectors of size N with 0 in all places
}

Matrix::Matrix(std::vector<std::vector<int>> nums) {
    data = nums;
}

Matrix Matrix::operator+(const Matrix &rhs) const {
    int N = get_size();

    Matrix result(N);//create a new emptu matix of size N
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            result.data[i][j] = data[i][j] + rhs.data[i][j];
        }
    }
    return result;
}
    
Matrix Matrix::operator*(const Matrix &rhs) const {
    int N = get_size();

    Matrix result(N); // create a new matrix of size N
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                result.data[i][j] += data[i][k] * rhs.data[k][j];
            }
        }
    }
    return result;
}

void Matrix::set_value(size_t i, size_t j, int n){
    data[i][j] = n;
}

int Matrix::get_value(size_t i, size_t j) const{
    return data[i][j];
}

int Matrix::get_size() const{
    return data.size();
}

int Matrix::sum_diagonal_major() const {
    int sum = 0;
    int N = get_size();
    for (int i = 0; i < N; i++) {
        sum += data[i][i];
    }
    return sum;
};

int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    int N = get_size();
    for (int i = 0; i < N; i++) {
        sum += data[i][N - i - 1];
    }
    return sum;
};
    
void Matrix::swap_rows(std::size_t r1, std::size_t r2){
    std::swap(data[r1], data[r2]);
};
    
void Matrix::swap_cols(std::size_t c1, std::size_t c2){
    int N = get_size();
    for (int i = 0; i < N; i++) {
        std::swap(data[i][c1], data[i][c2]);
    }
};

void Matrix::print_matrix() const {
    for (const auto &row : data) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}
