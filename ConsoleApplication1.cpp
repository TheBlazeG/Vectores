// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <locale>
const int MAX_ITEMS = 6;
const int SPACE_COST = 6;
const int FREE_ITEMS = 3;

using namespace std;
void vector1();
void vectorReserve();
void scoresrandom();
void Shuffleoriginal();
void iterInventory();
void Shuffle();
void Swap(vector<int>& uno);
void myswap();
void display(const vector<string>& vec);
void iterinventory();
bool AskYesNo(string question);
void ShowMenu();
int askNumber(string question, int a, int b);
void itemreplace(vector<string>& InventoryVector, string objectinput);
void SpaceBuy(vector<string>& InventoryVector, unsigned int& Resource, string founditem);

int main()
{
    std::setlocale(LC_ALL,"es_ES.UTF-8");
    unsigned int gems = 8;

    int space;
   
    bool isContinue;
    //items
    vector<string> items = { "sword","shield","potion","bow" };
     //inventory
    vector<string> inventory;
    inventory.reserve(MAX_ITEMS);
    vector<string>::const_iterator iter;
    do
    {
cout << "\n---INVENTARIO---\n";
    cout << "Gemas: " << gems<<endl;

    string itemfound = GetRandomItem(items);

    cout << "Has encontrado un(a) " << itemfound << "!\n";
    if (inventory.size()>=FREE_ITEMS)
    {
        ShowMenu();
        int option = askNumber("\n Elige un numero entre: ",0, 3);

        switch (option)
        {
        case 1:
            do
            {   
            itemreplace(inventory, itemfound);
            } while (isdigit(space));
            
            break;
        case 3:
            SpaceBuy(inventory, gems, itemfound);
            break;
        default:
            break;
        }
    }
    else
    {
inventory.push_back(itemfound);
    }
    
    //displayItems
    display(inventory);
    isContinue = AskYesNo("¿Quieres seguir explorando?");
    } while (isContinue);
    
}

