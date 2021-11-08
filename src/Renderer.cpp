#include "Renderer.h"


/*------------------------------------------------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------------*/



    Renderer::Renderer(): MAX_DISPLAY_SIZE(350){
        InitWindow();
        rect_stamp.setFillColor(sf::Color::Red);
        base_stamp.setFillColor(sf::Color::Green);
    }



/*---------------------------------------------------- PUBLIC  FUNCTIONS ----------------------------------------------------*/



    void Renderer::Draw(int to, int from){
        window.clear();

        position = sf::Vector2f(150,350);

        float aux, counter=0;
        for (auto val: *list){

            aux = ValToPixels(val);     // convert value in pixels
            SetStamps(aux);

            rect_stamp.setFillColor(sf::Color::Red);
            base_stamp.setFillColor(sf::Color::Green);
            if(counter == to || counter == from){
                base_stamp.setFillColor(sf::Color::White);
                rect_stamp.setFillColor(sf::Color::White);
            }


            window.draw(rect_stamp);
            window.draw(base_stamp);
            
            counter++;
        }

        window.display();
    }


    void Renderer::HandleInputs(){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type = sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::KeyReleased)
                if(event.key.code == sf::Keyboard::Escape)
                    window.close(); 
        }
    }    

    sf::RenderWindow* Renderer::GetWindow(){ return &window;}

    void Renderer::SetArr(std::vector<float>* array){ list = array; }

    void Renderer::SetMaxValue(float maxVal){ max_list_value = maxVal; }



/*---------------------------------------------------- PRIVATE FUNCTIONS ----------------------------------------------------*/



    void Renderer::InitWindow(){
        window.create(sf::VideoMode(1500, 1000), "Sorting Algorithms", sf::Style::Default);
    }


    void Renderer::SetStamps(float aux){
        rect_stamp.setSize(sf::Vector2f(8, aux));
        rect_stamp.setPosition(position);

        base_stamp.setSize(sf::Vector2f(8, MAX_DISPLAY_SIZE-aux));
        base_stamp.setPosition(sf::Vector2f(position.x, aux+position.y));
        
        position.x += 10;           // stamp 10 px to the left from last time
    }


    /**
     *  Works to translate the values from the vector to a specificly 
     * set range of pixel sizes that fit the screen 
     *  @param: value = the value of one element from the list
     */
    float Renderer::ValToPixels(float value){
        return (value * MAX_DISPLAY_SIZE) / max_list_value;
    }





