#include<iostream>
using namespace std;

class sudoku{
public:
	static const int size = 144;
	
	bool CheckMap(int all[]){
		int check[12];
		bool result;
		for( int i=0 ; i<144 ; i+=12 ){//check row
			for( int j=0 ; j<12 ;j++ ){
				check[j] = map[i+j];
			}
			result = CheckUnity( check[] );
			if( result==false ){
				return false;
			}
		}
		for( int i=0 ; i<12 ; i++ ){//check column
			for( int j=0 ; j<12 ; j++ ){
				check[j] = map[i+12*j];
			}
			result = CheckUnity( check[] );
			if( result==false ){
				return false;
			}
		}
		for( int i=0 ; i<12 ; i++ ){//check cell
			for( int j=0 ; j<12 ; j++ ){
				int cell = ;///////////////////
				check[j] = map[cell];
			}
			result = CheckUnity( check[] );
			if( result==false ){
				return false;
			}
		}
		return true;
	}
	void GiveQuestion();
	void ReadIn(){
		for( int i = 0 ; i < 12 ; i++ ){
            		for( int j = 0 ; j < 12 ; j++ ){
                		cin >> sudoku[i];
			}
		}
	}
	void Solve();
private:
	int map[size] = {};
	bool CheckUnity(int unit[]){
		int amount[12] = {};//count unity numbers(set to 0)
		for( int i=0 ; i<12 ; i++ ){
			unit[i] = all[i];
		}
		for( int i=0 ; i<12 ; i++ ){
			amount[ unit[i]+1 ]++;
		}
		if( amount[0]!=3 ){
			return false;
		}
		for( int i=2 ; i<=10 ; i++ ){
			if( amount[i]!=1 ){
				return false;
			}
		}
		return true;
	}
	
}
