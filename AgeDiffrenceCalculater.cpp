#include <iostream>
#include <ctime>
using namespace std;

int checkYear (int,int);
int checkMon (int);
int checkDay (int,int);
int checkHour (int);
int checkMin (int);
int checkSec (int);
int main(){

//the next part is to get the time locally (automatically)
time_t time_ptr; 
time_ptr = time(NULL);
// Get the localtime 
tm* tm_local = localtime(&time_ptr); 

int date_y = tm_local->tm_year + 1900 , date_m = tm_local->tm_mon + 1 , date_d = tm_local->tm_mday ,date_h = tm_local->tm_hour , date_mi = tm_local->tm_min , date_s = tm_local->tm_sec;

// y= year , m = month , d = day , h = hour , m = minute , s = second.
int firstDate_y = 2003 , firstDate_m = 11 , firstDate_d = 4 , firstDate_h = 9 , firstDate_mi = 30 , firstDate_s = 54;
int secondDate_y = 2003 , secondDate_m = 2 , secondDate_d = 16 , secondDate_h = 6 , secondDate_mi = 22 , secondDate_s = 58;
int firstDateAge_y , firstDateAge_d , firstDateAge_m , firstDateAge_h , firstDateAge_mi , firstDateAge_s;
int secondDateAge_m , secondDateAge_d , secondDateAge_y , secondDateAge_h , secondDateAge_mi , secondDateAge_s;
int ageDiff_y , ageDiff_m , ageDiff_d , ageDiff_h , ageDiff_mi , ageDiff_s;
int details;

cout<<"do you want to calculaate hours, minutes and seconds?"<<endl<<"Enter 0 for false or 1 true"<<endl;
cin>>details;
while (details != 1 && details != 0){
    cout<<"please enter eaither 1 or 0"<<endl;
    cin>>details;
}

if (details == 1){
    cout<<"enter first birthdate (years -> months -> days -> hours -> minutes -> seconds )"<< endl;
    cin>>firstDate_y>>firstDate_m>>firstDate_d>>firstDate_h>>firstDate_mi>>firstDate_s;
    firstDate_y = checkYear(firstDate_y, date_y);
    firstDate_m = checkMon (firstDate_m);
    firstDate_d = checkDay (firstDate_d, date_y);
    firstDate_h = checkHour(firstDate_h);
    firstDate_mi = checkMin (firstDate_mi);
    firstDate_s = checkSec (firstDate_s);
    cout<<"enter second birthdate (Same)"<< endl;
    cin>>secondDate_y>>secondDate_m>>secondDate_d>>secondDate_h>>secondDate_mi>>secondDate_s;
    secondDate_y = checkYear(secondDate_y, date_y);
    secondDate_m = checkMon (secondDate_m);
    secondDate_d = checkDay (secondDate_d, date_y);
    secondDate_h = checkHour(secondDate_h);
    secondDate_mi = checkMin (secondDate_mi);
    secondDate_s = checkSec (secondDate_s);
    }
else{
    cout<<"enter first birthdate (years -> months -> days)"<< endl;
    cin>>firstDate_y>>firstDate_m>>firstDate_d;
    firstDate_y = checkYear(firstDate_y, date_y);
    firstDate_m = checkMon (firstDate_m);
    firstDate_d = checkDay (firstDate_d, date_y);
    cout<<"enter second birthdate (Same)"<< endl;
    cin>>secondDate_y>>secondDate_m>>secondDate_d;
    secondDate_y = checkYear(secondDate_y, date_y);
    secondDate_m = checkMon (secondDate_m);
    secondDate_d = checkDay (secondDate_d, date_y);
    }

if (details == 1){
    firstDateAge_d = date_d - firstDate_d;
    firstDateAge_m = date_m - firstDate_m;
    firstDateAge_y = date_y - firstDate_y;
    firstDateAge_h = date_h - firstDate_h;
    firstDateAge_mi = date_mi - firstDate_mi;
    firstDateAge_s = date_s - firstDate_s;
    secondDateAge_d = date_d - secondDate_d;
    secondDateAge_m = date_m - secondDate_m;
    secondDateAge_y = date_y - secondDate_y;
    secondDateAge_h = date_h - secondDate_h;
    secondDateAge_mi = date_mi - secondDate_mi;
    secondDateAge_s = date_s - secondDate_s;
}
else{
    firstDateAge_y = date_y - firstDate_y;
    firstDateAge_m = date_m - firstDate_m;
    firstDateAge_d = date_d - firstDate_d;
    secondDateAge_d = date_d - secondDate_d;
    secondDateAge_m = date_m - secondDate_m;
    secondDateAge_y = date_y - secondDate_y;
}

if (firstDateAge_s < 0 ){
    firstDateAge_mi--;
    firstDateAge_s+= 60;
}
if (firstDateAge_mi < 0 ){
    firstDateAge_h--;
    firstDateAge_mi+= 60;
}
if (firstDateAge_h < 0 ){
    firstDateAge_d--;
    firstDateAge_h+= 24;
}
if (firstDateAge_d < 0 ){
    firstDateAge_m--;
    firstDateAge_d+= 30;
}
if (firstDateAge_m < 0){
    firstDateAge_y--;
    firstDateAge_m+=12;
}
if (secondDateAge_s < 0 ){
    secondDateAge_mi--;
    secondDateAge_s+= 60;
}
if (secondDateAge_mi < 0 ){
    secondDateAge_h--;
    secondDateAge_mi+= 60;
}
if (secondDateAge_h < 0 ){
    secondDateAge_d--;
    secondDateAge_h+= 24;
}
if (secondDateAge_d < 0 ){
    secondDateAge_m--;
    secondDateAge_d+= 30;
}
if (secondDateAge_m < 0){
    secondDateAge_y--;
    secondDateAge_m+=12;
}

ageDiff_y = secondDateAge_y - firstDateAge_y;
ageDiff_m = secondDateAge_m - firstDateAge_m;
ageDiff_d = secondDateAge_d - firstDateAge_d;
ageDiff_h = secondDateAge_h - firstDateAge_h;
ageDiff_mi = secondDateAge_mi - firstDateAge_mi;
ageDiff_s = secondDateAge_s - firstDateAge_s;

if (ageDiff_s < 0 ){
    ageDiff_s*=-1;
}
if (ageDiff_m < 0){
    ageDiff_m *= -1;
}
if (ageDiff_h < 0){
    ageDiff_h *= -1;
}
if (ageDiff_d < 0 ){
    ageDiff_d*=-1;
}
if (ageDiff_mi < 0){
    ageDiff_mi *= -1;
}
if (ageDiff_y <0){
    ageDiff_y*= -1;
}

if(details == 1){
    cout <<"first age: "<<endl<<"Years: "<<firstDateAge_y<<endl<<"months: "<<firstDateAge_m<<endl<<"days: "<<firstDateAge_d<<endl<<"hours: "<<firstDateAge_h <<endl<<"minutes: "<<firstDateAge_mi<<endl<<"seconds: "<<firstDateAge_s<<endl;
    cout <<"second age: "<<endl<<"Years: "<<secondDateAge_y<<endl<<"months: "<<secondDateAge_m<<endl<<"days: "<<secondDateAge_d<<endl<<"hours: "<<secondDateAge_h <<endl<<"minutes: "<<secondDateAge_mi <<endl<<"seconds: "<<secondDateAge_s<<endl;
    cout <<"the difference between them is "<< endl<<"by years :"<<ageDiff_y<<endl<<"by months : "<<ageDiff_m<<endl<<"by days: "<<ageDiff_d<<endl<<"by hours: "<<ageDiff_h <<endl<<"by minutes: "<<ageDiff_mi<<endl<<"by seconds: "<<ageDiff_s<<endl;
}
else{
    cout <<"first age: "<<endl<<"Years: "<<firstDateAge_y<<endl<<"months: "<<firstDateAge_m<<endl<<"days: "<<firstDateAge_d<<endl;
    cout <<"second age: "<<endl<<"Years: "<<secondDateAge_y<<endl<<"months: "<<secondDateAge_m<<endl<<"days: "<<secondDateAge_d<<endl;
    cout <<"the difference between them is "<< endl<<"by years: "<<ageDiff_y<<endl<<"by months: "<<ageDiff_m<<endl<<"by days: "<<ageDiff_d<<endl;
}
    return 0;
}

