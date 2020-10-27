#include <iostream>
#include <vector>
#include <conio.h>
#include <ctime>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>

class taskLogin
{
public:
    int col = 3, row = 3, c = 0, r = 0, moves = 3, attempts = 3, passCount = 0;
    char star = '*';

    std::vector<std::vector<int> > loginPanel{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

public:
    void showLogin()            // Prints the loginPanel.
    {
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (i == c && j == r)
                {
                    std::cout << star << " ";
                }
                else
                {
                    std::cout << loginPanel[i][j] << " ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << '\n';
    }

    void loginSwitch()      // Gets user input and moves around the login accordingly.
    {
        while (true)
        {          
            showLogin();

            switch (_getch())
            {
            case 'w':
                if (c == 0)
                {
                    c = 0;
                }
                else
                {
                    c--;
                }
                break;
            case 'a':
                if (r == 0)
                {
                    r = 0;
                }
                else
                {
                    r--;
                }
                break;
            case 's':
                if (c == 2)
                {
                    c = 2;
                }
                else
                {
                    c++;
                }
                break;
            case 'd':
                if (r == 2)
                {
                    r = 2;
                }
                else
                {
                    r++;
                }
                break;
            }

            loginCheck();
            
            if (passCount == 4)
            {
                break;
            }

            attemptCheck();

            std::cout << "You have: " << moves << " move/s left.\n\n";
            moves--;
        }
    }

    void loginCheck()           // Adds a counter for every correct movement.
    {
        if (c == 1 && r == 0 && moves == 3)
        {
            passCount++;
        }
        else if (c == 1 && r == 1 && moves == 2)
        {
            passCount++;
        }
        else if (c == 0 && r == 1 && moves == 1)
        {
            passCount++;
        }
        else if (c == 0 && r == 2 && moves == 0)
        {
            passCount++;
        }      
    }
    void attemptCheck()     // Checks if one is out of attempts. If one is the game exits.
    {
        if (moves == 0)
        {
            attempts--;
            std::cout << "You have: " << attempts << " attempt/s left.\n\n";
            c = 0;
            r = 0;
            moves = 4;
            passCount = 0;
        }
        else if (attempts == 0)
        {
            std::cout << "You are out of attempts\n";
            exit(EXIT_SUCCESS);
        }
  
    }

}login;

std::vector<int> die(2000);
std::vector<int> dieValue(0);

class taskOne
{
public:
    int ones = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0;
public:
    void task1()
    {
        std::cout << "Welcome to task one!\n\n";
        dieRoll();

    }

    void dieRoll()
    {
        std::cout << "throwing a die 2000 times.\n";

            for (int i = 0; i < die.size(); i++)
            {
                die[i] = rand() % 6 + 1;

                dieValue.push_back(die[i]);
            }

            for (int i = 0; i < dieValue.size(); i++)
            {
                

                if (dieValue[i] == 1)
                {
                    ones++;
                }
                
                if (dieValue[i] == 2)
                {
                    twos++;
                }

                if (dieValue[i] == 3)
                {
                    threes++;
                }

                if (dieValue[i] == 4)
                {
                    fours++;
                }

                if (dieValue[i] == 5)
                {
                    fives++;
                }

                if (dieValue[i] == 6)
                {
                    sixes++;
                }
            }

            std::sort(dieValue.begin(), dieValue.end());

            std::cout << "Your rolls: \n\n";
            std::cout << "1: " << ones << '\n';
            std::cout << "2: " << twos << '\n';
            std::cout << "3: " << threes << '\n';
            std::cout << "4: " << fours << '\n';
            std::cout << "5: " << fives << '\n';
            std::cout << "6: " << sixes << '\n';
            
    }

}one;

class taskTwo
{
public:
    std::vector<int> value{0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> no{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<char> name{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
    std::vector<char> health{ '*', '*', '*', '*', '*','*', '*', '*', '*' };

    int printLimit = 9;

public:

    void task2()
    {
        std::cout << "Welcome to task two!\n\n";
        tablePrint();
        
    }

    void tablePrint()
    {
        std::cout << "Printing random numbers between 1 and 20: ";

        for (int i = 0; i < value.size(); i++)
        {
            value[i] = rand() % 20 + 1;

            std::cout << value[i] << " ";
        }
        std::cout << std::endl;

        visualPrint();

        std::sort(value.begin(), value.end());

        std::cout << "\nPrinting random numbers sorted: \n";

        for (int i = 0; i < value.size(); i++)
        {
            std::cout << value[i] << " ";
        }
        std::cout << std::endl;
        
        visualPrint();
    }
    
    void visualPrint()
    {

        std::cout << "\nNo     " << "Name   " << "Value     " << "Health Bar\n";
        std::cout << "---------------------------------------------------------------\n";
        for (int i = 0; i < printLimit; i++)
        {
            std::cout << no[i];
            std::cout << '\t' << name[i];
            std::cout << '\t' << value[i];
            std::cout << '\t';

            for (int j = 0; j < value[i]; j++)
            {
                std::cout << health[i];
            }
            std::cout << std::endl;
        }

        std::cout << "\t";
    }

}two;

class taskThree
{
public:
    static constexpr int c = 32, r = 18;
    int col = 1, row = 1, playerScore = 0;

    char player = 'E';

    char pacMap[r][c]

    {
        {'+', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '+'},
        {'|', '-', '-', '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', '#', '#', '-', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|'},
        {'|', ' ', ' ', '-', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', '|', '-', '|', '#', '#', '#', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', '|', '-', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', '#', '#', '#', '#', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', '|'},
        {'|', ' ', '|', '-', '#', '#', '#', '#', '#', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', '|', '-', '-', '-', '-', '-', '-', ' ', ' ', ' ', ' ', '|', '#', '#', '#', '#', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', '|', '#', '#', '#', '#', '#', '-', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', ' ', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'+', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '+'}

    };



public:
    void task3()
    {
        std::cout << "Welcome to task 3!\n\n";

        boardSwitch();
    }
    
    void boardPrint()   // Prints the gameboard.
    {
        for (int i = 0; i < r; i++)
        {
            std::cout << " ";
            for (int j = 0; j < c; j++)
            {
                std::cout << pacMap[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "Your score is: " << playerScore << "\n";
        std::cout << "\n";
    }

    void boardSwitch()      // Allows the player to move around the board within it's boundaries. Adds score for collecting '-'.
    {
        while (true)
        {
            pacMap[row][col] = player;
            boardPrint();

            switch (_getch())
            {
            case 'w':
                if (pacMap[row - 1][col] == '#' || pacMap[row - 1][col] == '|')
                {
                    if (pacMap[row][col] == '#')
                    {
                        pacMap[row][col] = '#';
                    }
                    else if (pacMap[row][col] == '|')
                    {
                        pacMap[row][col] = '|';
                    }
                }
                else if (pacMap[row - 1][col] == '-')
                {
                    pacMap[row][col] = ' ';
                    playerScore += 5;
                    row--;
                }
                else
                {
                    pacMap[row][col] = ' ';
                    row--;
                }
                break;
            case 'a':
                if (pacMap[row][col - 1] == '#' || pacMap[row][col - 1] == '|')
                {
                    if (pacMap[row][col] == '#')
                    {
                        pacMap[row][col] = '#';
                    }
                    else if (pacMap[row][col] == '|')
                    {
                        pacMap[row][col] = '|';
                    }
                }
                else if (pacMap[row][col - 1] == '-')
                {
                    pacMap[row][col] = ' ';
                    playerScore += 5;
                    col--;
                }
                else
                {
                    pacMap[row][col] = ' ';
                    col--;
                }
                break;
            case 's':
                if (pacMap[row + 1][col] == '#' || pacMap[row + 1][col] == '|')
                {
                    if (pacMap[row][col] == '#')
                    {
                        pacMap[row][col] = '#';
                    }
                    else if (pacMap[row][col] == '|')
                    {
                        pacMap[row][col] = '|';
                    }
                }
                else if (pacMap[row + 1][col] == '-')
                {
                    pacMap[row][col] = ' ';
                    playerScore += 5;
                    row++;
                }
                else
                {
                    pacMap[row][col] = ' ';
                    row++;
                }
                break;
            case 'd':
                if (pacMap[row][col + 1] == '#' || pacMap[row][col + 1] == '|')
                {
                    if (pacMap[row][col] == '#')
                    {
                        pacMap[row][col] = '#';
                    }
                    else if (pacMap[row][col] == '|')
                    {
                        pacMap[row][col] = '|';
                    }
                }
                else if (pacMap[row][col + 1] == '-')
                {
                    pacMap[row][col] = ' ';
                    playerScore += 5;
                    col++;
                }
                else
                {
                    pacMap[row][col] = ' ';
                    col++;
                }
                break;
            }
        }
    }

}three;

class taskFour : taskThree
{
public:
    char hostile = 'H';

    int rRow = 0, rCol = 0, moveInt = 0;

public:
    void task4()
    {
        std::cout << "Welcome to task 4!\n\n";

        pacAi();
        boardSwitch2();
    }

    void pacAi()    // Places the hostile character in a random blank spot in the board.
    {
        while (!(pacMap[rRow][rCol] == ' '))
        {
            rRow = rand() % 30 + 1;
            rCol = rand() % 16 + 1;
        }
    }

    void pacAiMove()        // Provides a random movement pattern for the Ai. The pattern is up, down, left, right based on a random number between 1 and 4.
    {
            moveInt = rand() % 4 + 1;

            if (pacMap[rRow - 1][rCol] == '#' || pacMap[rRow - 1][rCol] == '|')
            {
                if (pacMap[rRow][rCol] == '#')
                {
                    pacMap[rRow][rCol] = '#';
                }
                else if (pacMap[rRow][rCol] == '|')
                {
                    pacMap[rRow][rCol] = '|';
                }
            }
            else if (moveInt == 1)
            {
                pacMap[rRow][rCol] = ' ';
                rRow--;           
            }

            if (pacMap[rRow][rCol - 1] == '#' || pacMap[rRow][rCol - 1] == '|')
            {
                if (pacMap[rRow][rCol] == '#')
                {
                    pacMap[rRow][rCol] = '#';
                }
                else if (pacMap[rRow][rCol] == '|')
                {
                    pacMap[rRow][rCol] = '|';
                }
            }
            else if (moveInt == 2)
            {
                pacMap[rRow][rCol] = ' ';
                rCol--;
            }

            if (pacMap[rRow][rCol + 1] == '#' || pacMap[rRow][rCol + 1] == '|')
            {
                if (pacMap[rRow][rCol] == '#')
                {
                    pacMap[rRow][rCol] = '#';
                }
                else if (pacMap[rRow][rCol] == '|')
                {
                    pacMap[rRow][rCol] = '|';
                }
            }
            else if (moveInt == 3)
            {
                pacMap[rRow][rCol] = ' ';
                rCol++;
            }

            if (pacMap[rRow + 1][rCol] == '#' || pacMap[rRow + 1][rCol] == '|')
            {
                if (pacMap[rRow][rCol] == '#')
                {
                    pacMap[rRow][rCol] = '#';
                }
                else if (pacMap[rRow][rCol] == '|')
                {
                    pacMap[rRow][rCol] = '|';
                }
            }
            else if (moveInt == 4)
            {
                pacMap[rRow][rCol] = ' ';
                rRow++;
            }
    }

    void boardSwitch2()  // Duplicating boardSwitch allows me to add the Ai movement.
    {
        while (true)
        {
            pacMap[row][col] = player;
            pacMap[rRow][rCol] = hostile;

            boardPrint();

            switch (_getch())
            {
            case 'w':
                if (pacMap[row - 1][col] == '#' || pacMap[row - 1][col] == '|')
                {
                    if (pacMap[row][col] == '#')
                    {
                        pacMap[row][col] = '#';
                    }
                    else if (pacMap[row][col] == '|')
                    {
                        pacMap[row][col] = '|';
                    }
                }
                else if (pacMap[row - 1][col] == '-')
                {
                    pacMap[row][col] = ' ';
                    playerScore += 5;
                    row--;
                }
                else
                {
                    pacMap[row][col] = ' ';
                    row--;
                }
                break;
            case 'a':
                if (pacMap[row][col - 1] == '#' || pacMap[row][col - 1] == '|')
                {
                    if (pacMap[row][col] == '#')
                    {
                        pacMap[row][col] = '#';
                    }
                    else if (pacMap[row][col] == '|')
                    {
                        pacMap[row][col] = '|';
                    }
                }
                else if (pacMap[row][col - 1] == '-')
                {
                    pacMap[row][col] = ' ';
                    playerScore += 5;
                    col--;
                }
                else
                {
                    pacMap[row][col] = ' ';
                    col--;
                }
                break;
            case 's':
                if (pacMap[row + 1][col] == '#' || pacMap[row + 1][col] == '|')
                {
                    if (pacMap[row][col] == '#')
                    {
                        pacMap[row][col] = '#';
                    }
                    else if (pacMap[row][col] == '|')
                    {
                        pacMap[row][col] = '|';
                    }
                }
                else if (pacMap[row + 1][col] == '-')
                {
                    pacMap[row][col] = ' ';
                    playerScore += 5;
                    row++;
                }
                else
                {
                    pacMap[row][col] = ' ';
                    row++;
                }
                break;
            case 'd':
                if (pacMap[row][col + 1] == '#' || pacMap[row][col + 1] == '|')
                {
                    if (pacMap[row][col] == '#')
                    {
                        pacMap[row][col] = '#';
                    }
                    else if (pacMap[row][col] == '|')
                    {
                        pacMap[row][col] = '|';
                    }
                }
                else if (pacMap[row][col + 1] == '-')
                {
                    pacMap[row][col] = ' ';
                    playerScore += 5;
                    col++;
                }
                else
                {
                    pacMap[row][col] = ' ';
                    col++;
                }
                break;
            }
            pacAiMove();
        }
    }
}four;

class menuTask
{
public:                     // Typing public 2 times to seperate functions and variables.
    int choice = 0;
    char choice2 = 0;

public:
    void printMenu()
    {
        std::cout << "******************Main Menu******************\n\n";
        std::cout << "1. Task 1\n";
        std::cout << "2. Task 2\n";
        std::cout << "3. Task 3\n";
        std::cout << "4. Task 4\n";
        std::cout << "5: Quit the program\n";

        while (!(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5))
        {
            std::cout << "\nPlease enter a number from 1 to 5:\n";
            std::cin >> choice;
            std::cin.clear();
            std::cin.ignore(36727, '\n');

            if (choice == 1)
            {
                one.task1();
                choice = 0;
                break;
            }
            else if (choice == 2)
            {
                two.task2();
                choice = 0;
                break;
            }
            else if (choice == 3)
            {
                three.task3();
                choice = 0;
                break;
            }
            else if (choice == 4)
            {
                four.task4();
                choice = 0;
                break;
            }
            else if (choice == 5)
            {
                exit(EXIT_SUCCESS);
            }
            else
            {
                while (!(choice2 == 'y' || choice2 == 'Y'))
                {
                    std::cout << "Wrong input, would you like to try again: (y/n)?";
                    std::cin >> choice2;
                    std::cin.clear();
                    std::cin.ignore(36727, '\n');

                    if (choice2 == 'y' || choice2 == 'Y')
                    {
                        choice2 = 0;
                        break;
                    }
                    else if (choice2 == 'n' || choice2 == 'N')
                    {
                        exit(EXIT_SUCCESS);
                    }
                }
            }
        }
    }
}menu;

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); //seed set seed value to system clock

    login.loginSwitch();

    while (true)
    {
        menu.printMenu();
    }
}