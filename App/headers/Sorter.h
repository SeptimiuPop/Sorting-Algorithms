#pragma once
#include "Renderer.h"
#include <vector>


class Sorter{

/*----------------------------------------------------- FUNCTIONS ----------------------------------------------------*/

    public:

        Sorter();

        void Sort();
        void SetupRenderer(Renderer*);
        
        void InitList(int);

    private:

        void BubbleSort();
        
        void Merge(int,int,int);
        void MergeSort(int, int);

        void Pause(int, int);
        float GetRandomValue();

/*-----------------------------------------------------  FIELDS   ----------------------------------------------------*/

    private:

        Renderer* renderer;
        std::vector<float> list;
        bool is_sorted;

        sf::Clock clock;
        float UPDATE_TRESHOLD = 1/5.f;
};