string GetRandomItem(vector<string>&items)
{
    srand(time(NULL));
    int itemRandomIndex = (rand() % items.size());
    string itemSelected = items[itemRandomIndex];

    return itemSelected;
}
void display(const vector<string> &vec)
{
    vector<string>::const_iterator iter;
    int i = 0;
    cout << "\n---Tus items--\n ";
    for (iter=vec.begin(); iter!=vec.end(); iter++)
    {
        
        cout <<i<<".-"<< * iter << endl;
        i++;
    }
}
bool AskYesNo(string question)
{
    char answer;
    do
    {
        cout << "\n"<<question<<"(y/n)"<<endl;
        cin >> answer;

        if (answer=='y')
        {
            return true;
        }
        else
        {
            return false;
        }
    } while (answer !='y' && answer != 'n');
    cout << "\n Vuelve Pronto!";
}
void ShowMenu()
{
    cout << "\nYa no tienes Espacio para más objetos \n";
    cout << "\n1.-Reemplazar Objeto";
    cout << "\n2.-Continuar sin el objeto";
    cout << "\n3.-Añadir un espacio por " << SPACE_COST << "Gemas"<< endl;

}
int askNumber(string question, int a, int b)
{
    int number = 0;
    string input;
    bool isValid;
    do
    {

    
    do
    {
        cout << question << "entre " << a << " y " << b << endl;
        getline(cin, input);
        for (char c:input)
        {
            if (isdigit(c))
            {
                isValid = false;
                break;
            }
        }
        if (!isValid)
        {
            cout << "\n Entrada inválida, por favor solo ingresa números." << endl;
        }
    } while (!isValid||input.empty());
    //number > a || number < b ||
    number = stoi(input);
    } while (number > a || number < b );
    return stoi(input);
}
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
void scoresrandom()
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
    cout << "Puntajes " << endl;
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;
    }

    cout << "Buscar Puntajes" << endl;
    cin >> score;
    iter = find(scores.begin(), scores.end(), score);
    if (iter != scores.end())
    {
        cout << "Tu puntaje se encuentra en el vector\n";
    }
    else
    {
        cout << "No encontramos el puntaje que buscas\n";
    }

    srand(time(NULL));
    random_shuffle(scores.begin(), scores.end());
    cout << "\nScores mezclados\n";
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;
    }

    cout << "\nCambiar orden\n";
    sort(scores.begin(), scores.end());
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;
    }
    string word = "espejo";
    random_shuffle(word.begin(), word.end());
    cout << word;
}
void Shuffleoriginal()
{
    int lives;
    int menu;
    bool Stop = true;
    bool Exit = true;
    bool Guess = false;
    vector<int>::const_iterator iterate;
    vector<string> palabras = { "sandwich","mango","madera","alcancia","multimetro" };
    string respuesta;
    do
    {
        do
        {
            system("cls");
            cout << "Bienvenido a SHUFFLE!\n" << "Jugar=1 Salir=2\n";
            cin >> menu;
        } while (menu < 1 || menu>2);

        switch (menu)
        {
        case 1:
            do
            {
                system("cls");
                lives = 3;
                Guess = true;
                srand(time(NULL));
                int vectorutilizado = rand() % 5;
                string palabra = palabras[vectorutilizado];
                cout << palabra << endl;
                random_shuffle(palabra.begin(), palabra.end());
                do
                {
                    system("cls");
                    cout << palabra << endl << "Tienes " << lives << " Vidas\n";
                    cin >> respuesta;
                    if (respuesta == palabras[vectorutilizado])
                    {
                        cout << "\nRespuesta correcta, Ganaste!\n";
                        Guess = false;
                    }
                    else
                    {
                        cout << "\nRespuesta incorrecta, -1 vida\n";
                        lives = lives--;
                    }
                } while (lives != 0 && Guess == true);
                if (lives == 0)
                {
                    cout << "Perdiste!\n";
                }

                cout << "Quieres seguir jugando? 1=Si 2=No\n";
                cin >> menu;
                if (menu == 2)
                {
                    Stop = false;
                }
            } while (Stop);
            break;
        case 2:
            Exit = false;
            break;
        default:
            break;
        }

    } while (Exit);



}
void iterInventory()
{
    vector<string> inventory;
    inventory.push_back("Espada");
    inventory.push_back("Escudo");
    inventory.push_back("Martillo");
    inventory.push_back("Rifle");

    vector<string>::iterator MyIterator;
    vector<string>::const_iterator iter;

    cout << "\nTus items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    //Intercambiar
    cout << "intercambiaste tu " << inventory[2] << " por un arco";
    MyIterator = inventory.begin() + 2;
    *MyIterator = "Arco";
    cout << "\nTus items: \n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    //Size
    cout << "\nEl nombre del item " << *MyIterator << " tiene" << (*MyIterator).size() << " letras.\n";
    cout << "\nEl nombre del item " << *MyIterator << " tiene" << (MyIterator)->size() << " letras.\n";

    //insert
    cout << "\n\n Recuperaste la bomba robada! ";
    inventory.insert(inventory.begin() + 2, "Bomba");
    cout << "\nTus items: \n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    //Delete
    cout << "\n tu " << inventory[1] << " se destruyo en combate";
    inventory.erase(inventory.begin() + 1);

    cout << "\nTus items: \n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }
}
void Shuffle()
{
    const int MAX_ATTEMPTS = 3;
    int attempts = 0;

    vector<string> words;
    words.push_back("Computadora");
    words.push_back("Juego");
    words.push_back("Codigo");
    words.push_back("Refrigerador");

    srand(time(NULL));
    int randomnumber = rand();
    int wordsRandomIndex = (randomnumber % words.size());
    string Wordselected = words[wordsRandomIndex];
    //cout << Wordselected << endl;

    random_shuffle(Wordselected.begin(), Wordselected.end());
    cout << Wordselected << endl;
    string correctWord;
    do
    {
        cin >> correctWord;
        transform(correctWord.begin(), correctWord.end(), correctWord.begin(), ::toupper);
        if (correctWord == words[wordsRandomIndex])
        {
            cout << "\nAdivinaste la palabra!!!\n";
            break;
        }
        else
        {
            attempts++;
            cout << "\nFallaste Humano inepto:\n" << "te quedan " << 3 - attempts << " intentos";
        }
    } while (attempts != MAX_ATTEMPTS);
    if (attempts == MAX_ATTEMPTS)
    {
        cout << "\n Perdiste, date de baja, la palabra era: \n" << words[wordsRandomIndex];
    }
    else
    {
        cout << "\nMuy Bien!! Lo hiciste en el intento " << attempts;
    }
    cout << "\nFin del Juego";
}
void Swap(vector<int>& uno)
{
    int change = uno[0];
    uno[0] = uno[1];
    uno[1] = change;
}
void myswap()
{
    vector<int> Scores = { 1337,2023 };
    vector<int>::const_iterator iter;
    for (iter = Scores.begin(); iter != Scores.end(); iter++)
    {
        cout << *iter << endl;
    }
    void Swap(vector<string> Scores);
    for (iter = Scores.begin(); iter != Scores.end(); iter++)
    {
        cout << *iter << endl;
    }
}
void iterinventory()
{
    vector<string> inventory = { "sword","armor","gun" };
    display(inventory);
}
void Matrix()
{
    const int HEIGHTWIDTH = 6;
    for (int i = 0; i < HEIGHTWIDTH; i++)
    {
        cout << endl;
        for (int j = 0; j < HEIGHTWIDTH; j++)
        {
            if (i == 0 || i == HEIGHTWIDTH - 1 || j == 0 || j == HEIGHTWIDTH - 1)
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }

        }
    }
    cout << endl;
    //diagonal
    for (int i = 0; i < HEIGHTWIDTH; i++)
    {
        cout << endl;
        for (int j = 0; j < HEIGHTWIDTH; j++)
        {
            if (i == 0 || i == HEIGHTWIDTH - 1 || j == 0 || j == HEIGHTWIDTH - 1 || i == j)
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }

        }
    }

    cout << endl;
    //inverse diagonal

    for (int i = 0; i < HEIGHTWIDTH; i++)
    {
        cout << endl;
        for (int j = 0; j < HEIGHTWIDTH; j++)
        {
            int sumij = i + j;
            if (i == 0 || i == HEIGHTWIDTH - 1 || j == 0 || j == HEIGHTWIDTH - 1 || i == j || sumij == HEIGHTWIDTH - 1)
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }

        }
    }
}
void originaltictactoe()
{
    const int ROWS = 3;
    const int COLUMNS = 3;

    char board[ROWS][COLUMNS] =
    { {'0','x','0'},
      {' ','x','x'} ,
      {'x','0','0'} };
    cout << "<<<Tic-Tac-Toe>>>\n";

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
    board[1][0] = 'x';

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}
void itemreplace(vector<string>& InventoryVector, string objectinput)
{
    vector<string>::iterator iterate;
    int spaceinput=0;
    cout << "\nQue Objeto quieres Reemplazar?(por número)" << endl;
    display(InventoryVector);
    cin >> spaceinput;
    iterate = InventoryVector.begin() + spaceinput;
    *iterate = objectinput;
    
}
void SpaceBuy(vector<string>& InventoryVector, unsigned int &Resource,string founditem)
{
   
            if (Resource>=SPACE_COST)
            {
                cout << "Espacio comprado con éxito" << endl;
                Resource = Resource - SPACE_COST;
                InventoryVector.push_back(founditem);
              
            }
            else
            {
                cout << "No tienes gemas";
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