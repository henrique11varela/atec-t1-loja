#include "Headerfiles/conmanip.h"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <stdio.h>
#include <fstream>

using namespace conmanip;
using namespace std;

/*////TO DO
to learn inicio do main
https://stackoverflow.com/questions/3471520/how-to-remove-scrollbars-in-console-windows-c
*/

/* fills tables with default and example values ACLEAN*/
/*void defaultValues(string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras)
{
    // default values for stock
    stock[*sizeStock][0] = to_string(*sizeStock); // 0
    stock[*sizeStock][1] = "Banana";
    stock[*sizeStock][2] = "5";
    stock[*sizeStock][3] = "0.70";
    (*sizeStock)++;
    stock[*sizeStock][0] = to_string(*sizeStock); // 1
    stock[*sizeStock][1] = "Pera";
    stock[*sizeStock][2] = "10";
    stock[*sizeStock][3] = "1.00";
    (*sizeStock)++;
    stock[*sizeStock][0] = to_string(*sizeStock); // 2
    stock[*sizeStock][1] = "Morango";
    stock[*sizeStock][2] = "42";
    stock[*sizeStock][3] = "0.50";
    (*sizeStock)++;

    // default values for clientes
    clientes[*sizeClientes][0] = to_string(*sizeClientes - 1); // 0
    clientes[*sizeClientes][1] = "Henrique";
    clientes[*sizeClientes][2] = "935560176";
    clientes[*sizeClientes][3] = "R. Henrique, 240";
    (*sizeClientes)++;
    clientes[*sizeClientes][0] = to_string(*sizeClientes - 1); // 1
    clientes[*sizeClientes][1] = "Maria";
    clientes[*sizeClientes][2] = "992485115";
    clientes[*sizeClientes][3] = "R. Maria, 169";
    (*sizeClientes)++;
    clientes[*sizeClientes][0] = to_string(*sizeClientes - 1); // 2
    clientes[*sizeClientes][1] = "Manuel";
    clientes[*sizeClientes][2] = "112";
    clientes[*sizeClientes][3] = "R. do Hospital, WeeWoo";
    (*sizeClientes)++;

    // default values for vendas e compras
    vendas[*sizeVendas][0] = to_string(*sizeVendas); // 0
    vendas[*sizeVendas][1] = "0";
    vendas[*sizeVendas][2] = "20";
    vendas[*sizeVendas][3] = "2/1/2022";
    compras[*sizeCompras][0] = to_string(*sizeVendas);
    compras[*sizeCompras][1] = "1";
    compras[*sizeCompras][2] = "3";
    (*sizeCompras)++;
    compras[*sizeCompras][0] = to_string(*sizeVendas);
    compras[*sizeCompras][1] = "0";
    compras[*sizeCompras][2] = "5";
    (*sizeCompras)++;
    (*sizeVendas)++;
    vendas[*sizeVendas][0] = to_string(*sizeVendas); // 1
    vendas[*sizeVendas][1] = "1";
    vendas[*sizeVendas][2] = "10";
    vendas[*sizeVendas][3] = "2/1/2022";
    compras[*sizeCompras][0] = to_string(*sizeVendas);
    compras[*sizeCompras][1] = "0";
    compras[*sizeCompras][2] = "3";
    (*sizeCompras)++;
    compras[*sizeCompras][0] = to_string(*sizeVendas);
    compras[*sizeCompras][1] = "2";
    compras[*sizeCompras][2] = "2";
    (*sizeCompras)++;
    (*sizeVendas)++;
};*/

/* reads the text file and fills the table with the contents
"|" == separator, "||" == endl, "|||" == end of file
returns false if failed to open file */
bool txtGet(string fileName, string **table, int *sizeTable)
{
    ifstream inputFile;
    inputFile.open(fileName);
    if (!inputFile.is_open())
    {
        return false;
    }
    for (int i = 0; i < 100; i++)
    {
        if (inputFile.eof())
        {
            break;
        }
        else
        {
            int j = 0, k = 0;
            bool eol = false;
            while (!eol)
            {
                string temp;
                inputFile >> temp;
                if (inputFile.fail())
                {
                    cout << fileName << "'s empty";
                    return false;
                }
                if (temp == "|")
                {
                    j++;
                    k = 0;
                }
                else if (temp == "||")
                {
                    (*sizeTable)++;
                    eol = true;
                }
                else if (temp == "|||")
                {
                    (*sizeTable)++;
                    return true;
                }
                else
                {
                    if (k > 0)
                    {
                        table[i][j] += " ";
                    }
                    table[i][j] += temp;
                    k++;
                }
            }
        }
    }
    inputFile.close();
    return true;
};

/* writes the contents of the table in the text file
"|" == separator, "||" == endl, "|||" == end of file
returns false if failed to open file */
bool txtSet(string fileName, string **table, int sizeTable, int C)
{
    ofstream outputFile;
    outputFile.open(fileName);
    if (!outputFile.is_open())
    {
        return false;
    }
    for (int i = 0; i < sizeTable; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (j > 0)
            {
                outputFile << " ";
            }
            outputFile << table[i][j] << " |";
        }
        outputFile << "|";
        if (i != sizeTable - 1)
        {
            outputFile << endl;
        }
    }
    outputFile << "|";
    outputFile.close();
    return true;
};

// ! Useless Flavor

/* Displays an apple on screen */
void apple(console_out *conout, int xr, int yr)
{
    int x = xr - 18;
    cout << setposy(yr) << setposx(x + 29) << settextcolor(console_text_colors::green) << "___\n"
         << setposx(x + 26) << "_/`.-'`.\n"
         << setposx(x + 16) << settextcolor(console_text_colors::yellow) << "_" << setposx(x + 24) << settextcolor(console_text_colors::green) << "_/` .  _.'\n"
         << settextcolor(console_text_colors::red) << setposx(x + 7) << "..:::::." << settextcolor(console_text_colors::yellow) << "(_)   " << settextcolor(console_text_colors::green) << "/` _.'_./\n"
         << settextcolor(console_text_colors::red) << setposx(x + 5) << ".oooooooooo" << settextcolor(console_text_colors::yellow) << "\\ \\" << settextcolor(console_text_colors::red) << "o" << settextcolor(console_text_colors::green) << "/.-'__.'" << settextcolor(console_text_colors::red) << "o.\n"
         << settextcolor(console_text_colors::red) << setposx(x + 4) << ".ooooooooo`._" << settextcolor(console_text_colors::yellow) << "\\_|" << settextcolor(console_text_colors::green) << "_.'`" << settextcolor(console_text_colors::red) << "oooooob.\n"
         << setposx(x + 2) << ".ooooooooooooooooooooo" << settextcolor(console_text_colors::light_red) << "&&" << settextcolor(console_text_colors::red) << "oooooob.\n"
         << setposx(x + 1) << ".oooooooooooooooooooo" << settextcolor(console_text_colors::light_red) << "&@@@@@@" << settextcolor(console_text_colors::red) << "oooob.\n"
         << setposx(x) << ".ooooooooooooooooooooooo" << settextcolor(console_text_colors::light_red) << "&&@@@@@" << settextcolor(console_text_colors::red) << "ooob.\n"
         << setposx(x) << "doooooooooooooooooooooooooo" << settextcolor(console_text_colors::light_red) << "&@@@@" << settextcolor(console_text_colors::red) << "ooob\n"
         << setposx(x) << "doooooooooooooooooooooooooo" << settextcolor(console_text_colors::light_red) << "&@@@" << settextcolor(console_text_colors::red) << "oooob\n"
         << setposx(x) << "dooooooooooooooooooooooooo" << settextcolor(console_text_colors::light_red) << "&@@@" << settextcolor(console_text_colors::red) << "ooooob\n"
         << setposx(x) << "dooooooooooooooooooooooooo" << settextcolor(console_text_colors::light_red) << "&@@" << settextcolor(console_text_colors::red) << "oooooob\n"
         << setposx(x) << "`dooooooooooooooooooooooooo" << settextcolor(console_text_colors::light_red) << "&@" << settextcolor(console_text_colors::red) << "ooooob'\n"
         << setposx(x + 1) << "`doooooooooooooooooooooooooooooob'\n"
         << setposx(x + 2) << "`doooooooooooooooooooooooooooob'\n"
         << setposx(x + 3) << "`doooooooooooooooooooooooooob'\n"
         << setposx(x + 4) << "`doooooooooooooooooooooooob'\n"
         << setposx(x + 5) << "`doooooooooooooooooooooob'\n"
         << setposx(x + 6) << "`dooooooooobodoooooooob'\n"
         << setposx(x + 7) << "`doooooooob dooooooob'\n"
         << setposx(x + 8) << "`\"\"\"\"\"\"\"' `\"\"\"\"\"\"'\"\n"
         << settextcolor(console_text_colors::white);
};

