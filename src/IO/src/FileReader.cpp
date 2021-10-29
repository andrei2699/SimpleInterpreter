#include "FileReader.hpp"

FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

bool FileReader::Open(char *fileName)
{
    _filePointer = fopen(fileName, "r");

    return _filePointer != NULL;
}

bool FileReader::ReadLine(char *line, int size)
{
    if (_filePointer == NULL)
    {
        return false;
    }

    return fgets(line, size, _filePointer) != NULL;
}

void FileReader::Close()
{
    if (_filePointer != NULL)
    {
        fclose(_filePointer);
    }
    _filePointer = NULL;
}
