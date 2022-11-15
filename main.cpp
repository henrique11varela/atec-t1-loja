#include <iostream>

using namespace std;

/*/////////////////////////////////////////////////////////////////////////////////ThinkingSpace

*/

////////////////////////////////////////////////////////////////////////////////////////Global Variables

// vec[item][atributo]
string **stock;    // STOCK 0-id 1-quantidade 2-nome 3-preço fabrica
string **clientes; // CLIENTE 0-id 1-nome 2-telefone 3-morada
string **vendas;   // VENDA 0-id_fatura 1-#id_cliente 3-quantidade 4-valor_entregue 5-data_(auto)
string **compras;  // COMPRAS 0-#id_fatura 1-#id_produto 2-quantidade
int sizeStock = 0;
int sizeClientes = 0;
int sizeVendas = 0;
int sizeCompras = 0;

////////////////////////////////////////////////////////////////////////////////////////Usefull

/* select 
string value, int index_value, & table, int index_return
returns the content of the table in index_return where index_value is value*/
string select(string value, int index_value, string **table, int index_return) {
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
string value, int index_value, & table1, int index_join1, int index_join2, & table2, int index_return
returns the content of the table2[index_return] where table1[index_value] == value and table1[index_join1] == table2[index_join2]*/
string joinSelect(string value, int index_value, string **table1, int index_join1, int index_join2, string **table2, int index_return) {
    for (int i = 0; i < 100; i++)
    {
        if (table1[i][index_value] == value)
        {
            for (int j = 0; j < 100; j++)
            {
                if (table1[i][index_join1] == table2[j][index_join2])
                {
                    return table2[j][index_return];
                }
            }
        }
    }
    return "";
};

/* joinSelectArray 
string value, int index_value, & table1, int index_join1, int index_join2, & table2, int index_return
returns the contents in an array of the table2[index_return] where table1[index_value] == value and table1[index_join1] == table2[index_join2]*/


/* check first empty line in table
& table
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
};

/* add value to table
string value, & table, int line, int column
returns true if successful, false if it failed*/
bool addValueToTable(string value, string **table, int Y, int X)
{
    if (table[Y][X] == "")
    {
        table[Y][X] == value;
        return true;
    }
    return false;
};

/* clean line from table 
string ** table, int Y
returns true if successful, false if it failed*/
bool cleanLine(string **table, int Y)
{
    if (table[Y][0] != "")
    {
        for (int i = 0; i < sizeof(table[Y])/sizeof(table[Y][0]); i++)
        {
            table[Y][i] == "";
        }
        return true;
    }
    return false;
};

/* remove empty line in table 
& table
returns true if successful, false if it failed*/
bool compactTable(string **table) {
    int line = 0;
    while (line < 100) {
        if(table[line][0] == "" && table[line + 1][0] == ""){
            return true;
        }
        else if (table[line][0] == "" && table[line + 1][0] != "") {
            for (int i = 0; i < sizeof(table[line])/sizeof(table[line][0]); i++)
            {
                table[line][i] = table[line + 1][i];
            }
            cleanLine(table, line);
        }
        line++;
    }
    
};

////////////////////////////////////////////////////////////////////////////////////////Efectuar venda

/* Selecionar produto */

/* Checkout */

/* Imprimir talao no ecra */


//////////////////////////////////////////////////////////////////////////////////////Comprar Stock

/* Criacao de artigo novo */

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


//////////////////////////////////////////////////////////////////////////////////////////Display

/* Display Menu 1 
returns false when exiting menu*/
bool displayMenu1()
{
    int choice;
    do
    {
        system("cls||clear");
        cout << "EFECTUAR VENDA" << endl
             << endl;
        cout << "1 - Selecionar produto" << endl;
        cout << "2 - Checkout" << endl;
        cout << "3 - Imprimir talao no ecra" << endl;
        cout << "0 - Voltar" << endl
             << endl;
        cout << ":";
        cin >> choice;
    } while (choice < 0 || choice > 3);
    switch (choice)
    {
    case 1:
        /* Selecionar produto */

        return true;
    case 2:
        /* Checkout */

        return true;
    case 3:
        /* Imprimir talao no ecra */

        return true;
    }
    return false;
}

/* Display Menu 2 
returns false when exiting menu*/
bool displayMenu2()
{
    int choice;
    do
    {
        system("cls||clear");
        cout << "COMPRAR STOCK" << endl
             << endl;
        cout << "1 - Criacao de artigo novo" << endl;
        cout << "2 - Adicionar stock a artigo existente" << endl;
        cout << "3 - Eliminar produto" << endl;
        cout << "0 - Voltar" << endl
             << endl;
        cout << ":";
        cin >> choice;
    } while (choice < 0 || choice > 3);
    switch (choice)
    {
    case 1:
        /* Criacao de artigo novo */

        return true;
    case 2:
        /* Adicionar stock a artigo existente */

        return true;
    case 3:
        /* Eliminar produto */

        return true;
    }
    return false;
}

/* Display Menu 3 
returns false when exiting menu*/
bool displayMenu3()
{
    int choice;
    do
    {
        system("cls||clear");
        cout << "CRIACAO DE RELATOROS" << endl
             << endl;
        cout << "1 - Relatorio de stock" << endl;
        cout << "2 - Relatorio de vendas por produto" << endl;
        cout << "3 - Relatorio total de vendas" << endl;
        cout << "0 - Voltar" << endl
             << endl;
        cout << ":";
        cin >> choice;
    } while (choice < 0 || choice > 3);
    switch (choice)
    {
    case 1:
        /* Relatorio de stock */

        return true;
    case 2:
        /* Relatorio de vendas por produto */

        return true;
    case 3:
        /* Relatorio total de vendas */

        return true;
    }
    return false;
}

/* Display Menu 4 
returns false when exiting menu*/
bool displayMenu4()
{
    int choice;
    do
    {
        system("cls||clear");
        cout << "OPCOES DE CLIENTE" << endl
             << endl;
        cout << "1 - Criar cliente" << endl;
        cout << "2 - Eliminar cliente" << endl;
        cout << "3 - Alterar nome" << endl;
        cout << "0 - Voltar" << endl
             << endl;
        cout << ":";
        cin >> choice;
    } while (choice < 0 || choice > 3);
    switch (choice)
    {
    case 1:
        /* Criar cliente */

        return true;
    case 2:
        /* Eliminar cliente */

        return true;
    case 3:
        /* Alterar nome */

        return true;
    }
    return false;
}

/* Display Main Menu 
returns false when exiting menu*/
bool displayMainMenu()
{
    int choice;
    do
    {
        system("cls||clear");
        cout << "MAIN MENU" << endl
             << endl;
        cout << "1 - Efectuar venda" << endl;
        cout << "2 - Compra Stock" << endl;
        cout << "3 - Criacao de relatorios" << endl;
        cout << "4 - Manipulacao de clientes" << endl;
        cout << "0 - Sair" << endl
             << endl;
        cout << ":";
        cin >> choice;
    } while (choice < 0 || choice > 4);
    switch (choice)
    {
    case 1:
        /* Efectuar venda */
        while (displayMenu1())
        {
        };
        return true;
    case 2:
        /* Compra Stock */
        while (displayMenu2())
        {
        };
        return true;
    case 3:
        /* Criacao de relatorios */
        while (displayMenu3())
        {
        };
        return true;
    case 4:
        /* Manipulacao de clientes */
        while (displayMenu4())
        {
        };
        return true;
    }
    return false;
}

//////////////////////////////////////////////////////////////////////////////////////////Main
int main()
{
    stock = new string *[100];
    clientes = new string *[100];
    vendas = new string *[100];
    compras = new string *[100];
    for (int i = 0; i < 100; i++)
    {
        stock[i] = new string[4];
        clientes[i] = new string[4];
        vendas[i] = new string[4];
        compras[i] = new string[3];
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
    }

    while (displayMainMenu())
    {
    };
    system("cls||clear");
    return 0;
}
