//
//  main.cpp
//  CS-776_Assignment_2
//
//  Created by Scott S Forer on 9/8/16.
//  Copyright © 2016 Scott S Forer. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


class individual
{
public:
    int combo[100];
    double fitness;
};

double eval(int *pj);
int bit_length = 100;
int target[100];


//-----------------------------------------------------------
//builds two solutions
void build_pop(individual& A, individual& B)
{
    //population.push_back(I);
    //population.at(p).combo.resize(100);
    for (int num=0; num<bit_length; num++)
    {
        A.combo[num] = rand() % 2;
        B.combo[num] = rand() % 2;
    }
}


//-----------------------------------------------------------
//builds target
void create_target()
{
    for (int num=0; num<bit_length; num++)
    {
        target[num] = rand() % 2;
    }
    //cout << "target" << endl;
    //for (int num=0; num<bit_length; num++)
    //{
    //cout << target[num] << "\t";
    //}
    //cout << endl;
    //cout << endl;
}


//-----------------------------------------------------------
//compares the individuals bit by bit to the target
void easy_eval(individual& A, individual& B)
{
    A.fitness = 0;
    B.fitness = 0;
    int A_fit;
    int B_fit;
    for (int i=0; i<bit_length; i++)
    {
        if (A.combo[i] == target[i])
        {
            A_fit = 1;
        }
        else
        {
            A_fit = 0;
        }
        A.fitness = A.fitness + A_fit;
        
        
        
        if (B.combo[i] == target[i])
        {
            B_fit = 1;
        }
        else
        {
            B_fit = 0;
        }
        B.fitness = B.fitness + B_fit;
    }
}

//-----------------------------------------------------------
//evaluates the fitness for
int hard_eval(int *pj)
{
    int sum=0;
    for(int i=0; i<25; i++)
    {
        if(pj[i]==0)
        {
            sum = sum + 1;
        }
    }
    for(int i=25; i<50; i++)
    {
        if(pj[i]==1)
        {
            sum = sum + 1;
        }
    }
    for(int i=50; i<75; i++)
    {
        if(pj[i]==0)
        {
            sum = sum + 1;
        }
    }
    for(int i=75; i<100; i++)
    {
        if(pj[i]==1)
        {
            sum = sum +1;
        }
    }
    
    if(sum<100)
    {
        if(sum<=75)
        {
            if(sum<50)
            {
                if(sum<=25)
                {
                    return sum;
                }
                else
                {
                    return 25;
                }
            }
            else
            {
                return sum;
            }
            return sum;
        }
        else
        {
            return 75;
        }
    }
    else
    {
        return 100;
    }
}

//-----------------------------------------------------------
//evaluates the fitness for each individual
void evaluate(individual& A, individual& B)
{
    //easy_eval(A, B);
    //hard_eval(A);
    //hard_eval(B);
}


//-----------------------------------------------------------
//gets the fitness for each individual
void get_fitness(individual& A, individual& B)
{
    //evaluate(A, B);
    A.fitness = 0;
    A.fitness = eval(A.combo);
    B.fitness = 0;
    B.fitness = eval(B.combo);
    
    //A.fitness = hard_eval(A.combo);
    //B.fitness = hard_eval(B.combo);
}


//-----------------------------------------------------------
//randomly selects two individuals and decides which one will die based on their fitness
individual binary_select(individual& A, individual& B)
{
    individual winner;
    if (A.fitness >= B.fitness)
    {
        winner = A;
    }
    else
    {
        winner = B;
    }
    return winner;
}


//-----------------------------------------------------------
//mutates the copies of the winning individuals
individual mutation(individual A)
{
    int rr = (int)rand() % bit_length;
    //int rr = 1;
    for (int p=0; p<rr; p++)
    {
        int rrr = (int)rand() % bit_length;
        for (int i=0; i< bit_length; i++)
        {
            if (i == rrr )
            {
                if (A.combo[i] == 0)
                {
                    A.combo[i] = 1;
                }
                else
                {
                    A.combo[i] = 0;
                }
            }
        }
    }
    return A;
}


//-----------------------------------------------------------
//runs the natural selection process
void natural_selection(individual& A, individual& B)
{
    A = binary_select(A, B);
    B = mutation(A);
}


//-----------------------------------------------------------
//runs program
void run_hill_climber(individual& A, individual& B)
{
    build_pop(A, B);
    create_target();
    for (int loop=0; loop<100; loop++)
    {
        cout << "loop" << "\t" << loop << endl;
        //cout << "in" << endl;
        //cout << "A " << endl;
        //for (int j=0; j<bit_length; j++)
        //{
        //cout << A.combo[j] << "\t";
        //}
        //cout << endl;
        //cout << "B " << endl;
        //for (int j=0; j<bit_length; j++)
        //{
        //cout << B.combo[j] << "\t";
        //}
        //cout << endl;
        
        get_fitness(A, B);
        cout << "A fitness" << "\t" << A.fitness << endl;
        cout << "B fitness" << "\t" << B.fitness << endl;
        natural_selection(A, B);
        
        //cout << "out" << endl;
        //cout << "A " << endl;
        //for (int j=0; j<bit_length; j++)
        //{
        //cout << A.combo[j] << "\t";
        //}
        //cout << endl;
        //cout << "B " << endl;
        //for (int j=0; j<bit_length; j++)
        //{
        //cout << B.combo[j] << "\t";
        //}
        //cout << endl;
        cout << endl;
        //if (loop == 999)
        //{
        //for (int l=0; l<100; l++)
        //{
        //cout << A.combo[l] << "\t";
        //}
        //cout << endl;
        //}
    }
}


void test()
{
    int vec[100];
    
    int i;
    
    for(i = 0; i < 100; i++){
        vec[i] = 0;
    }
    double fitness;
    //fitness = eval(vec);
    cout << "fitness = " << fitness << endl;
}


//-----------------------------------------------------------
//-----------------------------------------------------------
int main()
{
    individual A;
    individual B;
    //test();
    srand(time(NULL));
    run_hill_climber(A, B);
    
    return 0;
}
