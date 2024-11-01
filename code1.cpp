/*
 * Name: Megan Svoren
 * Lab Session: Wednesday @ 1:00pm
 * Lab #: Lab07
 * Last modified: 10/31/24
*/
#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from file into a matrix
  void readFromFile(int start_line);

  // 2. Display a matrix
  void display() const;

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const;

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const;

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const;

  // 6. Swap matrix rows
  void swapRows(int row1, int row2);
};

// Function to read the matrix from the input file "matrix-data-file.txt"
void Matrix::readFromFile(int start_line)
{
  ifstream file("matrix-data-file.txt");
  int temp = 0;
  // Skips the first 0 lines for mat1 and 4 lines for mat2 so the two matrices have the proper values
  for (int i = 0; i < start_line; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      file >> temp;
    }
  }

  // Fills the matrix with the values in the file
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      file >> data[i][j];
    }
  }
  file.close();
}

// Function to print the matrix in a user-friendly format
void Matrix::display() const
{
  // print matrix
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      cout << data[i][j] << " ";
    }
    cout << endl;
  }
}

// Function to overload the "+" operator for adding two matrices
Matrix Matrix::operator+(const Matrix& other) const
{
  Matrix result; // Creates result matrix
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      result.data[i][j] = data[i][j] + other.data[i][j];
    }
  }
  return result;
}

// Function to overload the "*" operator for multiplying two matrices
Matrix Matrix::operator*(const Matrix& other) const
{
  Matrix result; // Creates result matrix
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      result.data[i][j] = 0;
      for (int k = 0; k < SIZE; k++)
      {
        result.data[i][j] += data[i][k] * other.data[k][j];
      }
    }
  }
  return result;
}

// Function to get the total sum of the primary diagonal and second diagonal of the matrix
int Matrix::sumOfDiagonals() const
{
  // sum diags
  int primary_sum = 0;
  int secondary_sum = 0;
  for (int i = 0; i < SIZE; i++)
  {
    primary_sum += data[i][i];
    secondary_sum += data[i][SIZE - 1 - i];
  }
  return primary_sum + secondary_sum;
}

// Function to swap the inputted rows of the matrix
void Matrix::swapRows(int row1, int row2)
{
  // swap rows
  if (row1 >= 0 && row2 >= 0 && row1 < SIZE && row2 < SIZE)
  {
    int temp[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
      temp[i] = data[row1][i];
      data[row1][i] = data[row2][i];
      data[row2][i] = temp[i];
    }
  }
}

// Main function to execute all functions
int main() {
  Matrix mat1;
  mat1.readFromFile(0);
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  mat2.readFromFile(4);
  cout << "\nMatrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "\nSum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "\nProduct of matrices:" << endl;
  product.display();

  cout << "\nSum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "\nMatrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