/* Displays the white background in for width chars */
string whiteBG(console_out *conout, int width)
{
    cout << setbgcolor(console_bg_colors::white) << settextcolor(console_text_colors::black);
    cout << setw(width) << " ";
    conout->setposx(conout->getposx() - width);
    return "";
};

/* writes a € sign */
string euro(console_out *conout)
{
    cout << WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"€", wcslen(L"€"), NULL, NULL)
         << setposx(conout->getposx() - 1)
         << " "
         << setposx(conout->getposx() - 1);
    return "";
};

// ! Custom io funcs

/* Displays the input box */
void inputBox(console_out *conout)
{
    cout << setposx(conout->getsize().X / 2 - 14)
         << setposy(conout->getsize().Y - 5)
         << "O----------------------------O"
         << endl
         << setposx(conout->getsize().X / 2 - 14)
         << "|                            |"
         << endl
         << setposx(conout->getsize().X / 2 - 14)
         << "O----------------------------O"
         << endl;
    for (int i = 0; i < conout->getsize().X; i++)
    {
        cout << setposx(i) << setposy(conout->getsize().Y - 1) << " ";
    }
    conout->setposx(conout->getsize().X / 2 - 12);
    conout->setposy(conout->getpos().Y - 3);
};

/* only accepts and returns ints */
int customCini(console_out *conout)
{
    inputBox(conout);
    int choice;
    while (!(cin >> choice))
    {
        inputBox(conout);
        cout << setposy(conout->getpos().Y + 2)
             << setposx(conout->getsize().X / 2 - 14)
             << settextcolor(console_text_colors::yellow)
             << "insira um numero"
             << setposx(conout->getsize().X / 2 - 12)
             << setposy(conout->getpos().Y - 2)
             << settextcolor(console_text_colors::white);
        cin.clear();
        cin.ignore(100, '\n');
    }
    return choice;
};

/* recieves and outputs strings */
string customCins(console_out *conout)
{
    inputBox(conout);
    char first;
    string choice;
    cin >> first;
    getline(cin, choice);
    return first + choice;
};

/* only accepts and returns floats */
float customCinf(console_out *conout)
{
    inputBox(conout);
    float choice;
    while (!(cin >> choice))
    {
        inputBox(conout);
        cout << setposy(conout->getpos().Y + 2)
             << setposx(conout->getsize().X / 2 - 14)
             << settextcolor(console_text_colors::yellow)
             << "insira um numero"
             << setposx(conout->getsize().X / 2 - 12)
             << setposy(conout->getpos().Y - 2)
             << settextcolor(console_text_colors::white);
        cin.clear();
        cin.ignore(100, '\n');
    }
    return choice;
};

/* outputs ontop of the input box */
void customCout(console_out *conout, string text)
{
    cout << setposx(0)
         << setposy(conout->getsize().Y - 6);
    for (int i = 0; i < conout->getsize().X; i++)
    {
        cout << " ";
    }
    cout << setposx(conout->getsize().X / 2 - text.length() / 2 + (text.length() % 2 ? 0 : 1))
         << text;
};

// ! improvSQL

/* returns the content of the table in index_return where index_value is value*/
string selectSQL(int index_return, string **table, int index_value, string value)
{
    for (int i = 0; i < 100; i++)
    {
        if (table[i][index_value] == value)
        {
            return table[i][index_return];
        }
    }
    return "";
};

/* check first line where table[Y][X] is value and returns Y */
int checkLineOf(string **table, int X, string value)
{
    for (int i = 0; i < 100; i++)
    {
        if (table[i][X] == value)
        {
            return i;
        }
    }
    return -1;
};

/* checks the highest non-negative value in a column from a table
returns the highest value from that column
returns -1 if failed to find any value*/
int checkHighestId(string **table, int X)
{
    int output = -1;
    for (int i = 0; i < 100; i++)
    {
        if (table[i][X] == "")
        {
            return output;
        }
        int value = stoi(table[i][X]);
        if (value > output)
        {
            output = value;
        }
    }
    return output;
};

/* clean line from table */
void cleanLine(string **table, int Y, int C)
{
    for (int i = 0; i < C; i++)
    {
        table[Y][i] = "";
    }
};

/* remove empty line in table
returns true if successful, false if it failed*/
bool compactTable(string **table, int C)
{
    int line = 0;
    while (line < 100)
    {
        if (table[line][0] == "" && table[line + 1][0] == "")
        {
            return true;
        }
        else if (table[line][0] == "" && table[line + 1][0] != "")
        {
            for (int i = 0; i < C; i++)
            {
                table[line][i] = table[line + 1][i];
            }
            cleanLine(table, line + 1, C);
        }
        line++;
    }
    return false;
};

// ! Usefull funcs

/* Pauses app until Enter/Return is pressed
num = input buffer
print = print or not */
void pressEnter(console_out *conout, int num, bool print)
{
    if (print)
    {
        customCout(conout, "press enter...");
    }
    for (int i = 0; i < num; i++)
    {
        cin.ignore();
    }
};

/* returns size of biggest string in the array */
int getBiggestStringSize(string *text, int sizeArr)
{
    int length = 0;
    for (int i = 0; i < sizeArr; i++)
    {
        if (text[i].length() > length)
        {
            length = text[i].length();
        }
    }
    return length;
};

/* calculates the value in the cart */
float precoTotalCart(string **stock, string **cart, int *sizeCart)
{
    float total = 0;
    for (int i = 0; i < *sizeCart; i++)
    {
        total += stoi(cart[i][1]) * stof(selectSQL(3, stock, 0, cart[i][0]));
    }
    return total;
};

/* returns float as a string with 2 decimal places */
string setPrecision2(float input)
{
    stringstream ss;
    ss << fixed << setprecision(2) << input;
    return ss.str();
};

// ! Table display

