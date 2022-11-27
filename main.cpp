#include "Headerfiles/conmanip.h"
#include <sstream>
#include <iomanip>
#include <locale.h>

using namespace conmanip;
using namespace std;

/*////TO DO
to learn inicio do main
https://stackoverflow.com/questions/3471520/how-to-remove-scrollbars-in-console-windows-c
*/
// TODO:
// TODO: redo checkout
// TODO: Imprimir talao no ecra
// TODO: Relatorio de stock
// TODO: Relatorio de vendas por produto
// TODO: Relatorio total de vendas
// TODO: clean unused parameters in display funcs

/* fills tables with default and example values */
void defaultValues(string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    // default values for stock
    stock[*sizeStock][0] = to_string(*sizeStock);
    stock[*sizeStock][1] = "Banana";
    stock[*sizeStock][2] = "5";
    stock[*sizeStock][3] = "0.70";
    (*sizeStock)++;
    stock[*sizeStock][0] = to_string(*sizeStock);
    stock[*sizeStock][1] = "Pera";
    stock[*sizeStock][2] = "10";
    stock[*sizeStock][3] = "1.00";
    (*sizeStock)++;
    stock[*sizeStock][0] = to_string(*sizeStock);
    stock[*sizeStock][1] = "Morango";
    stock[*sizeStock][2] = "42";
    stock[*sizeStock][3] = "0.50";
    (*sizeStock)++;

    // default values for clientes
    clientes[*sizeClientes][0] = to_string(*sizeClientes - 1);
    clientes[*sizeClientes][1] = "Henrique";
    clientes[*sizeClientes][2] = "935560176";
    clientes[*sizeClientes][3] = "R. Henrique, 240";
    (*sizeClientes)++;
    clientes[*sizeClientes][0] = to_string(*sizeClientes - 1);
    clientes[*sizeClientes][1] = "Maria";
    clientes[*sizeClientes][2] = "992485115";
    clientes[*sizeClientes][3] = "R. Maria, 169";
    (*sizeClientes)++;
    clientes[*sizeClientes][0] = to_string(*sizeClientes - 1);
    clientes[*sizeClientes][1] = "Manuel";
    clientes[*sizeClientes][2] = "112";
    clientes[*sizeClientes][3] = "R. do Hospital, WeeWoo";
    (*sizeClientes)++;
};

// ! Useless Flavor

