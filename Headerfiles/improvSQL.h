#include <string>

using namespace std;

/* select
string value, int index_value, **table, int index_return
returns the content of the table in index_return where index_value is value*/
string select(string value, int index_value, string **table, int index_return);

/* joinSelect
string value, int index_value, ** table1, int index_join1, int index_join2, **table2, int index_return
returns the content of the table2[index_return] where table1[index_value] == value and table1[index_join1] == table2[index_join2]*/
string joinSelect(string value, int index_value, string **table1, int index_join1, int index_join2, string **table2, int index_return);

/* joinSelectArray
string value, int index_value, **table1, int index_join1, int index_join2, **table2, int index_return, **table_return
changes the contents in a temporary array table_return created before with the contents of a column of the table2[index_return] where table1[index_value] == value and table1[index_join1] == table2[index_join2]
returns the size of the useful part of the array*/
int joinSelectArray(string value, int index_value, string **table1, int index_join1, int index_join2, string **table2, int index_return, string *array_return);

/* check first empty line in table
**table
returns the index of the first empty line */
int checkFirstEmptyLine(string **table);


/* clean line from table
string ** table, int Y
returns true if successful, false if it failed*/
bool cleanLine(string **table, int Y);

/* remove empty line in table
**table
returns true if successful, false if it failed*/
bool compactTable(string **table);

/* checks the highest value in a column from a table
**table, int column
returns the highest id from the table */
int checkHighestId(string **table, int X);
