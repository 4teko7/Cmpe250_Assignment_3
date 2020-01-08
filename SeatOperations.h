#ifndef CMPE250_ASSIGNMENT3_SEATOPERATIONS_H
#define CMPE250_ASSIGNMENT3_SEATOPERATIONS_H
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Person{
    int type=0;
    string ticketInfo = "";
    string originalTicketInfo = "";
    int ticketNumber=0;
    int currentSeat = 0;
    int type3LastOperation=0;

};

class SeatOperations{

private:
    Person p;
    vector<Person> lines{2000,p};
    int N, M;

public:
    SeatOperations(int N, int M);
    void addNewPerson(int personType, const string& ticketInfo);
    void printAllSeats(ofstream& outFile);
    int findIndex(const Person &sittingPerson,const int &N,const int &M);
    int findIndex2(Person &sittingPerson,const int &N,const int &M);
    void addPersonToVector(Person &person,int &index);

    // YOU CAN ADD YOUR HELPER FUNCTIONS

};

#endif //CMPE250_ASSIGNMENT3_SEATOPERATIONS_H
