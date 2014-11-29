#include "../lib/imports.h"
Gauss::Gauss(Matrix* independentTermsMatrix, Matrix* coefficientMatrix)
    :GaussTemplate(independentTermsMatrix, coefficientMatrix){}

void Gauss::beforeSolve(){
    Matrix* copy1 = getIndependentTerms()->getCopy();
    Matrix* copy2 = getCoefficienMatrix()->getCopy();
    this->independentTermsMatrixTemp = getIndependentTerms();
    this->coefficientMatrixTemp = getCoefficienMatrix();
    setIndependentTerms(copy1);
    setCoefficienMatrix(copy2);

    setExecutionTime(0);
    resetList();

}

void Gauss::resolveSytem(){
    int numberOfLines;
    double multiplier;
    double newValue_aij;
    double newValue_bi;

    long double executionTimeInSec = 0;
    clock_t executionTime = 0;
    clock_t start;
    clock_t end;

    beforeSolve();


    Matrix* coefficients = getCoefficienMatrix();
    Matrix* independentTerms = getIndependentTerms();
    numberOfLines = independentTerms->getHeight();


    for(int k = 0; k<=numberOfLines-2; k++){
        saveOnList("Operação realizada nesse ponto");
        start = clock();
        for(int i = k +1; i<=numberOfLines-1;i++){
            multiplier = independentTerms->getValue(i,k)/independentTerms->getValue(k,k);
            independentTerms->setValue(i,k,0);

            for(int j = k + 1; j<numberOfLines; j++){
                newValue_aij = independentTerms->getValue(i,j) - multiplier * independentTerms->getValue(k,j);
                independentTerms->setValue(i,j,newValue_aij);
            }

            newValue_bi = coefficients->getValue(i,0) - multiplier * coefficients->getValue(k,0);
            coefficients->setValue(i,0,newValue_bi);
        }
        end = clock();
        executionTime = executionTime + (end - start);
    }

    start = clock();
    retroSubstitutions();
    end = clock();

    executionTime = executionTime + (end - start);
    executionTimeInSec = executionTime/(long double) CLOCKS_PER_SEC;
    setExecutionTime(executionTimeInSec);

    afterSolve();
}

void Gauss::afterSolve(){
    delete getIndependentTerms();
    delete getCoefficienMatrix();
    setIndependentTerms(this->independentTermsMatrixTemp);
    setCoefficienMatrix(this->coefficientMatrixTemp);
}
