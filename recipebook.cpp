#include <iostream>
#include <string>

using namespace std;

class Ingredient
{
    string name;

public:
    Ingredient(string _name) : name(_name) {}

    string getName() const
    {
        return name;
    }
};

class Recipe
{
protected:
    string name;
    string preptime;

public:
    Recipe(string _name, string _preptime) : name(_name), preptime(_preptime) {}

    virtual void displayRecipe()
    {
        cout << "Recipe Name: " << name << endl;
        cout << "Preparation Time: " << preptime << endl;
    }
};

class Dish : public Recipe
{
    string method;

public:
    Dish(string _name, string _preptime, string _method) : Recipe(_name, _preptime), method(_method) {}

    void displayRecipe() override
    {
        Recipe::displayRecipe();
        cout << "Cooking Method: " << method << endl;
    }
};

int main()
{
    // Ingredients
    Ingredient ingredients[] = {Ingredient("Bread"), Ingredient("Cheese"), Ingredient("Butter"),
                                Ingredient("Macaroni"), Ingredient("Egg"), Ingredient("Onion"),
                                Ingredient("Rice"), Ingredient("Tomato"), Ingredient("Potato"),
                                Ingredient("Milk"), Ingredient("Spices"), Ingredient("Flour"),
                                Ingredient("Sugar"), Ingredient("Soya Sauce"), Ingredient("Curd"),
                                Ingredient("Oil"), Ingredient("Cucumber"), Ingredient("Paneer"),
                                Ingredient("Green Peas"), Ingredient("Capsicum")};

    // Recipes
    Dish dish1("Cheese Sandwich", "10-15 Minutes", "\n Take two slices of cheese bread or regular bread with a slice of cheese in between. \n Spread butter on the outside of each slice.\n Heat a non-stick pan over medium heat.\n Place the sandwich in the pan and cook until both sides turn golden brown and the cheese melts (about 2-3 minutes per side).\n Remove from the pan, let it cool for a moment, then cut and serve hot.");
    Dish dish2("Mac N Cheese", "15-20 Minutes", "\n Boil macaroni according to package instructions.\n Drain and return to the pot.\n Add grated cheese and a tablespoon of butter.\n Mix until the cheese melts and coats the macaroni.\n Season with salt and pepper if desired.");
    Dish dish3("Pulav", "30-40 Minutes", "\n Rinse and soak 1 cup of basmati rice for 20-30 minutes, then drain.\n Sauté mixed vegetables and whole spices in oil or ghee.\n Add the soaked rice and sauté briefly.\n Pour in 2 cups of water and add salt.\n Cook on low heat until the rice is done and the water is absorbed. Serve hot");
    Dish dish4("Aloo Paratha", "15-20 Minutes", "\n Mix boiled and mashed potatoes with chopped onion, green chilies, coriander leaves, and spices.\n Divide dough into small balls, flatten one, and stuff with potato mixture.\n Roll it out into a paratha.\n Cook on a griddle with ghee or oil until golden brown spots appear on both sides. Serve Hot");
    Dish dish5("Kheer", "40-50 Minutes", "\n In a heavy-bottomed pan, bring the milk to a boil.\n Add the rice and let it simmer on low heat, stirring occasionally to prevent it from sticking to the bottom.\n Once the rice is cooked and the milk has reduced and thickened, add sugar and cardamom powder.\n Simmer for a few more minutes until the sugar dissolves and the kheer reaches a creamy consistency. Serve Warm or Chilled");
    Dish dish6("Onion Pakoda", "30-40 Minutes", "\n Mix sliced onions with besan, red chili powder, salt, and a pinch of asafoetida.\n Add water to form a thick batter.\n Heat oil in a pan and drop spoonfuls of the batter.\n Fry until golden and crispy.\n Drain excess oil on a paper towel. Serve Hot");
    Dish dish7("Omelette", "5-10 Minutes", "\n Beat 2 eggs in a bowl with salt and pepper.\n Heat a non-stick pan and add butter or oil.\n Pour the egg mixture into the pan.\n Cook until the edges set, then fold it in half.\n Cook for a little longer until fully set but still moist. Serve Hot");
    Dish dish8("Samosa", "Around 1 Hour", "\n Make a dough with flour, oil, and water. Rest for 30 mins.\n Cook peas, mix with potatoes and spices.\n Roll dough, cut into semi-circles, fill with the potato mixture, and fold into triangles.\n Fry until golden brown. Serve hot");
    Dish dish9("Raita", "5-10 Minutes", "\n In a bowl, whisk the curd until smooth.\n Add the grated cucumber, salt, and roasted cumin powder if using. Mix well.\n Garnish with chopped cilantro if desired. Serve Chilled.");
    Dish dish10("Chilli Paneer", "30 Minutes", "\n Fry paneer until golden, set aside.\n Sauté garlic, chilies, onion, and bell pepper.\n Add soy sauce, ketchup, chili sauce, vinegar.\n Return paneer, mix, and season with salt. Garnish with coriander and serve hot.");

    // Menu
    cout << "Choose Ingredients (Enter 0 to stop):" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << i + 1 << ". " << ingredients[i].getName() << endl;
    }

    int selectedCount = 0;
    int choice;
    bool selected[20] = {false};

    do
    {
        cout << "Enter the ingredient number (0 to stop): ";
        cin >> choice;

        if (choice > 0 && choice <= 20)
        {
            selected[choice - 1] = true;
            selectedCount++;
        }
        else if (choice != 0)
        {
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 0 && selectedCount < 4);

    cout << "\n Suggested Recipes: " << endl;
    bool dish1Possible = selected[0] && selected[1] && selected[2];
    bool dish2Possible = selected[1] && selected[2] && selected[3];
    bool dish3Possible = selected[5] && selected[6] && selected[8] && selected[10];
    bool dish4Possible = selected[5] && selected[8] && selected[11] && selected[15];
    bool dish5Possible = selected[6] && selected[9] && selected[12];
    bool dish6Possible = selected[5] && selected[10] && selected[11] && selected[15];
    bool dish7Possible = selected[2] && selected[4] && selected[10];
    bool dish8Possible = selected[8] && selected[11] && selected[18] && selected[15];
    bool dish9Possible = selected[10] && selected[14] && selected[16];
    bool dish10Possible = selected[10] && selected[13] && selected[17] && selected[19] && selected[15];

    if (dish1Possible)
    {
        dish1.displayRecipe();
    }
    if (dish2Possible)
    {
        dish2.displayRecipe();
    }
    if (dish3Possible)
    {
        dish3.displayRecipe();
    }
    if (dish4Possible)
    {
        dish4.displayRecipe();
    }
    if (dish5Possible)
    {
        dish5.displayRecipe();
    }
    if (dish6Possible)
    {
        dish6.displayRecipe();
    }
    if (dish7Possible)
    {
        dish7.displayRecipe();
    }
    if (dish8Possible)
    {
        dish8.displayRecipe();
    }
    if (dish9Possible)
    {
        dish9.displayRecipe();
    }
    if (dish10Possible)
    {
        dish10.displayRecipe();
    }
    if (!dish1Possible && !dish2Possible && !dish3Possible && !dish4Possible && !dish5Possible && !dish6Possible && !dish7Possible && !dish8Possible && !dish9Possible && !dish10Possible)
    {
        cout << "No matching recipes found for the selected ingredients." << endl;
    }

    return 0;
}