/* Displays Clientes table
displays left if left == true, else displays centered*/
void showClientes(console_out *conout, string **clientes, int *sizeClientes, bool left)
{
    if (*sizeClientes != 0)
    {
        // prepares space for contents
        int biggestString[] = {0, 0, 0, 0};
        for (int i = 0; i < *sizeClientes; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                string item = clientes[i][j];
                if (item.length() > biggestString[j])
                {
                    biggestString[j] = item.length();
                }
            }
        }
        int Xpos = left ? 1 : (conout->getsize().X / 2 - (biggestString[0] + biggestString[1] + biggestString[2] + biggestString[3] + 5) / 2);
        // top box
        cout << setposx(Xpos)
             << setposy(1)
             << settextcolor(console_text_colors::red)
             << ("CLIENTES")
             << settextcolor(console_text_colors::white)
             << endl;
        cout << setposx(Xpos) << "O" << setfill('-') << setw(biggestString[0] + biggestString[1] + biggestString[2] + biggestString[3] + 4) << "O" << setfill(' ') << endl;
        // content
        for (int i = 1; i < *sizeClientes; i++)
        {
            cout << setposx(Xpos)
                 << "|"
                 << clientes[i][0]
                 << setposx(Xpos + biggestString[0] + 1)
                 << "|"
                 << clientes[i][1]
                 << setposx(Xpos + biggestString[0] + biggestString[1] + 2)
                 << "|"
                 << clientes[i][2]
                 << setposx(Xpos + biggestString[0] + biggestString[1] + biggestString[2] + 3)
                 << "|"
                 << clientes[i][3]
                 << setposx(Xpos + biggestString[0] + biggestString[1] + biggestString[2] + biggestString[3] + 4)
                 << "|"
                 << endl;
        }
        // bottom box
        cout << setposx(Xpos) << "O" << setfill('-') << setw(biggestString[0] + biggestString[1] + biggestString[2] + biggestString[3] + 4) << "O" << setfill(' ') << endl;
        // legend
        cout << setposx(Xpos)
             << settextcolor(console_text_colors::light_blue)
             << "id|name|phone|address"
             << settextcolor(console_text_colors::white);
    }
};

/* Displays Stock table
displays left if left == true, else displays right
if venda is true, adds lucro and IVA to the price*/
void showStock(console_out *conout, string **stock, int *sizeStock, bool left, bool venda)
{
    if (*sizeStock != 0)
    {
        // prepares space for contents
        int biggestString[] = {0, 0, 0, 0};
        for (int i = 0; i < *sizeStock; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                string item = stock[i][j];
                if (item.length() > biggestString[j])
                {
                    biggestString[j] = item.length();
                }
            }
        }
        int Xpos = left ? 1 : (conout->getsize().X - (biggestString[0] + biggestString[1] + biggestString[2] + biggestString[3] + 5) - 1);
        // top box
        cout << setposx(Xpos)
             << setposy(1)
             << settextcolor(console_text_colors::red)
             << ("STOCK")
             << settextcolor(console_text_colors::white)
             << endl;
        cout << setposx(Xpos) << "O" << setfill('-') << setw(biggestString[0] + biggestString[1] + biggestString[2] + biggestString[3] + 5) << "O" << setfill(' ') << endl;

        // contents
        for (int i = 0; i < *sizeStock; i++)
        {
            cout << setposx(Xpos)
                 << "|"
                 << stock[i][0]
                 << setposx(Xpos + biggestString[0] + 1)
                 << "|"
                 << stock[i][1]
                 << setposx(Xpos + biggestString[0] + biggestString[1] + 2)
                 << "|"
                 << stock[i][2]
                 << setposx(Xpos + biggestString[0] + biggestString[1] + biggestString[2] + 3)
                 << "|"
                 << setPrecision2(stof(stock[i][3]) * (venda ? (1.30 * 1.23) : 1))
                 << setposx(Xpos + biggestString[0] + biggestString[1] + biggestString[2] + biggestString[3] + 4)
                 << euro(conout)
                 << "|"
                 << endl;
        }
        // bottom box
        cout << setposx(Xpos) << "O";
        cout << setposx(Xpos) << "O" << setfill('-') << setw(biggestString[0] + biggestString[1] + biggestString[2] + biggestString[3] + 5) << "O" << setfill(' ') << endl;

        // legend
        cout << setposx(Xpos)
             << settextcolor(console_text_colors::light_blue)
             << "id|name|quant|price"
             << settextcolor(console_text_colors::white);
    }
};

/* Displays Cart table
displays left if left == true, else displays right*/
void showCart(console_out *conout, string **stock, string **cart, int *sizeCart, bool left)
{
    if (*sizeCart != 0)
    {
        // prepares space for content
        int biggestString[] = {3, 0};
        for (int i = 0; i < *sizeCart; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                string item;
                switch (j)
                {
                case 0:
                    item = selectSQL(1, stock, 0, cart[i][0]);
                    break;
                case 1:
                    item = cart[i][1];
                    break;
                }
                if (item.length() > biggestString[j])
                {
                    biggestString[j] = item.length();
                }
            }
        }
        int Xpos = left ? 1 : (conout->getsize().X - (biggestString[0] + biggestString[1] + 3) - 1);
        // top box
        cout << setposx(Xpos)
             << setposy(1)
             << settextcolor(console_text_colors::red)
             << ("CART")
             << settextcolor(console_text_colors::white)
             << endl;
        cout << setposx(Xpos) << "O" << setfill('-') << setw(biggestString[0] + biggestString[1] + 2) << "O" << setfill(' ') << endl;
        // contents
        for (int i = 0; i < *sizeCart; i++)
        {
            cout << setposx(Xpos)
                 << "|"
                 << selectSQL(1, stock, 0, cart[i][0])
                 << setposx(Xpos + biggestString[0] + 1)
                 << "|"
                 << cart[i][1]
                 << setposx(Xpos + biggestString[0] + biggestString[1] + 2)
                 << "|"
                 << endl;
        }
        // value
        string valor = setPrecision2(precoTotalCart(stock, cart, sizeCart) * 1.30 * 1.23);
        cout << setposx(Xpos)
             << "|"
             << setposx((Xpos + biggestString[0] + biggestString[1] + 1) - valor.length())
             << valor
             << euro(conout)
             << setposx(Xpos + biggestString[0] + biggestString[1] + 2)
             << "|"
             << endl;
        // bottom box
                cout << setposx(Xpos) << "O" << setfill('-') << setw(biggestString[0] + biggestString[1] + 2) << "O" << setfill(' ') << endl;
        // legend
        cout << setposx(Xpos)
             << settextcolor(console_text_colors::light_blue)
             << "nome|quant"
             << settextcolor(console_text_colors::white);
    }
};

/* Displays Vendas table
displays left if left == true, else displays centered*/
void showVendas(console_out *conout, string **vendas, int *sizeVendas, string **clientes, bool left)
{
    if (*sizeVendas != 0)
    {
        // prepares space for content
        int biggestString[] = {0, 0, 0};
        for (int i = 0; i < *sizeVendas; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                string item;
                switch (j)
                {
                case 0:
                    item = vendas[i][0];
                    break;
                case 1:
                    item = selectSQL(1, clientes, 0, vendas[i][1]);
                    break;
                case 2:
                    item = vendas[i][3];
                    break;

                default:
                    break;
                }
                if (item.length() > biggestString[j])
                {
                    biggestString[j] = item.length();
                }
            }
        }
        if (biggestString[1] == 0)
        {
            biggestString[1] = 9;
        }
        int Xpos = left ? 1 : (conout->getsize().X / 2 - (biggestString[0] + biggestString[1] + biggestString[2] + 4) / 2);
        // top box
        cout << setposx(Xpos)
             << setposy(1)
             << settextcolor(console_text_colors::red)
             << ("Vendas")
             << settextcolor(console_text_colors::white)
             << endl;
        cout << setposx(Xpos) << "O" << setfill('-') << setw(biggestString[0] + biggestString[1] + biggestString[2] + 3) << "O" << setfill(' ') << endl;
        // contents
        for (int i = 0; i < *sizeVendas; i++)
        {
            string nomeCliente = selectSQL(1, clientes, 0, vendas[i][1]);
            if (nomeCliente == "")
            {
                nomeCliente = "Eliminado";
            }
            cout << setposx(Xpos)
                 << "|"
                 << vendas[i][0]
                 << setposx(Xpos + biggestString[0] + 1)
                 << "|"
                 << nomeCliente
                 //<< selectSQL(vendas[i][1], 0, clientes, 1)
                 << setposx(Xpos + biggestString[0] + biggestString[1] + 2)
                 << "|"
                 << vendas[i][3]
                 << setposx(Xpos + biggestString[0] + biggestString[1] + biggestString[2] + 3)
                 << "|"
                 << endl;
        }
        // bottom box
        cout << setposx(Xpos) << "O" << setfill('-') << setw(biggestString[0] + biggestString[1] + biggestString[2] + 3) << "O" << setfill(' ') << endl;
        // legend
        cout << setposx(Xpos)
             << settextcolor(console_text_colors::light_blue)
             << "fatura|nome|data"
             << settextcolor(console_text_colors::white);
    }
};

