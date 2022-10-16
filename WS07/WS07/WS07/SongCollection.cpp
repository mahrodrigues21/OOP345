// Student Information
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-11-06
// WS07
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 
// I used this resource to create a display function https://www.geeksforgeeks.org/lambda-expression-in-c/
// I used this resource to push the information to class https://en.cppreference.com/w/cpp/container/vector/push_back
// I used this resource https://en.cppreference.com/w/cpp/algorithm

#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <algorithm>
#include "SongCollection.h"

using namespace std;

namespace sdds {
	//constructor that receives as a parameter the name of the file
	SongCollection::SongCollection(const char* nameFile) {
		std::ifstream fileIn(nameFile); //load the file into the fileIn variable
		Song readSong; //create a new object Song
		std::string lineFile; //get a line of the file

		//creates a lambda function to load the file 
		auto readFile = [](std::string& nameFile, int length)
		{
			//get "length" characters to pass of the member
			std::string field = nameFile.substr(0, length);

			//substract the "length" characters to the line;
			nameFile = nameFile.substr(length);

			//cleand the blanks first and last
			field.erase(0, field.find_first_not_of(' '));
			field.erase(field.find_last_not_of(' ') + 1);

			return field;
		};
		//if the file is incorrect show an exception
		if (!fileIn.is_open()) {
			std::cout << "Error";
		}
		else {
			while (std::getline(fileIn, lineFile)) {
				readSong.m_title = readFile(lineFile, 25);
				readSong.m_artist = readFile(lineFile, 25);
				readSong.m_album = readFile(lineFile, 25);
				readSong.m_year = readFile(lineFile, 5);
				readSong.m_lengthSong = stoi(readFile(lineFile, 5));
				readSong.m_price = stod(readFile(lineFile, 5));

				//sum the total of paytime in each interation
				m_total += readSong.m_lengthSong;
				//push the readSong object to the vector m_song
				//Appends the given element value to the end of the container
				m_song.push_back(std::move(readSong));
			}
		}
	}
	//print the one song per line
	void SongCollection::display(std::ostream& out) const {
		//lambda expression t print vector
		for_each(m_song.begin(), m_song.end(), [&out](const Song& theSong) {
			out << theSong << endl;
			});
		//calculate the seconds to hour, minutes and seconds
		/*size_t min = m_total / 60; 77 is 1h 17 min.
		size_t hour = min / 60;
		size_t second = m_total % 60;*/

		size_t hour = m_total / 3600;
		size_t min = (m_total % 3600) / 60;
		size_t second = (m_total % 3600) % 60;

		//display the total of hours of playtime
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "|" << std::right << setw(78) << setfill(' ')  << "Total Listening Time: ";
		out << hour << ":" << min << ":" << second << " |" << endl;

	}
	//Free helper: to field each parameter with the song information
	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		//example of output
		// | Rafiki's Fireflies   | Hans Zimmer     | Best of              |   2017 | 1:52 | 1.29 |
		//Calculate the song time
		size_t min = theSong.m_lengthSong / 60;
		size_t second = theSong.m_lengthSong % 60;

		out << "| " << std::left << std::setw(20) << std::setfill(' ') << theSong.m_title;
		out << " | " << std::setw(15) << std::setfill(' ') << theSong.m_artist;
		out << " | " << std::setw(20) << std::setfill(' ') << theSong.m_album;
		out << " | " << std::right << std::setw(6) << theSong.m_year;
		out << " | " << min << ":" << std::setw(2) << std::setfill('0') << second;
		out << " | " << std::fixed << std::setprecision(2) << theSong.m_price << " |";

		return out;
	}
	//use the name to sort the field of the songs
	void SongCollection::sort(std::string field) {
		if (field == "title")
			std::sort(m_song.begin(), m_song.end(), [](Song& theSong, Song& other) {
			return theSong.m_title < other.m_title;
				});
		else if (field == "album")
			std::sort(m_song.begin(), m_song.end(), [](Song& theSong, Song& other) {
			return theSong.m_album < other.m_album;
				});
		else if (field == "length")
			std::sort(m_song.begin(), m_song.end(), [](Song& theSong, Song& other) {
			return theSong.m_lengthSong < other.m_lengthSong;
				});
		else cout << "Invalid input, please try again" << "\n";
	}

	//remove the token[None] from the album field
	void SongCollection::cleanAlbum() {
		for_each(m_song.begin(), m_song.end(), [](Song& theSong) {
			if (theSong.m_album == "[None]") {
				theSong.m_album = "";
			}
			});
	}
	//receives the name of an artist, and returns true
	bool SongCollection::inCollection(std::string field) const {
		//any_of (STL library), check an array of element and return true or false if each element satisfy the condition {};
		return any_of(m_song.begin(), m_song.end(), [field](const Song& theSong) {
			//condition
			return theSong.m_artist == field;
			});
	}
	//receives the name of an artists, and return a list of songs. Needs the list library
	std::list<Song> SongCollection::getSongsForArtist(std::string artistName) const {
		//destination vetor Song pass at the end (return)
		std::list<Song> listSong;

		//Check the list of songs that the artist has
		copy_if(m_song.begin(), m_song.end(), back_inserter(listSong), [artistName](const Song& theSong)
			{
				//it's the if condition, if the theSong.m_artist is equal the parameter receives than the copy will be done.
				return theSong.m_artist == artistName;
			});
		return listSong;
	}
}
