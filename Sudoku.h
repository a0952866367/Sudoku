#include<iostream>
#include<cstdlib>
#include<ctime>

class sdk{
	public:
		static const int size = 144;
		int sudokumap[size];
		void GiveQuestion();
		void ReadIn();
		void Solve();
	private:
		int getFirstZero();
		bool CheckLine( int line[] );
		bool CheckCell( int cell[] );
};
