#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

template<class iter,class T>
    iter Median(iter begin , iter end, T size){
        double n = distance(begin,end);
        double an =n/size;
        iter pointer;

        if(size == 1 || fmod(an,1) !=0) {
            return end;
        }
        else{     
                iter sortedbyElements;
                iter end_iter;
                pointer = begin;
                iter med = begin;

            while(end_iter!=end){

                sortedbyElements = begin;
                end_iter = sortedbyElements+size;
                sort(sortedbyElements,end_iter);
                if(size%2 == 0){//Even array
                    int in1=(size/2)-1;
                    
                    for(int i = 0; i < in1 ; i++){
                        med++;
                    }
                    iter temp = med+1;
                    double avg=(*med+*temp)/2; 
                    *pointer=avg;
                    pointer++;

                }
                else{//Odd array
    
                    int index = size/2; // 1
                    for(int i = 0; i < index ; i++){
                        med++;
                    }
                    *pointer = *med;
                    pointer++;
                }

                begin = begin+size;
                med = begin;

            }    
        }
        return pointer;

    }



    ////////////////////////////////////////////////////////////////////////////////////

    template<class iter>
    iter Transpose(iter begin , iter end){
        bool odd = false;
        bool even = false;
        iter tmp=begin;
        while(tmp != end){ 
            if(distance(begin,end)%2 == 0){

                std::swap(*tmp,*(tmp+1));
                tmp+=2;
                even = true;
            }
            else{
                if(*(tmp) != *(end-1)){
                swap(*tmp,*(tmp+1));
                tmp+=2;
                odd = true;
                }
                else {
                    break;
                }
                
            }
        }
        if(even){
            return tmp;
        }else if(odd){
            return end-1;
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////
    template<class iter, class Op>
    iter Transformations(iter begin , iter end , Op init){
        iter ans = begin;
        if(distance(begin,end)%2 != 0){
            return end;
        }
        else{
            iter tmp=begin;
            iter result=begin;
            while (tmp!=end) {
                *result=init(*tmp,*(tmp+1));  
                tmp+=2;
                result++;
            }
            return result;
        }
    }