// ! sub submenus

/* introdução dos valores de novo cliente
returns id*/
int clienteNovo(console_out *conout, string **clientes, int *sizeClientes)
{
    string nome, telefone, morada;
    customCout(conout, "Insira o nome:"); // input do nome
    nome = customCins(conout);
    while (checkLineOf(clientes, 1, nome) != -1)
    {
        customCout(conout, "Cliente ja existente, insira de novo:");
        nome = customCins(conout);
    }
    customCout(conout, "Insira o numero de telefone:"); // input do tlf
    telefone = customCins(conout);
    customCout(conout, "Insira a morada:"); // input da morada
    morada = customCins(conout);
    // tables update
    clientes[*sizeClientes][0] = to_string(checkHighestId(clientes, 0) + 1);
    clientes[*sizeClientes][1] = nome;
    clientes[*sizeClientes][2] = telefone;
    clientes[*sizeClientes][3] = morada;
    (*sizeClientes)++;
    return stoi(clientes[(*sizeClientes) - 1][0]);
};

/* pagamento e finalizacao da transacao */
void pagamento(console_out *conout, string **stock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    float precoAPagar = precoTotalCart(stock, cart, sizeCart);
    system("cls||clear");
    showCart(conout, stock, cart, sizeCart, false);
    cout << setposx(conout->getsize().X / 2 - 9 / 2)
         << setposy(1)
         << "PAGAMENTO";
    customCout(conout, "Insira o valor entregue"); // input do valor entregue pelo cliente
    float valorEntregue = customCinf(conout);
    while (valorEntregue < (precoAPagar * 1.30 * 1.23))
    {
        customCout(conout, "Valor baixo, insira o valor entregue");
        valorEntregue = customCinf(conout);
    }
    int idCliente = -1;
    string resposta;
    do // ja e cliente?
    {
        customCout(conout, "Ja e cliente? (S/N)");
        resposta = customCins(conout);
    } while (resposta != "s" && resposta != "S" && resposta != "n" && resposta != "N");
    if (resposta == "s" || resposta == "S")
    {
        showClientes(conout, clientes, sizeClientes, false);
        customCout(conout, "Insira o numero de cliente");
        idCliente = customCini(conout);
    }
    else
    {
        do // quer ser cliente?
        {
            customCout(conout, "Quer ser cliente? (S/N)");
            resposta = customCins(conout);
        } while (resposta != "s" && resposta != "S" && resposta != "n" && resposta != "N");
        if (resposta == "s" || resposta == "S")
        {
            idCliente = clienteNovo(conout, clientes, sizeClientes);
        }
    }
    // tables update
    time_t t = time(nullptr);
    tm *now = localtime(&t);
    string idFatura = to_string(checkHighestId(vendas, 0) + 1);
    vendas[*sizeVendas][0] = idFatura;
    vendas[*sizeVendas][1] = to_string(idCliente);
    vendas[*sizeVendas][2] = setPrecision2(valorEntregue);
    vendas[*sizeVendas][3] = to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
    (*sizeVendas)++;
    for (int i = 0; i < *sizeCart; i++)
    {
        compras[*sizeCompras][0] = idFatura;
        compras[*sizeCompras][1] = cart[i][0];
        compras[*sizeCompras][2] = cart[i][1];
        (*sizeCompras)++;
        int lineInStock = checkLineOf(stock, 0, cart[i][0]);
        stock[lineInStock][2] = to_string(stoi(stock[lineInStock][2]) - stoi(cart[i][1]));
        cleanLine(cart, i, 2);
    }
    *sizeCart = 0;
};

// ! Submenus

// ! Efectuar venda

/* imprime o talao da transacao escolhida em idFatura*/
void imprimirTalao(console_out *conout, string **stock, string **clientes, string **vendas, string **compras, int *sizeCompras, int idFatura)
{
    system("cls||clear");
    string **tempTable = new string *[100]; // temporary table to hold values
    for (int i = 0; i < 100; i++)
    {
        tempTable[i] = new string[2];
    }
    int sizeTempTable = 0;
    for (int i = 0; i < *sizeCompras; i++)
    {
        if (compras[i][0] == to_string(idFatura))
        {
            tempTable[sizeTempTable][0] = compras[i][1];
            tempTable[sizeTempTable][1] = compras[i][2];
            sizeTempTable++;
        }
    }
    // prepares space for contents
    int biggestString[] = {0, 0, 0};
    for (int i = 0; i < sizeTempTable; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            string item;
            switch (j)
            {
            case 0: // quantidade
                item = tempTable[i][1];
                break;
            case 1: // nome do produto
                item = selectSQL(1, stock, 0, tempTable[i][0]);
                break;
            case 2: // preco
                item = setPrecision2(stof(selectSQL(3, stock, 0, tempTable[i][0])) * 1.30 * 1.23 * stoi(tempTable[i][1]));
                break;
            }
            if (item.length() > biggestString[j])
            {
                biggestString[j] = item.length();
            }
        }
    }
    string numCliente = selectSQL(1, vendas, 0, to_string(idFatura));
    string nomeCliente = selectSQL(1, clientes, 0, numCliente);
    nomeCliente = nomeCliente == "" ? "Eliminado" : nomeCliente;
    numCliente = numCliente == "-1" ? " " : numCliente;
    string data = selectSQL(3, vendas, 0, to_string(idFatura));
    string total = setPrecision2(precoTotalCart(stock, tempTable, &sizeTempTable) * 1.30);
    string entregue = setPrecision2(stof(selectSQL(2, vendas, 0, to_string(idFatura))));
    string troco = setPrecision2(stof(entregue) - stof(total) * 1.23);
    int big = biggestString[0] + biggestString[1] + biggestString[2] + 4;
    if (big < 17)
    {
        big = 17;
    }
    int Xpos = conout->getsize().X / 2 - big / 2;
    int width = biggestString[0] + biggestString[1] + biggestString[2] + 5;
    if (width < 17)
    {
        width = 17;
    }
    // top
    cout << setposy(3)
         << setposx(Xpos)
         << whiteBG(conout, width) << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width / 2 - 9 / 2) << "FRUIT INC" << endl
         << setposx(Xpos) << whiteBG(conout, width) << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width / 2 - (7 + to_string(idFatura).length()) / 2) << "Fatura " << idFatura << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width / 2 - nomeCliente.length() / 2 - (nomeCliente.length() % 2 ? 1 : 0) - numCliente.length() / 2 - 1) << numCliente << " " << nomeCliente << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width / 2 - data.length() / 2) << data << endl
         << setposx(Xpos) << whiteBG(conout, width) << endl;
    // body
    for (int i = 0; i < sizeTempTable; i++)
    {
        string semIVA = setPrecision2(stof(selectSQL(3, stock, 0, tempTable[i][0])) * 1.30);
        string soIVA = setPrecision2(stof(selectSQL(3, stock, 0, tempTable[i][0])) * 1.30 * 0.23);
        cout << setposx(Xpos)
             << whiteBG(conout, width)
             << setposx(Xpos + 1)
             << tempTable[i][1]
             << setposx(Xpos + biggestString[0] + 2)
             << selectSQL(1, stock, 0, tempTable[i][0])
             << setposx(Xpos + width - semIVA.length() - 2)
             << semIVA
             << euro(conout)
             << endl
             << setposx(Xpos)
             << whiteBG(conout, width)
             << setposx(Xpos + width - soIVA.length() - 2)
             << soIVA
             << euro(conout)
             << endl;
    }
    // tail
    cout << setposx(Xpos) << whiteBG(conout, width) << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width - 8 - total.length()) << "Total " << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width - 8 - total.length()) << "s/IVA " << total << euro(conout) << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width - 12 - total.length()) << "Valor IVA " << setPrecision2(stof(total) * 0.23) << euro(conout) << endl
         << setposx(Xpos) << whiteBG(conout, width) << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width - 8 - setPrecision2(stof(total) * 1.23).length()) << "c/IVA " << setPrecision2(stof(total) * 1.23) << euro(conout) << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width - 11 - entregue.length()) << "Entregue " << entregue << euro(conout) << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width - 8 - troco.length()) << "Troco " << troco << euro(conout) << endl
         << setposx(Xpos) << whiteBG(conout, width)
         << setbgcolor(console_bg_colors::black) << settextcolor(console_text_colors::white) << endl;
    pressEnter(conout, 2, false);
};

