#include <iostream>										//header file for input output operations
using namespace std;									//to avoid the usage of "std::" for every standard library function

class Game{												//creating an ABSTRACT  BASE class
	public:
		virtual void choose_level()=0;					//pure virtual function
		virtual void play_game()=0;						//pure virtual function
		virtual ~Game(){								//creating virtual base destructor
			cout<<"\nVirtual destructor called"<<endl;
		}
};

class tic_tac_toe : public Game{						//derived class for tic tac toe game
	private:
		int level;										//will store difficulty level
		int n;											//will store size of board: 3, 4 or 5
		char board[5][5];								//keeping board size as 5*5
	public:
		void choose_level() override{					//overrides the abstract function
			cout<<"Choose a level"<<endl;				//asks user for difficulty level
			cout<<"Level 1: 3*3 board"<<endl;
			cout<<"Level 2: 4*4 board"<<endl;
			cout<<"Level 3: 5*5 board"<<endl;
			cin>>level;									//takes input from the user
			if (level==1){
				n=3;									//will set 3*3 board if level=1
			}
			else if(level==2){
				n=4;									//will set 4*4 board if level=2
			}
			else{
				n=5;									//else will set 5*5 board
			}
			for (int i=0;i<n;i++){						//initializing the board
				for (int j=0;j<n;j++){
					board[i][j]=' ';
				}
			}
		}
		
		friend void board_check(tic_tac_toe &t);		//friend function which can access the private board
		
		void display_board(){							//function which will print the board
			for (int i=0;i<n;i++){						//for looping the rows
				cout<<"  ";
				for (int j=0;j<n;j++){
					cout<<"----";
				}
				cout<<"-\n";
				cout<<" | ";
				for (int j=0;j<n;j++){					//for looping the columns
					cout<<board[i][j]<<" | ";			//for printing the cell
				}
				cout<<"\n";
			}
			
			cout<<"  ";
			for(int j=0;j<n;j++){
				cout<<"----";
			}
			cout<<"-\n";
			
		}
		
		void play_game() override{						//overrides the abstract function in the base class
			board_check(*this);							//calls the friend function to play the game
		}
};

bool check_win(char board[5][5], int n, char sym) {		//function to check the winning condition
    for (int i = 0; i < n; i++) {						//check all the rows
        bool row_win = true;
        for (int j = 0; j < n; j++){
            if (board[i][j] != sym){
				row_win = false;						//returns false if any mismatch is found
			}
		}
        if (row_win){
			return true;								//returns true if the whole row matches
		}
    }
    for (int j = 0; j < n; j++) {						//checks all the columns
        bool col_win = true;
        for (int i = 0; i < n; i++){
            if (board[i][j] != sym){
				col_win = false;						//returns false if any mismatch is found
			}
    	}
        if (col_win){
			return true;								//returns true if the whole column matches
		}
    }
    
    bool diagonal_1 = true;								//checks main diagonal
    for (int i = 0; i < n; i++){
        if (board[i][i] != sym){
			diagonal_1 = false;							//returns false if mismatch found
		}
    }
    if (diagonal_1){
		return true;									//returns true if the whole diagonal matches
	}
	
    bool diagonal_2 = true;								//checks anti diagonal
    for (int i = 0; i < n; i++){
        if (board[i][n-i-1] != sym){
			diagonal_2 = false;							//returns false if mismatch found
		}
    }
    if (diagonal_2){
		return true;									//returns true if entire diagonal matches
	}

    return false;										//returns false if none of the above cases is accomplished
}

