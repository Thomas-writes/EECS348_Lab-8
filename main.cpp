#include <iostream>
#include <fstream>
#include <sstream>
#include "Matrix.hpp"

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;  // Get the filename from user input

    std::ifstream file(filename);  // Open the user-specified file
    if (!file) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;  // Return with error code if the file cannot be opened
    }

    int N;  // Size of the matrix
    file >> N;  // Read the size of the matrix
    std::cout << "Matrix size: " << N << std::endl;

    // Read the first matrix
    std::vector<std::vector<int>> matrix_data_1(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file >> matrix_data_1[i][j];
        }
    }

    // Read the second matrix
    std::vector<std::vector<int>> matrix_data_2(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file >> matrix_data_2[i][j];
        }
    }
    
    // Create Matrix objects
    Matrix matrix1(matrix_data_1);
    Matrix matrix2(matrix_data_2);

    // Print the matrices
    std::cout << "\nMatrix 1:" << std::endl;
    matrix1.print_matrix();
    
    std::cout << "\nMatrix 2:" << std::endl;
    matrix2.print_matrix();

    // Perform matrix operations (example: addition)
    Matrix result = matrix1 + matrix2;
    std::cout << "\nMatrix 1 + Matrix 2:" << std::endl;
    result.print_matrix();

    result = matrix1 * matrix2;
    std::cout << "\nMatrix 1 * Matrix 2:" << std::endl;
    result.print_matrix();

    int sum_result_main, sum_result_minor;
    sum_result_main = matrix1.sum_diagonal_major();
    sum_result_minor = matrix1.sum_diagonal_minor();
    std::cout << "\nMatrix1 Main Diagonal Sum: " << sum_result_main;
    std::cout << "\nMatrix1 Minor Diagonal Sum: " << sum_result_minor;
    sum_result_main = matrix2.sum_diagonal_major();
    sum_result_minor = matrix2.sum_diagonal_minor();
    std::cout << "\nMatrix2 Main Diagonal Sum: " << sum_result_main;
    std::cout << "\nMatrix2 Minor Diagonal Sum: " << sum_result_minor;

    

    return 0;
}