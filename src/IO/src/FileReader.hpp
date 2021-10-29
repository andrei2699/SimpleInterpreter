#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdio.h>
#include <stdlib.h>

class FileReader
{
public:
    FileReader();
    ~FileReader();

    FileReader(const FileReader &) = delete;
    FileReader &operator=(const FileReader &) = delete;

    bool Open(char *fileName);
    bool ReadLine(char *line, int size);
    void Close();

private:
    FILE *_filePointer;
};

#endif // FILE_READER_H
