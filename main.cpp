/* My first project in C++ is vector calculator to do calculations on maximum three vectors simultaneously
 * Calculator is designed in structural form of programming
 * It is designed to do basic actions on maximum three vectors like adding, subtraction, scalar,
 * calculation the modules of vectors and multiplication them by a number.
 *
 * (C) ragane27
 */

// Attached libraries, used in this basic project
#include <iostream>
#include <cmath>



// Functions used in operation on vectors
void SelectAction(int HowMany, int size, int ** &tab);
int **EnterData(int size, int HowMany);
int *Adding(int HowMany, int size, int** &tab);
int *Subtraction(int HowMany, int size, int **&tab);
int Multiplier(int HowMany, int size, int **&tab);
int *Scalar(int HowMany, int size, int ** &tab);
float *Module(int HowMany, int size, int ** &tab);

void ClearMemory(int** &tab, int HowMany);

int main() {
    for (int j = 0; j < 10; j++)
        for (int i = 0; i < 30; i++)
            std::cout << "* ";
        std::cout << std::endl;

    std::cout << "================================================ ACTIONS ON VECTORS ===================================================" << std::endl;
    int VectorNumbers;
    std::cout << std::endl;
    std::cout << "\t\t\t\t Enter number of vectors (max. 3): ";
    std::cin >> VectorNumbers;
    std::cout <<"\t\t\t\t Enter number of elements for each of vectors: ";
    int ElementNumbers;
    std::cin >> ElementNumbers;
    int ** vector = EnterData(ElementNumbers, VectorNumbers);

    SelectAction(VectorNumbers, ElementNumbers, vector);


    ClearMemory(vector, VectorNumbers);

}


void SelectAction(int size, int length, int** &tab)
{

        int c;
        // Select action to do on vectors
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "\t\t\t\t Select action to do on vectors: " << std::endl;
        std::cout << std::endl;
        std::cout << "\t\t\t\t [1] Adding vectors (a + b + c)" << std::endl;
        std::cout << "\t\t\t\t [2] Subtraction vectors (a - b - c)" << std::endl;
        std::cout << "\t\t\t\t [3] Multiplication vector by a number (k * a, k * b, k * c)" << std::endl;
        std::cout << "\t\t\t\t [4] Scalar multiplication (a o b o c)" << std::endl;
        std::cout << "\t\t\t\t [5] Length of each vector." << std::endl;
        std::cout << std::endl;
        std::cout << "\t\t\t\t ***SELECT***: ";
        std::cin >> c;

        switch(c)
        {
        case 1:
        {
            std::cout << std::endl;
            std::cout << "\t\t\t\t\t**Adding vectors**";
            Adding(size, length, tab);
            break;
        }
        case 2:
        {
            std::cout << std::endl;
            std::cout << "\t\t\t\t\t**Subtraction vectors**";
            Subtraction(size, length, tab);
            break;
        }
        case 3:
        {
            std::cout << std::endl;
            std::cout <<"\t\t\t\t\t**Multiplication vector by a number**";
            Multiplier(size, length, tab);
            break;
        }

        case 4:
        {
            std::cout << std::endl;
            std::cout <<"\t\t\t\t\t**Scalar multiplication**";
            Scalar(size, length, tab);
            break;
        }


        case 5:
        {
            std::cout << std::endl;
            std::cout <<"\t\t\t\t**Length of each vector**";
            Module(size, length, tab);
            break;
        }


    }
}

int **EnterData(int size, int HowMany) {
    float value;
    int ** vector = new int * [size];
    for (int i = 0; i < HowMany; i++)
    {
        vector[i] = new int[size];
        std::cout << " " << std::endl;
        for (int j = 0; j < size; j++)
        {   std::cout << "\t\t\t\t Enter value of vector "<< i << " in the place [" << j << "] : ";
            std::cin >> value;
            vector[i][j] = value;
        }
    }
    std::cout << std::endl;
    //std::cout << "\t\t\t Vector a = [";
    for (int i = 0; i < 3; i++)
    {   if ((i < 1) && (i >= 0))
            std::cout <<"\t Vector a = [";
        else if((i >= 1) && (i < 2))
            std::cout <<"\t\t Vector b = [";
        else if (i >= 2)
            std::cout <<"\t\t\t Vector c = [";
        for (int j = 0; j < size; j++)
        {
        std::cout << " " << vector[i][j] << " ";
        }
        std::cout << "] " << " ";
    }
    return vector;
    }


int *Adding (int size, int length, int ** &tab)
{
    int ** result = new int * [size];
    std::cout << std::endl;
    std::cout << "\t\t\t\t Result of adding a + b + c = ";
    for (int i = 0; i < size; i++)
    {
        result[i] = new int[size];
        std::cout <<" [";
        for (int j = 0; j < length; j++)
        {

            result[i][j] = tab[i][j] + tab[i+1][j];
            result[i][j] += tab[i + 2][j];
            std::cout << " " << result[i][j] << " ";
        }
        std::cout << "]" << std::endl;
    }
    delete [] result;
}


int Multiplier(int size, int length, int ** &tab)
{
    float value;
    std::cout <<"\t\t\t Enter the number by which the vector's coordinates will be multiplied: ";
    std::cin >> value;
    for (int i = 0; i < size; i++)
    {
        std::cout << "[";
        for (int j = 0; j < length; j++)
        {
            tab[i][j] = tab[i][j] * value;
            std::cout << " " << tab[i][j] << " ";
        }
        std::cout << " ]";
    }
}


int *Subtraction (int size, int length, int **&tab)
{
    // TODO subtraction of C vector a - b - c !!!

    int * result = new int[length];
    std::cout << std::endl;
    std::cout << "\t\t\t\t Result of subraction vectors (a - b - c) = ";
    for (int i = 0; i < size; i++)
    {
        std::cout <<" [";
        for (int j = 0; j < length; j++)
        {
            result[j] = tab[i][j] - tab[i+1][j] - tab[i + 2][j];
            std::cout << " " << result[j] << " ";
        }
        std::cout << "]" << std::endl;

    }
    delete [] result;
}

int *Scalar(int size, int length, int ** &tab)
{
    int *result = new int[length];
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout <<" [";
        for (int j = 0; j < length; j++)
        {
            result[j] = tab[i][j] * tab[i + 1][j] * tab[i + 2][j];
            std::cout << " " << result[j] << " ";
        }
        std::cout << "]" << std::endl;
    }
    delete [] result;
}

float *Module(int size, int length, int ** &tab)
{
    float *result = new float[size];
    for (int i = 0; i < size; i++)
    {
        std::cout << "\n\t\t\t ";
        for (int j = 0; j < length; j++)
        {
            result[i] += (pow(tab[i][j], 2));
            result[i] = sqrt(result[i]);

        }
        std::cout << result[i] << std::endl;


    }
    delete [] result;
}

void ClearMemory(int** &tab, int HowMany)
{
    for (int i = 0; i < HowMany; i++)
        delete [] tab[i];
    delete [] tab;
    tab = 0;
    std::cout << std::endl;
    std::cout <<"=======================================================================================================================" << std::endl;
    std::cout <<"\t\t\t Dealocation of memory carried out successfully." << std::endl;
    std::cout <<"=======================================================================================================================" << std::endl;
}




