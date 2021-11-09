#pragma once
#include "Includes.h"

class Renderer{

/*----------------------------------------------------- FUNCTIONS ----------------------------------------------------*/

    public:

        Renderer();

        void Draw(int, int);
        void HandleInputs();

        sf::RenderWindow* GetWindow();
        void SetArr(std::vector<float>*);
        void SetMaxValue(float);

    private:

        void InitWindow();
        void SetStamps(float);
        float ValToPixels(float);


/*-----------------------------------------------------  FIELDS   ----------------------------------------------------*/

    private:

        sf::RenderWindow window;
        sf::RectangleShape rect_stamp;
        sf::RectangleShape base_stamp;
        sf::Vector2f position;

        std::vector<float>* list;
        float max_list_value;
        float MAX_DISPLAY_SIZE;



};

