#include <stdlib.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <thread>
#include <cstdlib>
#include <thread>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <chrono>   
#include <mutex>


using namespace std;



int maxS = 62;
int a, b, c = 0;
int timer = 0;

mutex mtx;


class Airplane { //airplane class

public: //define planes

	int id, sx, sy, sz, x, y, z, te;

    Airplane() {
      id = 0;
      sx = 0;
      sy = 0;
      sz = 0;
      x = 0;
      y = 0;
      z = 0;
      te = 0;
    }


	Airplane(int id, int sx, int sy, int sz, int x, int y, int z, int te) {
		this->id = id;
		this->sx = sx;
		this->sy = sy;
		this->sz = sz;
		this->x = x;
		this->y = y;
		this->z = z;
		this->te = te;
	}

	int getID(){
		return id;
	}
	
	int getX(){
		return x;
	}
	
	int getY(){
		return y;
	}
	
	int getZ(){
		return z;
	}
	
	int getTe(){
		return te;
	}

	int getSx(){
		return sx;
	}

	int getSy(){
		return sy;
	}

	int getSz(){
		return sz;
	}
	
	void changePos(int newx, int newy, int newz){
		x = newx;
		y = newy;
		z = newz;
	}
	
	void setX(int newX){
		x = newX;
	}

	void setY(int newY){
		y = newY;
	}

	void setZ(int newZ){
		z = newZ;
	}
	
	void changeSpe(int newsx, int newsy, int newsz){
		sx = newsx;
		sy = newsy;
		sz = newsz;
	}
	
	void setSx(int newsx){
		sx = newsx;
	}

	void setSy(int newsy){
		sy = newsy;
	}

	void setSz(int newsz){
		sz = newsz;
	}
	
	void setAirplane(Airplane plane){
		x = plane.x;
		y = plane.y;
		z = plane.z;
		id = plane.id;
		sx = plane.sx;
		sy = plane.sy;
		sz = plane.sz;
		te = plane.te;
	}

	string toString() { // passing to strings
		string str;
		
	    if(x == 0){
		str = " ID:  "+to_string(id) + "\t X:  " + "0000" + "\t Y:  " + to_string(y) + "\t Z:  "
				+ to_string(z) + "\t Speed X, Y, Z :  " + to_string(sx) + " ,  " + to_string(sy) + " ,  " +to_string(sz) + "\t Entry:  " + to_string(te) + " ";
		return str;				
		}
		if(y == 0){
		str = " ID:  "+to_string(id) + "\t X:  " + to_string(x) + "\t Y:  " + "0000" + "\t Z:  "
				+ to_string(z) + "\t Speed X, Y, Z :  " + to_string(sx) + " ,  " + to_string(sy) + " ,  " +to_string(sz) + "\t Entry:  " + to_string(te) + " ";
		return str;
		}
		if(z == 0){
		str = " ID:  "+to_string(id) + "\t X:  " + to_string(x) + "\t Y:  " + to_string(y) + "\t Z:  "
				+ "0000" + "\t Speed X, Y, Z :  " + to_string(sx) + " ,  " + to_string(sy) + " ,  " +to_string(sz) + "\t Entry:  " + to_string(te) + " ";
		return str;			
		}
		
		str = " ID:  "+to_string(id) + "\t X:  " + to_string(x) + "\t Y:  " + to_string(y) + "\t Z:  "
				+ to_string(z) + "\t Speed X, Y, Z :  " + to_string(sx) + " ,  " + to_string(sy) + " ,  " +to_string(sz) + "\t Entry:  " + to_string(te) + " ";
		return str;
		
	}

};


vector<Airplane> Hit;


