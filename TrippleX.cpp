#include <iostream>
#include <ctime>


void GameIntro(int LevelDifficulty){
    std::cout << "\nYou wakeup from your cryo bed and don't see anyone around to investigate you need to get out of the room.. !!\n" ;
    std::cout << "But the room door has a 3 digit number lock which you need to figure out..\n\n";
}

bool PlayGame(int LevelDifficulty){
   GameIntro(LevelDifficulty);

    int Digit1 = rand() % (LevelDifficulty+ LevelDifficulty);
    int Digit2 = rand()%(LevelDifficulty+LevelDifficulty);
    int Digit3 = rand()%(LevelDifficulty+LevelDifficulty);

    int DigitSum = Digit1 + Digit2 + Digit3;
    int DigitProd = Digit1 * Digit2 * Digit3;

    std::cout << "+ The sum of the 3 digits is: " << DigitSum << "\n";

    std::cout<< "+ The product of the 3 digits is: " << DigitProd << "\n\n";

    int GuessDigit1 , GuessDigit2 , GuessDigit3;

    std::cin >> GuessDigit1 >> GuessDigit2 >> GuessDigit3 ;
    std::cout << std::endl << "You entered: " << GuessDigit1 << " " << GuessDigit2 << " " << GuessDigit3 << "\n";

    int GuessSum =  GuessDigit1 + GuessDigit2 + GuessDigit3;
    int GuessProd = GuessDigit1 * GuessDigit2 * GuessDigit3;

    if (DigitSum == GuessSum && DigitProd == GuessProd){
        std::cout << "ACCESS GRANTED \n";
        return true;
    }else{
        std::cout << "ACCESS DENIED \n";
        return false;
    } 


}

int main()
{   
    const int MaxLevel = 6;
    int LevelDificulty = 1;
    srand(time(NULL));
    while(LevelDificulty <= MaxLevel){

        bool bLevelComplete = PlayGame(LevelDificulty);
        std::cin.clear();
        std::cin.ignore();
        if (bLevelComplete){
            ++LevelDificulty;
        }
    }
    std::cout << "**You Break Out Of The Cryo Chamber And Start Searching For Everone Else (To Be Continued..)**";
    return 0;
}