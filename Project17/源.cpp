#include <iostream>
#include <stack>
#include <vector>

using namespace std;
typedef enum { AVAILABLE, ROUTE, DEAD, WALL } Status;

typedef enum { UNKNOWN, EAST, SOUTH, WEST, NORTH, NO_WAY } ESWN;

inline ESWN nextESWN(ESWN eswn) { return ESWN(eswn + 1); };

struct Cell {
	int num;
	int x, y;
	bool isChecked;
	Status status;
	ESWN incoming, outgoing;
};

int main()
{
	int rows;
	int cols;
	cin >> rows >> cols;
	Cell** picture = new Cell* [rows];
	for (int i = 0; i < rows; i++)
	{
		picture[i] = new Cell [cols]();
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> picture[i][j].num;
			picture[i][j].isChecked = (picture[i][j].num == 0);
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{

		}
	}
}