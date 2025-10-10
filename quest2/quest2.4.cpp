#include <iostream>
using namespace std;

int main() {

    cout << "Please type the number corresponding to the type item you'd like to browse:\n";
    cout << "1. Armor\n";
    cout << "2. Weapons\n";
    cout << "3. Potions\n";
    cout << "4. Clothing\n";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "You chose Armor.\n";
            cout << "Here are the options:\n";
            cout << "1. Helmet - 50 gold\n";
            cout << "2. Chestplate - 75 gold\n";
            cout << "3. Chainmail Leggings - 60 gold\n";
            cout << "4. Metal Boots - 40 gold\n";

            int armor;
            cin >> armor;

            switch (armor) {
                case 1:
                    cout << "That will be 50 gold.";
                    break;
                case 2:
                    cout << "That will be 75 gold.";
                    break;
                case 3:
                    cout << "That will be 60 gold.";
                    break;
                case 4:
                    cout << "That will be 40 gold.";
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            break;
        case 2:
            cout << "You chose Weapons.\n";
            cout << "Here are the options:\n";
            cout << "1. Stick - 50 gold\n";
            cout << "2. Sword - 75 gold\n";
            cout << "3. Mace - 60 gold\n";
            cout << "4. Spear - 40 gold\n";

            int weapons;
            cin >> weapons;

            switch (weapons) {
                case 1:
                    cout << "That will be 50 gold.";
                    break;
                case 2:
                    cout << "That will be 75 gold.";
                    break;
                case 3:
                    cout << "That will be 60 gold.";
                    break;
                case 4:
                    cout << "That will be 40 gold.";
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            break;
        case 3:
            cout << "You chose Potions.\n";
            cout << "Here are the options:\n";
            cout << "1. Slowness - 50 gold\n";
            cout << "2. Speed - 75 gold\n";
            cout << "3. Luck - 60 gold\n";
            cout << "4. Jump - 40 gold\n";

            int potions;
            cin >> potions;

            switch (potions) {
                case 1:
                    cout << "That will be 50 gold.";
                    break;
                case 2:
                    cout << "That will be 75 gold.";
                    break;
                case 3:
                    cout << "That will be 60 gold.";
                    break;
                case 4:
                    cout << "That will be 40 gold.";
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            break;
        case 4:
            cout << "You chose Clothing.\n";
            cout << "Here are the options:\n";
            cout << "1. Tshirt - 50 gold\n";
            cout << "2. Top Hat - 75 gold\n";
            cout << "3. Socks - 60 gold\n";
            cout << "4. Gloves - 40 gold\n";

            int clothing;
            cin >> clothing;

            switch (clothing) {
                case 1:
                    cout << "That will be 50 gold.";
                    break;
                case 2:
                    cout << "That will be 75 gold.";
                    break;
                case 3:
                    cout << "That will be 60 gold.";
                    break;
                case 4:
                    cout << "That will be 40 gold.";
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }

    return 0;
}