void board_check(tic_tac_toe &t) {						//main game loop
    for (int i = 0; i < t.n; i++) {						//initializing the board with a space in each cell
        for (int j = 0; j < t.n; j++) {
            t.board[i][j] = ' ';
        }
    }

    int total_moves = 0;								//to store the number of moves
    int max_moves = t.n * t.n;							//setting the condition for "DRAW" case
    char player = 'X';									//starting the game with player X

    while (total_moves < max_moves) {					//loop will continue till either "DRAW" or "WIN" case achieved
        cout << "\nCurrent Board:\n";
        t.display_board();								//shows the current board

        int r, c;										//will store the row and column input by the user
        cout << "Player " << player << "\nEnter row(0-based index): ";
        cin >> r;										//takes input from the user
		cout<<"Enter column (0-based index):";
		cin>>c;
        if (r < 0 || r >= t.n || c < 0 || c >= t.n || t.board[r][c] != ' ') {	//for handling invalid moves
            cout << "Invalid move! Try again.\n";
            continue;
        }

        t.board[r][c] = player;							//places the symbol on the board cell
        total_moves++;									//total move count increases by 1

        if (check_win(t.board, t.n, player)) {			//checks win condition
            cout << "\nPlayer " << player << " WINS!\n";
            t.display_board();
            return;										//closes the game if "WIN" achieved
        }
        if (player=='X'){								//changes the turn of the player
        	player='O';
		}
		else{
			player='X';
		}
    }
    cout << "\nIt's a DRAW!\n";							//if all moves reached ---> DRAW case achieved
    t.display_board();
}

void jug_pour(int jug1, int jug2, int target);
class water_jug : public Game{							//derived class: Water Jug game
	private:
		int level;										//will store difficulty of level
		int jug1,jug2, target;							//will store jug capacities and the target capacity 
		
	public:
		void choose_level() override{					//overrides the abstract function
			cout<<"Choose a level"<<endl;				//aska user for the diffuiculty level
			cout<<"Level 1: Make 2L from 4L and 3L  "<<endl;
			cout<<"Level 2: Make 4L from 3L and 5L "<<endl;
			cin>>level;									//takes input from the user
		}
		
		friend void jug_pour(int jug1, int jug2, int target);	//friend function for main gameplay
		
		void play_game() override{								//overrides the abstract function
			if (level==1){										//will set the following capacities if level=1
				cout<<"playing Water Jug Problem level 1"<<endl;
				jug1=4;
				jug2=3;
				target=2;
				jug_pour(4,3,2);								//calls main gameplay function
			}
			else if(level==2){									//will set the following jug capacities if level=2
				cout<<"playing Water Jug level 2"<<endl;
				jug1=3;
				jug2=5;
				target=4;
				jug_pour(3,5,4);								//calls main gameplay function
			}
			else{												//invalid level case
				cout<<"Invalid level"<<endl;
			}
		}
};