/*

void entry() {
	while (*timer < maxS ) // entry point
	{
		string t;
			if( test == 1){
			}
			else{
		
			for(int i =0; i<20; i++){
				if( *timer == airplanes.at(i).te ){
					if(airplanes.at(i).x < 100000 && airplanes.at(i).y < 100000 && airplanes.at(i).z < 25000 && airplanes.at(i).x > 0 && airplanes.at(i).y > 0 && airplanes.at(i).z > 0){
						test = 1;

					}
					if(airplanes.at(i).x > 100000 || airplanes.at(i).y > 100000 || airplanes.at(i).z > 25000){
						test = 1;
						enter.push_back(airplanes.at(i).id);
						object.push_back(airplanes.at(i));
					}
					else{
					cout<< *timer << "s\t"<<airplanes.at(i).toString() << "sec\t\t has entered."<<endl;
			//	cout<<" Enter next command"<<endl;
			//	cin >> t;
					enter.push_back(airplanes.at(i).id);
					test = 1;
					}
				}
			}

			}
	}

}


void crash(){

	int crashXYZ;
	int t;
	int temp;
	for(size_t i =0; i < enter.size(); i++){
		for(size_t j = i + 1; j < enter.size(); j++){
			crashXYZ = sqrt(pow((airplanes.at(i).x - airplanes.at(j).x), 2) + pow((airplanes.at(i).y - airplanes.at(j).y), 2)+ pow((airplanes.at(i).z - airplanes.at(j).z), 2));
			if (crashXYZ <= 5000) {
				cout<< "\n !! Near crash between ID " << airplanes.at(i).id << " and ID " << airplanes.at(j).id <<" BECAREFUL !!" <<endl;
					cout<<" Enter next command"
							"\n  1. Change Position of X for ID "<< airplanes.at(i).id<<
							"\n  2. Change Position of Y for ID "<< airplanes.at(i).id<<
							"\n  3. Change Position of Z for ID "<< airplanes.at(i).id<<
							"\n  4. Change Position of X for ID "<< airplanes.at(j).id<<
							"\n  5. Change Position of Y for ID "<< airplanes.at(j).id<<
							"\n  6. Change Position of Z for ID "<< airplanes.at(j).id<<
							""<<endl;
					cin >> t;

					switch(t){
					case 1 : cout<<"Enter the value of X"<<endl;
							 cin >> temp;
							 airplanes.at(i).setX(temp);
							 break;
					case 2 : cout<<"Enter the value of Y"<<endl;
							 cin >> temp;
							 airplanes.at(i).setY(temp);
							 break;
					case 3 : cout<<"Enter the value of Z"<<endl;
							 cin >> temp;
							 airplanes.at(i).setZ(temp);
							 break;
					case 4 : cout<<"Enter the value of X"<<endl;
							 cin >> temp;
							 airplanes.at(j).setX(temp);
							 break;
					case 5 : cout<<"Enter the value of Y"<<endl;
							 cin >> temp;
							 airplanes.at(j).setY(temp);
							 break;
					case 6 : cout<<"Enter the value of Z"<<endl;
							 cin >> temp;
							 airplanes.at(j).setZ(temp);
							 break;


					}

			}

		}
	}

}

void airspace(){
	while (*timer < maxS ) // entry point
	{
		int temp;
			if( co == 1){
			}
			else {
			m.lock();
			for(size_t i = 0; i < enter.size(); i++){

					temp = 1 * airplanes.at(i).sx + airplanes.at(i).x;
					if(temp <= 0)
						temp = 0;
					airplanes.at(i).setX(temp);
					temp = 1 * airplanes.at(i).sy + airplanes.at(i).y;
					if(temp <= 0)
						temp = 0;
					airplanes.at(i).setY(temp);
					temp = 1 * airplanes.at(i).sz + airplanes.at(i).z;
					if(temp <= 0)
						temp = 0;
					airplanes.at(i).setZ(temp);

					if(airplanes.at(i).x > 100000 || airplanes.at(i).y > 100000 || airplanes.at(i).z > 25000){
						co = 1;

					}
					else{
					cout<< *timer << "s\t"<<airplanes.at(i).toString() << "sec\t\t has updated."<<endl;
					crash((void *)&arg);
			//	cout<<" Enter next command"<<endl;
			//	cin >> t;
					}
					//to code speed * time + position = new position
					co = 1;

				}

			m.unlock();
			}

	}


}


void display(){
	while (*timer < maxS ) // entry point
	{
		int temp;
			if( re == 1){
			}
			else {
			m.lock();
			if(*timer % 5 == 0){
			for(size_t i = 0; i < enter.size(); i++){
				if(i == 0 )
					cout<< "\n\t\t\t\t\t\t\t\t\t\t\t\t  Display View: \n";

				if(airplanes.at(i).x > 100000 || airplanes.at(i).y > 100000 || airplanes.at(i).z > 25000){
					re = 1;
				}
				else{
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t   ID: "<<airplanes.at(i).id<<"  \t X: "<<airplanes.at(i).x<<"  \t Y: "<<airplanes.at(i).y<<"  \t Z: "<<airplanes.at(i).z << endl;

 				}
					re = 1;

				}

			}

			if(*timer % 15 == 0){
			for(size_t i = 0; i < object.size(); i++){
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t  OBJECT: "<<object.at(i).id<<" \t X: "<<object.at(i).x<<"\t Y: "<<object.at(i).y<<"\t Z: "<<object.at(i).z << endl;
				re = 1;
				}
			re = 1;
			}

			m.unlock();
			}

	}


}






void timer() { // timer thread
// save the seco argument into local variable second.
	int second = 0;

	while(second < maxS){
	std::this_thread::sleep_for (std::chrono::seconds(1));
	m.lock();
	test = 0;
	co = 0;
	re = 0;
	second = second + 1; //increment second by 1 after sleep
	test = second;
	timer = &second;
	m.unlock();

	}

}

*/

