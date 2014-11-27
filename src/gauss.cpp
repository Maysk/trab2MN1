#include "../lib/imports.h"

Gauss::Gauss(Matrix* independentTermsMatrix, Matrix* coefficientMatrix)
    :GaussTemplate(independentTermsMatrix, coefficientMatrix){}

void Gauss::beforeSolve(){
    this->independentTermsMatrixTemp = getIndependentTerms();
    this->coefficientMatrixTemp = getCoefficienMatrix();
}

void Gauss::resolveSytem(){}

void Gauss::afterSolve(){
    setIndependentTerms(independentTermsMatrixTemp);
    setCoefficienMatrix(coefficientMatrixTemp);
}