void jug_pour(int jug1, int jug2, int target){					//main gameplay function
	int temp1=0,temp2=0;										//will store the current capacities in jug1 and jug2
	while (temp1!=target && temp2!=target){						//loop will continue till jug1 or jug2 reaches the target capacity
		int act, pour_amt=0;									//will store the action number and amount to pour
		cout<<"Jug 1 max capacity: "<<jug1<<endl;				//display maxmimum capacity of jug1 and jug2
		cout<<"Jug 2 max capacity: "<<jug2<<endl;
		cout<<"\nJug 1 current capacity: "<<temp1<<endl;		//display current states of jug1 and jug2
		cout<<"Jug 2 current capacity: "<<temp2<<endl;
		
		cout<<"\n1. Fill Jug 1"<<endl;							//menu of actions to choose from						
		cout<<"2. Fill Jug 2"<<endl;
		cout<<"3. Empty Jug 1"<<endl;
		cout<<"4. Empty Jug 2"<<endl;
		cout<<"5. Pour water from Jug 1 to Jug 2"<<endl;
		cout<<"6. Pour water from Jug 2 to Jug 1"<<endl;
		cout<<"7. Give up"<<endl;
		cout<<"\nChoose your action: "<<endl;
		cin>>act;												//user selects the action
		
		switch(act){											//switch case for the action
			case 1:													
				temp1=jug1;										//fills jug1 fully
				break;
			case 2:
				temp2=jug2;										//fills jug2 fully
				break;
			case 3:
				temp1=0;										//empties jug1 fully
				break;
			case 4:
				temp2=0;										//empties jug2 fully
				break;
			case 5:												//pour from jug1 to jug2
				if (temp1<=jug2-temp2){							//checks if jug1 capacity is less or equal than remaining capacity of jug2
					pour_amt=temp1;								//whole jug1 capacity is poured if true
				}
				else{
					pour_amt=jug2-temp2;						//pour remaining capacity jug2 has left if false
				}
				temp1=temp1-pour_amt;							//reduce water capacity from jug1
				temp2=temp2+pour_amt;							//increase water capacity in jug2
				break;
			case 6:												//pour from jug2 to jug1
				if (temp2<=jug1-temp1){							//checks if jug2 capacity is less or equal than remaining capacity of jug1	
					pour_amt=temp2;								//whole capacity of jug2 is poured if true
				}
				else{
					pour_amt=jug1-temp1;						//pour remaining capacity jug1 has left if false
				}
				temp2=temp2-pour_amt;							//reduce capacity in jug2
				temp1=temp1+pour_amt;							//increase capacity in jug1
				break;
			case 7:
				cout<<"YOU LOST THE GAME!"<<endl;				//user quits the game
				return;
			default:
				cout<<"Invalid action! try again!"<<endl;		//invalid action from the user
				continue;
		}
	}
	cout<<"Congratulations! YOU WON THE GAME!"<<endl;			//target capacity achieved
}


class missionary_cannibal : public Game{   //derived class: Missionary&Cannibal game
	private:
		int missionary_left=3;				//store missionaries on left side
		int missionary_right=0;				//store missionaries on right side
		int cannibal_left=3;				//store cannibals on left side
		int cannibal_right=0;				//store cannibals on right side
		bool boat_left=true;				//stores if boat is in left bank
		
	public:
		void choose_level() override{		//only one level in this game
			cout<<"Playing Missionary and Cannibal Level 1-- 2 people on the boat at one time"<<endl;
		}
		
		void play_game() override{			//overrides the abstract function
			
			while (missionary_right != 3 || cannibal_right != 3) {		//loop will continue till all 3 missionaries and cannibals reach right bank
				
            	cout<< "\nLeft bank - M: " << missionary_left << "\t C: " << cannibal_left<<endl;		//will show current status in the left river bank
            	cout<<" | Right bank - M: " << missionary_right << "\t C: " << cannibal_right << endl;	//will show current status in the right river bank
            	
	            int missionary_boat, cannibal_boat;													//will store how many missionaries and cannibals in boat
	            cout << "Enter number of missionaries to move (0,1,2): ";							//asks user for no of missionaries to put in boat
	            cin >> missionary_boat;
	            cout << "Enter number of cannibals to move (0,1,2): ";								//asks user for no of cannibals to put in boat
	            cin >> cannibal_boat;

	            if (missionary_boat + cannibal_boat > 2 || missionary_boat > 2 || cannibal_boat >2) {				//checks if the boat capacity condition is met or not
	                cout << "Invalid move. Boat can carry maximum 2 people." << endl;
	                continue;
	            }
            	
	            if (boat_left) {			
					cout<<"BOAT MOVING FROM LEFT TO RIGHT"<<endl;									//moving the boat from left bank to right bank
					cout<<"-------------------------------------------------------------\n";
	                if (missionary_boat > missionary_left || cannibal_boat > cannibal_left) {		//will check if enough people are present on the left river bank
	                    cout << "Not enough people on left bank!" << endl;
	                    continue;
	                }
	                missionary_left=missionary_left-missionary_boat;			//subtracting missionaries from left bank	
	                cannibal_left=cannibal_left-cannibal_boat;					//subtracting cannibals from left bank
	                missionary_right=missionary_right+missionary_boat;			//adding missionaries to right bank
	                cannibal_right=cannibal_right+cannibal_boat;				//adding cannibals to right bank
	            } 
				
				else {				//moving the boat from right to left bank
					cout<<"\nBOAT MOVING FROM RIGHT TO LEFT"<<endl;
					cout<<"-------------------------------------------------------------\n";
	                if (missionary_boat > missionary_right || cannibal_boat > cannibal_right) {			//checks if enough people present in the right bank
	                    cout << "Not enough people on right bank!" << endl;
	                    continue;
	                }
	                missionary_right=missionary_right-missionary_boat;			//subtracting missionaries from right bank	
	                cannibal_right=cannibal_right-cannibal_boat;					//subtracting cannibals from right bank
	                missionary_left=missionary_left+missionary_boat;			//adding missionaries to left bank
	                cannibal_left=cannibal_left+cannibal_boat;				//adding cannibals to left bank
	            }

	            boat_left = !boat_left; 									//moving the boat to opposite side
	
				                                                            //checking the losing condition: cannibals>missionaries on either bank
	            if ((missionary_left > 0 && missionary_left < cannibal_left) || (missionary_right > 0 && missionary_right < cannibal_right)) {
	                cout << "\nCannibals ate missionaries. GAME OVER!!" << endl;
	                return;
	            }
	    	}
        	cout << "\nCongratulations! All missionaries and cannibals are safely on the right bank." << endl;  //wins game otherwise
		}
};

