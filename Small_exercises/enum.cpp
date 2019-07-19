#include <iostream>

using namespace std;

enum class statemachine {state0, state1, state2};
enum class statemachine2 {state0,state1,state2};
int main()
{
enum statemachine states;
states = state0; 			// the default value of the firs enum value is 0. 
cout<<states<<endl<<states+1<<endl;

enum statemachine2 states_2 = statemachine2::state0;		// you don't need to write class for this. 
return 0;}
