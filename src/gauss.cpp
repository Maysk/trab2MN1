#include "../lib/imports.h"
Gauss::Gauss(Matrix* independentTermsMatrix, Matrix* coefficientMatrix)
    :GaussTemplate(independentTermsMatrix, coefficientMatrix){}

void Gauss::resolveSytem( bool usePivot ){
    int numberOfLines;
    double multiplier;
    double newValue_aij;
    double newValue_bi;
    double pivo;
    long double executionTimeInSec = 0;

    clock_t executionTime = 0;
    clock_t start;
    clock_t end;
    std::ostringstream description;

    beforeSolve();

    Matrix* coefficients = getCoefficienMatrix();
    Matrix* independentTerms = getIndependentTerms();
    numberOfLines = independentTerms->getHeight();

    saveOnList("Sistema Inicial: \n");


    try{
        for(int k = 0; k<=numberOfLines-2; k++){
            for(int i = k +1; i<=numberOfLines-1;i++){
                start = clock();

                if(usePivot == true){
                    pivoting( independentTerms, coefficients, numberOfLines, k );
                }

                pivo = independentTerms->getValue(k,k);

                if(pivo == 0){
                    end = clock();
                    executionTime = executionTime + (end - start);
                    throw 0;
                }

                multiplier = independentTerms->getValue(i,k)/pivo;
                independentTerms->setValue(i,k,0);

                for(int j = k + 1; j<numberOfLines; j++){
                    newValue_aij = independentTerms->getValue(i,j) - multiplier * independentTerms->getValue(k,j);
                    independentTerms->setValue(i,j,newValue_aij);
                }

                newValue_bi = coefficients->getValue(i,0) - multiplier * coefficients->getValue(k,0);
                coefficients->setValue(i,0,newValue_bi);
                end = clock();
                executionTime = executionTime + (end - start);

               description<<"Operação realizada: L"<< i <<" <- L"<< i <<" - ("<< multiplier <<") * L"<< k<<"\n";

               saveOnList(description.str());
               description.str("");

            }

            if(independentTerms->getValue(numberOfLines-1,numberOfLines-1) == 0){
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


