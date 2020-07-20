#include <iostream>
#include <vector>
using namespace std;
int main(){
    int nbFloors, width, nbRounds, exitFloor, exitPos, nbTotalClones, nbAdditionalElevators, nbElevators;
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    vector<int> map(nbFloors);
    for(int i = 0; i < nbElevators; i++){
        int elevatorFloor, elevatorPos; cin >> elevatorFloor >> elevatorPos; cin.ignore();
        map[elevatorFloor] = elevatorPos;
    }
    while(1){
        int cloneFloor, clonePos;
        string direction;
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();
        if((cloneFloor == exitFloor && direction == "LEFT" && exitPos > clonePos) || (cloneFloor == exitFloor && direction == "RIGHT" && exitPos < clonePos))
            cout << "BLOCK" << endl;
        else if((cloneFloor == exitFloor && direction == "LEFT" && exitPos < clonePos) || (cloneFloor == exitFloor && direction == "RIGHT" && exitPos > clonePos))
            cout << "WAIT" << endl;
        else{
            if(((clonePos < map[cloneFloor]) && (direction == "LEFT")) || ((clonePos > map[cloneFloor]) && (direction == "RIGHT"))) cout << "BLOCK" << endl;
            else cout << "WAIT" << endl;
        }
    }
}
