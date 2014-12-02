#include "../lib/imports.h"

GaussJordan::GaussJordan(Matrix* coefficientMatrix, Matrix* independentTermsMatrix)
    :GaussTemplate(coefficientMatrix, independentTermsMatrix){}


void GaussJordan::resolveSytem( bool usePivot ){
    int numberOfLines;
    double multiplier;
    double pivo;
    long double executionTimeInSec = 0;

    clock_t executionTime = 0;
    clock_t start;
    clock_t end;
    std::ostringstream description;

    beforeSolve();

    Matrix* coefficientsMatrix = getCoefficientMatrix();
    Matrix* independentTermsMatrix = getIndependentTerms();
    numberOfLines = independentTermsMatrix->getHeight();

    saveOnList("Sistema Inicial: \n");
    try{
        for(int k = 0; k < numberOfLines; k++ ){
            start = clock();

            if(usePivot == true){ pivoting( coefficientsMatrix, independentTermsMatrix, numberOfLines, k ); }

            pivo = coefficientsMatrix->getValue(k,k);

            if(pivo == 0){
                end = clock();
                executionTime = executionTime + (end - start);
                throw 0;
            }

            multiplyRowByScalar(coefficientsMatrix, independentTermsMatrix, k, 1/pivo);

            end = clock();
            executionTime = executionTime + (end - start);
            description<<"Operação realizada: L"<< k <<" <- L"<< k <<" * 1/( "<< pivo <<" ) \n";
            saveOnList(description.str());
            description.str("");

            for(int i = 0; i < numberOfLines; i++ ){
                if( i != k ){
                    start=clock();

                    multiplier = coefficientsMatrix->getValue(i,k);

                    addRowByOtherRowMultipliedByScalar(coefficientsMatrix, independentTermsMatrix, i, k, multiplier);

                    end = clock();
                    executionTime = executionTime + (end - start);

                    description<<"Operação realizada: L"<< i <<" <- L"<< i <<" - ("<< multiplier <<") * L"<< k<<"\n";
                    saveOnList(description.str());
                    description.str("");

                }

            }
        }

        start = clock();
        retroSubstitutions();
        end = clock();
        executionTime = executionTime + (end - start);

    }
    catch(int e){
        saveOnList("Nao foi possivel continuar pois o pivô atual é igual a zero.\n");
        setSolvable(false);
    }

    executionTimeInSec = executionTime/(long double) CLOCKS_PER_SEC;
    setExecutionTime(executionTimeInSec);
    afterSolve();
}



