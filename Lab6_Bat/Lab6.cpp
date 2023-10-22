#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;

void readMatrixFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& N) {
    std::ifstream inputFile("matrix_input.txt");
    if (inputFile.is_open()) {
        inputFile >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                inputFile >> matrixA[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                inputFile >> matrixB[i][j];
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Failed to open the input file." << std::endl;
        exit(1);
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

int main() {
    int N;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    readMatrixFromFile(matrixA, matrixB, N);

    std::cout << "Naran Bat" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, N);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, N);

    addMatrices(matrixA, matrixB, result, N);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(result, N);

    multiplyMatrices(matrixA, matrixB, result, N);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(result, N);

    subtractMatrices(matrixA, matrixB, result, N);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(result, N);

    return 0;
}
