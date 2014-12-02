class Gauss : public GaussTemplate{
public:
    Gauss(Matrix* coefficientMatrix, Matrix* independentTermsMatrix);

    void resolveSytem( bool usePivot );

};
