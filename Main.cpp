#include <iostream>
#include <chrono>
#include <random>

// lenght and width of matrix
const int N = 5000, M = 5000;

void sum_horizontally(int matrix[N][M]) {
    int sum = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            sum += matrix[i][j];
        }
    }
}

void sum_vertically(int matrix[N][M]) {
    int sum = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            sum += matrix[j][i];
        }
    }
}

int main() {
    // creating matrix
    int matrix[N][M];
    // filling matrix with random numbers
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            matrix[i][j] = rand() % 100000;
            matrix[i][j] += rand() / 100000;
        }
    }
    
    auto time_start_1 = std::chrono::high_resolution_clock::now();
    sum_horizontally(matrix);
    auto time_end_1 = std::chrono::high_resolution_clock::now();

    std::cout << "Horizontally time: " << std::chrono::duration<double, std::milli>(time_end_1 - time_start_1).count() << std::endl;
    
    auto time_start_2 = std::chrono::high_resolution_clock::now();
    sum_vertically(matrix);
    auto time_end_2 = std::chrono::high_resolution_clock::now();

    std::cout << "vertically time " << std::chrono::duration<double, std::milli>(time_start_2 - time_end_2).count() << std::endl;
    
    return 0;
}