#include "../lib/imports.h"
Result::Result(){
    this->coefficientMatrix = NULL;
    this->independentTermsMatrix = NULL;
    this->description = "";
}

Result::Result(Matrix *coefficientMatrix, Matrix *independentTermsMatrix, std::string description){
    this->coefficientMatrix = coefficientMatrix;
    this->independentTermsMatrix = independentTermsMatrix;
    this->description = description;
}

void Result::setDescription(std::string description){
    this->description = description;
}

std::string Result::getDescription(){
    return this->description;
}

void Result::setCoefficienMatrix(Matrix *matrix){
    this->coefficientMatrix = matrix;
}

Matrix *Result::getCoefficienMatrix(){
    return this->coefficientMatrix;
}

void Result::setIndependentTerms(Matrix *matrix){
    this->independentTermsMatrix = matrix;
}

Matrix *Result::getIndependentTerms(){
    return this->independentTermsMatrix;
}
