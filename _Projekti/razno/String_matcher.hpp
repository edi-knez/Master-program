#pragma once
class String_matcher
{
public:
    virtual ~String_matcher() = default;

public:
    // Returns true if string matches, false
    virtual int match( const char* const string ) = 0;

};
