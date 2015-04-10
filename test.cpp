#include<iostream>
using namespace std;

class sudoku{
public:
    static const int size = 144;
    
    bool CheckMap( int map[] ){
        int check[12];
        bool result;
        for( int i=0 ; i<144 ; i+=12 ){//check row
            for( int j=0 ; j<12 ; j++ ){
                check[j] = map[i+j];
            }
				/*for( int i=0 ; i<12 ; i++ ){/////////////
					cout << check[i] << " ";////////////
				}cout << endl;*/////////////
            result = CheckUnity( check );
            if( result==false ){
                return false;
            }
        }
        for( int i=0 ; i<12 ; i++ ){//check column
            for( int j=0 ; j<12 ; j++ ){
                check[j] = map[i+12*j];
            }
				/*for( int i=0 ; i<12 ; i++ ){/////////////
	             cout << check[i] << " ";////////////
	         }cout << endl;*////////////
            result = CheckUnity( check );
            if( result==false ){
                return false;
            }
        }
        for( int i=0 ; i<16 ; i++ ){//check cell
            for( int j=0 ; j<9 ; j++ ){
                int locate = 36*(i/4) + 3*(i%4) + 12*(j/3) + (j%3);
                check[j] =  map[locate];
					 //////cout << check[j] << " ";/////////////
            }//////cout << endl;///////////////
            result = CheckCell( check );
            if( result==false ){
                return false;
            }
        }
        return true;
    }
    
    void GiveQuestion();
    
    /*void ReadIn(){
        for( int i = 0 ; i < 12 ; i++ ){
            for( int j = 0 ; j < 12 ; j++ ){
                cin >> sudoku[i];
            }
        }
    }*/
    
    void Solve();
    
private:
   //int map[size] = {};
   bool CheckUnity( int unit[] ){
       int amount[12] = {};//count unity numbers(set to 0)
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
   bool CheckCell( int cell[] ){
      int amount[9] = {};//count unity number (set to 0)
      int fuyee = 0;//number of -1
		for( int i=0 ; i<9 ; i++ ){
			if( cell[i]==-1 ){
				fuyee++;
			}
		}///////////cout << fuyee << endl;/////////
		if( fuyee==9 ){
			return true;
		}
		else{
			for( int i=0 ; i<9 ; i++ ){
      		amount[ cell[i]-1 ]++;
      	}
     		for( int i=0 ; i<9 ;i++ ){////cout << amount[i] << endl;///////
				if( amount[i]!=1 ){
   	  			return false;
     			}
     		}
		}
   	return true;
   }
};

////////////////////////////////////////////////////////////
int main(){
	sudoku ss;
   bool rr;
   int test1[144] = {4,2,6,8,7,3,9,5,1,-1,-1,-1,
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
	   int test2[144] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
			               -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
								-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
								-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
								-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
								-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
								-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
								-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
								-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
								-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
								-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
								-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
   rr = ss.CheckMap(test2);
   if( rr==false ){
   	cout << "False" << endl;
   }
   else
      cout << "True" << endl;
   for( int i=0 ; i<144 ; i++ ){
		cout << test2[i] << " ";
		if( ( (i+1)%12 )==0 ){
			cout << endl;
    	}
   }
   return 0;
}
