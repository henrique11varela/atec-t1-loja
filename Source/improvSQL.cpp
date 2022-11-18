#include "../Headerfiles/improvSQL.h"


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

string joinSelect(string value, int index_value, string **table1, int index_join1, int index_join2, string **table2, int index_return)
{
    return select(select(value, index_value, table1, index_join1), index_join2, table2, index_return);
};

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