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

// todo
// todo pagamento venda e compra 100+
// todo offer venda e compra 100+
/*  //? logic
    "compact table" but eliminates the lowest id                //? shiftTable(string **table, int C)  clear first line and compact normally
    and add new line to last place                              //? basic table[i][j] = someValue
    (sizeVariable - lowestId) should always be multiple of 100
*/

/* fills tables with default and example values*/
void defaultValues(string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras)
{
    // default values for stock
    stock[*sizeStock][0] = to_string(*sizeStock); // 0
    stock[*sizeStock][1] = "Banana";
    stock[*sizeStock][2] = "5";
    stock[*sizeStock][3] = "0.70";
    (*sizeStock)++;
    stock[*sizeStock][0] = to_string(*sizeStock); // 1
    stock[*sizeStock][1] = "Pear";
    stock[*sizeStock][2] = "10";
    stock[*sizeStock][3] = "1.00";
    (*sizeStock)++;
    stock[*sizeStock][0] = to_string(*sizeStock); // 2
    stock[*sizeStock][1] = "Strawberry";
    stock[*sizeStock][2] = "42";
    stock[*sizeStock][3] = "0.50";
    (*sizeStock)++;

    // default values for clientes
    clientes[0][0] = "-1";
    clientes[0][1] = "Anonymous";
    clientes[0][2] = "NA";
    clientes[0][3] = "NA";
    (*sizeClientes)++;
    clientes[*sizeClientes][0] = to_string(*sizeClientes - 1); // 0
    clientes[*sizeClientes][1] = "Henrique";
    clientes[*sizeClientes][2] = "935560176";
    clientes[*sizeClientes][3] = "Henrique St., 240";
    (*sizeClientes)++;
    clientes[*sizeClientes][0] = to_string(*sizeClientes - 1); // 1
    clientes[*sizeClientes][1] = "Maria";
    clientes[*sizeClientes][2] = "992485115";
    clientes[*sizeClientes][3] = "Maria St., 169";
    (*sizeClientes)++;
    clientes[*sizeClientes][0] = to_string(*sizeClientes - 1); // 2
    clientes[*sizeClientes][1] = "Manuel";
    clientes[*sizeClientes][2] = "112";
    clientes[*sizeClientes][3] = "Hospital St., WeeWoo";
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
};

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
    int x = xr - 18; // - largura da imagem
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

