#include <string>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////Efectuar venda

/* Selecionar produto */
void selecionarProduto(string **cart, int *sizeCart);

float precoTotalCart(string **stock, int *sizeStock, string **cart, int *sizeCart);

float pagar(string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart, float valor_pagar);

/* Checkout
add values from cart to respective tables and delete cart
*/
void checkout(string **stock, int *sizeStock, string **clientes, int *sizeClientes, string **vendas, int *sizeVendas, string **compras, int *sizeCompras, string **cart, int *sizeCart);

/* Imprimir talao no ecra */

//////////////////////////////////////////////////////////////////////////////////////Comprar Stock

/* Criacao de artigo novo */
void criacaoArtigo(string **stock, int *sizeStock);

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

