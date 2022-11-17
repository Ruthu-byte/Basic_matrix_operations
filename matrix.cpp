#include <iomanip>
#include <iostream>

#include "arithmetic.h"
#include "matrix.h"

//TO DO: ERROR EXCEPTION!


using namespace std;

Matrix::Matrix(unsigned r, unsigned c): Arithmetic(){
    if(r== 0 || c== 0){
        if( r== 0) rows = 1;
        if(c== 0) cols = 1;
    }
    else{
        rows= r;
        cols= c;
    }

    matrix= new double*[rows];
    for(int i= 0; i< rows; i++){
        matrix[i]= new double[cols];
        for(int j= 0; j< cols; j++){
            matrix[i][j]= 0;
        }
    }
}

Matrix::Matrix(const Matrix& rhs){
    rows= rhs.rows;
    cols= rhs.cols;

    matrix= new double*[rows];
    for(int i= 0; i< rows; i++){
        matrix[i]= new double[cols];
        for(int j= 0; j< cols; j++){
            matrix[i][j]= rhs.matrix[i][j];
        }
    }
}

Matrix::~Matrix(){
    for(int i= 0; i< rows; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
}

void Matrix::print(){
    for(int i= 0; i< rows; i++){
        for(int j= 0; j< cols; j++){
            if(j != cols- 1) cout<< setprecision(3)<< matrix[i][j]<< setw(10);
            else cout<< setprecision(3)<< matrix[i][j];
        }
        if(i != rows- 1) cout<< endl;
        else continue;
    }
    cout<< endl;
}



void Matrix::readFile(istream &infile){
    double data;

    for(int i= 0; i< rows; i++){
        for(int j= 0; j< cols; j++){
            infile >> matrix[i][j];
        }
    }
}

const Matrix& Matrix::operator=(const Matrix& rhs){
    if(this== &rhs) return *this;
    
    for(int i= 0; i< rows; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
    
    rows= rhs.rows;
    cols= rhs.cols;

    matrix= new double*[rows];
    for(int i= 0; i< rows; i++){
        matrix[i]= new double[cols];
        for(int j= 0; j< cols; j++){
            matrix[i][j]= rhs.matrix[i][j];
        }
    }
    return *this;
}

Vector Matrix::operator[](const unsigned r) const{
    if(r>= rows || r< 0) throw "Error: invalid row index";
    Vector rowVector(cols);

    double temp;
    for(int i= 0; i< cols; i++){
        temp= matrix[r][i];
        rowVector(i)= temp; //The overloaded Vector() operator works index-wise
    }
    return rowVector;
}

double& Matrix::operator()(const unsigned r, const unsigned c){
    if(r>= rows || r< 0) throw "Error: invalid row index";
    if(c>= cols || c< 0) throw "Error: invalid column index";

    return matrix[r][c];
}

 unsigned Matrix::getRows() const{
    return rows;
 }

 unsigned Matrix::getCols() const{
    return cols;
 }


//SCALAR OPERATIONS

Matrix Matrix::operator*(const double& rhs){
    Matrix matrx= *this;
    double temp= rhs;

    for(int i= 0; i< rows; i++){
        for(int j= 0; j< cols; j++){
            matrx(i, j)= temp* matrx[i][j];
        }
    }
    return matrx;
}

Matrix operator* (const double& scalar, const Matrix& mat){
    Matrix matrx= mat;
    double temp= scalar;

    for(int i= 0; i< matrx.rows; i++){
        for(int j= 0; j< matrx.cols; j++){
            matrx(i, j)= temp* matrx[i][j];
        }
    }
    return matrx;  
}

Matrix& Matrix::operator*=(const double& rhs){
    double temp= rhs;

    for(int i= 0; i< rows; i++){
        for(int j= 0; j< cols; j++){
            matrix[i][j]= temp* matrix[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator/(const double& rhs){
    if(rhs== 0) throw "Error: division by zero";

    Matrix matrx= *this;
    double temp= rhs;

    for(int i= 0; i< rows; i++){
        for(int j= 0; j< cols; j++){
            matrx(i, j)= matrx[i][j]/ temp;
        }
    }
    return matrx;
}


// Matrix mathematical operations
Matrix Matrix::operator+(const Matrix& rhs){
    if(rows!= rhs.rows || cols!= rhs.cols) throw "Error: adding matrices of different dimensionality";

    for(int i= 0; i< rows; i++){
        for(int j= 0; j< cols; j++){
            matrix[i][j]= matrix[i][j]+ rhs.matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& rhs){
    if(rows!= rhs.rows || cols!= rhs.cols) throw "Error: adding matrices of different dimensionality";

    for(int i= 0; i< rows; i++){
        for(int j= 0; j< cols; j++){
            matrix[i][j]= matrix[i][j]+ rhs.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix& rhs){
    if(rows!= rhs.rows || cols!= rhs.cols) throw "Error: subtractring matrices of different dimensionality";

    for(int i= 0; i< rows; i++){
        for(int j= 0; j< cols; j++){
            matrix[i][j]= matrix[i][j]- rhs.matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& rhs){
    if(rows!= rhs.rows || cols!= rhs.cols) throw "Error: subtractring matrices of different dimensionality";

    for(int i= 0; i< rows; i++){
        for(int j= 0; j< cols; j++){
            matrix[i][j]= matrix[i][j]- rhs.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix& rhs){
    if(cols!= rhs.rows) throw "Error: invalid matrix multiplication";

    Matrix product(rows, rhs.cols);

    for(int anchor= 0; anchor< rows; anchor++){/*Controls the rows of the product matrix*/
        for(int i= 0; i< rhs.cols; i++){ /*controls the columns of the product matrix*/
            for(int j= 0; j< cols; j++){ /*controls the element-wise multiplication*/
                product(anchor, i)+= matrix[anchor][j]* rhs.matrix[j][i];
            }
        }
    }
    return product;
}

Matrix& Matrix::operator*=(const Matrix& rhs){
    if(cols!= rhs.rows) throw "Error: invalid matrix multiplication";

    Matrix product(rows, rhs.cols);

    for(int anchor= 0; anchor< rows; anchor++){/*Controls the rows of the product matrix*/
        for(int i= 0; i< rhs.cols; i++){ /*controls the columns of the product matrix*/
            for(int j= 0; j< cols; j++){ /*controls the element-wise multiplication*/
                product(anchor, i)+= matrix[anchor][j]* rhs.matrix[j][i];
            }
        }
    }

    *this= product;
    return *this;
}

Matrix Matrix::operator^(int pow){
    if(cols!=rows) throw "Error: non-square matrix provided";

    Matrix obj= *this;

    if(pow< 0) throw "Error: negative power is not supported";
    if(pow== 0){
        obj*= 0;
        for(int i= 0; i< rows; i++){
            obj(i, i)= 1;
        }
        *this= obj;
        return *this;
    }

    for(int i= 1; i< pow; i++){
        //cout<< pow<< endl;
        obj *= obj;
    }
    *this= obj;
    return *this;
}

Matrix& Matrix::operator^=(int pow){
    if(cols!=rows) throw "Error: non-square matrix provided";

    Matrix obj= *this;

    if(pow< 0) throw "Error: negative power is not supported";
    if(pow== 0){
        obj*= 0;
        for(int i= 0; i< rows; i++){
            obj(i, i)= 1;
        }
        *this= obj;
        return *this;
    }

    for(int i= 1; i< pow; i++){
        //cout<< pow<< endl;
        obj *= obj;
    }
    *this= obj;
    return *this;
}

Matrix Matrix::operator~(){
    Matrix transposed(cols, rows);

    for(int i= 0; i< rows; i++){
        for(int j= 0; j< cols; j++){
            transposed(j, i)= matrix[i][j];
        }
    }
    return transposed;
}

// Linear equations:
Matrix Matrix::operator|(const Matrix& rhs){
    if(rows!= cols) throw "Error: non-square matrix provided";
    if(rhs.cols!= 1 && rhs.rows!= rows) throw "Error: incorrect augmentation";

    Matrix s= rhs;

    Matrix A= *this;
    A|=s;
    for(int i= rows- 1; i>= 0; i--) {
        for(int j= i+ 1; j< rows; j++){
            s(i,0)= s[i][0]- A[i][j]* s[j][0];

        }
        if(A[i][i]== 0) throw "Error: division by zero";
        s(i, 0)= s[i][0]/ A[i][i];
    }
    return s;
}

Matrix& Matrix::operator|=(Matrix& rhs){
    if(rows!= cols) throw "Error: non-square matrix provided";
    if(rhs.cols!= 1 && rhs.rows!= rows) throw "Error: incorrect augmentation";

    Matrix A= *this;
    Matrix s= rhs;
    double m= 0;
    for(int j= 0; j< rows- 1; j++){/*iterate through Rows*/
        for(int i= j+ 1; i< rows; i++){
            if(A[j][j]== 0) throw "Error: division by zero";

            m= A[i][j]/ A[j][j];          
            for( int k=0; k< rows; k++){
                A(i,k)= A[i][k]- m* A[j][k]; 
            }
            s(i, 0)= s[i][0]- m* s[j][0];
        }
    }
    *this= A;
    rhs= s;
    return *this;
}
/*







*/
//To DO: Keep the returned vector from deleting the same address as the matrix when program terminates