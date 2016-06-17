@@ -7,9 +7,134 @@
//

#include <iostream>
#include <random>
#include <stdlib.h>
using namespace std;
int numberOfPlayers;
int iIndexCardNow;
int maxSum;
int idOfWinner;
struct Card{
    string Face;
    int point;
    int flag;
};
Card deck[8];
int flag=1;


class player {
public: string nameOfPlayer;
public: int idOfPlayer,sum;
public: player(string name,int id) {
        nameOfPlayer = name;
        idOfPlayer = id;
        sum=0;
    }
    void GetCard (int card) {
        sum=sum+card;
    }
    int checkOfMuch (int sum){
        if (sum>21)
            return 1;
        else
            return 0;
    }
};
void  Filling (Card *deck){
    deck[0].Face = '6';
    deck[0].point = 6;
    deck[0].flag = 4;
    deck[1].Face = '7';
    deck[1].point = 7;
    deck[1].flag = 4;
    deck[2].Face = '8';
    deck[2].point = 8;
    deck[2].flag = 4;
    deck[3].Face = '9';
    deck[3].point = 9;
    deck[3].flag = 4;
    deck[4].Face =  "10";
    deck[4].point = 10;
    deck[4].flag = 4;
    deck[5].Face = "Валет";
    deck[5].point = 2;
    deck[5].flag = 4;
    deck[6].Face = "Дама";
    deck[6].point = 3;
    deck[6].flag = 4;
    deck[7].Face = "Король";
    deck[7].point = 4;
    deck[7].flag = 4;
    deck[8].Face = "Туз";
    deck[8].point = 11;
    deck[8].flag = 4;
}
player *AllPlayer[5];
string nameBuff;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    setlocale(LC_ALL, "Russian");
    Filling(deck);
    cout << "Max 6 players.\n\n";
    cout << "Сколько игроков будет играть? ";
    cin >> numberOfPlayers;
    for (int i = 0; i < numberOfPlayers; i++){
        cout << "Введите имя игрока " << i+1 << ":" << " ";
        cin >> nameBuff;
        AllPlayer[i]=new player(nameBuff,i);
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0,8);
    for (int i = 0; i < numberOfPlayers; i++){
        flag=1;
        while (flag){
            while (1){
                iIndexCardNow = dist(gen);
                if (deck[iIndexCardNow].flag < 0)
                    continue;
                else {
                    deck[iIndexCardNow].flag = deck[iIndexCardNow].flag-1;
                    break;
                }
            }
        AllPlayer[i]->GetCard(deck[iIndexCardNow].point);
        cout << "Играет " << "игрок " << AllPlayer[i]->nameOfPlayer << endl;
        cout << "Ваши очки: " << AllPlayer[i]->sum << endl;
        if (AllPlayer[i]->checkOfMuch(AllPlayer[i]->sum)){
            cout << "Перебор"<<endl;
            break;
        }
        cout << "Еще?(y/n)"<<endl;
        while (1){
                char ch;
                cin >> ch;
                if (ch != 121)
                {
                    if (ch != 110)
                    {
                        continue;
                    }
                }
                if (ch == 121)
                {
                    flag = 1; break;
                }
                if (ch == 110)
                {
                    flag = 0; break;
                }
            }
        }
    }
    maxSum = 0;
    for (int i = 0; i < numberOfPlayers;i++){
        if ((!(AllPlayer[i]->checkOfMuch(AllPlayer[i]->sum))) & (AllPlayer[i]->sum > maxSum)){
            maxSum = AllPlayer[i]->sum;
            idOfWinner = i;
        }
    }
    cout << "Победил игрок " << AllPlayer[idOfWinner]->nameOfPlayer << endl;
    return 0;
}
} 
