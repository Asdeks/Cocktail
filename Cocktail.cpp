#include <iostream>
#include <vector>
#include <cstdlib> // For rand() function
#include <ctime>   // For time() function

using namespace std;

class Cocktail {
private:
    string name;
    vector<string> ingredients;

public:
    Cocktail(string cocktailName) {
        name = cocktailName;
    }

    void addIngredient(string ingredient) {
        ingredients.push_back(ingredient);
    }

    void displayIngredients() {
        cout << "Ingredients for cocktail '" << name << "':" << endl;
        for (int i = 0; i < ingredients.size(); i++) {
            cout << i + 1 << ". " << ingredients[i] << endl;
        }
    }

    string getName() const {
        return name;
    }
};

int main() {
    // Set up random number generator
    srand(time(0));

    vector<Cocktail> cocktails;
    cocktails.push_back(Cocktail("Mojito"));
    cocktails.push_back(Cocktail("Pina Colada"));
    cocktails.push_back(Cocktail("Margarita"));
    cocktails.push_back(Cocktail("Cosmopolitan"));

    cocktails[0].addIngredient("White rum, Soda water, Lime juice, Sugar");
    cocktails[1].addIngredient("White rum, Coconut milk, Pineapple juice");
    cocktails[2].addIngredient("Silver tequila, Orange liqueur, Lime juice");
    cocktails[3].addIngredient("Vodka, Cranberry juice, Lime juice, Triple sec");

    char userInput;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "Press Enter to select a random cocktail. Press 'x' to exit the program." << endl;
        userInput = cin.get();

        if (userInput == '\n') { // Enter was pressed
            int randomIndex = rand() % cocktails.size();
            Cocktail randomCocktail = cocktails[randomIndex];
            cout << "Randomly selected cocktail: " << randomCocktail.getName() << endl;
            randomCocktail.displayIngredients();
            cout << endl;
        } else if (userInput == 'x' || userInput == 'X') { // User pressed 'x'
            exitProgram = true;
        } else {
            cin.ignore(); // Clear input buffer in case of invalid input
        }
    }

    return 0;
}