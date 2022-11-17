#include <iomanip>
#include <iostream>
#include <fstream>

#include "arithmetic.h"
#include "vector.h"

using namespace std;

Vector::Vector(unsigned s):Arithmetic(){
    if(s== 0) size= 1;
    else size= s;

    vector= new double[size];
    for(int i= 0; i< size; i++){
        vector[i]= 0;
    }
}

Vector::Vector(const Vector& rhs){
    size= rhs.size;

    vector= new double[size];
    for(int i= 0; i< size; i++){
        vector[i]= rhs.vector[i];
    }
}

Vector::~Vector(){
    delete [] vector;
}

void Vector::print(){
    for(int i= 0; i< size; i++){
        if(i!= size- 1) cout<< setprecision(3)<< vector[i]<< setw(10);
        else cout<< setprecision(3)<< vector[i];
    }
    cout<< endl;
}

void Vector::readFile(istream &infile){
    for(int i= 0; i< size; i++){
        infile >> vector[i]; 
    }
}

const Vector& Vector::operator=(const Vector& rhs){
    if(this== &rhs) return *this;
    
    delete [] vector;

    size= rhs.size;
    vector= new double[size];

    for(int i= 0; i< size; i++){
        vector[i]= rhs.vector[i];
        //cout<< &vector[i]<< " "<< &rhs.vector[i]<< endl;
    }

    return *this;
}

const double& Vector::operator[](const unsigned r) const{
    if(r>= size || r< 0) throw "Error: invalid index";
    return vector[r];
}

double& Vector::operator()(const unsigned r){
    if(r>= size || r< 0) throw "Error: invalid index";
    return vector[r];
}

unsigned Vector::getSize() const{
    return size;
}

// SCALAR OPERATIONS

Vector Vector::operator*(const double& rhs){
    double n= rhs;
    Vector temp= *this;

    for(int i= 0; i< size; i++){
        temp(i)= temp[i] * n;
    }

    return temp;
}

Vector operator*(const double& scalar, const Vector& vec){
    double n= scalar;
    Vector temp= vec;

    for(int i= 0; i< vec.size; i++){
        temp(i)= temp[i] * n;
    }

    return temp;
}
Vector& Vector::operator*=(const double& rhs){
    double n= rhs;

    for(int i= 0; i< size; i++){
        vector[i]= vector[i] * n;
    }

    return *this;
}

Vector Vector::operator/(const double& rhs){
    if(rhs== 0) throw "Error: division by zero";

     double n= rhs;
    Vector temp= *this;

    for(int i= 0; i< size; i++){
        temp(i)= temp[i] / n;
    }

    return temp;
}

// Vector mathematical operations
Vector Vector::operator+(const Vector& rhs){
    if(size!= rhs.size) throw "Error: adding vectors of different dimensionality";

    for(int i= 0; i< size; i++){
        vector[i]= vector[i]+ rhs.vector[i];
    }
    return *this;
}

Vector& Vector::operator+=(const Vector& rhs){
    if(size!= rhs.size) throw "Error: adding vectors of different dimensionality";

    for(int i= 0; i< size; i++){
        vector[i]= vector[i]+ rhs.vector[i];
    }
    return *this;
}

Vector Vector::operator-(const Vector& rhs){
    if(size!= rhs.size) throw "Error: subtracting vectors of different dimensionality";

    for(int i= 0; i< size; i++){
        vector[i]= vector[i]- rhs.vector[i];
    }
    return *this;
}
Vector& Vector::operator-=(const Vector& rhs){
    if(size!= rhs.size) throw "Error: subtracting vectors of different dimensionality";

    for(int i= 0; i< size; i++){
        vector[i]= vector[i]- rhs.vector[i];
    }
    return *this;
}

Vector Vector::operator^(int pow){
    if(pow< 0) throw "Error: negative power is not supported";
    if(pow== 0){
        for(int i= 0; i< size; i++){
            vector[i]= 1;
        }
    }

    for(int i= 0; i< size; i++){
        for(int j= 1; j< pow; j++){
            vector[i]= vector[i]* vector[i];
        }
    }
    return *this;
}

Vector& Vector::operator^=(int pow){
    if(pow< 0) throw "Error: negative power is not supported";
    if(pow== 0){
        for(int i= 0; i< size; i++){
            vector[i]= 1;
        }
    }

    for(int i= 0; i< size; i++){
        for(int j= 1; j< pow; j++){
            vector[i]= vector[i]* vector[i];
        }
    }
    return *this;
}

Vector Vector::operator~(){
    Vector rVector(size);

    for(int i= 0; i< size; i++){
        rVector(i)= vector[size-i- 1];
    }
    return rVector;
}
