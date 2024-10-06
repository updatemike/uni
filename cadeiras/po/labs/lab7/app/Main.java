// // The class that contains the main should:
// // 1. Create the main entity of the core application that gives context to the MainMenu
// // 2. Create the main menu and open it 
package app;

import core.IntegerManager;
import app.main.MainMenu;

public class Main {
    public static void main(String[] args) {
        IntegerManager obj = new IntegerManager();
        MainMenu menu = new MainMenu(obj);
        menu.open();
    }
}