/* Selecionar produto
submenu */
void selecionarProduto(console_out *conout, string **stock, int *sizeStock, string **cart, int *sizeCart)
{
    system("cls||clear");
    cout << setposx(conout->getsize().X / 2 - 18 / 2)
         << setposy(1)
         << "SELECIONAR PRODUTO";
    showStock(conout, stock, sizeStock, true, true);
    showCart(conout, stock, cart, sizeCart, false);
    int id, quantidade, quantStock;
    do // input product
    {
        customCout(conout, "O que vais querer comprar? (id)");
        id = customCini(conout);
    } while (checkLineOf(stock, 0, to_string(id)) == -1);
    string inCart = selectSQL(1, cart, 0, to_string(id));
    int numCart = stoi((inCart == "") ? "0" : inCart);
    quantStock = stoi(selectSQL(2, stock, 0, to_string(id))) - numCart;
    do // input quantity
    {
        customCout(conout, "quanto?");
        quantidade = customCini(conout);
    } while (quantStock < quantidade || (numCart + quantidade) < 0);
    customCout(conout, "");
    // tables update
    if (quantidade != 0)
    {
        if (inCart == "")
        {
            cart[*sizeCart][0] = to_string(id);
            cart[*sizeCart][1] = to_string(quantidade);
            (*sizeCart)++;
        }
        else
        {
            cart[checkLineOf(cart, 0, to_string(id))][1] = to_string(stoi(cart[checkLineOf(cart, 0, to_string(id))][1]) + quantidade);
        }
    }
    for (int i = 0; i < *sizeCart; i++)
    {
        if (cart[i][1] == "0")
        {
            cleanLine(cart, i, 2);
            compactTable(cart, 2);
            (*sizeCart)--;
        }
    }
};

/* add values from cart to respective tables and delete cart */
void checkout(console_out *conout, string **stock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    float precoAPagar = precoTotalCart(stock, cart, sizeCart);
    string choice;
    do
    {
        system("cls||clear");
        showCart(conout, stock, cart, sizeCart, false);
        cout << setposx(conout->getsize().X / 2 - 8 / 2)
             << setposy(1)
             << "CHECKOUT";
        customCout(conout, "Confirmar que quer pagar (S/N)");
        choice = customCins(conout);
        customCout(conout, "");
    } while (choice != "s" && choice != "S" && choice != "n" && choice != "N");
    if (choice == "s" || choice == "S")
    {
        pagamento(conout, stock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
        imprimirTalao(conout, stock, clientes, vendas, compras, sizeCompras, checkHighestId(vendas, 0));
    }
};

// ! Comprar Stock

/* Criacao de artigo novo */
void criacaoArtigo(console_out *conout, string **stock, int *sizeStock)
{
    system("cls||clear");
    cout << setposx(conout->getsize().X / 2 - 22 / 2)
         << setposy(1)
         << "CRIACAO DE ARTIGO NOVO";
    float preco_fabrica;
    string nome;
    customCout(conout, "Insira o nome do artigo: "); // input product name
    nome = customCins(conout);
    while (checkLineOf(stock, 1, nome) != -1)
    {
        customCout(conout, "Artigo ja existente, insira novo: ");
        nome = customCins(conout);
    }
    customCout(conout, "Preco base do artigo: "); // input value
    preco_fabrica = customCinf(conout);
    // tables update
    stock[*sizeStock][0] = to_string(checkHighestId(stock, 0) + 1);
    stock[*sizeStock][1] = nome;
    stock[*sizeStock][2] = "0";
    stock[*sizeStock][3] = setPrecision2(preco_fabrica);
    (*sizeStock)++;
};

/* Adicionar stock a artigo existente */
void adicionarStock(console_out *conout, string **stock, int *sizeStock)
{
    system("cls||clear");
    cout << setposx(conout->getsize().X / 2 - 15 / 2)
         << setposy(1)
         << "ADICIONAR STOCK";
    showStock(conout, stock, sizeStock, true, false);
    int id, quantidade;
    do // input product
    {
        customCout(conout, "Insira o id do artigo");
        id = customCini(conout);
    } while (checkLineOf(stock, 0, to_string(id)) == -1);
    do // quantity
    {
        customCout(conout, "Quanto vai adicionar?");
        quantidade = customCini(conout);
    } while (quantidade < 0);
    stock[checkLineOf(stock, 0, to_string(id))][2] = to_string(stoi(stock[checkLineOf(stock, 0, to_string(id))][2]) + quantidade);
};

/* Eliminar produto */
void eliminarProduto(console_out *conout, string **stock, int *sizeStock)
{
    system("cls||clear");
    cout << setposx(conout->getsize().X / 2 - 16 / 2)
         << setposy(1)
         << "ELIMINAR PRODUTO";
    showStock(conout, stock, sizeStock, true, false);
    int id;
    do // input product
    {
        customCout(conout, "Insira o id do artigo");
        id = customCini(conout);
    } while (checkLineOf(stock, 0, to_string(id)) == -1);
    string choice;
    do // input confirm
    {
        customCout(conout, "Queres mesmo eliminar o produto? (S/N)");
        choice = customCins(conout);
    } while (choice != "s" && choice != "S" && choice != "n" && choice != "N");
    if (choice == "s" || choice == "S") // tables update
    {
        cleanLine(stock, checkLineOf(stock, 0, to_string(id)), 4);
        compactTable(stock, 4);
        (*sizeStock)--;
    }
};

// ! Criação de relatorios

/* Relatorio de stock */
void relatorioStock(console_out *conout, string **stock, int *sizeStock)
{
    system("cls||clear");
    showStock(conout, stock, sizeStock, true, false);
    int Xpos = conout->getsize().X - 1;
    cout << setposx(Xpos)
         << setposy(2);
    int stockTotal = 0;   // quantidade total de stock
    float valorTotal = 0; // valor monetario do stock todo
    for (int i = 0; i < *sizeStock; i++)
    {
        int quantidadeAtual = stoi(stock[i][2]);
        stockTotal += quantidadeAtual;
        valorTotal += quantidadeAtual * stof(stock[i][3]);
    }
    cout << setposx(Xpos - 15 - setPrecision2(valorTotal).length()) << "Total stock: " << settextcolor(console_text_colors::light_yellow) << stockTotal << settextcolor(console_text_colors::white) << endl
         << setposx(Xpos - 21 - setPrecision2(valorTotal).length()) << "Valor total s/IVA: " << settextcolor(console_text_colors::light_yellow) << setPrecision2(valorTotal * 1.30) << euro(conout) << settextcolor(console_text_colors::white) << endl
         << setposx(Xpos - 18 - setPrecision2(valorTotal).length()) << "Possivel lucro: " << settextcolor(console_text_colors::light_yellow) << setPrecision2(valorTotal * 0.3) << euro(conout) << settextcolor(console_text_colors::white) << endl;
    pressEnter(conout, 2, true);
};

/* Relatorio de vendas por produto */
void relatorioVendasProduto(console_out *conout, string **stock, int *sizeStock, string **compras, int *sizeCompras)
{
    system("cls||clear");
    showStock(conout, stock, sizeStock, true, false);
    customCout(conout, "Insira o nome do produto"); // input product name
    string produto = customCins(conout);
    while (checkLineOf(stock, 1, produto) == -1)
    {
        customCout(conout, "Produto nao encontrado, insira de novo");
        produto = customCins(conout);
    }
    system("cls||clear");
    int quantidadeInfo = 4;
    string text[] = {"Quantidade em stock: ", "Quantidade vendida: ", "Possivel lucro: ", "Lucro ja adquirido: "};
    string output[] = {"", "", "", ""};
    // quantos em stock
    output[0] = selectSQL(2, stock, 1, produto);
    // quantos prods vendidos
    int quantosVendidos = 0;
    for (int i = 0; i < *sizeCompras; i++)
    {
        if (compras[i][1] == selectSQL(0, stock, 1, produto))
        {
            quantosVendidos += stoi(compras[i][2]);
        }
    }
    output[1] = to_string(quantosVendidos);
    // possivel lucro
    output[2] = setPrecision2(stoi(output[0]) * stof(selectSQL(3, stock, 1, produto)) * 0.30);
    // lucro ja dado
    output[3] = setPrecision2(stoi(output[1]) * stof(selectSQL(3, stock, 1, produto)) * 0.30);
    int middle = conout->getsize().X / 2;
    int biggestString[] = {0, 0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            string item;
            switch (j)
            {
            case 0:
                item = text[i];
                break;
            case 1:
                item = output[i];
                break;
            }
            if (item.length() > biggestString[j])
            {
                biggestString[j] = item.length();
            }
        }
    }
    cout << setposy(2)
         << setposx(middle - 31 / 2) << "RELATORIO DE VENDAS POR PRODUTO" << endl
         << endl
         << setposx(middle - produto.length() / 2) << produto << endl
         << endl;
    for (int i = 0; i < quantidadeInfo; i++)
    {
        cout << setposx(middle - (biggestString[0] + biggestString[1]) / 2) << text[i] << settextcolor(console_text_colors::light_yellow) << output[i];
        if (i == 2 || i == 3)
        {
            euro(conout);
        }
        cout << settextcolor(console_text_colors::white) << endl;
    }
    pressEnter(conout, 1, true);
};

