/*
 * Name: Megan Svoren
 * Lab Session: Wednesday @ 1:00pm
 * Lab #: Lab07
 * Last modified: 10/30/24
*/
#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 4;

// Matrix class consisting of a 2D array of integer values (the 2D array is the matrix)
class Matrix
{
  public:
    int values[MAX_SIZE][MAX_SIZE];

    // Functions for operator overloading
    Matrix operator+(Matrix x);
    Matrix operator*(Matrix x);
};

// Function to overload the "+" operator for adding two matrices
Matrix Matrix::operator+(Matrix matrix2)
{
  Matrix result; // Creates result matrix
  for (int i = 0; i < MAX_SIZE; i++)
  {
    for (int j = 0; j < MAX_SIZE; j++)
    {
      result.values[i][j] = values[i][j] + matrix2.values[i][j];
    }
  }
  return result;
}

// Function to overload the "*" operator for multiplying two matrices
Matrix Matrix::operator*(Matrix matrix2)
{
  Matrix result; // Creates result matrix
  for (int i = 0; i < MAX_SIZE; i++)
  {
    for (int j = 0; j < MAX_SIZE; j++)
    {
      result.values[i][j] = 0.0;
      for (int k = 0; k < MAX_SIZE; k++)
      {
        result.values[i][j] += values[i][k] * matrix2.values[k][j];
      }
    }
  }
  return result;
}



// Function to read the two matrices from the input file "matrix-data-file.txt"
void read_matrix_from_file(Matrix &matrix_1, Matrix &matrix_2, int &matrix_size)
{
  ifstream file("matrix-data-file.txt");
  file >> matrix_size; // Gets matrix size

  // Fills matrix_1
  for (int i = 0; i < MAX_SIZE; i++)
  {
    for (int j = 0; j < MAX_SIZE; j++)
    {
      file >> matrix_1.values[i][j];
    }
  }

  // Fills matrix_2
  for (int i = 0; i < MAX_SIZE; i++)
  {
    for (int j = 0; j < MAX_SIZE; j++)
    {
      file >> matrix_2.values[i][j];
    }
  }

  file.close();
}

// Function to print one matrix in a user-friendly format to the console
void print_matrix(Matrix matrix, int matrix_size)
{
  for (int i = 0; i < matrix_size; i++)
  {
    for (int j = 0; j < matrix_size; j++)
    {
      cout << matrix.values[i][j] << " ";
    }
    cout << endl;
  }
}

// Function to print two matrices in a user-friendly format to the console
void print_matrix(Matrix matrix_1, Matrix matrix_2, int matrix_size)
{
  // Prints matrix_1
  cout << "Matrix 1:\n";
  for (int i = 0; i < matrix_size; i++)
  {
    for (int j = 0; j < matrix_size; j++)
    {
      cout << matrix_1.values[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  // Prints matrix_2
  cout << "Matrix 2:\n";
  for (int i = 0; i < matrix_size; i++)
  {
    for (int j = 0; j < matrix_size; j++)
    {
      cout << matrix_2.values[i][j] << " ";
    }
    cout << endl;
  }
}

// Function to add two inputted matrices, using the overloaded "+" operator. Stores the result in the "result" matrix
void add_matrices(Matrix matrix_1, Matrix matrix_2, Matrix &result, int matrix_size)
{
  result = matrix_1 + matrix_2;
}

// Function to multiply two inputted matrices, using the overloaded "*" operator. Stores the result in the "result" matrix
void multiply_matrices(Matrix matrix_1, Matrix matrix_2, Matrix &result, int matrix_size)
{
  result = matrix_1 * matrix_2;
}

// Function to get the sum of the primary diagonal and the sum of the second diagonal of the inputted matrix. Prints these results to the console
void get_diagonal_sum(Matrix matrix, int matrix_size) {
  // TODO: Calculate and print the sum of the diagonal elements
  int primary_sum = 0;
  int secondary_sum = 0;
  for (int i = 0; i < matrix_size; i++)
  {
    primary_sum += matrix.values[i][i];
    secondary_sum += matrix.values[i][matrix_size - 1 - i];
  }
  cout << "Sum of Primary Diagonals: " << primary_sum << "\nSum of Secondary Diagonals: " << secondary_sum << endl;
}

// Function to swap the inputted rows of the inputted matrix. Prints the matrix with swapped rows to the console
void swap_matrix_row(Matrix matrix, int matrix_size, int row1, int row2) {
  // TODO: Swap the rows 'row1' and 'row2' in the matrix
  //       Handle invalid row indices
  if (row1 >= 0 && row2 >= 0 && row1 < matrix_size && row2 < matrix_size)
  {
    double temp[matrix_size];
    for (int i = 0; i < matrix_size; i++)
    {
      temp[i] = matrix.values[row1][i];
      matrix.values[row1][i] = matrix.values[row2][i];
      matrix.values[row2][i] = temp[i];
    }
  }
  print_matrix(matrix, matrix_size);
}

// Main function to execute all functions
int main(int argc, char *argv[]) {
  Matrix matrix_1, matrix_2;
  int matrix_size;

  read_matrix_from_file(matrix_1, matrix_2, matrix_size);
  print_matrix(matrix_1, matrix_2, matrix_size);

  Matrix add_result;
  add_matrices(matrix_1, matrix_2, add_result, matrix_size);
  cout << "\nadd_matrices result:" << endl;
  print_matrix(add_result, matrix_size);

  Matrix multiply_result;
  multiply_matrices(matrix_1, matrix_2, multiply_result, matrix_size);
  cout << "\nmultiply_matrices result:" << endl;
  print_matrix(multiply_result, matrix_size);
  
  cout << "\nget matrix diagonal sum" << endl;
  get_diagonal_sum(matrix_1, matrix_size);

  cout << "\nswap matrix rows" << endl;
  swap_matrix_row(matrix_1, matrix_size, 0, 1);

  return 0;
}