#include "../lib/imports.h"

GaussJordan::GaussJordan(Matrix* independentTermsMatrix, Matrix* coefficientMatrix)
    :GaussTemplate(independentTermsMatrix, coefficientMatrix){}


void GaussJordan::resolveSytem( bool usePivot ){
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
        for(int k = 0; k < numberOfLines; k++ ){
            start = clock();

            if(usePivot == true){ pivoting( independentTerms, coefficients, numberOfLines, k ); }
            pivo = independentTerms->getValue(k,k);

            if(pivo == 0){
                end = clock();
                executionTime = executionTime + (end - start);
                throw 0;
            }

            for(int j = k+1; j < numberOfLines; j++ ){
                multiplier = independentTerms->getValue( k, j ) / pivo;
                independentTerms->setValue( k, j, multiplier );
            }


            newValue_bi = coefficients->getValue(k,0) / pivo;
            coefficients->setValue( k, 0, newValue_bi );
            independentTerms->setValue( k, k, 1 );

            end = clock();
            executionTime = executionTime + (end - start);

            description<<"Operação realizada: L"<< k <<" <- L"<< k <<" * 1/( "<< pivo <<" ) \n";
            saveOnList(description.str());
            description.str("");

            for(int i = 0; i < numberOfLines; i++ ){
                if( i != k ){
                    start=clock();

                    multiplier = independentTerms->getValue(i,k);
                    for(int j = k + 1; j < numberOfLines; j++ ){
                        newValue_aij = independentTerms->getValue( i, j ) - multiplier * independentTerms->getValue( k, j );
                        independentTerms->setValue( i, j, newValue_aij );
                    }

                    newValue_bi = coefficients->getValue( i, 0 ) - multiplier * coefficients->getValue( k, 0 );
                    coefficients->setValue( i, 0, newValue_bi );
                    independentTerms->setValue( i, k, 0 );

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



