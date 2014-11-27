#include "../lib/imports.h"


GaussTemplate::GaussTemplate(Matrix* independentTermsMatrix, Matrix* coefficientMatrix){
    this->independentTermsMatrix = independentTermsMatrix;
    this->coefficientMatrix = coefficientMatrix;
}

void GaussTemplate::setCoefficienMatrix(Matrix *matrix){
    this->coefficientMatrix = matrix;
}
Matrix *GaussTemplate::getCoefficienMatrix(){
    return this->coefficientMatrix;
}

void GaussTemplate::setIndependentTerms(Matrix* matrix){
    this->independentTermsMatrix = matrix;
}
Matrix *GaussTemplate::getIndependentTerms(){
    return this->independentTermsMatrix;
}

Matrix *GaussTemplate::getUnknownsMatrix(){
    return this->unknownsMatrix;
}

//TODO
void GaussTemplate::retroSubstitutions(){}

//TODO
void GaussTemplate::saveOnList(){}

