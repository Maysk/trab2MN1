class GaussJordan : public GaussTemplate{
public:
    GaussJordan(Matrix* independentTermsMatrix, Matrix* coefficientMatrix);

    void resolveSytem( bool usePivot );
};
