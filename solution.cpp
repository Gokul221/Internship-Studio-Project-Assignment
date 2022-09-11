#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <array>
using namespace std;

int p=0;

class assets {
    char roomno[5], host[10], start[5], end[5], from[10], to[10], chair[8][4][10];

    public:
        void bookRoom();
        void bookingInfo();
        void empty();
        void show();
        void avail();
        void position(int i);
};

assets room[10];

void vline(char ch) {
    for(int i=80; i>0; i--) {
        cout << ch;
    }
}

void assets::bookRoom() {
    cout << "Enter room number: ";
    cin >> room[p].roomno;

    cout << "\nEnter host name: ";
    cin >> room[p].host;

    cout << "\nStart time: ";
    cin >> room[p].start;

    cout << "\nSession ends at: ";
    cin >> room[p].end;

    cout << "\nFrom: ";
    cin >> room[p].from;

    cout << "\nTo: ";
    cin >> room[p].to;

    room[p].empty();
    p++;
}

void assets::bookingInfo() {
    int chair;
    char number[5];
    
    top:
    cout << "\nRoom number: ";
    cin >> number;

    int n=0;
    for(n=0; n<=p; n++) {
        if(strcmp(room[n].roomno, number) == 0)
        break;
    }

    while (n<=p) {
        cout << "\nChair Number: ";
        cin >> chair;

        if (chair>32) {
            cout << "\nThere are only 32 chairs available in this room.";
        }
        else {
            if(strcmp(room[n].chair[chair/4][(chair%4) - 1], "Empty") == 0) {
                cout << "\nEnter passenger's name: ";
                cin >> room[n].chair[chair/4][(chair%4) - 1];
                break;
            }

            else
                cout << "The chair number is already reserved.\n";
        }
    }

    if (n>p) {
        cout << "Enter correct room number!\n";
        goto top;
    }
}


void assets::empty() {
    for(int i=0; i<8; i++) {
        for(int j=0; j<4; j++) {
            strcpy(room[p].chair[i][j], "Empty");
        }
    }
}


void assets::show() {
    int n;
    char number[5];
    cout << "\nEnter registered room number: ";
    cin >> number;
    for(n=0; n<=p; n++) {
        if(strcmp(room[n].roomno, number) == 0)
        break;
    }

    while(n<=p) {
        vline('*');
        cout << "\nRoom number: " << room[n].roomno << "\nHost: " << room[n].host 
        << "\nStart time: " << room[n].start << "\nEnd time: " << room[n].end
        << "\nFrom: " << room[n].from << "\nTo: " << room[n].to << "\n";
        
        //vline('*');
        room[0].position(n);
        int a=1;
        for(int i=0; i<8; i++) {
            for(int j=0; j<4; j++) {
                a++;
                if(strcmp(room[n].chair[i][j], "Empty")!=0) {
                    cout << "\nThe chair number " << (a-1) << " is reserved for " << room[n].chair[i][j] << ".";
                }
            }
        }
        break;
    }

    if(n>p) {
        cout << "\nEnter correct room number!";
    }
}


void assets::position(int l) {
    int s=0; p=0;
    for(int i=0; i<8; i++) {
        cout << "\n";
        for(int j=0; j<4; j++) {
            s++;
            if(strcmp(room[l].chair[i][j], "Empty") == 0) {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << room[l].chair[i][j];
                p++;
            }
            else {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << room[l].chair[i][j];
            }
        }
        
    }

    cout << "\n\nThere are " << p << " chairs empty in room number " << room[l].roomno;
}


void assets::avail() {
    for(int n=0; n<p; n++) {
        cout << "\n";
        vline('*');
        cout << "\nRoom number: " << room[n].roomno << "\nHost: " << room[n].host
        << "\nStart time: " << room[n].start << "\nEnd time: "
        << room[n].end << "\nFrom: " << room[n].from << "\nTo: "
        << room[n].to << "\n";
        vline('*');
    }
}


int main() {
    system("cls");
    int w;
    while(1) {
        cout << "\n\n\n";
        cout << "1. Book a room\n" << "2. Book chair(s)\n"
        << "3. Show booking info\n" << "4. Show rooms available\n"
        << "5. Exit"
        << "\nEnter your choice: ";
        cin >> w;
        switch (w)
        {
        case 1: room[p].bookRoom();
                break;

        case 2: room[p].bookingInfo();
                break;

        case 3: room[0].show();
                break;

        case 4: room[0].avail();
                break;

        case 5: exit(0);
        }
    }

    return 0;
}