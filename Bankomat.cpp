#include <iostream>
using namespace std;

void menu() {
    cout << "--------MENU--------" << endl;
    cout << "1    *zustatek*     " << endl;
    cout << "2     *vyber*       " << endl;
    cout << "3   *zmena pinu*    " << endl;
    cout << "4 *konec programu*  " << endl;
    cout << "--------------------" << endl;
}

void zustatek(int zustatek) {
    cout << "zustatek na ucte je:" << zustatek << "Kc" << endl;
}

void vyber(int& penize, int& zustatek) {
    cout << "zadejte hotovost kterou chcete vybrat: ";
    cin >> penize;
    if (penize < zustatek) {
        if (penize % 200 == 0) {
            cout << "-" << penize << "kc" << endl;
            zustatek -= penize;
            cout << "zustatek na ucte je: " << zustatek << "Kc" << endl;
        }
        else {
            cout << "castku nelze vybrat" << endl;
        }
    }
    else {
        cout << "nedostatek penez na ucte" << endl;
    }
}

void zmenaPinu(int& pin) {
    int novyPin;
    cout << "zadejte novy pin: ";
    cin >> novyPin;
    cout << endl;
    cout << "novy pin nastaven";
    pin = novyPin;
}

int main(){
    int ucty[5][3] = {
        {549484, 5493, 89753},
        {186403, 2289, 169700},
        {147943, 1084, 58900},
        {900923, 7218, 257697},
        {362723, 1234, 15970}
    };

    int cisloKarty, pin, penize;
    string akce;
    cout << "zadejte cislo karty: ";
    cin >> cisloKarty;
    cout << "zadejte pin: ";
    cin >> pin;

    for (int i = 0; i < 5; i++) {
        if (ucty[i][0] == cisloKarty && ucty[i][1] == pin) {
            while (akce != "konecprogramu") {
                menu();
                cin >> akce;

                if (akce == "zustatek") {
                    zustatek(ucty[i][2]);
                }
                else if (akce == "vyber") {
                    vyber(penize, ucty[i][2]);
                }
                else if (akce == "zmenapinu") {
                    zmenaPinu(ucty[i][1]);
                }
                else if (akce == "konecprogramu") {
                    return 0;
                }
            }

            return 0;
        }
    }
    cout << "spatne cislo karty nebo pin, zkuste znovu: " << endl;

    return 0;
}