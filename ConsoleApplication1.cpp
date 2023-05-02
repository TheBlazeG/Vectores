// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>
#include <vector>

using namespace std;
void vector1()
{//vector<string> myStuff = {"espada", "martillo", "bomba"};
      //  vector <string> inventory(10);
        //vector <string> inventory(10, "-");
          //  vector<string> inventory(myStuff);
    string objeto;
    vector<string> inventory;

    inventory.push_back("Espada");
    inventory.push_back("Escudo");
    inventory.push_back("Martillo");

    cout << "Tienes" << inventory.size() << "items en tu inventario" << endl;
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i] << endl;
    }
    cout << "\nCambiaste tu" << inventory[0] << "por una bomba.";
    inventory[0] = "bomba";

    cout << "\n";

    int i = 0;
    do
    {
        cout << inventory[i] << endl;
        i++;
    } while (i < inventory.size());

    //Delete item from vector
    inventory.pop_back();
    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i] << endl;
    }
    cout << "Un enemigo ha robado todas tus armas" << endl;
    inventory.clear();

    for (unsigned int i = 0; i < 5; i++)
    {
        system("cls");
        cout << "Busca un objeto" << endl;
        cin >> objeto;
        cout << "encontraste un/a " << objeto << endl;
        inventory.push_back(objeto);
        system("pause");
    }
    if (inventory.empty())
    {
        cout << "no tienes nada" << endl;
    }
    else
    {
        cout << "tu inventario es" << endl;
        for (unsigned int i = 0; i < inventory.size(); i++)
        {
            cout << inventory[i] << endl;
        }
    }
}
void vectorReserve()
{
    vector <int> scores(10, 0);
    cout << "Size is: " << scores.size() << endl;
    cout << "Vector capacity is: " << scores.capacity() << endl;

    scores.push_back(0);
    cout << "Size is: " << scores.size() << endl;
    cout << "Vector capacity is: " << scores.capacity() << endl;

    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    cout << "Size is: " << scores.size() << endl;
    cout << "Vector capacity is: " << scores.capacity() << endl;

    scores.reserve(40);
    cout << "Size is: " << scores.size() << endl;
    cout << "Vector capacity is: " << scores.capacity() << endl;
}
int main()
{
    const int NUM_SCORES = 4;
    int score;
    vector<int>::const_iterator iter;
    vector<int> scores;

    for (int i = 0; i < NUM_SCORES; i++)
    {
        cout << "Score " << i + 1 << endl;
        cin >> score;
        scores.push_back(score);
    }

    for (  iter = scores.begin(); iter!=scores.end(); iter++)
    {
        cout << *iter;
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
