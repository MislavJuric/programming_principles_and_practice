#include "../Headers/std_lib_facilities.h"

/*

12. Implement a version of the game “Hunt the Wumpus.” “Hunt the Wumpus” (or just “Wump”) is a simple (non-graphical) computer
game originally invented by Gregory Yob. The basic premise is that a rather smelly monster lives in a dark cave consisting of
connected rooms. Your job is to slay the wumpus using bow and arrow. In addition to the wumpus, the cave has two hazards:
bottomless pits and giant bats. If you enter a room with a bottomless pit, it’s the end of the game for you. If you enter a
room with a bat, the bat picks you up and drops you into another room. If you enter the room with the wumpus or he enters yours,
he eats you. When you enter a room you will be told if a hazard is nearby:

“I smell the wumpus”: It’s in an adjoining room.

“I feel a breeze”: One of the adjoining rooms is a bottomless pit.

“I hear a bat”: A giant bat is in an adjoining room.

For your convenience, rooms are numbered. Every room is connected by tunnels to three other rooms. When entering a room, you are
told something like “You are in room 12; there are tunnels to rooms 1, 13, and 4; move or shoot?” Possible answers are m13
(“Move to room 13”) and s13–4–3 (“Shoot an arrow through rooms 13, 4, and 3”). The range of an arrow is three rooms. At the
start of the game, you have five arrows. The snag about shooting is that it wakes up the wumpus and he moves to a room adjoining
the one he was in — that could be your room.

Probably the trickiest part of the exercise is to make the cave by selecting which rooms are connected with which other rooms.
You’ll probably want to use a random number generator (e.g., randint() from std_lib_facilities.h) to make different runs of the
program use different caves and to move around the bats and the wumpus. Hint: Be sure to have a way to produce a debug output
of the state of the cave.

*/

// the first step is to generate the cave - how could I do this?

class Room
{
    private:
        int roomNumber;
        vector<int> connectedTo;
        // I don't know if storing this information within a room itself is the best implementation idea
        bool hasBat{false};
        bool hasWumpus{false};
        bool hasPit{false};
    public:
        Room(int roomNumberArg) { roomNumber = roomNumberArg; }
        int getRoomNumber() const { return roomNumber; }
        vector<int> getConnectedTo() const { return connectedTo; }
        bool getHasBat() const { return hasBat; }
        bool getHasWumpus() const { return hasWumpus; }
        bool getHasPit() const { return hasPit; }
        void addConnection(int connection) { connectedTo.push_back(connection); }
        void putWumpus() { hasWumpus = true; }
        void removeWumpus() { hasWumpus = false; }
        void putBat() { hasBat = true; }
        void putPit() { hasPit = true; }
};

vector<int> generatedRoomNumbers;

void Generate_Rooms(vector<Room>& rooms, int numberOfRooms)
{
    for (int i = 0; i < numberOfRooms; i++)
    {
        rooms.push_back(Room{i});
        constexpr int minNumberOfConnections = 1;
        constexpr int maxNumberOfConnections = 6;
        vector<int> alreadyConnectedTo;
        for (int j = 0; j < maxNumberOfConnections; j += randint(1, 3)) // 3 is chosen randomly here
        {
            // elaborate code to make sure that I don't connect a room to itself and that there are no duplicates

            bool canAdd = true;
            int temp = rand() % numberOfRooms;
            for (int k = 0; k < alreadyConnectedTo.size(); k++)
            {
                if (alreadyConnectedTo[k] == temp)
                {
                    canAdd = false;
                    break;
                }
            }
            if ((temp != i) && (canAdd == true))
            {
                rooms[i].addConnection(temp);
                alreadyConnectedTo.push_back(temp);
            }
        }
    }
}

void Output_Rooms(vector<Room>& rooms)
{
    for (int i = 0; i < rooms.size(); i++)
    {
        cout << "You are looking at a room number " << rooms[i].getRoomNumber() << endl;
        cout << "It is connected to room numbers: ";
        for (int j = 0; j < rooms[i].getConnectedTo().size(); j++)
        {
            cout << rooms[i].getConnectedTo()[j] << " ";
        }
        cout << endl;
    }
}

constexpr int numberOfBats = 3;
constexpr int numberOfPits = 1;
// there is always only 1 wumpus

void Place_Bat_Pit_And_Wumpus(vector<Room>& rooms)
{
    for (int i = 0; i < numberOfBats; i++)
    {
        // cout << "Put a bat." << endl;
        int roomNumber = randint(0, (rooms.size() - 1));
        if (rooms[roomNumber].getHasBat() == false)
        {
            rooms[roomNumber].putBat();
        }
    }
    for (int i = 0; i < numberOfPits; i++)
    {
        int roomNumber = randint(0, (rooms.size() - 1));
        if ((rooms[roomNumber].getHasBat() == false) && (rooms[roomNumber].getHasPit() == false))
        {
            rooms[roomNumber].putPit();
        }
    }
    int roomNumber = randint(0, (rooms.size() - 1));
    if ((rooms[roomNumber].getHasBat() == false) && (rooms[roomNumber].getHasPit() == false))
        // we don't want a bat in the same room as the Wumpus
    {
        // cout << "Put wumups." << endl;
        rooms[roomNumber].putWumpus();
    }
}

class Player
{
    private:
        int currentRoom; // the room the player is in
        int numberOfArrows{5};
    public:
        Player() {}
        void setCurrentRoom(int roomNumber) { currentRoom = roomNumber; }
        void shootArrow() { numberOfArrows--; }
        int getCurrentRoom() { return currentRoom; }
        int getNumberOfArrows() { return numberOfArrows; }
};

