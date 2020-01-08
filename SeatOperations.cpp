/*
Student Name: Bilal Tekin
Student Number:2017400264
Project Number: 3
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include "SeatOperations.h"
using namespace std;

SeatOperations::SeatOperations(int N, int M){
    // IMPLEMENT ME!
    this->N = N;
    this->M = M;

}

void SeatOperations::addNewPerson(int personType, const string& ticketInfo){
    // IMPLEMENT ME!
    Person person;
    person.type = personType;
    person.ticketNumber = ticketInfo.at(1) - 48;

    string temp = ticketInfo;
    temp[0] = '0';
    person.ticketNumber = std::stoi(temp);

    person.currentSeat = 0;
    person.ticketInfo = person.originalTicketInfo = ticketInfo;

    int index = findIndex(person,N,M);
    addPersonToVector(person,index);

}

int SeatOperations::findIndex(const Person &sittingPerson,const int &N,const int &M){
    int index;
    if(sittingPerson.ticketInfo.at(0) == 'B'){
        int modulo = sittingPerson.ticketNumber % M;
        if(modulo == 0){
            index = N+M-1;
        }else{
            index = N + modulo - 1;
        }
    }else{
        int modulo = sittingPerson.ticketNumber % N;
        if(modulo == 0){
            index = N-1;
        }else{
            index = modulo - 1;
        }
    }
    return index;
}
int SeatOperations::findIndex2(Person &sittingPerson,const int &N,const int &M){
    if(sittingPerson.currentSeat < N+M){
        return (sittingPerson.currentSeat);
    }
    else {
    return sittingPerson.currentSeat % (N+M);
    }
}
void SeatOperations::addPersonToVector(Person &person,int &index){
    if(lines[index].ticketInfo == ""){
        lines[index] = person;
        lines[index].currentSeat = index;
    }
    else{
        Person sittingPerson = lines[index];
        lines[index] = person;
        lines[index].currentSeat = index;

        if(sittingPerson.type == 1){
            if(sittingPerson.ticketInfo.at(0) == 'A'){
                sittingPerson.ticketInfo[0]= 'B';
            }else{
                sittingPerson.ticketInfo[0]= 'A';
            }
            int index = findIndex(sittingPerson,N,M);
            addPersonToVector(sittingPerson,index);
        }


        else if(sittingPerson.type == 2){
            sittingPerson.currentSeat++;

            int index = findIndex2(sittingPerson,N,M);
            addPersonToVector(sittingPerson,index);
        }


        else{
            sittingPerson.currentSeat += 2 * sittingPerson.type3LastOperation + 1;
            sittingPerson.type3LastOperation++;
            int index = findIndex2(sittingPerson,N,M);
            addPersonToVector(sittingPerson,index);
        }

    }
}


void SeatOperations::printAllSeats(ofstream& outFile){
    // IMPLEMENT ME!
    for(int i = 0; i < N+M; i++){
        outFile << lines[i].type;
        if(lines[i].originalTicketInfo != ""){
            outFile << " ";
            outFile << lines[i].originalTicketInfo<<endl;
        }else{
            outFile<<endl;
        }
    }
}

// YOU CAN ADD YOUR HELPER FUNCTIONS