/* Relatorio de vendas por cliente */
void relatorioVendasCliente(console_out *conout, string **stock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras)
{
    system("cls||clear");
    showClientes(conout, clientes, sizeClientes, false);
    customCout(conout, "Insira o nome do cliente"); // input client name
    string cliente = customCins(conout);
    while (checkLineOf(clientes, 1, cliente) == -1)
    {
        customCout(conout, "Cliente nao encontrado, insira de novo");
        cliente = customCins(conout);
    }
    system("cls||clear");
    string text[] = {"Quantidade de compras: ", "Quantidade de produtos comprados: ", "Valor gasto: ", "Lucro dado: "};
    string output[] = {"", "", "", ""};
    int quantDeCompras = 0;
    int quantItemComprado = 0;
    float valorGasto = 0;
    for (int i = 0; i < *sizeVendas; i++)
    {
        if (vendas[i][1] == selectSQL(0, clientes, 1, cliente))
        {
            for (int j = 0; j < *sizeCompras; j++)
            {
                if (vendas[i][0] == compras[j][0])
                {
                    quantItemComprado += stoi(compras[j][2]);
                    valorGasto += stoi(compras[j][2]) * stof(selectSQL(3, stock, 0, compras[j][1]));
                }
            }
            quantDeCompras++;
        }
    }
    output[0] = to_string(quantDeCompras);
    output[1] = to_string(quantItemComprado);
    output[2] = setPrecision2(valorGasto * 1.30 * 1.23);
    output[3] = setPrecision2(valorGasto * 0.30);
    // Display output
    int middle = conout->getsize().X / 2;
    int biggestString[] = {0, 0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            string item;
            switch (j)
            {
            case 0:
                item = text[i];
                break;
            case 1:
                item = output[i];
                break;
            }
            if (item.length() > biggestString[j])
            {
                biggestString[j] = item.length();
            }
        }
    }
    cout << setposy(2)
         << setposx(middle - 31 / 2) << "RELATORIO DE VENDAS POR CLIENTE" << endl
         << endl
         << setposx(middle - cliente.length() / 2) << cliente << endl
         << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << setposx(middle - (biggestString[0] + biggestString[1]) / 2) << text[i] << settextcolor(console_text_colors::light_yellow) << output[i];
        if (i == 2 || i == 3)
        {
            euro(conout);
        }
        cout << settextcolor(console_text_colors::white) << endl;
    }
    pressEnter(conout, 1, true);
};

/* Relatorio total de vendas */
void relatorioTotalVendas(console_out *conout, string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras)
{
    system("cls||clear");
    string text[] = {"Produto mais vendido: ", "Produto menos vendido: ", "Produto com mais lucro: ", "Cliente que mais comprou: "};
    string output[] = {"", "", "", ""}; // maisVendido, menosVendido, maisLucro, melhorCliente
    // produto mais vendido e menos vendido
    int quantMaior = INT_MIN;
    int quantMenor = INT_MAX;
    float lucro = INT_MIN;
    for (int i = 0; i < *sizeStock; i++)
    {
        int quantTemp = 0;
        for (int j = 0; j < *sizeCompras; j++)
        {
            if (stock[i][0] == compras[j][1])
            {
                quantTemp += stoi(compras[j][2]);
            }
        }
        // prod mais vendido
        if (quantTemp > quantMaior)
        {
            quantMaior = quantTemp;
            output[0] = stock[i][1] + " " + to_string(quantMaior);
        }
        // prod menos vendido
        if (quantTemp < quantMenor)
        {
            quantMenor = quantTemp;
            output[1] = stock[i][1] + " " + to_string(quantMenor);
        }
        // mais lucro
        float lucroTemp = quantTemp * stof(selectSQL(3, stock, 0, to_string(i))) * 0.30;
        if (lucroTemp > lucro)
        {
            lucro = lucroTemp;
            output[2] = stock[i][1] + " " + setPrecision2(lucro);
        }
    }
    // melhor cliente
    float valorCliente = INT_MIN;
    for (int i = 0; i < *sizeClientes; i++) // por cada cliente
    {
        float valorClienteTemp = 0;
        for (int j = 0; j < *sizeVendas; j++) // por cada venda
        {
            if (vendas[j][1] == clientes[i][0])
            {
                for (int k = 0; k < *sizeCompras; k++) // por cada compra
                {
                    if (compras[k][0] == vendas[j][0])
                    {
                        float valorDoProduto = stof(selectSQL(3, stock, 0, compras[k][1]));
                        int quantDoProduto = stoi(compras[k][2]);
                        valorClienteTemp += valorDoProduto * quantDoProduto * 0.30;
                    }
                }
            }
        }
        if (valorClienteTemp > valorCliente)
        {
            valorCliente = valorClienteTemp;
            output[3] = clientes[i][1] + " " + setPrecision2(valorCliente);
        }
    }
    int middle = conout->getsize().X / 2;
    int biggestString[] = {0, 0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            string item;
            switch (j)
            {
            case 0:
                item = text[i];
                break;
            case 1:
                item = output[i];
                break;
            }
            if (item.length() > biggestString[j])
            {
                biggestString[j] = item.length();
            }
        }
    }
    cout << setposy(2)
         << setposx(middle - 25 / 2) << "RELATORIO TOTAL DE VENDAS" << endl
         << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << setposx(middle - (biggestString[0] + biggestString[1]) / 2) << text[i] << settextcolor(console_text_colors::light_yellow) << output[i];
        if (i == 2 || i == 3)
        {
            euro(conout);
        }
        cout << settextcolor(console_text_colors::white) << endl;
    }
    pressEnter(conout, 2, true);
};

