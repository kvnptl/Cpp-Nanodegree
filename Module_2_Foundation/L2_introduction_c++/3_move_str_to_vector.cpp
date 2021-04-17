#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

// TODO: Add the ParseLine function here.
vector<int> ParseLine(string st)
{
    vector<int> vec;
    istringstream line1(st);
    int n;
    char c;
    while (line1 >> n >> c && c == ',')
    {
        //   	line1 >> n;
        //   	if (line1){
        vec.push_back(n);
        //     	cout << n;
        //   	}
    }
    return vec;
}

void ReadBoardFile(string path)
{
    ifstream myfile(path);
    if (myfile)
    {
        string line;
        while (getline(myfile, line))
        {
            cout << line << "\n";
        }
    }
}

void PrintBoard(const vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

// #include "test.cpp" // For testing.

int main()
{
    //ReadBoardFile("1.board");
    //TestParseLine(); // For testing.
    vector<int> v1;
    v1 = ParseLine("0,1,0,0,0,0,");
    cout << v1.size() << "\n";
    // Leave commented out.
    // PrintBoard(board);
}
