//Daniel Thompson
#include "Artists.hpp"

Artists::Artists(){}

int Artists::numArtists()
{
  return numJSONObjects();
}

void Artists::addArtist(Artist *artist)
{
  listOfArtists()->push_back(artist);
}

Artists *Artists::artistWithID( unsigned int aID )
{
  Artists *art = new Artists();
  for( auto it = listOfArtists()->begin(); it != listOfArtists()->end(); it++ )
    if( (*it)->artistID() == aID )
      art->addArtist( (*it) );
  return art;
}

//Loads the artist JSON file into the stream
void Artists::loadArtistsFromFile( std::string fileName)
{
  std::fstream artStream;
  artStream.open(fileName.c_str(), std::fstream::in);
  parseJSONArray(artStream);
  artStream.close();
}

//Begins the html string creation. Waterfall From Artists->Artist all the way to Track.
std::string Artists::htmlString()
{
  std::string temp;
  for( auto it = listOfArtists()->begin(); it != listOfArtists()->end(); it++ )
   temp+= (*it)->htmlString();
  return temp;
}

//Uses auto iterator to cycle through the list of singular artists and sets the albums.
//The albums class uses nearly the same logic for setting its images, tracks, and artist.
void Artists::setAlbumsForArtists(Albums *albums)
{
  for( auto it = listOfArtists()->begin(); it !=listOfArtists()->end(); it++ ){
    Albums *al =  albums->albumWithID( (*it)->artistID() );
    for(auto i = al->listOfAlbums()->begin(); i != al->listOfAlbums()->end(); i++)
      (*i)->setArtist((*it));
    (*it)->setAlbums(al);
  }
}

//Sets the images for ther artist using the auto iterator. Again, Albums uses the same logic, and therefore will remain uncommented in that function
void Artists::setImagesForArtists(ArtistImages *artistImages)
{
  for( auto it = listOfArtists()->begin(); it !=listOfArtists()->end(); it++ )
    {
      std::vector<ArtistImage *> *temp = artistImages->artistImageWithID( (*it)->artistID() )->listOfArtistImages();
      for( auto t = temp->begin(); t != temp->end(); t++ )
	{
	  if( (*t)->type() == "primary" )
	    (*it)->primaryImage() = (*t);
	  else
	    (*it)->secondaryImage() = (*t);
	}
    }
}

//Intended for testing, however these functions weren't really used.
void Artists::runAsserts()
{
  for( auto it = listOfArtists()->begin(); it !=listOfArtists()->end(); it++ )
    (*it)->albums()->print();
}

//JSONArray calls delete and this is a virtual function, so it is done from there.
Artists::~Artists()
{
  
}

