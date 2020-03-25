#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include "alg.h"

int main(){

    int arr1[8] = {5,7,1,3,40,10,30,20};//->1,3, 2,8, 6,10 ,3,5 -> 
    double arr[8] = {3.0,1.0,2.0,8.0,6.0,10.0,5.0,3.0};//->1,3, 2,8, 6,10 ,3,5 -> 
    int arrTrans[7] = {2,1,4,3,6,5,121231}; 
    // 1,2,3,3,5,6,8,10
    int arr2[9] = {4,1,3,8,5,9,0,-6,2};

    auto p = Median(std::begin(arr1),std::end(arr1),4);

    for(auto i : arr1){
        cout << i << ", ";

    }
    
    
    /*Transpose(begin(arrTrans),end(arrTrans));
        cout << "{ ";
    for(int i : arrTrans){
        cout << i << ",";
    
    }
        cout << " }";
*/
    // int ia[]={1,2,3,10,8,6};//->3,13,14
    // auto r = Transpose(std::begin(ia),std::end(ia));

//     for(auto i : ia){
//         cout << i << ",";
//     }


  




    // int * p1=Transformations(std::begin(ia),std::end(ia),[](const int x,const int y){return x+y;});
    // for(int i:ia){
    //     cout<<i<<", ";
    // }

    return 0;
}