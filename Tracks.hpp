//Daniel Thompson
#ifndef _TRACKS
#define _TRACKS
#include "JSONArray.hpp"
#include "Track.hpp"

class Tracks: public JSONArray
{
public:
  Tracks();
  virtual ~Tracks();

  int numTracks();
  void addTrack(Track *track);
  
  Tracks *trackWithID(unsigned int tID);
  void loadTracksFromFile(std::string fileName);
  std::string htmlString();
  JSONDataObject *jsonObjectNode() { return new Track(); }
 
  std::vector<Track *> *listOfTracks() { return (std::vector<Track *> *) _listOfDataObjects; }
  void runAsserts();
};

#endif
