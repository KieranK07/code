#include <windows.h>

// callback window for all four
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case 1: // give four options for user to buy
                    // Armor
                    CreateWindow("BUTTON", "Chest Plate", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 60, 180, 30, hwnd, NULL, NULL, NULL);
                    CreateWindow("BUTTON", "Helmet", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 95, 180, 30, hwnd, NULL, NULL, NULL);
                    CreateWindow("BUTTON", "Gauntlets", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 130, 180, 30, hwnd, NULL, NULL, NULL);
                    CreateWindow("BUTTON", "Boots", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 165, 180, 30, hwnd, NULL, NULL, NULL);
                    // when the user clicks on armor all the other buttons from before have to be disabled
                    EnableWindow(GetDlgItem(hwnd, 1), FALSE);
                    EnableWindow(GetDlgItem(hwnd, 2), FALSE);
                    EnableWindow(GetDlgItem(hwnd, 3), FALSE);
                    EnableWindow(GetDlgItem(hwnd, 4), FALSE);
                    break;
                case 2: // Weapons 
                    // Create buttons for Weapon options
                    CreateWindow("BUTTON", "Sword", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 60, 180, 30, hwnd, NULL, NULL, NULL);
                    CreateWindow("BUTTON", "Axe", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 95, 180, 30, hwnd, NULL, NULL, NULL);
                    CreateWindow("BUTTON", "Bow", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 130, 180, 30, hwnd, NULL, NULL, NULL);
                    CreateWindow("BUTTON", "Dagger", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 165, 180, 30, hwnd, NULL, NULL, NULL);
                    // when the user clicks on weapons all the other buttons from before have to be disabled
                    EnableWindow(GetDlgItem(hwnd, 1), FALSE);
                    EnableWindow(GetDlgItem(hwnd, 3), FALSE);
                    EnableWindow(GetDlgItem(hwnd, 4), FALSE);
                    break;
                case 3: // Potions 
                    // Create buttons for Potion options
                    CreateWindow("BUTTON", "Health Potion", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 60, 180, 30, hwnd, NULL, NULL, NULL);
                    CreateWindow("BUTTON", "Mana Potion", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 95, 180, 30, hwnd, NULL, NULL, NULL);
                    CreateWindow("BUTTON", "Stamina Potion", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 130, 180, 30, hwnd, NULL, NULL, NULL);
                    CreateWindow("BUTTON", "Strength Potion", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 165, 180, 30, hwnd, NULL, NULL, NULL);
                    // when the user clicks on potions all the other buttons from before have to be disabled
                    EnableWindow(GetDlgItem(hwnd, 1), FALSE);
                    EnableWindow(GetDlgItem(hwnd, 2), FALSE);
                    EnableWindow(GetDlgItem(hwnd, 4), FALSE);
                    break;
                case 4: // Clothing 
                    // Create buttons for Clothing options
                    CreateWindow("BUTTON", "Robe", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 60, 180, 30, hwnd, NULL, NULL, NULL);
                    CreateWindow("BUTTON", "Boots", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 95, 180, 30, hwnd, NULL, NULL, NULL);
                    CreateWindow("BUTTON", "Gloves", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 130, 180, 30, hwnd, NULL, NULL, NULL);
                    CreateWindow("BUTTON", "Helmet", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                 60, 165, 180, 30, hwnd, NULL, NULL, NULL);
                    // when the user clicks on clothing all the other buttons from before have to be disabled
                    EnableWindow(GetDlgItem(hwnd, 1), FALSE);
                    EnableWindow(GetDlgItem(hwnd, 2), FALSE);
                    EnableWindow(GetDlgItem(hwnd, 3), FALSE);
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    // i dont know what im doing
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "InGameMenu";
    RegisterClass(&wc);

    // make main window
    HWND hwnd = CreateWindow("InGameMenu", "Store",
                             WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                             300, 300, NULL, NULL, hInstance, NULL);
    
    // make button
    CreateWindow("BUTTON", "Armor", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 50, 50, 200, 40, hwnd, (HMENU)1, hInstance, NULL);

    // button number 2
    CreateWindow("BUTTON", "Weapons", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 50, 100, 200, 40, hwnd, (HMENU)2, hInstance, NULL);

    // button number 3
    CreateWindow("BUTTON", "Potions", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 50, 150, 200, 40, hwnd, (HMENU)3, hInstance, NULL);

    // button number 4
    CreateWindow("BUTTON", "Clothing", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 50, 200, 200, 40, hwnd, (HMENU)4, hInstance, NULL);

    //show amount of gold
    CreateWindow("STATIC", "Gold: 100", WS_VISIBLE | WS_CHILD,
                 50, 0, 200, 40, hwnd, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);

    // message loop because they told me to
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
