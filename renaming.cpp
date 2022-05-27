#include <iostream>
#include <vector>
#include <filesystem>
#include <string>
#include <direct.h> // _getcwd
#include <stdlib.h> // free, perror
#include <stdio.h>  // printf
#include <string.h> // strlen


using std::filesystem::directory_iterator;
using std::filesystem::directory_entry;
using namespace std;


int main() {
    
    /// if working with files residing in a folder in the current working directory
    char* buffer;
    buffer = _getcwd(NULL, 0);
    cout << "CWD  " << buffer << endl;
    //cout << "Buffer len: " << strlen(buffer) << endl;

    char curr_dir[120];

    if (sizeof(buffer) > 0) {
        strcpy(curr_dir, buffer);
        strcat(curr_dir, "\\pics"); // assigning the new working directory, the folder we would like to rename it's contents
        cout << "CWD now " << curr_dir << endl;
    }
    
    const std::filesystem::path myPath = curr_dir;  // the folder we would like to rename it's contents
    

    //const std::filesystem::path myPath = "C:\\Users\\nick1\\Documents\\"; // giving the path manually instead of the CWD proccess above
    
    std::vector<std::string> filenames;


    for (const auto& entry : std::filesystem::directory_iterator(myPath)) {
        string filename = std::filesystem::absolute(entry.path()).string();
        //cout << filename << endl;
        filenames.push_back(filename);  // pushing every filename to a vector of strings
       
    }

    const std::string dir_to_string = myPath.string();
    int ctr = 0;

    for (auto name : filenames) {
            //std::cout << name << '\n';
            const std::string newFileName{ dir_to_string + "\\img_" + std::to_string(ctr++) + ".jpg" };

            std::vector<string>::iterator it = std::find(filenames.begin(), filenames.end(), newFileName);  //searching if a file with the new name already exists in the names vector
            if (it != filenames.end()) {
                std::cout << "name found in : " << std::endl;
                int index = std::distance(filenames.begin(), it);  //position of found filename
                cout << index << endl;
            }
            else {
                std::cout << "Element Not Found" << std::endl;
                std::filesystem::rename(name, newFileName);        //renaming the file to newFileName
            }

    }
    ctr = 0;
    return 0;
}