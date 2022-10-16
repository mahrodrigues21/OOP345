// Student Information
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-11-06
// WS07
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 

#ifndef SDDS_SONGCOLLECTION__H
#define SDDS_SONGCOLLECTION__H

#include <string>
#include <vector>
#include <list>

namespace sdds {
	//structure to stores information about a single song.
	//text as a string, price as a double (0.0), length as a positive integer
	//Initialized each member, string{} other with 0
	struct Song {
		std::string m_artist{};
		std::string m_title{};
		std::string m_album{};
		std::string m_year{};
		double m_price = 0.0;
		/*size_t m_year = 0u;*/
		size_t m_lengthSong = 0u;
	};

	//class to manages a collection of objects of type of structure Song
	class SongCollection {
		std::vector<Song> m_song;
		size_t m_total = 0u; // sum all playtime to the songs
//This class does not have members because it will manipulate/manager the Song structure information.
//public menmbers	
	public:
		//constructor that receives as a parameter the name of the file
		SongCollection(const char* nameFile);
		//print the one song per line
		void display(std::ostream& out) const;
		//use the name to sort the field of the songs
		void sort(std::string field);
		//remove the token[None] from the album field
		void cleanAlbum();
		//receives the name of an artist, and returns true
		bool inCollection(std::string field) const;
		//receives the name of an artists, and return a list of songs. Needs the list library
		std::list<Song> getSongsForArtist(std::string artistName) const;
	};
	//Free helper: to field each parameter with the song information
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SDDS_SONGCOLLECTION__H
