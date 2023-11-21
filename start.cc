#include <iostream>

int main()
{
    char arrayz[11][8];

    // Initialisierung des Arrays mit '|'
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            arrayz[i][j] = '|';
        }
    }

    // Überschreiben der inneren Elemente mit Leerzeichen
    for (int i = 0; i < 11; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            arrayz[i][j] = ' ';
        }
    }

    // Ausgabe des Arrays
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            std::cout << arrayz[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
