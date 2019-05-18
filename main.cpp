#include <iostream>
#include <Windows.h>

#define SIZE 7

using namespace std;

int chess[SIZE][SIZE];

int move_col[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int move_row[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int numbb = 0;
void printChess(){
    system("cls");
    for(int i=0 ; i<SIZE ; i++){
        for(int j=0 ; j<SIZE ; j++){
            switch(chess[i][j]){
            case 0:
                cout<<" 0 ";
                break;
            case 1:
                cout<<" 1 ";
                break;
            case 2:
                cout<<" 2 ";
                break;
            case 3:
                cout<<" 3 ";
                break;
            case 4:
                cout<<" 4 ";
                break;
            case 5:
                cout<<" 5 ";
                break;
            case 6:
                cout<<" 6 ";
                break;
            case 7:
                cout<<" 7 ";
                break;
            case 8:
                cout<<" 8 ";
                break;
            case 9:
                cout<<" 9 ";
                break;
            default:
                cout<<chess[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}


bool solve(int move_number, int current_col, int current_row)
{
    if(move_number == (SIZE*SIZE))
        return true;

        chess[current_row][current_col] = move_number++;

        for(int i=0 ; i<8 ; i++)
        {

            int new_col = (current_col + move_col[i]);
            int new_row = (current_row + move_row[i]);

            if(new_row < 0 || new_row >= SIZE || new_col < 0 || new_col >= SIZE)
                continue;

            if(chess[new_row][new_col] != 0)
                continue;


//            printChess();
//            cin.get();

			numbb++;
			
            if(solve(move_number, new_col, new_row))
                return true;
        }
        chess[current_row][current_col] = 0;

        return false;
}

void start(int col, int row){

    if(solve(1, col, row)){
    	printChess();
        cout<<numbb;
	}
        
    else
        cout<<"There Is No Soloution :/"<<endl;
}

int main(){
    start(0, 0);
	cin.get();
    return 0;
}
