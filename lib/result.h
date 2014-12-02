class Result{
    std::string description;    //Uma descrição do que será realizado sobre a matriz.
    Matrix* coefficientMatrix;
    Matrix* independentTermsMatrix;

public:
    Result();
    Result(Matrix *coefficientMatrix, Matrix *independentTermsMatrix, std::string description);

    void setDescription(std::string description);
    std::string getDescription();

    void setCoefficientMatrix(Matrix *matrix);
    Matrix *getCoefficientMatrix();

    void setIndependentTerms(Matrix* matrix);
    Matrix *getIndependentTerms();
};