/* Displays an apple on screen */
void apple(console_out *conout, int xr, int yr)
{
    int x = xr - 18;
    cout << setposy(yr)
         << setposx(x + 29) << settextcolor(console_text_colors::green) << "___\n"
         << setposx(x + 26) << "_/`.-'`.\n"
         << setposx(x + 16) << settextcolor(console_text_colors::yellow) << "_" << setposx(x + 24) << settextcolor(console_text_colors::green) << "_/` .  _.'\n"
         << settextcolor(console_text_colors::red)
         << setposx(x + 7) << "..:::::." << settextcolor(console_text_colors::yellow) << "(_)   " << settextcolor(console_text_colors::green) << "/` _.'_./\n"
         << settextcolor(console_text_colors::red)
         << setposx(x + 5) << ".oooooooooo" << settextcolor(console_text_colors::yellow) << "\\ \\" << settextcolor(console_text_colors::red) << "o" << settextcolor(console_text_colors::green) << "/.-'__.'" << settextcolor(console_text_colors::red) << "o.\n"
         << settextcolor(console_text_colors::red)
         << setposx(x + 4) << ".ooooooooo`._" << settextcolor(console_text_colors::yellow) << "\\_|" << settextcolor(console_text_colors::green) << "_.'`" << settextcolor(console_text_colors::red) << "oooooob.\n"
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

string whiteBG(console_out *conout, int width)
{
    cout << setbgcolor(console_bg_colors::white) << settextcolor(console_text_colors::black);
    for (int i = 0; i < width; i++)
    {
        cout << " ";
    }
    conout->setposx(conout->getposx() - width);
    return "";
};

// ! Custom io funcs

/* custom CIN
only accepts and returns ints */
int customCini(console_out *conout)
{
    int choice;
    cout << setposx(conout->getsize().X / 2 - 14)
         << setposy(conout->getsize().Y - 4)
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

    while (!(cin >> setposx(conout->getsize().X / 2 - 12) >> setposy(conout->getsize().Y - 3) >> choice))
    {
        cout << setposx(conout->getsize().X / 2 - 14)
             << setposy(conout->getsize().Y - 3)
             << "|                            |"
             << endl
             << endl
             << setposx(conout->getsize().X / 2 - 14)
             << settextcolor(console_text_colors::yellow)
             << "insira um numero"
             << settextcolor(console_text_colors::white);
        cin.clear();
        cin.ignore(100, '\n');
    }
    return choice;
};

/* custom CIN
recieves and outputs strings */
string customCins(console_out *conout)
{
    char first;
    string choice;
    cout << setposx(conout->getsize().X / 2 - 14)
         << setposy(conout->getsize().Y - 4)
         << "O----------------------------O"
         << endl
         << setposx(conout->getsize().X / 2 - 14)
         << "|                            |"
         << endl
         << setposx(conout->getsize().X / 2 - 14)
         << "O----------------------------O"
         << endl;
    conout->setposx(conout->getsize().X / 2 - 12);
    conout->setposy(conout->getsize().Y - 3);
    cin >> first;
    getline(cin, choice);
    return first + choice;
};

/* custom CIN
only accepts and returns floats */
float customCinf(console_out *conout)
{
    float choice;
    int Xpos = conout->getsize().X / 2 - 14;
    cout << setposx(Xpos)
         << setposy(conout->getsize().Y - 4)
         << "O----------------------------O"
         << endl
         << setposx(Xpos)
         << "|                            |"
         << endl
         << setposx(Xpos)
         << "O----------------------------O"
         << endl;
    for (int i = Xpos; i < (Xpos + 30); i++)
    {
        cout << setposx(i) << setposy(conout->getsize().Y - 1) << " ";
    }
    while (!(cin >> setposx(conout->getsize().X / 2 - 12) >> setposy(conout->getsize().Y - 3) >> choice))
    {
        cout << setposx(conout->getsize().X / 2 - 14)
             << setposy(conout->getsize().Y - 3)
             << "|                            |"
             << endl
             << endl
             << setposx(conout->getsize().X / 2 - 14)
             << settextcolor(console_text_colors::yellow)
             << "insira um numero"
             << settextcolor(console_text_colors::white);
        cin.clear();
        cin.ignore(100, '\n');
    }
    return choice;
};

/* custom COUT
outputs ontop of the input box */
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

/* selectSQL
returns the content of the table in index_return where index_value is value*/
string selectSQL(string value, int index_value, string **table, int index_return)
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

/* joinSelect
returns the content of the table2[index_return] where table1[index_value] == value and table1[index_join1] == table2[index_join2]*/
string joinSelect(string value, int index_value, string **table1, int index_join1, int index_join2, string **table2, int index_return)
{
    return selectSQL(selectSQL(value, index_value, table1, index_join1), index_join2, table2, index_return);
};

/* joinSelectArray
changes the contents in a temporary array table_return created before with the contents of a column of the table2[index_return] where table1[index_value] == value and table1[index_join1] == table2[index_join2]
returns the size of the useful part of the array*/
int joinSelectArray(string value, int index_value, string **table1, int index_join1, int index_join2, string **table2, int index_return, string *array_return)
{
    int sizeArr = 0;
    for (int i = 0; i < 100; i++)
    {
        if (table1[i][index_value] == value)
        {
            for (int j = 0; j < 100; j++)
            {
                if (table1[i][index_join1] == table2[j][index_join2])
                {
                    array_return[sizeArr] = table2[j][index_return];
                    sizeArr++;
                }
            }
        }
    }
    return sizeArr;
};

/* check first empty line in table
returns the index of the first empty line */
int checkFirstEmptyLine(string **table)
{
    for (int i = 0; i < 100; i++)
    {
        if (table[i][0] == "")
        {
            return i;
        }
    }
    return -1;
};

/* check first line where table[Y][X] is value
returns Y */
int checkLineOf(string **table, int *tableSize, int X, string value)
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

/* clean line from table V*/
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

/* checks the highest value in a column from a table
returns the highest id from the table */
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

// ! Usefull funcs

/* getBiggestStringSize
returns size of biggest string in the array */
int getBiggestStringSize(string *text, int size)
{
    int length = 0;
    for (int i = 0; i < size; i++)
    {
        if (text[i].length() > length)
        {
            length = text[i].length();
        }
    }
    return length;
};

/* precoTotalCart
Calculates the value in the cart */
float precoTotalCart(string **stock, int *sizeStock, string **cart, int *sizeCart)
{
    float total = 0;
    for (int i = 0; i < *sizeCart; i++)
    {
        total += stoi(cart[i][1]) * stof(selectSQL(cart[i][0], 0, stock, 3));
    }
    return total;
};

/* setPrecision2
returns float as a string with 2 decimal places */
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
        cout << setposx(Xpos)
             << setposy(1)
             << settextcolor(console_text_colors::red)
             << ("CLIENTES")
             << settextcolor(console_text_colors::white)
             << endl;
        cout << setposx(Xpos) << "O";
        for (int i = 0; i < (biggestString[0] + biggestString[1] + biggestString[2] + biggestString[3] + 3); i++)
        {
            cout << "-";
        }
        cout << "O" << endl;
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
        cout << setposx(Xpos) << "O";
        for (int i = 0; i < (biggestString[0] + biggestString[1] + biggestString[2] + biggestString[3] + 3); i++)
        {
            cout << "-";
        }
        cout << "O" << endl;
        cout << setposx(Xpos)
             << settextcolor(console_text_colors::light_blue)
             << "id|name|phone|address"
             << settextcolor(console_text_colors::white);
    }
};