// ! Opçoes de cliente

/* Criar cliente */
void criarCliente(console_out *conout, string **clientes, int *sizeClientes)
{
    system("cls||clear");
    showClientes(conout, clientes, sizeClientes, false);
    clienteNovo(conout, clientes, sizeClientes);
};

/* Eliminar cliente */
void eliminarCliente(console_out *conout, string **clientes, int *sizeClientes)
{
    system("cls||clear");
    cout << setposx(conout->getsize().X / 2 - 16 / 2)
         << setposy(1)
         << "ELIMINAR CLIENTE";
    showClientes(conout, clientes, sizeClientes, false);
    int id;
    do // input client number
    {
        customCout(conout, "Insira o numero de cliente");
        id = customCini(conout);
    } while (checkLineOf(clientes, 0, to_string(id)) == -1);
    string choice;
    do // input confirm
    {
        customCout(conout, "Queres mesmo eliminar o cliente? (S/N)");
        choice = customCins(conout);
    } while (choice != "s" && choice != "S" && choice != "n" && choice != "N");
    if (choice == "s" || choice == "S")
    {
        cleanLine(clientes, checkLineOf(clientes, 0, to_string(id)), 4);
        compactTable(clientes, 4);
        (*sizeClientes)--;
    }
};

/* Alterar nome */
void alterarNomeCliente(console_out *conout, string **clientes, int *sizeClientes)
{
    system("cls||clear");
    cout << setposx(conout->getsize().X / 2 - 23 / 2)
         << setposy(1)
         << "ALTERAR NOME DO CLIENTE";
    showClientes(conout, clientes, sizeClientes, false);
    int id;
    do // input client number
    {
        customCout(conout, "Insira o numero de cliente");
        id = customCini(conout);
    } while (checkLineOf(clientes, 0, to_string(id)) == -1);
    string newName;
    customCout(conout, "Insira o novo nome"); // input new name
    newName = customCins(conout);
    while (checkLineOf(clientes, 1, newName) != -1)
    {
        customCout(conout, "Cliente ja existe, insira o novo nome"); // input new name
        newName = customCins(conout);
    }
    clientes[checkLineOf(clientes, 0, to_string(id))][1] = newName;
};

// ! Main Menus

