#include "Sudoku.h"

class sdk{
	public:
		static const int sdk::size = 144;
		int sdk::map[size];
		void sdk::GiveQuestion(){
			int origin1[144]={4,2,6,8,7,3,9,5,1,-1,-1,-1,
									8,7,3,9,5,1,6,2,4,-1,-1,-1,
									9,5,1,6,2,4,8,7,3,-1,-1,-1,
									-1,-1,-1,1,3,2,4,8,7,9,5,6,
									-1,-1,-1,7,8,5,1,9,6,4,2,3,
									-1,-1,-1,4,9,6,2,3,5,8,7,1,
									1,3,7,2,4,8,-1,-1,-1,6,9,5,
									2,8,4,5,6,9,-1,-1,-1,1,3,7,
									6,9,5,3,1,7,-1,-1,-1,2,8,4,
									3,1,2,-1,-1,-1,7,4,8,5,6,9,
									7,4,8,-1,-1,-1,5,6,9,3,1,2,
									5,6,9,-1,-1,-1,3,1,2,7,4,8};
			int origin2[144]={-1,-1,-1,6,3,1,5,7,4,9,2,8,
									-1,-1,-1,5,2,7,9,3,8,6,1,4,
									-1,-1,-1,9,4,8,6,1,2,5,3,7,
									1,4,3,7,6,5,-1,-1,-1,8,9,2,
									5,2,7,8,9,3,-1,-1,-1,4,6,1,
									9,6,8,4,1,2,-1,-1,-1,7,5,3,
									3,1,4,2,5,6,8,9,7,-1,-1,-1,
									7,5,2,3,8,9,4,6,1,-1,-1,-1,
									8,9,6,1,7,4,2,5,3,-1,-1,-1,
									6,3,1,-1,-1,-1,7,4,5,2,8,9,
									2,7,5,-1,-1,-1,3,8,9,1,4,6,
									4,8,9,-1,-1,-1,1,2,6,3,7,5};
			int origin3[144]={8,4,7,2,1,3,-1,-1,-1,9,6,5,
									2,1,3,9,6,5,-1,-1,-1,8,4,7,
									9,6,5,8,4,7,-1,-1,-1,2,1,3,
									4,8,2,-1,-1,-1,7,1,3,5,9,6,
									7,3,1,-1,-1,-1,9,6,5,4,8,2,
									5,9,6,-1,-1,-1,8,4,2,7,3,1,
									1,7,8,5,3,2,6,9,4,-1,-1,-1,
									3,2,4,6,9,1,5,8,7,-1,-1,-1,
									6,5,9,7,8,4,2,3,1,-1,-1,-1,
									-1,-1,-1,3,7,8,4,2,6,1,5,9,
									-1,-1,-1,4,2,6,1,5,9,3,7,8,
									-1,-1,-1,1,5,9,3,7,8,6,2,4};
			int origin4[144]={5,7,3,6,2,1,-1,-1,-1,9,8,4,
									6,4,1,9,8,3,-1,-1,-1,5,7,2,
									9,8,2,5,4,7,-1,-1,-1,1,3,6,
									-1,-1,-1,3,5,2,4,7,1,6,9,8,
									-1,-1,-1,1,6,4,9,8,3,2,5,7,
									-1,-1,-1,7,9,8,6,5,2,4,1,3,
									3,5,7,-1,-1,-1,2,1,4,8,6,9,
									1,6,4,-1,-1,-1,3,9,8,7,2,5,
									2,9,8,-1,-1,-1,5,6,7,3,4,1,
									7,3,5,2,1,6,8,4,9,-1,-1,-1,
									4,1,6,8,3,9,7,2,5,-1,-1,-1,
									8,2,9,4,7,5,1,3,6,-1,-1,-1};
			srand( (unsigned)time(NULL) );
			int ori = rand()%3+1;//1~4
			int origin[144]={};
			if( ori==1 ){
				for( int i=0 ; i<144 ; i++ )
					origin[i] = origin1[i];
			}
			else if( ori==2 ){
				for( int i=0 ; i<144 ; i++ )
					origin[i] = origin2[i];
			}
			else if( ori==3 ){
				for( int i=0 ; i<144 ; i++ )
					origin[i] = origin3[i];
			}
			else
				for( int i=0 ; i<144 ; i++ )
					origin[i] = origin4[i];
			int add = rand()%8+1;//1~9
			int dark = rand()%11;//0~11
			for( int i=0 ; i<144 ; i++ ){
				if( origin[i]>0 ){
					origin[i] += add;
					if( origin[i]>9 ){
						origin[i] -= 9;
					}
				}
				for( int j=dark ; j<144 ; j+=11 ){
					if( origin[j]>0 ){
						origin[j] = 0;
					}
				}
				cout << origin[i] << " ";
				if( ( (i+1)%12 )==0 ){
					cout << endl;
				}
			}
		}//GiveQuestion End;

		void sdk::ReadIn(){
			for( int i = 0 ; i < 144 ; i++ ){
				cin >> map[i];
			}
		}

		void sdk::Solve(){
			int o = getFirstZero;
			int x = o%12;
			int y = o/12;
			int row[12],column[12],cell[9];
			for( int i=0 ; i<12 ; i++ )//check row
				row[i] = map[y*12+i];
			if( CheckLine(row)==false )
				return false;
			for( int i=0 ; i<size ; i+=12 )//check column
				column[i] = map[x+i];
			if( CheckLine(column)==false )
				return false;
			for( int i=0 ; ;  )//check cell
				cell[i] = map[];
			if( CheckCell(cell)==false )
				return false;
		}

private:
	      int sdk::getFirstZero(){
				for( int i=0 ; i<144 ; i++ ){
					if( sudokumap[i]==0 ){
						return i;
					}
					return -1;
				}
			}

			bool sdk::CheckLine( int line[] ){
				int amount[12] = {};//count unity numbers(set to 0)
					for( int i=0 ; i<12 ; i++ )
						amount[ line[i]+1 ]++;
					if( amount[0]!=3 )
						return false;
					for( int i=2 ; i<=10 ; i++ ){
						if( amount[i]!=1 ){
							return false;
						}
					}
					return true;
			}//CheckLine end;
			
			bool sdk::CheckCell( int cell[] ){
				int amount[9] = {};//count unity number (set to 0)
				int fuyee = 0;//number of -1
				for( int i=0 ; i<9 ; i++ ){
					if( cell[i]==-1 ){
						fuyee++;      
					}
				}
				if( fuyee==9 )
					return true;
				else{
					for( int i=0 ; i<9 ; i++ ){
						amount[ cell[i]-1 ]++;
					}
					for( int i=0 ; i<9 ;i++ ){
						if( amount[i]!=1 ){
							return false;
						}
					}
				}
				return true;
			}//CheckCell end;
};//class end
