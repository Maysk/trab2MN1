class GaussJordan : public GaussTemplate{
public:
    GaussJordan(Matrix* coefficientMatrix, Matrix* independentTermsMatrix);

    void resolveSytem( bool usePivot );
};
