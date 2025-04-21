#ifndef STRING_REP_H
#define STRING_REP_H

class StringRep
{
friend class String;
private:
    char *str_;
    int len_;
    int rc;

    StringRep();
    StringRep(const char* s);
    ~StringRep();

public:

};

#endif