#include "Headerfiles/conmanip.h"

using namespace conmanip;
using namespace std;

/*/////////////////////////////////////////////////////////////////////////////////TO DO
    IN THE END:
        clean unused parameters in display funcs

    NOW:
        cart not working, not clearing
        redo checkout


    while(!(cin >> num)){
        cout << "nao e um numero! tente novamente";
        //limpa o erro, e o valor inserido
        cin.clear();
        //ignorar a mensagem de erro x vezes, neste caso 100, o que faz com que o user pode inserir ate 100 chars que nao vai dar erro
        cin.ignore(100, '\n');
    }

*/

//////////////////////////////////////////////////////////////////////////Custom display funcs

/* custom cin
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
    cin >> setposx(conout->getsize().X / 2 - 12) >> setposy(conout->getsize().Y - 3) >> choice;
    return choice;
};

/* custom cin
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

/* getBiggestStringSize
string *text, int size_of_array
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

/* custome COUT
console_out *conout, string text
outputs ontop of the input box */
void customCout(console_out *conout, string text)
{
    cout << setposx(0)
         << setposy(conout->getsize().Y - 6);
    for (int i = 0; i < conout->getsize().X; i++)
    {
        cout << " ";
    }
    cout << setposx(conout->getsize().X / 2 - text.length() / 2)
         << text;
};

//////////////////////////////////////////////////////////////////////////////////////////////# improvSQL

/* select
string value, int index_value, **table, int index_return
returns the content of the table in index_return where index_value is value*/
string select(string value, int index_value, string **table, int index_return)
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
string value, int index_value, ** table1, int index_join1, int index_join2, **table2, int index_return
returns the content of the table2[index_return] where table1[index_value] == value and table1[index_join1] == table2[index_join2]*/
string joinSelect(string value, int index_value, string **table1, int index_join1, int index_join2, string **table2, int index_return)
{
    return select(select(value, index_value, table1, index_join1), index_join2, table2, index_return);
};

/* joinSelectArray
string value, int index_value, **table1, int index_join1, int index_join2, **table2, int index_return, **table_return
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
**table
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

/* clean line from table
string ** table, int Y
returns true if successful, false if it failed*/
bool cleanLine(string **table, int Y)
{
    if (table[Y][0] != "")
    {
        for (int i = 0; i < sizeof(table[Y]) / sizeof(table[Y][0]); i++)
        {
            table[Y][i] == "";
        }
        return true;
    }
    return false;
};

/* remove empty line in table
**table
returns true if successful, false if it failed*/
bool compactTable(string **table)
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
            for (int i = 0; i < sizeof(table[line]) / sizeof(table[line][0]); i++)
            {
                table[line][i] = table[line + 1][i];
            }
            cleanLine(table, line);
        }
        line++;
    }
    return false;
};

/* checks the highest value in a column from a table
**table, int column
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

/////////////////////////////////////////////////////////////////////////////////////Table display

/* Displays Cart table
console_out conout | string **stock | string **cart | int *sizeCart | bool left
void*/
void showCart(console_out *conout, string **stock, string **cart, int *sizeCart, bool left)
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
                    item = select(cart[i][0], 0, stock, 2);
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
                 << select(cart[i][0], 0, stock, 2)
                 << setposx(Xpos + biggestString[0] + 1)
                 << "|"
                 << cart[i][1]
                 << "|"
                 << endl;
        }
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////# submenus
//## Efectuar venda

/* Selecionar produto 
console_out *conout, string **cart, int *sizeCart
submenu */
void selecionarProduto(console_out *conout, string **cart, int *sizeCart)
{
    int id, quantidade;
    customCout(conout, "O que vais querer comprar? (id)");
    id = customCini(conout);
    customCout(conout, "quanto?");
    quantidade = customCini(conout);
    customCout(conout, "");
    cart[*sizeCart][0] = to_string(id);
    cart[*sizeCart][1] = to_string(quantidade);
    (*sizeCart)++;
};


/* para refazer */
float precoTotalCart(string **stock, int *sizeStock, string **cart, int *sizeCart)
{
    float total = 0;
    for (int i = 0; i < *sizeCart; i++)
    {
        total += stoi(cart[i][1]) * stof(select(cart[i][0], 0, stock, 3));
    }
    return total;
};

