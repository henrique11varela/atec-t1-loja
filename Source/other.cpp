#include "../Headerfiles/improvSQL.h"
#include "../Headerfiles/menus.h"




////////////////////////////////////////////////////////////////////////////////////////Efectuar venda

void selecionarProduto(string **cart, int *sizeCart)
{
    cout << "tabela do stock" << endl
         << endl;
    int id, quantidade;
    cout << "O que vais querer comprar? (id): ";
    cin >> id;
    cout << "quanto? ";
    cin >> quantidade;
    cart[*sizeCart][0] = to_string(id);
    cart[*sizeCart][1] = to_string(quantidade);
    (*sizeCart)++;
};

float precoTotalCart(string **stock, int *sizeStock, string **cart, int *sizeCart)
{
    float total = 0;
    for (int i = 0; i < *sizeCart; i++)
    {
        total += stoi(cart[i][1]) * stof(select(cart[i][0], 0, stock, 3));
    }
    return total;
};

float pagar(string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart, float valor_pagar)
{
    float money;
    int numCliente;
    do
    {
        system("cls||clear");
        cout << "Insira o dinheiro: ";
        cin >> money;
    } while (money < valor_pagar);

    cout << "Insira numero de cliente: ";
    cin >> numCliente;
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

void checkout(string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart)
{
    float precoAPagar = precoTotalCart(stock, sizeStock, cart, sizeCart) ;
    int choice;
    do
    {
        system("cls||clear");
        cout << "CHECKOUT" << endl
             << endl;
        cout << "Valor sem lucro e sem IVA: " << precoAPagar << endl;
        cout << "Valor a pagar: " << precoAPagar  * 1.30 * 1.23 << endl
             << endl;

        cout << "1 - Pagar" << endl;
        cout << "0 - Voltar" << endl
             << endl;
        cout << ":";
        cin >> choice;
    } while (choice < 0 || choice > 1);
    switch (choice)
    {
    case 1:
        /* Selecionar produto */
        pagar(vendas, sizeVendas, cart, sizeCart, compras, sizeCompras, precoAPagar);
        break;
    default:

        break;
    }
};

//////////////////////////////////////////////////////////////////////////////////////Comprar Stock

void criacaoArtigo(string **stock, int *sizeStock)
{
    cout << "CRIACAO DE ARTIGO NOVO" << endl
         << endl;
    float preco_fabrica;
    string nome;
    cout << "Insira o nome do artigo: ";
    cin >> nome;
    cout << "Preco base do artigo: ";
    cin >> preco_fabrica;
    stock[*sizeStock][0] = to_string(checkHighestId(stock, 0) + 1);
    stock[*sizeStock][1] = "0";
    stock[*sizeStock][2] = nome;
    stock[*sizeStock][3] = to_string(preco_fabrica);
    (*sizeStock)++;
};

///////////////////////////////////////////////////////////////////////////////////////Criação de relatorios


////////////////////////////////////////////////////////////////////////////////////////Opçoes de cliente

