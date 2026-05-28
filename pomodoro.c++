#include <iostream>
#include <Windows.h>
#include <array>
using namespace std;


static int result = 0 , sessions = 1 , breakss = 1;

class data{
    private:
        array<int , 3>datas = {
            0,  // 0 Min_Timer
            0,  // 1 Min_Break
            60  // 2 sec
        };

        array<int , 2>saves = {
            0, // 1 Min_Timer
            0  // 2 Min_Break
        };

        array<string , 2>chara = {
            "Min_Timer",
            "Min_Break",
        };

        int sizes = datas.size();

        public:
            data(){
                for(int i = 0; i < (sizes - 1) ; ++i){
                    cout << "how many " << chara[i] <<" : ";
                    cin >> datas[i];
                    saves[i] += datas[i];
                }
            }

        int Timer(){
            // set_value[0] /= 60;
            result += datas[0];
            datas[2] = 60;
            datas[0] -= 1;
            while(true){
                    cout << "\033[2J\033[1;1H";

                    if(datas[0] <= 0 && datas[2] <= 0){
                        break;
                    }
                
                    if(datas[2] <= 0){
                        datas[0]--;
                        datas[2] = 60;
                    }

                    cout << "\n===> "<< sessions <<" <===\n";
                    cout << "=  Timer  =";
                    cout << "\n===========\n";
                    cout << "=  " <<datas[0]<<":"<<datas[2];
                    cout << "\n===========\n";
                    Sleep(1000);
                    datas[2]--;
                }

            return result;
        }

        void breaks(){
                while(true){
                cout << "\033[2J\033[1;1H";

                    if(datas[1] <= 0 && datas[2] <= 0){
                        break;
                    }

                if(datas[2] <= 0){
                    datas[1]--;
                    datas[2] = 60;
                }
                
                cout << "\n===> "<< sessions <<" <===\n";
                cout << "=  Break  =";
                cout << "\n===========\n";
                cout << "=  "<<datas[1]<<":"<<datas[2];
                cout << "\n===========\n";
                Sleep(1000);
                datas[2]--;

                }
        
        }

        void reset(){
            for(int i = 0; i < (sizes - 1) ; ++i){
                datas[i] = saves[i];
            }
            datas[2] = 60;

            // datas[0] = datas[1] = datas[2] = 0;
        }
};

int main(){
int Time = 0;
cout << "how many Session: ";
cin >> Time;

data ob;
for(int i = 0; i < Time ; ++i){
    ob.Timer();
    ob.breaks();
    ob.reset();
    sessions++;
}

    cout << "Time: " << result << " m" << endl; 
    std::cout << "Test sound..." << std::endl;
    MessageBeep(MB_ICONASTERISK);
    
    return 0;
}