void updateLog(Airplane& airplane) {

	for (int i = 0; i < Hit.size(); i++)
	{
		int airplaneListId = Hit[i].getID();
		int id = airplane.getID();

		if (airplaneListId == id) {
			Hit[i].setX(airplane.getX());
			Hit[i].setY(airplane.getY());
			Hit[i].setZ(airplane.getZ());
		}
	}
}



void deleteFromLog (Airplane& airplane, int x, int y, int z, int& timer, ofstream& file ) {

	int id = airplane.getID();

	if ((x > 100000 | x < 0) || (y > 100000 | y < 0) || (z > 25000 | z < 0)) {

		for (int i = 0; i < Hit.size(); i++)
		{
			int airplaneListId = Hit[i].getID();

			int x_hit = airplane.getX();
			int y_hit = airplane.getY();
			int z_hit = airplane.getZ();

			if ((airplaneListId == id) && (x_hit == x) && (y_hit == y) && (z_hit == z)) {
	//			file <<"Time: "<<timer<< "  "<<airplane.toString() <<" Left" <<endl;
				Hit.erase(Hit.begin() + i);
				break; // break from the loop when aircraft found in the list
			}
		}
	}
}



void detectLostObjects(int airplaneID, int& timer, ofstream& file) {

	file <<"Time: "<<timer<< "   ID:  " << airplaneID << " Object Identified" <<endl;

}


void addToLog(Airplane& airplane, int x, int y, int z, int& timer, ofstream& file) {

	int id = airplane.getID();
	int counter = 0;

	// if in those coordinates, then airplane in the airspace
	if ((x <= 100000 & x >= 0) && (y <= 100000 & y >= 0) && (z >= 0 & z <= 25000)) {

		for (int i = 0; i < Hit.size(); i++)
		{
			int airplaneListID = Hit[i].getID();
			
			// Check if aircraft already inserted in the Hit list
			int x_hit = airplane.getX();
			int y_hit = airplane.getY();
			int z_hit = airplane.getZ();
		//	&& (x_hit != x) && (y_hit != y) && (z_hit != z)
		
			if ((id < 0) && (x_hit != x) && (y_hit != y) && (z_hit != z)) { // means that lost object, still add into hit list because id can be the same
				Hit.push_back(airplane);
				detectLostObjects(airplane.getID(), timer, file);
				break;
			}
			else if(airplaneListID == id){
				break;
			}
			else 
				counter++;
		}
		// If the counter is equal to the size of the Hit list, 
		// it means it has looped through all of the list and that the aircraft doesn't exist in the list

		if (counter == Hit.size()) {
		//	file <<"Time: "<<timer<< "  "<<airplane.toString() <<" Entered" <<endl;
			Hit.push_back(airplane);

		}
		
	}
}


