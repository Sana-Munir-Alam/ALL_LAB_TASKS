#include <iostream>
using namespace std;

class DynamicMatrix {
    private:
        int** Matrix;
        int Row, Col;
    public:
        DynamicMatrix(int r, int c, int Value = 0) : Row(r), Col(c) {    // Parametrized Constructor
            Matrix = new int*[Row];             // Creating Rows Dynamically
            for (int i = 0; i < Row; i++) {     // Traversing Row
                Matrix[i] = new int[Col];       // Creating Cols Dynamically
                for (int j = 0; j < Col; j++) { // Traversing Cols
                    Matrix[i][j] = Value;       // Initialize Matrix With the Argument Passed Value
                }
            }
        }
        ~DynamicMatrix() { // Destructor
            FreeMatrix();
        }

        /* Creating This Free function so that I dont have to rewrite the freeing of memory in different parts of the code when needed */
        void FreeMatrix() {
            for (int i = 0; i < Row; i++) {
                delete[] Matrix[i];
            }
            delete[] Matrix;
            Matrix = nullptr;
        }

        // Resize Matrix
        void Resize(int NewRow, int NewCol, int Value = 0) {
            int** NewMatrix = new int*[NewRow];         // Creating a New Matrix with User given Rows
            for (int i = 0; i < NewRow; i++) {          // Traversing Row
                NewMatrix[i] = new int[NewCol];         // Creating the number of Colunms given by User
                for (int j = 0; j < NewCol; j++) {
                    if (i < Row && j < Col) {           // Condition Check for Old Matrix Size
                        NewMatrix[i][j] = Matrix[i][j]; // If true copy the old matrix values in new
                    } else {                            // If not true and we have no new/more rows and columns than
                        NewMatrix[i][j] = Value;        // Initialize the new matrix with the new given values
                    }
                }
            }
            FreeMatrix();   // Free old Matrix
            Matrix = NewMatrix; // Update to New Matrix
            Row = NewRow;
            Col = NewCol;
        }

        // Transpose Matrix
        void Transpose() {
            int** TransposedMatrix = new int*[Col];   // Making Now rows with the value of Cols
            for (int i = 0; i < Col; i++) {
                TransposedMatrix[i] = new int[Row];   // Making Now Cols with the value of Rows
                for (int j = 0; j < Row; j++) {
                    TransposedMatrix[i][j] = Matrix[j][i];    // Copy the matrix value in transpose value
                }
            }
            FreeMatrix();   // Free old Matrix
            Matrix = TransposedMatrix;  // Update to new Transpose Matrix
            int temp = Row;
            Row = Col;
            Col = temp;
        }

        // Add 2 to each odd index element (row + col odd index)
        void AddTwoOddIndex() {
            for (int i = 0; i < Row; i++) {
                for (int j = 0; j < Col; j++) {
                    if ((i + j) % 2 == 1) { // odd index position
                        Matrix[i][j] += 2;
                    }
                }
            }
        }

        // Print Matrix
        void Print() const {
            for (int i = 0; i < Row; i++) {
                for (int j = 0; j < Col; j++) {
                    cout << Matrix[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
};

int main() {
    int Row, Col, Value;
    cout << "\n======INITIAL MATRIX======\n\n";
    cout << "Enter The Number of Rows for the Matrix: ";
    cin >> Row;
    cout << "Enter The Number of Cols for the Matrix: ";
    cin >> Col;
    cout << "Enter The Value you want to initilise the Matrix with: ";
    cin >> Value;
    
    cout << "\n\nMatrix: \n";
    DynamicMatrix mat(Row, Col, Value);
    mat.Print();

    cout << "\n======RESIZE MATRIX======\n\n";
    cout << "Enter The NEW Number of Rows for the Matrix: ";
    cin >> Row;
    cout << "Enter The NEW Number of Cols for the Matrix: ";
    cin >> Col;
    cout << "Enter The NEW Value you want to initilise the Matrix [incase this matrix will be bigger than old one]: ";
    cin >> Value;
    cout << "\nResized Matrix:\n";
    mat.Resize(Row, Col, Value);
    mat.Print();

    cout << "\n======TRANSPOSE MATRIX======\n\n";
    cout << "Transposed Matrix:\n";
    mat.Transpose();
    mat.Print();

    cout << "\n======ADD TWO to ODD INDEX ======\n\n";
    cout << "Assuming by odd index you meant the sum of row and col to be odd??\n";
    mat.AddTwoOddIndex();
    mat.Print();

    return 0;
}