/* Displays Stock table */
void showStock(console_out *conout, string **stock, int *sizeStock, string **cart, bool left)
{
    if (*sizeStock != 0)
    {
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
        cout << setposx(Xpos)
             << setposy(1)
             << settextcolor(console_text_colors::red)
             << ("STOCK")
             << settextcolor(console_text_colors::white)
             << endl;
        cout << setposx(Xpos) << "O";
        for (int i = 0; i < (biggestString[0] + biggestString[1] + biggestString[2] + biggestString[3] + 3); i++)
        {
            cout << "-";
        }
        cout << "O" << endl;
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
                 << stock[i][3]
                 << setposx(Xpos + biggestString[0] + biggestString[1] + biggestString[2] + biggestString[3] + 4)
                 << "|"
                 << endl;
        }
        cout << setposx(Xpos) << "O";
        for (int i = 0; i < (biggestString[0] + biggestString[1] + biggestString[2] + biggestString[3] + 3); i++)
        {
            cout << "-";
        }
        cout << "O" << endl;
        cout << setposx(Xpos)
             << settextcolor(console_text_colors::light_blue)
             << "id|name|quant|price"
             << settextcolor(console_text_colors::white);
    }
};

/* Displays Cart table */
void showCart(console_out *conout, string **stock, int *sizeStock, string **cart, int *sizeCart, bool left)
{
    if (*sizeCart != 0)
    {
        int biggestString[] = {0, 0};
        for (int i = 0; i < *sizeCart; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                string item;
                switch (j)
                {
                case 0:
                    item = selectSQL(cart[i][0], 0, stock, 1);
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
        cout << setposx(Xpos)
             << setposy(1)
             << settextcolor(console_text_colors::red)
             << ("CART")
             << settextcolor(console_text_colors::white)
             << endl;
        cout << setposx(Xpos) << "O";
        for (int i = 0; i < (biggestString[0] + biggestString[1] + 1); i++)
        {
            cout << "-";
        }
        cout << "O" << endl;
        for (int i = 0; i < *sizeCart; i++)
        {
            cout << setposx(Xpos)
                 << "|"
                 << selectSQL(cart[i][0], 0, stock, 1)
                 << setposx(Xpos + biggestString[0] + 1)
                 << "|"
                 << cart[i][1]
                 << setposx(Xpos + biggestString[0] + biggestString[1] + 2)
                 << "|"
                 << endl;
        }
        string valor = setPrecision2(precoTotalCart(stock, sizeStock, cart, sizeCart) * 1.30 * 1.23);
        char euro = 128;
        cout << setposx(Xpos)
             << "|"
             << setposx((Xpos + biggestString[0] + biggestString[1] + 1) - valor.length())
             << valor
             << WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"€", wcslen(L"€"), NULL, NULL)
             << setposx(Xpos + biggestString[0] + biggestString[1] + 2)
             << "|"
             << endl;
        cout << setposx(Xpos) << "O";
        for (int i = 0; i < (biggestString[0] + biggestString[1] + 1); i++)
        {
            cout << "-";
        }
        cout << "O" << endl;
        cout << setposx(Xpos)
             << settextcolor(console_text_colors::light_blue)
             << "nome|quant"
             << settextcolor(console_text_colors::white);
    }
};

void showVendas(console_out *conout, string **vendas, int *sizeVendas, string **clientes, int *sizeClientes, bool left)
{
    if (*sizeVendas != 0)
    {
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
                    item = selectSQL(vendas[i][1], 0, clientes, 1);
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
        int Xpos = left ? 1 : (conout->getsize().X / 2 - (biggestString[0] + biggestString[1] + biggestString[2] + 4) / 2);
        cout << setposx(Xpos)
             << setposy(1)
             << settextcolor(console_text_colors::red)
             << ("Vendas")
             << settextcolor(console_text_colors::white)
             << endl;
        cout << setposx(Xpos) << "O";
        for (int i = 0; i < (biggestString[0] + biggestString[1] + biggestString[2] + 2); i++)
        {
            cout << "-";
        }
        cout << "O" << endl;
        for (int i = 0; i < *sizeVendas; i++)
        {
            cout << setposx(Xpos)
                 << "|"
                 << vendas[i][0]
                 << setposx(Xpos + biggestString[0] + 1)
                 << "|"
                 << selectSQL(vendas[i][1], 0, clientes, 1)
                 << setposx(Xpos + biggestString[0] + biggestString[1] + 2)
                 << "|"
                 << vendas[i][3]
                 << setposx(Xpos + biggestString[0] + biggestString[1] + biggestString[2] + 3)
                 << "|"
                 << endl;
        }
        cout << setposx(Xpos) << "O";
        for (int i = 0; i < (biggestString[0] + biggestString[1] + biggestString[2] + 2); i++)
        {
            cout << "-";
        }
        cout << "O" << endl;
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
    customCout(conout, "Insira o nome:");
    nome = customCins(conout);
    customCout(conout, "Insira o numero de telefone:");
    telefone = customCins(conout);
    customCout(conout, "Insira a morada:");
    morada = customCins(conout);
    clientes[*sizeClientes][0] = to_string(checkHighestId(clientes, 0) + 1);
    clientes[*sizeClientes][1] = nome;
    clientes[*sizeClientes][2] = telefone;
    clientes[*sizeClientes][3] = morada;
    (*sizeClientes)++;
    return stoi(clientes[(*sizeClientes) - 1][0]);
};

/* pagamento e finalizacao da transacao */
void pagamento(console_out *conout, string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    float precoAPagar = precoTotalCart(stock, sizeStock, cart, sizeCart);
    system("cls||clear");
    showCart(conout, stock, sizeStock, cart, sizeCart, false);
    cout << setposx(conout->getsize().X / 2 - 9 / 2)
         << setposy(1)
         << "PAGAMENTO";
    customCout(conout, "Insira o valor entregue");
    float valorEntregue = customCinf(conout);
    while (valorEntregue < (precoAPagar * 1.30 * 1.23))
    {
        customCout(conout, "Valor baixo, insira o valor entregue");
        valorEntregue = customCinf(conout);
    }
    int idCliente = -1;
    bool jaECliente;
    bool querSerCliente;
    string resposta;
    do
    {
        customCout(conout, "Ja e cliente? (S/N)");
        resposta = customCins(conout);
    } while (resposta != "s" && resposta != "S" && resposta != "n" && resposta != "N");
    jaECliente = (resposta == "s" || resposta == "S") ? true : false;
    if (jaECliente)
    {
        showClientes(conout, clientes, sizeClientes, false);
        customCout(conout, "Insira o numero de cliente");
        idCliente = customCini(conout);
    }
    else
    {
        string resposta;
        do
        {
            customCout(conout, "Quer ser cliente? (S/N)");
            resposta = customCins(conout);
        } while (resposta != "s" && resposta != "S" && resposta != "n" && resposta != "N");
        querSerCliente = (resposta == "s" || resposta == "S") ? true : false;
        if (querSerCliente)
        {
            clienteNovo(conout, clientes, sizeClientes);
        }
    }
    string idFatura = to_string(checkHighestId(vendas, 0) + 1);
    vendas[*sizeVendas][0] = idFatura;
    vendas[*sizeVendas][1] = to_string(idCliente);
    vendas[*sizeVendas][2] = setPrecision2(valorEntregue);
    vendas[*sizeVendas][3] = "01/01/2022";
    (*sizeVendas)++;
    for (int i = 0; i < *sizeCart; i++)
    {
        compras[*sizeCompras][0] = idFatura;
        compras[*sizeCompras][1] = cart[i][0];
        compras[*sizeCompras][2] = cart[i][1];
        (*sizeCompras)++;
        int lineInStock = checkLineOf(stock, sizeStock, 0, cart[i][0]);
        stock[lineInStock][2] = to_string(stoi(stock[lineInStock][2]) - stoi(cart[i][1]));
        cleanLine(cart, i, 2);
    }
    *sizeCart = 0;
};

/* imprime o talao da transacao escolhida em idFatura*/
void imprimirTalao(console_out *conout, string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart, int idFatura)
{
    system("cls||clear");
    string **tempTable = new string *[100];
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
                item = selectSQL(tempTable[i][0], 0, stock, 1);
                break;
            case 2: // preco
                item = setPrecision2(stof(selectSQL(tempTable[i][0], 0, stock, 3)) * 1.30 * 1.23 * stoi(tempTable[i][1]));
                break;
            }
            if (item.length() > biggestString[j])
            {
                biggestString[j] = item.length();
            }
        }
    }
    string baseText[] = {"FRUIT INC"};
    string nomeCliente = selectSQL(selectSQL(to_string(idFatura), 0, vendas, 1), 0, clientes, 1);
    string data = selectSQL(to_string(idFatura), 0, vendas, 3);
    string total = setPrecision2(precoTotalCart(stock, sizeStock, tempTable, &sizeTempTable) * 1.30 * 1.23);
    string entregue = setPrecision2(stof(selectSQL(to_string(idFatura), 0, vendas, 2)));
    string troco = setPrecision2(stof(entregue) - stof(total));
    int Xpos = conout->getsize().X / 2 - (biggestString[0] + biggestString[1] + biggestString[2] + 3) / 2;
    // top
    int width = biggestString[0] + biggestString[1] + biggestString[2] + 5;
    cout << setposy(3)
         << setposx(Xpos)
         << whiteBG(conout, width)
         << endl;

    cout << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width / 2 - baseText[0].length() / 2) << baseText[0] << endl
         << setposx(Xpos) << whiteBG(conout, width) << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width / 2 - nomeCliente.length() / 2 - (nomeCliente.length() % 2 ? 1 : 0)) << nomeCliente << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + width / 2 - data.length() / 2) << data << endl
         << setposx(Xpos) << whiteBG(conout, width) << endl;

    // body
    for (int i = 0; i < sizeTempTable; i++)
    {
        cout << setposx(Xpos)
             << whiteBG(conout, width)
             << setposx(Xpos + 1)
             << tempTable[i][1]
             << setposx(Xpos + biggestString[0] + 2)
             << " "
             << selectSQL(tempTable[i][0], 0, stock, 1)
             << setposx(Xpos + biggestString[0] + biggestString[1] + 3)
             << " "
             << setPrecision2(stof(selectSQL(tempTable[i][0], 0, stock, 3)) * 1.30 * 1.23)
             << endl;
    }

    // tail
    cout << setposx(Xpos) << whiteBG(conout, width) << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + biggestString[0] + biggestString[1] + biggestString[2] - 2 - total.length()) << "Total " << total << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + biggestString[0] + biggestString[1] + biggestString[2] - 5 - entregue.length()) << "Entregue " << entregue << endl
         << setposx(Xpos) << whiteBG(conout, width) << setposx(Xpos + biggestString[0] + biggestString[1] + biggestString[2] - 2 - troco.length()) << "Troco " << troco << endl
         << setposx(Xpos) << whiteBG(conout, width);
    cout << setbgcolor(console_bg_colors::black) << settextcolor(console_text_colors::white) << endl;
    cin.ignore();
    cin.ignore();
};

