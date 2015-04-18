#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Sudoku{
	public:
		Sudoku();
		static const int size = 144;
		int map[144];
		int map1[144];
		int map2[144];
		int step1;
		int step2;
		int info1[1000];//maximum step:972
		int info2[1000];//maximum step:972
		int last1;
		int last2;
		int answer;
		void GiveQuestion();
		void ReadIn();
		void Solve();
		int getFirstZero( int map[] );
		void setElementup( int z );
		void setElementdw( int z );
	private:
		bool CheckMap( int map[] );
		bool CheckLine( int line[] );
		bool CheckCell( int cell[] );
};
