#include <iostream>
#include <set>

using namespace std;

// function used to validate the flags and inputs
bool validateFlagInput(string flag, string input){
    set<string> validShapes = {"rectangle"};
    set<string> validColor = {"red"};

    if(flag.compare("-s") == 0){
        // if the input is in the set then return true
        if(validShapes.find(input) != validShapes.end()){
            return true;
        }
        cout << "ERROR: The -s argument is not valid" << endl;
    }
    else if(flag.compare("-c") == 0){
        if(validColor.find(input) != validColor.end()){
            return true;
        }
        cout << "ERROR: The -c argument is not valid" << endl;
    }
    else if(flag.compare("-o") == 0){
        return true;
    }
    else{
        return false;
    }
    return false;
}

int main(int argc, char *argv[]) {

    // make sure there are the right number of arguments
    if (argc > 8){
        cout << "ERROR: The provided number of arguments exceeded the allowed number of arguments" << endl;
        return 0;
    }

    if (argc < 8){
        cout << "ERROR: The provided number of arguments are less than the minimum requirement" << endl;
        return 0;
    }

    // cout << "argc: " << argc << endl;

    string inputImageFileName = argv[1];
    string idShape = "";
    string color = "";
    string outFileName = "";

    for(int i = 2; i < argc; i+=2){
        set<string> flags = {"-s", "-c" , "-o"};

        // match the flag
        auto findFlagResult = flags.find(argv[i]);

        // if flag is not found
        if(findFlagResult == flags.end()){
            cout << "ERROR: There exists an invalid flag" << endl;
            return 0;
        }
        else if( (*findFlagResult).compare("-s") == 0 && validateFlagInput("-s", argv[i+1]) ){
            idShape = argv[i+1];
        }
        else if( (*findFlagResult).compare("-c") == 0 && validateFlagInput("-c", argv[i+1]) ){
            color = argv[i+1];
        }
        else if( (*findFlagResult).compare("-o") == 0 ){
            outFileName = argv[i+1];
        }
        else{
            return 0;
        }
    }

    cout << "inputImageFileName: " << inputImageFileName << endl;
    cout <<  "idShape: " << idShape << endl;
    cout <<  "color: " << color << endl;
    cout <<  "outFileName: " << outFileName << endl;

    return 0;
}