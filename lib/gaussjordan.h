class GaussJordan : public GaussTemplate{
    Matrix* coefficientMatrixTemp;
    Matrix* independentTermsMatrixTemp;
public:
    GaussJordan(Matrix* independentTermsMatrix, Matrix* coefficientMatrix);

    void resolveSytem( bool usePivot );
};