constexpr int numberOfRooms = 12;

void Place_Player(Player& player, vector<Room>& rooms)
{
    bool done = false;
    while (done != true)
    {
        int roomNumber = rand() % numberOfRooms;
        // cout << roomNumber << endl;
        // cout << "Place player executed" << endl;
        // cout << "rooms[roomNumber].getHasWumpus() = " << rooms[roomNumber].getHasWumpus() << endl;
        // cout << "rooms[roomNumber].getHasBat() = " << rooms[roomNumber].getHasBat() << endl;
        if ((rooms[roomNumber].getHasWumpus() == false) && (rooms[roomNumber].getHasBat() == false) && (rooms[roomNumber].getHasPit() == false))
        {
            // this never executes...
            player.setCurrentRoom(roomNumber);
            done = true;
            break;
        }
    }
}

bool gameOver = false;

void Game_Loop(Player& player, vector<Room>& rooms)
{
    while (gameOver != true)
    {
        Room roomThePlayerIsIn = rooms[player.getCurrentRoom()];
        if (roomThePlayerIsIn.getHasWumpus() == true)
        {
            gameOver = true;
            cout << "Wumpus ate you. Game over." << endl;
            break;
        }
        vector<int> roomsConnectedToThisRoom = roomThePlayerIsIn.getConnectedTo();
        for (int i = 0; i < roomsConnectedToThisRoom.size(); i++)
        {
            if (rooms[roomsConnectedToThisRoom[i]].getHasBat() == true)
            {
                cout << "I hear the bat." << endl;
            }
            if (rooms[roomsConnectedToThisRoom[i]].getHasPit() == true)
            {
                cout << "I feel a breeze." << endl;
            }
            if (rooms[roomsConnectedToThisRoom[i]].getHasWumpus() == true)
            {
                cout << "I smell the wumups." << endl;
            }
        }
        cout << "You are in room " << player.getCurrentRoom() << "; there are tunnels to rooms ";
        for (int i = 0; i < rooms[player.getCurrentRoom()].getConnectedTo().size(); i++)
        {
            cout << rooms[player.getCurrentRoom()].getConnectedTo()[i] << ", "; // could format the output a bit more
        }
        cout << "; move or shoot?" << endl;
        string input;
        cin >> input;
        // input parsing happens below
        if (input[0] == 'm') // we are moving
        {
            stringstream ss{input};
            char first;
            int roomToMoveTo;
            ss >> first;
            ss >> roomToMoveTo;
            // cout << roomToMoveTo << endl;
            bool canMoveToRoom = false;
            for (int i = 0; i < rooms[player.getCurrentRoom()].getConnectedTo().size(); i++)
            {
                if (rooms[player.getCurrentRoom()].getConnectedTo()[i] == roomToMoveTo)
                {
                    canMoveToRoom = true;
                    break;
                }
            }
            if (canMoveToRoom == true)
            {
                player.setCurrentRoom(roomToMoveTo);
            }
            else
            {
                cout << "You can't move to that room." << endl;
            }
            if (rooms[roomToMoveTo].getHasWumpus() == true)
            {
                gameOver = true;
                cout << "Wumups ate you. You lost the game." << endl;
            }
            if (rooms[roomToMoveTo].getHasPit() == true)
            {
                gameOver = true;
                cout << "You fell in the botomless pit. You lost the game." << endl;
            }
            if (rooms[roomToMoveTo].getHasBat() == true)
            {
                int randRoom = randint(0, numberOfRooms);
                if ((rooms[randRoom].getHasBat() == false) && (rooms[randRoom].getHasPit() == false) && (rooms[randRoom].getHasWumpus() == false))
                {
                    player.setCurrentRoom(randRoom);
                }
            }
        }
        else if(input[0] == 's') // we are shooting
        {
             stringstream ss{input};
             char first;
             int firstRoom;
             /*
             char delimiter;
             int secondRoom;
             int thirdRoom;
             */

             // first I'll implement shooting an arrow through just one room
             ss >> first;
             ss >> firstRoom;
             // cout << firstRoom << endl;
             bool canShoot = false;
             for (int i = 0; i < rooms[player.getCurrentRoom()].getConnectedTo().size(); i++)
             {
                 if (rooms[player.getCurrentRoom()].getConnectedTo()[i] == firstRoom)
                 {
                     // cout << "Executed" << endl;
                     canShoot = true;
                     break;
                 }
             }
             if (canShoot == true)
             {
                 if (rooms[firstRoom].getHasWumpus() == true)
                 {
                     gameOver = true;
                     cout << "You killed the wumpus. You won the game!" << endl;
                 }
                 if (rooms[firstRoom].getHasWumpus() == false)
                 {
                     int wumpusNewRoom = randint(0, rooms[player.getCurrentRoom()].getConnectedTo().size());
                     // manually moving wumpus here... I should probably have methods for this

                     // something fishy here...
                     for (int i = 0; i < rooms.size(); i++)
                     {
                         if (rooms[i].getHasWumpus() == true)
                         {
                             rooms[i].removeWumpus();
                         }
                     }
                     rooms[wumpusNewRoom].putWumpus();
                 }
             }

        }
    }
}

int main()
{
    srand(time(0));
    vector<Room> rooms;
    Player player;
    Generate_Rooms(rooms, numberOfRooms);
    // Output_Rooms(rooms);
    Place_Bat_Pit_And_Wumpus(rooms);
    Place_Player(player, rooms);
    Game_Loop(player, rooms);
    return 0;
}