class chess : public Game{					//derived class: N queen problem
	private:
		int level;							//will store difficulty of level
		int n;								//will store size of board: 4 or 8
		char board[10][10];					//keeping board size as 10*10
		
	public:
		void choose_level() override{			//overrides abstract function
			cout<<"Choose a level"<<endl;		//asks user for difficulty level
			cout<<"Level 1: FOUR QUEENS"<<endl;		
			cout<<"Level 2: EIGHT QUEENS"<<endl;
			cin>>level;								//takes input from the user
			if (level==1){
				cout<<"Playing 4Q level 1"<<endl;			
				n=4;								//will set 4*4 board if level=1
			}
			else{
				cout<<"playing 8Q level 2"<<endl;
				n=8;								//will set 8*8 board if level=2
			}
			for (int i=0; i<n;i++){					//initializing the board rows
				for (int j=0;j<n;j++){				//initializing the board columns
					board[i][j]='.';				//initializing the board cells with a '.'
				}
			}
		}
		
		void display_board(){						//printing the current board
			cout<<"\nCurrent Board\n";
			cout<<"\n-----------------------------------------------------------------------------------------------------------------------------\n";
			for (int i=0; i<n;i++){					//loop rows
				for (int j=0;j<n;j++){				//loop columns
					cout<<board[i][j]<<"\t|\t";		//print the cell with the tab separator
				}
			cout<<"\n-----------------------------------------------------------------------------------------------------------------------------\n";
			}
		}
		
		bool check_queen(int row, int col){				//checking if queen can be placed at given row and column
			for (int j=0;j<col;j++){					//check left side
				if (board[row][j]=='Q'){
					return false;						//returns false if queen is found
				}
			}
			for (int i=row-1,j=col-1; i>=0 && j>=0; i--,j--){	//check upper-left diagonal...moves up-left
				if (board[i][j]=='Q'){						
					return false;							//returns false if queen is found on diagonal
				}
			}
			for (int i=row+1, j=col-1; i<n &&j>=0;i++,j--){				//check lower-left diagonal...moves down-left
				if (board[i][j]=='Q'){
					return false;							//returns false if queen is found 
				}
			}
			return true;								//returns true if no conflicts are found
		}
		