int checkYear(int x , int date){
    while (x < 0 || x > date){
        cout<<"please enter a valid year (0 -> "<<date<<")"<<endl;
        cin>>x;
    }
    return x;
}
int checkMon (int x){
    while (x < 0 || x > 12){
        cout<<"please enter a valid month (0 -> 12)"<<endl;
        cin>>x;
    }
    return x;
}
int checkDay (int x , int date){
    if (date %4 == 0){
        while (x < 0 || x > 29){
            cout<<"please enter a valid day (0 -> 29)"<<endl;
            cin>> x;
        }
        }
        else{
        while (x < 0 || x > 28){
            cout<<"please enter a valid day ( 0 -> 28)"<<endl;
            cin>>x;
        
        }
        }
    return x;
}
int checkHour(int x){
    while (x < 0 || x > 23){
        cout<<"please enter a valid hour (0 -> 23)"<<endl;
        cin>>x;
    }
    return x;
}
int checkMin (int x){
    while (x < 0 || x > 59){
        cout<<"please enter a valid minute (0 -> 59)"<<endl;
        cin>>x;
    }
    return x;
}
int checkSec (int x){
    while (x < 0 || x > 59 ){
        cout<<"please enter a valid second (0 -> 59)"<<endl;
        cin>>x;
    }
    return x;
}