void aircraftMovement(Airplane& airplane) { // pass by reference in order to update and save the new position values

	int current_speed_x = airplane.getSx();
	int current_speed_y = airplane.getSy();
	int current_speed_z = airplane.getSz();

	int current_pos_x = airplane.getX();
	int current_pos_y = airplane.getY();
	int current_pos_z = airplane.getZ();
	
	int newx = current_pos_x + current_speed_x;
	int newy = current_pos_y + current_speed_y;
	int newz = current_pos_z + current_speed_z;
	
	if(newx <= 0){
		newx =0;
	}
	if(newy <= 0){
		newy =0;
	}
	if(newz <= 0){
		newz =0;
	}
	// The position of the aircraft will be updated every second
	// New coordinates after each seconds
	airplane.changePos(newx, newy, newz);
	
	updateLog(airplane);
}




void history(ostream &file, int& timer) {

	// current date/time based on current system 

	if (Hit.empty()) 
	{

		file << "Time: " << timer<<"  ";
		file << " \t**The airspace is currently empty at this time**" << endl;

	}
	else 
	{
		for (int i = 0; i < Hit.size(); i++)
		{

			file << "Time: " << timer<<"  ";
			file << Hit[i].toString()<<endl;

		}
		
	}

}

int user(vector<Airplane>& tracklist, int& timer, ofstream& file) {\


	int input, choice;
	cout << "Operator Command?(Enter number)"<<"\n0. No"<<"\n1. Yes"<<endl;
	
	cin >> input;
	
	switch(input){
		
		case 0:
		this_thread::sleep_for(chrono::seconds(1));
		break;
		
		case 1:
			cout<<" Pick an option(Enter number)"<<"\n1. Change position of a airplane\n2. Project the position of an airplane"<<
			"\n3. Change altitude of a airplane\n4. Brodacast message to airspace\n5. Brodcast message to an airplane"<<endl;
			cin >> choice;
			break;		
	}
	
	return 0;

}

void entry(vector<Airplane>& airplanelist, vector<Airplane>& tracklist, int& timer, ofstream& file, int input) {
	timer++;
	a = 0;
	b = 0;
	c = 0;
	int result;
	// compare the counter to the release time of the aircraft
	// If the counter is equal to the release time, then add to the list of aircraft 
	if(timer > 0 && timer % input == 0){
	mtx.lock();
	result = user(tracklist,timer,file);
	mtx.unlock();
	}
	

	for (int i = 0; i < airplanelist.size(); i++)
	{
		Airplane airplane = airplanelist[i];  
		int entryTime = airplane.getTe();

		if (entryTime == timer) {
			tracklist.push_back(airplane);
		}
	}
}

void track(vector<Airplane>& tracklist, int& timer, ofstream& file) {

	for (int i = 0; i < tracklist.size(); i++)
	{
		// airspace dimensions are 100 x 100 miles (x,y) --> coordinates starts at origin from a corner, therefore 0 to 100000 in x and y
		// height is 25000 ft --> from 0 to 25000 feet
		int x = tracklist[i].getX();
		int y = tracklist[i].getY();
		int z = tracklist[i].getZ();

		addToLog(tracklist[i], x, y, z, timer, file);
		deleteFromLog(tracklist[i], x, y, z, timer, file);
		aircraftMovement(tracklist[i]);
	}
}

void display(int& timer) {
	
	if(Hit.empty() && timer > 7){
		cout << "Time: " << timer<<"  ";
		cout << " \t**The airspace is currently empty at this time**" << endl;
		
	}

	for (int i = 0; i < Hit.size(); i++)
	{
		int id = Hit[i].getID(); 
		int x = Hit[i].getX();
		int y = Hit[i].getY();
		int z = Hit[i].getZ();


		if ((x > 100000 | x < 0) || (y > 100000 | y < 0) || (z > 25000 | z < 0)) { 
			// don't display if out of airspace... do nothing
		}
		else {	
			cout << "Time: " << timer<<"  ";
			cout << Hit[i].toString()<<endl;
		}
	}
}




void timer_log(function<void(ofstream&, int&)> func, ofstream& file, unsigned int interval, int& timer) {

	thread([func, &file, interval, &timer]() {
		while (timer < maxS)
		{
			if(a == 1){
			}
			else if(timer % interval == 0 && timer > 0){
			func(file, timer);
			a=1;
		}
		}
	}).detach();
}


