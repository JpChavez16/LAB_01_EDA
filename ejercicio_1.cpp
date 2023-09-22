#include <iostream>
#include <random>
#include <cmath>
#include <fstream>
using namespace std;

double distancia_euclidiana(const double punto_1[], const double punto_2[], int dim) 
{
    double distancia = 0.0;
    for (int i = 0; i < dim; ++i) 
    {
        double aux = punto_1[i] - punto_2[i];
        distancia += pow(aux,2);
    }
    return sqrt(distancia);
}

int main() 
{
    int dimensiones[] = {5000};
    for (int dim : dimensiones) 
    {
        cout<<"Dimension: "<<dim<<endl;
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<double> dist(0.0, 1.0);

        double puntos[100][dim];
        for (int i = 0; i < 100; ++i) 
        {
            for (int j = 0; j < dim; ++j) 
            {
                puntos[i][j] = dist(gen);
            }
        }

        ofstream archivo("distancias_5000.txt");
        if (archivo.is_open()) {
            for (int i = 0; i < 100; ++i) 
            {
                for (int j = i + 1; j < 100; ++j)
                 {
                    double distancia = distancia_euclidiana(puntos[i], puntos[j], dim);
                    archivo<<distancia<<" ";
                }
            }
            archivo.close();
        } else 
            cerr<<"Error al abrir el archivo para escritura."<<endl;
    }
    return 0;
}
