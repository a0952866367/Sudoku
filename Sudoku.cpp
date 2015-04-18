#include "Sudoku.h"
using namespace std;
		
		sdk::sdk(){
			for( int i=0 ; i<size ; i++){
				map[i] = 0;
				map1[i] = 0;
				map2[i] = 0;
			}
			start1 = 1;
			start2 = 1;
			step1 = 1;
			step2 = 1;
			for( int i=0 ; i<1000 ; i++ ){
				info1[i] = 0;
				info2[i] = 0;
			}
			last1 = 0;
			last2 = 0;
			answer = 0;
		}
		/*static const int sdk::size = 144;
		int sdk::map[size];
		int sdk::map1[size];
		int sdk::map2[size];
		int sdk::start1 = 1;
		int sdk::start2 = 1;
		int sdk::step1 = 1;
		int sdk::step2 = 1;
		int sdk::info1[size*2];
		int sdk::info2[size*2];
		int sdk::last1 = 0;
		int sdk::last2 = 0;
		int sdk::answer = 0;
		*/
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
			for( int i=0 ; i<144 ; i++ ){
				cin >> map[i];
			}
			for( int i=0 ; i<144 ; i++ ){
				map1[i] = map[i];
				map2[i] = map[i];
			}
		/*	for(int i=0 ; i<144 ; i++){/////DDDDDDDDDDDDDDDDDDDDDDDD//////////////////
				cout << map1[i] << " " ;
				if( (i+1)%12==0 ) cout << endl;
			}
			for(int i=0 ; i<144 ; i++){/////DDDDDDDDDDDDDDDDDDDDDDDD///////////////////
				cout << map2[i] << " " ;
				if( (i+1)%12==0 ) cout << endl;
			}  
		*/
		}

		void sdk::Solve(){
			do{
				/*cout << "map1:" << endl;///////DDDDDDDDDDDDDDDDDDDDDDDD///////////////////
				for(int i=0 ; i<144 ; i++){/////DDDDDDDDDDDDDDDDDDDDDDDD///////////////////
					cout << map2[i] << " " ;
					if( (i+1)%12==0 ) cout << endl;
				}*/
				int firstZero1 = getFirstZero( map1 );
				/*cout << "map1:" << endl;///////DDDDDDDDDDDDDDDDDDDDDDDD///////////////////
				for(int i=0 ; i<144 ; i++){/////DDDDDDDDDDDDDDDDDDDDDDDD///////////////////
					cout << map1[i] << " " ;
					if( (i+1)%12==0 ) cout << endl;
				}
				cout << "firstZero1:" << firstZero1 <<endl;/////////DDDDDDDDDDDDDDDDDDDDDDDDD///////////
				*/
				if( firstZero1==-1 ){
					do{
						int firstZero2 = getFirstZero( map2 );
					/*	cout << "map2:" << endl;///////DDDDDDDDDDDDDDDDDDDDDDDD///////////////////
						for(int i=0 ; i<144 ; i++){/////DDDDDDDDDDDDDDDDDDDDDDDD///////////////////
							cout << map2[i] << " " ;
							if( (i+1)%12==0 ) cout << endl;
						}
						cout << "firstZero2:" << firstZero2 << endl;////////////DDDDDDDDDDDDDDDDDDDD///////////////
					*/	
						if( firstZero2==-1 ){
							for( int i=0 ; i<144 ; i++ ){
								if( map1[i]!=map2[i] ){
									answer = 2;
									break;
								}
							}
							answer = 3;
						}
						else{
							setElementdw( firstZero2 );
						}
					}while( (answer!=1)&&(answer!=2)&&(answer!=3) );
				}
				else{
					setElementup( firstZero1 );
				}
			}while( (answer!=1)&&(answer!=2)&&(answer!=3) );
			if( answer==1 ){//no solution
				cout << "0" <<endl;
			}
			if( answer==2 ){//infinite solution
				cout << "2" << endl;
			}
			if( answer==3 ){
				cout << "1" << endl;
				for( int i=0 ; i<144 ; i++ ){
					cout << map2[i] << " ";
					if( ( (i+1)%12 )==0 ){
						cout << endl;
					}
				}
			}
		}//Solve End

	   int sdk::getFirstZero( int map[] ){
			for( int i=0 ; i<144 ; i++ ){
				if( map[i]==0 ){
					return i;
				}
			}
			return -1;
		}
		
		void sdk::setElementup( int z ){
			int x = z%12;
			int xx = x/3;
			int y = z/12;
			int yy = y/3;
			int row[12];
			int column[12];
			int cell[9];
			for( int i=0 ; i<12 ; i++ ){//get row
				row[i] = map1[y*12+i];
			}
			for( int i=0 ; i<12 ; i++ ){//get column
				column[i] = map1[x+i*12];
			}
			for( int i=0 ; i<9 ; i++ ){//get cell
				cell[i] = map1[36*(yy%4)+3*(xx%4)+12*(i/3)+(i%3)];
			}
			start1 = 1;
			if( last1==1 ){
				start1 = map1[step1*2];
			}
			for( int set=start1 ; set<=9 ; set++ ){
				int s = 1;//decide whether the number is right or not
				for( int i=0 ; i<12 ; i++ ){//check row
					if( row[i]==set ){
						s = 0;
						break;
					}
				}
				for( int i=0 ; i<12 ; i++ ){//check column
					if( s==0 ){
						break;
					}
					else if( column[i]==set ){
						s = 0;
						break;
					}
				}
				for( int i=0 ; i<9 ; i++ ){//check cell
					if( s==0 ){
						break;
					}
					else if( cell[i]==set ){
						break;
					}
				}
				if( s==1 ){
					map1[z] = set;
					info1[step1*2-1] = z;
					info1[step1*2] = set;
					step1++;
					last1 = 0;
				}
			}//for End
			step1--;
			if( step1==0 ){
				answer = 1;
			}
			map1[step1*2-1] = 0;
			last1 = 1;
		}//setElementup End

		void sdk::setElementdw( int z ){
			int x = z%12;
			int xx = x/3;
			int y = z/12;
			int yy = y/3;
			int row[12];
			int column[12];
			int cell[9];
			for( int i=0 ; i<12 ; i++ ){//get row
				row[i] = map2[y*12+i];
			}
			for( int i=0 ; i<12 ; i++ ){//get column
				column[i] = map2[x+i*12];
			}
			for( int i=0 ; i<9 ; i++ ){//get cell
				cell[i] = map2[36*(yy%4)+3*(xx%4)+12*(i/3)+(i%3)];
			}
			start2 = 9;
			if( last2==1 ){
				start2 = map2[step2*2];
			}
			for( int set=start2 ; set>=0 ; set-- ){
				int s = 1;//decide whether the number is right or not
				for( int i=0 ; i<12 ; i++ ){//check row
					if( row[i]==set ){
						s = 0;
						break;
					}
				}
				for( int i=0 ; i<12 ; i++ ){//check column
					if( s==0 ){
						break;
					}
					else if( column[i]==set ){
						s = 0;
						break;
					}
				}
				for( int i=0 ; i<9 ; i++ ){//check cell
					if( s==0 ){
						break;
					}
					else if( cell[i]==set ){
						break;
					}
				}
				if( s==1 ){
					map2[z] = set;   cout << "map2[z]:" << map2[z] <<endl;///////////////DDDDDDDDDDDDD
					info2[step2*2-1] = z;
					info1[step2*2] = set;
					step2++;
					last2 = 0;
				}
			}//for End
			step2--;
			if( step2==0 ){
				answer = 1;
			}
			map2[step2*2-1] = 0;
			last2 = 1;
		}//setElementdw End

			/*bool sdk::CheckLine( int line[] ){
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
			}//CheckCell end;*/
