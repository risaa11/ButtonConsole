#include "Button.h"

using namespace std;

int UIElement::count = 0;
vector<Button> listt;
int resultAgeConfirm = 1;

Button::Button() : size_x(10), size_y(3), text("Button"),
padding_horizontal(1), checkVal(false), target(false) {
}

Button::Button(int size_x, int size_y, string text, int padding_horizontal) :
    size_x(size_x + padding_horizontal), size_y(size_y), text(text),
    padding_horizontal(padding_horizontal), checkVal(false), target(false) {
    if (text.size() + padding_horizontal > size_x) {
        this->size_x = text.size() + 3 + padding_horizontal;
    }
}

bool Button::checktarget() { return target; }
void Button::swapTarget() { target = !target; }

void Button::draw() {
    string textBuffer = this->text;
    for (int i = 0; i < size_y; i++) {
        for (int j = 0; j < size_x; j++) {
            if (i == 0 || i == size_y - 1) { cout << '-'; continue; }
            if (j == 0 || j == size_x - 1) { cout << '|'; continue; }

            int a = size_x - textBuffer.size();

            if ((i == size_y / 2 && j > padding_horizontal && textBuffer.size() > 0 && j >= a / 2)
                && text == listt[resultAgeConfirm - 1].text) {
                cout << "\033[30;47m" << textBuffer[0] << "\033[0m";
                textBuffer.erase(0, 1);
                continue;
            }

            if (i == size_y / 2 && j > padding_horizontal && textBuffer.size() > 0 && j >= a / 2) {
                cout << textBuffer[0];
                textBuffer.erase(0, 1);
                continue;
            }

            text == listt[resultAgeConfirm - 1].text ?
                cout << "\033[47m \033[0m" : cout << " ";
        }
        cout << endl;
    }
}

Row::Row(vector<Button*> components) {
    for (auto& comp : components) this->components.push_back(comp);
}

void Row::printStr(int number)
{
        int temp = 1;
        while (temp < components.size())
        {
            string textBuffer = components[temp]->text;
            for (int c = 0; c < components[temp]->size_y; ++c)
            {
                if (number == 0 || number == components[temp]->size_y) { cout << '-'; continue; }
                if (c == 0 || c == components[temp]->size_x - 2) { cout << '|'; continue; }
                int a = components[temp]->size_x - textBuffer.size();

                if ((number == components[temp]->size_y / 2 && c > components[temp]->padding_horizontal && textBuffer.size() > 0 && c >= a / 2)
                    && components[temp]->text == listt[resultAgeConfirm - 1].text) {
                    cout << "\033[30;47m" << textBuffer[0] << "\033[0m";
                    textBuffer.erase(0, 1);
                    continue;
                }

                if (number == components[temp]->size_y / 2 && c > components[temp]->padding_horizontal && textBuffer.size() > 0 && c >= a / 2) {
                    cout << textBuffer[0];
                    textBuffer.erase(0, 1);
                    continue;
                }

                components[temp]->text == listt[resultAgeConfirm - 1].text ?
                    cout << "\033[47m \033[0m" : cout << " ";
            }
            ++temp;
            std::cout << "\t";
        }
        std::cout << std::endl;
}

void Row::draw() {
    for (int i = 0; i < components.size(); ++i)
    {
        if (i == 0)
        {
            components[i]->draw();
        }
        else
        {
            for (int j = 0; j < components[i]->size_x; j++)
            {
                printStr(j);
            }
            break;
        }
    }
}

Column::Column(vector<UIElement*> components) {
    for (auto& comp : components) this->components.push_back(comp);
}

void Column::draw() {
    for (auto& component : components) component->draw();
}

Window::Window(int size_x, int size_y, UIElement* component) :
    size_x(size_x), size_y(size_y), component(component) {
}

void Window::draw() {
    component->draw();
}

bool drawTest()
{
    Button text(30, 15, "Choose the color of your shapes");
    Button whiteColor(10, 10, "White");
    Button BlackColor(10, 10, "Black");
    Button hell(10, 10, "HELLO!!!");
    listt.push_back(whiteColor);
    listt.push_back(BlackColor);
    listt.push_back(hell);
    Row colorText({ &text, &whiteColor, &BlackColor, &hell });
    Window screen1(100, 100, &colorText);
    
    do
    {
        screen1.draw();
        int valueAge = _getch();
        switch (valueAge) {
        case 13:
            listt.clear();
            if (resultAgeConfirm != 2)
            {
                system("CLS");
                return true;
            }
            else
            {
                system("CLS");
                return false;
            }
        case 72:
        case 75:
            if (resultAgeConfirm > 1)
                resultAgeConfirm--;
            break;
        case 80:
        case 77:
            if (resultAgeConfirm < listt.size())
                resultAgeConfirm++;
            break;
        }
        system("CLS");
    } while (true);
}

bool selectStartColor() {
    bool sert = false;

    do {
        Button text(30, 15, "Choose the color of your shapes");
        Button whiteColor(10, 10, "White");
        Button BlackColor(10, 10, "Black");

        Column colorText({ &text, &whiteColor, &BlackColor });
        listt.push_back(whiteColor);
        listt.push_back(BlackColor);

        Window screen1(100, 100, &colorText);
        screen1.draw();

        int valueAge = _getch();
        switch (valueAge) {
        case 13:
            listt.clear();
            if (resultAgeConfirm != 2)
            {
                system("CLS");
                return true;
            }
            else
            {
                system("CLS");
                return false;
            }
        case 72:
        case 75:
            if (resultAgeConfirm > 1)
                resultAgeConfirm--;
            break;
        case 80:
        case 77:
            if (resultAgeConfirm < listt.size())
                resultAgeConfirm++;
            break;
        }
        system("CLS");
    } while (true);
}

bool selectGameMode()
{
    bool sert = false;

    do {
        Button text(30, 15, "Select a game mode");
        Button whiteColor(10, 10, "Play against a bot");
        Button BlackColor(10, 10, "Play alone");

        Column colorText({ &text, &whiteColor, &BlackColor });
        listt.push_back(whiteColor);
        listt.push_back(BlackColor);

        Window screen1(100, 100, &colorText);
        screen1.draw();

        int valueAge = _getch();
        switch (valueAge) {
        case 13:
            listt.clear();
            if (resultAgeConfirm != 2)
            {
                system("CLS");
                return true;
            }
            else
            {
                system("CLS");
                return false;
            }
        case 72:
        case 75:
            if (resultAgeConfirm > 1)
                resultAgeConfirm--;
            break;
        case 80:
        case 77:
            if (resultAgeConfirm < 2)
                resultAgeConfirm++;
            break;
        }
        system("CLS");
    } while (true);
}