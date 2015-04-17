#include<iostream>
#include<cstdlib>
#include<ctime>

class sdk{
	public:
		static const int size = 144;
		int map[size];
		int map1[size];
		int map2[size];
		int start1;
		int start2;
		int step1;
		int step2;
		int info1[size*2];
		int info2[size*2];
		int last1;
		int last2;
		int answer;
		void GiveQuestion();
		void ReadIn();
		void Solve();
		int getFirstZero();
		void setElementup( int z );
		void setElementdw( int z );
};
