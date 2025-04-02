#include "matrix.hpp"
#include <vector>
#include <stdexcept>

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

void Matrix::print_matrix() const {
    // print out the matrix
}