		bool solve_game(int col){						//recursive function: placing queens by column
			if (col==n){								//base case: checking if all columns are processed
				return true;							//returns true since solution is found
			}
			for (int row=0;row<n;row++){				//loop to try to place queens in all the rows of passed column
				if (check_queen(row, col)){				//calling function to check if queen is safe to place
					board[row][col]='Q';				//places queen if truw
					if (solve_game(col+1)){				//trying to place next column recursively
						return true;
					}
					board[row][col]='.';				//backtracking if false...remove queen and trying next row
				}
			}
			return false;								//no placement possible in this column...hence backtrack
		}
		
		void play_game() override{						//overriding abstract function					
			if (solve_game(0)){							//starting the solving from column 0
				cout<<"Solution exists"<<endl;			//solution exists if solver returns TRUE
				display_board();						//displaying the final board
			}
			else{
				cout<<"NO SOLUTION EXISTS"<<endl;
			}
		}
};


class tower_of_hanoi : public Game{						//derived class for tower of hanoi game
	private:
		int level,n;									//will store the difficulty level and no of disks
		
	public:
		void choose_level() override{					//overrides the abstract function
			cout<<"Choose a level"<<endl;				//asks user for difficulty level
			cout<<"Level 1: THREE DISKS"<<endl;
			cout<<"Level 2: FIVE DISKS"<<endl;
			cin>>level;									//takes input from user
		}
		
		void move_disks(int n, char source, char destination, char temporary){		//recursive function to solve
			if (n==1){																//base case: only one disk is left
				cout<<"Move disk 1 from "<<source<<" to "<<destination<<endl;
				return;																//recursion ends 
			}
			move_disks(n-1,source,temporary,destination);						//moves (n-1) disks from source to temporary using destination
			cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;		//moves remaining largest disk from source to destination
			move_disks(n-1, temporary,destination,source);						//moves (n-1) disks from temporary to destination using source	
		}
		
		void play_game() override{						//overrides the abstract function
			if (level==1){
				cout<<"\n--------------------------------------------------"<<endl;
				cout<<"Playing Tower Of Hanoi level 1"<<endl;
				n=3;									//setting no of disks as 3 if level chosen=1
			}
			else{
				cout<<"\n--------------------------------------------------"<<endl;
				cout<<"Playing TOH level 2"<<endl;
				n=5;									//setting no of disks as 5 if level chosen=2
			}
			move_disks(n,'A','C','B');				//calling the function to move n disks from A to C using B as helper
		}
		
		
};



int main(){
	Game *g = NULL;				//creating a base class pointer and initializing it to NULL value
	int choice, flg=1;
	cout<<"-------------------------------------------------"<<endl;
	cout<<"\nGAME THEORY IMPLEMENTATION\n"<<endl;
	cout<<"1. Tic Tac Toe"<<endl;
	cout<<"2. Water Jug Problem"<<endl;
	cout<<"3. Missionary and Cannibal"<<endl;
	cout<<"4. N Queen Problem"<<endl;
	cout<<"5. Tower of Hanoi"<<endl;
	cout<<"-------------------------------------------------\n"<<endl;
	while (flg==1){
		cout<<"Enter your choice:";
		cin>>choice;							//takes the user's choice of game
		switch(choice){
			case 1:
				g= new tic_tac_toe();			//allocate Tic Tac Toe object
				break;
			case 2:
				g= new water_jug();				//allocate Water Jug object
				break;
			case 3:
				g= new missionary_cannibal();	//allocate Missionary and Cannibal object
				break;
			case 4:
				g= new chess();					//allocate N Queen object
				break;
			case 5:
				g= new tower_of_hanoi();		//allocate Tower of Hanoi object
				break;
			default:
				cout<<"Invalid choice...try again"<<endl;
				continue;						//restart the loop if invalid case met
		}
		g->choose_level();						//calls level selection (runtime poly)
		g->play_game();							//calls actual gameplay (runtime poly)
		delete g;								//free the dynamically allocated memory
		cout<<"Want to continue?	1. Yes	0.No"<<endl;
		cin>>flg;
	}
	return 0;									//program ends
}
