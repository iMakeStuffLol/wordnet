#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//Function to find difference between strings of various sizes
//Return 0 if
int diff(string s1, string s2){
  int d = 0;
  int ssize = s1.size() < s2.size() ? s1.size() : s2.size();
  int lsize = s1.size() == ssize ? s2.size() : s1.size();
  for(int i = 0; i<ssize; i++){
    if(s1[i] != s2[i]) d++;
  }
  return d+lsize-ssize;
}

void makeGraph(vector<string> words, string outname, int difference){
  ofstream outfile(outname);
  if(outfile.fail()) throw (string)"FAILED TO ACCESS WRITE FILE. CHECK YOUR PERMISSIONS!";

  //Create file with initial nodes
  outfile<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?><gexf xmlns=\"http://gexf.net/1.2\" version=\"1.2\"><graph mode=\"static\" defaultedgetype=\"directed\"><nodes>";
  cout<<"Writing nodes\n";
  for(int i=0; i<words.size(); i++){
    outfile<<"<node id=\""+to_string(i)+"\" label=\""+words[i]+"\" />";
  }
  outfile<<"</nodes>";

  //Write connections
  cout<<"Writing connections\n";
  outfile<<"<edges>";
  for(int i = 0; i<words.size(); i++){
    if(i%100 == 0) cout<<i<<'\n';
    for(int x = i+1; x<words.size(); x++){
      int d = diff(words[i], words[x]);
      //Connection is only valid if it isn't 0
      if(d <= difference && d > 0) outfile<<"<edge id=\""+to_string(i)+'-'+to_string(x)+"\" source=\""+to_string(i)+"\" target=\""+to_string(x)+"\" />";
    }
  }
  outfile<<"</edges></graph></gexf>";
}