// ! Submenus

// ! Efectuar venda

/* Selecionar produto
submenu V*/
void selecionarProduto(console_out *conout, string **stock, int *sizeStock, string **cart, int *sizeCart)
{
    system("cls||clear");
    cout << setposx(conout->getsize().X / 2 - 18 / 2)
         << setposy(1)
         << "SELECIONAR PRODUTO";
    showStock(conout, stock, sizeStock, cart, true);
    showCart(conout, stock, sizeStock, cart, sizeCart, false);
    int id, quantidade, quantStock;
    customCout(conout, "O que vais querer comprar? (id)");
    id = customCini(conout);
    string inCart = selectSQL(to_string(id), 0, cart, 1);
    quantStock = stoi(selectSQL(to_string(id), 0, stock, 2)) - stoi((inCart == "") ? "0" : inCart);
    do
    {
        customCout(conout, "quanto?");
        quantidade = customCini(conout);
    } while (quantStock < quantidade);
    customCout(conout, "");
    if (inCart == "")
    {
        cart[*sizeCart][0] = to_string(id);
        cart[*sizeCart][1] = to_string(quantidade);
        (*sizeCart)++;
    }
    else
    {
        cart[checkLineOf(cart, sizeCart, 0, to_string(id))][1] = to_string(stoi(cart[checkLineOf(cart, sizeCart, 0, to_string(id))][1]) + quantidade);
    }
};