/* Display Menu 1 EFECTUAR VENDA */
void displayMenu1(console_out *conout, string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    string text[] = {"1 - Selecionar produto", "2 - Checkout", "3 - Imprimir talao no ecra", "0 - Voltar"};
    const int biggestString = getBiggestStringSize(text, 4);
    bool repetition = true;
    while (repetition)
    {
        int choice = -1;
        do
        {
            system("cls||clear");
            showStock(conout, stock, sizeStock, true, true);
            showCart(conout, stock, cart, sizeCart, false);
            cout << setposx(conout->getsize().X / 2 - 14 / 2)
                 << setposy(1)
                 << "EFECTUAR VENDA"
                 << endl
                 << endl;
            cout << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[0]
                 << endl;
            cout << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[1]
                 << endl;
            cout << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[2]
                 << endl;
            cout << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[3]
                 << endl
                 << endl;
            customCout(conout, "Escolhe uma opcao");
            choice = customCini(conout);
            customCout(conout, "");
        } while (choice < 0 || choice > 3);
        switch (choice)
        {
        case 1:
            /* Selecionar produto */
            selecionarProduto(conout, stock, sizeStock, cart, sizeCart);
            break;
        case 2:
            /* Checkout */
            if (*sizeCart > 0)
            {
                checkout(conout, stock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
            }
            break;
        case 3:
            /* Imprimir talao no ecra */
            if (*sizeVendas > 0)
            {
                system("cls||clear");
                showVendas(conout, vendas, sizeVendas, clientes, false);
                int fatura;
                do
                {
                    customCout(conout, "Escolha fatura");
                    fatura = customCini(conout);
                } while (checkLineOf(vendas, 0, to_string(fatura)) == -1);
                imprimirTalao(conout, stock, clientes, vendas, compras, sizeCompras, fatura);
            }

            break;
        default:
            repetition = false;
            break;
        }
    }
}

/* Display Menu 2 COMPRAR STOCK */
void displayMenu2(console_out *conout, string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    string text[] = {"1 - Criacao de artigo novo", "2 - Adicionar stock a artigo existente", "3 - Eliminar produto", "0 - Voltar"};
    const int biggestString = getBiggestStringSize(text, 4);
    bool repetition = true;
    while (repetition)
    {
        int choice = -1;
        do
        {
            system("cls||clear");
            showStock(conout, stock, sizeStock, true, false);
            cout << setposx(conout->getsize().X / 2 - 13 / 2)
                 << setposy(1)
                 << "COMPRAR STOCK"
                 << endl
                 << endl;
            cout << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[0]
                 << endl;
            cout << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[1]
                 << endl;
            cout << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[2]
                 << endl;
            cout << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[3]
                 << endl
                 << endl;
            customCout(conout, "Escolhe uma opcao");
            choice = customCini(conout);
            customCout(conout, "");
        } while (choice < 0 || choice > 3);
        switch (choice)
        {
        case 1:
            /* Criacao de artigo novo */
            criacaoArtigo(conout, stock, sizeStock);
            break;
        case 2:
            /* Adicionar stock a artigo existente */
            adicionarStock(conout, stock, sizeStock);
            break;
        case 3:
            /* Eliminar produto */
            eliminarProduto(conout, stock, sizeStock);
            break;
        default:
            repetition = false;
            break;
        }
    }
}

/* Display Menu 3 CRIACAO DE RELATOROS */
void displayMenu3(console_out *conout, string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    string text[] = {"1 - Relatorio de stock", "2 - Relatorio de vendas por produto", "3 - Relatorio de vendas por cliente", "4 - Relatorio total de vendas", "0 - Voltar"};
    const int biggestString = getBiggestStringSize(text, 4);
    bool repetition = true;
    while (repetition)
    {
        int choice = -1;
        do
        {
            system("cls||clear");
            cout << setposx(conout->getsize().X / 2 - 20 / 2)
                 << setposy(1)
                 << "CRIACAO DE RELATOROS"
                 << endl
                 << endl
                 << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[0]
                 << endl
                 << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[1]
                 << endl
                 << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[2]
                 << endl
                 << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[3]
                 << endl
                 << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[4]
                 << endl
                 << endl;
            customCout(conout, "Escolhe uma opcao");
            choice = customCini(conout);
            customCout(conout, "");
        } while (choice < 0 || choice > 4);
        switch (choice)
        {
        case 1:
            /* Relatorio de stock */
            relatorioStock(conout, stock, sizeStock);
            break;
        case 2:
            /* Relatorio de vendas por produto */
            relatorioVendasProduto(conout, stock, sizeStock, compras, sizeCompras);
            break;
        case 3:
            /* Relatorio de vendas por cliente */
            relatorioVendasCliente(conout, stock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras);
            break;
        case 4:
            /* Relatorio total de vendas */
            relatorioTotalVendas(conout, stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras);
            break;
        default:
            repetition = false;
            break;
        }
    }
}

/* Display Menu 4 OPCOES DE CLIENTE */
void displayMenu4(console_out *conout, string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    string text[] = {"1 - Criar cliente", "2 - Alterar nome", "3 - Eliminar cliente", "0 - Voltar"};
    const int biggestString = getBiggestStringSize(text, 4);
    bool repetition = true;
    while (repetition)
    {
        int choice = -1;
        do
        {
            system("cls||clear");
            showClientes(conout, clientes, sizeClientes, true);
            cout << setposx((conout->getsize().X / 4) * 3 - 17 / 2)
                 << setposy(1)
                 << "OPCOES DE CLIENTE"
                 << endl
                 << endl;
            cout << setposx((conout->getsize().X / 4) * 3 - biggestString / 2)
                 << text[0]
                 << endl;
            cout << setposx((conout->getsize().X / 4) * 3 - biggestString / 2)
                 << text[1]
                 << endl;
            cout << setposx((conout->getsize().X / 4) * 3 - biggestString / 2)
                 << text[2]
                 << endl;
            cout << setposx((conout->getsize().X / 4) * 3 - biggestString / 2)
                 << text[3]
                 << endl
                 << endl;
            customCout(conout, "Escolhe uma opcao");
            choice = customCini(conout);
            customCout(conout, "");
        } while (choice < 0 || choice > 3);
        switch (choice)
        {
        case 1:
            /* Criar cliente */
            criarCliente(conout, clientes, sizeClientes);
            break;
        case 2:
            /* Alterar nome */
            alterarNomeCliente(conout, clientes, sizeClientes);
            break;
        case 3:
            /* Eliminar cliente */
            eliminarCliente(conout, clientes, sizeClientes);
            break;
        default:
            repetition = false;
            break;
        }
    }
}

/* Display Main Menu */
void displayMainMenu(console_out *conout, string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    string text[5] = {"1 - Efectuar venda", "2 - Compra Stock", "3 - Criacao de relatorios", "4 - Gestao de clientes", "0 - Sair"};
    const int biggestString = getBiggestStringSize(text, 5);
    bool repetition = true;
    while (repetition)
    {
        int choice = -1;
        do
        {
            system("cls||clear");
            cout << setposx(conout->getsize().X / 2 - 9 / 2)
                 << setposy(1)
                 << "MAIN MENU"
                 << endl
                 << endl;
            cout << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[0]
                 << endl;
            cout << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[1]
                 << endl;
            cout << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[2]
                 << endl;
            cout << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[3]
                 << endl;
            cout << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[4]
                 << endl
                 << endl;
            customCout(conout, "Escolhe uma opcao");
            choice = customCini(conout);
            customCout(conout, "");
        } while (choice < 0 || choice > 4);
        switch (choice)
        {
        case 1:
            /* Efectuar venda */
            displayMenu1(conout, stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
            break;
        case 2:
            /* Compra Stock */
            displayMenu2(conout, stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
            break;
        case 3:
            /* Criacao de relatorios */
            displayMenu3(conout, stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
            break;
        case 4:
            /* Manipulacao de clientes */
            displayMenu4(conout, stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
            break;
        default:
            string choice;
            do
            {
                system("cls||clear");
                cout << setposx(conout->getsize().X / 2 - 8 / 2)
                     << setposy(1)
                     << settextcolor(console_text_colors::red)
                     << "ATENCAO";
                customCout(conout, "Queres mesmo fechar a aplicacao? (S/N)");
                choice = customCins(conout);
                customCout(conout, "");
            } while (choice != "s" && choice != "S" && choice != "n" && choice != "N");
            if (choice == "s" || choice == "S")
            {
                repetition = false;
            }
            cout << settextcolor(console_text_colors::white);
            break;
        }
    }
}

// ! Main

int main()
{
    // remover scrollbars
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
    GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);
    short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
    short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;
    short scrBufferWidth = scrBufferInfo.dwSize.X;
    short scrBufferHeight = scrBufferInfo.dwSize.Y;
    COORD newSize;
    newSize.X = scrBufferWidth;
    newSize.Y = winHeight;
    int Status = SetConsoleScreenBufferSize(hOut, newSize);
    if (Status == 0)
    {
        cout << "SetConsoleScreenBufferSize() failed! Reason : " << GetLastError() << endl;
        exit(Status);
    }
    GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);
    cout << "Screen Buffer Size : " << scrBufferInfo.dwSize.X << " x " << scrBufferInfo.dwSize.Y << endl;

    // setlocale(LC_ALL, "");
    console_out_context ctxout;
    console_out conout(ctxout);
    conout.settitle("FRUIT INC.");
    // vec[item][atributo]
    string **stock = new string *[100];    // STOCK 0-id 1-nome 2-quantidade 3-preço_fabrica
    string **clientes = new string *[100]; // CLIENTE 0-id 1-nome 2-telefone 3-morada
    string **vendas = new string *[100];   // VENDA 0-id_fatura 1-#id_cliente 3-quantidade 4-valor_entregue 5-data_(auto)
    string **compras = new string *[100];  // COMPRAS 0-#id_fatura 1-#id_produto 2-quantidade
    string **cart = new string *[100];     // cart 0-id_produto 1-quantidade **tabela deitada**
    int sizeStock = 0;
    int sizeClientes = 0;
    int sizeVendas = 0;
    int sizeCompras = 0;
    int sizeCart = 0;
    for (int i = 0; i < 100; i++)
    {
        stock[i] = new string[4];
        clientes[i] = new string[4];
        vendas[i] = new string[4];
        compras[i] = new string[3];
        cart[i] = new string[2];
        for (int j = 0; j < 4; j++)
        {
            stock[i][j] = "";
            clientes[i][j] = "";
            vendas[i][j] = "";
        }
        for (int j = 0; j < 3; j++)
        {
            compras[i][j] = "";
        }
        for (int j = 0; j < 2; j++)
        {
            cart[i][j] = "";
        }
    }
    /*clientes[0][0] = "-1";
    clientes[0][1] = "Anonymous";
    clientes[0][2] = "NA";
    clientes[0][3] = "NA";*/
    sizeClientes++;
    //defaultValues(stock, &sizeStock, clientes, &sizeClientes, vendas, &sizeVendas, compras, &sizeCompras);
    txtGet("Tables/stock.txt", stock, &sizeStock);
    txtGet("Tables/clientes.txt", clientes, &sizeClientes);
    txtGet("Tables/vendas.txt", vendas, &sizeVendas);
    txtGet("Tables/compras.txt", compras, &sizeCompras);
    system("cls||clear");
    cout << setposx(conout.getsize().X / 2 - 10 / 2)
         << setposy(9)
         << "WELCOME TO"
         << endl
         << setposx(conout.getsize().X / 2 - 10 / 2)
         << "FRUIT INC."
         << endl
         << endl
         << setposx(conout.getsize().X / 2 - 12 / 2);
    pressEnter(&conout, 1, true);
    displayMainMenu(&conout, stock, &sizeStock, clientes, &sizeClientes, vendas, &sizeVendas, compras, &sizeCompras, cart, &sizeCart);
    system("cls||clear");
    apple(&conout, conout.getsize().X / 2, 1);
    cout << setposx(conout.getsize().X / 2 - 7 / 2)
         << setposy(12)
         << "Made by"
         << endl
         << setposx(conout.getsize().X / 2 - 22 / 2)
         << "Henrique Varela Vieira"
         << endl
         << setposx(conout.getsize().X / 2 - 8 / 2)
         << "T0123178"
         << endl
         << endl
         << setposx(conout.getsize().X / 2 - 12 / 2);
    txtSet("Tables/stock.txt", stock, sizeStock, 4);
    txtSet("Tables/clientes.txt", clientes, sizeClientes, 4);
    txtSet("Tables/vendas.txt", vendas, sizeVendas, 4);
    txtSet("Tables/compras.txt", compras, sizeCompras, 3);
    pressEnter(&conout, 1, true);
    system("cls||clear");
    return 0;
}
