class Gauss : public GaussTemplate{

public:
    Gauss(Matrix* independentTermsMatrix, Matrix* coefficientMatrix);

    void resolveSytem( bool usePivot );

};
