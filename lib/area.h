#ifndef AREA_H
#define AREA_H

class Area
{
    Matrix *raio;
    Matrix *area;
    void calculeArea();
public:
    Area(Matrix *raio);

    void setRaio(Matrix *raio);
    Matrix* getRaio();

    Matrix* getArea();
};

#endif // AREA_H