/* Displays a caution sign on screen */
void caution(console_out *conout, int xr, int yr)
{
    int x = xr - 16; // - largura da imagem
    cout << setposy(yr)
         << setposx(x + 15) << "888" << endl
         << setposx(x + 14) << "88888" << endl
         << setposx(x + 13) << "8888888" << endl
         << setposx(x + 12) << "888   888" << endl
         << setposx(x + 11) << "888     888" << endl
         << setposx(x + 10) << "888       888" << endl
         << setposx(x + 9) << "888   888   888" << endl
         << setposx(x + 8) << "888    888    888" << endl
         << setposx(x + 7) << "888     888     888" << endl
         << setposx(x + 6) << "888      888      888" << endl
         << setposx(x + 5) << "888       888       888" << endl
         << setposx(x + 4) << "888        888        888" << endl
         << setposx(x + 3) << "888                     888" << endl
         << setposx(x + 2) << "888          888          888" << endl
         << setposx(x + 1) << "888                         888" << endl
         << setposx(x) << "888888888888888888888888888888888" << endl
         << setposx(x) << "888888888888888888888888888888888" << endl;
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
             << "Insert a number"
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
             << "Insert a number"
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
    cout << setposx(0) << setw(conout->getsize().X) << "";
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
    while (line < 99)
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

/* deletes every line where X == value and compacts table */
void deleteEntry(string **table, int *sizeTable, int X, string value, int C)
{
    for (int i = 0; i < *sizeTable; i++)
    {
        if (table[i][X] == value)
        {
            cleanLine(table, i, C);
            compactTable(table, C);
            (*sizeTable)--;
            i--;
        }
    }
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
             << ("CLIENTS")
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
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl;
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
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl;
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
        if (biggestString[0] < 5)
        {
            biggestString[0] = 5;
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
             << "name|quant"
             << settextcolor(console_text_colors::white);
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl;
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
                if (j == 1 && item.length() == 0 && biggestString[1] < 9)
                {
                    biggestString[1] = 9;
                }
            }
        }
        if (biggestString[1] == 0)
        {
            biggestString[1] = 7;
        }
        int Xpos = left ? 1 : (conout->getsize().X / 2 - (biggestString[0] + biggestString[1] + biggestString[2] + 4) / 2);
        // top box
        cout << setposx(Xpos)
             << setposy(1)
             << settextcolor(console_text_colors::red)
             << ("Sales")
             << settextcolor(console_text_colors::white)
             << endl;
        cout << setposx(Xpos) << "O" << setfill('-') << setw(biggestString[0] + biggestString[1] + biggestString[2] + 3) << "O" << setfill(' ') << endl;
        // contents
        for (int i = 0; i < *sizeVendas; i++)
        {
            string nomeCliente = selectSQL(1, clientes, 0, vendas[i][1]);
            if (nomeCliente == "")
            {
                nomeCliente = "Deleted";
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
             << "invoice|name|date"
             << settextcolor(console_text_colors::white);
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl;
    }
};

// ! sub submenus

/* introdução dos valores de novo cliente
returns id*/
int clienteNovo(console_out *conout, string **clientes, int *sizeClientes)
{
    string nome, telefone, morada;
    customCout(conout, "Insert a name:"); // input do nome
    nome = customCins(conout);
    while (checkLineOf(clientes, 1, nome) != -1)
    {
        customCout(conout, "Client already exists, insert a new one:");
        nome = customCins(conout);
    }
    customCout(conout, "Insert a phone number:"); // input do tlf
    telefone = customCins(conout);
    customCout(conout, "Insert an address:"); // input da morada
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
    cout << setposx(conout->getsize().X / 2 - 7 / 2)
         << setposy(1)
         << "PAYMENT";
    customCout(conout, "Insert the money:"); // input do valor entregue pelo cliente
    float valorEntregue = customCinf(conout);
    while (valorEntregue < (precoAPagar * 1.30 * 1.23))
    {
        customCout(conout, "Value's too low, insert the money:");
        valorEntregue = customCinf(conout);
    }
    int idCliente = -1;
    string resposta;
    do // ja e cliente?
    {
        customCout(conout, "Already a client? (Y/N)");
        resposta = customCins(conout);
    } while (resposta != "y" && resposta != "Y" && resposta != "n" && resposta != "N");
    if (resposta == "y" || resposta == "Y")
    {
        showClientes(conout, clientes, sizeClientes, false);
        customCout(conout, "Insert client's number:");
        idCliente = customCini(conout);
    }
    else
    {
        do // quer ser cliente?
        {
            customCout(conout, "Want to be a client? (Y/N)");
            resposta = customCins(conout);
        } while (resposta != "y" && resposta != "Y" && resposta != "n" && resposta != "N");
        if (resposta == "y" || resposta == "Y")
        {
            idCliente = clienteNovo(conout, clientes, sizeClientes);
        }
    }
    // tables update
    time_t t = time(nullptr);
    tm *now = localtime(&t);
    string idFatura = to_string(checkHighestId(vendas, 0) + 1);
    if (*sizeVendas == 100)
    {
        string idToDelete = vendas[0][0];
        deleteEntry(vendas, sizeVendas, 0, idToDelete, 4);
        deleteEntry(compras, sizeCompras, 0, idToDelete, 3);
        vendas[*sizeVendas][0] = idFatura;
        vendas[*sizeVendas][1] = to_string(idCliente);
        vendas[*sizeVendas][2] = setPrecision2(valorEntregue);
        vendas[*sizeVendas][3] = to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
        (*sizeVendas)++;
        for (int i = 0; i < *sizeCart; i++)
        {
            if (*sizeCompras == 100)
            {
                string idToDelete = compras[0][0];
                deleteEntry(compras, sizeCompras, 0, idToDelete, 3);
                deleteEntry(vendas, sizeVendas, 0, idToDelete, 4);
                compras[*sizeCompras][0] = idFatura;
                compras[*sizeCompras][1] = cart[i][0];
                compras[*sizeCompras][2] = cart[i][1];
                (*sizeCompras)++;
                int lineInStock = checkLineOf(stock, 0, cart[i][0]);
                stock[lineInStock][2] = to_string(stoi(stock[lineInStock][2]) - stoi(cart[i][1]));
                cleanLine(cart, i, 2);
            }
            else
            {
                compras[*sizeCompras][0] = idFatura;
                compras[*sizeCompras][1] = cart[i][0];
                compras[*sizeCompras][2] = cart[i][1];
                (*sizeCompras)++;
                int lineInStock = checkLineOf(stock, 0, cart[i][0]);
                stock[lineInStock][2] = to_string(stoi(stock[lineInStock][2]) - stoi(cart[i][1]));
                cleanLine(cart, i, 2);
            }
        }
        *sizeCart = 0;
    }
    else
    {
        vendas[*sizeVendas][0] = idFatura;
        vendas[*sizeVendas][1] = to_string(idCliente);
        vendas[*sizeVendas][2] = setPrecision2(valorEntregue);
        vendas[*sizeVendas][3] = to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
        (*sizeVendas)++;
        for (int i = 0; i < *sizeCart; i++)
        {
            if (*sizeCompras == 100)
            {
                string idToDelete = compras[0][0];
                deleteEntry(compras, sizeCompras, 0, idToDelete, 3);
                deleteEntry(vendas, sizeVendas, 0, idToDelete, 4);
                compras[*sizeCompras][0] = idFatura;
                compras[*sizeCompras][1] = cart[i][0];
                compras[*sizeCompras][2] = cart[i][1];
                (*sizeCompras)++;
                int lineInStock = checkLineOf(stock, 0, cart[i][0]);
                stock[lineInStock][2] = to_string(stoi(stock[lineInStock][2]) - stoi(cart[i][1]));
                cleanLine(cart, i, 2);
            }
            else
            {
                compras[*sizeCompras][0] = idFatura;
                compras[*sizeCompras][1] = cart[i][0];
                compras[*sizeCompras][2] = cart[i][1];
                (*sizeCompras)++;
                int lineInStock = checkLineOf(stock, 0, cart[i][0]);
                stock[lineInStock][2] = to_string(stoi(stock[lineInStock][2]) - stoi(cart[i][1]));
                cleanLine(cart, i, 2);
            }
        }
        *sizeCart = 0;
    }
};

/* oferece a compra */
void offer(console_out *conout, string **stock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    float precoAPagar = precoTotalCart(stock, cart, sizeCart);
    system("cls||clear");
    showCart(conout, stock, cart, sizeCart, false);
    cout << setposx(conout->getsize().X / 2 - 8 / 2)
         << setposy(1)
         << "CONGRATS"
         << endl
         << endl
         << setposx(conout->getsize().X / 2 - 9 / 2)
         << "YOU WON!!";
    int idCliente = -1;
    string resposta;
    do // ja e cliente?
    {
        customCout(conout, "Already a client? (Y/N)");
        resposta = customCins(conout);
    } while (resposta != "y" && resposta != "Y" && resposta != "n" && resposta != "N");
    if (resposta == "y" || resposta == "Y")
    {
        showClientes(conout, clientes, sizeClientes, false);
        customCout(conout, "Insert client's number:");
        idCliente = customCini(conout);
    }
    else
    {
        do // quer ser cliente?
        {
            customCout(conout, "Want to be a client? (Y/N)");
            resposta = customCins(conout);
        } while (resposta != "y" && resposta != "Y" && resposta != "n" && resposta != "N");
        if (resposta == "y" || resposta == "Y")
        {
            idCliente = clienteNovo(conout, clientes, sizeClientes);
        }
    }
    // tables update
    time_t t = time(nullptr);
    tm *now = localtime(&t);
    string idFatura = to_string(checkHighestId(vendas, 0) + 1);
    if (*sizeVendas == 100)
    {
        string idToDelete = vendas[0][0];
        deleteEntry(vendas, sizeVendas, 0, idToDelete, 4);
        deleteEntry(compras, sizeCompras, 0, idToDelete, 3);
        vendas[*sizeVendas][0] = idFatura;
        vendas[*sizeVendas][1] = to_string(idCliente);
        vendas[*sizeVendas][2] = to_string(-1);
        vendas[*sizeVendas][3] = to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
        (*sizeVendas)++;
        for (int i = 0; i < *sizeCart; i++)
        {
            if (*sizeCompras == 100)
            {
                string idToDelete = compras[0][0];
                deleteEntry(compras, sizeCompras, 0, idToDelete, 3);
                deleteEntry(vendas, sizeVendas, 0, idToDelete, 4);
                compras[*sizeCompras][0] = idFatura;
                compras[*sizeCompras][1] = cart[i][0];
                compras[*sizeCompras][2] = cart[i][1];
                (*sizeCompras)++;
                int lineInStock = checkLineOf(stock, 0, cart[i][0]);
                stock[lineInStock][2] = to_string(stoi(stock[lineInStock][2]) - stoi(cart[i][1]));
                cleanLine(cart, i, 2);
            }
            else
            {
                compras[*sizeCompras][0] = idFatura;
                compras[*sizeCompras][1] = cart[i][0];
                compras[*sizeCompras][2] = cart[i][1];
                (*sizeCompras)++;
                int lineInStock = checkLineOf(stock, 0, cart[i][0]);
                stock[lineInStock][2] = to_string(stoi(stock[lineInStock][2]) - stoi(cart[i][1]));
                cleanLine(cart, i, 2);
            }
        }
        *sizeCart = 0;
    }
    else
    {
        vendas[*sizeVendas][0] = idFatura;
        vendas[*sizeVendas][1] = to_string(idCliente);
        vendas[*sizeVendas][2] = to_string(-1);
        vendas[*sizeVendas][3] = to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
        (*sizeVendas)++;
        for (int i = 0; i < *sizeCart; i++)
        {
            if (*sizeCompras == 100)
            {
                string idToDelete = compras[0][0];
                deleteEntry(compras, sizeCompras, 0, idToDelete, 3);
                deleteEntry(vendas, sizeVendas, 0, idToDelete, 4);
                compras[*sizeCompras][0] = idFatura;
                compras[*sizeCompras][1] = cart[i][0];
                compras[*sizeCompras][2] = cart[i][1];
                (*sizeCompras)++;
                int lineInStock = checkLineOf(stock, 0, cart[i][0]);
                stock[lineInStock][2] = to_string(stoi(stock[lineInStock][2]) - stoi(cart[i][1]));
                cleanLine(cart, i, 2);
            }
            else
            {
                compras[*sizeCompras][0] = idFatura;
                compras[*sizeCompras][1] = cart[i][0];
                compras[*sizeCompras][2] = cart[i][1];
                (*sizeCompras)++;
                int lineInStock = checkLineOf(stock, 0, cart[i][0]);
                stock[lineInStock][2] = to_string(stoi(stock[lineInStock][2]) - stoi(cart[i][1]));
                cleanLine(cart, i, 2);
            }
        }
        *sizeCart = 0;
    }
};

/* faz o sorteio */
void sorteio(console_out *conout, string **stock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    int randomValue = rand() % 100;
    if (randomValue >= 20)
    {
        pagamento(conout, stock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
    }
    else
    {
        offer(conout, stock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
    }
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
    nomeCliente = nomeCliente == "" ? "Deleted" : nomeCliente;
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
    if (width < (nomeCliente.length() + 3 + numCliente.length()))
    {
        width = nomeCliente.length() + 3 + numCliente.length();
    }

    // top
    cout << setposy(3)
         << setposx(Xpos)
         << whiteBG(conout, width) << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width / 2 - 9 / 2) << "FRUIT INC" << endl
         << setposx(Xpos) << whiteBG(conout, width) << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width / 2 - (7 + to_string(idFatura).length()) / 2) << "Invoice " << idFatura << endl
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
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width - 9 - total.length()) << "wo/IVA " << total << euro(conout) << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width - 6 - total.length()) << "IVA " << setPrecision2(stof(total) * 0.23) << euro(conout) << endl
         << setposx(Xpos) << whiteBG(conout, width) << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width - 8 - setPrecision2(stof(total) * 1.23).length()) << "w/IVA " << setPrecision2(stof(total) * 1.23) << euro(conout) << endl;
    if (stoi(entregue) == -1)
    {
        cout << setposx(Xpos) << whiteBG(conout, width) << endl
             << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width - 7 - setPrecision2(stof(total) * 1.23).length()) << "OFFER" << endl
             << setposx(Xpos) << whiteBG(conout, width);
    }
    else
    {
        cout << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width - 8 - entregue.length()) << "Payed " << entregue << euro(conout) << endl
             << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width - 9 - troco.length()) << "Change " << troco << euro(conout) << endl
             << setposx(Xpos) << whiteBG(conout, width);
    }
    cout << setbgcolor(console_bg_colors::black) << settextcolor(console_text_colors::white) << endl;
    pressEnter(conout, 2, false);
};

