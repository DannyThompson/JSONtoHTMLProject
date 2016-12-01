//Daniel Thompson

#include "Tracks.hpp"

Tracks::Tracks(){}

int Tracks::numTracks()
{
  return numJSONObjects();
}

void Tracks::addTrack(Track *track)
{
  listOfTracks()->push_back(track);
}

void Tracks::loadTracksFromFile(std::string tracksfileName)
{
  std::fstream trStream;
  trStream.open(tracksfileName.c_str(), std::fstream::in);
  parseJSONArray(trStream);
  trStream.close();
}

Tracks *Tracks::trackWithID(unsigned int tID)
{
  Tracks *newL = new Tracks();
  for( auto it = listOfTracks()->begin(); it != listOfTracks()->end(); it++ )
    if( (*it)->albumID() == tID )
      newL->addTrack( (*it) );
  return newL;
  
}

void Tracks::runAsserts()
{

}

std::string Tracks::htmlString()
{
  std::string temp = "<h2>Tracklist</h2>";
  temp += "<table class=\"tracks\">";
  temp+= "<tbody>";
    
  for( auto it = listOfTracks()->begin(); it != listOfTracks()->end(); it++ )
   temp+= (*it)->htmlString();

  temp+= "</tbody>";
  temp+="</table>";

  return temp;
}


Tracks::~Tracks()
{
   
}

