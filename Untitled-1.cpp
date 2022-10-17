#include <iostream>
#define MAX 3

float deltaCalculo(float x, float xOld)
{
    float deltaX;
    deltaX = x - xOld;
    if (deltaX < 0)
        deltaX = -deltaX;
    return deltaX;
}

float matrizCalculo(float matriz1, float matriz2, float matriz3, float resposta, float x, float y)
{
    return (-(matriz1 * x) - (matriz2 * y) + resposta) / matriz3;
}

float erroCalculo(float deltaX, float x)
{
    return (deltaX / x) * 100;
}

int main()
{

    int tamanho = 0, matriz[MAX][MAX], respostas[MAX], correto = 0, contador = 1;
    float x, y, z, xOld, yOld, zOld, deltaX, deltaY, deltaZ, erroX, erroY, erroZ, erro;
    x = y = z = xOld = yOld = zOld = erroZ = 0;
    system("cls");

    while (true)
    {
        std::cout << "Você quer fazer uma matriz de 3x3 ou 2x2?\n";
        std::cin >> tamanho;
        if (tamanho != 2 && tamanho != 3)
            std::cout << "Valor Invalido, digite novamente\n";
        else
            break;
    }

    std::cout << "Quanto erro será permitido?\n";
    std::cin >> erro;
    while (correto == 0)
    {
        system("cls");
        for (int i = 0; i < tamanho; i++)
        {
            for (int j = 0; j < tamanho; j++)
            {
                std::cout << "Qual o valor para x[" << j << "] da linha " << i + 1 << ": ";
                std::cin >> matriz[i][j];
            }
            std::cout << "Qual o valor para a resposta da linha " << i + 1 << ": ";
            std::cin >> respostas[i];
        }
        system("cls");
        std::cout << "Essa é a sua matriz?\n[0] Não\n[1] Sim\n";
        std::cout << "----------------------------------------";
        for (int i = 0; i < tamanho; i++)
        {
            std::cout << std::endl;
            for (int j = 0; j < tamanho; j++)
            {
                if (matriz[i][j] > 0)
                    std::cout << "+" << matriz[i][j] << "x" << j << " ";
                else
                    std::cout << matriz[i][j] << "x" << j << " ";
            }
            std::cout << " = " << respostas[i];
        }
        std::cout << "\n----------------------------------------\n";
        std::cin >> correto;
    }

    system("cls");
    while (true)
    {
        
        std::cout << std::endl << std::endl << contador <<" Rotação\n\n";
        x = matrizCalculo(matriz[0][1], matriz[0][2], matriz[0][0], respostas[0], y, z);
        deltaX = deltaCalculo(x, xOld);
        xOld = x;
        erroX = erroCalculo(deltaX, x);
        std::cout << "------------------------------------------------------------------\n"
                  << "X = " << x << std::endl
                  << "Delta de X = " << deltaX << std::endl
                  << "Erro de X = " << erroX << "%" << std::endl;

        y = matrizCalculo(matriz[1][0], matriz[1][2], matriz[1][1], respostas[1], x, z);
        deltaY = deltaCalculo(y, yOld);
        yOld = y;
        erroY = erroCalculo(deltaY, y);
        std::cout << "------------------------------------------------------------------\n"
                  << "Y = " << y << std::endl
                  << "Delta de Y = " << deltaY << std::endl
                  << "Erro de Y = " << erroY << "%" << std::endl;
        if (tamanho > 2)
        {
            z = matrizCalculo(matriz[2][0], matriz[2][1], matriz[2][2], respostas[2], x, y);
            deltaZ = deltaCalculo(z, zOld);
            zOld = z;
            erroZ = erroCalculo(deltaZ, z);
            std::cout << "------------------------------------------------------------------\n"
                      << "Z = " << z << std::endl
                      << "Delta de Z = " << deltaZ << std::endl
                      << "Erro de Z = " << erroZ << "%" << std::endl;
        }
        if (erroX <= erro && erroY <= erro && erroZ <= erro)
            break;
        system("pause");
        contador++;
    }

    std::cout << "PROGRAMA FINALIZADO";
}