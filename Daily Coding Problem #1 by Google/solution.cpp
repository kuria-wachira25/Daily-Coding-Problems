/*
 Problem statement
 
 Good morning! Here's your coding interview problem for today.
 
 This problem was recently asked by Google.
 
 Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
 
 For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
 
 Bonus: Can you do this in one pass?
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Big O notation - O(n) Linear
*/

int main()
{
    //Sum of vectors your looking for
    int sumOfNumbers{17};
    
    //List of integers in a vector
    vector<int> V{10, 15, 3, 7};
    
    //First value is initialized to the sum of the numbers your looking for while second value is initialized to zero
    int first=sumOfNumbers,second=0;
    
    //There must be atleast two elements in the vector for comparison purposes
    if(V.size()>2)
    {
        //Sorting is just to increase the probability of the elements that we are looking for to be close to each other
        sort(V.begin(),V.end());
        
        //Indicate as true if both elements are present in the vector
        bool found=false;
        
        //Check if the first value is greater than zero
        while(first>=0)
        {
            //find the iterator of the first number if it exits in the vector
            auto first_it=find(V.begin(),V.end(),first);
            
            //find the iterator to the second number if it exists in the vector
            auto second_it=find(V.begin(),V.end(),second);
            
            //if both the first iterator and second iterator are not equal to the V.end() iterator
            if(first_it!=V.end()&&second_it!=V.end())
            {
                //Mark Both elements are present in the loop and break from loop
                found=true;
                break;
            }
            else
            {
                //Adjust value of first and second number to test again
                first--;
                second++;
            }
        }
        
        //if found both elements in the vector
        if(found)
        {
            //print both numbers
            cout<<"First Number: "<<first<<" Second Number: "<<second<<endl;
        }
        else
        {
            //else print no elements found
            cout<<"There are no elements that add upto: "<<sumOfNumbers<<endl;
        }
    }
    else
    {
        //else print that the vector has to have atleast two elements present to do comparison
        cout<<"There has to be atleast two elements in the vector for comparison"<<endl;
    }
    
    return 0;
}
