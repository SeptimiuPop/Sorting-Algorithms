#include "Sorter.h"
#include <cstdlib>
#include <ctime>

/*------------------------------------------------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------------*/



    Sorter::Sorter(): is_sorted(false){
        srand(time(0));
    }



/*---------------------------------------------------- PUBLIC  FUNCTIONS ----------------------------------------------------*/


    /**
     *  Advances the sorting algorithm by one step
     * When run continously it sorts the entire list  
     */ 
    void Sorter::Sort(){
        if (!is_sorted){
            MergeSort(0,list.size()-1);
            is_sorted = true;
        }
        else
            renderer->Draw(-1,-1);
    }


    /**
     *  Links the Renderer to the Sorter and sends a pointer 
     * to the list that is sorted. This is necessary as we 
     * can't break the sorting algorithms into steps easily
     */ 
    void Sorter::SetupRenderer(Renderer* rend){
        renderer = rend;
        renderer->SetArr(&list);
    }

    /**     
     *  Creates a list of random values and sends the highest 
     * to the renderer for later scaling purposes
     *  @param: size = how big we want the list to be 
     */
    void Sorter::InitList(int size){

        list.resize(size);  // resizes the list to the specified length
        list.clear();       // clears old values (if any)

        float maxValue  = 0;
        float randNum;

        for (int i=0; i<size; i++){
            randNum = GetRandomValue();
            list.push_back(randNum);
            
            if (randNum > maxValue)
                maxValue = randNum;
                
        }

        renderer->SetMaxValue(maxValue); 
    }



/*---------------------------------------------------- PRIVATE FUNCTIONS ----------------------------------------------------*/



    void Sorter::BubbleSort(){
        for (int i=0; i<list.size(); i++)
        for (int j=i+1; j<list.size(); j++){

            Pause(i,j);

            if (list[i]<list[j]){
                float aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
        }
    }

    void Sorter::Merge(int left, int mid, int right){
        Pause(right, left);
        auto const subArrayOne = mid - left + 1;
        auto const subArrayTwo = right - mid;
    
        // Create temp arrays
        auto *leftArray = new int[subArrayOne],
            *rightArray = new int[subArrayTwo];
    
        // Copy data to temp arrays leftArray[] and rightArray[]
        for (auto i = 0; i < subArrayOne; i++)
            leftArray[i] = list[left + i];
        for (auto j = 0; j < subArrayTwo; j++)
            rightArray[j] = list[mid + 1 + j];
    
        auto indexOfSubArrayOne = 0, // Initial index of first sub-array
            indexOfSubArrayTwo = 0; // Initial index of second sub-array
        int indexOfMergedArray = left; // Initial index of merged array
    
        // Merge the temp arrays back into array[left..right]
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
            if (leftArray[indexOfSubArrayOne] >= rightArray[indexOfSubArrayTwo]) {
                list[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                list[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        // Copy the remaining elements of
        // left[], if there are any
        while (indexOfSubArrayOne < subArrayOne) {
            list[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }
        // Copy the remaining elements of
        // right[], if there are any
        while (indexOfSubArrayTwo < subArrayTwo) {
            list[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
    }

    void Sorter::MergeSort(int begin, int end){

        if(begin>=end)  return;

        int mid = begin + (end-begin) / 2;
        MergeSort(begin, mid);
        MergeSort(mid+1, end);
        Merge(begin, mid, end);

    }



    void Sorter::Pause(int to, int from){
        while (clock.getElapsedTime().asSeconds() <= UPDATE_TRESHOLD){}
        clock.restart();
        renderer->HandleInputs();
        renderer->Draw(to,from);
    }

    /**
     *  Used in initializing the list
     *  @return: a random value generated 
     */
    float Sorter::GetRandomValue(){
        return rand() % 100;
    }