void timer_entry(function<void(vector<Airplane>&, vector<Airplane>& , int&, ofstream&, int)> func, vector<Airplane>& airplanelist, vector<Airplane>& tracklist, int& timer, unsigned int interval, ofstream& file, int input)
{
	thread([func, &airplanelist, &tracklist,&timer, interval,&file,input]() {
		while (timer < maxS)
		{
			func(airplanelist, tracklist, timer, file, input);

			this_thread::sleep_for(chrono::seconds(interval));
		}
	}).detach();
}

void timer_track(function<void(vector<Airplane>&, int&, ofstream&)> func, vector<Airplane>& tracklist , unsigned int interval, int& timer, ofstream& file)
{
	thread([func, &tracklist, interval, &timer, &file]() {
		while (timer < maxS)
		{
			if (b == 1){
			}
			else if(timer % interval == 0 && timer > 0){
			func(tracklist,timer,file);
			b =1;
		}

			
		}
	}).detach();
}

void timer_display(function<void(int&)> func, unsigned int interval,int& timer)
{
	thread([func, interval, &timer]() {
		while (true)
		{
			if(c == 1){
			}
			else if(timer % interval == 0 && timer > 0){
			func(timer);
			c= 1;
		}

		}
	}).detach();
}




void schedule(vector<Airplane>& airplanelist,vector<Airplane>& tracklist,ofstream& file,int& timer, int input){
	
		timer_entry(entry, airplanelist, tracklist, timer, 1, file, input);
		
		timer_track(track, tracklist, 3, timer, file);
		
		timer_display(display, 5, timer);
		timer_log(history, file, 15, timer);
		
		
		




}



int main() { //vector airplane

	Airplane a1(0, -641, 283, 500, 95000, 101589, 10000, 13);
	Airplane a2(1, -223, -630, -526, 71000, 100000, 13000, 16);
	Airplane a3(-1, -180, -446, -186, 41000, 100000, 6000, 31);
	Airplane a4(3, 474, -239, 428, 38000, 0, 14000, 44);
	Airplane a5(-1, -535, 520, 360, 95000, 100000, 1000, 49);
	Airplane a6(-1, -164, -593, -501, 83000, 100000, 12000, 67);
	Airplane a7(6, 512, 614, 520, 86000, -1571, 9000, 87);
	Airplane a8(7, -275, 153, -399, 47000, 100000, 12000, 103);
	Airplane a9(8, -129, 525, -300, 92000, 100000, 1000, 123);
	Airplane a10(9, 437, 574, 339, 32000, 0, 8000, 129);
	Airplane a11(10, 568, 538, 192, 50000, 0, 4000, 133);
	Airplane a12(11, 347, 529, -599, 83000, -1799, 10000, 140);
	Airplane a13(12, -512, -482, 578, 35000, 100000, 4000, 142);
	Airplane a14(13, 619, -280, 194, 74000, 0, 10000, 157);
	Airplane a15(14, -141, 427, -321, 41000, 102251, 11000, 165);
	Airplane a16(15, -199, 242, -205, 56000, 100000, 4000, 172);
	Airplane a17(16, 315, -197, -365, 77000, 0, 1000, 187);
	Airplane a18(17, -138, 455, 602, 23000, 102290, 14000, 199);
	Airplane a19(18, -150, 557, -356, 38000, 100000, 1000, 204);
	Airplane a20(19, 194, 184, 598, 35000, 0, 2000, 221);
	
	vector<Airplane> airplanelist = {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20};

	vector<Airplane> tracklist; 
	
	int input;
	auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());

//	cout << "Update:  " << ctime(&timenow) << endl;
	ofstream file;
	file.open("history.log", std::ofstream::out | std::ofstream::trunc);

    cout << "ATC: ON \nTime: "<<ctime(&timenow)<<" " << endl;
    file << "ATC: ON \nTime: "<<ctime(&timenow)<<" " << endl;
    cout<<"Initializing System..."<<endl;
    file<<"Initializing System..."<<endl;
    
    cout << "At what interval would you like to Command? (for never enter 300)"<<endl;
    cin >> input;
    

	schedule(airplanelist, tracklist, file, timer, input);
	while(timer < maxS);
	
	this_thread::sleep_for(chrono::seconds(1));
	
	cout << "ATC: OFF \nTime: "<<ctime(&timenow)<<" " << endl;
	file << "ATC: OFF \nTime: "<<ctime(&timenow)<<" " << endl;
	file.close();



	return 0;

}