/* Selecionar produto
submenu */
void selecionarProduto(console_out *conout, string **stock, int *sizeStock, string **cart, int *sizeCart)
{
    system("cls||clear");
    cout << setposx(conout->getsize().X / 2 - 15 / 2)
         << setposy(1)
         << "SELECT PRODUCT";
    showStock(conout, stock, sizeStock, true, true);
    showCart(conout, stock, cart, sizeCart, false);
    int id, quantidade, quantStock;
    do // input product
    {
        customCout(conout, "Select a product? (id)");
        id = customCini(conout);
    } while (checkLineOf(stock, 0, to_string(id)) == -1);
    string inCart = selectSQL(1, cart, 0, to_string(id));
    int numCart = stoi((inCart == "") ? "0" : inCart);
    quantStock = stoi(selectSQL(2, stock, 0, to_string(id))) - numCart;
    do // input quantity
    {
        customCout(conout, "Quantity?");
        quantidade = customCini(conout);
    } while (quantStock < quantidade || (numCart + quantidade) < 0 || quantidade < 0);
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

/* Remover produto
submenu */
void removerProduto(console_out *conout, string **stock, int *sizeStock, string **cart, int *sizeCart)
{
    system("cls||clear");
    cout << setposx(conout->getsize().X / 2 - 26 / 2)
         << setposy(1)
         << "REMOVE A PRODUCT";
    showStock(conout, stock, sizeStock, true, true);
    showCart(conout, stock, cart, sizeCart, false);
    int id, quantidade, quantStock;
    do // input product
    {
        customCout(conout, "Select what to remove? (id)");
        id = customCini(conout);
    } while (checkLineOf(cart, 0, to_string(id)) == -1);
    string inCart = selectSQL(1, cart, 0, to_string(id));
    int numCart = stoi((inCart == "") ? "0" : inCart);
    quantStock = stoi(selectSQL(2, stock, 0, to_string(id))) - numCart;
    do // input quantity
    {
        customCout(conout, "Quantity?");
        quantidade = customCini(conout);
    } while (numCart < quantidade || quantidade < 0);
    customCout(conout, "");
    // tables update
    if (quantidade != 0)
    {
        cart[checkLineOf(cart, 0, to_string(id))][1] = to_string(stoi(cart[checkLineOf(cart, 0, to_string(id))][1]) - quantidade);
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
        customCout(conout, "Confirm you want to pay (Y/N)");
        choice = customCins(conout);
        customCout(conout, "");
    } while (choice != "y" && choice != "Y" && choice != "n" && choice != "N");
    if (choice == "y" || choice == "Y")
    {
        sorteio(conout, stock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
        imprimirTalao(conout, stock, clientes, vendas, compras, sizeCompras, checkHighestId(vendas, 0));
    }
};

// ! Comprar Stock

/* Criacao de artigo novo */
void criacaoArtigo(console_out *conout, string **stock, int *sizeStock)
{
    system("cls||clear");
    cout << setposx(conout->getsize().X / 2 - 21 / 2)
         << setposy(1)
         << "CREATE A NEW PRODUCT";
    float preco_fabrica;
    string nome;
    customCout(conout, "Insert the name of the product: "); // input product name
    nome = customCins(conout);
    while (checkLineOf(stock, 1, nome) != -1)
    {
        customCout(conout, "Product already exists, insert a new one: ");
        nome = customCins(conout);
    }
    customCout(conout, "Base price: "); // input value
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
    cout << setposx(conout->getsize().X / 2 - 9 / 2)
         << setposy(1)
         << "ADD STOCK";
    showStock(conout, stock, sizeStock, true, false);
    int id, quantidade;
    do // input product
    {
        customCout(conout, "Select the product (id)");
        id = customCini(conout);
    } while (checkLineOf(stock, 0, to_string(id)) == -1);
    do // quantity
    {
        customCout(conout, "Quantity to add?");
        quantidade = customCini(conout);
    } while (quantidade < 0);
    stock[checkLineOf(stock, 0, to_string(id))][2] = to_string(stoi(stock[checkLineOf(stock, 0, to_string(id))][2]) + quantidade);
};

/* Eliminar produto */
void eliminarProduto(console_out *conout, string **stock, int *sizeStock)
{
    system("cls||clear");
    cout << setposx(conout->getsize().X / 2 - 14 / 2)
         << setposy(1)
         << "DELETE PRODUCT";
    showStock(conout, stock, sizeStock, true, false);
    int id;
    do // input product
    {
        customCout(conout, "Select the product: (id)");
        id = customCini(conout);
    } while (checkLineOf(stock, 0, to_string(id)) == -1);
    string choice;
    do // input confirm
    {
        customCout(conout, "Confirm you want to delete? (Y/N)");
        choice = customCins(conout);
    } while (choice != "y" && choice != "Y" && choice != "n" && choice != "N");
    if (choice == "y" || choice == "Y") // tables update
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
         << setposx(Xpos - 21 - setPrecision2(valorTotal).length()) << "Total value wo/IVA: " << settextcolor(console_text_colors::light_yellow) << setPrecision2(valorTotal * 1.30) << euro(conout) << settextcolor(console_text_colors::white) << endl
         << setposx(Xpos - 18 - setPrecision2(valorTotal).length()) << "Possible gains: " << settextcolor(console_text_colors::light_yellow) << setPrecision2(valorTotal * 0.3) << euro(conout) << settextcolor(console_text_colors::white) << endl;
    pressEnter(conout, 2, true);
};

/* Relatorio de vendas por produto */
void relatorioVendasProduto(console_out *conout, string **stock, int *sizeStock, string **compras, int *sizeCompras)
{
    system("cls||clear");
    showStock(conout, stock, sizeStock, true, false);
    customCout(conout, "Insert the product name:"); // input product name
    string produto = customCins(conout);
    while (checkLineOf(stock, 1, produto) == -1)
    {
        customCout(conout, "Product not found, insert again:");
        produto = customCins(conout);
    }
    system("cls||clear");
    int quantidadeInfo = 4;
    string text[] = {"Quantity in stock: ", "Quantity sold: ", "Possible gains: ", "Gains until now: "};
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
         << setposx(middle - 24 / 2) << "SALE SUMMARY PER PRODUCT" << endl
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
    customCout(conout, "Insert clients name:"); // input client name
    string cliente = customCins(conout);
    while (checkLineOf(clientes, 1, cliente) == -1)
    {
        customCout(conout, "Client not found, insert again:");
        cliente = customCins(conout);
    }
        int middle = conout->getsize().X / 2;

    if (checkLineOf(vendas, 1, selectSQL(0, clientes, 1, cliente)) == -1)
    {
        system("cls||clear");
        cout << setposy(2)
         << setposx(middle - 24 / 2) << "SALES SUMMARY PER CLIENT" << endl
         << endl
         << setposx(middle - cliente.length() / 2) << cliente << endl
         << endl;
        customCout(conout, "Client hasn't bought anything yet");
        pressEnter(conout, 1, false);
        return;
    }
    

    system("cls||clear");
    string text[] = {"Number of transactions: ", "Quantity bought: ", "Money spent: ", "Gains given: "};
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
         << setposx(middle - 24 / 2) << "SALES SUMMARY PER CLIENT" << endl
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
    string text[] = {"Most sold product: ", "Least sold product: ", "Product with highest gains: ", "Best customer: "};
    string output[] = {"", "", "", ""}; // maisVendido, menosVendido, maisLucro, melhorCliente
    // produto mais vendido e menos vendido
    int quantMaior = INT_MIN;
    int quantMenor = INT_MAX;
    float lucro = INT_MIN;
    for (int i = 0; i < *sizeStock; i++)
    {
        int quantTemp = 0, quantVendida = 0;
        for (int j = 0; j < *sizeCompras; j++)
        {
            if (stock[i][0] == compras[j][1])
            {
                quantTemp += stoi(compras[j][2]);
                if (selectSQL(2, vendas, 0, compras[j][0]) != "-1")
                {
                    quantVendida += stoi(compras[j][2]);
                }
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
        float lucroTemp = quantVendida * stof(selectSQL(3, stock, 0, to_string(i))) * 0.30;
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
            if (vendas[j][1] == clientes[i][0] && vendas[j][2] != "-1")
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
         << setposx(middle - 25 / 2) << "TOTAL SALES SUMMARY" << endl
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
    cout << setposx(conout->getsize().X / 2 - 13 / 2)
         << setposy(1)
         << "DELETE CLIENT";
    showClientes(conout, clientes, sizeClientes, false);
    int id;
    do // input client number
    {
        customCout(conout, "Insert clients id:");
        id = customCini(conout);
    } while (checkLineOf(clientes, 0, to_string(id)) == -1);
    string choice;
    do // input confirm
    {
        customCout(conout, "Confirm you want to delete? (Y/N)");
        choice = customCins(conout);
    } while (choice != "y" && choice != "Y" && choice != "n" && choice != "N");
    if (choice == "y" || choice == "Y")
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
    cout << setposx(conout->getsize().X / 2 - 19 / 2)
         << setposy(1)
         << "CHANGE CLIENTS NAME";
    showClientes(conout, clientes, sizeClientes, false);
    int id;
    do // input client number
    {
        customCout(conout, "Insert clients id:");
        id = customCini(conout);
    } while (checkLineOf(clientes, 0, to_string(id)) == -1);
    string newName;
    customCout(conout, "Insert a new name:"); // input new name
    newName = customCins(conout);
    while (checkLineOf(clientes, 1, newName) != -1)
    {
        customCout(conout, "Client already exists, insert a new name:"); // input new name
        newName = customCins(conout);
    }
    clientes[checkLineOf(clientes, 0, to_string(id))][1] = newName;
};

// ! Definiçoes

/* Deletes the content from all the tables */
void deleteTables(string **stock, string **clientes, string **vendas, string **compras, string **cart)
{
    for (int i = 0; i < 100; i++)
    {
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
};

/* Saves the table content in txt form */
void saveTables(string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    system("mkdir Tables");
    txtSet("Tables/stock.txt", stock, *sizeStock, 4);
    txtSet("Tables/clientes.txt", clientes, *sizeClientes, 4);
    txtSet("Tables/vendas.txt", vendas, *sizeVendas, 4);
    txtSet("Tables/compras.txt", compras, *sizeCompras, 3);
};

/* Le as tabelas em txt e guarda nas matrizes */
void readTables(string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    deleteTables(stock, clientes, vendas, compras, cart);
    *sizeStock = 0;
    *sizeClientes = 0;
    *sizeVendas = 0;
    *sizeCompras = 0;
    *sizeCart = 0;
    txtGet("Tables/stock.txt", stock, sizeStock);
    txtGet("Tables/clientes.txt", clientes, sizeClientes);
    txtGet("Tables/vendas.txt", vendas, sizeVendas);
    txtGet("Tables/compras.txt", compras, sizeCompras);
};

// ! Main Menus

/* Display Menu 1 EFECTUAR VENDA */
void displayMenu1(console_out *conout, string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    string text[] = {"1 - Select product", "2 - Remove product", "3 - Checkout", "4 - Print invoice", "0 - Back"};
    const int biggestString = getBiggestStringSize(text, 5);
    bool repetition = true;
    while (repetition)
    {
        int choice = -1;
        do
        {
            system("cls||clear");
            showStock(conout, stock, sizeStock, true, true);
            showCart(conout, stock, cart, sizeCart, false);
            cout << setposx(conout->getsize().X / 2 - 11 / 2)
                 << setposy(1)
                 << "MAKE A SALE"
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
                 << endl
                 << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[4]
                 << endl
                 << endl;
            customCout(conout, "Choose an option");
            choice = customCini(conout);
            customCout(conout, "");
        } while (choice < 0 || choice > 4);
        switch (choice)
        {
        case 1:
            /* Selecionar produto */
            selecionarProduto(conout, stock, sizeStock, cart, sizeCart);
            break;
        case 2:
            /* Remover produto */
            if (*sizeCart > 0)
            {
                removerProduto(conout, stock, sizeStock, cart, sizeCart);
            }
            break;
        case 3:
            /* Checkout */
            if (*sizeCart > 0)
            {
                checkout(conout, stock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
            }
            break;
        case 4:
            /* Imprimir talao no ecra */
            if (*sizeVendas > 0)
            {
                system("cls||clear");
                showVendas(conout, vendas, sizeVendas, clientes, false);
                int fatura;
                do
                {
                    customCout(conout, "Choose invoice");
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
    string text[] = {"1 - Create a new product", "2 - Add stock to product", "3 - Delete product", "0 - Back"};
    const int biggestString = getBiggestStringSize(text, 4);
    bool repetition = true;
    while (repetition)
    {
        int choice = -1;
        do
        {
            system("cls||clear");
            showStock(conout, stock, sizeStock, true, false);
            cout << setposx(conout->getsize().X / 2 - 9 / 2)
                 << setposy(1)
                 << "BUY STOCK"
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
                 << endl
                 << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[3]
                 << endl
                 << endl;
            customCout(conout, "Choose an option");
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
    string text[] = {"1 - Stock summary", "2 - Sales summary per product", "3 - Sales summary per client", "4 - Total sales summary", "0 - Back"};
    const int biggestString = getBiggestStringSize(text, 4);
    bool repetition = true;
    while (repetition)
    {
        int choice = -1;
        do
        {
            system("cls||clear");
            cout << setposx(conout->getsize().X / 2 - 9 / 2)
                 << setposy(1)
                 << "SUMMARIES"
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
                 << endl
                 << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[4]
                 << endl
                 << endl;
            customCout(conout, "Choose an option");
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
    string text[] = {"1 - Create client", "2 - Change clients name", "3 - Delete client", "0 - Back"};
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
                 << "CLIENT OPTIONS"
                 << endl
                 << endl
                 << setposx((conout->getsize().X / 4) * 3 - biggestString / 2)
                 << text[0]
                 << endl
                 << setposx((conout->getsize().X / 4) * 3 - biggestString / 2)
                 << text[1]
                 << endl
                 << setposx((conout->getsize().X / 4) * 3 - biggestString / 2)
                 << text[2]
                 << endl
                 << endl
                 << setposx((conout->getsize().X / 4) * 3 - biggestString / 2)
                 << text[3]
                 << endl
                 << endl;
            customCout(conout, "Choose an option");
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

/* Menu definiçoes */
void def(console_out *conout, string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    string bd;
    do
    {
        system("cls||clear");
        cout << setposx(conout->getsize().X / 2 - 7 / 2)
             << setposy(1)
             << settextcolor(console_text_colors::red)
             << "CAUTION";
        caution(conout, conout->getsize().X / 2, 4);
        customCout(conout, "Do you really want to change the data base? (Y/N)");
        bd = customCins(conout);
        customCout(conout, "");
        cout << settextcolor(console_text_colors::white);
    } while (bd != "y" && bd != "Y" && bd != "n" && bd != "N");
    if (bd == "y" || bd == "Y")
    {
        string text[4] = {"1 - Update DB", "2 - Save DB", "3 - DB default", "0 - Back"};
        const int biggestString = getBiggestStringSize(text, 4);
        bool repetition = true;
        while (repetition)
        {
            int choice = -1;
            do
            {
                system("cls||clear");
                cout << setposx(conout->getsize().X / 2 - 10 / 2)
                     << setposy(1)
                     << "SETTINGS"
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
                     << endl
                     << setposx(conout->getsize().X / 2 - biggestString / 2)
                     << text[3]
                     << endl
                     << endl;
                customCout(conout, "Choose an option");
                choice = customCini(conout);
                customCout(conout, "");
            } while (choice < 0 || choice > 3);
            switch (choice)
            {
            case 1:
                /* Ler TxT */
                readTables(stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
                repetition = false;
                break;
            case 2:
                /* Escrever TxT */
                saveTables(stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
                repetition = false;
                break;
            case 3:
                /* Voltar a default db */
                deleteTables(stock, clientes, vendas, compras, cart);
                *sizeStock = 0;
                *sizeClientes = 0;
                *sizeVendas = 0;
                *sizeCompras = 0;
                *sizeCart = 0;
                defaultValues(stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras);
                saveTables(stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
                repetition = false;
                break;
            default:
                repetition = false;
                break;
            }
        }
    }
};

/* Display Main Menu */
void displayMainMenu(console_out *conout, string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    string text[6] = {"1 - Make a sale", "2 - Buy stock", "3 - Summaries", "4 - Manage clients", "5 - Settings", "0 - Quit"};
    const int biggestString = getBiggestStringSize(text, 6);
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
                 << endl
                 << setposx(conout->getsize().X / 2 - biggestString / 2)
                 << text[5]
                 << endl
                 << endl;
            customCout(conout, "Choose an option");
            choice = customCini(conout);
            customCout(conout, "");
        } while (choice < 0 || choice > 5);
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
        case 5:
            /* defeniçoes */
            def(conout, stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
            break;
        default:
            string ex;
            do
            {
                system("cls||clear");
                cout << setposx(conout->getsize().X / 2 - 7 / 2)
                     << setposy(1)
                     << settextcolor(console_text_colors::red)
                     << "CAUTION";
                caution(conout, conout->getsize().X / 2, 4);
                customCout(conout, "Do you really want to quit? (Y/N)");
                ex = customCins(conout);
                customCout(conout, "");
            } while (ex != "y" && ex != "Y" && ex != "n" && ex != "N");
            if (ex == "y" || ex == "Y")
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

    srand(time(NULL));
    console_out_context ctxout;
    console_out conout(ctxout);
    conout.settitle("FRUIT INC.");
    // vec[item][atributo]
    string **stock = new string *[100];    // STOCK 0-id 1-nome 2-quantidade 3-preço_fabrica
    string **clientes = new string *[100]; // CLIENTE 0-id 1-nome 2-telefone 3-morada
    string **vendas = new string *[100];   // VENDA 0-id_fatura 1-#id_cliente 3-valor_entregue 4-data_(auto)
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
    }
    deleteTables(stock, clientes, vendas, compras, cart);
    /*clientes[0][0] = "-1";
    clientes[0][1] = "Anonymous";
    clientes[0][2] = "NA";
    clientes[0][3] = "NA";*/
    // defaultValues(stock, &sizeStock, clientes, &sizeClientes, vendas, &sizeVendas, compras, &sizeCompras);
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
