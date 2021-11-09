#include "App.h"


/*------------------------------------------------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------------*/



    App::App (): terminate_app(false){
        sorter.SetupRenderer(&renderer);
        CreateList();
    }



/*----------------------------------------------------- PUBLIC  FUNCTIONS ----------------------------------------------------*/



    void App::Run(){
        while (!terminate_app){
            sorter.Sort();
        }
    }

    void App::CreateList(){
        sorter.InitList(120);
    }



/*----------------------------------------------------- PRIVATE FUNCTIONS ----------------------------------------------------*/



    
