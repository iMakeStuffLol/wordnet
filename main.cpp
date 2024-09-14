#include "makegraph.h"

//Reads file into a vector of strings
vector<string> readfile(string fname, int min, int max){
  if(max<min) throw (string)"MIN CANNOT BE BELOW MAX!";
  ifstream readfile(fname);
  vector<string> out;
  if(readfile.fail()) throw "File \""+fname+"\" does not exist.";
  while(!readfile.eof()){
    string topush;
    getline(readfile, topush);
    if(min == 0 || topush.size()-1 >= min && topush.size()-1 <= max) out.push_back(topush.substr(0, topush.size()-1));
  }
  return out;
}

int main(int argc, char** argv){
  //Parse arguments
  map<string, string> args;
  for(int i=1; i<argc; i++){
    if(argv[i][0] == '-'){
      if(i == argc-1 || argv[i+1][0] == '-') args[argv[i]] = "true";
      else{
        args[argv[i]] = argv[i+1];
        i++;
      }
      continue;
    }
    args["DEFAULT"] = argv[i];
  }

  //Validate and set default parameters
  if(args.find("-l") == args.end()) args["-l"] = "3";
  if(args.find("-u") == args.end()) args["-u"] = args["-l"];
  if(args.find("-d") == args.end()) args["-d"] = "1";
  if(args.find("DEFAULT") == args.end() || args.find("-o") == args.end()){
    cout<<"NO " <<(args.find("DEFAULT") == args.end() ? "INPUT" : "OUTPUT") << " FILE SELECTED!\n";
    return 0;
  }

  //Try to generate, catch errors.
  try{
    vector<string> words = readfile(args["DEFAULT"], stoi(args["-l"]), stoi(args["-u"]));
    cout<<"Received list of "<<words.size()<< " words. Processing...\n";
    makeGraph(words, args["-o"], stoi(args["-d"]));
    cout<<"Graph complete!\n";
  }
  catch(string exc){
    cout<<exc<<'\n';
  }

}
