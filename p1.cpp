#include<iostream>
using namespace std;

class sudoku{
public:
	static const int size = 12;
	int map[size][size] = {0};
	
	void GiveQuestion();
	void ReadIn(){
		for( int i = 0 ; i < 9 ; i++ ){
            		for( int j = 0 ; j < 9 ; j++ ){
                		cin >> sudoku[i][j];
			}
		}
	}
	void Solve();
	
	
	
}
