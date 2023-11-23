#include <iostream>

int main()
{
    const int rows = 11;    // Zeilen (Abstandsmarkierungen)
    const int columns = 24; // Spalten (Spuren)

    char arrayz[rows][columns];
    int distAnd = 100;

    // Initialisierung des Arrays mit Leerzeichen
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arrayz[i][j] = ' ';
        }
    }

    // Markierung der Spuren
    for (int j = 0; j < columns; j += 6)
    {
        for (int i = 0; i < rows; i++)
        {
            arrayz[i][j] = '|';     // Rand der Spur
            arrayz[i][j + 1] = ' '; // Leerzeichen in der Spur
            arrayz[i][j + 2] = ' '; // Leerzeichen in der Spur
        }
    }

    // Setzen Sie die Zahlen für "L", "C" und "R" in die erste Zeile
    std::cout << "\t    L\t  C     R \n";
    // Ausgabe des Arrays
    for (int i = 0; i < rows; i++)
    {
        std::cout << distAnd << " \t ";
        distAnd -= 20;
        for (int j = 0; j < columns; j++)
        {
            std::cout << arrayz[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
