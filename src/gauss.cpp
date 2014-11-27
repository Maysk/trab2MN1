#include "../lib/imports.h"

Gauss::Gauss(Matrix* independentTermsMatrix, Matrix* coefficientMatrix)
    :GaussTemplate(independentTermsMatrix, coefficientMatrix){}

void Gauss::beforeSolve(){
    this->independentTermsMatrixTemp = getIndependentTerms();
    this->coefficientMatrixTemp = getCoefficienMatrix();
}

void Gauss::resolveSytem(){
    int numberOfLines;
    double multiplier;
    double newValue_aij;
    double newValue_bi;


    Matrix *independentTerms = getIndependentTerms();
    Matrix *coefficients = getCoefficienMatrix();

    numberOfLines = independentTerms->getHeight();

    for(int k = 0; k<numberOfLines-1; k++){
        for(int i = k +1; i<numberOfLines;i++){
            multiplier = independentTerms->getValue(i,k)/independentTerms->getValue(k,k);
            independentTerms->setValue(i,k,0);

            for(int j = k + 1; j<numberOfLines; j++){
                newValue_aij = independentTerms->getValue(i,j) - multiplier * independentTerms->getValue(k,j);
                independentTerms->setValue(i,j,newValue_aij);

                newValue_bi = coefficients->getValue(i,1) - multiplier * coefficients->getValue(k,1);
                coefficients->setValue(i,1,newValue_bi);

            }
        }
    }
}

void Gauss::afterSolve(){
    setIndependentTerms(independentTermsMatrixTemp);
    setCoefficienMatrix(coefficientMatrixTemp);
}
