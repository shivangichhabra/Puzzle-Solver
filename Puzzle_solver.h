/**
 * Generic puzzle solver which is implemented using breadth first search.
 * 
 *
 */
#ifndef _PUZZLE_SOLVER_H_
#define _PUZZLE_SOLVER_H_
#include<iostream>
#include <queue>  
#include <set>  
#include "Puzzle.h"
using namespace std;
template<typename T>
class S{
    public:
    T data;
    S *parent;
	/**
	*	Parametrised Constuctor
	*	@param - in - refers to the data of the node
	*	@param - father - refers to the parent of the node.
	*/
    S(T &in,S* father){
        data=new T(&in);
        parent=father;
    }
	/**
	*	Parametrised Constuctor
	*	@param - in - refers to the data of the node
	*/
    S(T &in){
        data=new T(&in);
        parent=NULL;
    }
};

template<typename T>
class Puzzle_solver{
    private:
    Jump_peg *game;
    
    public:
        Puzzle_solver(Jump_peg*);
        void solve();
};
/**
*	Parametrised Constructor
*/
template<typename T>
Puzzle_solver<T>::Puzzle_solver(Jump_peg *myGame){
    game=myGame;
}
/**
*	This method implements the breadth first search algorithm.
*/
template<typename T>
void Puzzle_solver<T>::solve(){
        queue<S<T> *> q;
        T first(game->init());
        S<T> *temp=new S<T>(first);
        q.push(temp);
        S<T> *toAdd;
        while(!q.empty()){
            temp= q.front();
            q.pop();
            //game->print(temp->data);
            if(game->solved(temp->data)){//if game solved
                break;
            }
            vector<T> nextSteps=game->getNext(temp->data);
            typename vector<T>::iterator it;
            for(it=nextSteps.begin();it != nextSteps.end();++it){
                        toAdd=new S<T>(*it,temp);
                        q.push(toAdd);
            }
        }
        if(game->solved(temp->data)){
            vector<T> answer;
            do{
                answer.insert(answer.begin(),temp->data);
                temp=temp->parent;
            }while(temp!=NULL);
            for(int i=0;i<answer.size();i++){
                game->print(answer[i]);
            }
            //cout<<"Total steps needed :"<<answer.size()<<endl;
        }   
        else{
            cout<<"No Solution Exists!!!";
        }
    }
#endif
