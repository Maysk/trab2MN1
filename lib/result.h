class Result{
    std::string description;    //Uma descrição do que será realizado sobre a matriz.
    Matrix* matrix;
public:
    Result();
    Result(Matrix *matrix, std::string description);

    void setDescription(std::string description);
    std::string getDescription();

    void setMatrix(Matrix *matrix);
    Matrix *getMatrix();
};
