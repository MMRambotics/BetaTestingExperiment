/*
 * @author: Andrew Horsman
 * @description: The StateMachine class allows a program to register and 
 * manipulate states in an easy, clean fashion. 
 */

// Includes:
#include "Headers/WPILibrary.h"

// Namespaces:
using namespace std;

// StateMachine Map type definition.
// stateMap<stateKey, stateHistory[]>
typedef map<int, vector<int> > holder;
typedef map<int, vector<int> >::iterator holderIterator;

/*
 * StateMachine Class
 * Stores states which can be read, compared, and changed.
 */
class StateMachine {
	
	public:
		StateMachine()  {} // Empty constructor.
		~StateMachine() {} // Empty destructor.
		
		/*
		 * Register a state key with it's initial state.
		 * stateKey must be unique.
		 */
		bool RegisterState(int stateKey, int currentState) {
			if (CheckIfMapKeyExists(this->stateMap, stateKey)) 
				return false;
			
			this->stateMap[stateKey] = this->DefaultState(currentState);
			return true;
		}
	
		/*
		 * Changes the current state via a state key.
		 * Returns false is the state has not been registered via a key.
		 */
		bool ChangeState(int stateKey, int newState) {
			if (!CheckIfMapKeyExists(this->stateMap, stateKey))
				return false;
			
			if (this->GetCurrentState(stateKey) != newState) 
				this->stateMap[stateKey].push_back(newState);
			
			return true;
		}
		
		/*
		 * Gets the current state via a state key.
		 */
		int GetCurrentState(int stateKey) {
			if (!CheckIfMapKeyExists(this->stateMap, stateKey))
				return -1;
			
			return this->stateMap[stateKey].back();
		}
		
		/*
		 * Checks if the current state via a key is the same as the compared 
		 * key.
		 */
		bool CompareState(int stateKey, int compareState) {
			if (!CheckIfMapKeyExists(this->stateMap, stateKey))
				return false;
			
			return (GetCurrentState(stateKey) == compareState);
		}
		
		/*
		 * Get the original value of the state (from registration).
		 */
		int GetOrigin(int stateKey) {
			if (!CheckIfMapKeyExists(this->stateMap, stateKey))
				return false;
			
			return this->stateMap[stateKey].front();
		}
		
		/*
		 * Resets a state via it's key to it's original state upon registration.
		 */
		bool ResetState(int stateKey) {
			if (!CheckIfMapKeyExists(this->stateMap, stateKey))
				return false;
			
			return this->ChangeState(stateKey, this->GetOrigin(stateKey));
		}
		
	private:
		holder stateMap;
		
		/*
		 * Check if an int key exists in a map<int, int> Map.
		 */
		bool CheckIfMapKeyExists(holder& checkMap, int key) {
			holderIterator isFound = checkMap.find(key);
			return (isFound != checkMap.end());
		}
		
		/*
		 * Creates a new stack for holding state values (current value and value
		 * history).
		 */
		vector<int> DefaultState(int initialState) {
			vector<int> stateHistory;
			stateHistory.push_back(initialState);
			return stateHistory;
		}
		
};