float pagar(console_out *conout, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart, float valor_pagar)
{
    float money;
    int numCliente;
    do
    {
        system("cls||clear");
        cout << "Insira o dinheiro: ";
        money = customCinf(conout);
    } while (money < valor_pagar);

    cout << "Insira numero de cliente: ";
    numCliente = customCini(conout);
    int id_fatura = checkHighestId(vendas, 0) + 1;
    vendas[*sizeVendas][0] = to_string(id_fatura);
    vendas[*sizeVendas][1] = to_string(numCliente);
    vendas[*sizeVendas][2] = to_string(money);
    // vendas[*sizeVendas][2] = to_string(data);
    (*sizeVendas)++;
    for (int i = 0; i < *sizeCart; i++)
    {
        compras[*sizeCompras][0] = to_string(id_fatura);
        compras[*sizeCompras][1] = cart[i][0];
        compras[*sizeCompras][2] = cart[i][1];
        (*sizeCompras)++;
        cleanLine(cart, i);
    }
    *sizeCart = 0;
    return money - valor_pagar;
};

/* Checkout
add values from cart to respective tables and delete cart*/
void checkout(console_out *conout, string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    float precoAPagar = precoTotalCart(stock, sizeStock, cart, sizeCart);
    int choice;
    do
    {
        system("cls||clear");
        cout << "CHECKOUT"
             << endl
             << endl;
        cout << "Valor sem lucro e sem IVA: "
             << precoAPagar
             << endl;
        cout << "Valor a pagar: "
             << precoAPagar * 1.30 * 1.23
             << endl
             << endl;

        cout << "1 - Pagar"
             << endl;
        cout << "0 - Voltar"
             << endl
             << endl;
        cout << ":";
        choice = customCini(conout);
    } while (choice < 0 || choice > 1);
    switch (choice)
    {
    case 1:
        /* Selecionar produto */
        pagar(conout, vendas, sizeVendas, cart, sizeCart, compras, sizeCompras, precoAPagar);
        break;
    default:

        break;
    }
};

/* Imprimir talao no ecra */

//////////////////////////////////////////////////////////////////////////////////////Comprar Stock

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
    stock[*sizeStock][1] = "0";
    stock[*sizeStock][2] = nome;
    stock[*sizeStock][3] = to_string(preco_fabrica);
    (*sizeStock)++;
};

/* Adicionar stock a artigo existente */

/* Eliminar produto */

///////////////////////////////////////////////////////////////////////////////////////Criação de relatorios

/* Relatorio de stock */

/* Relatorio de vendas por produto */

/* Relatorio total de vendas */

////////////////////////////////////////////////////////////////////////////////////////Opçoes de cliente

/* Criar cliente */

/* Eliminar cliente */

/* Alterar nome */

/////////////////////////////////////////////////////////////////////////////////////////////////////Main Menus

/* Display Menu 1 EFECTUAR VENDA
returns false when exiting menu*/
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
            selecionarProduto(conout, cart, sizeCart);
            break;
        case 2:
            /* Checkout */
            checkout(conout, stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
            break;
        case 3:
            /* Imprimir talao no ecra */

            break;
        default:
            repetition = false;
            break;
        }
    }
}

/* Display Menu 2 COMPRAR STOCK
returns false when exiting menu*/
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

            break;
        case 3:
            /* Eliminar produto */

            break;
        default:
            repetition = false;
            break;
        }
    }
}

/* Display Menu 3 CRIACAO DE RELATOROS
returns false when exiting menu*/
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

/* Display Menu 4 OPCOES DE CLIENTE
returns false when exiting menu*/
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
            cout << setposx(conout->getsize().X / 2 - 17 / 2)
                 << setposy(1)
                 << "OPCOES DE CLIENTE"
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
            /* Criar cliente */

            break;
        case 2:
            /* Eliminar cliente */

            break;
        case 3:
            /* Alterar nome */

            break;
        default:
            repetition = false;
            break;
        }
    }
}

/* Display Main Menu
returns false when exiting menu*/
void displayMainMenu(console_out *conout, string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    string text[] = {"1 - Efectuar venda", "2 - Compra Stock", "3 - Criacao de relatorios", "4 - gestao de clientes", "0 - Sair"};
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

//////////////////////////////////////////////////////////////////////////////////////////Main
int main()
{
    console_out_context ctxout;
    console_out conout(ctxout);
    conout.settitle("ATEC LOJA");
    int consoleXsize = conout.getsize().X;
    int consoleYsize = conout.getsize().Y;

    // vec[item][atributo]
    string **stock = new string *[100];    // STOCK 0-id 1-quantidade 2-nome 3-preço_fabrica
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

    displayMainMenu(&conout, stock, &sizeStock, clientes, &sizeClientes, vendas, &sizeVendas, compras, &sizeCompras, cart, &sizeCart);
    system("cls||clear");
    return 0;
}
