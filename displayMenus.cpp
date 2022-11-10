#include "headerFiles/displayMenus.h"

//Display Menu 1
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
//Display Menu 2
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
//Display Menu 3
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

//Display Menu 4
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

//Display Main Menu
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
        while (displayMenu1()){};
        return true;
    case 2:
        /* Compra Stock */
        while (displayMenu2()){};
        return true;
    case 3:
        /* Criacao de relatorios */
        while (displayMenu3()){};
        return true;
    case 4:
        /* Manipulacao de clientes */
        while (displayMenu4()){};
        return true;
    }  
    return false;
}