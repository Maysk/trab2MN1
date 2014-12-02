class GaussTemplate {
    Matrix* coefficientMatrix;
    Matrix* independentTermsMatrix;
    Matrix* unknownsMatrix;
    ListResults* results;
    bool solvable;
    long double executionTime;

    //Atributos que nao possuem getter or setters.
    Matrix* coefficientMatrixTemp;
    Matrix* independentTermsMatrixTemp;

protected:
    void resetList();
    void saveOnList(std::string desc);
    void retroSubstitutions();
    void beforeSolve();
    void afterSolve();

    void pivoting(Matrix* A, Matrix* b, int numberOfLines, int k);

    void addRowByOtherRowMultipliedByScalar(Matrix* A, Matrix* b, int line_i,int line_j, double scalar);

    void multiplyRowByScalar(Matrix* A, Matrix* b, int line_i, double scalar);

    void switchRows(Matrix* m, int line_i, int line_j);

    void setSolvable(bool s);

public:
    GaussTemplate(Matrix* coefficientMatrix, Matrix* independentTermsMatrix);

    void setCoefficientMatrix(Matrix* matrix);
    Matrix *getCoefficientMatrix();

    void setIndependentTerms(Matrix* matrix);
    Matrix *getIndependentTerms();

    Matrix *getUnknownsMatrix();

    void setExecutionTime(long double executionTime);
    long double getExecutionTime();

    ListResults* getResults();

    bool isSolvable();

    virtual void resolveSytem( bool usePivot ) = 0;

    double getError();
};
