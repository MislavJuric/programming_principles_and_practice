#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 12. Define a File_handle class with a constructor that takes a string argument (the file name), opens the file in the
// constructor, and closes it in the destructor.

template<typename T>
class File_handle
{
    private:
        fstream handle;
    public:
        File_handle(string filename);
        ~File_handle();
        void write(T arg);
        // what will I read into? hmmm...
};

template<typename T>
File_handle<T>::File_handle(string filename)
{
    handle.open(filename);
    if (handle.fail())
    {
        // error("Failed to open file.");
    }
}

template<typename T>
File_handle<T>::~File_handle()
{
    handle.close();
}

template<typename T>
void File_handle<T>::write(T arg)
{
    handle << arg;
    handle << endl;
}

int main()
{
    File_handle<int> fh("test.txt");
    fh.write(3);
    fh.write(54);
    return 0;
}
