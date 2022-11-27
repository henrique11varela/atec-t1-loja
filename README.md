
# atec-t1-loja

Este projecto é um trabalho em C++ para a UFCD 0789 do Curso de *Técnico Especialista em Tecnologias e Programação de Sistemas de Informação* que estou a tirar na ATEC.

É um programa para ser utilizado numa loja para fazer a gestão de vendas, stock e clientes.

---

# Sobre o programa:

## Funções principais

dicionário  
`& - pointer para tabela`
`int - inteiro`
`string - texto`

### ImprovisedSQL
`string select(string A, int B, & C, int D);`  
>retorna o valor de C na posição D onde a posição B é igual a A.

`string joinSelect(string A, int B, & C, int D, int E, & F, int G);`  
>Junta as tabelas C e F onde C\[D] == F\[E] e retorna o valor de F\[G] onde C\[B] é A.

`string *joinSelectArray(string A, int B, & C, int D, int E, & F, int G);`
>Junta as tabelas C e F onde C\[D] == F\[E] e retorna todos os valores de F onde C\[B] é A.

### Base de dados em Matrizes

Dicionário  
`chave primaria`

#### Stock
| `0` | 1 | 2 | 3 |
| :- | :- | :- | :- |
| `id` |  nome | quantidade | preço de fabrica |

#### Clientes
| `0` | 1 | 2 | 3 |
| :- | :- | :- | :- |
| `id` |  nome | telefone | morada |

#### Vendas
| `0` | 1 | 2 | 3 |
| :- | :- | :- | :- |
| `id de fatura` | id cliente | valor entregue | data |

#### Compras
| `0` | `1` | 2 |
| :- | :- | :- |
| `id fatura` | `id produto` | quantidade |

#### Cart
| `0` | 1 |
| :- | :- |
| `id produto` | quantidade |



g++ main.cpp Source/*.cpp




Nome loja  
Data  
Cliente  
Quantidade produto preco (varias Xs)  
Total  
Entregue  
Troco  
Codigo de barras  