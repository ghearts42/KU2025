#include <cstring>
#include <cassert>
#include "string.h"

std::ostream& operator<<(std::ostream& out , String& rhs)
{
    // return out << rhs.pRep_->str_;
    return out << rhs.c_str();
}

String::String()
{
    pRep_= new StringRep;
    pRep_-> = 1;
}

String::String(const char *s)
{
    pRep_ = new StringRep(s);
    pRep_->rc = 1;
}

String::~String()
{
    --pRep_->rc;
    if(pPep_->rc == 0)
        delete pRep_;
}

String::String(const String& rhs)
{
    pRep_ = rhs.pRep_;
    ++pRep_->rc;
}

String& String::operator=(const String& rhs)
{
    if (this != &rhs){ 
        
        delete [] str_;
        str_ = new char[rhs.len_ + 1];
        assert(str_);
        strcpy(str_ , rhs.str_);
    
        len_ = rhs.len_;
    }

    return *this;
}

bool String::operator==(const String& rhs) const
{
    return strcmp(pRep_->str_, rhs.pRep_->str_) == 0;
}

const String String::operator+(const String& rhs) const
{
    char buf[strlen(pRep_->str_) + strlen(rhs.pRep_->str_) + 1];
    strcpy(buf , pRep_->str_);
    strcat(buf , rhs.pRep_->str_);

    String result(buf);
    return result;
}

const char *String::c_str() const
{
    return pRep_->str_;
}

int String::size() const
{
    return pRep_->len_;
}