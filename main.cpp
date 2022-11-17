#include <iostream>
#include "matrix.h"
#include "vector.h"
#include <fstream>
//#include <string>

using namespace std;

/*static void print(Arithmetic *mat) {
    mat->print();
    cout << endl;
}

static void readFile(istream &infile, Arithmetic *mat) {
    mat->readFile(infile);
}

//
static void task1() {
    ifstream infile("example_input.txt");
    // The test code below assumes that you have implemented all Task 1 functionality

    // 1. Test constructor:
    cout << "Constructors: " << endl;

    Matrix *m1 = new Matrix(3, 4);
    print(m1);

    Vector *v1 = new Vector(7);
    v1->print();
    print(v1);


    // read file.
    readFile(infile, v1);
    v1->print();

    cout << "vector  Test" << endl;
    Vector v2(3);

    cout << v2[0] << endl;

    readFile(infile, m1);
    m1->print();

    // Test assignment operator:
    Matrix *m2 = new Matrix(1, 4);
    print(m2);
    m2 = m1; // assignment
    print(m2);

    // Test getters
    cout << "Getters: " << endl;
    cout << m1->getRows() << endl;
    cout << m2->getCols() << endl;
    cout << v1->getSize() << endl;

//    // Test [][]
    cout << "Test [][]: " << endl;
    try {
        Matrix m4(3, 3);
        m4.readFile(infile);
        cout << m4[0][2] << endl;
        m4(0,2) = 5;
        cout << m4[0][2] << endl;
        m4(5,2) = 5;
    } catch (const char *error) {
        cout << error << endl;
    }

    infile.close();
}


static void task2() {

    // Matrix Arithmeitc:
    // The test code below assumes that you have implemented all Task 2 functionality.
    // ------------------------------------------------------------------------------
    // NOTE: The examples below are illustrative, NOT exhaustive. You must extend the
    // provided code with your own tests. Trigger every exception, make sure all corner
    // cases work. Test all operators!
    ifstream infile("example_input.txt");

    cout << "Matrix arithmetic" << endl;
    Matrix *m1 = new Matrix(2, 6);
    m1->readFile(infile);
    m1->print();
    // Scalar * matrix
    cout << "Matrix Multiplication by scalar:" << endl;
    m1->operator*(3.5).print();
    m1->operator*=(2);
    m1->print();

    cout << "Vector Multiplication by scalar:" << endl;
    Vector *vec1 = new Vector(5);
    vec1->readFile(infile);
    vec1->print();

    vec1->operator*(3.5).print();
    vec1->operator*=(2);
    vec1->print();


    // Scalar / matrix
    cout << "Division by scalar:" << endl;
    try {
        m1->operator/(7.2).print();
        m1->operator/(0).print();
    } // should trigger exception
    catch(const char * err) { cout << err << endl; }

    infile.close();
}

static void task3() {
    //////////////////////////////////
    // The rest is linear equations //
    //////////////////////////////////
    ifstream infile("task3Input.txt");

    cout << "Reading matrices..." << endl;
    Matrix system(3,3), augmented(3,1);
    system.readFile(infile);
    augmented.readFile(infile);

    Matrix A = system;
    Matrix b = augmented;

    A.print();
    b.print();

    cout << "Reducing to upper-triangular form:" << endl;

    A |= b;

    A.print();
    b.print();

    cout << "Solving the system:" << endl;
    Matrix c = A|b;
    c.print();

    cout << "Reducing to upper-triangular form AND solving the system:" << endl;
    c = system|augmented;
    c.print();

    infile.close();
}
*/
int main() {
//   task1();
//    task2();
/**   try{
        task3();
    }
    catch(const char* err){
        cout<< err<< endl;
    }*/
    Vector vector(5);
    Vector vector2(5);

    for(int i= 0; i< 5; i++){
        vector(i)= 4;
        vector2(i)= 2* i+ 1;
    }

    vector.print(); cout<< endl;
    vector2.print(); cout<< endl;
    vector= vector- vector2;
    vector.print(); cout<< endl;
    
    return 0;
}


