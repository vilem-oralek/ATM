#include <iostream>
using namespace std;

int main()
{

    //c. karty   pin   penize
    int ucty[5][3] = { {549684, 5493, 89753},
                        {186403, 4289, 169700},
                        {147943, 1084, 58900},
                        {950943, 2683, 257697},
                        {364723, 7816, 15970} };

    int cislokarty, pin, penize;
    string akce;
    cout << "zadejte cislo karty: ";
    cin >> cislokarty;
    cout << "zadejte pin: ";
    cin >> pin;

    for (int i = 0; i < 5; i++) {
        if (ucty[i][0] == cislokarty) {
            if (ucty[i][1] == pin) {
                cout << "uzivatel prihlasen: zustatek, vyber: ";
                cin >> akce;
                if (akce == "zustatek") {
                    cout << ucty[i][2];
                }
                else if (akce == "vyber") {
                    cout << "zadejte hotovost kterou chcete vybrat: ";
                    cin >> penize;
                    if (penize < ucty[i][2]) {
                        cout << "-" << penize << "kc" << endl;
                        cout << "zustatek na ucte je: " << ucty[i][2] - penize << "kc";
                    }
                    else cout << "nedostatek penez na ucte";
                }
            }
            else cout << "spatne cislo karty nebo pin, zkuste znovu: " << endl;
        }
    }
    return 0;
}
