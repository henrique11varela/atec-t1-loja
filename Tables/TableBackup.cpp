#include <fstream>

using namespace std;

/* fills tables with default and example values ACLEAN*/
void defaultValues(string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras)
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
    clientes[0][0] = "-1";
    clientes[0][1] = "Anonymous";
    clientes[0][2] = "NA";
    clientes[0][3] = "NA";
    (*sizeClientes)++;
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

int main()
{
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
    defaultValues(stock, &sizeStock, clientes, &sizeClientes, vendas, &sizeVendas, compras, &sizeCompras);
    txtSet("stock.txt", stock, sizeStock, 4);
    txtSet("clientes.txt", clientes, sizeClientes, 4);
    txtSet("vendas.txt", vendas, sizeVendas, 4);
    txtSet("compras.txt", compras, sizeCompras, 3);
    return 0;
}