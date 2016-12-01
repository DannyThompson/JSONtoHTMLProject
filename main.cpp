//Daniel Thompson
#include "Tracks.hpp"
#include "Albums.hpp"
#include "Artists.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

  //Creat all the instances we need
  Artists *a = new Artists();
  Tracks *t = new Tracks();
  Albums *al = new Albums();
  AlbumImages *alIM = new AlbumImages();
  ArtistImages *arIM = new ArtistImages();

  //Loading each file into its respective object
  arIM->loadArtistImagesFromFile("artistImages.json");
  alIM->loadAlbumImagesFromFile("albumImages.json");
  t->loadTracksFromFile("tracks.json");
  a->loadArtistsFromFile("artists.json");
  al->loadAlbumsFromFile("albums.json");


  //Setting Albums, Artists, Images, and Tracks
  a->setAlbumsForArtists(al);
  a->setImagesForArtists(arIM);
  al->setTracksForAlbums(t);
  al->setImagesForAlbums(alIM);


  //Takes the entire HTML string and writes it to a MASTER html file.
  //Same logic as project 1 using the buffer
  std::fstream input("artists_template.html");
  std::stringstream buffer;
  buffer << input.rdbuf();
  std::string data = buffer.str();
  int idx = data.find("<% artists %>");
  std::string output = data.replace(idx, 13, a->htmlString());
  std::fstream outputfile("MASTER.html");
  outputfile << output;
  outputfile.close();
  input.close();



  //This iterates through the list of albums,
  //Makes a new directory "html_albums" and makes a file for each album
  //With it'd Artist ID as the name
  //Could have been made into a function, but just did it like this instead
  //Ofstream was used for outputfile2 in place of fstream, since a new directory was made.
  for(auto it = al->listOfAlbums()->begin(); it != al->listOfAlbums()->end(); it++)
    {
      std::string output2;
      std::fstream input2("album_template.html");
      std::stringstream buffer2;
      buffer2 << input2.rdbuf();
      std::string data2 = buffer2.str();
      std::string data3 = buffer2.str();
      int idx2 = data2.find("<% album_name %>");
      int idx3 = data3.find("<% album_details %>");

      std::string alID = std::to_string((*it)->albumID());
      std::ofstream outputfile2("html_albums/" + alID + ".html");
      if(!outputfile2.is_open())
	cout<<"Error opening output file";
      
      output2 = data2.replace(idx2, 16, (*it)->title());
      output2 = data3.replace(idx3, 19, (*it)->htmlString());
      
      outputfile2 << output2;
      input2.close();
    }

  //Deletes all of the objects we created.
  //Their destructors are virtual, and call JSONArrays Destructor, which then also calls JSONDataObject's destructor.
  delete a;
  delete al;
  delete t;
  delete alIM;
  delete arIM;
  return 0;
}
