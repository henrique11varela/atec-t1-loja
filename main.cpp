#include "Headerfiles/improvSQL.h"
#include "Headerfiles/menus.h"

using namespace std;

/*/////////////////////////////////////////////////////////////////////////////////TO DO
    IN THE END:
        clean unused parameters in display funcs

    NOW:
        cart not working, not clearing

*/

//////////////////////////////////////////////////////////////////////////////////////////Main
int main()
{
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

    displayMainMenu(stock, &sizeStock, clientes, &sizeClientes, vendas, &sizeVendas, compras, &sizeCompras, cart, &sizeCart);
    system("cls||clear");
    return 0;
}
