# file_renaming_C++
Renaming all files from a folder to user specified new filenames (C++)

Added all filenames in a string vector and accessed it through the 2nd for loop,
because when making the renaming proccess through the first loop, the check if the new filename already exists could not be done cause the for loop is accessing the files with this sequence: img_0, img_1, img_10, img_11...
So it renamed img_10 to img_2, overwriting(deleting) the existing file every time.
In the second for loop we go through all file names in the filenames vector and the check if our new filename exist is done with the std::find function.
