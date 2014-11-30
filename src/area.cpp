#include "../lib/imports.h"

Area::Area(Matrix *raio)
{
    this->raio = raio->getCopy();
    this->area = new Matrix(raio->getHeight(),raio->getWidth());
    calculeArea();
}
void Area::calculeArea(){
    for(int i = 0 ; i < raio->getHeight(); i++)
        area->setValue(i,0,raio->getValue(i,0) * raio->getValue(i,0) * M_PI);
}

void Area::setRaio(Matrix *raio){
    delete this->raio;
    delete this->area;
    this->area = new Matrix(raio->getHeight(),raio->getWidth());
    this->raio = raio->getCopy();
    calculeArea();
}

Matrix* Area::getRaio(){
    return this->raio;
}

Matrix* Area::getArea(){
    return this->area;
}
