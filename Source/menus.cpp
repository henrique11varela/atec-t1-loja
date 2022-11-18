#include "../Headerfiles/menus.h"
#include "../Headerfiles/improvSQL.h"
#include "../Headerfiles/other.h"


void debugTabelas(string **tabela, int *L, int C)
{
    for (int i = 0; i < *L; i++)
    {
        cout << endl
             << "| ";
        for (int j = 0; j < C; j++)
        {
            cout << tabela[i][j] << " | ";
        }
    }
    cout << endl
         << endl;
};

void displayMenu1(string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{

    bool repetition = true;
    while (repetition)
    {
        int choice;
        do
        {
            system("cls||clear");
            cout << *sizeCart << endl;
            debugTabelas(cart, sizeCart, 2);

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
            selecionarProduto(cart, sizeCart);
            break;
        case 2:
            /* Checkout */
            checkout(stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
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

void displayMenu2(string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    bool repetition = true;
    while (repetition)
    {
        int choice;
        do
        {
            system("cls||clear");

            cout << *sizeStock << endl;
            debugTabelas(stock, sizeStock, 4);

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
            criacaoArtigo(stock, sizeStock);
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

void displayMenu3(string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    bool repetition = true;
    while (repetition)
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

void displayMenu4(string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    bool repetition = true;
    while (repetition)
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

void displayMainMenu(string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    bool repetition = true;
    while (repetition)
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
            displayMenu1(stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
            break;
        case 2:
            /* Compra Stock */
            displayMenu2(stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
            break;
        case 3:
            /* Criacao de relatorios */
            displayMenu3(stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
            break;
        case 4:
            /* Manipulacao de clientes */
            displayMenu4(stock, sizeStock, clientes, sizeClientes, vendas, sizeVendas, compras, sizeCompras, cart, sizeCart);
            break;
        default:
            repetition = false;
            break;
        }
    }
}