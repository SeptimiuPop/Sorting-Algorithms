#pragma once
#include "Includes.h"
#include "Renderer.h"
#include "Sorter.h"

class App{

/*----------------------------------------------------- FUNCTIONS ----------------------------------------------------*/

    public: 

        App();

        void Run();
        void CreateList();


/*-----------------------------------------------------  FIELDS   ----------------------------------------------------*/

    private:

        Renderer renderer;
        Sorter sorter;

        bool terminate_app;

};