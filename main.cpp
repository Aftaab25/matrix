#include <iostream>
#include <string>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <chrono>

const int width = 170;
const int flipsPerLine = 5;
const int sleepTime = 100;

using namespace std;

int main(){
    srand(time(NULL));
    bool switches[width] = {0};

    //List of characters to print from
    const string ch = "1234567890qwertyuiopasdfghjkl"
                      "zxcvbnm,./';[]!@#$%^&*()-=_+";
    const int len = ch.size();


    // For Green Colour
    system("Color 0A");
    
    //cout << "\033[1;32mbold red text\033[0m\n";
    //cout << "\033[1;32m ch[rand] bold red text \033[0m\n";

    while(true){
        for(int i=0; i<width; i+=2){
            if(switches[i]){
                char s = ch[rand() % len];
                // printf("\033[1;32m %c \033[0m\n ", s);
                // cout << ch[rand() % len] << " ";
                cout << s << " ";
            }
            else {
                cout << " ";
            }
        }

        for (int i=0; i!=flipsPerLine; ++i){
            int x = rand() % width;
            switches[x] = !switches[x];
        }

        cout << endl;

        this_thread::sleep_for(chrono::milliseconds(sleepTime));
    }

    return 0;
}