/*int main(){
    Matrix matrix(3, 4);
    Matrix mtrx(2,4);
    matrix.print();
    cout<<endl<<endl;
    Vector vector(5);
    Vector vtr(3);
    vector.print();

    cout<< endl<< endl;

    ifstream inputfile;
    inputfile.open("example_input.txt");

    cout<<"testin this assign operator"<< endl;
    mtrx.readFile(inputfile);
    mtrx.print();
    cout<< endl<< endl;
    matrix= mtrx;
    matrix.print();
    cout<< endl<< endl;

    cout<< "Testing out this vector assign operator overload"<< endl;
    vtr.readFile(inputfile);
    vtr.print();
    cout<< endl<< endl;
    vector.print();

    cout<< endl<< endl;
    vector= vtr;
    vector.print();
    cout<< endl;
    inputfile.close();

    cout<< endl<< endl;
    cout<< vector[2]<< endl;
    vector(1)= 500;
    vector.print();
    cout<< endl<< endl;


    cout<< matrix[0][0]<< endl;

    cout<< endl<< "checking out the ()() overload"<< endl;
    matrix(1, 1)= 12.45;
    matrix.print();
    cout<< endl<< endl;

    cout<< "Let's get ssom"<< endl;
    cout<< vector.getSize()<< endl;
    cout<< "matrix "<< matrix.getRows()<< " "<< matrix.getCols()<< endl;

    /*catch(int e){
        if(e== -1) cout<< "Error: invalid row index";
        else if(e== -2) cout<< "Error: invalid column index";
    }*/
    /*catch(-2){
        cout<< "Error: invlaid column index";
    }
    cout<< endl;

    /*cout<< "Testing * overload"<< endl;
    vector.print();
    cout<< endl;
    vector*= 2;
    vector.print();
    cout<< endl;
    //vector= 0.5* vector;
    vector= vector/ 2;
    vector.print();
    cout<< endl<< endl;

    cout<< "Testing * overload for matrix"<< endl;
    matrix.print();
    matrix*= 2;
    cout<< endl<< endl;
    matrix.print();
    cout<< endl<< endl;
    //matrix= 0.5* matrix;
    matrix= matrix/ 2;
    cout<< endl;
    matrix.print();
    cout<< endl;

    cout<< "Testing matrix operations::: Matrices"<< endl<< endl;
    Matrix matrix1(3, 4), matrix2(4, 2);
    for(int i= 0; i< 3; i++){
        for(int j= 0; j< 4; j++){
            matrix1(i, j)= 2+ j*5 + i;
            //matrix2(i, j)= 3;
        }
    }

    for(int i= 0; i< 4; i++){
        for(int j= 0; j< 2; j++){
            matrix2(i, j)= 1+ j*3- i;
        }
    }

    /*matrix1.print();
    cout<< endl<< endl;
    matrix2.print();
    cout<< endl<< endl;

    //matrix1= matrix1+ matrix2;
    matrix1+= matrix2;
    matrix1.print();
    cout<< endl<< endl;
    //matrix1= matrix1- 2*matrix2;
    matrix1-= 2*matrix2;
    matrix1.print();
    cout<< endl<< endl;

    cout<< "Testing matrix operations::: Vectors"<< endl<< endl;
    Vector vector1(3), vector2(3);
    for(int i= 0; i< 3; i++){
        vector1(i)= 4;
        vector2(i)= 2* i+ 1;
    }

    vector1.print();
    cout<< endl;
    vector2.print();
    cout<< endl<< endl;

    //vector1= vector1 + vector2;
    vector1+= vector2;
    vector1.print();
    cout<< endl<< endl;

    //vector2= vector2- vector1;
    vector2-= vector1;
    vector2.print();
    cout<< endl<< endl;


    cout<< "matrix Multiplication"<< endl;
    matrix1.print(); cout<< endl<< endl;
    matrix2.print(); cout<< endl;
    cout<< endl;

    //Matrix matrix3= matrix1* matrix2;
    /*try{
        matrix1*= matrix2;
        matrix1.print();       
    }
    catch(const char* errMessage){
        cout<< errMessage<< endl;
    }
    //matrix1*= matrix2;
    //matrix1.print();
    cout<< endl<< endl;
    
   try{
    Matrix square(4,4);

    for(int i= 0; i< 4; i++){
        for(int j= 0; j< 4; j++){
            square(i, j)= 1+ i*2 -j;
        }
    }

   /* square.print();
    cout<< endl<< endl;
    square^=3;
    square.print();*
    cout<< endl<< endl;

    Vector v(3);
    for(int i= 0; i< 3; i++){
        v(i)= 1+ i*2;
    }

    v.print();
    cout<< endl;
    v^=2;
    v.print();
    cout<< endl;

    cout<< "transposing "<< endl<< endl;
    square.print();
    square= ~square;
    cout<< endl<< endl;
    square.print();
    cout<< endl<< endl;

    v.print();
    cout<< endl;
    v= ~v;
    v.print();
    cout<< endl;
   }
   catch(const char* errMessage){
    cout<< errMessage<< endl;
   }
    try{
            cout<< "Testing matrix reduction"<< endl;
        Matrix bMatrix(4, 1);

        Matrix square(4,4);

        for(int i= 0; i< 4; i++){
            for(int j= 0; j< 4; j++){
                square(i, j)= 1+ i*2 -j + 4;
            }
        }
        square.print(); cout<< endl;
        for(int i= 0; i< 4; i++){
            for(int j= 0; j< 1; j++){
                bMatrix(i, j)= 1+ i*2 + j+i;
            }
        }
        cout<< "this is the matrix"<< endl;
        bMatrix.print(); cout<< endl;

        cout<< "preforming operation"<< endl;
        square|=bMatrix;
        cout<< "This the reduced marix"<< endl;
        square.print(); cout<< endl;
        cout<< "The corresponding augmented matrix"<< endl;
        bMatrix.print(); cout<< endl;
        return 0;
    }
    catch(const char* errMessage){
        cout<< errMessage<< endl;
    }*/
