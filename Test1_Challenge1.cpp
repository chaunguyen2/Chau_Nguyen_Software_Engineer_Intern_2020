#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    
    vector<int> map(nbFloors); // create a vector to strore the elevator position of each floor 

    for (int i = 0; i < nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();   
        map[elevatorFloor] = elevatorPos; // store elevator position of each floor which has elevator.
    }

    // game loop
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        // if leading clone is on exit floor and clones travels toward LEFT direction and exit position is on the RIGHT of clone positon
        // or leading clone is on exit floor and clones travels toward RIGHT direction and exit position is on the LEFT of clone position 
        if((cloneFloor == exitFloor && direction == "LEFT" && exitPos > clonePos) || (cloneFloor == exitFloor && direction == "RIGHT" && exitPos < clonePos))
        {
            cout << "BLOCK" << endl; // use leading clone to block current way and other clone replications change direction 
        }

        //else if leading clone is on exit floor and clones are in LEFT direction and exit position is on the LEFT of clone position
        // of leading clone is one exit floor and clones are in RIGHT direction and exist position is on the RIGHT of clone position
        else if((cloneFloor == exitFloor && direction == "LEFT" && exitPos < clonePos) || (cloneFloor == exitFloor && direction == "RIGHT" && exitPos > clonePos))
            cout << "WAIT" << endl; // do nothing

        else // not the exit floor 
        {
            // position of leading clone is on the LEFT of elevator position and clones are in LEFT direction 
            // or position of leading clone is on the right of elevator position and clones are in RIGHT direction
            if(((clonePos < map[cloneFloor]) && (direction == "LEFT")) || ((clonePos > map[cloneFloor]) && (direction == "RIGHT")))
                cout << "BLOCK" << endl; // use leading clone to block the current way and make clone replications change direction
            else
                cout << "WAIT" << endl;       // do nothing
        }
    }
}