// TODO:
/* Checkout
add values from cart to respective tables and delete cart */
void checkout(console_out *conout, string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    float precoAPagar = precoTotalCart(stock, sizeStock, cart, sizeCart);
    string choice;
    do
    {
        system("cls||clear");
        showCart(conout, stock, sizeStock, cart, sizeCart, false);
        cout << setposx(conout->getsize().X / 2 - 8 / 2)
             << setposy(1)
             << "CHECKOUT";
        customCout(conout, "Confirmar que quer pagar (S/N)");
        choice = customCins(conout);
        customCout(conout, "");
    } while (choice != "s" && choice != "S" && choice != "n" && choice != "N");
    if (choice == "s" || choice == "S")
    {
        pagamento(conout, stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
        imprimirTalao(conout, stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart, checkHighestId(vendas, 0));
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
    customCout(conout, "Insira o nome do artigo: ");
    nome = customCins(conout);
    customCout(conout, "Preco base do artigo: ");
    preco_fabrica = customCinf(conout);
    stock[*sizeStock][0] = to_string(checkHighestId(stock, 0) + 1);
    stock[*sizeStock][1] = nome;
    stock[*sizeStock][2] = "0";
    stringstream ss;
    ss << fixed << setprecision(2) << preco_fabrica;
    stock[*sizeStock][3] = ss.str();
    (*sizeStock)++;
};

/* Adicionar stock a artigo existente */
void adicionarStock(console_out *conout, string **cart, string **stock, int *sizeStock)
{
    system("cls||clear");
    cout << setposx(conout->getsize().X / 2 - 15 / 2)
         << setposy(1)
         << "ADICIONAR STOCK";
    showStock(conout, stock, sizeStock, cart, true);
    int id, quantidade;
    do
    {
        customCout(conout, "Insira o id do artigo");
        id = customCini(conout);
    } while (checkLineOf(stock, sizeStock, 0, to_string(id)) == -1);
    do
    {
        customCout(conout, "Quanto vai adicionar?");
        quantidade = customCini(conout);
    } while (quantidade < 0);

    stock[checkLineOf(stock, sizeStock, 0, to_string(id))][2] = to_string(stoi(stock[checkLineOf(stock, sizeStock, 0, to_string(id))][2]) + quantidade);
};

/* Eliminar produto */
void eliminarProduto(console_out *conout, string **cart, string **stock, int *sizeStock)
{
    system("cls||clear");
    cout << setposx(conout->getsize().X / 2 - 16 / 2)
         << setposy(1)
         << "ELIMINAR PRODUTO";
    showStock(conout, stock, sizeStock, cart, true);
    int id;
    do
    {
        customCout(conout, "Insira o id do artigo");
        id = customCini(conout);
    } while (checkLineOf(stock, sizeStock, 0, to_string(id)) == -1);

    cleanLine(stock, checkLineOf(stock, sizeStock, 0, to_string(id)), 4);
    compactTable(stock, 4);
    (*sizeStock)--;
};

// ! Criação de relatorios

// TODO:
/* Relatorio de stock */

// TODO:
/* Relatorio de vendas por produto */

// TODO:
/* Relatorio total de vendas */

// ! Opçoes de cliente

/* Criar cliente */
void criarCliente(console_out *conout, string **clientes, int *sizeClientes)
{
    system("cls||clear");
    showClientes(conout, clientes, sizeClientes, false);

    string nome, telefone, morada;
    customCout(conout, "Insira o nome:");
    nome = customCins(conout);
    customCout(conout, "Insira o numero de telefone:");
    telefone = customCins(conout);
    customCout(conout, "Insira a morada:");
    morada = customCins(conout);
    clientes[*sizeClientes][0] = to_string(checkHighestId(clientes, 0) + 1);
    clientes[*sizeClientes][1] = nome;
    clientes[*sizeClientes][2] = telefone;
    clientes[*sizeClientes][3] = morada;
    (*sizeClientes)++;
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
    do
    {
        customCout(conout, "Insira o numero de cliente");
        id = customCini(conout);
    } while (checkLineOf(clientes, sizeClientes, 0, to_string(id)) == -1);

    cleanLine(clientes, checkLineOf(clientes, sizeClientes, 0, to_string(id)), 4);
    compactTable(clientes, 4);
    (*sizeClientes)--;
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
    do
    {
        customCout(conout, "Insira o numero de cliente");
        id = customCini(conout);
    } while (checkLineOf(clientes, sizeClientes, 0, to_string(id)) == -1);
    customCout(conout, "Insira o novo nome");
    clientes[checkLineOf(clientes, sizeClientes, 0, to_string(id))][1] = customCins(conout);
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
            showStock(conout, stock, sizeStock, cart, true);
            showCart(conout, stock, sizeStock, cart, sizeCart, false);
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
                checkout(conout, stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
            }
            break;
        case 3:
            /* Imprimir talao no ecra */
            if (*sizeVendas > 0)
            {
                system("cls||clear");
                showVendas(conout, vendas, sizeVendas, clientes, sizeClientes, false);
                int fatura;
                do
                {
                    customCout(conout, "Escolha fatura");
                    fatura = customCini(conout);
                } while (checkLineOf(vendas, sizeVendas, 0, to_string(fatura)) == -1);
                imprimirTalao(conout, stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart, checkHighestId(vendas, 0));
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
            showStock(conout, stock, sizeStock, cart, true);
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
            adicionarStock(conout, cart, stock, sizeStock);
            break;
        case 3:
            /* Eliminar produto */
            eliminarProduto(conout, cart, stock, sizeStock);
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
    string text[] = {"1 - Relatorio de stock", "2 - Relatorio de vendas por produto", "3 - Relatorio total de vendas", "0 - Voltar"};
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
            /* Relatorio de stock */

            break;
        case 2:
            /* Relatorio de vendas por produto */

            break;
        case 3:
            /* Relatorio total de vendas */

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
    string text[] = {"1 - Criar cliente", "2 - Eliminar cliente", "3 - Alterar nome", "0 - Voltar"};
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
            /* Eliminar cliente */
            eliminarCliente(conout, clientes, sizeClientes);
            break;
        case 3:
            /* Alterar nome */
            alterarNomeCliente(conout, clientes, sizeClientes);
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
    string text[5] = {"1 - Efectuar venda", "2 - Compra Stock", "3 - Criacao de relatorios", "4 - gestao de clientes", "0 - Sair"};
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
            repetition = false;
            break;
        }
    }
}

// ! Main

int main()
{
    setlocale(LC_ALL, "");
    // get handle to the console window
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    // retrieve screen buffer info
    CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
    GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);
    // current window size
    short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
    short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;
    // current screen buffer size
    short scrBufferWidth = scrBufferInfo.dwSize.X;
    short scrBufferHeight = scrBufferInfo.dwSize.Y;
    // to remove the scrollbar, make sure the window height matches the screen buffer height
    COORD newSize;
    newSize.X = scrBufferWidth;
    newSize.Y = winHeight;
    // set the new screen buffer dimensions
    int Status = SetConsoleScreenBufferSize(hOut, newSize);
    if (Status == 0)
    {
        cout << "SetConsoleScreenBufferSize() failed! Reason : " << GetLastError() << endl;
        exit(Status);
    }
    // print the current screen buffer dimensions
    GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);
    cout << "Screen Buffer Size : " << scrBufferInfo.dwSize.X << " x " << scrBufferInfo.dwSize.Y << endl;

    console_out_context ctxout;
    console_out conout(ctxout);
    conout.settitle("ATEC LOJA");
    int consoleXsize = conout.getsize().X;
    int consoleYsize = conout.getsize().Y;

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
    clientes[0][0] = "-1";
    clientes[0][1] = "Anonymous";
    clientes[0][2] = "NA";
    clientes[0][3] = "NA";
    sizeClientes++;
    defaultValues(stock, &sizeStock, clientes, &sizeClientes, vendas, &sizeVendas, compras, &sizeCompras, cart, &sizeCart);
    system("cls||clear");
    cout << setposx(conout.getsize().X / 2 - 10 / 2)
         << setposy(9)
         << "WELCOME TO"
         << endl
         << setposx(conout.getsize().X / 2 - 10 / 2)
         << "FRUIT INC."
         << endl
         << endl
         << setposx(conout.getsize().X / 2 - 12 / 2)
         << "press enter...";
    cin.ignore();

    displayMainMenu(&conout, stock, &sizeStock, clientes, &sizeClientes, vendas, &sizeVendas, compras, &sizeCompras, cart, &sizeCart);

    system("cls||clear");
    apple(&conout, conout.getsize().X / 2, 3);
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
         << setposx(conout.getsize().X / 2 - 12 / 2)
         << "press enter...";
    cin.ignore();
    cin.ignore();
    system("cls||clear");
    return 0;
}
