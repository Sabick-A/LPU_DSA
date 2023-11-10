

#include <iostream>

using namespace std;


void hollow_rectangle(int n, int m)

{

int i, j;

for (i = 1; i <= n; i++)

{

for (j = 1; j <= m; j++)

{

if (i==1 || i==n || j==1 || j==m)

cout << "*";

else

cout << " ";

}

cout << endl;

}

}

int main()

{

int rows, columns;


cin >> rows;


cin >> columns;

cout << endl;

hollow_rectangle(rows, columns);

return 0;

}

