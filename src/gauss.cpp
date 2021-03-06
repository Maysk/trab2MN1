#include "../lib/imports.h"
Gauss::Gauss(Matrix* coefficientMatrix, Matrix* independentTermsMatrix)
    :GaussTemplate(coefficientMatrix, independentTermsMatrix){}

void Gauss::resolveSytem( bool usePivot ){
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
        for(int k = 0; k<=numberOfLines-2; k++){
            for(int i = k +1; i<=numberOfLines-1;i++){
                start = clock();

                if(usePivot == true){ pivoting( coefficientsMatrix, independentTermsMatrix, numberOfLines, k );}

                pivo = coefficientsMatrix->getValue(k,k);

                if(pivo == 0){
                    end = clock();
                    executionTime = executionTime + (end - start);
                    throw 0;
                }

                multiplier = coefficientsMatrix->getValue(i,k)/pivo;
                addRowByOtherRowMultipliedByScalar(coefficientsMatrix,independentTermsMatrix,i,k,multiplier);

                end = clock();
                executionTime = executionTime + (end - start);
                description<<"Operação realizada: L"<< i <<" <- L"<< i <<" - ("<< multiplier <<") * L"<< k<<"\n";
                saveOnList(description.str());
                description.str("");

            }

            if(coefficientsMatrix->getValue(numberOfLines-1,numberOfLines-1) == 0){
                end = clock();
                executionTime = executionTime + (end - start);
                throw 1;
            }

        }

        start = clock();
        retroSubstitutions();
        end = clock();
        executionTime = executionTime + (end - start);

    }

    catch(int e){
        if( e == 0 ){
            saveOnList("Nao foi possivel continuar pois o pivô atual é igual a zero.\n");
        }
        if( e == 1 ){
            saveOnList("Não é possivel realizar a retro-substituição\n");
        }
        setSolvable(false);
    }

    executionTimeInSec = executionTime/(long double) CLOCKS_PER_SEC;
    setExecutionTime(executionTimeInSec);

    afterSolve();

}


