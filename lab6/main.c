/*
* Finite state machine implementation for a soda vending machine
* Inputs: 1, 2, 5 or 10 ruble coins
* States: Sx, where x is the value of coins in machine. One drink costs 5 rubles.
* Output: drink + change
*/

typedef enum {
    S0 = 0, // Used also when machine has 5 rubles
    S1 = 1,
    S2 = 2,
    S3 = 3,
    S4 = 4,
} State;

typedef enum {
    Coin1 = 1,
    Coin2 = 2,
    Coin5 = 5,
    Coin10 = 10
} Input;

// Output consists of 5 bits
typedef enum {
    Drink = 0x10,   // bit 4
    Change1 = 0x8,      // bit 3
    Change2 = 0x4,      // bit 2
    Change2x2 = 0x2,    // bit 1
    Change5 = 0x1       // bit 0
} Output;

char update(State* currState, Input in)
{
    // Default output is 0, which means no drink or change for you
    char out = 0;
    switch (*currState)
    {
        case S0:
            switch (in)
            {
                case Coin1:
                    (*currState) = S1;
                    break;
                case Coin2:
                    (*currState) = S2;
                    break; 
                case Coin5:
                    out = Drink;
                    break;
                case Coin10:
                    out = Drink | Change5; // 0 + 10 - 5 = 5 rub change
                    break;
            }
            break;
            
         case S1:
             switch (in)
            {
                case Coin1:
                    (*currState) = S2;
                    break;
                case Coin2:
                    (*currState) = S3;
                    break;
                case Coin5:
                    (*currState) = S0;
                    out = Drink | Change1; // 1 + 5 - 5 = 1 rub change
                    break;
                case Coin10:
                    (*currState) = S0;
                    out = Drink | Change1 | Change5; // 1 + 10 - 5 = 1 + 5 rub change
                    break;
            }
            break;
            
         case S2:
             switch (in)
            {
                case Coin1:
                    (*currState) = S3;
                    break;
                case Coin2:
                    (*currState) = S4;
                    break;
                case Coin5: 
                    (*currState) = S0;
                    out = Drink | Change2; // 2 + 5 - 5 = 2 rub change
                    break;
                case Coin10:
                    (*currState) = S0;
                    out = Drink | Change2 | Change5; // 2 + 10 - 5 = 2 + 5 rub change
                    break;
            }
            break;
            
         case S3:
             switch (in)
            {
                case Coin1:
                    (*currState) = S4;
                    break;
                case Coin2:
                    (*currState) = S0;
                    out = Drink;
                    break;
                case Coin5:
                    (*currState) = S0;
                    out = Drink | Change1 | Change2; // 3 + 5 - 5 = 1 + 2 rub change
                    break;
                case Coin10:
                    (*currState) = S0;
                    out = Drink | Change1 | Change2 | Change5; // 3 + 10 - 5 = 1 + 2 + 5 rub change
                    break;
            }
            break;
            
         case S4:
             switch (in)
            {
                case Coin1:
                    (*currState) = S0;
                    out = Drink;
                    break;
                case Coin2:
                    (*currState) = S0;
                    out = Drink | Change1; // 4 + 2 - 5 = 1 rub change
                    break;
                case Coin5:
                    (*currState) = S0;
                    out = Drink | Change2x2; // 4 + 5 - 5 = 2*2 rub change
                    break;
                case Coin10:
                    (*currState) = S0;
                    out = Drink | Change2x2 | Change5; // 4 + 10 - 5 = 2*2 + 5 rub change
                    break;
            }
            break;
    }
    return out;
}

int main()
{
    State currState = S0;
    Input coin = Coin1;
    char out = 0;
    while(1)
    {
        out = update(&currState, coin);
    }
    return 0;
}
