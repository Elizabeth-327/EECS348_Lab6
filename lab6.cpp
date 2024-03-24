#include <fstream>
#include <iostream>

using namespace std;
const int maxsize=100;

void read_matrix(string filename, int matrix1[maxsize][maxsize], int matrix2[maxsize][maxsize], int &size){

    ifstream input_file(filename);

    input_file >> size;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            input_file >> matrix1[i][j];
        }
    }

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            input_file >> matrix2[i][j];
        }
    }

    input_file.close();
}

void print_matrix(int matrix[maxsize][maxsize], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n"; //for readability
}

void add_matrices(int matrix1[maxsize][maxsize], int matrix2[maxsize][maxsize], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << matrix1[i][j] + matrix2[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n"; //for readability
}

void multiply_matrices(int matrix1[maxsize][maxsize], int matrix2[maxsize][maxsize], int size){
    
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            int sum_of_products = 0;
            for (int k = 0; k < size; k++){
                sum_of_products += matrix1[i][k]*matrix2[k][j];
            }
            cout << sum_of_products << " ";
        }
        cout << "\n";
    }
    cout << "\n"; //for readability
}

void subtract_matrices(int matrix1[maxsize][maxsize], int matrix2[maxsize][maxsize], int size){

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << matrix1[i][j] - matrix2[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n"; //for readability
}

//check this!
void update_matrix(int matrix[maxsize][maxsize], int size, int row, int col, int new_value){
    bool valid_inputs = false;
    
    if (row >= 0 && row < size && col >= 0 && col < size){
        matrix[row][col] = new_value;
        valid_inputs = true;
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else{
        cout << "Enter a valid row and column number\n";
    }
    cout << "\n"; //for readability
    
}

void get_max(int matrix[maxsize][maxsize], int size){
    int max_value = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (matrix[i][j] > max_value){
                max_value = matrix[i][j];
            }
        }
    }
    cout << max_value << "\n\n";
}

void transpose(int matrix[maxsize][maxsize], int size){

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << matrix[j][i] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}

int main(){
    int matrix1[maxsize][maxsize];
    int matrix2[maxsize][maxsize];
    int size;

    read_matrix("matrix_input.txt", matrix1, matrix2, size);
    
    print_matrix(matrix1, size);
    
    print_matrix(matrix2, size);

    add_matrices(matrix1, matrix2, size);

    multiply_matrices(matrix1, matrix2, size);

    subtract_matrices(matrix1, matrix2, size);

    update_matrix(matrix1, size, 2, 2, 4);

    get_max(matrix1, size);

    transpose(matrix1, size);

    return 0;
}